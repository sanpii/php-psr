--TEST--
PSR-0 implementation: <http://www.php-fig.org/psr/psr-0/>
Psr\Autoloader\Psr0
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
$al = new Psr\Autoloader\Psr0();
$al->setNamespaceSeparator('_');
var_dump($al->getNamespaceSeparator());

$al = new Psr\Autoloader\Psr0();
$al->setIncludePath('lib');
var_dump($al->getIncludePath());

$al = new Psr\Autoloader\Psr0();
$al->setFileExtension('.inc');
var_dump($al->getFileExtension());
--EXPECT--
string(1) "_"
string(3) "lib"
string(4) ".inc"
