#ifdef HAVE_CONFIG_H
#    include "config.h"
#endif

#include "psr3.h"

/* {{{ interface Psr\Log\Loggerinterface */
/* {{{ public void emergency($message, array $context = array())
   System is unusable. */
static PHP_METHOD(LoggerInterface, emergency)
{
}
/* }}} */

/* {{{ public void alert($message, array $context = array())
   Action must be taken immediately. */
static PHP_METHOD(LoggerInterface, alert)
{
}
/* }}} */

/* {{{ public void critical($message, array $context = array())
   Critical conditions. */
static PHP_METHOD(LoggerInterface, critical)
{
}
/* }}} */

/* {{{ public void error($message, array $context = array())
   Runtime errors that do not require immediate action but should typically be
   logged and monitored. */
static PHP_METHOD(LoggerInterface, error)
{
}
/* }}} */

/* {{{ public void warning($message, array $context = array())
   Exceptional occurrences that are not errors. */
static PHP_METHOD(LoggerInterface, warning)
{
}
/* }}} */

/* {{{ public void notice($message, array $context = array())
   Normal but significant events. */
static PHP_METHOD(LoggerInterface, notice)
{
}
/* }}} */

/* {{{ public void info($message, array $context = array())
   Interesting events. */
static PHP_METHOD(LoggerInterface, info)
{
}
/* }}} */

/* {{{ public void debug($message, array $context = array())
   Detailed debug information. */
static PHP_METHOD(LoggerInterface, debug)
{
}
/* }}} */

/* {{{ public void log($level, $message, array $context = array())
   Logs with an arbitrary level. */
static PHP_METHOD(LoggerInterface, log)
{
}
/* }}} */

/* {{{ arginfo */
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
/* }}} */

/* {{{ interface Psr\Log\Loggerinterface */
/* {{{ public function setLogger(LoggerInterface $logger)
   Se  logger instance on the object. */
static PHP_METHOD(LoggerAwareInterface, setLogger)
{
}
/* }}} */

/* {{{ arginfo */
ZEND_BEGIN_ARG_INFO(arginfo_loggerAwareInterface_setLogger, 0)
    ZEND_ARG_OBJ_INFO(0, logger, Psr\\Log\\LoggerInterface, 0)
ZEND_END_ARG_INFO()

static zend_function_entry loggerAwareInterface_class_functions[] = {
    PHP_ABSTRACT_ME(LoggerAwareInterface, setLogger, arginfo_loggerAwareInterface_setLogger)
    PHP_FE_END
};
/* }}} */
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(psr3)
{
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, "Psr\\Log", "LoggerInterface", loggerInterface_class_functions);
    ce_loggerInterface = zend_register_internal_interface(&ce TSRMLS_CC);

    INIT_NS_CLASS_ENTRY(ce, "Psr\\Log", "LoggerAwareInterface", loggerAwareInterface_class_functions);
    ce_loggerAwareInterface = zend_register_internal_interface(&ce TSRMLS_CC);

    return SUCCESS;
}
/* }}} */
