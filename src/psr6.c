#ifdef HAVE_CONFIG_H
#    include "config.h"
#endif

#include "psr6.h"

/* {{{ interface Psr\Cache\CacheItemInterface */
ZEND_BEGIN_ARG_INFO(arginfo_cacheItemInterface_set, 0)
    ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_cacheItemInterface_expiresAt, 0)
    ZEND_ARG_INFO(0, expiration)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_cacheItemInterface_expiresAfter, 0)
    ZEND_ARG_INFO(0, time)
ZEND_END_ARG_INFO()

static zend_function_entry cacheItemInterface_class_fuctions[] = {
    PHP_ABSTRACT_ME(CacheItemInterface, getKey, NULL)
    PHP_ABSTRACT_ME(CacheItemInterface, get, NULL)
    PHP_ABSTRACT_ME(CacheItemInterface, isHit, NULL)
    PHP_ABSTRACT_ME(CacheItemInterface, set, arginfo_cacheItemInterface_set)
    PHP_ABSTRACT_ME(CacheItemInterface, expiresAt, arginfo_cacheItemInterface_expiresAt)
    PHP_ABSTRACT_ME(CacheItemInterface, expiresAfter, arginfo_cacheItemInterface_expiresAfter)
    PHP_FE_END
};
/* }}} */

/* {{{ interface Psr\Cache\CacheItemPoolInterface */
ZEND_BEGIN_ARG_INFO(arginfo_cacheItemInterface_getItem, 0)
    ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cacheItemInterface_getItems, 0, ZEND_RETURN_VALUE, 0)
    ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_cacheItemInterface_hasItem, 0)
    ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_cacheItemInterface_deleteItem, 0)
    ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_cacheItemInterface_deleteItems, 0)
    ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_cacheItemInterface_save, 0)
    ZEND_ARG_OBJ_INFO(0, item, Psr\\Cache\\CacheItemInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_cacheItemInterface_saveDeferred, 0)
    ZEND_ARG_OBJ_INFO(0, item, Psr\\Cache\\CacheItemInterface, 0)
ZEND_END_ARG_INFO()

static zend_function_entry cacheItemPoolInterface_class_fuctions[] = {
    PHP_ABSTRACT_ME(CacheItemPoolInterface, getItem, arginfo_cacheItemInterface_getItem)
    PHP_ABSTRACT_ME(CacheItemPoolInterface, getItems, arginfo_cacheItemInterface_getItems)
    PHP_ABSTRACT_ME(CacheItemPoolInterface, hasItem, arginfo_cacheItemInterface_hasItem)
    PHP_ABSTRACT_ME(CacheItemPoolInterface, clear, NULL)
    PHP_ABSTRACT_ME(CacheItemPoolInterface, deleteItem, arginfo_cacheItemInterface_deleteItem)
    PHP_ABSTRACT_ME(CacheItemPoolInterface, deleteItems, arginfo_cacheItemInterface_deleteItems)
    PHP_ABSTRACT_ME(CacheItemPoolInterface, save, arginfo_cacheItemInterface_save)
    PHP_ABSTRACT_ME(CacheItemPoolInterface, saveDeferred, arginfo_cacheItemInterface_saveDeferred)
    PHP_ABSTRACT_ME(CacheItemPoolInterface, commit, NULL)
    PHP_FE_END
};
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(psr6)
{
    zend_class_entry ce;
    zend_class_entry *cacheException = NULL;
    zend_class_entry *invalidArgumentException = NULL;

    INIT_NS_CLASS_ENTRY(ce, "Psr\\Cache", "CacheItemInterface", cacheItemInterface_class_fuctions);
    zend_register_internal_interface(&ce TSRMLS_CC);

    INIT_NS_CLASS_ENTRY(ce, "Psr\\Cache", "CacheItemPoolInterface", cacheItemPoolInterface_class_fuctions);
    zend_register_internal_interface(&ce TSRMLS_CC);

    INIT_NS_CLASS_ENTRY(ce, "Psr\\Cache", "CacheException", NULL);
    cacheException = zend_register_internal_interface(&ce TSRMLS_CC);

    INIT_NS_CLASS_ENTRY(ce, "Psr\\Cache", "InvalidArgumentException", NULL);
    invalidArgumentException = zend_register_internal_interface(&ce TSRMLS_CC);
    zend_class_implements(invalidArgumentException, 1, cacheException);

    return SUCCESS;
}
/* }}} */
