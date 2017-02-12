--TEST--
PSR-13 implementation: <https://github.com/php-fig/fig-standards/blob/master/accepted/PSR-13-links.md>
Psr\Link\EvolvableLinkInterface
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
echo ReflectionClass::export('\Psr\Link\EvolvableLinkInterface');
--EXPECT--
Interface [ <internal:psr> interface Psr\Link\EvolvableLinkInterface extends Psr\Link\LinkInterface ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [9] {
    Method [ <internal:psr> abstract public method withHref ] {

      - Parameters [1] {
        Parameter #0 [ <required> $href ]
      }
    }

    Method [ <internal:psr> abstract public method withRel ] {

      - Parameters [1] {
        Parameter #0 [ <required> $rel ]
      }
    }

    Method [ <internal:psr> abstract public method withoutRel ] {

      - Parameters [1] {
        Parameter #0 [ <required> $rel ]
      }
    }

    Method [ <internal:psr> abstract public method withAttribute ] {

      - Parameters [2] {
        Parameter #0 [ <required> $attribute ]
        Parameter #1 [ <required> $value ]
      }
    }

    Method [ <internal:psr> abstract public method withoutAttribute ] {

      - Parameters [1] {
        Parameter #0 [ <required> $attribute ]
      }
    }

    Method [ <internal:psr, inherits Psr\Link\LinkInterface> abstract public method getHref ] {
    }

    Method [ <internal:psr, inherits Psr\Link\LinkInterface> abstract public method isTemplated ] {
    }

    Method [ <internal:psr, inherits Psr\Link\LinkInterface> abstract public method getRels ] {
    }

    Method [ <internal:psr, inherits Psr\Link\LinkInterface> abstract public method getAttributes ] {
    }
  }
}
