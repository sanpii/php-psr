--TEST--
PSR-7 implementation: <https://github.com/php-fig/fig-standards/blob/master/proposed/http-message.md>
Psr\Http\Message\UploadedFileInterface
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
echo ReflectionClass::export('\Psr\Http\Message\UploadedFileInterface');
--EXPECT--
Interface [ <internal:psr> interface Psr\Http\Message\UploadedFileInterface ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [6] {
    Method [ <internal:psr> abstract public method getStream ] {
    }

    Method [ <internal:psr> abstract public method move ] {

      - Parameters [1] {
        Parameter #0 [ <required> $path ]
      }
    }

    Method [ <internal:psr> abstract public method getSize ] {
    }

    Method [ <internal:psr> abstract public method getError ] {
    }

    Method [ <internal:psr> abstract public method getClientFilename ] {
    }

    Method [ <internal:psr> abstract public method getClientMediaType ] {
    }
  }
}
