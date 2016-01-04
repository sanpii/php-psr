#ifdef HAVE_CONFIG_H
#    include "config.h"
#endif

#include "psr13.h"

/* {{{ interface Psr\Link\LinkInterface */
static zend_function_entry linkInterface_class_fuctions[] = {
    PHP_ABSTRACT_ME(LinkInterface, getHref, NULL)
    PHP_ABSTRACT_ME(LinkInterface, isTemplated, NULL)
    PHP_ABSTRACT_ME(LinkInterface, getRels, NULL)
    PHP_ABSTRACT_ME(LinkInterface, getAttributes, NULL)
    PHP_FE_END
};
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(psr13)
{
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, "Psr\\Link", "LinkInterface", linkInterface_class_fuctions);
    zend_register_internal_interface(&ce TSRMLS_CC);

    return SUCCESS;
}
/* }}} */
