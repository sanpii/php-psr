dnl $Id$
dnl config.m4 for extension psr

PHP_ARG_ENABLE(psr, whether to enable psr support,
[  --enable-psr           Enable psr support])

if test "$PHP_PSR" != "no"; then
  PHP_NEW_EXTENSION(psr, psr.c, $ext_shared)
fi
