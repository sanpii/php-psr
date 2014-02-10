--TEST--
PSR-0 implementation: <http://www.php-fig.org/psr/psr-0/>
Psr\Autoloader
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
spl_autoload_register(function () {});

$al = new Psr\Autoloader();
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
    object(Psr\Autoloader)#2 (3) {
      ["namespaceSeparator":"Psr\Autoloader":private]=>
      string(1) "\"
      ["includePath":"Psr\Autoloader":private]=>
      NULL
      ["fileExtension":"Psr\Autoloader":private]=>
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
    object(Psr\Autoloader)#2 (3) {
      ["namespaceSeparator":"Psr\Autoloader":private]=>
      string(1) "\"
      ["includePath":"Psr\Autoloader":private]=>
      NULL
      ["fileExtension":"Psr\Autoloader":private]=>
      string(4) ".php"
    }
    [1]=>
    string(9) "loadClass"
  }
  [1]=>
  object(Closure)#1 (0) {
  }
}
