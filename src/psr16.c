#ifdef HAVE_CONFIG_H
#    include "config.h"
#endif

#include "psr16.h"

/* {{{ interface Psr\SimpleCache\CacheInterface */
ZEND_BEGIN_ARG_INFO_EX(arginfo_cacheInterface_get, 0, ZEND_RETURN_VALUE, 1)
    ZEND_ARG_INFO(0, key)
    ZEND_ARG_INFO(0, default)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cacheInterface_set, 0, ZEND_RETURN_VALUE, 2)
    ZEND_ARG_INFO(0, key)
    ZEND_ARG_INFO(0, value)
    ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_cacheInterface_delete, 0)
    ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cacheInterface_getMultiples, 0, ZEND_RETURN_VALUE, 1)
    ZEND_ARG_INFO(0, keys)
    ZEND_ARG_INFO(0, default)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_cacheInterface_setMultiples, 0, ZEND_RETURN_VALUE, 1)
    ZEND_ARG_INFO(0, values)
    ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_cacheInterface_deleteMultiples, 0)
    ZEND_ARG_INFO(0, keys)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_cacheInterface_has, 0)
    ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

static zend_function_entry cacheInterface_class_fuctions[] = {
    PHP_ABSTRACT_ME(CacheInterface, get, arginfo_cacheInterface_get)
    PHP_ABSTRACT_ME(CacheInterface, set, arginfo_cacheInterface_set)
    PHP_ABSTRACT_ME(CacheInterface, delete, arginfo_cacheInterface_delete)
    PHP_ABSTRACT_ME(CacheInterface, clear, NULL)
    PHP_ABSTRACT_ME(CacheInterface, getMultiple, arginfo_cacheInterface_getMultiples)
    PHP_ABSTRACT_ME(CacheInterface, setMultiple, arginfo_cacheInterface_setMultiples)
    PHP_ABSTRACT_ME(CacheInterface, deleteMultiple, arginfo_cacheInterface_deleteMultiples)
    PHP_ABSTRACT_ME(CacheInterface, has, arginfo_cacheInterface_has)
    PHP_FE_END
};
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(psr16)
{
    zend_class_entry ce;
    zend_class_entry *cacheException = NULL;
    zend_class_entry *invalidArgumentException = NULL;

    INIT_NS_CLASS_ENTRY(ce, "Psr\\SimpleCache", "CacheInterface", cacheInterface_class_fuctions);
    zend_register_internal_interface(&ce TSRMLS_CC);

    INIT_NS_CLASS_ENTRY(ce, "Psr\\SimpleCache", "CacheException", NULL);
    cacheException = zend_register_internal_interface(&ce TSRMLS_CC);

    return SUCCESS;
}
/* }}} */
