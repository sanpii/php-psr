#ifdef HAVE_CONFIG_H
#    include "config.h"
#endif

#include "psr8.h"

/* {{{ interface Psr\Hug\Huggable */
ZEND_BEGIN_ARG_INFO(arginfo_huggable_hug, 0)
    ZEND_ARG_OBJ_INFO(0, h, Psr\\Hug\\Huggable, 0)
ZEND_END_ARG_INFO()

static zend_function_entry huggable_class_fuctions[] = {
    PHP_ABSTRACT_ME(Huggable, hug, arginfo_huggable_hug)
    PHP_FE_END
};
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(psr8)
{
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, "Psr\\Hug", "Huggable", huggable_class_fuctions);
    zend_register_internal_interface(&ce TSRMLS_CC);

    return SUCCESS;
}
/* }}} */
