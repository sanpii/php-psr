#ifdef HAVE_CONFIG_H
#    include "config.h"
#endif

#include "psr4.h"
#include "psr.h"

static zend_class_entry *ce_psr_autoloader_psr4;

static void array_unshift_str(zval* array, zend_string* str)
{
    zval params[2];
    zval new_element;
    zval* retval = NULL;

    ZVAL_STR(&new_element, str);
    params[0] = *array;
    params[1] = new_element;

    ZVAL_MAKE_REF(&params[0]);
    retval = psr_call_function("array_unshift", params, 2);
    ZVAL_UNREF(&params[0]);
    if (retval) {
        zval_dtor(retval);
        efree(retval), retval = NULL;
    }
}

static zend_string* psr_zend_string_sub(zend_string *s, size_t start)
{
    size_t len;
    zend_string *ret;

    len = ZSTR_LEN(s) - start;
    ret = zend_string_alloc(len, 0);
    memcpy(ZSTR_VAL(ret), s->val + start, len + 1);

    return ret;
}

static zend_string* get_prefix(zval* this, zend_string* className)
{
    zval* prefixes = NULL;
    zend_string* prefix = NULL;

    prefixes = zend_read_property(ce_psr_autoloader_psr4, this, ZEND_STRL("prefixes"), 1, NULL);
    if (Z_ARRVAL_P(prefixes) != NULL) {
        char* start = NULL;

        prefix = zend_string_init(ZSTR_VAL(className), ZSTR_LEN(className), 0);

        while ((start = strrchr(ZSTR_VAL(prefix), '\\')) != NULL) {
            zval* value = NULL;
            size_t pos = start - ZSTR_VAL(prefix);

            ZSTR_VAL(prefix)[pos] = '\0';
            prefix = zend_string_truncate(prefix, pos, 0);

            value = zend_hash_find(Z_ARRVAL_P(prefixes), prefix);
            if (value != NULL) {
                break;
            }
        }

        if (ZSTR_VAL(prefix)[0] == '\0') {
            zend_string_free(prefix), prefix = NULL;
        }
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

static int find_file_callback(zval* data, int num_args, va_list ap, zend_hash_key *key)
{
    const char* dirName = Z_STRVAL_P(data);
    char** filename = va_arg(ap, char**);
    zend_string* className = va_arg(ap, zend_string*);

    *filename = ecalloc(sizeof(**filename), strlen(dirName) + ZSTR_LEN(className) + strlen(".php") + 2);
    sprintf(*filename, "%s/%s.php", dirName, ZSTR_VAL(className));
    str_replace(*filename, '\\', '/');
    if (file_exists(*filename)) {
        return ZEND_HASH_APPLY_STOP;
    }
    else {
        efree(*filename), *filename = NULL;
        return ZEND_HASH_APPLY_KEEP;
    }
}

static char* get_filename(zval* this, zend_string* prefix, zend_string* className)
{
    zval* value = NULL;
    zval* prefixes = NULL;
    char* filename = NULL;

    prefixes = zend_read_property(ce_psr_autoloader_psr4, this, ZEND_STRL("prefixes"), 1, NULL);

    value = zend_hash_find(Z_ARRVAL_P(prefixes), prefix);
    if (value != NULL) {
        zend_hash_apply_with_arguments(Z_ARRVAL_P(value), find_file_callback, 2, &filename, className);
    }

    return filename;
}

/* {{{ class Psr\Autoloader\Psr4 */
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
    add_next_index_string(&method, "loadClass");

    {
        zval* retval = NULL;
        zval params[] = {method};

        retval = psr_call_function("spl_autoload_register", params, 1);
        zval_dtor(&method);

        if (retval) {
            zval_dtor(retval);
            efree(retval), retval = NULL;
        }
    }
}
/* }}} */

/* {{{ public void addNamespace($prefix, $base_dir, $prepend = false)
   Adds a base directory for a namespace prefix. */
static PHP_METHOD(Psr4, addNamespace)
{
    zend_bool prepend = 0;
    zend_string* prefix = NULL;
    zend_string* base_dir = NULL;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "SS|b", &prefix, &base_dir, &prepend) == FAILURE) {
        return;
    }

    base_dir = zend_string_dup(base_dir, 1);

    {
        zval* this = NULL;
        zval* prefixes = NULL;
        zval* zv_prefix = NULL;

        this = getThis();

        prefixes = zend_read_property(ce_psr_autoloader_psr4, this, ZEND_STRL("prefixes"), 1, NULL);

        zv_prefix = zend_hash_find(Z_ARRVAL_P(prefixes), prefix);
        if (zv_prefix != NULL) {
            if (prepend) {
                array_unshift_str(zv_prefix, base_dir);
            }
            else {
                add_next_index_str(zv_prefix, base_dir);
            }
        }
        else {
            zval value;

            array_init(&value);
            add_next_index_str(&value, base_dir);

            add_assoc_zval(prefixes, ZSTR_VAL(prefix), &value);
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
    zend_string* prefix = NULL;
    zend_string* fullName = NULL;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "S", &fullName) == FAILURE) {
        RETURN_FALSE;
    }

    this = getThis();
    prefix = get_prefix(this, fullName);

    if (prefix != NULL) {
        char* filename = NULL;
        zend_string* className = NULL;

        className = psr_zend_string_sub(fullName, ZSTR_LEN(prefix));

        filename = get_filename(this, prefix, className);
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

/* {{{ public void __construct() */
static PHP_METHOD(Psr4, __construct)
{
    zval* this = NULL;
    zval* prefixes = NULL;

    this = getThis();

    prefixes = zend_read_property(ce_psr_autoloader_psr4, this, ZEND_STRL("prefixes"), 1, NULL);
    array_init(prefixes);
}
/* }}} */

/* {{{ arginfo */
ZEND_BEGIN_ARG_INFO_EX(arginfo_autoloader_psr4_addNamespace, 0, ZEND_RETURN_VALUE, 2)
    ZEND_ARG_INFO(0, prefix)
    ZEND_ARG_INFO(0, base_dir)
    ZEND_ARG_INFO(0, prepend)
ZEND_END_ARG_INFO()

static zend_function_entry autoloader_psr4_class_functions[] = {
    PHP_ME(Psr4, __construct, NULL, ZEND_ACC_PUBLIC)
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
