#ifndef PHP_PSR_0_H
#define PHP_PSR_0_H

#include "php.h"

PHP_MINIT_FUNCTION(psr0);
zend_class_entry* ce_psr_autoloader;

#endif /* PHP_PSR_0_H */
