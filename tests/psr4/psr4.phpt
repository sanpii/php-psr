--TEST--
PSR-4 implementation: <http://www.php-fig.org/psr/psr-4/>
Psr\Autoloader\Psr4
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
$al = new Psr\Autoloader\Psr4();
--EXPECT--
