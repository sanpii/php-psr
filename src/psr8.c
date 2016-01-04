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

/* {{{ interface Psr\Hug\GroupHuggable */
ZEND_BEGIN_ARG_INFO(arginfo_group_huggable_grouphug, 0)
    ZEND_ARG_INFO(0, huggables)
ZEND_END_ARG_INFO()

static zend_function_entry group_huggable_class_fuctions[] = {
    PHP_ABSTRACT_ME(GroupHuggable, groupHug, arginfo_group_huggable_grouphug)
    PHP_FE_END
};
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(psr8)
{
    zend_class_entry ce;
    zend_class_entry* huggable = NULL;
    zend_class_entry* groupHuggable = NULL;

    INIT_NS_CLASS_ENTRY(ce, "Psr\\Hug", "Huggable", huggable_class_fuctions);
    huggable = zend_register_internal_interface(&ce TSRMLS_CC);

    INIT_NS_CLASS_ENTRY(ce, "Psr\\Hug", "GroupHuggable", group_huggable_class_fuctions);
    groupHuggable = zend_register_internal_interface(&ce TSRMLS_CC);
    zend_class_implements(groupHuggable, 1, huggable);

    return SUCCESS;
}
/* }}} */
