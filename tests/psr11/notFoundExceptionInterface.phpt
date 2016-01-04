--TEST--
PSR-11 implementation: <https://github.com/container-interop/fig-standards/blob/master/proposed/container.md>
Psr\Container\NotFoundExceptionInterface
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
echo ReflectionClass::export('\Psr\Container\NotFoundExceptionInterface');
--EXPECT--
Interface [ <internal:psr> interface Psr\Container\NotFoundExceptionInterface extends Psr\Container\ContainerExceptionInterface ] {

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