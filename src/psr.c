#ifdef HAVE_CONFIG_H
#    include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "psr.h"
#include "psr0.h"
#include "psr3.h"
#include "psr4.h"
#include "psr6.h"
#include "psr7.h"

/* {{{ PHP_MINIT_FUNCTION
 */
static PHP_MINIT_FUNCTION(psr)
{
    PHP_MINIT(psr0)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(psr3)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(psr4)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(psr6)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(psr7)(INIT_FUNC_ARGS_PASSTHRU);
    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
static PHP_MINFO_FUNCTION(psr)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "psr support", "enabled");
    php_info_print_table_end();
}
/* }}} */

/* {{{ psr_module_entry
 */
zend_module_entry psr_module_entry = {
    STANDARD_MODULE_HEADER,
    "psr",
    NULL,
    PHP_MINIT(psr),
    NULL,
    NULL,
    NULL,
    PHP_MINFO(psr),
    PHP_PSR_VERSION,
    STANDARD_MODULE_PROPERTIES
};
/* }}} */

void psr_require(const char* filename)
{
    zend_file_handle fh = {
        .filename = filename,
        .opened_path = NULL,
        .free_filename = 0,
        .type = ZEND_HANDLE_FILENAME,
    };

    zend_execute_scripts(ZEND_REQUIRE, NULL, 1, &fh);
}

zval* psr_call_function(const char* name, zval params[], int param_count)
{
    zval* retval = NULL;
    zend_fcall_info finfo;
    zend_fcall_info_cache fcache;

    {
        zval fname;

        ZVAL_STRING(&fname, name);
        zend_fcall_info_init(&fname, IS_CALLABLE_STRICT, &finfo, &fcache, NULL, NULL);
        zval_dtor(&fname);
    }

    retval = emalloc(sizeof(*retval));

    finfo.param_count = param_count;
    finfo.params = params;
    finfo.retval = retval;

    if (zend_call_function(&finfo, &fcache) == FAILURE) {
        php_error_docref(NULL, E_WARNING, "Failed calling %s()", name);
    }

    return retval;
}

#ifdef COMPILE_DL_PSR
ZEND_GET_MODULE(psr)
#endif
