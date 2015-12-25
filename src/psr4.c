#ifdef HAVE_CONFIG_H
#    include "config.h"
#endif

#include "psr4.h"
#include "psr.h"

static zend_class_entry *ce_psr_autoloader_psr4;

static zend_string* psr_zend_string_sub(zend_string *s, size_t start)
{
    size_t len;
    zend_string *ret;

    len = ZSTR_LEN(s) - start;
    ret = zend_string_alloc(len, 0);
    memcpy(ZSTR_VAL(ret), s->val + start, len + 1);

    return ret;
}

static zend_string* get_prefix(zval* this, zend_string className)
{
    zval* prefixes = NULL;
    zend_string* prefix = NULL;

    prefixes = zend_read_property(ce_psr_autoloader_psr4, this, ZEND_STRL("prefixes"), 1, NULL);
    if (Z_ARRVAL_P(prefixes) != NULL) {
        char* start = NULL;
        char* relative_class = NULL;

        prefix = zend_string_dup(&className, 0);
        relative_class = ecalloc(sizeof(*relative_class), ZSTR_LEN(&className) + 1);

        while ((start = strrchr(ZSTR_VAL(prefix), '\\')) != NULL) {
            zval* value = NULL;
            size_t pos = start - ZSTR_VAL(prefix);

            ZSTR_VAL(prefix)[pos] = '\0';
            ZSTR_LEN(prefix) = pos + 1;
            strcpy(relative_class, ZSTR_VAL(&className) + pos + 1);

            value = zend_hash_find(Z_ARRVAL_P(prefixes), prefix);
            if (value != NULL) {
                break;
            }
        }

        if (ZSTR_VAL(prefix)[0] == '\0') {
            zend_string_free(prefix), prefix = NULL;
        }

        efree(relative_class), relative_class = NULL;
    }

    return prefix;
}

static void str_replace(char* subject, char search, char replace)
{
    int i;

    for (i = 0; i < strlen(subject); i++) {
        if (subject[i] == search) {
            subject[i] = replace;
        }
    }
}

static zend_bool file_exists(const char* filename)
{
    FILE* file = NULL;
    zend_bool exist = 0;

    file = fopen(filename, "r");
    if (file != NULL) {
        exist = 1;
        fclose(file), file = NULL;
    }
    return exist;
}

static char* get_filename(zval* this, zend_string* prefix, const zend_string className)
{
    zval* value = NULL;
    zval* prefixes = NULL;
    char* filename = NULL;

    prefixes = zend_read_property(ce_psr_autoloader_psr4, this, ZEND_STRL("prefixes"), 1, NULL);

    value = zend_hash_find(Z_ARRVAL_P(prefixes), prefix);
    if (value != NULL) {
        HashPosition pos;
        zval* data = NULL;

        for (
            zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(value), &pos);
            data = zend_hash_get_current_data_ex(Z_ARRVAL_P(value), &pos);
            zend_hash_move_forward_ex(Z_ARRVAL_P(value), &pos)
        ) {
            const char* dirName = Z_STRVAL_P(data);

            filename = ecalloc(sizeof(*filename), strlen(dirName) + ZSTR_LEN(&className) + strlen(".php") + 2);
            sprintf(filename, "%s/%s.php", dirName, ZSTR_VAL(&className));
            str_replace(filename, '\\', '/');
            if (file_exists(filename)) {
                break;
            }
            efree(filename), filename = NULL;
        }
    }

    return filename;
}

/* {{{ class Psr\Autoloader\Psr0 */
/* {{{ public void register()
   Register loader with SPL autoloader stack. */
static PHP_METHOD(Psr4, register)
{
    zval method;
    zval* this = NULL;

    this = getThis();

    array_init(&method);
    Z_ADDREF_P(this);

    add_next_index_zval(&method, this);
    add_next_index_string(&method, estrdup("loadClass"));

    {
        zval* retval = NULL;
        zval params[] = {method};

        retval = psr_call_function("spl_autoload_register", params, 1);
        if (retval) {
            zval_ptr_dtor(retval), retval = NULL;
        }
    }
}
/* }}} */

