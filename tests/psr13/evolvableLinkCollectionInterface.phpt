--TEST--
PSR-13 implementation: <https://github.com/php-fig/fig-standards/blob/master/proposed/links.md>
Psr\Link\EvolvableLinkCollectionInterface
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
echo ReflectionClass::export('\Psr\Link\EvolvableLinkCollectionInterface');
--EXPECT--
Interface [ <internal:psr> interface Psr\Link\EvolvableLinkCollectionInterface extends Psr\Link\LinkCollectionInterface ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [4] {
    Method [ <internal:psr> abstract public method withLink ] {

      - Parameters [1] {
        Parameter #0 [ <required> Psr\Link\LinkInterface $link ]
      }
    }

    Method [ <internal:psr> abstract public method withoutLink ] {

      - Parameters [1] {
        Parameter #0 [ <required> Psr\Link\LinkInterface $link ]
      }
    }

    Method [ <internal:psr, inherits Psr\Link\LinkCollectionInterface> abstract public method getLinks ] {
    }

    Method [ <internal:psr, inherits Psr\Link\LinkCollectionInterface> abstract public method getLinksByRel ] {

      - Parameters [1] {
        Parameter #0 [ <required> $rel ]
      }
    }
  }
}
