--TEST--
PSR-0 implementation: <http://www.php-fig.org/psr/psr-0/>
Psr\Autoloader\Psr0->findFile()
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
$al = new Psr\Autoloader\Psr0();
var_dump(
    $al->findFile('\Foo')
);
--EXPECT--
string(7) "Foo.php"
