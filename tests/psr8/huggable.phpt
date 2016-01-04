--TEST--
PSR-8 implementation: <https://github.com/php-fig/fig-standards/blob/master/proposed/psr-8-hug/psr-8-hug.md>
Psr\Hug\Huggable
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
echo ReflectionClass::export('\Psr\Hug\Huggable');
--EXPECT--
Interface [ <internal:psr> interface Psr\Hug\Huggable ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [1] {
    Method [ <internal:psr> abstract public method hug ] {

      - Parameters [1] {
        Parameter #0 [ <required> Psr\Hug\Huggable $h ]
      }
    }
  }
}
