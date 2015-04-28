--TEST--
PSR-6 implementation: <https://github.com/php-fig/fig-standards/blob/master/proposed/cache.md>
Psr\Cache\CacheItemPoolInterface
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
echo ReflectionClass::export('\Psr\Cache\CacheItemPoolInterface');
--EXPECT--
Interface [ <internal:psr> interface Psr\Cache\CacheItemPoolInterface ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [9] {
    Method [ <internal:psr> abstract public method getItem ] {

      - Parameters [1] {
        Parameter #0 [ <required> $key ]
      }
    }

    Method [ <internal:psr> abstract public method getItems ] {

      - Parameters [1] {
        Parameter #0 [ <optional> array $keys ]
      }
    }

    Method [ <internal:psr> abstract public method hasItem ] {

      - Parameters [1] {
        Parameter #0 [ <required> $key ]
      }
    }

    Method [ <internal:psr> abstract public method clear ] {
    }

    Method [ <internal:psr> abstract public method deleteItem ] {

      - Parameters [1] {
        Parameter #0 [ <required> $key ]
      }
    }

    Method [ <internal:psr> abstract public method deleteItems ] {

      - Parameters [1] {
        Parameter #0 [ <required> array $keys ]
      }
    }

    Method [ <internal:psr> abstract public method save ] {

      - Parameters [1] {
        Parameter #0 [ <required> Psr\Cache\CacheItemInterface $item ]
      }
    }

    Method [ <internal:psr> abstract public method saveDeferred ] {

      - Parameters [1] {
        Parameter #0 [ <required> Psr\Cache\CacheItemInterface $item ]
      }
    }

    Method [ <internal:psr> abstract public method commit ] {
    }
  }
}
