--TEST--
PSR-11 implementation: <https://github.com/container-interop/fig-standards/blob/master/proposed/container.md>
Psr\Container\ContainerInterface
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
echo ReflectionClass::export('\Psr\Container\ContainerInterface');
--EXPECT--
Interface [ <internal:psr> interface Psr\Container\ContainerInterface ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [2] {
    Method [ <internal:psr> abstract public method get ] {

      - Parameters [1] {
        Parameter #0 [ <required> $id ]
      }
    }

    Method [ <internal:psr> abstract public method has ] {

      - Parameters [1] {
        Parameter #0 [ <required> $id ]
      }
    }
  }
}
