--TEST--
PSR-0 implementation: <http://www.php-fig.org/psr/psr-0/>
Psr\Autoloader
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
$al = new Psr\Autoloader();
var_dump(
    $al->getNamespaceSeparator(),
    $al->getIncludePath(),
    $al->getFileExtension()
);
--EXPECT--
string(1) "\"
NULL
string(4) ".php"
