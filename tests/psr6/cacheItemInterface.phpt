--TEST--
PSR-6 implementation: <https://github.com/php-fig/fig-standards/blob/master/proposed/cache.md>
Psr\Cache\CacheItemInterface
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
echo ReflectionClass::export('\Psr\Cache\CacheItemInterface');
--EXPECT--
Interface [ <internal:psr> interface Psr\Cache\CacheItemInterface ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [6] {
    Method [ <internal:psr> abstract public method getKey ] {
    }

    Method [ <internal:psr> abstract public method get ] {
    }

    Method [ <internal:psr> abstract public method isHit ] {
    }

    Method [ <internal:psr> abstract public method set ] {

      - Parameters [1] {
        Parameter #0 [ <required> $value ]
      }
    }

    Method [ <internal:psr> abstract public method expiresAt ] {

      - Parameters [1] {
        Parameter #0 [ <required> $expiration ]
      }
    }

    Method [ <internal:psr> abstract public method expiresAfter ] {

      - Parameters [1] {
        Parameter #0 [ <required> $time ]
      }
    }
  }
}
