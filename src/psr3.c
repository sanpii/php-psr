#ifdef HAVE_CONFIG_H
#    include "config.h"
#endif

#include "psr3.h"

/* {{{ interface Psr\Log\Loggerinterface */
ZEND_BEGIN_ARG_INFO(arginfo_loggerInterface, 0)
    ZEND_ARG_INFO(0, message)
    ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_loggerInterface_log, 0)
    ZEND_ARG_INFO(0, level)
    ZEND_ARG_INFO(0, message)
    ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

static zend_function_entry loggerInterface_class_functions[] = {
    PHP_ABSTRACT_ME(LoggerInterface, emergency, arginfo_loggerInterface)
    PHP_ABSTRACT_ME(LoggerInterface, alert, arginfo_loggerInterface)
    PHP_ABSTRACT_ME(LoggerInterface, critical, arginfo_loggerInterface)
    PHP_ABSTRACT_ME(LoggerInterface, error, arginfo_loggerInterface)
    PHP_ABSTRACT_ME(LoggerInterface, warning, arginfo_loggerInterface)
    PHP_ABSTRACT_ME(LoggerInterface, notice, arginfo_loggerInterface)
    PHP_ABSTRACT_ME(LoggerInterface, info, arginfo_loggerInterface)
    PHP_ABSTRACT_ME(LoggerInterface, debug, arginfo_loggerInterface)
    PHP_ABSTRACT_ME(LoggerInterface, log, arginfo_loggerInterface_log)
    PHP_FE_END
};
/* }}} */

/* {{{ interface Psr\Log\LoggerAwareInterface */
ZEND_BEGIN_ARG_INFO(arginfo_loggerAwareInterface_setLogger, 0)
    ZEND_ARG_OBJ_INFO(0, logger, Psr\\Log\\LoggerInterface, 0)
ZEND_END_ARG_INFO()

static zend_function_entry loggerAwareInterface_class_functions[] = {
    PHP_ABSTRACT_ME(LoggerAwareInterface, setLogger, arginfo_loggerAwareInterface_setLogger)
    PHP_FE_END
};
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(psr3)
{
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, "Psr\\Log", "LoggerInterface", loggerInterface_class_functions);
    ce_psr_loggerInterface = zend_register_internal_interface(&ce TSRMLS_CC);

    INIT_NS_CLASS_ENTRY(ce, "Psr\\Log", "LoggerAwareInterface", loggerAwareInterface_class_functions);
    ce_psr_loggerAwareInterface = zend_register_internal_interface(&ce TSRMLS_CC);

    INIT_NS_CLASS_ENTRY(ce, "Psr\\Log", "LogLevel", NULL);
    ce_psr_logLevel = zend_register_internal_class(&ce TSRMLS_CC);
    zend_declare_class_constant_string(ce_psr_logLevel, ZEND_STRL("EMERGENCY"), "emergency");
    zend_declare_class_constant_string(ce_psr_logLevel, ZEND_STRL("ALERT"), "alert");
    zend_declare_class_constant_string(ce_psr_logLevel, ZEND_STRL("CRITICAL"), "critical");
    zend_declare_class_constant_string(ce_psr_logLevel, ZEND_STRL("ERROR"), "error");
    zend_declare_class_constant_string(ce_psr_logLevel, ZEND_STRL("WARNING"), "warning");
    zend_declare_class_constant_string(ce_psr_logLevel, ZEND_STRL("NOTICE"), "notice");
    zend_declare_class_constant_string(ce_psr_logLevel, ZEND_STRL("INFO"), "info");
    zend_declare_class_constant_string(ce_psr_logLevel, ZEND_STRL("DEBUG"), "debug");

    return SUCCESS;
}
/* }}} */
