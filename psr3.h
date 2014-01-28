#ifndef PHP_PSR_3_H
#define PHP_PSR_3_H

#include "php.h"

PHP_MINIT_FUNCTION(psr3);
zend_class_entry* ce_psr_loggerInterface;
zend_class_entry* ce_psr_loggerAwareInterface;
zend_class_entry* ce_psr_logLevel;

#endif /* PHP_PSR_3_H */
