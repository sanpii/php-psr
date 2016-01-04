--TEST--
PSR-8 implementation: <https://github.com/php-fig/fig-standards/blob/master/proposed/psr-8-hug/psr-8-hug.md>
Psr\Hug\GroupHuggable
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
echo ReflectionClass::export('\Psr\Hug\GroupHuggable');
--EXPECT--
Interface [ <internal:psr> interface Psr\Hug\GroupHuggable extends Psr\Hug\Huggable ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [2] {
    Method [ <internal:psr> abstract public method groupHug ] {

      - Parameters [1] {
        Parameter #0 [ <required> $huggables ]
      }
    }

    Method [ <internal:psr, inherits Psr\Hug\Huggable> abstract public method hug ] {

      - Parameters [1] {
        Parameter #0 [ <required> Psr\Hug\Huggable $h ]
      }
    }
  }
}
