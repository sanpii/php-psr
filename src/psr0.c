#ifdef HAVE_CONFIG_H
#    include "config.h"
#endif

#include "psr0.h"
#include "psr.h"
#include "Zend/zend_alloc.h"
#include "Zend/zend_interfaces.h"

static zend_class_entry *ce_psr_autoloader_psr0;

static zval* psr_autoloader_psr0_getter(const char* property, size_t property_length, INTERNAL_FUNCTION_PARAMETERS)
{
    zval* this = NULL;
    zval* value = NULL;

    if (zend_parse_parameters_none() == FAILURE) {
        return NULL;
    }

    this = getThis();

    value = zend_read_property(ce_psr_autoloader_psr0, this, property, property_length, 1, NULL);

    return value;
}

static void psr_autoloader_psr0_setter(const char* property, size_t property_length, INTERNAL_FUNCTION_PARAMETERS)
{
    zval* this = NULL;
    zval* value = NULL;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "z", &value) == FAILURE) {
        return;
    }

    this = getThis();

    zend_update_property(ce_psr_autoloader_psr0, this, property, property_length, value);
}

static char* get_filename(zval* this, zend_string* className)
{
    char* lastPos = NULL;
    char* filename = NULL;
    zval* includePath = NULL;
    zval* fileExtension = NULL;
    zval* namespaceSeparator = NULL;

    includePath = zend_read_property(ce_psr_autoloader_psr0, this, ZEND_STRL("includePath"), 1, NULL);
    fileExtension = zend_read_property(ce_psr_autoloader_psr0, this, ZEND_STRL("fileExtension"), 1, NULL);
    namespaceSeparator = zend_read_property(ce_psr_autoloader_psr0, this, ZEND_STRL("namespaceSeparator"), 1, NULL);

    lastPos = strrchr(ZSTR_VAL(className), Z_STRVAL_P(namespaceSeparator)[0]);
    if (lastPos != NULL) {
        int i;
        const char* basename = NULL;
        const char* dirname = NULL;

        lastPos[0] = '\0';
        dirname = ZSTR_VAL(className);

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

/* {{{ class Psr\Autoloader\Psr0 */
/* {{{ public void setNamespaceSeparator($namespaceSeparator)
   Sets the namespace separator used by classes in the namespace of this class loader. */
static PHP_METHOD(Psr0, setNamespaceSeparator)
{
    psr_autoloader_psr0_setter(ZEND_STRL("namespaceSeparator"), INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

/* {{{ public void getNamespaceSeparator()
   Gets the namespace seperator used by classes in the namespace of this class loader. */
static PHP_METHOD(Psr0, getNamespaceSeparator)
{
    zval *value = NULL;

    value = psr_autoloader_psr0_getter(ZEND_STRL("namespaceSeparator"), INTERNAL_FUNCTION_PARAM_PASSTHRU);
    RETURN_ZVAL(value, 1, 0);
}
/* }}} */

/* {{{ public void setIncludePath($includePath)
   Sets the base include path for all class files in the namespace of this class loader. */
static PHP_METHOD(Psr0, setIncludePath)
{
    psr_autoloader_psr0_setter(ZEND_STRL("includePath"), INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

/* {{{ public void getIncludePath()
   Gets the base include path for all class files in the namespace of this class loader. */
static PHP_METHOD(Psr0, getIncludePath)
{
    zval *value = NULL;

    value = psr_autoloader_psr0_getter(ZEND_STRL("includePath"), INTERNAL_FUNCTION_PARAM_PASSTHRU);
    RETURN_ZVAL(value, 1, 0);
}
/* }}} */

/* {{{ public void setFileExtension($fileExtension)
   Sets the file extension of class files in the namespace of this class loader.*/
static PHP_METHOD(Psr0, setFileExtension)
{
    psr_autoloader_psr0_setter(ZEND_STRL("fileExtension"), INTERNAL_FUNCTION_PARAM_PASSTHRU);
}
/* }}} */

/* {{{ public void getFileExtension()
   Gets the file extension of class files in the namespace of this class loader. */
static PHP_METHOD(Psr0, getFileExtension)
{
    zval *value = NULL;

    value = psr_autoloader_psr0_getter(ZEND_STRL("fileExtension"), INTERNAL_FUNCTION_PARAM_PASSTHRU);
    RETURN_ZVAL(value, 1, 0);
}
/* }}} */

/* {{{ public void register($prepend = false)
   Installs this class loader on the SPL autoload stack. */
static PHP_METHOD(Psr0, register)
{
    zval method;
    zval prepend;
    zval do_throw;
    zval* this = NULL;

    ZVAL_FALSE(&prepend);

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "|z", &Z_LVAL(prepend)) == FAILURE) {
        RETURN_FALSE;
    }

    this = getThis();

    array_init(&method);
    Z_ADDREF_P(this);

    add_next_index_zval(&method, this);
    add_next_index_string(&method, estrdup("loadClass"));

    ZVAL_FALSE(&do_throw);

    {
        zval* retval = NULL;
        zval params[] = {method, do_throw, prepend};

        retval = psr_call_function("spl_autoload_register", params, 3);
        if (retval) {
            zval_ptr_dtor(retval);
        }
    }
}
/* }}} */

/* {{{ public void unregister()
   Uninstalls this class loader from the SPL autoloader_psr0 stack. */
static PHP_METHOD(Psr0, unregister)
{
    zval method;
    zval* this = NULL;

    this = getThis();

    array_init(&method);
    Z_ADDREF_P(this);

    add_next_index_zval(&method, this);
    add_next_index_string(&method, estrdup("loadClass"));

    zend_call_method_with_1_params(NULL, NULL, NULL, "spl_autoload_unregister", NULL, &method);
}
/* }}} */

/* {{{ public string|false findFile($className)
   Finds the path to the file where the class is defined. */
static PHP_METHOD(Psr0, findFile)
{
    zval* this = NULL;
    char* filename = NULL;
    zend_string* className = NULL;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "S", &className) == FAILURE) {
        RETURN_FALSE;
    }

    this = getThis();

    filename = get_filename(this, className);
    if (filename != NULL) {
        RETVAL_STRING(filename);
        efree(filename), filename = NULL;
    }
    else {
        RETVAL_NULL();
    }
}
/* }}} */

/* {{{ public void loadClass($className)
   Loads the given class or interface. */
static PHP_METHOD(Psr0, loadClass)
{
    zval* this = NULL;
    char* filename = NULL;
    zend_string* className;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "S", &className) == FAILURE) {
        return;
    }

    this = getThis();
    filename = get_filename(this, className);
    psr_require(filename);
    efree(filename), filename = NULL;
}
/* }}} */

