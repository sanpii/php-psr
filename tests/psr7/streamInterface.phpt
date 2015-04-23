--TEST--
PSR-7 implementation: <https://github.com/php-fig/fig-standards/blob/master/proposed/http-message.md>
Psr\Http\Message\StreamInterface
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
echo ReflectionClass::export('\Psr\Http\Message\StreamInterface');
--EXPECT--
Interface [ <internal:psr> interface Psr\Http\Message\StreamInterface ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [14] {
    Method [ <internal:psr> abstract public method __toString ] {
    }

    Method [ <internal:psr> abstract public method close ] {
    }

    Method [ <internal:psr> abstract public method detach ] {
    }

    Method [ <internal:psr> abstract public method getSize ] {
    }

    Method [ <internal:psr> abstract public method tell ] {
    }

    Method [ <internal:psr> abstract public method eof ] {
    }

    Method [ <internal:psr> abstract public method isSeekable ] {
    }

    Method [ <internal:psr> abstract public method seek ] {

      - Parameters [2] {
        Parameter #0 [ <required> $offset ]
        Parameter #1 [ <optional> $whence ]
      }
    }

    Method [ <internal:psr> abstract public method rewind ] {
    }

    Method [ <internal:psr> abstract public method isWritable ] {
    }

    Method [ <internal:psr> abstract public method write ] {

      - Parameters [1] {
        Parameter #0 [ <required> $string ]
      }
    }

    Method [ <internal:psr> abstract public method isReadable ] {
    }

    Method [ <internal:psr> abstract public method read ] {

      - Parameters [1] {
        Parameter #0 [ <required> $length ]
      }
    }

    Method [ <internal:psr> abstract public method getContents ] {
    }
  }
}
