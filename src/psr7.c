#ifdef HAVE_CONFIG_H
#    include "config.h"
#endif

#include "psr7.h"

/* {{{ interface Psr\Http\Message\MessageInterface */
ZEND_BEGIN_ARG_INFO(arginfo_messageInterface_withProtocolVersion, 0)
    ZEND_ARG_INFO(0, version)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_messageInterface_hasHeader, 0)
    ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_messageInterface_getHeader, 0)
    ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_messageInterface_getHeaderLine, 0)
    ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_messageInterface_withHeader, 0)
    ZEND_ARG_INFO(0, name)
    ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_messageInterface_withAddedHeader, 0)
    ZEND_ARG_INFO(0, name)
    ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_messageInterface_withoutHeader, 0)
    ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_messageInterface_withBody, 0)
    ZEND_ARG_OBJ_INFO(0, body, Psr\\Http\\Message\\StreamInterface, 0)
ZEND_END_ARG_INFO()

static zend_function_entry messageInterface_class_functions[] = {
    PHP_ABSTRACT_ME(MessageInterface, getProtocolVersion, NULL)
    PHP_ABSTRACT_ME(MessageInterface, withProtocolVersion, arginfo_messageInterface_withProtocolVersion)
    PHP_ABSTRACT_ME(MessageInterface, getHeaders, NULL)
    PHP_ABSTRACT_ME(MessageInterface, hasHeader, arginfo_messageInterface_hasHeader)
    PHP_ABSTRACT_ME(MessageInterface, getHeader, arginfo_messageInterface_getHeader)
    PHP_ABSTRACT_ME(MessageInterface, getHeaderLine, arginfo_messageInterface_getHeaderLine)
    PHP_ABSTRACT_ME(MessageInterface, withHeader, arginfo_messageInterface_withHeader)
    PHP_ABSTRACT_ME(MessageInterface, withAddedHeader, arginfo_messageInterface_withAddedHeader)
    PHP_ABSTRACT_ME(MessageInterface, withoutHeader, arginfo_messageInterface_withoutHeader)
    PHP_ABSTRACT_ME(MessageInterface, getBody, NULL)
    PHP_ABSTRACT_ME(MessageInterface, withBody, arginfo_messageInterface_withBody)
    PHP_FE_END
};
/* }}} */

/* {{{ interface Psr\Http\Message\RequestInterface */
ZEND_BEGIN_ARG_INFO(arginfo_requestInterface_withRequestTarget, 0)
    ZEND_ARG_INFO(0, requestTarget)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_requestInterface_withMethod, 0)
    ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_requestInterface_withUri, 0, ZEND_RETURN_VALUE, 1)
    ZEND_ARG_OBJ_INFO(0, uri, Psr\\Http\\Message\\UriInterface, 0)
    ZEND_ARG_INFO(0, preserveHost)
ZEND_END_ARG_INFO()

static zend_function_entry requestInterface_class_functions[] = {
    PHP_ABSTRACT_ME(MessageInterface, getRequestTarget, NULL)
    PHP_ABSTRACT_ME(MessageInterface, withRequestTarget, arginfo_requestInterface_withRequestTarget)
    PHP_ABSTRACT_ME(MessageInterface, getMethod, NULL)
    PHP_ABSTRACT_ME(MessageInterface, withMethod, arginfo_requestInterface_withMethod)
    PHP_ABSTRACT_ME(MessageInterface, getUri, NULL)
    PHP_ABSTRACT_ME(MessageInterface, withUri, arginfo_requestInterface_withUri)
    PHP_FE_END
};
/* }}} */

/* {{{ interface Psr\Http\Message\ServerRequestInterface */
ZEND_BEGIN_ARG_INFO(arginfo_serverRequestInterface_withCookieParams, 0)
    ZEND_ARG_ARRAY_INFO(0, cookies, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_serverRequestInterface_withQueryParams, 0)
    ZEND_ARG_ARRAY_INFO(0, query, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_serverRequestInterface_withUploadedFiles, 0)
    ZEND_ARG_ARRAY_INFO(0, uploadedFiles, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_serverRequestInterface_withParsedBody, 0)
    ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_serverRequestInterface_getAttribute, 0, ZEND_RETURN_VALUE, 1)
    ZEND_ARG_INFO(0, name)
    ZEND_ARG_INFO(0, default)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_serverRequestInterface_withAttribute, 0)
    ZEND_ARG_INFO(0, name)
    ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_serverRequestInterface_withoutAttribute, 0)
    ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

