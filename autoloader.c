#ifdef HAVE_CONFIG_H
#    include "config.h"
#endif

#include "autoloader.h"
#include "Zend/zend_alloc.h"
#include "Zend/zend_interfaces.h"

static zval* psr_autoloader_getter(const char* property, size_t property_length, INTERNAL_FUNCTION_PARAMETERS)
{
    zval* this = NULL;
    zval* value = NULL;
    zend_class_entry* ce = NULL;

    if (zend_parse_parameters_none() == FAILURE) {
        return NULL;
    }

    this = getThis();

    value = zend_read_property(ce_psr_autoloader, this, property, property_length, 1 TSRMLS_CC);

    return value;
}

static void psr_autoloader_setter(const char* property, size_t property_length, INTERNAL_FUNCTION_PARAMETERS)
{
    zval* this = NULL;
    zval* value = NULL;
    zend_class_entry* ce = NULL;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &value) == FAILURE) {
        return;
    }

    this = getThis();

    zend_update_property(ce_psr_autoloader, this, property, property_length, value);
}

static char* get_filename(zval* this, const char* className)
{
    zval* ns = NULL;
    char* lastPos = NULL;
    char* filename = NULL;
    zval* includePath = NULL;
    zval* fileExtension = NULL;
    zval* namespaceSeparator = NULL;

    MAKE_STD_ZVAL(ns);

    includePath = zend_read_property(ce_psr_autoloader, this, ZEND_STRL("includePath"), 1 TSRMLS_CC);
    fileExtension = zend_read_property(ce_psr_autoloader, this, ZEND_STRL("fileExtension"), 1 TSRMLS_CC);
    namespaceSeparator = zend_read_property(ce_psr_autoloader, this, ZEND_STRL("namespaceSeparator"), 1 TSRMLS_CC);

    lastPos = strrchr(className, Z_STRVAL_P(namespaceSeparator)[0]);
    if (lastPos != NULL) {
        int i;
        const char* basename = NULL;
        const char* dirname = NULL;
        char file[MAXPATHLEN] = "";

        lastPos[0] = '\0';
        dirname = className;

        for (i = 1; lastPos[i]; i++) {
            if (lastPos[i] == Z_STRVAL_P(namespaceSeparator)[0]) {
                lastPos[i] = DEFAULT_SLASH;
            }
        }
        basename = lastPos + 1;

        {
            const char sep[2] = {DEFAULT_SLASH, '\0'};

            filename = emalloc(MAXPATHLEN * sizeof(*filename));
            filename[0] = '\0';

            if (!ZVAL_IS_NULL(includePath)) {
                snprintf(filename, MAXPATHLEN, "%s%s", includePath, sep);
            }
            if (dirname[0] != '\0') {
                snprintf(filename, MAXPATHLEN, "%s%s%s", filename, dirname, sep);
            }
            snprintf(filename, MAXPATHLEN, "%s%s%s", filename, basename, Z_STRVAL_P(fileExtension));
        }
    }
    return filename;
}

static zval* call_function(const char* name, zval** params[], int param_count)
{
    zval fname;
    zval* retval = NULL;
    zend_fcall_info finfo;
    zend_fcall_info_cache fcache;

    ZVAL_STRING(&fname, "spl_autoload_register", 0);
    if (zend_fcall_info_init(&fname, IS_CALLABLE_STRICT, &finfo, &fcache, NULL, NULL TSRMLS_CC) == FAILURE) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "WTF??? Can't find the spl_autoload_register() function!");
        return retval;
    }

    finfo.param_count = param_count;
    finfo.params = params;
    finfo.retval_ptr_ptr = &retval;

    if (zend_call_function(&finfo, &fcache TSRMLS_CC) == FAILURE) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "Failed calling %s()", name);
    }

    return retval;
}

/* {{{ interface Psr\Autoloader */
/* {{{ public void setNamespaceSeparator($namespaceSeparator)
   Sets the namespace separator used by classes in the namespace of this class loader. */
