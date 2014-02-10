#ifdef HAVE_CONFIG_H
#    include "config.h"
#endif

#include "php.h"
#include "php_psr.h"

/* {{{ PHP_MINIT_FUNCTION
 */
static PHP_MINIT_FUNCTION(psr)
{
    PHP_MINIT(psr_autoloader)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(psr_logger)(INIT_FUNC_ARGS_PASSTHRU);
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

#ifdef COMPILE_DL_PSR
ZEND_GET_MODULE(psr)
#endif