static zend_function_entry serverRequestInterface_class_functions[] = {
    PHP_ABSTRACT_ME(MessageInterface, getServerParams, NULL)
    PHP_ABSTRACT_ME(MessageInterface, getCookieParams, NULL)
    PHP_ABSTRACT_ME(MessageInterface, withCookieParams, arginfo_serverRequestInterface_withCookieParams)
    PHP_ABSTRACT_ME(MessageInterface, getQueryParams, NULL)
    PHP_ABSTRACT_ME(MessageInterface, withQueryParams, arginfo_serverRequestInterface_withQueryParams)
    PHP_ABSTRACT_ME(MessageInterface, getUploadedFiles, NULL)
    PHP_ABSTRACT_ME(MessageInterface, withUploadedFiles, arginfo_serverRequestInterface_withUploadedFiles)
    PHP_ABSTRACT_ME(MessageInterface, getParsedBody, NULL)
    PHP_ABSTRACT_ME(MessageInterface, withParsedBody, arginfo_serverRequestInterface_withParsedBody)
    PHP_ABSTRACT_ME(MessageInterface, getAttributes, NULL)
    PHP_ABSTRACT_ME(MessageInterface, getAttribute, arginfo_serverRequestInterface_getAttribute)
    PHP_ABSTRACT_ME(MessageInterface, withAttribute, arginfo_serverRequestInterface_withAttribute)
    PHP_ABSTRACT_ME(MessageInterface, withoutAttribute, arginfo_serverRequestInterface_withoutAttribute)
    PHP_FE_END
};
/* }}} */

/* {{{ interface Psr\Http\Message\ResponseInterface */
ZEND_BEGIN_ARG_INFO_EX(arginfo_responseInterface_withStatus, 0, ZEND_RETURN_VALUE, 1)
    ZEND_ARG_INFO(0, code)
    ZEND_ARG_INFO(0, reasonPhrase)
ZEND_END_ARG_INFO()

static zend_function_entry responseInterface_class_functions[] = {
    PHP_ABSTRACT_ME(MessageInterface, getStatusCode, NULL)
    PHP_ABSTRACT_ME(MessageInterface, withStatus, arginfo_responseInterface_withStatus)
    PHP_ABSTRACT_ME(MessageInterface, getReasonPhrase, NULL)
    PHP_FE_END
};
/* }}} */

/* {{{ interface Psr\Http\Message\StreamInterface */
ZEND_BEGIN_ARG_INFO_EX(arginfo_streamInterface_seek, 0, ZEND_RETURN_VALUE, 1)
    ZEND_ARG_INFO(0, offset)
    ZEND_ARG_INFO(0, whence)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_streamInterface_write, 0)
    ZEND_ARG_INFO(0, string)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_streamInterface_read, 0)
    ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

static zend_function_entry streamInterface_class_functions[] = {
    PHP_ABSTRACT_ME(MessageInterface, __toString, NULL)
    PHP_ABSTRACT_ME(MessageInterface, close, NULL)
    PHP_ABSTRACT_ME(MessageInterface, detach, NULL)
    PHP_ABSTRACT_ME(MessageInterface, getSize, NULL)
    PHP_ABSTRACT_ME(MessageInterface, tell, NULL)
    PHP_ABSTRACT_ME(MessageInterface, eof, NULL)
    PHP_ABSTRACT_ME(MessageInterface, isSeekable, NULL)
    PHP_ABSTRACT_ME(MessageInterface, seek, arginfo_streamInterface_seek)
    PHP_ABSTRACT_ME(MessageInterface, rewind, NULL)
    PHP_ABSTRACT_ME(MessageInterface, isWritable, NULL)
    PHP_ABSTRACT_ME(MessageInterface, write, arginfo_streamInterface_write)
    PHP_ABSTRACT_ME(MessageInterface, isReadable, NULL)
    PHP_ABSTRACT_ME(MessageInterface, read, arginfo_streamInterface_read)
    PHP_ABSTRACT_ME(MessageInterface, getContents, NULL)
    PHP_FE_END
};
/* }}} */

/* {{{ interface Psr\Http\Message\UriInterface */
ZEND_BEGIN_ARG_INFO(arginfo_uriInterface_withScheme, 0)
    ZEND_ARG_INFO(0, scheme)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_uriInterface_withUserInfo, 0, ZEND_RETURN_VALUE, 1)
    ZEND_ARG_INFO(0, user)
    ZEND_ARG_INFO(0, password)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_uriInterface_withHost, 0)
    ZEND_ARG_INFO(0, host)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_uriInterface_withPort, 0)
    ZEND_ARG_INFO(0, port)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_uriInterface_withPath, 0)
    ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_uriInterface_withQuery, 0)
    ZEND_ARG_INFO(0, query)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_uriInterface_withFragment, 0)
    ZEND_ARG_INFO(0, fragment)
