--TEST--
PSR-7 implementation: <https://github.com/php-fig/fig-standards/blob/master/proposed/http-message.md>
Psr\Http\Message\ResponseInterface
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
echo ReflectionClass::export('\Psr\Http\Message\ResponseInterface');
--EXPECT--
Interface [ <internal:psr> interface Psr\Http\Message\ResponseInterface extends Psr\Http\Message\MessageInterface ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [14] {
    Method [ <internal:psr> abstract public method getStatusCode ] {
    }

    Method [ <internal:psr> abstract public method withStatus ] {

      - Parameters [2] {
        Parameter #0 [ <required> $code ]
        Parameter #1 [ <optional> $reasonPhrase ]
      }
    }

    Method [ <internal:psr> abstract public method getReasonPhrase ] {
    }

    Method [ <internal:psr, inherits Psr\Http\Message\MessageInterface> abstract public method getProtocolVersion ] {
    }

    Method [ <internal:psr, inherits Psr\Http\Message\MessageInterface> abstract public method withProtocolVersion ] {

      - Parameters [1] {
        Parameter #0 [ <required> $version ]
      }
    }

    Method [ <internal:psr, inherits Psr\Http\Message\MessageInterface> abstract public method getHeaders ] {
    }

    Method [ <internal:psr, inherits Psr\Http\Message\MessageInterface> abstract public method hasHeader ] {

      - Parameters [1] {
        Parameter #0 [ <required> $name ]
      }
    }

    Method [ <internal:psr, inherits Psr\Http\Message\MessageInterface> abstract public method getHeader ] {

      - Parameters [1] {
        Parameter #0 [ <required> $name ]
      }
    }

    Method [ <internal:psr, inherits Psr\Http\Message\MessageInterface> abstract public method getHeaderLine ] {

      - Parameters [1] {
        Parameter #0 [ <required> $name ]
      }
    }

    Method [ <internal:psr, inherits Psr\Http\Message\MessageInterface> abstract public method withHeader ] {

      - Parameters [2] {
        Parameter #0 [ <required> $name ]
        Parameter #1 [ <required> $value ]
      }
    }

    Method [ <internal:psr, inherits Psr\Http\Message\MessageInterface> abstract public method withAddedHeader ] {

      - Parameters [2] {
        Parameter #0 [ <required> $name ]
        Parameter #1 [ <required> $value ]
      }
    }

    Method [ <internal:psr, inherits Psr\Http\Message\MessageInterface> abstract public method withoutHeader ] {

      - Parameters [1] {
        Parameter #0 [ <required> $name ]
      }
    }

    Method [ <internal:psr, inherits Psr\Http\Message\MessageInterface> abstract public method getBody ] {
    }

    Method [ <internal:psr, inherits Psr\Http\Message\MessageInterface> abstract public method withBody ] {

      - Parameters [1] {
        Parameter #0 [ <required> Psr\Http\Message\StreamInterface $body ]
      }
    }
  }
}
