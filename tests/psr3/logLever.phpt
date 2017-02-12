--TEST--
PSR-3 implementation: <http://www.php-fig.org/psr/psr-3/>
Psr\Log\LogLevel
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
echo ReflectionClass::export('\Psr\Log\LogLevel');
--EXPECT--
Class [ <internal:psr> class Psr\Log\LogLevel ] {

  - Constants [8] {
    Constant [ public string EMERGENCY ] { emergency }
    Constant [ public string ALERT ] { alert }
    Constant [ public string CRITICAL ] { critical }
    Constant [ public string ERROR ] { error }
    Constant [ public string WARNING ] { warning }
    Constant [ public string NOTICE ] { notice }
    Constant [ public string INFO ] { info }
    Constant [ public string DEBUG ] { debug }
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
