--TEST--
PSR-13 implementation: <https://github.com/php-fig/fig-standards/blob/master/accepted/PSR-13-links.md>
Psr\Link\EvolvableLinkProviderInterface
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
echo ReflectionClass::export('\Psr\Link\EvolvableLinkProviderInterface');
--EXPECT--
Interface [ <internal:psr> interface Psr\Link\EvolvableLinkProviderInterface ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [2] {
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
  }
}

