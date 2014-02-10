#ifndef PHP_PSR_AUTOLOADER_H
#define PHP_PSR_AUTOLOADER_H

#include "php.h"

PHP_MINIT_FUNCTION(psr_autoloader);
zend_class_entry* ce_psr_autoloader;

#endif /* PHP_PSR_AUTOLOADER_H */
