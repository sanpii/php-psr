#ifdef HAVE_CONFIG_H
#    include "config.h"
#endif

#include "psr11.h"

/* {{{ interface Psr\Container\Containerinterface */
ZEND_BEGIN_ARG_INFO(arginfo_containerInterface_get, 0)
    ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_containerInterface_has, 0)
    ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

static zend_function_entry containerInterface_class_fuctions[] = {
    PHP_ABSTRACT_ME(ContainerInterface, get, arginfo_containerInterface_get)
    PHP_ABSTRACT_ME(ContainerInterface, has, arginfo_containerInterface_has)
    PHP_FE_END
};
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(psr11)
{
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, "Psr\\Container", "ContainerInterface", containerInterface_class_fuctions);
    zend_register_internal_interface(&ce TSRMLS_CC);

    INIT_NS_CLASS_ENTRY(ce, "Psr\\Container", "ContainerExceptionInterface", NULL);
    zend_register_internal_interface(&ce TSRMLS_CC);

    return SUCCESS;
}
/* }}} */
