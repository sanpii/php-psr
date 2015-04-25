--TEST--
PSR-4 implementation: <http://www.php-fig.org/psr/psr-4/>
Psr\Autoloader\Psr4::loadClass
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
$al = new Psr\Autoloader\Psr4();
var_dump(class_exists('Foo\Bar\ClassName'));

$al->addNamespace('Foo', '/vendor/foo/src');
var_dump(
    $al->loadClass('Foo\Bar\ClassName')
);

$al->addNamespace('Foo\Bar', './tests/psr4');
$al->addNamespace('Foo\Bar', '/vendor/foo.bar/src2');
$al->addNamespace('Foo\Bar', '/vendor/foo.bar/src0', true);
var_dump(
    $al
);

var_dump(
    $al->loadClass('Foo\Bar\ClassName')
);
var_dump(class_exists('Foo\Bar\ClassName'));
--EXPECT--
bool(false)
bool(false)
object(Psr\Autoloader\Psr4)#1 (1) {
  ["prefixes":"Psr\Autoloader\Psr4":private]=>
  array(2) {
    ["Foo"]=>
    array(1) {
      [0]=>
      string(15) "/vendor/foo/src"
    }
    ["Foo\Bar"]=>
    array(3) {
      [0]=>
      string(20) "/vendor/foo.bar/src0"
      [1]=>
      string(12) "./tests/psr4"
      [2]=>
      string(20) "/vendor/foo.bar/src2"
    }
  }
}
bool(true)
bool(true)
