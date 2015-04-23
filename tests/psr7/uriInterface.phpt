--TEST--
PSR-7 implementation: <https://github.com/php-fig/fig-standards/blob/master/proposed/http-message.md>
Psr\Http\Message\UriInterface
--SKIPIF--
<?php if (!extension_loaded("psr")) die("skip"); ?>
--FILE--
<?php
echo ReflectionClass::export('\Psr\Http\Message\UriInterface');
--EXPECT--
Interface [ <internal:psr> interface Psr\Http\Message\UriInterface ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [16] {
    Method [ <internal:psr> abstract public method getScheme ] {
    }

    Method [ <internal:psr> abstract public method getAuthority ] {
    }

    Method [ <internal:psr> abstract public method getUserInfo ] {
    }

    Method [ <internal:psr> abstract public method getHost ] {
    }

    Method [ <internal:psr> abstract public method getPort ] {
    }

    Method [ <internal:psr> abstract public method getPath ] {
    }

    Method [ <internal:psr> abstract public method getQuery ] {
    }

    Method [ <internal:psr> abstract public method getFragment ] {
    }

    Method [ <internal:psr> abstract public method withScheme ] {

      - Parameters [1] {
        Parameter #0 [ <required> $scheme ]
      }
    }

    Method [ <internal:psr> abstract public method withUserInfo ] {

      - Parameters [2] {
        Parameter #0 [ <required> $user ]
        Parameter #1 [ <optional> $password ]
      }
    }

    Method [ <internal:psr> abstract public method withHost ] {

      - Parameters [1] {
        Parameter #0 [ <required> $host ]
      }
    }

    Method [ <internal:psr> abstract public method withPort ] {

      - Parameters [1] {
        Parameter #0 [ <required> $port ]
      }
    }

    Method [ <internal:psr> abstract public method withPath ] {

      - Parameters [1] {
        Parameter #0 [ <required> $path ]
      }
    }

    Method [ <internal:psr> abstract public method withQuery ] {

      - Parameters [1] {
        Parameter #0 [ <required> $query ]
      }
    }

    Method [ <internal:psr> abstract public method withFragment ] {

      - Parameters [1] {
        Parameter #0 [ <required> $fragment ]
      }
    }

    Method [ <internal:psr> abstract public method __toString ] {
    }
  }
}
