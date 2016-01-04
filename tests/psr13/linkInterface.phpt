--TEST--
PSR-6 implementation: <https://github.com/php-fig/fig-standards/blob/master/proposed/cache.md>
Psr\Http\Link\LinkInterface
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
echo ReflectionClass::export('\Psr\Http\Link\LinkInterface');
--EXPECT--
Interface [ <internal:psr> interface Psr\Http\Link\LinkInterface ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [3] {
    Method [ <internal:psr> abstract public method getHref ] {
    }

    Method [ <internal:psr> abstract public method getRel ] {
    }

    Method [ <internal:psr> abstract public method getAttributes ] {
    }
  }
}