static PHP_METHOD(Autoloader, setNamespaceSeparator)
{
    psr_autoloader_setter(ZEND_STRL("namespaceSeparator"), INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

/* {{{ public void getNamespaceSeparator()
   Gets the namespace seperator used by classes in the namespace of this class loader. */
static PHP_METHOD(Autoloader, getNamespaceSeparator)
{
    zval *value = NULL;

    value = psr_autoloader_getter(ZEND_STRL("namespaceSeparator"), INTERNAL_FUNCTION_PARAM_PASSTHRU);
    RETURN_ZVAL(value, 1, 0);
}
/* }}} */

/* {{{ public void setIncludePath($includePath)
   Sets the base include path for all class files in the namespace of this class loader. */
static PHP_METHOD(Autoloader, setIncludePath)
{
    psr_autoloader_setter(ZEND_STRL("includePath"), INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

/* {{{ public void getIncludePath()
   Gets the base include path for all class files in the namespace of this class loader. */
static PHP_METHOD(Autoloader, getIncludePath)
{
    zval *value = NULL;

    value = psr_autoloader_getter(ZEND_STRL("includePath"), INTERNAL_FUNCTION_PARAM_PASSTHRU);
    RETURN_ZVAL(value, 1, 0);
}
/* }}} */

/* {{{ public void setFileExtension($fileExtension)
   Sets the file extension of class files in the namespace of this class loader.*/
static PHP_METHOD(Autoloader, setFileExtension)
{
    psr_autoloader_setter(ZEND_STRL("fileExtension"), INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

/* {{{ public void getFileExtension()
   Gets the file extension of class files in the namespace of this class loader. */
static PHP_METHOD(Autoloader, getFileExtension)
{
    zval *value = NULL;

    value = psr_autoloader_getter(ZEND_STRL("fileExtension"), INTERNAL_FUNCTION_PARAM_PASSTHRU);
    RETURN_ZVAL(value, 1, 0);
}
/* }}} */

/* {{{ public void register($prepend = false)
   Installs this class loader on the SPL autoload stack. */
static PHP_METHOD(Autoloader, register)
{
    zval* this = NULL;
    zval* method = NULL;
    zval* prepend = NULL;
    zval* do_throw = NULL;

    MAKE_STD_ZVAL(prepend);
    ZVAL_BOOL(prepend, 0);

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &Z_LVAL_P(prepend)) == FAILURE) {
        zval_ptr_dtor(&prepend), prepend = NULL;
        RETURN_FALSE;
    }

    this = getThis();

    MAKE_STD_ZVAL(method);
    array_init(method);
    Z_ADDREF_P(this);

    add_next_index_zval(method, this);
    add_next_index_string(method, estrdup("loadClass"), 0);

    MAKE_STD_ZVAL(do_throw);
    ZVAL_BOOL(do_throw, 0);

    {
        zval* retval = NULL;
        zval** params[] = {&method, &do_throw, &prepend};

        retval = call_function("spl_autoload_register", params, 3);
        if (retval) {
            zval_ptr_dtor(&retval);
        }
    }

    zval_ptr_dtor(&do_throw), do_throw = NULL;
    zval_ptr_dtor(&prepend), prepend = NULL;
    zval_ptr_dtor(&method), method = NULL;
}
/* }}} */

/* {{{ public void unregister()
   Uninstalls this class loader from the SPL autoloader stack. */
static PHP_METHOD(Autoloader, unregister)
{
    zval* this = NULL;
    zval* method = NULL;

    this = getThis();

    MAKE_STD_ZVAL(method);
    array_init(method);
    Z_ADDREF_P(this);

    add_next_index_zval(method, this);
    add_next_index_string(method, estrdup("loadClass"), 0);

    zend_call_method_with_1_params(NULL, NULL, NULL, "spl_autoload_unregister", NULL, method);

    zval_ptr_dtor(&method), method = NULL;
}
/* }}} */

/* {{{ public string|false findFile($className)
   Finds the path to the file where the class is defined. */
static PHP_METHOD(Autoloader, findFile)
{
    zval* this = NULL;
    char* className = NULL;
    char* filename = NULL;
    size_t className_length;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &className, &className_length) == FAILURE) {
        RETURN_FALSE;
    }

    this = getThis();

    filename = get_filename(this, className);
    if (filename != NULL) {
        zval* file = NULL;
        MAKE_STD_ZVAL(file);

        ZVAL_STRING(file, filename, 0);
        RETURN_ZVAL(file, 0, NULL);
        efree(filename), filename = NULL;
    }
    RETURN_FALSE;
}
/* }}} */

/* {{{ public void loadClass($className)
   Loads the given class or interface. */
static PHP_METHOD(Autoloader, loadClass)
{
    zval* this = NULL;
    zval* file = NULL;
    char* filename = NULL;
    char* className = NULL;
    size_t className_length;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &className, &className_length) == FAILURE) {
        RETURN_FALSE;
    }

    this = getThis();
    filename = get_filename(this, className);

    zend_file_handle fh = {
        .filename = filename,
        .opened_path = NULL,
        .free_filename = 0,
        .type = ZEND_HANDLE_FILENAME,
    };

    zend_execute_scripts(ZEND_INCLUDE TSRMLS_CC, NULL, 1, &fh);
    efree(filename), filename = NULL;
}
/* }}} */

/* {{{ arginfo */
ZEND_BEGIN_ARG_INFO(arginfo_autoloader_setter, 0)
    ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()
ZEND_BEGIN_ARG_INFO(arginfo_autoloader_load, 0)
    ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

static zend_function_entry autoloader_class_functions[] = {
    PHP_ME(Autoloader, setNamespaceSeparator, arginfo_autoloader_setter, ZEND_ACC_PUBLIC)
    PHP_ME(Autoloader, getNamespaceSeparator, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(Autoloader, setIncludePath, arginfo_autoloader_setter, ZEND_ACC_PUBLIC)
    PHP_ME(Autoloader, getIncludePath, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(Autoloader, setFileExtension, arginfo_autoloader_setter, ZEND_ACC_PUBLIC)
    PHP_ME(Autoloader, getFileExtension, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(Autoloader, register, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(Autoloader, unregister, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(Autoloader, findFile, arginfo_autoloader_load, ZEND_ACC_PUBLIC)
    PHP_ME(Autoloader, loadClass, arginfo_autoloader_load, ZEND_ACC_PUBLIC)
    PHP_FE_END
};
/* }}} */
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(psr_autoloader)
{
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, "Psr", "Autoloader", autoloader_class_functions);
    ce_psr_autoloader = zend_register_internal_class(&ce TSRMLS_CC);

    zend_declare_property_string(ce_psr_autoloader, ZEND_STRL("namespaceSeparator"), "\\", ZEND_ACC_PRIVATE);
    zend_declare_property_null(ce_psr_autoloader, ZEND_STRL("includePath"), ZEND_ACC_PRIVATE);
    zend_declare_property_string(ce_psr_autoloader, ZEND_STRL("fileExtension"), ".php", ZEND_ACC_PRIVATE);

    return SUCCESS;
}
/* }}} */
