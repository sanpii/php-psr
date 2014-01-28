--TEST--
PSR-3 implementation: <http://www.php-fig.org/psr/psr-3/>
Psr\Log\LogLevel
--FILE--
<?php
echo ReflectionClass::export('\Psr\Log\LogLevel');
--EXPECT--
Class [ <internal:psr> class Psr\Log\LogLevel ] {

  - Constants [8] {
    Constant [ string EMERGENCY ] { emergency }
    Constant [ string ALERT ] { alert }
    Constant [ string CRITICAL ] { critical }
    Constant [ string ERROR ] { error }
    Constant [ string WARNING ] { warning }
    Constant [ string NOTICE ] { notice }
    Constant [ string INFO ] { info }
    Constant [ string DEBUG ] { debug }
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