ZEND_END_ARG_INFO()

static zend_function_entry uriInterface_class_functions[] = {
    PHP_ABSTRACT_ME(MessageInterface, getScheme, NULL)
    PHP_ABSTRACT_ME(MessageInterface, getAuthority, NULL)
    PHP_ABSTRACT_ME(MessageInterface, getUserInfo, NULL)
    PHP_ABSTRACT_ME(MessageInterface, getHost, NULL)
    PHP_ABSTRACT_ME(MessageInterface, getPort, NULL)
    PHP_ABSTRACT_ME(MessageInterface, getPath, NULL)
    PHP_ABSTRACT_ME(MessageInterface, getQuery, NULL)
    PHP_ABSTRACT_ME(MessageInterface, getFragment, NULL)
    PHP_ABSTRACT_ME(MessageInterface, withScheme, arginfo_uriInterface_withScheme)
    PHP_ABSTRACT_ME(MessageInterface, withUserInfo, arginfo_uriInterface_withUserInfo)
    PHP_ABSTRACT_ME(MessageInterface, withHost, arginfo_uriInterface_withHost)
    PHP_ABSTRACT_ME(MessageInterface, withPort, arginfo_uriInterface_withPort)
    PHP_ABSTRACT_ME(MessageInterface, withPath, arginfo_uriInterface_withPath)
    PHP_ABSTRACT_ME(MessageInterface, withQuery, arginfo_uriInterface_withQuery)
    PHP_ABSTRACT_ME(MessageInterface, withFragment, arginfo_uriInterface_withFragment)
    PHP_ABSTRACT_ME(MessageInterface, __toString, NULL)
    PHP_FE_END
};
/* }}} */

/* {{{ interface Psr\Http\Message\UploadedFileInterface */
ZEND_BEGIN_ARG_INFO(arginfo_uploadedFileInterface_move, 0)
    ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

static zend_function_entry uploadedFileInterface_class_functions[] = {
    PHP_ABSTRACT_ME(MessageInterface, getStream, NULL)
    PHP_ABSTRACT_ME(MessageInterface, move, arginfo_uploadedFileInterface_move)
    PHP_ABSTRACT_ME(MessageInterface, getSize, NULL)
    PHP_ABSTRACT_ME(MessageInterface, getError, NULL)
    PHP_ABSTRACT_ME(MessageInterface, getClientFilename, NULL)
    PHP_ABSTRACT_ME(MessageInterface, getClientMediaType, NULL)
    PHP_FE_END
};
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(psr7)
{
    zend_class_entry ce;

    zend_class_entry* ce_psr_http_message_messageInterface;
    zend_class_entry* ce_psr_http_message_requestInterface;
    zend_class_entry* ce_psr_http_message_serverRequestInterface;
    zend_class_entry* ce_psr_http_message_responseInterface;


    INIT_NS_CLASS_ENTRY(ce, "Psr\\Http\\Message", "MessageInterface", messageInterface_class_functions);
    ce_psr_http_message_messageInterface = zend_register_internal_interface(&ce);

    INIT_NS_CLASS_ENTRY(ce, "Psr\\Http\\Message", "RequestInterface", requestInterface_class_functions);
    ce_psr_http_message_requestInterface = zend_register_internal_interface(&ce);
    zend_class_implements(ce_psr_http_message_requestInterface, 1, ce_psr_http_message_messageInterface);

    INIT_NS_CLASS_ENTRY(ce, "Psr\\Http\\Message", "ServerRequestInterface", serverRequestInterface_class_functions);
    ce_psr_http_message_serverRequestInterface = zend_register_internal_interface(&ce);
    zend_class_implements(ce_psr_http_message_serverRequestInterface, 1, ce_psr_http_message_requestInterface);

    INIT_NS_CLASS_ENTRY(ce, "Psr\\Http\\Message", "ResponseInterface", responseInterface_class_functions);
    ce_psr_http_message_responseInterface = zend_register_internal_interface(&ce);
    zend_class_implements(ce_psr_http_message_responseInterface, 1, ce_psr_http_message_messageInterface);

    INIT_NS_CLASS_ENTRY(ce, "Psr\\Http\\Message", "StreamInterface", streamInterface_class_functions);
    zend_register_internal_interface(&ce);

    INIT_NS_CLASS_ENTRY(ce, "Psr\\Http\\Message", "UriInterface", uriInterface_class_functions);
    zend_register_internal_interface(&ce);

    INIT_NS_CLASS_ENTRY(ce, "Psr\\Http\\Message", "UploadedFileInterface", uploadedFileInterface_class_functions);
    zend_register_internal_interface(&ce);

    return SUCCESS;
}
/* }}} */
