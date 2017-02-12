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

/* {{{ interface Psr\Link\EvolvableLinkInterface */
ZEND_BEGIN_ARG_INFO(arginfo_evolvableLinkInterface_withHref, 0)
    ZEND_ARG_INFO(0, href)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_evolvableLinkInterface_withRel, 0)
    ZEND_ARG_INFO(0, rel)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_evolvableLinkInterface_withoutRel, 0)
    ZEND_ARG_INFO(0, rel)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_evolvableLinkInterface_withAttribute, 0)
    ZEND_ARG_INFO(0, attribute)
    ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_evolvableLinkInterface_withoutAttribute, 0)
    ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

static zend_function_entry evolvableLinkInterface_class_fuctions[] = {
    PHP_ABSTRACT_ME(EvolvableLinkInterface, withHref, arginfo_evolvableLinkInterface_withHref)
    PHP_ABSTRACT_ME(EvolvableLinkInterface, withRel, arginfo_evolvableLinkInterface_withRel)
    PHP_ABSTRACT_ME(EvolvableLinkInterface, withoutRel, arginfo_evolvableLinkInterface_withoutRel)
    PHP_ABSTRACT_ME(EvolvableLinkInterface, withAttribute, arginfo_evolvableLinkInterface_withAttribute)
    PHP_ABSTRACT_ME(EvolvableLinkInterface, withoutAttribute, arginfo_evolvableLinkInterface_withoutAttribute)
    PHP_FE_END
};
/* }}} */

/* {{{ interface Psr\Link\LinkProviderInterface */
ZEND_BEGIN_ARG_INFO(arginfo_linkProviderInterface_getLinksByRel, 0)
    ZEND_ARG_INFO(0, rel)
ZEND_END_ARG_INFO()

static zend_function_entry linkProviderInterface_class_fuctions[] = {
    PHP_ABSTRACT_ME(LinkProviderInterface, getLinks, NULL)
    PHP_ABSTRACT_ME(LinkProviderInterface, getLinksByRel, arginfo_linkProviderInterface_getLinksByRel)
    PHP_FE_END
};
/* }}} */

/* {{{ interface Psr\Link\EvolvableLinkProviderInterface */
ZEND_BEGIN_ARG_INFO(arginfo_evolvableLinkProviderInterface_withLink, 0)
    ZEND_ARG_OBJ_INFO(0, link, Psr\\Link\\LinkInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_evolvableLinkProviderInterface_withoutLink, 0)
    ZEND_ARG_OBJ_INFO(0, link, Psr\\Link\\LinkInterface, 0)
ZEND_END_ARG_INFO()

static zend_function_entry evolvableLinkProviderInterface_class_fuctions[] = {
    PHP_ABSTRACT_ME(EvolvableLinkProviderInterface, withLink, arginfo_evolvableLinkProviderInterface_withLink)
    PHP_ABSTRACT_ME(EvolvableLinkProviderInterface, withoutLink, arginfo_evolvableLinkProviderInterface_withoutLink)
    PHP_FE_END
};
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(psr13)
{
    zend_class_entry ce;
    zend_class_entry *linkInterface = NULL;
    zend_class_entry *evolvableLinkInterface = NULL;

    INIT_NS_CLASS_ENTRY(ce, "Psr\\Link", "LinkInterface", linkInterface_class_fuctions);
    linkInterface = zend_register_internal_interface(&ce TSRMLS_CC);

    INIT_NS_CLASS_ENTRY(ce, "Psr\\Link", "EvolvableLinkInterface", evolvableLinkInterface_class_fuctions);
    evolvableLinkInterface = zend_register_internal_interface(&ce TSRMLS_CC);
    zend_class_implements(evolvableLinkInterface, 1, linkInterface);

    INIT_NS_CLASS_ENTRY(ce, "Psr\\Link", "LinkProviderInterface", linkProviderInterface_class_fuctions);
    linkInterface = zend_register_internal_interface(&ce TSRMLS_CC);

    INIT_NS_CLASS_ENTRY(ce, "Psr\\Link", "EvolvableLinkProviderInterface", evolvableLinkProviderInterface_class_fuctions);
    linkInterface = zend_register_internal_interface(&ce TSRMLS_CC);

    return SUCCESS;
}
/* }}} */
