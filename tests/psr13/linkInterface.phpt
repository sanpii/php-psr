--TEST--
PSR-13 implementation: <https://github.com/php-fig/fig-standards/blob/master/accepted/PSR-13-links.md>
Psr\Link\LinkInterface
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
echo ReflectionClass::export('\Psr\Link\LinkInterface');
--EXPECT--
Interface [ <internal:psr> interface Psr\Link\LinkInterface ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [4] {
    Method [ <internal:psr> abstract public method getHref ] {
    }

    Method [ <internal:psr> abstract public method isTemplated ] {
    }

    Method [ <internal:psr> abstract public method getRels ] {
    }

    Method [ <internal:psr> abstract public method getAttributes ] {
    }
  }
}
