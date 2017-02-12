--TEST--
PSR-16 implementation: <https://github.com/php-fig/fig-standards/blob/master/accepted/PSR-16-simple-cache.md>
Psr\Cache\InvalidArgumentException
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
echo ReflectionClass::export('\Psr\SimpleCache\InvalidArgumentException');
--EXPECT--
Interface [ <internal:psr> interface Psr\SimpleCache\InvalidArgumentException extends Psr\SimpleCache\CacheException ] {

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
