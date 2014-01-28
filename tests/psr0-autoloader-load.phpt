--TEST--
PSR-0 implementation: <http://www.php-fig.org/psr/psr-0/>
Psr\Autoloader->loadClass()
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
$al = new Psr\Autoloader();
var_dump(class_exists('Foo'));
$al->loadClass('\Foo');
var_dump(class_exists('Foo'));
--EXPECT--
bool(false)
bool(true)
