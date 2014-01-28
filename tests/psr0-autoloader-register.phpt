--TEST--
PSR-0 implementation: <http://www.php-fig.org/psr/psr-0/>
Psr\Autoloader
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
$al = new Psr\Autoloader();
$al->register();
var_dump(spl_autoload_functions());
$al->unregister();
var_dump(spl_autoload_functions());
--EXPECT--
array(1) {
  [0]=>
  array(2) {
    [0]=>
    object(Psr\Autoloader)#1 (3) {
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
array(0) {
}
