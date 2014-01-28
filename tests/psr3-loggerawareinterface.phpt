--TEST--
PSR-3 implementation: <http://www.php-fig.org/psr/psr-3/>
Psr\Log\LoggerAwareInterface
--FILE--
<?php
echo ReflectionClass::export('\Psr\Log\LoggerAwareInterface');
--EXPECT--
Interface [ <internal:psr> interface Psr\Log\LoggerAwareInterface ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [1] {
    Method [ <internal:psr> abstract public method setLogger ] {

      - Parameters [1] {
        Parameter #0 [ <required> Psr\Log\LoggerInterface $logger ]
      }
    }
  }
}