/* {{{ public void addNamespace($prefix, $base_dir, $prepend = false)
   Adds a base directory for a namespace prefix. */
static PHP_METHOD(Psr4, addNamespace)
{
    zend_bool prepend = 0;
    zend_string prefix;
    zend_string base_dir;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "SS|b", &prefix, &base_dir, &prepend) == FAILURE) {
        return;
    }

    {
        zval* this = NULL;
        zval* prefixes = NULL;
        zval* zv_prefix = NULL;

        ZVAL_STR(&zv, &base_dir);

        this = getThis();

        prefixes = zend_read_property(ce_psr_autoloader_psr4, this, ZEND_STRL("prefixes"), 1, NULL);
        if (Z_ARRVAL_P(prefixes) == NULL) {
            array_init(prefixes);

            zend_update_property(ce_psr_autoloader_psr4, this, ZEND_STRL("prefixes"), prefixes);
        }

        zv_prefix = zend_hash_find(Z_ARRVAL_P(prefixes), &prefix);
        if (zv_prefix != NULL) {
            if (prepend) {
                zval* retval = NULL;
                zval params[] = {*zv_prefix, zv};

                psr_call_function("array_unshift", params, 2);
                if (retval) {
                    zval_ptr_dtor(retval), retval = NULL;
                }
            }
            else {
                add_next_index_zval(zv_prefix, &zv);
            }
        }
        else {
            zval value;

            array_init(&value);

            add_next_index_zval(&value, &zv);

            add_assoc_zval(prefixes, ZSTR_VAL(&prefix), &value);
        }
    }
}
/* }}} */

/* {{{ public mixed loadClass($className)
   Loads the class file for a given class name. */
static PHP_METHOD(Psr4, loadClass)
{
    int loaded = 0;
    zval* this = NULL;
    zend_string fullName;
    zend_string* prefix = NULL;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "S", &fullName) == FAILURE) {
        RETURN_FALSE;
    }

    this = getThis();
    prefix = get_prefix(this, fullName);

    if (prefix != NULL) {
        char* filename = NULL;
        zend_string* className = NULL;

        className = psr_zend_string_sub(&fullName, ZSTR_LEN(prefix) + 1);

        filename = get_filename(this, prefix, *className);
        zend_string_free(prefix), prefix = NULL;
        zend_string_free(className), className = NULL;

        if (filename != NULL) {
            psr_require(filename);
            efree(filename), filename = NULL;

            loaded = 1;
        }
    }

    RETURN_BOOL(loaded);
}
/* }}} */

/* {{{ arginfo */
ZEND_BEGIN_ARG_INFO_EX(arginfo_autoloader_psr4_addNamespace, 0, ZEND_RETURN_VALUE, 2)
    ZEND_ARG_INFO(0, prefix)
    ZEND_ARG_INFO(0, base_dir)
    ZEND_ARG_INFO(0, prepend)
ZEND_END_ARG_INFO()

static zend_function_entry autoloader_psr4_class_functions[] = {
    PHP_ME(Psr4, register, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(Psr4, addNamespace, arginfo_autoloader_psr4_addNamespace, ZEND_ACC_PUBLIC)
    PHP_ME(Psr4, loadClass, NULL, ZEND_ACC_PUBLIC)
    PHP_FE_END
};
/* }}} */
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(psr4)
{
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, "Psr\\Autoloader", "Psr4", autoloader_psr4_class_functions);
    ce_psr_autoloader_psr4 = zend_register_internal_class(&ce);

    zend_declare_property_null(ce_psr_autoloader_psr4, ZEND_STRL("prefixes"), ZEND_ACC_PRIVATE);

    return SUCCESS;
}
/* }}} */
