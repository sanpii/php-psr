--TEST--
PSR-13 implementation: <https://github.com/php-fig/fig-standards/blob/master/proposed/links.md>
Psr\Link\LinkCollectionInterface
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
echo ReflectionClass::export('\Psr\Link\LinkCollectionInterface');
--EXPECT--
Interface [ <internal:psr> interface Psr\Link\LinkCollectionInterface ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [2] {
    Method [ <internal:psr> abstract public method getLinks ] {
    }

    Method [ <internal:psr> abstract public method getLinksByRel ] {

      - Parameters [1] {
        Parameter #0 [ <required> $rel ]
      }
    }
  }
}
