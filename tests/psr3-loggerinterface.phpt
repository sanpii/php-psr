--TEST--
PSR-3 implementation: <http://www.php-fig.org/psr/psr-3/>
Psr\Log\LoggerInterface
--FILE--
<?php
echo ReflectionClass::export('\Psr\Log\LoggerInterface');
--EXPECT--
Interface [ <internal:psr> interface Psr\Log\LoggerInterface ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [9] {
    Method [ <internal:psr> abstract public method emergency ] {

      - Parameters [2] {
        Parameter #0 [ <required> $message ]
        Parameter #1 [ <required> array or NULL $context ]
      }
    }

    Method [ <internal:psr> abstract public method alert ] {

      - Parameters [2] {
        Parameter #0 [ <required> $message ]
        Parameter #1 [ <required> array or NULL $context ]
      }
    }

    Method [ <internal:psr> abstract public method critical ] {

      - Parameters [2] {
        Parameter #0 [ <required> $message ]
        Parameter #1 [ <required> array or NULL $context ]
      }
    }

    Method [ <internal:psr> abstract public method error ] {

      - Parameters [2] {
        Parameter #0 [ <required> $message ]
        Parameter #1 [ <required> array or NULL $context ]
      }
    }

    Method [ <internal:psr> abstract public method warning ] {

      - Parameters [2] {
        Parameter #0 [ <required> $message ]
        Parameter #1 [ <required> array or NULL $context ]
      }
    }

    Method [ <internal:psr> abstract public method notice ] {

      - Parameters [2] {
        Parameter #0 [ <required> $message ]
        Parameter #1 [ <required> array or NULL $context ]
      }
    }

    Method [ <internal:psr> abstract public method info ] {

      - Parameters [2] {
        Parameter #0 [ <required> $message ]
        Parameter #1 [ <required> array or NULL $context ]
      }
    }

    Method [ <internal:psr> abstract public method debug ] {

      - Parameters [2] {
        Parameter #0 [ <required> $message ]
        Parameter #1 [ <required> array or NULL $context ]
      }
    }

    Method [ <internal:psr> abstract public method log ] {

      - Parameters [3] {
        Parameter #0 [ <required> $level ]
        Parameter #1 [ <required> $message ]
        Parameter #2 [ <required> array or NULL $context ]
      }
    }
  }
}
