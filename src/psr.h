#ifndef PHP_PSR_H
#define PHP_PSR_H

extern zend_module_entry psr_module_entry;
#define phpext_psr_ptr &psr_module_entry

#define PHP_PSR_VERSION "1.0.0"

#ifdef PHP_WIN32
#    define PHP_PSR_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#    define PHP_PSR_API __attribute__ ((visibility("default")))
#else
#    define PHP_PSR_API
#endif

#ifdef ZTS
#    include "TSRM.h"
#endif

#ifdef ZTS
#    define PSR_G(v) TSRMG(psr_globals_id, zend_psr_globals *, v)
#else
#    define PSR_G(v) (psr_globals.v)
#endif

#endif /* PHP_PSR_H */
