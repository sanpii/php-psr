--TEST--
PSR-6 implementation: <https://github.com/php-fig/fig-standards/blob/master/proposed/cache.md>
Psr\Cache\CacheException
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
echo ReflectionClass::export('\Psr\Cache\CacheException');
--EXPECT--
Interface [ <internal:psr> interface Psr\Cache\CacheException ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [0] {
  }
}
