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

/* {{{ interface Psr\Link\LinkCollectionInterface */
ZEND_BEGIN_ARG_INFO(arginfo_linkCollectionInterface_getLinksByRel, 0)
    ZEND_ARG_INFO(0, rel)
ZEND_END_ARG_INFO()

static zend_function_entry linkCollectionInterface_class_fuctions[] = {
    PHP_ABSTRACT_ME(LinkInterface, getLinks, NULL)
    PHP_ABSTRACT_ME(LinkInterface, getLinksByRel, arginfo_linkCollectionInterface_getLinksByRel)
    PHP_FE_END
};
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(psr13)
{
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, "Psr\\Link", "LinkInterface", linkInterface_class_fuctions);
    zend_register_internal_interface(&ce TSRMLS_CC);

    INIT_NS_CLASS_ENTRY(ce, "Psr\\Link", "LinkCollectionInterface", linkCollectionInterface_class_fuctions);
    zend_register_internal_interface(&ce TSRMLS_CC);

    return SUCCESS;
}
/* }}} */
