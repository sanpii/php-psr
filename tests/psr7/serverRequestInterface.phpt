--TEST--
PSR-7 implementation: <https://github.com/php-fig/fig-standards/blob/master/proposed/http-message.md>
Psr\Http\Message\ServerRequestInterface
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
echo ReflectionClass::export('\Psr\Http\Message\ServerRequestInterface');
--EXPECT--
Interface [ <internal:psr> interface Psr\Http\Message\ServerRequestInterface extends Psr\Http\Message\RequestInterface, Psr\Http\Message\MessageInterface ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [30] {
    Method [ <internal:psr> abstract public method getServerParams ] {
    }

    Method [ <internal:psr> abstract public method getCookieParams ] {
    }

    Method [ <internal:psr> abstract public method withCookieParams ] {

      - Parameters [1] {
        Parameter #0 [ <required> array $cookies ]
      }
    }

    Method [ <internal:psr> abstract public method getQueryParams ] {
    }

    Method [ <internal:psr> abstract public method withQueryParams ] {

      - Parameters [1] {
        Parameter #0 [ <required> array $query ]
      }
    }

    Method [ <internal:psr> abstract public method getUploadedFiles ] {
    }

    Method [ <internal:psr> abstract public method withUploadedFiles ] {

      - Parameters [1] {
        Parameter #0 [ <required> array $uploadedFiles ]
      }
    }

    Method [ <internal:psr> abstract public method getParsedBody ] {
    }

    Method [ <internal:psr> abstract public method withParsedBody ] {

      - Parameters [1] {
        Parameter #0 [ <required> $data ]
      }
    }

    Method [ <internal:psr> abstract public method getAttributes ] {
    }

    Method [ <internal:psr> abstract public method getAttribute ] {

      - Parameters [2] {
        Parameter #0 [ <required> $name ]
        Parameter #1 [ <optional> $default ]
      }
    }

    Method [ <internal:psr> abstract public method withAttribute ] {

      - Parameters [2] {
        Parameter #0 [ <required> $name ]
        Parameter #1 [ <required> $value ]
      }
    }

    Method [ <internal:psr> abstract public method withoutAttribute ] {

      - Parameters [1] {
        Parameter #0 [ <required> $name ]
      }
    }

    Method [ <internal:psr, inherits Psr\Http\Message\RequestInterface> abstract public method getRequestTarget ] {
    }

    Method [ <internal:psr, inherits Psr\Http\Message\RequestInterface> abstract public method withRequestTarget ] {

      - Parameters [1] {
        Parameter #0 [ <required> $requestTarget ]
      }
    }

    Method [ <internal:psr, inherits Psr\Http\Message\RequestInterface> abstract public method getMethod ] {
    }

    Method [ <internal:psr, inherits Psr\Http\Message\RequestInterface> abstract public method withMethod ] {

      - Parameters [1] {
        Parameter #0 [ <required> $method ]
      }
    }

    Method [ <internal:psr, inherits Psr\Http\Message\RequestInterface> abstract public method getUri ] {
    }

    Method [ <internal:psr, inherits Psr\Http\Message\RequestInterface> abstract public method withUri ] {

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