/* {{{ arginfo */
ZEND_BEGIN_ARG_INFO(arginfo_autoloader_psr0_setter, 0)
    ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_autoloader_psr0_load, 0)
    ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

static zend_function_entry autoloader_psr0_class_functions[] = {
    PHP_ME(Psr0, setNamespaceSeparator, arginfo_autoloader_psr0_setter, ZEND_ACC_PUBLIC)
    PHP_ME(Psr0, getNamespaceSeparator, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(Psr0, setIncludePath, arginfo_autoloader_psr0_setter, ZEND_ACC_PUBLIC)
    PHP_ME(Psr0, getIncludePath, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(Psr0, setFileExtension, arginfo_autoloader_psr0_setter, ZEND_ACC_PUBLIC)
    PHP_ME(Psr0, getFileExtension, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(Psr0, register, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(Psr0, unregister, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(Psr0, findFile, arginfo_autoloader_psr0_load, ZEND_ACC_PUBLIC)
    PHP_ME(Psr0, loadClass, arginfo_autoloader_psr0_load, ZEND_ACC_PUBLIC)
    PHP_FE_END
};
/* }}} */
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(psr0)
{
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, "Psr\\Autoloader", "Psr0", autoloader_psr0_class_functions);
    ce_psr_autoloader_psr0 = zend_register_internal_class(&ce);

    zend_declare_property_string(ce_psr_autoloader_psr0, ZEND_STRL("namespaceSeparator"), "\\", ZEND_ACC_PRIVATE);
    zend_declare_property_null(ce_psr_autoloader_psr0, ZEND_STRL("includePath"), ZEND_ACC_PRIVATE);
    zend_declare_property_string(ce_psr_autoloader_psr0, ZEND_STRL("fileExtension"), ".php", ZEND_ACC_PRIVATE);

    return SUCCESS;
}
/* }}} */
