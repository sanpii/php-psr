dnl $Id$
dnl config.m4 for extension psr

PHP_ARG_ENABLE(psr, whether to enable psr support,
[  --enable-psr           Enable psr support])

if test "$PHP_PSR" != "no"; then
  PHP_NEW_EXTENSION(psr, src/psr.c src/psr0.c src/psr3.c src/psr4.c src/psr6.c src/psr7.c src/psr13.c src/psr16.c, $ext_shared)
fi
