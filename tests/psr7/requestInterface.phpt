--TEST--
PSR-7 implementation: <https://github.com/php-fig/fig-standards/blob/master/proposed/http-message.md>
Psr\Http\Message\RequestInterface
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
echo ReflectionClass::export('\Psr\Http\Message\RequestInterface');
--EXPECT--
Interface [ <internal:psr> interface Psr\Http\Message\RequestInterface extends Psr\Http\Message\MessageInterface ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [17] {
    Method [ <internal:psr> abstract public method getRequestTarget ] {
    }

    Method [ <internal:psr> abstract public method withRequestTarget ] {

      - Parameters [1] {
        Parameter #0 [ <required> $requestTarget ]
      }
    }

    Method [ <internal:psr> abstract public method getMethod ] {
    }

    Method [ <internal:psr> abstract public method withMethod ] {

      - Parameters [1] {
        Parameter #0 [ <required> $method ]
      }
    }

    Method [ <internal:psr> abstract public method getUri ] {
    }

    Method [ <internal:psr> abstract public method withUri ] {

      - Parameters [2] {
        Parameter #0 [ <required> Psr\Http\Message\UriInterface $uri ]
        Parameter #1 [ <optional> $preserveHost ]
      }
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
