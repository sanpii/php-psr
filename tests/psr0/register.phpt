--TEST--
PSR-0 implementation: <http://www.php-fig.org/psr/psr-0/>
Psr\Autoloader\Psr0
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
spl_autoload_register(function () {});

$al = new Psr\Autoloader\Psr0();
$al->register();
var_dump(spl_autoload_functions());
$al->unregister();
var_dump(spl_autoload_functions());
$al->register(true);
var_dump(spl_autoload_functions());
--EXPECT--
array(2) {
  [0]=>
  object(Closure)#1 (0) {
  }
  [1]=>
  array(2) {
    [0]=>
    object(Psr\Autoloader\Psr0)#2 (3) {
      ["namespaceSeparator":"Psr\Autoloader\Psr0":private]=>
      string(1) "\"
      ["includePath":"Psr\Autoloader\Psr0":private]=>
      NULL
      ["fileExtension":"Psr\Autoloader\Psr0":private]=>
      string(4) ".php"
    }
    [1]=>
    string(9) "loadClass"
  }
}
array(1) {
  [0]=>
  object(Closure)#1 (0) {
  }
}
array(2) {
  [0]=>
  array(2) {
    [0]=>
    object(Psr\Autoloader\Psr0)#2 (3) {
      ["namespaceSeparator":"Psr\Autoloader\Psr0":private]=>
      string(1) "\"
      ["includePath":"Psr\Autoloader\Psr0":private]=>
      NULL
      ["fileExtension":"Psr\Autoloader\Psr0":private]=>
      string(4) ".php"
    }
    [1]=>
    string(9) "loadClass"
  }
  [1]=>
  object(Closure)#1 (0) {
  }
}
