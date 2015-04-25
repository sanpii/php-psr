--TEST--
PSR-4 implementation: <http://www.php-fig.org/psr/psr-4/>
Psr\Autoloader\Psr4
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
spl_autoload_register(function () {});

$al = new Psr\Autoloader\Psr4();
$al->register();
var_dump(spl_autoload_functions());
--EXPECT--
array(2) {
  [0]=>
  object(Closure)#1 (0) {
  }
  [1]=>
  array(2) {
    [0]=>
    object(Psr\Autoloader\Psr4)#2 (1) {
      ["prefixes":"Psr\Autoloader\Psr4":private]=>
      NULL
    }
    [1]=>
    string(9) "loadClass"
  }
}
