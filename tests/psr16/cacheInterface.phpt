--TEST--
PSR-16 implementation: <https://github.com/php-fig/fig-standards/blob/master/accepted/PSR-16-simple-cache.md>
Psr\SimpleCache\CacheInterface
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
echo ReflectionClass::export('\Psr\SimpleCache\CacheInterface');
--EXPECT--
Interface [ <internal:psr> interface Psr\SimpleCache\CacheInterface ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [8] {
    Method [ <internal:psr> abstract public method get ] {

      - Parameters [2] {
        Parameter #0 [ <required> $key ]
        Parameter #1 [ <optional> $default ]
      }
    }

    Method [ <internal:psr> abstract public method set ] {

      - Parameters [3] {
        Parameter #0 [ <required> $key ]
        Parameter #1 [ <required> $value ]
        Parameter #2 [ <optional> $ttl ]
      }
    }

    Method [ <internal:psr> abstract public method delete ] {

      - Parameters [1] {
        Parameter #0 [ <required> $key ]
      }
    }

    Method [ <internal:psr> abstract public method clear ] {
    }

    Method [ <internal:psr> abstract public method getMultiple ] {

      - Parameters [2] {
        Parameter #0 [ <required> $keys ]
        Parameter #1 [ <optional> $default ]
      }
    }

    Method [ <internal:psr> abstract public method setMultiple ] {

      - Parameters [2] {
        Parameter #0 [ <required> $values ]
        Parameter #1 [ <optional> $ttl ]
      }
    }

    Method [ <internal:psr> abstract public method deleteMultiple ] {

      - Parameters [1] {
        Parameter #0 [ <required> $keys ]
      }
    }

    Method [ <internal:psr> abstract public method has ] {

      - Parameters [1] {
        Parameter #0 [ <required> $key ]
      }
    }
  }
}
