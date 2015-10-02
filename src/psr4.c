#ifdef HAVE_CONFIG_H
#    include "config.h"
#endif

#include "psr4.h"
#include "psr.h"

static zend_class_entry *ce_psr_autoloader_psr4;

static char* get_prefix(zval* this, const zend_string className)
{
    char* prefix = NULL;
    zval* prefixes = NULL;

    prefixes = zend_read_property(ce_psr_autoloader_psr4, this, ZEND_STRL("prefixes"), 1);
    if (Z_ARRVAL_P(prefixes) != NULL) {
        char* start = NULL;
        char* relative_class = NULL;

        prefix = estrdup(ZSTR_VAL(className));
        relative_class = ecalloc(sizeof(*relative_class), ZSTR_LEN(className) + 1);

        while ((start = strrchr(prefix, '\\')) != NULL) {
            zval* value = NULL;
            size_t pos = start - prefix;

            prefix[pos] = '\0';
            strcpy(relative_class, ZSTR_VAL(className) + pos + 1);

            if (zend_hash_find(Z_ARRVAL_P(prefixes), prefix, pos + 1, (void **)&value) == SUCCESS) {
                break;
            }
        }

        if (prefix[0] == '\0') {
            efree(prefix), prefix = NULL;
        }

        efree(relative_class), relative_class = NULL;
    }

    return prefix;
}

static void str_replace(char* subject, char search, char replace)
{
    for (int i = 0; i < strlen(subject); i++) {
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

static char* get_filename(zval* this, const char* prefix, const zend_string className)
{
    zval** value = NULL;
    zval* prefixes = NULL;
    char* filename = NULL;

    prefixes = zend_read_property(ce_psr_autoloader_psr4, this, ZEND_STRL("prefixes"), 1);

    if (zend_hash_find(Z_ARRVAL_P(prefixes), prefix, strlen(prefix) + 1, (void **)&value) == SUCCESS) {
        HashPosition pos;
        zval** data = NULL;

        for (
            zend_hash_internal_pointer_reset_ex(Z_ARRVAL_PP(value), &pos);
            zend_hash_get_current_data_ex(Z_ARRVAL_PP(value), (void**) &data, &pos) == SUCCESS;
            zend_hash_move_forward_ex(Z_ARRVAL_PP(value), &pos)
        ) {
            const char* dirName = Z_STRVAL_PP(data);

            filename = ecalloc(sizeof(*filename), strlen(dirName) + ZSTR_LEN(className) + strlen(".php") + 2);
            sprintf(filename, "%s/%s.php", dirName, ZSTR_VAL(className));
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
    zval* this = NULL;
    zval* method = NULL;

    this = getThis();

    MAKE_STD_ZVAL(method);
    array_init(method);
    Z_ADDREF_P(this);

    add_next_index_zval(method, this);
    add_next_index_string(method, estrdup("loadClass"), 0);

    {
        zval* retval = NULL;
        zval** params[] = {&method};

        retval = psr_call_function("spl_autoload_register", params, 1);
        if (retval) {
            zval_ptr_dtor(&retval), retval = NULL;
        }
    }

    zval_ptr_dtor(&method), method = NULL;
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
        zval* zv = NULL;
        zval* this = NULL;
        zval* prefixes = NULL;
        zval** zv_prefix = NULL;

        MAKE_STD_ZVAL(zv);
        ZVAL_STR(zv, base_dir);

        this = getThis();

        prefixes = zend_read_property(ce_psr_autoloader_psr4, this, ZEND_STRL("prefixes"), 1);
        if (Z_ARRVAL_P(prefixes) == NULL) {
            MAKE_STD_ZVAL(prefixes);
            array_init(prefixes);

            zend_update_property(ce_psr_autoloader_psr4, this, ZEND_STRL("prefixes"), prefixes);
        }

        if (zend_hash_find(Z_ARRVAL_P(prefixes), ZSTR_VAR(prefix), ZSTR_LEN(prefix) + 1, (void **)&zv_prefix) == SUCCESS) {
            if (prepend) {
                zval* retval = NULL;
                zval** params[] = {zv_prefix, &zv};

                psr_call_function("array_unshift", params, 2);
                if (retval) {
                    zval_ptr_dtor(&retval), retval = NULL;
                }
            }
            else {
                add_next_index_zval(*zv_prefix, zv);
            }
        }
        else {
            zval* value = NULL;

            MAKE_STD_ZVAL(value);
            array_init(value);

            add_next_index_zval(value, zv);

            add_assoc_zval(prefixes, ZSTR_VAR(prefix), value);
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
    char* prefix = NULL;
    zend_string className;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "S", &className) == FAILURE) {
        RETURN_FALSE;
    }

    this = getThis();
    prefix = get_prefix(this, className);

    if (prefix != NULL) {
        char* filename = NULL;

        className += strlen(prefix) + 1;

        filename = get_filename(this, prefix, className);
        efree(prefix), prefix = NULL;

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
