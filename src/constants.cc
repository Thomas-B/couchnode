#include "couchbase_impl.h"
namespace Couchnode {

/**
 * Because some of these values are macros themselves, just use a function
 * and stringify in place
 */
static void define_constant(Handle<Object> target, const char *k, int n)
{
    Nan::ForceSet(target,
                Nan::New<String>(k).ToLocalChecked(),
                Nan::New<Number>(n),
                static_cast<v8::PropertyAttribute>(v8::ReadOnly|v8::DontDelete));
}

Handle<Object> CouchbaseImpl::createConstants()
{
    Handle<Object> o = Nan::New<Object>();

#define X(n) define_constant(o, #n, LCB_##n);
    X(CNTL_SET) \
    X(CNTL_GET) \
    X(CNTL_OP_TIMEOUT) \
    X(CNTL_DURABILITY_INTERVAL) \
    X(CNTL_DURABILITY_TIMEOUT) \
    X(CNTL_HTTP_TIMEOUT) \
    X(CNTL_N1QL_TIMEOUT) \
    X(CNTL_VIEW_TIMEOUT) \
    X(CNTL_CONFIGURATION_TIMEOUT) \
    X(CNTL_VBMAP) \
    X(CNTL_CHANGESET) \
    X(CNTL_CONFIGCACHE) \
    X(CNTL_SSL_MODE) \
    X(CNTL_SSL_CACERT) \
    X(CNTL_RETRYMODE) \
    X(CNTL_HTCONFIG_URLTYPE) \
    X(CNTL_COMPRESSION_OPTS) \
    X(CNTL_RDBALLOCFACTORY) \
    X(CNTL_SYNCDESTROY) \
    X(CNTL_CONLOGGER_LEVEL) \
    X(CNTL_DETAILED_ERRCODES) \
    X(CNTL_REINIT_CONNSTR) \
    X(CNTL_CONFDELAY_THRESH) \
    \
    X(ADD) \
    X(REPLACE) \
    X(SET) \
    X(APPEND) \
    X(PREPEND) \
    \
    X(SUCCESS) \
    X(AUTH_CONTINUE) \
    X(AUTH_ERROR) \
    X(DELTA_BADVAL) \
    X(E2BIG) \
    X(EBUSY) \
    X(ENOMEM) \
    X(ERANGE) \
    X(ERROR) \
    X(ETMPFAIL) \
    X(EINVAL) \
    X(CLIENT_ETMPFAIL) \
    X(KEY_EEXISTS) \
    X(KEY_ENOENT) \
    X(DLOPEN_FAILED) \
    X(DLSYM_FAILED) \
    X(NETWORK_ERROR) \
    X(NOT_MY_VBUCKET) \
    X(NOT_STORED) \
    X(NOT_SUPPORTED) \
    X(UNKNOWN_COMMAND) \
    X(UNKNOWN_HOST) \
    X(PROTOCOL_ERROR) \
    X(ETIMEDOUT) \
    X(BUCKET_ENOENT) \
    X(CLIENT_ENOMEM) \
    X(CONNECT_ERROR) \
    X(EBADHANDLE) \
    X(SERVER_BUG) \
    X(PLUGIN_VERSION_MISMATCH) \
    X(INVALID_HOST_FORMAT) \
    X(INVALID_CHAR) \
    X(DURABILITY_ETOOMANY) \
    X(DUPLICATE_COMMANDS) \
    X(EINTERNAL) \
    X(NO_MATCHING_SERVER) \
    X(BAD_ENVIRONMENT) \
    X(BUSY) \
    X(INVALID_USERNAME) \
    X(CONFIG_CACHE_INVALID) \
    X(SASLMECH_UNAVAILABLE) \
    X(TOO_MANY_REDIRECTS) \
    X(MAP_CHANGED) \
    X(INCOMPLETE_PACKET) \
    X(ECONNREFUSED) \
    X(ESOCKSHUTDOWN) \
    X(ECONNRESET) \
    X(ECANTGETPORT) \
    X(EFDLIMITREACHED) \
    X(ENETUNREACH) \
    X(ECTL_UNKNOWN) \
    X(ECTL_UNSUPPMODE) \
    X(ECTL_BADARG) \
    X(EMPTY_KEY) \
    X(SSL_ERROR) \
    X(SSL_CANTVERIFY) \
    X(SCHEDFAIL_INTERNAL) \
    X(CLIENT_FEATURE_UNAVAILABLE) \
    X(OPTIONS_CONFLICT) \
    X(HTTP_ERROR) \
    X(DURABILITY_NO_MUTATION_TOKENS) \
    X(UNKNOWN_MEMCACHED_ERROR) \
    X(MUTATION_LOST) \
    X(SUBDOC_PATH_ENOENT) \
    X(SUBDOC_PATH_MISMATCH) \
    X(SUBDOC_PATH_EINVAL) \
    X(SUBDOC_PATH_E2BIG) \
    X(SUBDOC_DOC_E2DEEP) \
    X(SUBDOC_VALUE_CANTINSERT) \
    X(SUBDOC_DOC_NOTJSON) \
    X(SUBDOC_NUM_ERANGE) \
    X(SUBDOC_BAD_DELTA) \
    X(SUBDOC_PATH_EEXISTS) \
    X(SUBDOC_MULTI_FAILURE) \
    X(SUBDOC_VALUE_E2DEEP) \
    X(EINVAL_MCD) \
    X(EMPTY_PATH) \
    X(UNKNOWN_SDCMD) \
    X(ENO_COMMANDS) \
    X(QUERY_ERROR) \
    X(GENERIC_TMPERR) \
    X(GENERIC_SUBDOCERR) \
    X(GENERIC_CONSTRAINT_ERR) \
    \
    X(HTTP_TYPE_VIEW) \
    X(HTTP_TYPE_MANAGEMENT) \
    X(HTTP_METHOD_GET) \
    X(HTTP_METHOD_POST) \
    X(HTTP_METHOD_PUT) \
    X(HTTP_METHOD_DELETE) \
    \
    X(SDCMD_GET) \
    X(SDCMD_EXISTS) \
    X(SDCMD_REPLACE) \
    X(SDCMD_DICT_ADD) \
    X(SDCMD_DICT_UPSERT) \
    X(SDCMD_ARRAY_ADD_FIRST) \
    X(SDCMD_ARRAY_ADD_LAST) \
    X(SDCMD_ARRAY_ADD_UNIQUE) \
    X(SDCMD_ARRAY_INSERT) \
    X(SDCMD_REMOVE) \
    X(SDCMD_COUNTER)
#undef X

    return o;
}



};
