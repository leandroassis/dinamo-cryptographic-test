/* Dinamo Networks. */
/* Date: 20210331(AAAAMMDD)   */



#ifndef NETDFENCE_H_INCLUDED
#define NETDFENCE_H_INCLUDED

/**
 \file
 \brief Application Programming Interface (API) do HSM Dinamo.
 */


#ifdef _WIN32
    #include <windows.h>
#endif

#include <time.h>

/**
 \def AAP_API
  Ambiente | Definição
  :--------|:--------
  Windows | __stdcall
  Linux | |
  INTEL_GCC | __attribute__((stdcall))
 */

#ifdef _WIN32
    typedef unsigned __int64 ND_uint64_t;
    typedef unsigned __int64 ND_OATH_uint64_t;
    #define AAP_API __stdcall

	typedef unsigned long long int	QWORD;
    #define DWORD_PRINT_TYPE "lu"
    #define DWORD_PRINT "%" DWORD_PRINT_TYPE
#else
    typedef unsigned long long ND_uint64_t;
    typedef unsigned long long ND_OATH_uint64_t;
    #ifdef INTEL_GCC
        #define AAP_API __attribute__((stdcall))
    #else
        #define AAP_API
    #endif /* INTEL_GCC */

	typedef unsigned char            BYTE;
	typedef unsigned int             DWORD;
	typedef unsigned long long int  QWORD;
	typedef unsigned short           WORD;
	typedef int                       BOOL;
	typedef unsigned int             UINT;
	typedef signed int               INT;
	typedef signed char              CHAR;

    #define DWORD_PRINT_TYPE "u"
    #define DWORD_PRINT "%" DWORD_PRINT_TYPE

	#ifndef FALSE
	#define FALSE   (0)
	#endif
	#ifndef TRUE
	#define TRUE    (1)
	#endif

#endif

typedef unsigned long			DN_ULONG;

typedef void *HSESSIONCTX;
typedef void *HHASHCTX;
typedef void *HKEYCTX;
typedef void *HCERTCTX;
typedef void *HSPBCTX;
typedef void *HCHAPCTX;
typedef void *HLOGCTX;
typedef void *HOBJMETACTX;
typedef void *HP11ATTRCTX;
typedef void *HOBJMETASEARCHCTX;


/* Client network errors. Negative errors. */

#define D_SOCKET_FAILED                       (-10)
#define D_GETHOSTNAME_FAILED                  (-11)
#define D_CONNECT_FAILED                      (-12)
#define D_SEND_FAILED                         (-13)
#define D_RECV_FAILED                         (-14)
#define D_INVALID_PACKAGE_SIZE                (-15)
#define D_SETSOCKOPT_FAILED                   (-16)
#define D_GETSOCKOPT_FAILED                   (-17)
#define D_ALL_LOAD_BALANCE_HSM_FAILED         (-18)

/* OpenSSL generated errors 1 to 100 */

#define D_SSL_CTX_NEW_FAILED        (1)
#define D_SSL_NEW_FAILED            (2)
#define D_SSL_CONNECT_FAILED        (3)
#define D_SSL_GENERAL_ERROR         (4)

/* External communication generated errors 101 to 200 */

#define D_CRL_GENERAL_ERROR					(101)
#define D_CRL_SSL_CACERT_BADFILE			(102)
#define D_CRL_COULDNT_RESOLVE_HOST			(103)
#define D_CRL_COULDNT_CONNECT				(104)
#define D_CRL_OPERATION_TIMEDOUT			(105)
#define D_CRL_PEER_FAILED_VERIFICATION		(106)
#define D_CRL_SSL_CONNECT_ERROR				(107)
#define D_CRL_SEND_ERROR					(108)
#define D_CRL_RECV_ERROR					(109)
#define D_CRL_SSL_CERTPROBLEM				(110)
#define D_CRL_SSL_ISSUER_ERROR				(111)
#define D_CRL_AUTH_ERROR					(112)
#define D_CRL_GOT_NOTHING					(113)
#define D_CRL_UNSUPPORTED_PROTOCOL			(114)
#define D_CRL_URL_MALFORMAT					(115)
#define D_CRL_WEIRD_SERVER_REPLY			(116)
#define D_CRL_REMOTE_ACCESS_DENIED			(117)
#define D_CRL_HTTP2							(118)
#define D_CRL_WRITE_ERROR					(119)
#define D_CRL_READ_ERROR					(120)
#define D_CRL_HTTP_POST_ERROR				(121)
#define D_CRL_ABORTED_BY_CALLBACK			(122)
#define D_CRL_TOO_MANY_REDIRECTS			(123)
#define D_CRL_SSL_CIPHER					(124)
#define D_CRL_BAD_CONTENT_ENCODING			(125)
#define D_CRL_LOGIN_DENIED					(126)
#define D_CRL_INSTALL_SIGN_CALL_FAILED      (127)
#define D_CRL_CERT_LOAD_FAILED              (128)
#define D_CRL_CHAIN_LOAD_FAILED             (129)
#define D_CRL_PRIVATE_KEY_LOAD_FAILED       (130)

/* System errors */

#define D_WSASTARTUP           (2001)
#define D_MEMORY_ALLOC         (2002)


/* Client errors */

#define D_INVALID_PARAM                (1001)
#define D_INVALID_TYPE                 (1002)
#define D_INVALID_STATE                (1003)
#define D_LOGGING_NOT_STARTED          (1004)
#define D_MORE_DATA                    (1005)
#define D_INVALID_RESPONSE             (1006)
#define D_INVALID_CONTEXT              (1007)
#define D_KEY_GEN_ERROR                (1008)
#define D_KEY_DEL_ERROR                (1009)
#define D_KEY_NOT_EXISTS               (1010)
#define D_INVALID_DATA_LENGTH          (1011)
#define D_INVALID_KEY_ALG              (1012)
#define D_INVALID_PADDING              (1013)
#define D_INVALID_KEY                  (1014)
#define D_BAD_DATA                     (1015)
#define D_INVALID_PUBKEY               (1016)
#define D_INVALID_ALG_ID               (1017)
#define D_INVALID_HASH                 (1018)
#define D_INIT_HASH_FAILED             (1019)
#define D_INVALID_HASH_STATE           (1020)
#define D_END_HASH_FAILED              (1021)
#define D_GET_INFO_ERROR               (1022)
#define D_INVALID_PIN_LEN              (1023)
#define D_OPEN_FILE_FAILED             (1025)
#define D_BACKUP_FAILED                (1026)
#define D_RESTORE_FAILED               (1027)
#define D_INVALID_CALLBACK             (1028)
#define D_NOT_IMPLEMENTED              (1029)
#define D_AUTH_FAILED                  (1030)
#define D_INVALID_CLEAR_OP             (1031)
#define D_CHANGE_PWD_ERROR             (1032)
#define D_PWD_SIZE_ERROR               (1033)
#define D_IMPORT_KEY_ERROR             (1034)
#define D_INVALID_KEY_ID               (1035)
#define D_INVALID_FLAG                 (1036)
#define D_INVALID_SIGNATURE            (1037)
#define D_INVALID_PUB_KEY              (1038)
#define D_INVALID_KEY_STATE            (1039)
#define D_CREATE_USER_ERROR            (1040)
#define D_NO_MORE_OBJECT               (1041)
#define D_PUT_ENV_VAR_FAILED           (1042)
#define D_INVALID_FILE_SIZE            (1043)
#define D_INVALID_TEXT_SIZE            (1044)
#define D_FILE_ACCESS_ERROR            (1045)
#define D_INVALID_COUNTER              (1046)
#define D_INVALID_MODE                 (1047)
#define D_INVALID_STRUCT_ID            (1048)
#define D_INVALID_IP_ADDRESS           (1049)
#define D_GET_PEER_IP_ERROR            (1050)
#define D_CERTIFICATE_PARSE_FAILED     (1051)
#define D_INVALID_KEY_PART_1           (1052)
#define D_INVALID_KEY_PART_2           (1053)
#define D_INVALID_KEY_PART_3           (1054)
#define D_VERIFY_DAC_FAILED            (1055)
#define D_DEPRECATED                   (1056)
#define D_NO_MATCHING_KEY_FOUND        (1057)
#define D_CALLBACK_ERROR               (1058)
#define D_INTERNAL_ERROR               (1059)
#define D_KEY_NOT_EXPORTABLE_ERROR     (1060)

#define D_INVALID_SPB_ID               (1062)
#define D_JSON_PARSE_ERROR			   (1063)
#define D_JSON_PARSE_WRONG_TYPE_ERROR  (1064)
#define D_JSON_SET_VALUE_ERROR         (1065)
#define D_JSON_UNSET_VALUE_ERROR       (1066)
#define D_JSON_VALUE_NOT_FOUND         (1067)
#define D_JSON_OBJ_CREATE_ERROR        (1068)

#define D_SLP_PARSE_ERROR				(1069)
#define D_SLP_INTERNAL_ERROR			(1070)
#define D_SLP_TOO_MANY_SERVERS_ERROR    (1071)

#define D_INVALID_SERVER_VERSION    (1072)

#define D_GENERATE_PKCS12_ERROR				(1073)
#define D_SET_LOAD_BALANCE_LIST_ERROR		(1074)

#define D_OATH_BLOB_UPDATE				(1075)
#define D_GZIP_DEFLATE_ERROR			(1076)
#define D_HTTP_UNEXPECTED_STATUS_CODE   (1077)
#define D_BASE64_ERROR                  (1078)

/* Server errors */

#define D_KEEP_ALIVE_ERROR     (3001)
#define D_RECEIVE_LOG_ERROR    (3002)
#define D_ERROR_NOTIFY         (3003)


/* Server returned errors */

#define D_SUCCESS                                           (0)
#define D_ERR_UNKNOWN                                       (5000)
#define D_ERR_NET_FAIL                                      (5001)
#define D_ERR_ACCESS_DENIED                                 (5002)
#define D_ERR_CANNOT_CREATE_OBJ                             (5003)
#define D_ERR_CANNOT_OPEN_OBJ                               (5004)
#define D_ERR_CANNOT_DEL_OBJ                                (5005)
#define D_ERR_CANNOT_ALLOC_RES                              (5006)
#define D_ERR_INVALID_CTX                                   (5007)
#define D_ERR_INVALID_OPERATION                             (5008)
#define D_ERR_INVALID_KEY                                   (5009)
#define D_ERR_NO_TLS_USED                                   (5010)
#define D_ERR_CANNOT_CHANGE_PWD                             (5011)
#define D_ERR_OBJ_NOT_EXPORTABLE                            (5012)
#define D_ERR_USR_ALREADY_EXISTS                            (5013)
#define D_ERR_INVALID_USR_NAME                              (5014)
#define D_ERR_CANNOT_CREATE_USR                             (5015)
#define D_ERR_NO_MORE_LOG_SLOTS                             (5016)
#define D_ERR_CANNOT_DELETE_USR                             (5017)
#define D_ERR_CANNOT_DELETE_MASTER                          (5018)
#define D_ERR_NOT_IMPLEMENTED                               (5019)
#define D_ERR_USR_NOT_FOUND                                 (5020)
#define D_ERR_INVALID_PAYLOAD                               (5021)
#define D_ERR_OBJ_ALREADY_EXISTS                            (5022)
#define D_ERR_INVALID_OBJ_NAME                              (5023)
#define D_ERR_OBJ_IN_USE                                    (5024)
#define D_ERR_CANNOT_WRITE_BACKUP_BLOB                      (5025)
#define D_ERR_CANNOT_OPEN_BACKUP_BLOB                       (5026)
#define D_ERR_CANNOT_RESTORE_BACKUP_BLOB                    (5027)
#define D_ERR_INVALID_BACKUP_PIN_OR_LEN                     (5028)
#define D_ERR_INVALID_XML_SIGNATURE                         (5029)
#define D_ERR_INVALID_CERTIFICATE                           (5030)
#define D_ERR_VERIFY_XML_FAILED                             (5031)
#define D_ERR_INVALID_XML                                   (5032)
#define D_ERR_SIGN_XML_FAILED                               (5033)
#define D_ERR_UPACK_VERIFY_FAILED                           (5034)
#define D_ERR_CANNOT_TRUNCATE_LOG                           (5035)
#define D_ERR_CANNOT_BACKUP_OLD_LOG                         (5036)
#define D_ERR_CERTIFICATE_EXPIRED                           (5037)
#define D_ERR_CERTIFICATE_FAILED                            (5038)
#define D_ERR_CERTIFICATE_NOT_FOUND                         (5039)
#define D_ERR_CERTIFICATE_REVOKED                           (5040)
#define D_ERR_CERTIFICATE_ISSUER_FAILED                     (5041)
#define D_ERR_CERTIFICATE_NOT_YET_VALID                     (5042)
#define D_ERR_CERT_EXPIRED_SIGN_VALID                       (5043)
#define D_ERR_CRL_EXPIRED                                   (5044)
#define D_ERR_INVALID_CRL_SIGN                              (5045)
#define D_ERR_CRL_CERT_MISMATCH                             (5046)
#define D_ERR_CERT_REVOKED                                  (D_ERR_CERTIFICATE_REVOKED)
#define D_ERR_CERT_REVOKED_LIBCLIENT_FIX1                   (5047)
#define D_ERR_ACCESS_DENIED_TOKEN_NOT_NEEDED                (5048)
#define D_ERR_ACCESS_DENIED_TOKEN_NEEDED                    (5049)
#define D_ERR_CERT_REVOKED_CRL_VAL_UNUSED                   (5050)
#define D_ERR_CERT_VALID_CRL_VAL_UNUSED                     (5051)
#define D_ERR_CANNOT_PARSE_XML                              (5052)
#define D_ERR_CANNOT_CREATE_XML_SIG_TEMPL                   (5053)
#define D_ERR_CANNOT_ADD_XML_SIG_TEMPL_REF                  (5054)
#define D_ERR_CANNOT_ADD_XML_SIG_TEMPL_TRANS                (5055)
#define D_ERR_CANNOT_ADD_XML_SIG_KEY_INFO                   (5056)
#define D_ERR_CANNOT_ADD_XML_SIG_KEY_CERT                   (5057)
#define D_ERR_CANNOT_ALLOC_XML_SIG_CTX                      (5058)
#define D_ERR_CANNOT_PARSE_DER_PRIV_KEY                     (5059)
#define D_ERR_XML_CANNOT_LOAD_PRIV_KEY                      (5060)
#define D_ERR_XML_CANNOT_LOAD_CERT                          (5061)
#define D_ERR_XML_CANNOT_CREATE_KEY_MNG                     (5062)
#define D_ERR_XML_CANNOT_INIT_KEY_MNG                       (5063)
#define D_ERR_XML_CANNOT_LOAD_TRUSTED_CERTS                 (5064)
#define D_ERR_XML_SIG_NODE_NOT_FOUND                        (5065)
#define D_ERR_XML_CERT_NODE_NOT_FOUND                       (5066)
#define D_ERR_XML_CANNOT_DECODE_CERT_NODE                   (5067)
#define D_ERR_CANNOT_PARSE_DER_CERT                         (5068)
#define D_ERR_DEPRECATED_XML_COMPRESS                       (5069)
#define D_ERR_INVALID_CERTIFICATE_NULL_RES                  (5070)
#define D_ERR_CANNOT_RECREATE_MASTER                        (5071)
#define D_ERR_CANNOT_CREATE_USR_STORAGE1                    (5072)
#define D_ERR_CANNOT_CREATE_USR_STORAGE2                    (5073)
#define D_ERR_CANNOT_CREATE_USR_DEFAULT_ACL                 (5074)
#define D_ERR_CANNOT_ALLOC_CTX                              (5075)
#define D_ERR_CANNOT_LOAD_PRIV_KEY                          (5076)
#define D_ERR_CANNOT_DECODE_PUB_KEY                         (5077)
#define D_ERR_CANNOT_GENERATE_RND_DATA                      (5078)
#define D_ERR_CACHE_LAYER_EXHAUSTED                         (5079)
#define D_ERR_RSA_POWER_SIGN_FAILED                         (5080)
#define D_ERR_CANNOT_GET_SYS_INFO                           (5100)
#define D_ERR_CANNOT_ALLOC_UPACK_ID                         (5101)
#define D_ERR_CANNOT_ALLOC_UPACK_PATH                       (5102)
#define D_ERR_CANNOT_WRITE_UPACK_OBJ                        (5103)
#define D_ERR_INVALID_CRL                                   (5104)
#define D_ERR_OPERATION_FAILED                              (5105)
#define D_ERR_GET_USR_ACL_FAILED                            (5106)
#define D_ERR_INVALID_SIGNATURE                             (5107)
#define D_ERR_CANNOT_GENERATE_SOFT_TOKEN                    (5108)
#define D_ERR_INVALID_SECRET                                (5109)
#define D_ERR_ACCESS_DENIED_USR_BLOCKED                     (5120)
#define D_ERR_INVALID_IMEI                                  (5121)
#define D_ERR_REPLAY_DETECTED                               (5122)
#define D_ERR_NON_APPROVED_OPERATION                        (5123)
#define D_ERR_ACCESS_DENIED_OBJ_BLOCKED                     (5124)
#define D_ERR_DRBG_CONTINUOUS_TEST                          (5125)
#define D_ERR_RSA_CONTINUOUS_TEST                           (5126)
#define D_ERR_ECC_CONTINUOUS_TEST                           (5127)
#define D_ERR_DES_CONTINUOUS_TEST                           (5128)
#define D_ERR_AES_CONTINUOUS_TEST                           (5129)
#define D_ERR_CANNOT_UPDATE_OBJ                             (5175)
#define D_ERR_CANNOT_GET_PWD_POLICY                         (5176)
#define D_ERR_PWD_BLOCKED_BY_POLICY                         (5177)
#define D_ERR_PWD_EXPIRED                                   (5178)
#define D_ERR_CERT_VALID_CRL_VAL_UNUSED_CRL_EXPIRED         (5179)
#define D_ERR_CERT_VALID_CRL_EXPIRED                        (5180)
#define D_ERR_INVALID_CERT_SIGN                             (5181)
#define D_ERR_CANNOT_LOAD_CORRUPTED_OBJ                     (5200)
#define D_ERR_INVALID_CERT_ISPB_MISMATCH                    (5230)
#define D_ERR_INVALID_CA                                    (5231)
#define D_ERR_DEPRECATED_FUNCTION                           (5303)
#define D_ERR_SERVER_BUSY                                   (5304)
#define D_ERR_SL_BE_BUSY                                    (5305)
#define D_ERR_SVMK_MISMATCH                                 (5306)
#define D_ERR_INVALID_CERT_SN_MISMATCH                      (5307)
#define D_ERR_CANNOT_DEC_SYM_KEY                            (5308)
#define D_ERR_CANNOT_REC_SYM_KEY                            (5309)
#define D_SUCCESS_CANNOT_OPEN_OBJ_AT_REPL                   (5401)
#define D_ERR_CANNOT_OPEN_INVALID_OBJ_AT_REPL               (5402)
#define D_ERR_CANNOT_SL_BE_CHECK_OBJ                        (5500)
#define D_ERR_CANNOT_WRITE_AUTH_INFO_OBJ                    (5501)
#define D_ERR_CANNOT_GEN_RSA_KEY                            (5502)
#define D_ERR_CANNOT_GEN_ECC_CURVE                          (5503)
#define D_ERR_CANNOT_GEN_ECC_KEY                            (5504)
#define D_ERR_CANNOT_GEN_ECC_DER                            (5505)
#define D_ERR_CANNOT_GEN_ECC_DER_KEY                        (5506)
#define D_ERR_CANNOT_CREATE_UNKNOWN_OBJ                     (5507)
#define D_ERR_CANNOT_WRITE_HSM_MODE                         (5508)
#define D_ERR_CANNOT_WRITE_LOGIN_BLOCK_INFO                 (5509)
#define D_ERR_CANNOT_SETUP_LIVE_SYNC_OBJ                    (5510)
#define D_ERR_CANNOT_CREATE_LIVE_SYNC_OBJ                   (5511)
#define D_ERR_CANNOT_OPEN_LOG                               (5512)
#define D_ERR_COULD_NOT_OPEN_OBJ                            (5513)
#define D_ERR_CANNOT_EXPORT_RAW_OBJ                         (5514)
#define D_ERR_CANNOT_RENAME_OBJ                             (5515)
#define D_ERR_REPLICATION_CANNOT_OPEN_OBJ                   (5516)
#define D_ERR_CANNOT_SETUP_LIVE_SYNC_IMG                    (5517)
#define D_ERR_CANNOT_LOAD_LIVE_SYNC_IMG                     (5518)
#define D_ERR_CANNOT_SETUP_LIVE_SYNC_DEL_USR                (5519)
#define D_ERR_CANNOT_DEL_LIVE_SYNC_USR                      (5520)
#define D_ERR_CANNOT_SETUP_LIVE_SYNC_DEL_CONFIG             (5521)
#define D_ERR_CANNOT_DEL_LIVE_SYNC_CONFIG                   (5522)
#define D_ERR_CANNOT_SETUP_LIVE_SYNC_CONFIG                 (5523)
#define D_ERR_CANNOT_CREATE_LIVE_SYNC_CONFIG                (5524)
#define D_ERR_CANNOT_SETUP_LIVE_SYNC_USER                   (5525)
#define D_ERR_CANNOT_CREATE_LIVE_SYNC_USER                  (5526)
#define D_ERR_CANNOT_SETUP_LIVE_SYNC_ACL                    (5527)
#define D_ERR_CANNOT_CREATE_LIVE_SYNC_ACL                   (5528)
#define D_ERR_CANNOT_DEL_AUTH_INFO_OBJ                      (5529)
#define D_ERR_INVALID_KEY_NULL_RES                          (5530)
#define D_ERR_INVALID_MSG_NULL_RES                          (5531)
#define D_ERR_CANNOT_GEN_SYM_KEY                            (5532)
#define D_ERR_CANNOT_SETUP_USR_AUTH_INFO                    (5533)
#define D_ERR_CANNOT_BIND_USR_AUTH_INFO                     (5534)
#define D_ERR_CANNOT_GET_CERT_SN                            (5535)
#define D_ERR_CANNOT_GET_CERT_ISPB                          (5536)
#define D_ERR_INVALID_HASH                                  (5537)
#define D_ERR_INVALID_SIG_LEN                               (5538)
#define D_ERR_INVALID_PUBKEY_LEN                            (5539)
#define D_ERR_INVALID_PSKC_XML                              (5540)
#define D_ERR_CANNOT_FIND_PSKC_XML_NODE                     (5541)
#define D_ERR_CANNOT_FIND_PSKC_XML_ATTR                     (5542)
#define D_ERR_INVALID_PSKC_KEY_DERIVATION                   (5543)
#define D_ERR_INVALID_PSKC_KEY_DERIVATION_IT                (5544)
#define D_ERR_INVALID_PSKC_KEY_DERIVATION_LEN               (5545)
#define D_ERR_INVALID_PSKC_KEY_DERIVATION_SALT_LEN          (5546)
#define D_ERR_PSKC_KEY_DERIVATION_FAILED                    (5547)
#define D_ERR_INVALID_PSKC_KEY_ALG                          (5548)
#define D_ERR_INVALID_PSKC_KEY_METHOD                       (5549)
#define D_ERR_INVALID_OATH_EPOCH                            (5550)
#define D_ERR_INVALID_OATH_TIMESTEP                         (5551)
#define D_ERR_INVALID_OATH_DRIFT                            (5552)
#define D_ERR_INVALID_PSKC_SECRET_LEN                       (5553)
#define D_ERR_UNKNOWN_PADDING_TYPE                          (5554)
#define D_ERR_DATA_TOO_LARGE_FOR_MODULUS                    (5555)
#define D_ERR_DATA_GREATER_THAN_MODULUS_LEN                 (5556)
#define D_ERR_PADDING_CHECK_FAILED                          (5557)
#define D_ERR_DATA_TOO_LARGE_FOR_KEY_SIZE                   (5558)
#define D_ERR_DATA_TOO_SMALL_FOR_KEY_SIZE                   (5559)
#define D_ERR_INVALID_TYPE1_PADDING                         (5560)
#define D_ERR_INVALID_TYPE2_PADDING                         (5561)
#define D_ERR_BAD_FIXED_HDR_PADDING                         (5562)
#define D_ERR_MISSING_NULL_PADDING                          (5563)
#define D_ERR_BAD_PAD_BYTE_COUNT                            (5564)
#define D_ERR_DATA_TOO_LARGE_FOR_PADDING                    (5565)
#define D_ERR_BN_NO_INVERSE                                 (5566)
#define D_ERR_STATIC_BN_CANNOT_EXPAND                       (5567)
#define D_ERR_BN_IS_NOT_PRIME                               (5568)
#define D_ERR_TOO_MANY_BN_ITERATIONS                        (5569)
#define D_ERR_BN_IS_NOT_A_SQUARE                            (5570)
#define D_ERR_BN_DIV_BY_ZERO                                (5571)
#define D_ERR_BN_NOT_INITIALIZED                            (5572)
#define D_ERR_BN_INVALID_RANGE                              (5573)
#define D_ERR_BN_BAD_RECIPROCAL                             (5574)
#define D_ERR_BN_CALLED_WITH_EVEN_MODULUS                   (5575)
#define D_ERR_BN_INPUT_NOT_REDUCED                          (5576)
#define D_ERR_BN_TOO_MANY_TMP_VARIABLES                     (5577)
#define D_ERR_BN_INVALID_LEN                                (5578)
#define D_ERR_BN_ENCODING_ERROR                             (5579)
#define D_ERR_INVALID_PUBLIC_EXP                            (5580)
#define D_ERR_INVALID_SPB_HDR_LEN                           (5581)
#define D_ERR_INVALID_SPB_HDR_VER                           (5582)
#define D_ERR_INVALID_SPB_HDR_SPECIAL_TREATMENT             (5583)
#define D_ERR_INVALID_SPB_HDR_R0                            (5584)
#define D_ERR_INVALID_SPB_HDR_DST_ASYM_ALG                  (5585)
#define D_ERR_INVALID_SPB_HDR_DST_SYM_ALG                   (5586)
#define D_ERR_INVALID_SPB_HDR_SIGN_KEY_TYPE                 (5587)
#define D_ERR_INVALID_SPB_HDR_DST_CA                        (5588)
#define D_ERR_INVALID_SPB_HDR_SIGN_CA                       (5589)
#define D_ERR_INVALID_SIGN_CERT_SN_MISMATCH                 (5590)
#define D_ERR_INVALID_DST_CERT_SN_MISMATCH                  (5591)
#define D_ERR_INVALID_SPB_MSG_LEN                           (5592)
#define D_ERR_CANNOT_PARSE_JSON                             (5593)
#define D_ERR_INVALID_SPB_CHARSET_SIG_OK                    (5594)
#define D_ERR_JSON_MORE_DATA                                (5595)
#define D_ERR_CANNOT_VIRTUALIZE_JSON                        (5596)
#define D_ERR_CANNOT_CHANGE_OEM_JSON                        (5597)
#define D_ERR_CANNOT_MERGE_JSON                             (5598)
#define D_ERR_INVALID_SPB_CHARSET                           (5599)
#define D_ERR_CANNOT_GET_JSON                               (5600)
#define D_ERR_INVALID_SPB_CHARSET_SIG_ERR                   (5601)
#define D_ERR_INVALID_SPB_DOMAIN                            (5602)
#define D_ERR_SERVER_STARTED                                (5700)
#define D_ERR_HSM_AUTO_TEST_FAILURE                         (5701)
#define D_ERR_SERVER_NOT_STARTED                            (5702)
#define D_ERR_UNAPPROVED_TSP_OPERATION                      (5703)
#define D_ERR_THROTTLED_VM_SIZE                             (10000)
#define D_ERR_THROTTLED_RAM                                 (10001)
#define D_ERR_CANNOT_ALLOC_SOCKET                           (11000)
#define D_ERR_CANNOT_ALLOC_MEM                              (11001)
#define D_ERR_CANNOT_ALLOC_KEY                              (11002)
#define D_ERR_CANNOT_ALLOC_SL_BE_HANDLE                     (11003)
#define D_ERR_CANNOT_ALLOC_IOM                              (11004)
#define D_ERR_CANNOT_INIT_DRBG                              (11005)
#define D_ERR_CANNOT_SEED_DRBG                              (11006)
#define D_ERR_CANNOT_USE_IOM                                (11007)
#define D_ERR_CANNOT_ALLOC_OBJ_HANDLE                       (11008)
#define D_ERR_REPL_CANNOT_ALLOC_SL_BE_HANDLE                (11009)
#define D_ERR_CANNOT_ALLOC_TLS_CTX                          (11010)
#define D_ERR_CANNOT_ALLOC_TLS_SOCKET                       (11011)
#define D_ERR_CANNOT_SERIALIZE_XML                          (11012)
#define D_ERR_CANNOT_ALLOC_BN                               (11013)
#define D_ERR_CANNOT_ALLOC_JSON                             (11014)
#define D_ERR_REPLICATION_BUSY                              (36000)
#define D_ERR_REPLICATION_D_BUSY                            (36001)
#define D_ERR_REPLICATION_S_BUSY                            (36002)
#define D_ERR_REPLICATION_STORAGE_LAYER_BUSY                (36003)
#define D_ERR_REPLICATION_SEC_LAYER_BUSY                    (36004)
#define D_ERR_REPLICATION_PEER_NOT_SYNCED                   (36500)
#define D_ERR_REPLICATION_CANNOT_PREPARE_TRANS              (37001)
#define D_ERR_REPLICATION_CANNOT_P2P_HANDSHAKE              (37002)
#define D_ERR_REPLICATION_CANNOT_P2P_FIND                   (37003)
#define D_ERR_REPLICATION_CANNOT_P2P_CONNECT                (37004)
#define D_ERR_REPLICATION_CANNOT_P2P_SEND                   (37005)
#define D_ERR_REPLICATION_CANNOT_P2P_RECV                   (37006)
#define D_ERR_REPLICATION_CANNOT_P2P_SEND_ALL               (37007)
#define D_ERR_REPLICATION_CANNOT_P2P_RECV_ALL               (37008)
#define D_ERR_REPLICATION_CANNOT_P2P_SCONNECT               (37009)
#define D_ERR_REPLICATION_CANNOT_P2P_SSEND                  (37010)
#define D_ERR_REPLICATION_CANNOT_P2P_SRECV                  (37011)
#define D_ERR_REPLICATION_CANNOT_P2P_SSEND_ALL              (37012)
#define D_ERR_REPLICATION_CANNOT_P2P_SRECV_ALL              (37013)
#define D_ERR_REPLICATION_CANNOT_P2P_WORK                   (37014)
#define D_ERR_REPLICATION_NOT_FOUND                         (37015)
#define D_ERR_REPLICATION_ACK_NOT_FOUND                     (37016)
#define D_ERR_REPLICATION_INVALID_OPERATION                 (37017)
#define D_ERR_REPLICATION_INVALID_EVENT                     (37018)
#define D_ERR_REPLICATION_OPERATION_FAILED                  (37019)
#define D_ERR_REPLICATION_COMMIT_FAILED                     (37020)
#define D_ERR_REPLICATION_ERASE_FAILED                      (37021)
#define D_ERR_REPLICATION_INQUIRE_FAILED                    (37022)
#define D_ERR_REPLICATION_UPDATE_ACK_FAILED                 (37023)
#define D_ERR_REPLICATION_DISPATCH_FAILED                   (37024)
#define D_ERR_REPLICATION_CANNOT_SL_BE_TRANSP               (37025)
#define D_ERR_REPLICATION_CANNOT_PRUNE_LOG                  (37026)
#define D_ERR_REPLICATION_CANNOT_LOAD_LOG                   (37027)
#define D_ERR_REPLICATION_CANNOT_WORK                       (37028)
#define D_ERR_REPLICATION_CANNOT_VALIDATE_EVENT             (37029)
#define D_ERR_REPLICATION_TRANS_MISMATCH                    (37030)
#define D_ERR_REPLICATION_CANNOT_SYNC_POINT                 (37031)
#define D_ERR_REPLICATION_UNDEFINED_LIVE_SYNC               (37032)
#define D_ERR_REPLICATION_CONNECTED_LIVE_SYNC               (37033)
#define D_ERR_REPLICATION_SELF_LIVE_SYNC                    (37034)
#define D_ERR_REPLICATION_OBJ_IN_USE                        (37035)
#define D_ERR_REPLICATION_CANNOT_BEGIN_TRANS                (37036)
#define D_ERR_REPLICATION_MAX_NODE_COUNT_REACHED            (37037)
#define D_ERR_REPL_CANNOT_PREPARE_LS_TRANS                  (37038)
#define D_ERR_REPL_PART_CANNOT_ADD_LOG                      (37039)
#define D_ERR_REPL_COOR_CANNOT_ADD_LOG                      (37040)
#define D_ERR_CANNOT_LOAD_LICENSE                           (47000)
#define D_ERR_INVALID_LICENSE                               (47001)
#define D_ERR_LICENSE_EXPIRED                               (47002)
#define D_ERR_LICENSE_BLOCKED                               (47003)

// -------------------------------------------------------------------



/* Server error macros */

#define D_IS_REPL_BUSY_ERR(dw) ( \
                (DWORD)(dw) == (DWORD) D_ERR_REPLICATION_BUSY   ||             \
                (DWORD)(dw) == (DWORD) D_ERR_REPLICATION_D_BUSY ||             \
                (DWORD)(dw) == (DWORD) D_ERR_REPLICATION_S_BUSY ||             \
                (DWORD)(dw) == (DWORD) D_ERR_REPLICATION_STORAGE_LAYER_BUSY || \
                (DWORD)(dw) == (DWORD) D_ERR_REPLICATION_SEC_LAYER_BUSY        \
             )




#define NOT_LISTED_ERROR (-999999)

/* DOpenSession - Options/parameters */

/* dwParam */
#define SS_ANONYMOUS			(0x00000001)  /*pbData == AUTH_PWD ou AUTH_PWD_EX*/
#define SS_USER_PWD				(0x00000002)  /*pbData == AUTH_PWD*/
#define SS_CERTIFICATE			(0x00000004)  /*pbData == SS_MEDIA_FILE*/
#define SS_CLUSTER				(0x00000008)  /*pbData == NULL*/
#define SS_USR_PWD_EX			(0x00000010)  /*pbData == AUTH_PWD_EX*/
#define SS_ATOKEN				(0x00000020)  /*pbData == AUTH_ATOKEN*/
#define SS_HTTP                 (0x00000040)  /*pbData == AUTH_HTTP*/

/* dwFlags */
#define ENCRYPTED_CONN      (0x00000001)  /* Encrypted communication */
#define USER_INTERACTIVE    (0x00000002)  /* User interactive. Not implemented. */
#define CLEAR_CONN          (0x00000004)  /* Not encrypted communication */
#define LB_BYPASS           (0x00000008)  /* Load balance bypass */
#define CACHE_BYPASS        (0x00000010)  /* Session Cache bypass */
#define DS_BYPASS           (0x00000020)  /* Dinamo Services bypass */

/* Strong authentication */

#define SA_AUTH_NONE			(0x00000000)    /* No strong authentication */
#define SA_AUTH_OTP				(0x00000001)    /* OTP authentication */
#define SA_AUTH_CERTIFICATE		(0x00000002)    /* Certificate authentication */

/* SetSessionParam/GetSessionParam */

/* dwParam */
#define SP_SESSION_TIMEOUT                  (0x00000001)  /* Time-out sessao pbData == dwTimeout (ms) */
#define SP_SEND_TIMEOUT                     (0x00000002)  /* Time-out send pbData == dwTimeout (ms) */
#define SP_RECV_TIMEOUT                     (0x00000004)  /* Time-out recv pbData == dwTimeout (ms) */
#define SP_ENCRYPTED                        (0x00000008)  /* Read-only pbData == bSessionEncrypted (TRUE/FALSE) */
#define SP_SESSION_ID                       (0x00000010)  /* Read-only pbData == dwSessionId */
#define SP_SESSION_CID                      (0x00000020)  /* Read-only pbData == DWORD */
#define SP_SESSION_TYPE                     (0x00000040)  /* Read-only pbData == DWORD */
#define SP_SESSION_CIPHER                   (0x00000080)  /* Read-only pbData == char * */
#define SP_SESSION_PIX_HTTP_RET             (0x00000100)  /* Read-only pbData == long */
#define SP_SESSION_PIX_HTTP_REQ_DETAILS     (0x00000200)  /* Read-only pbData == PIX_HTTP_REQUEST_DETAILS */

/* SP_SESSION_TYPE */

#define SP_SESSION_TYPE_CLEAR_CONN		(1)
#define SP_SESSION_TYPE_SSL2			(2)
#define SP_SESSION_TYPE_SSL3			(3)
#define SP_SESSION_TYPE_TLS1			(4)
#define SP_SESSION_TYPE_TLS1_1			(5)
#define SP_SESSION_TYPE_TLS1_2			(6)
#define SP_SESSION_TYPE_UNKNOWN			(7)


/* CloseSession */

/* dwFlags */
#define WAIT_OPERATIONS     (0x00000004)  /* Wait the end of all operations in progress. Not implemented. */
#define CLOSE_PHYSICALLY    (0x00000008)  /* Force the end of the connection with the HSM. Session will not be cached. */

/* DDSBindHSM */

#define D_DS_BIND_VERSION (1)
#define D_MAX_DS_BIND_URL (255)
#define D_DS_BIND_PSK_LEN (16)
#define D_MIN_DS_BIND_B62_ID (1)
#define D_MAX_DS_BIND_B62_ID (22)

/* DBackupObject */

#define D_BACKUP_OBJ		(1)
#define D_RESTORE_OBJ		(2)

#define D_MAX_BACKUP_OBJ_LEN	(1024*4)

/* Backup */

#define MAKE_BACKUP                         (0)
#define MAKE_RESTORE                        (1)                /* Deprecated. Only defined for backward compatibility. */
#define MAKE_RESTORE_WITH_NET_CONFIG        MAKE_RESTORE
#define MAKE_RESTORE_WITHOUT_NET_CONFIG     (2)

/* GetHsmData/SetHsmData */

/* dwParam */
#define HD_AUDIT_START      (0x00000001)  /* Indicate that the connection will be used to retrieve logs. */
#define HD_AUDIT_RECV       (0x00000002)  /* Receive logs from server. */

/* dwFlags */
#define DATA_ONLY           (0x00000008)  /* Backup/Restore only data */
#define CONFIG_ONLY         (0x00000010)  /* Backup/Restore only configurations*/


/* GetHsmConfig/SetHsmConfig */

/* dwParam*/
#define HC_PASS_PORT_VALUE  (0x00000001)  /* Monitoring port. pbData == wPortNumber */
#define HC_PASS_PORT_ENABLE (0x00000002)  /* Enable/disable monitoring port. pbData == bEnable */
#define HC_MAX_CONNECT      (0x00000004)  /* Maximum connections (processing). pbData == dwMaxConnections */
#define HC_MAX_MONITORING   (0x00000008)  /* Maximum connections (monitoring). pbData == dwMaxConnections */
#define HC_PERMISSION_IP    (0x00000010)  /* Clients IP list. pbData == szIPList (xxx.xxx.xxx.xxx;xxx...) */

/* dwFlags */
#define ENABLE_VALUES       (0x00000020)  /* Enable values indicated by pbData. */
#define DISABLE_VALUES      (0x00000040)  /* Disable values indicated by pbData. */


/* DAdmOperation */

/* dwParam */
#define AO_SHUTDOWN           (0x00000001)  /* Shutdown HSM. pbData == NULL */
#define AO_RESTART            (0x00000002)  /* Restart HSM services. pbData == NULL */
#define AO_KEEPALIVE          (0x00000004)  /* Keep session alive. */
#define AO_SET_DATE_TIME      (0x00000008)  /* Set the HSM's time and date. pbData == struct tm (time.h) */
#define AO_ADD_CLUSTER_LIST   (0x00000010)  /* DEPRECATED! */
#define AO_DEL_CLUSTER_LIST   (0x00000012)  /* DEPRECATED! */
#define AO_GET_CLUSTER_LIST   (0x00000014)  /* DEPRECATED! */
#define AO_RST_CLUSTER_LIST   (0x00000018)  /* DEPRECATED! */
#define AO_SET_PWD_SEC_POLICY (0x00000019)  /* Define password security policies. */
#define AO_GET_PWD_SEC_POLICY (0x00000020)  /* Recover password security policies. */
#define AO_REPL_UPDATE        (0x00000021)  /* Process an update replication command. pbData == NULL */
#define AO_REPL_NODE_MESSAGE  (0x00000022)  /* Send comands to the HSM's replication subsystem. pbData == *REPL_NODE_MSG */
#define AO_LOG_CACHE_STATE    (0x00000023)  /* Get cache log state. pbData == *DWORD */
#define AO_LOG_CACHE_ENABLE   (0x00000024)  /* Enable log cache. pbData == NULL */
#define AO_LOG_CACHE_DISABLE  (0x00000025)  /* Disable log cache. pbData == NULL */
#define AO_SET_TLS_BUNDLE	  (0x00000026)  /* Set TLS bundle. pbData == TLS_BUNDLE_INFO */

#define AO_KEEPALIVE_FLAG_NOISELESS ((DWORD) -2371)

#define AO_LOG_CACHE_STATE_ENABLED   (11)
#define AO_LOG_CACHE_STATE_DISABLED  (22)

//
// Replication operation messages
// to be used with AO_REPL_NODE_MESSAGE.
//
#define RNM_PROBE           (1)
#define RNM_DOWN            (2)
#define RNM_SLP_BYPASS_ADD  (3)
#define RNM_SLP_BYPASS_DEL  (4)

/* SetUserParam/GetUserParam */

/* dwParam */
#define UP_USER_NAME                (0x00000001)  /* User name. pbData == szUserName */
#define UP_AUTH_MASK                (0x00000002)  /* Authorization mask. pdData == dwAuthMask */
#define UP_ACCESS_TYPE              (0x00000004)  /* Access type mask. pbData == dwAccessType */
#define UP_CERTIFICATE              (0x00000008)  /* User certificate. pbData == pbCertificate */
#define UP_PASSWORD                 (0x00000010)  /* User password. pbData == pwd */
#define UP_INVALID_LOGIN_ATTEMPTS   (0x00000020)  /* Amount of invalid login attempts. pbData == DWORD */
#define UP_BLOCK_USR                (0x00000040)  /* Block user. == szUserName */
#define UP_UNBLOCK_USR              (0x00000080)  /* Unblock user. == szUserName */
#define UP_USR_PASSWORD             (0x00000100)  /* Re-define user password. == USER_INFO */
#define UP_USR_PA_STATE				(0x00000200)  /* Partition autorization state. == USER_PA_INFO */

/* FindUser */

/* dwFindType */
#define FU_USER_ID          (0x00000001)  /* User ID pvFindParam == szUserId */
#define FU_USER_NAME        (0x00000002)  /* User ID pvFindParam == szUserName */
#define FU_AUTH_MASK        (0x00000004)  /* Authorization mask. pvFindParam == dwAuthMask */
#define FU_ACCESS_TYPE      (0x00000008)  /* Access type. pvFindParam == dwAccessType */
#define FU_ROOT_ID          (0x00000010)  /* Root certificate issuer. pvFindParam == szRootCN */

/* dwFlags */
#define PARTIAL_VALUE       (0x00000080)  /* pvFindParam contains part of the search value. */

/* DGetHsmInfo */

#define HI_BATTERY_LIFE     (0x00000001)  /* Battery remaining life time. pbData == tLife (time_t) */
#define HI_PERFOMANCE_COUNT (0x00000002)  /* Use percentage: CPU, Memory e disk. pbData == * PERFOMANCE_COUNT */
#define HI_MODULE_INFO      (0x00000004)  /* Existing modules. pbData == * MODULE_INFO */
#define HI_HSM_INFO         (0x00000008)  /* HSM's model and version. pbData == szHsmInfo */
#define HI_OPERATIONS_COUNT (0x00000010)  /* Operation counter. pbData == * OPERATIONS_INFO */
#define HI_SYS_HEALTH       (0x00000020)  /* Elapsed time since last update and battery check. pbData == * SYS_HEALTH */
#define HI_FIPS_MODE        (0x00000040)  /* Recover HSM's operation mode. pbData == *DWORD */
#define HI_DISK_INFO        (0x00000080)  /* Recover HSM's disk usage information. pbData == *SYS_DISK_INFO */
#define HI_REPL_INFO        (0x00000100)  /* Recover HSM's replication information. pbData == *SYS_REPL_INFO */
#define HI_CURRENT_DATE     (0x00000200)  /* Recover HSM's date and time. pbData == *QWORD */
#define HI_HW_STR           (0x00000400)  /* Recover HSM's date and time. pbData == *SYS_HW_STR_INFO */
#define HI_NTP_INFO         (0x00000800)  /* Recover HSM's date and time. pbData == *SYS_NTP_INFO */
#define HI_STATS_INFO       (0x00001000)  /* Recover HSM's statistics info. pbData == *SYS_STATUS_INFO */
#define HI_COUNTER_INFO     (0x00002000)  /* Recover HSM's counter info. pbData == *SYS_COUNTER_INFO */
#define HI_FIPS_RCODE_INFO  (0x00004000)  /* Recover HSM's FIPS auto-test return code. pbData == *DWORD */
#define HI_PENDING_INFO     (0x00008000)  /* Recover HSM's pending info. pbData == *SYS_PENDING_INFO */
#define HI_ALL_INFO			(0x00010000)  /* Recover HSM's ALL info. pbData == *SYS_ALL_INFO */


#define INVALID_OBJ_TYPE    (0)

#define MSGSH_NO_INFO  (0xFFFFFFFF)


#define GET_INFO_MAX_REPL_DOMAIN_NAME        (1024)
#define GET_INFO_MAX_REPL_NODES               (255)
#define GET_INFO_MAX_SN_LEN                   (255)
#define GET_INFO_MAX_HW_STR_LEN               (255)
#define GET_INFO_MAX_TPKEY_LEN                 (16)
#define GET_INFO_MAX_NTP_SVRS                  (16)
#define GET_INFO_MAX_NTPQ_LEN                 (256)
#define GET_INFO_MAX_NTP_KT_LEN                (16)
#define GET_INFO_MAX_NTP_KM_LEN                (64)


//Replication states returned by SYS_REPL_INFO structure.
#define REPL_STATE_TWOPC_VIRTUAL       (1)
#define REPL_STATE_TWOPC_PREPARED      (2)
#define REPL_STATE_TWOPC_COMMITTED     (3)
#define REPL_STATE_TWOPC_COMMITTED_TM  (4)

//Replication events returned by SYS_REPL_INFO structure.
#define REPL_EVENT_ET_NULL                       (1)
#define REPL_EVENT_ET_CREATE_USR                 (2)
#define REPL_EVENT_ET_DELETE_USR                 (3)
#define REPL_EVENT_ET_CREATE_OBJ                 (4)
#define REPL_EVENT_ET_DELETE_OBJ                 (5)
#define REPL_EVENT_ET_DELETE_USR_OTP_AUTH_INFO   (6)
#define REPL_EVENT_ET_WRITE_USR_OTP_AUTH_INFO    (7)
#define REPL_EVENT_ET_UPDATE_USR_OTP_AUTH_INFO   (8)
#define REPL_EVENT_ET_CHANGE_USR_PWD             (9)
#define REPL_EVENT_ET_SET_USR_LOCK_COUNT        (10)
#define REPL_EVENT_ET_SET_GLOBAL_SEC_POLICY     (11)
#define REPL_EVENT_ET_SET_SYS_DATE_TIME         (12)
#define REPL_EVENT_ET_UPDATE_ACL                (13)
#define REPL_EVENT_ET_BLOCK_OBJ                 (14)
#define REPL_EVENT_ET_UPDATE_OBJ                (15)
#define REPL_EVENT_ET_SET_USR_NS_AUTH_COOKIE    (16)
#define REPL_EVENT_ET_SET_USR_OTP_MOV_FACTOR    (17)

/* DListUserTrusts */

#define OP_LST_USR_TRUSTERS  (0x01) /* List users that permits the current logged user to access it's partition. */
#define OP_LST_USR_TRUSTEES  (0x02) /* List users that have permission to access the current logged user's partition. */


/* DAssignToken/DUnassignToken */

#define AT_GO3_TOKEN            (1) /* DEPRECATED! */
#define AT_OATH_TOKEN           (2) /* Assign a OATH EVENT OTP token */
#define AT_OATH_TOKEN_TOTP      (3) /* Assign a OATH TIME OTP token */

//
// mod_OATH's NEW_SA; use with structure OATH_SA_v1.
//
#define MAX_OATH_HMAC_LEN         (128)   // up to hmac-sha512, in bytes

#define OATH_SA_v1_type_SHA1            (0x01)
#define OATH_SA_v1_HOTP_DYN_TRUNC_OFF     (16)
#define OATH_SA_v2_default_TIME_STEP      (30)
#define OATH_SA_v2_default_T0_Epoch        (0)


/* DOATHResync */

#define OATH_MIN_HOTP_LEN    (6 + 1) //plus 1 for the null terminator
#define OATH_MAX_HOTP_LEN    (16 + 1) //plus 1 for the null terminator

/* DOATHGetBlobInfo */

#define OATH_ISSUE_OATH_BLOB_t			(1)
#define OATH_ISSUE_OATH_INFO_t			(2)


/* DEncrypt/DDecrypt */

#define D_NO_RSA_PADDING            (3)
#define D_FORCE_ACTUAL_RSA            (4)


/* DPKCS7Sign - Sign using PKCS#7 */

#define TAC_MOD_CORE_P7_TEXT           0x0001
#define TAC_MOD_CORE_P7_NOCERTS        0x0002
#define TAC_MOD_CORE_P7_NOSIGS         0x0004
#define TAC_MOD_CORE_P7_NOCHAIN        0x0008
#define TAC_MOD_CORE_P7_NOINTERN       0x0010
#define TAC_MOD_CORE_P7_NOVERIFY       0x0020
#define TAC_MOD_CORE_P7_DETACHED       0x0040
#define TAC_MOD_CORE_P7_BINARY         0x0080
#define TAC_MOD_CORE_P7_NOATTR         0x0100
#define TAC_MOD_CORE_P7_NOSMIMECAP     0x0200
#define TAC_MOD_CORE_P7_NOOLDMIMETYPE  0x0400
#define TAC_MOD_CORE_P7_CRLFEOL        0x0800
#define TAC_MOD_CORE_P7_NOCRL          0x2000

#define TAC_MOD_CORE_P7_COSIGN         0x80000000



/* HASH algorithms */

#define ALG_MD5             (1)
#define ALG_SHA1            (2)
#define ALG_SSL_SHA1_MD5    (3)
#define ALG_SHA2_256        (4)
#define ALG_SHA2_384        (5)
#define ALG_SHA2_512        (6)
#define ALG_SHA2_224        (7)
#define ALG_SHA3_224		(8)
#define ALG_SHA3_256		(9)
#define ALG_SHA3_384		(10)
#define ALG_SHA3_512		(11)

#define ALG_IDENTITY_FUNC	(255)

/*
	DSignXML/DSignXML2/DPIXSign hash mode options.
*/
#define ALG_MD5_InclC14N                (1)
#define ALG_SHA1_InclC14N               (2)
#define ALG_SHA256_InclC14N             (3)
#define ALG_SHA384_InclC14N             (4)
#define ALG_SHA512_InclC14N             (5)
#define ALG_SHA224_InclC14N             (6)
#define ALG_MD5_ExclC14N                (31)
#define ALG_SHA1_ExclC14N               (32)
#define ALG_MD5_InclC14NWithComments    (33)
#define ALG_SHA1_InclC14NWithComments   (34)
#define ALG_MD5_ExclC14NWithComments    (35)
#define ALG_SHA1_ExclC14NWithComments   (36)
#define ALG_SHA256_ExclC14N             (37)
#define ALG_SHA256_InclC14NWithComments (38)
#define ALG_SHA256_ExclC14NWithComments (39)
#define ALG_SHA384_ExclC14N             (40)
#define ALG_SHA384_InclC14NWithComments (41)
#define ALG_SHA384_ExclC14NWithComments (42)
#define ALG_SHA512_ExclC14N             (43)
#define ALG_SHA512_InclC14NWithComments (44)
#define ALG_SHA512_ExclC14NWithComments (45)
#define ALG_SHA224_ExclC14N             (46)
#define ALG_SHA224_InclC14NWithComments (47)
#define ALG_SHA224_ExclC14NWithComments (48)

/* 
	DSignXML2 flags
*/


#define XML_SIGN_FLAGS_FQN    (1 << 31)
#define XML_SIGN_FLAGS_NOL    (1 << 30)
#define XML_SIGN_FLAGS_NO_RNS (1 << 29)


/*
	DSignXML/DSignXML2 filter options
*/

#define XML_FILTER_NULL_URI        "''"

/*
	DPIXSign flags
*/

#define PIX_SIGN_RNS	(1)

/* DPIXPost/DPIXGet/DPIXDelete */

#define PIX_VERIFY_HOST_NAME    (0x00000001)
#define PIX_BASIC_HTTP_HEADER   (0x00000002)
#define PIX_GZIP                (0x00000004)

/*
	DPIXJWSSign
*/

#define PIX_JWS_GEN_MAX_LEN (8*1024)

#define MD5_LEN             (16)
#define SHA1_LEN            (20)
#define SSL_SHA1_MD5_LEN    (36)
#define SHA2_224_LEN        (28)
#define SHA2_256_LEN        (32)
#define SHA2_384_LEN        (48)
#define SHA2_512_LEN        (64)
#define CMAC_3DES_LEN       (8)
#define CMAC_AES_LEN        (16)
#define SHA3_224_LEN        (28)
#define SHA3_256_LEN        (32)
#define SHA3_384_LEN        (48)
#define SHA3_512_LEN        (64)

#define MAX_HASH_LEN        (64)//SHA2_512_LEN

/* Digital signature */

#define NO_HASH_OID         (1)
#define MD5_HASH_OID        (2)
#define SHA_HASH_OID        (3)
#define SHA256_HASH_OID     (4)
#define SHA384_HASH_OID     (5)
#define SHA512_HASH_OID     (6)
#define SHA224_HASH_OID     (7)

#define MD5_HASH_OID_LEN    (18)
#define SHA_HASH_OID_LEN    (15)
#define SHA224_HASH_OID_LEN (19)
#define SHA256_HASH_OID_LEN (19)
#define SHA384_HASH_OID_LEN (19)
#define SHA512_HASH_OID_LEN (19)

/* DSignHash flags */

#define DN_SIGN_NO_HASH_OID					  (0x01)
#define DN_SIGN_DISABLE_LEGACY_OPERATION      (0x02)
#define DN_SIGN_ECC_P11_FMT					  (0x04)

/* DVerifySignature flags */

#define DN_VERIFY_NO_HASH_OID					  (0x01)
#define DN_VERIFY_ECC_P11_FMT					  (0x02)

#define DN_SIG_EDDSA_MAX_DATA_LEN			(4 * 1024 * 1024)

/* Symmetric cryptography algorithms */

#define ALG_DES             (1)
#define ALG_3DES_112        (2)  /* EDE */
#define ALG_3DES_168        (3)  /* EDE */
#define ALG_DESX            (91)

#define ALG_AES_128         (7)
#define ALG_AES_192         (8)
#define ALG_AES_256         (9)

#define ALG_ARC4            (10)
#define ALG_ARC5            (89)

/* Symmetric key sizes (bytes) */

#define ALG_DES_LEN             (8)
#define ALG_DES3_112_LEN        (16)
#define ALG_DES3_168_LEN        (24)

//Deprecated
#define DES_LEN             (ALG_DES_LEN)
#define DES3_112_LEN        (ALG_DES3_112_LEN)
#define DES3_168_LEN        (ALG_DES3_168_LEN)

#define ALG_DESX_LEN        (24)

#define ALG_AES_128_LEN     (16)
#define ALG_AES_192_LEN     (24)
#define ALG_AES_256_LEN     (32)

#define ALG_ARC4_LEN        (16)
#define ALG_ARC5_LEN        (16)

/* Block sizes */

#define DES_BLOCK            (8)
#define DES3_BLOCK           (8)
#define DESX_BLOCK           (8)
#define AES_BLOCK			(16)
#define AES_128_BLOCK       (16)
#define AES_192_BLOCK       (16)
#define AES_256_BLOCK       (16)
#define ARC5_BLOCK          (8)

/* Operation modes */

#define MODE_NONE			(0)
#define MODE_ECB            (1 << 0)
#define MODE_CBC            (1 << 1)
#define MODE_CFB            (1 << 2)
#define MODE_OFB            (1 << 3)
#define MODE_CTR			(1 << 4)
#define MODE_GCM			(1 << 5)
#define MODE_KW             (1 << 6) // AES: SP800-38F / RFC3394

/* Operation directions */

#define D_ENCRYPT          (0 << 7)
#define D_DECRYPT          (1 << 7)

/* Asymmetric algorithms */

#define ALG_RSA_512         (4)
#define ALG_RSA_1024        (5)
#define ALG_RSA_2048        (6)
#define ALG_RSA_4096        (11)
#define ALG_RSA_1152        (121)
#define ALG_RSA_1408        (122)
#define ALG_RSA_1536        (131)
#define ALG_RSA_1976        (130)
#define ALG_RSA_1984        (123)
#define ALG_RSA_8192        (124)
#define ALG_RSA_2304		(126)
#define ALG_RSA_2560		(127)
#define ALG_RSA_2816		(128)
#define ALG_RSA_3072		(129)


#define ALG_ECX_ED25519 (201)
#define ALG_ECX_ED448   (202)
#define ALG_ECX_X25519  (203)
#define ALG_ECX_X448    (204)

#define ALG_ECC_SECP112R1          (18) // SECG/WTLS curve over a 112 bit prime field
#define ALG_ECC_SECP112R2          (19) // SECG curve over a 112 bit prime field
#define ALG_ECC_SECP128R1          (20) // SECG curve over a 128 bit prime field
#define ALG_ECC_SECP128R2          (21) // SECG curve over a 128 bit prime field
#define ALG_ECC_SECP160K1          (22) // SECG curve over a 160 bit prime field
#define ALG_ECC_SECP160R1          (23) // SECG curve over a 160 bit prime field
#define ALG_ECC_SECP160R2          (24) // SECG/WTLS curve over a 160 bit prime field
#define ALG_ECC_SECP192K1          (25) // SECG curve over a 192 bit prime field
#define ALG_ECC_SECP192R1          (26) // NIST/X9.62/SECG curve over a 192 bit prime field
#define ALG_ECC_SECP224K1          (27) // SECG curve over a 224 bit prime field
#define ALG_ECC_SECP224R1          (28) // NIST/SECG curve over a 224 bit prime field
#define ALG_ECC_SECP256K1          (29) // SECG curve over a 256 bit prime field
#define ALG_ECC_SECP256R1          (30) // X9.62/SECG curve over a 256 bit prime field
#define ALG_ECC_SECP384R1          (31) // NIST/SECG curve over a 384 bit prime field
#define ALG_ECC_SECP521R1          (32) // NIST/SECG curve over a 521 bit prime field
#define ALG_ECC_X9_62_PRIME192V1   (ALG_ECC_SECP192R1)
#define ALG_ECC_X9_62_PRIME192V2   (33) // X9.62 curve over a 192 bit prime field
#define ALG_ECC_X9_62_PRIME192V3   (34) // X9.62 curve over a 192 bit prime field
#define ALG_ECC_X9_62_PRIME239V1   (35) // X9.62 curve over a 239 bit prime field
#define ALG_ECC_X9_62_PRIME239V2   (36) // X9.62 curve over a 239 bit prime field
#define ALG_ECC_X9_62_PRIME239V3   (37) // X9.62 curve over a 239 bit prime field
#define ALG_ECC_X9_62_PRIME256V1   (ALG_ECC_SECP256R1)

#define ALG_ECC_BRAINPOOL_P160R1   (38) // RFC 5639 standard curves
#define ALG_ECC_BRAINPOOL_P160T1   (39)
#define ALG_ECC_BRAINPOOL_P192R1   (40)
#define ALG_ECC_BRAINPOOL_P192T1   (41)
#define ALG_ECC_BRAINPOOL_P224R1   (42)
#define ALG_ECC_BRAINPOOL_P224T1   (43)
#define ALG_ECC_BRAINPOOL_P256R1   (44)
#define ALG_ECC_BRAINPOOL_P256T1   (45)
#define ALG_ECC_BRAINPOOL_P320R1   (46)
#define ALG_ECC_BRAINPOOL_P320T1   (47)
#define ALG_ECC_BRAINPOOL_P384R1   (48)
#define ALG_ECC_BRAINPOOL_P384T1   (49)
#define ALG_ECC_BRAINPOOL_P512R1   (50)
#define ALG_ECC_BRAINPOOL_P512T1   (51)


/* blobs */
#define BLOB_TYPE                  (12)
#define ALG_OBJ_BLOB               (12)
#define ALG_OBJ_BLOB_X509          (13)
#define ALG_OBJ_BLOB_PKCS7         (14)
#define ALG_OBJ_BLOB_CRL           (15)
#define ALG_OBJ_BLOB_HOTP          (16)
#define ALG_OBJ_BLOB_DPGO3         (17) /* TAC-PASS (Vasco Digipass GO3 Compatible) */
#define ALG_OBJ_MAP                (90)
#define ALG_OBJ_EXT_MAP_2_OBJ     (125)


/* Public key objects */

#define ALG_OBJ_PUBKEY_BLOB           (350)
#define ALG_OBJ_PUBKEY_RSA_BLOB       (351) // pkcs1/oem
#define ALG_OBJ_PUBKEY_ECC_BLOB       (352) // SubjectPublicKeyInfo
#define ALG_OBJ_PUBKEY_SPKI_RSA_BLOB  (353) // SubjectPublicKeyInfo
#define ALG_OBJ_PUBKEY_ECC_Ed_BLOB    (354) // SubjectPublicKeyInfo
#define ALG_OBJ_PUBKEY_ECC_X_BLOB     (355) // SubjectPublicKeyInfo

/* HMAC objects */

#define ALG_HMAC_MD5               (92)
#define ALG_HMAC_SHA1              (93)
#define ALG_HMAC_SHA2_256          (94)
#define ALG_HMAC_SHA2_384          (95)
#define ALG_HMAC_SHA2_512          (96)
#define ALG_HMAC_SHA2_224          (97)
#define ALG_HMAC_SHA3_224          (98)
#define ALG_HMAC_SHA3_256          (99)
#define ALG_HMAC_SHA3_384         (100)
#define ALG_HMAC_SHA3_512         (101)

/* CMAC algorithms - DCreateHash Only */

#define ALG_CMAC_AES              (250)
#define ALG_CMAC_DES              (251)


/* PKCS11 objects */

#define ALG_PKCS11_MAP             (120) // pkcs11 shell obj



#define MAX_ALG_ID            (ALG_OBJ_PUBKEY_SPKI_RSA_BLOB)


/* Public keys -> most significant bit of the DWORD must be set. */

#define ALG_RSA_512_PUB     (ALG_RSA_512 | 1 << 31)
#define ALG_RSA_1024_PUB    (ALG_RSA_1024 | 1 << 31)
#define ALG_RSA_2048_PUB    (ALG_RSA_2048 | 1 << 31)
#define ALG_RSA_4096_PUB    (ALG_RSA_4096 | 1 << 31)
#define ALG_RSA_1152_PUB    (ALG_RSA_1152 | 1 << 31)
#define ALG_RSA_1408_PUB    (ALG_RSA_1408 | 1 << 31)
#define ALG_RSA_1536_PUB    (ALG_RSA_1536 | 1 << 31)
#define ALG_RSA_1976_PUB    (ALG_RSA_1976 | 1 << 31)
#define ALG_RSA_1984_PUB    (ALG_RSA_1984 | 1 << 31)
#define ALG_RSA_8192_PUB    (ALG_RSA_8192 | 1 << 31)
#define ALG_RSA_2304_PUB	(ALG_RSA_2304 | 1 << 31)
#define ALG_RSA_2560_PUB	(ALG_RSA_2560 | 1 << 31)
#define ALG_RSA_2816_PUB	(ALG_RSA_2816 | 1 << 31)
#define ALG_RSA_3072_PUB	(ALG_RSA_3072 | 1 << 31)

#define ALG_ECX_ED25519_PUB (ALG_ECX_ED25519 | 1 << 31)
#define ALG_ECX_ED448_PUB   (ALG_ECX_ED448 | 1 << 31)
#define ALG_ECX_X25519_PUB  (ALG_ECX_X25519 | 1 << 31)
#define ALG_ECX_X448_PUB    (ALG_ECX_X448 | 1 << 31)


#define ALG_ECC_SECP112R1_PUB          (ALG_ECC_SECP112R1 | (1 << 31))
#define ALG_ECC_SECP112R2_PUB          (ALG_ECC_SECP112R2 | (1 << 31))
#define ALG_ECC_SECP128R1_PUB          (ALG_ECC_SECP128R1 | (1 << 31))
#define ALG_ECC_SECP128R2_PUB          (ALG_ECC_SECP128R2 | (1 << 31))
#define ALG_ECC_SECP160K1_PUB          (ALG_ECC_SECP160K1 | (1 << 31))
#define ALG_ECC_SECP160R1_PUB          (ALG_ECC_SECP160R1 | (1 << 31))
#define ALG_ECC_SECP160R2_PUB          (ALG_ECC_SECP160R2 | (1 << 31))
#define ALG_ECC_SECP192K1_PUB          (ALG_ECC_SECP192K1 | (1 << 31))
#define ALG_ECC_SECP192R1_PUB          (ALG_ECC_SECP192R1 | (1 << 31))
#define ALG_ECC_SECP224K1_PUB          (ALG_ECC_SECP224K1 | (1 << 31))
#define ALG_ECC_SECP224R1_PUB          (ALG_ECC_SECP224R1 | (1 << 31))
#define ALG_ECC_SECP256K1_PUB          (ALG_ECC_SECP256K1 | (1 << 31))
#define ALG_ECC_SECP256R1_PUB          (ALG_ECC_SECP256R1 | (1 << 31))
#define ALG_ECC_SECP384R1_PUB          (ALG_ECC_SECP384R1 | (1 << 31))
#define ALG_ECC_SECP521R1_PUB          (ALG_ECC_SECP521R1 | (1 << 31))
#define ALG_ECC_X9_62_PRIME192V1_PUB   (ALG_ECC_SECP192R1_PUB)
#define ALG_ECC_X9_62_PRIME192V2_PUB   (ALG_ECC_X9_62_PRIME192V2 | (1 << 31))
#define ALG_ECC_X9_62_PRIME192V3_PUB   (ALG_ECC_X9_62_PRIME192V3 | (1 << 31))
#define ALG_ECC_X9_62_PRIME239V1_PUB   (ALG_ECC_X9_62_PRIME239V1 | (1 << 31))
#define ALG_ECC_X9_62_PRIME239V2_PUB   (ALG_ECC_X9_62_PRIME239V2 | (1 << 31))
#define ALG_ECC_X9_62_PRIME239V3_PUB   (ALG_ECC_X9_62_PRIME239V3 | (1 << 31))
#define ALG_ECC_X9_62_PRIME256V1_PUB   (ALG_ECC_SECP256R1_PUB)

#define ALG_ECC_BRAINPOOL_P160R1_PUB   (ALG_ECC_BRAINPOOL_P160R1 | (1 << 31))
#define ALG_ECC_BRAINPOOL_P160T1_PUB   (ALG_ECC_BRAINPOOL_P160T1 | (1 << 31))
#define ALG_ECC_BRAINPOOL_P192R1_PUB   (ALG_ECC_BRAINPOOL_P192R1 | (1 << 31))
#define ALG_ECC_BRAINPOOL_P192T1_PUB   (ALG_ECC_BRAINPOOL_P192T1 | (1 << 31))
#define ALG_ECC_BRAINPOOL_P224R1_PUB   (ALG_ECC_BRAINPOOL_P224R1 | (1 << 31))
#define ALG_ECC_BRAINPOOL_P224T1_PUB   (ALG_ECC_BRAINPOOL_P224T1 | (1 << 31))
#define ALG_ECC_BRAINPOOL_P256R1_PUB   (ALG_ECC_BRAINPOOL_P256R1 | (1 << 31))
#define ALG_ECC_BRAINPOOL_P256T1_PUB   (ALG_ECC_BRAINPOOL_P256T1 | (1 << 31))
#define ALG_ECC_BRAINPOOL_P320R1_PUB   (ALG_ECC_BRAINPOOL_P320R1 | (1 << 31))
#define ALG_ECC_BRAINPOOL_P320T1_PUB   (ALG_ECC_BRAINPOOL_P320T1 | (1 << 31))
#define ALG_ECC_BRAINPOOL_P384R1_PUB   (ALG_ECC_BRAINPOOL_P384R1 | (1 << 31))
#define ALG_ECC_BRAINPOOL_P384T1_PUB   (ALG_ECC_BRAINPOOL_P384T1 | (1 << 31))
#define ALG_ECC_BRAINPOOL_P512R1_PUB   (ALG_ECC_BRAINPOOL_P512R1 | (1 << 31))
#define ALG_ECC_BRAINPOOL_P512T1_PUB   (ALG_ECC_BRAINPOOL_P512T1 | (1 << 31))

/* Binary objects */

#define ALG_OBJ_INVALID_TYPE    (0)
#define ALG_OBJ_NULL            (ALG_OBJ_INVALID_TYPE)
#define ALG_OBJ                 (12)
#define OBJ_BLOCK               (1)


/* RSA module sizes */
#define RSA_512_LEN             (64)
#define RSA_1024_LEN            (128)
#define RSA_2048_LEN            (256)
#define RSA_4096_LEN            (512)
#define RSA_1152_LEN            (144)
#define RSA_1408_LEN            (176)
#define RSA_1536_LEN            (192)
#define RSA_1976_LEN            (247)
#define RSA_1984_LEN            (248)
#define RSA_8192_LEN            (1024)
#define RSA_2304_LEN			(288)
#define RSA_2560_LEN			(320)
#define RSA_2816_LEN			(352)
#define RSA_3072_LEN			(384)

#define RSA_512_PUB_LEN         (RSA_512_LEN  * 2)
#define RSA_1024_PUB_LEN        (RSA_1024_LEN * 2)
#define RSA_2048_PUB_LEN        (RSA_2048_LEN * 2)
#define RSA_4096_PUB_LEN        (RSA_4096_LEN * 2)
#define RSA_1152_PUB_LEN        (RSA_1152_LEN * 2)
#define RSA_1408_PUB_LEN        (RSA_1408_LEN * 2)
#define RSA_1536_PUB_LEN        (RSA_1536_LEN * 2)
#define RSA_1976_PUB_LEN        (RSA_1976_LEN * 2)
#define RSA_1984_PUB_LEN        (RSA_1984_LEN * 2)
#define RSA_8192_PUB_LEN        (RSA_8192_LEN * 2)
#define RSA_2304_PUB_LEN		(RSA_2304_LEN * 2)
#define RSA_2560_PUB_LEN		(RSA_2560_LEN * 2)
#define RSA_2816_PUB_LEN		(RSA_2816_LEN * 2)
#define RSA_3072_PUB_LEN		(RSA_3072_LEN * 2)

#define MAX_RSA_PUB_LEN         RSA_8192_PUB_LEN
#define MAX_RSA_LEN             RSA_8192_LEN


/* ECC key sizes (bits) */
#define ECC_SECP112R1_LEN          (112)
#define ECC_SECP112R2_LEN          (112)
#define ECC_SECP128R1_LEN          (128)
#define ECC_SECP128R2_LEN          (128)
#define ECC_SECP160K1_LEN          (160)
#define ECC_SECP160R1_LEN          (160)
#define ECC_SECP160R2_LEN          (160)
#define ECC_SECP192K1_LEN          (192)
#define ECC_SECP192R1_LEN          (192)
#define ECC_SECP224K1_LEN          (224)
#define ECC_SECP224R1_LEN          (224)
#define ECC_SECP256K1_LEN          (256)
#define ECC_SECP256R1_LEN          (256)
#define ECC_SECP384R1_LEN          (384)
#define ECC_SECP521R1_LEN          (521)
#define ECC_X9_62_PRIME192V1_LEN   (ECC_SECP192R1_LEN)
#define ECC_X9_62_PRIME192V2_LEN   (192)
#define ECC_X9_62_PRIME192V3_LEN   (192)
#define ECC_X9_62_PRIME239V1_LEN   (239)
#define ECC_X9_62_PRIME239V2_LEN   (239)
#define ECC_X9_62_PRIME239V3_LEN   (239)
#define ECC_X9_62_PRIME256V1_LEN   (ECC_SECP256R1_LEN)

#define ECC_BRAINPOOL_P160R1_LEN   (160) // RFC 5639 standard curves
#define ECC_BRAINPOOL_P160T1_LEN   (160)
#define ECC_BRAINPOOL_P192R1_LEN   (192)
#define ECC_BRAINPOOL_P192T1_LEN   (192)
#define ECC_BRAINPOOL_P224R1_LEN   (224)
#define ECC_BRAINPOOL_P224T1_LEN   (224)
#define ECC_BRAINPOOL_P256R1_LEN   (256)
#define ECC_BRAINPOOL_P256T1_LEN   (256)
#define ECC_BRAINPOOL_P320R1_LEN   (320)
#define ECC_BRAINPOOL_P320T1_LEN   (320)
#define ECC_BRAINPOOL_P384R1_LEN   (384)
#define ECC_BRAINPOOL_P384T1_LEN   (384)
#define ECC_BRAINPOOL_P512R1_LEN   (512)
#define ECC_BRAINPOOL_P512T1_LEN   (512)

#define ECC_Ed25519_LEN     (256)
#define ECC_Ed448_LEN		(448)
#define ECC_X25519_LEN		(256)
#define ECC_X448_LEN		(448)

/* Initialization vector sizes */

#define DES_IV_LEN            (8)
#define AES_IV_LEN            (16)

/* Padding */

#define D_NO_PADDING			  (0)
#define D_PKCS5_PADDING			  (1)
#define D_ZERO_PADDING			  (2)
#define D_OAEP_PADDING			  (3)
#define D_PKCS1_PADDING			  (4)
#define D_PSS_PADDING			  (5)
#define D_X931_PADDING			  (6)
#define D_PSS_SALT_LEN_MD_PADDING (7)

/* Key Blobs */

#define PRIVATEKEY_BLOB				(1)
#define PUBLICKEY_BLOB				(2)
#define SIMPLE_BLOB					(3)
#define PLAINTEXTKEY_BLOB			(4)
#define RAW_BLOB					(5) //Deprecated
#define HOTP_BLOB					(6)
#define SIMPLE_BLOB_OAEP			(7)
#define SIMPLE_BLOB_PKCS1			(SIMPLE_BLOB)
#define PUBLICKEY_BLOB_X509			(8)
#define SYM_WRAPPED_KEY_BLOB		(9)
#define OPAQUE_BLOB					(10)
#define PUBLICKEY_BLOB_HSM			(11)
#define PUBLICKEY_RSA_PARTS_HSM		(12)
#define PRIVATEKEY_BLOB_P8			(13)
#define PRIVATEKEY_BLOB_STRICT		(14)
#define SYM_WRAPPED_KEY_BLOB_P11	(15)//Importkey only
#define WRAPPED_KEY_BLOB            (16)

/* Pkcs11 Blobs */
#define P11_BLOB            (1)

/* Pkcs11 Update Flags */

#define UPDATE_P11_target               ( 1 << 0  )
#define UPDATE_P11_associate            ( 1 << 1  )
#define UPDATE_P11_Class                ( 1 << 2  )
#define UPDATE_P11_App                  ( 1 << 3  )
#define UPDATE_P11_Id                   ( 1 << 4  )
#define UPDATE_P11_Label                ( 1 << 5  )
#define UPDATE_P11_Trusted              ( 1 << 6  )
#define UPDATE_P11_WrapWithTrusted      ( 1 << 7  )
#define UPDATE_P11_Local                ( 1 << 8  )
#define UPDATE_P11_CertificateCategory  ( 1 << 9  )
#define UPDATE_P11_JavaMidpSecDomain    ( 1 << 10 )
#define UPDATE_P11_KeyGenMechanism      ( 1 << 11 )

/* Key types */

/* DGenerateKey DImportKey and related */
/* Flags */
#define EXPORTABLE_KEY      (0x00000001)  // Mark the key as exportable.
#define NO_CRYPTO           (0x00000002)  // The key will not be encrypted inside the HSM. Deprecated in newer versions.
#define TEMPORARY_KEY       (0x00000004)  // Mark key as temporary. Key will exist while the session exists. (default in ImportKey).
#define PERMANENT_KEY       (0x00000008)  // The key will be persistent in the HSM. (default in GenerateKey and ImportKeyPart).
#define RSA_PUB_EXP3        (0x00000800)  // Use exponent 0x03 when generating a RSA key pair
#define MOD_SPB_RELATED     (0x00001000)  // Mark as mod_SPB related object
#define TSP_KEY             (0x00002000)  // TSP keys: don't replicate, export, backup, etc;
#define BCHAIN_KEY          (0x00004000)  // BChain keys: PBKs are handled specially, etc;

// Attribute Usage-profile
#define AUP_DIG_SIG          (0x01000000) // signature generation/verification
#define AUP_DATA_CRYPTO      (0x02000000) // data encryption/decryption
#define AUP_KeK              (0x03000000) // key wrapping/unwrapping
#define AUP_MAC              (0x04000000) // MAC generation/verification
#define AUP_KDF              (0x05000000) // key derivation function
#define AUP_CRYPTOGRAM       (0x06000000) // cryptogram generation/verification
#define AUP_KEY_TRANSLATE    (0x07000000) // key translation
#define AUP_EFT_CVK          (0x08000000) // CVV generation/verification
#define AUP_EFT_VISA_PVK     (0x09000000) // PVV generation
#define AUP_EFT_IBM_3624     (0x0a000000) // PIN generation/validation
#define AUP_EFT_PEK          (0x0b000000) // PIN encryption/decryption
#define AUP_EFT_BDK          (0x0c000000) // DUKPT
#define AUP_EFT_IPEK         (0x0d000000) // DUKPT IPEK
#define AUP_EMV_IMK          (0x0e000000) // ICC MK, IDN derivation
#define AUP_EMV_IMKDAC       (0x0f000000) // ICC DAC derivation
#define AUP_EMV_IMKENC       (0x10000000) // ICC data encryption - PinBlock
#define AUP_EMV_IMKMAC       (0x11000000) // ICC data cryptogram - EmvMac
#define AUP_EMV_KeK          (0x12000000) // ICC MK wrapping
#define AUP_EMV_IMKKDF       (0x13000000) // EMV key derivation
#define AUP_EMV_IMKACRYPTO   (0x14000000) // ARPC calculation
#define AUP_EFT_KeK          (0x15000000) // EFT key wrapping/unwrapping
#define AUP_EMV_DIG_SIG      (0x16000000) // EMV signature generation/verification
#define AUP_EFT_TR31_KBPK    (0x17000000) // TR31 key-block protection key
#define AUP_EFT_TR34_PK      (0x18000000) // TR34 sign/envelope
#define AUP_SPB_PK           (0x19000000) // Brazilian National banking system sig gen/verify and key-wrapping key

#define AUP_RESERVED_MASK     (0xFF000000) // Mask of reserved Usage profile bits.

/* DRemoveKey */
#define REMOVE_FROM_HSM (0x00000020)      // Erase a key from the HSM and destroys it's handle.
#define REMOVE_FROM_HCM (REMOVE_FROM_HSM) // DEPRECATED. use REMOVE_FROM_HSM

/* SetKeyParam/GetKeyParam */

#define DKP_ALGID            (1)  /* Key algorithm ID. pbData == nAlgId */
#define DKP_IV               (2)  /* Initialization Vector. pbData == pbIV */
#define DKP_PADDING          (3)  /* Padding format. pbData == dwPadding */
#define DKP_MODE             (4)  /* Operation mode. pbData == dwOpMode */
#define DKP_OWNER            (5)  /* Key owner. pbData == szUserId (separated by ";" ) */
#define DKP_USER             (6)  /* Key user. pbData == szUserId (separated by ";" )*/
#define DKP_READ_LOCK        (7)  /* Key read lock status. pbData == NULL */
#define DKP_ENCRYPTED        (8)  /* Encrypted object. */
#define DKP_KEYLEN           (9)  /* Key size (bytes). */
#define DKP_TEMPORARY_KEY    (10) /* Temporary key. pbData == dwTempKey */
#define DKP_MAP_VALUE        (11) /* Values of a MAP object.pbData == MAP_2_OBJ_INFO*/
#define DKP_BLOCKED          (12) /* Block object. pbData == nBlocked (TRUE|FALSE)*/
#define DKP_CERT_X509_INFO   (13) /* Returns information of a x.509 certificate. pbData == CERT_X509_INFO */
#define DKP_SESSION          (14) /* Session associated to the key handle. pbData == HSESSIONCTX */
#define DKP_KEY_ID           (15) /* Key name associated to the key handle. pbData == szKeyId */
#define DKP_PUB_KEY_EXP      (16) /* Public exponent for the key. pbData == DBLOB */
#define DKP_SP80057_INFO     (17) /* Object's SP80057 info. pbData == OBJ_SP80057_INFO */
#define DKP_KEY_INFO		 (18) /* Key info. pbData == GET_USR_KEY_OFFLINE */
#define DKP_BLOCK_SIZE       (19) /* Key block size (bytes). */
#define DKP_OBJ_ATTRIBUTES   (20) /* Object attributes. pbData == DWORD*/

//Flags
#define REMOVE_ATTRIBUTE (0x00000040)

/* SetHashParam/GetHashParam */

#define DHP_ALGID            (1)  /* Hash algorithm. */
#define DHP_HASH_VALUE       (2)  /* Hash value. */
#define DHP_HASH_SIZE        (4)  /* Hash size (bytes). */

/* HashSessionKey */

#define DHS_LITTLE_ENDIAN    (1)

/* DSetObjParam */
#define OP_OBJ_BLOCKED              (1)  /* User blocked */
#define OP_OBJ_UNBLOCKED            (2)  /* Used unblocked */

/* LogParam */

#define LP_LOG_PATH            (0x00000001)  /* Log file full path. */
#define LP_LOG_LEVEL           (0x00000002) /* Log level. */

#define LOG_ERROR_LEVEL       (0)
#define LOG_DEBUG_LEVEL       (3)

#define LOG_DISABLED_LEVEL    (1000)

/*	
	DGetHSMLogInit 
	Remote log start and offset options 
*/

#define GET_LOG_START_FULL	(0x00000000) //Deprecated - Use RLOG_GET_LOG_START_FULL instead.
#define GET_LOG_END_FULL	(0x00000000) //Deprecated - Use RLOG_GET_LOG_END_FULL instead.

#define RLOG_GET_LOG_START_FULL	(0x00000000)
#define RLOG_GET_LOG_END_FULL	(0x00000000)

#define  RLOG_GET_ZLOG_START_FULL (RLOG_GET_LOG_START_FULL)
#define  RLOG_GET_ZLOG_END_FULL   (0xFFFFFFFF)

// Set both to get full compressed OEM log (pkzip format).
#define  RLOG_GET_OEM_ZLOG_START_FULL (RLOG_GET_LOG_START_FULL)
#define  RLOG_GET_OEM_ZLOG_END_FULL   (RLOG_GET_ZLOG_END_FULL -1)




/* Permissions */

#define ACL_NOP                 (0x00000000)       // "may the Force be with ya'!"
#define ACL_OBJ_DEL             (ACL_NOP + 1)      // delete objects
#define ACL_OBJ_READ            (ACL_OBJ_DEL << 1) // read obj content
#define ACL_OBJ_LIST            (ACL_OBJ_READ)     // list usr objs
#define ACL_OBJ_CREATE          (ACL_OBJ_DEL << 2) // create obj
#define ACL_OBJ_UPDATE          (ACL_OBJ_DEL << 3) // update obj (hdr and alike)
#define ACL_OBJ_WRITE           (ACL_OBJ_UPDATE)   // update obj
#define ACL_USR_CREATE          (ACL_OBJ_DEL << 4) // create usr
#define ACL_USR_DELETE          (ACL_USR_CREATE)   // makes no sense only to create
#define ACL_USR_REMOTE_LOG      (ACL_OBJ_DEL << 5) // can usr use remote log/info?
#define ACL_USR_LIST            (ACL_OBJ_DEL << 6) // can usr get user-list?
#define ACL_SYS_OPERATOR        (ACL_OBJ_DEL << 7) // operate as master (adm mode)
#define ACL_SYS_BACKUP          (ACL_OBJ_DEL << 8) // extract full appliance backup
#define ACL_SYS_RESTORE         (ACL_SYS_BACKUP)   // restore full appliance backup
#define ACL_SYS_UDATE_HSM       (ACL_OBJ_DEL << 9) // firmware and stuff like that
#define ACL_NS_AUTHORIZATION    (ACL_OBJ_DEL << 10) // user must be authorized with "m of n"
#define ACL_VIRTUAL_X509_AUTH    (ACL_OBJ_DEL << 28) // presence means SA (user must use 2F PKI)
#define ACL_VIRTUAL_OTP_AUTH    (ACL_OBJ_DEL << 29) // presence means SA (user must use 2-F OTP)
#define ACL_CHANGE_PWD_NEXT_TIME (ACL_OBJ_DEL << 30) // can force usrs to change pwd on next login


#define ACL_DEFAULT_OWNER ( ACL_OBJ_DEL | ACL_OBJ_READ | ACL_OBJ_CREATE | \
                                ACL_OBJ_UPDATE |ACL_OBJ_WRITE \
                                )

/* DGenerateCVV/DVerifyCVV */

#define    MIN_CVV_LEN            (3 + 1)
#define    MAX_PAN_LEN            (24 + 1)
#define    MAX_EXP_DATE_LEN       (4 + 1)
#define    MAX_SVC_LEN            (3 + 1)

/* DEFTExportTR31 */

// A.5.1, Table 6, inverted (little-endian);
#define EFT_ME_TR31_EXP_USAGE_AUTO (0x0000)
#define EFT_ME_TR31_EXP_USAGE_B0 (0x3042)
#define EFT_ME_TR31_EXP_USAGE_B1 (0x3142)
#define EFT_ME_TR31_EXP_USAGE_B2 (0x3242)
#define EFT_ME_TR31_EXP_USAGE_C0 (0x3043)
#define EFT_ME_TR31_EXP_USAGE_D0 (0x3044)
#define EFT_ME_TR31_EXP_USAGE_D1 (0x3144)
#define EFT_ME_TR31_EXP_USAGE_D2 (0x3244)
#define EFT_ME_TR31_EXP_USAGE_E0 (0x3045)
#define EFT_ME_TR31_EXP_USAGE_E1 (0x3145)
#define EFT_ME_TR31_EXP_USAGE_E2 (0x3245)
#define EFT_ME_TR31_EXP_USAGE_E3 (0x3345)
#define EFT_ME_TR31_EXP_USAGE_E4 (0x3445)
#define EFT_ME_TR31_EXP_USAGE_E5 (0x3545)
#define EFT_ME_TR31_EXP_USAGE_E6 (0x3645)
#define EFT_ME_TR31_EXP_USAGE_I0 (0x3049)
#define EFT_ME_TR31_EXP_USAGE_K0 (0x304B)
#define EFT_ME_TR31_EXP_USAGE_K1 (0x314B)
#define EFT_ME_TR31_EXP_USAGE_K2 (0x324B)
#define EFT_ME_TR31_EXP_USAGE_K3 (0x334B)
#define EFT_ME_TR31_EXP_USAGE_M0 (0x304D)
#define EFT_ME_TR31_EXP_USAGE_M1 (0x314D)
#define EFT_ME_TR31_EXP_USAGE_M2 (0x324D)
#define EFT_ME_TR31_EXP_USAGE_M3 (0x334D)
#define EFT_ME_TR31_EXP_USAGE_M4 (0x344D)
#define EFT_ME_TR31_EXP_USAGE_M5 (0x354D)
#define EFT_ME_TR31_EXP_USAGE_M6 (0x364D)
#define EFT_ME_TR31_EXP_USAGE_M7 (0x374D)
#define EFT_ME_TR31_EXP_USAGE_M8 (0x384D)
#define EFT_ME_TR31_EXP_USAGE_P0 (0x3050)
#define EFT_ME_TR31_EXP_USAGE_S0 (0x3053)
#define EFT_ME_TR31_EXP_USAGE_S1 (0x3153)
#define EFT_ME_TR31_EXP_USAGE_S2 (0x3253)
#define EFT_ME_TR31_EXP_USAGE_V0 (0x3056)
#define EFT_ME_TR31_EXP_USAGE_V1 (0x3156)
#define EFT_ME_TR31_EXP_USAGE_V2 (0x3256)
#define EFT_ME_TR31_EXP_USAGE_V3 (0x3356)
#define EFT_ME_TR31_EXP_USAGE_V4 (0x3456)

// A.5.3, Table 8
#define EFT_ME_TR31_EXP_MODE_AUTO (0x00)
#define EFT_ME_TR31_EXP_MODE_B (0x42)
#define EFT_ME_TR31_EXP_MODE_C (0x43)
#define EFT_ME_TR31_EXP_MODE_D (0x44)
#define EFT_ME_TR31_EXP_MODE_E (0x45)
#define EFT_ME_TR31_EXP_MODE_G (0x47)
#define EFT_ME_TR31_EXP_MODE_N (0x4E)
#define EFT_ME_TR31_EXP_MODE_S (0x53)
#define EFT_ME_TR31_EXP_MODE_T (0x55)
#define EFT_ME_TR31_EXP_MODE_V (0x56)
#define EFT_ME_TR31_EXP_MODE_X (0x58)
#define EFT_ME_TR31_EXP_MODE_Y (0x59)

// A.5.5, Table 10
#define EFT_ME_TR31_EXP_AUTO (0x00)
#define EFT_ME_TR31_EXP_X9_24 (0x45) // ANSI X9.24 approved kek form
#define EFT_ME_TR31_EXP_NON_EXPORTABLE (0x4E)
#define EFT_ME_TR31_EXP_KEK_EXPORTABLE (0x53)

/* DGeneratePVV */

#define EFT_MIN_PVKI        (0x00)
#define EFT_MAX_PVKI        (0x06)
#define EFT_PVV_LEN            (4)

/* DGeneratePIN */

#define GP_DEFAULT_PIN        (1)
#define GP_USER_DEF_PIN       (2)
#define GP_RANDOM_PIN         (3)

/* DEFTExportKey/DEFTKeKImport */

#define EK_EFT_KEK_EXPORT_RAW   (1) // BLOB() == envelope + checksum[3];
#define EK_EFT_KEK_EXPORT_VISA1 (2) // Variant-1 ZCMK, BLOB() == envelope + checksum[3];
#define EK_EFT_KEK_EXPORT_LMK   (3) // BLOB() == 3DES_CBC(SVMK, Key)
#define EK_EFT_KEK_EXPORT_JCB   (4) // BLOB() == envelope + checksum[8];

/* DPINBlockTranslate */

// translate types
#define TP_TRANSLATE_TYPE_AUTO        (0xFF)
#define TP_TRANSLATE_TYPE_IBM_3624    (0x36)
#define TP_TRANSLATE_TYPE_ISO_0        (1) // == VISA 1; HSM default
#define TP_TRANSLATE_TYPE_ISO_1        (2)
#define TP_TRANSLATE_TYPE_ISO_3        (3)

/* Other constants */


#define MAX_USR_PWD                      (16)
#define MAX_USR_LEN                      (16)
#define MAX_CN_LEN                      (256)
#define MAX_PATH_LEN                    (256)
#define MAX_MODULE_NAME_LEN             (128)
#define MAX_MODULE_VERSION_LEN           (32)
#define MAX_ADDR_LEN                    (128)
#define MAX_CHANNEL_CIPHER_NAME_LEN     (128)
#define MIN_PIN_LEN                       (8)
#define MIN_BACKUP_OBJ_PIN_LEN            (8)
#define MAX_BACKUP_OBJ_PIN_LEN            (32)
#define MIN_BACKUP_PIN_LEN               (8)
#define MAX_BACKUP_PIN_LEN               (32)
#define MAX_OBJ_NAME_LEN                 (32)
#define MAX_PIN_LEN                       (6)
#define MAX_MODULE_NAME_VERSION_LEN    (1024)
#define MAX_IP_LEN                       (15)
#define MAX_NET_NAME                     (16)
#define MAX_HOTP_PIN                      (4)
#define MAX_HOTP_IMEI                    (24)
#define MAX_HOTP_APP_NAME                (13)
#define MAX_HOTP_LOGO_LEN              (1632)
#define MAX_P11_OBJ_ID                  (128)
#define MAX_OBJ_ID_BIN_LEN           (32 + 1)
#ifndef MAX_OBJ_ID
#define MAX_OBJ_ID                        MAX_OBJ_ID_BIN_LEN
#endif
#ifndef MAX_OBJ_ID_LEN
#define MAX_OBJ_ID_LEN                    (MAX_USR_LEN + 1 + MAX_OBJ_ID)
#endif
#ifndef MAX_OBJ_ID_FQN_LEN
#define MAX_OBJ_ID_FQN_LEN                (MAX_OBJ_ID_LEN)
#endif
#define MAX_P11_DATE_TXT                 (8)
#define MIN_EFT_PIN_LEN                  (4)
#define MAX_EFT_PIN_LEN                 (12)
#define MIN_KSI_LEN						(5)
#define MIN_CTR_LEN                      (5)
#define MAX_HSM_DOMAIN_NAME				(32)
#define MAX_HSM_MODEL_NAME				(32)
#define MAX_HSM_ID_NAME					(32)


/* MOD EFT*/

#define EFT_VISA_KEY_CHECKSUM_LEN		   (3)
#define EFT_JCB_KEY_CHECKSUM_LEN		   (8)
#define EFT_EXP_DATE_LEN                   (4)

#define EFT_EMV_SDA_SEQ_LEN                (2)
#define EFT_EMV_SDA_DAC_LEN                (2)
#define EFT_EMV_ARC_LEN					   (2)
#define EFT_EMV_CSU_LEN					   (4)
#define EFT_EMV_PAD_LEN					   (8)

#define EFT_EMV_IDN_LEN      (2)
#define EFT_EMV_IDN_ATC_LEN  (2)
#define EFT_EMV_IDN_UN_LEN   (4)

#define EFT_EMV_CSR_VISA_TRACK_NUM_LEN       (3)
#define EFT_EMV_CSR_VISA_SERVICE_ID_LEN      (4)
#define EFT_EMV_CSR_VISA_ISSUER_ID_LEN       (4)
#define EFT_EMV_CSR_VISA_PUB_KEY_INDEX_LEN   (3)

#define EFT_EMV_CSR_VISA_HASH_SIZE      (20)
#define EFT_EMV_CSR_MASTER_HASH_SIZE    (28)



/* DGenerateICCMK */

#define EFT_EMV_GEN_ICC_MK_OP_CBC_EXP  (0x01)
#define EFT_EMV_GEN_ICC_MK_OP_ECB_EXP  (0x02)

/* DMAC_ISO9797_1_Met2*/

#define    EMV_MAC_TYPE_ALG1                (1)
#define    EMV_MAC_TYPE_ALG3                (2)

/* DGenerateEMV_MAC/DGenerateEMV_HMAC/DCalculateARPC */

#define EMV_OP_ISO_9797_1_M2_COMMON                     (0x01)
#define EMV_OP_ISO_9797_1_M2_MCHIP                      (0x02)
#define EMV_OP_ISO_9797_1_M2_VISA                       (0x03)
#define EMV_OP_ISO_9797_1_M2_VISA_CRYPTOGRAM            (0x04)
#define EMV_OP_ISO_9797_1_M2_VISA_ICC_V1_4_PAN_AUTO     (0x05)
#define EMV_OP_ISO_9797_1_M2_RAW                        (0x06)
#define EMV_OP_ISO_9797_1_M1_VISA_CRYPTOGRAM_PADD_V10   (0x7F)
#define EMV_OP_ISO_9797_1_M2_ELO                        (0x07)
#define EMV_OP_ISO_9797_1_M2_JCB                        (0x08)
#define EMV_OP_ISO_9797_1_M1_JCB                        (0x09)
#define EMV_OP_ISO_9797_1_M1_JCB_CRYPTOGRAM             (0x0A)

/* DGenerateDDA_ICCCert */

#define EFT_EMV_DDA_OP_RSA_SIGN1        (0x01) // rsa + sha1

/* DGenerateEMV_CSR */

#define EFT_EMV_OP_CSR_VISA              (0x01)
#define EFT_EMV_OP_CSR_MASTER            (0x02)
#define EFT_EMV_OP_CSR_ELO               (0x03)
#define EFT_EMV_OP_CSR_JCB               (0x04)


/* DGenerateISO9796Cert2 */

#define CORE_P_ISO_9796_USER_ID_LEN          (32)
#define CORE_P_ISO_9796_USER_NAME_LEN        (32)
#define CORE_P_ISO_9796_KEY_LEN             (512) // 128
#define CORE_P_ISO_9796_MIN_KEY_LEN          (64)
#define CORE_P_ISO_9796_EXPONENT_LEN          (8)
#define CORE_P_ISO_9796_MIN_EXPONENT_LEN      (1)


/* DGenerateEMV_PinBlock */

#define PBC_EMV_PIN_BLOCK_OP_COMMON           (EMV_OP_ISO_9797_1_M2_COMMON)
#define PBC_EMV_PIN_BLOCK_OP_MCHIP            (EMV_OP_ISO_9797_1_M2_MCHIP)
#define PBC_EMV_PIN_BLOCK_OP_VISA             (EMV_OP_ISO_9797_1_M2_VISA)
#define PBC_EMV_PIN_BLOCK_OP_VISA_CRYPTOGRAM  (EMV_OP_ISO_9797_1_M2_VISA_CRYPTOGRAM)
#define PBC_EMV_PIN_BLOCK_OP_ELO              (EMV_OP_ISO_9797_1_M2_ELO)
#define PBC_EMV_PIN_BLOCK_OP_JCB              (EMV_OP_ISO_9797_1_M2_JCB)

#define PBC_EMV_PIN_BLOCK_MAX_OUTPUT            (64)


/* DDeriveKeyFromBuffer */

#define EMV_DERIVE_KEY_OP_XOR     (0x01)
#define EMV_DERIVE_KEY_OP_ECB     (0x02)


/* DGeneratePKCS10CSR */

#define CORE_P10_CSR_VERSION1    (0x00)
#define CORE_P10_CSR_DN_MAX_LEN  (2048)

#define P10_CSR_DER            (1)
#define P10_CSR_PEM            (2)

#define CORE_P10_HASH_SHA1   (0x01)
#define CORE_P10_HASH_SHA224 (0x02)
#define CORE_P10_HASH_SHA256 (0x03)
#define CORE_P10_HASH_SHA384 (0x04)
#define CORE_P10_HASH_SHA512 (0x05)
#define CORE_P10_HASH_SHA2_224 CORE_P10_HASH_SHA224
#define CORE_P10_HASH_SHA2_256 CORE_P10_HASH_SHA256
#define CORE_P10_HASH_SHA2_384 CORE_P10_HASH_SHA384
#define CORE_P10_HASH_SHA2_512 CORE_P10_HASH_SHA512
#define CORE_P10_HASH_SHA3_224 (0x06)
#define CORE_P10_HASH_SHA3_256 (0x07)
#define CORE_P10_HASH_SHA3_384 (0x08)
#define CORE_P10_HASH_SHA3_512 (0x09)

/* DPKCS8ExportKey */

// ASCII
#define CORE_P8_EXPORT_PWD_LEN		(16)
#define ND_MIN_P8_PWD_LEN			(8)
#define ND_MAX_P8_PWD_LEN			(CORE_P8_EXPORT_PWD_LEN)

/* DImportPKCS12Buffer */

#define DN_MAX_P12_PWD_LEN (CORE_P8_EXPORT_PWD_LEN)

/* DExportPKCS12 */

#define DN_EXPORT_P12_LEGACY (1)

/* SPB */

#define DN_SPB_MSG_HEADER_V2_LEN       (588)
#define ND_SPB_MSG_HEADER_V2_LEN       DN_SPB_MSG_HEADER_V2_LEN
#define DN_SPB_MSG_HEADER_V3_LEN       ND_SPB_MSG_HEADER_V2_LEN
#define DN_SPB_MAX_NOTIFY_DATA_SEG     (32 * 1024)
#define ND_SPB_MAX_NOTIFY_DATA_SEG     DN_SPB_MAX_NOTIFY_DATA_SEG
#define DN_SPB_V3_TAG_LEN              (16)
#define DN_SPB_MAX_RCV_NOTIFY_DATA_SEG (ND_SPB_MAX_NOTIFY_DATA_SEG + DN_SPB_V3_TAG_LEN)

//dwFlags
#define ND_SPB_USE_CIP1 (0x80000000)
#define ND_SPB_USE_ANY  (0x40000000)


/* DSPBEncode */

#define ND_SPB_HASH_MODE_SHA1    (0x02)
#define ND_SPB_HASH_MODE_SHA256  (0x03)

//dwFlags
#define ND_SPB_ENCODE_GEN_01     (0x01)
#define ND_SPB_ENCODE_HEADER_V3  (0x02)

/* DSPBDecode */

//dwFlags
#define ND_SPB_OUT_NO_PADDING      (0x01)
#define ND_SPB_OUT_WITH_PADDING    (0x02)

#define ND_SPB_ISPB_LEN				  (8)
#define ND_SPB_CA_LEN                 (2)
#define ND_SPB_DOMAIN_MAX_LEN         (5)
#define ND_SPB_SN_MAX_LEN            (32)
#define ND_SPB_ID_MAX_LEN        (ND_SPB_SN_MAX_LEN + 1 + ND_SPB_CA_LEN + 1)
#define ND_SPB_ID_MAX_FQN_LEN    (MAX_USR_LEN + 1 + ND_SPB_SN_MAX_LEN + 1 + ND_SPB_CA_LEN + 1)
#define ND_SPB_MAX_SUBJECT         (1024)
#define ND_SPB_MAX_ISSUER          (1024)
#define ND_SPB_MAX_ALG_ID           (256)


//strong auth
#define SA_TP_MAX_DES_LEN           (16 + 1)
#define SA_TP_MAX_OFFSET_LEN         (6 + 1)
#define SA_TP_MAX_SERIAL_LEN        (10 + 1)
#define SA_TP_MAX_MKEY_LEN          (32 + 1)
#define SA_TP_MAX_OTP_LEN            (6 + 1)

#define SA_HOTP_CHAP_LEN                (10)

/* Module OATH */

/* DOATHIssueHOTPBlob */
#define ISSUE_OATH_MIN_OTP_LEN    (6)
#define ISSUE_OATH_MAX_OTP_LEN    (16)
#define ISSUE_OATH_MAX_OTP_RETRY  (129)

//bSeedLen
#define ISSUE_OATH_SHA1_LEN      (20)
#define ISSUE_OATH_SHA256_LEN    (32)
#define ISSUE_OATH_SHA512_LEN    (64)

//bTruncationOffset
#define ISSUE_OATH_DYN_TRUNC     (OATH_SA_v1_HOTP_DYN_TRUNC_OFF)

//wTimeStep
#define ISSUE_OATH_DEFAULT_TIME_STEP    (OATH_SA_v2_default_TIME_STEP)
#define ISSUE_OATH_HOTP_TS       (0)

//otT0
#define ISSUE_OATH_HOTP_T0       (OATH_SA_v2_default_T0_Epoch)

//otMovingFactor
#define ISSUE_OATH_INIT_MF       (0)

#define ISSUE_OATH_OUTPUT_BLOB_V1_LEN     (160)
#define ISSUE_OATH_OUTPUT_BLOB_V2_LEN     (180)
#define ISSUE_OATH_OUTPUT_BLOB_LEN        (ISSUE_OATH_OUTPUT_BLOB_V1_LEN)
#define ISSUE_OATH_OUTPUT_MAX_BLOB_LEN	  (ISSUE_OATH_OUTPUT_BLOB_V2_LEN)

#define OATH_MAX_PSK_LEN                 (255)

#define ISSUE_OATH_GENERATE_HOTP            (1)
#define ISSUE_OATH_GENERATE_TOTP            (2)
#define ISSUE_OATH_IMPORT_HOTP              (3)
#define ISSUE_OATH_IMPORT_TOTP              (4)


#define OATH_UPDATE_BLOB (0x80000000)

#define ISSUE_OATH_BLOB_V2_IV_LEN			(AES_BLOCK)
#define ISSUE_OATH_BLOB_V2_TAG_LEN			(AES_BLOCK)

/* DOATHCheckOTP */

#define MAX_OTP_LOOK_AHEAD_INTERVAL (255)


#define DEFAULT_PORT            (4433)


/* DListObjsFilter */

#define LST_NO_FILTER        (1)
#define LST_FILTER           (2)

/* DSPBCalculateObjectId */

#define        SPB_GENERATE_KEY_NAME    (1)
#define        SPB_GENERATE_CER_NAME    (2)


/* DIPFilterOperation */

#define D_IPF_ENABLE        (1)
#define D_IPF_DISABLE       (2)
#define D_IPF_LIST         (33)
#define D_IPF_ADD          (44)
#define D_IPF_DEL          (55)


/* DCert2CertInfo */

#define    P2C_SPB_CERT_INFO	    (1)
#define    P2C_CERT_BASIC_INFO		(2)

//CERT_X509_BASIC_INFO
#define DN_MAX_SUBJECT         (1024)
#define DN_MAX_ISSUER          (1024)
#define DN_MAX_SN	           (1024)
#define DN_MAX_EMAIL	       (1024)
#define DN_MAX_ALG_ID           (256)


/* DGenerateDUKPT */

// flags/modes; duk, pek, and mek are mutually exclusive;
#define NEW_DUKPT_MODE_DUK  (0x00000000)
#define NEW_DUKPT_MODE_EXP  (1 << 31)
#define NEW_DUKPT_MODE_DE   (1 << 30)
#define NEW_DUKPT_MODE_PEK  (1 << 29)
#define NEW_DUKPT_MODE_MEK  (1 << 28)
#define NEW_DUKPT_MODE_TMP  (1 << 27)
#define NEW_DUKPT_MODE_IPEK (1 << 26)


/* DGetNetInfo */

#define NET_INFO_MAX_SROUTE_COUNT   (48)
#define NET_INFO_MAX_SROUTE_LEN     (52)
#define NET_INFO_MAX_SNMP_T_COUNT   (16)
#define NET_INFO_MAX_SNMP_SC_STR   (255)
#define NET_INFO_MAX_SNMP_SL_STR   (255)
#define NET_INFO_MAX_SNMP_C_STR     (64)

//Flags
#define NET_INFO_INFO_0        (0)
#define NET_INFO_INFO_1        (1)

/* Bond mode - comes in bond gateway info. */
#define NET_INFO_BOND_HOT_STANDBY  "hot standby"
#define NET_INFO_BOND_BALANCE      "balance"
#define NET_INFO_BOND_AGGREGATION  "aggregation"



/* DCertEncodingConvert and DGetHSMTLSCert*/

#define CERT_OUT_DER    1
#define CERT_OUT_PEM    2



/* DGenEcdhKey -  dwOP*/

#define DN_GEN_KEY_KDF_RAW_SECRET       (0x01)
#define DN_GEN_KEY_X9_63_SHA256			(0x02)


#define DN_ECDH_GEN_KEY_MAX_DATA        (1024)
#define DN_GEN_ECDH_MAX_SHARED_LEN		(128)

/* DCreateHash */

#define DN_HASH_OFFLINE		(1)

/* DFindHSM */

//Service Type
#define DN_FIND_SRVC_TYPE_IP		(1)
#define DN_FIND_SRVC_TYPE_AAP		(2)
#define DN_FIND_SRVC_TYPE_ALL		(3)

//Filter
#define DN_FIND_FILTER_TYPE_POCKET	(0x01)
#define DN_FIND_FILTER_TYPE_XP		(0x02) //Not implemented
#define DN_FIND_FILTER_TYPE_ST		(0x04) //Not implemented
#define DN_FIND_FILTER_TYPE_LEGACY	(0x08) //Not implemented
#define DN_FIND_FILTER_TYPE_UNKNOWN	(0x10) //Not implemented
#define DN_FIND_FILTER_TYPE_HSM		(0x40000000)
#define DN_FIND_FILTER_TYPE_ALL		(0x80000000)

#define DN_SLP_POCKET_ID			"$pocket"
#define DN_SLP_HSM_MODEL_POCKET		"DMP"
#define DN_SLP_HSM_MODEL_XP			"DXP"
#define DN_SLP_HSM_MODEL_ST			"DST"
#define DN_SLP_HSM_MODEL_LEGACY		"lhM"
#define DN_SLP_HSM_MODEL_UNKNOWN	"DHSM"


/* DManageAToken */

#define DN_USR_A_TOKEN_KLEN				(16)
#define DN_RND_CHAP_LEN					(16)

#define DN_A_TOKEN_OP_ISSUE		(1)
#define DN_A_TOKEN_OP_REVOKE	(2)
#define DN_A_TOKEN_OP_LIST		(3)
#define DN_A_TOKEN_OP_L_ISSUE	(4)
#define DN_A_TOKEN_OP_L_REVOKE	(5)

#define DN_A_TOKEN_INFINITE   (~0)


/* DBatchSign */

#define DN_BATCH_SIGN_BLOCK_HEADER	((DWORD *2) + MAX_OBJ_ID_FQN_LEN)


/* DSetLBList and DGetLBList */

#define DN_LB_LIST	(1)
#define DN_MAX_LB_HSM_COUNT			(16)
#define DN_MAX_LB_SETS				(16)

/* DGetUserKey */

#define D_GET_USR_KEY_OFFLINE	(1)

/* DSVaultGenToken and DSVaultGetData */

#define D_SVAULT_MIN_TL (6)
#define D_SVAULT_MAX_TL (256)

#define D_SVAULT_T_TKR2 (1)

#define D_SVAULT_F_MASK_TOKEN (1)
#define D_SVAULT_F_MASK_SECRET (2)

#define D_SVAULT_CKS_NULL (0)
#define D_SVAULT_CKS_CPF (1)
#define D_SVAULT_CKS_CNPJ (2)
#define D_SVAULT_CKS_PAN (3)
#define D_SVAULT_CKS_IEL (4)

#define D_SVAULT_BASE10 (10)
#define D_SVAULT_BASE16 (16)
#define D_SVAULT_BASE26 (26)
#define D_SVAULT_BASE52 (52)
#define D_SVAULT_BASE62 (62)

#define D_SVAULT_TOKEN_BLOB_LEN (805)

/* DSVaultGetData */

#define D_SVAULT_GET_OP_SECRET (1)
#define D_SVAULT_GET_OP_TOKEN (2)

    /*
     *
     *    Unaligned structures
     *
     */

    /**
    Dados para geração de SVAULT token. Usado pela API DSVaultGenToken().
    */
    typedef struct tag_SVAULT_GEN_TOKEN
{
    BYTE bFlags; /**< Opções de geração. Pode ser uma das opções da tabela abaixo
     Valor | Operação
    ------|-----------------
    0 | Não utiliza máscaras para geração do _token_ ou recuperação do _secret_.
    #D_SVAULT_F_MASK_TOKEN | Utiliza máscaras para geração do _token_. A máscara poderá ser passada em DSVaultGetData().
    #D_SVAULT_F_MASK_SECRET | Utiliza máscaras para geração do _secret_. A máscara poderá ser passada em DSVaultGetData().
    */
    BYTE bCKS;   /**< Define o tipo de _checksum_ para a geração de _tokens_. 
    Pode ser uma das opções da tabela abaixo
     Valor | Operação
    ------|-----------------
#D_SVAULT_CKS_NULL | Não faz geração de _checksum_. Apenas gera o _token_.
#D_SVAULT_CKS_CPF | Gera os 2 dígitos verificadores no padrão CPF (Cadastro de Pessoas Físicas) no _token_. O _secret_ deverá conter apenas números e incluir os dígitos verificadores.
#D_SVAULT_CKS_CNPJ | Gera os 2 dígitos verificadores no padrão CNPJ (Cadastro Nacional da Pessoa Jurídica) no _token_. O _secret_ deverá conter apenas números e incluir os dígitos verificadores.
#D_SVAULT_CKS_PAN | Gera um PAN (Primary Account Number) com o dígito verificador válido no _token_. O _secret_ deverá ser completo e  conter apenas números.
#D_SVAULT_CKS_IEL | Gera os 2 dígitos verificadores no padrão do número do título de eleitor no _token_. O _secret_ deverá conter apenas números e incluir os dígitos verificadores.
    */
    BYTE bType;  /**< Deverá ser passado #D_SVAULT_T_TKR2. */
    BYTE bFrom;  /**< Define a base de representação da string UTF-8 do _secret_ para o FPE (Format-Preserving-Encryption).
    Pode ser uma das opções da tabela abaixo.
     Valor | Operação
    ------|-----------------
#D_SVAULT_BASE10 | Apenas decimais.
#D_SVAULT_BASE62 | Caracteres que são letras A-Z, a-z ou os números 0–9. */
    BYTE bTo;    /**< Define a base de representação da string do _token_ para o FPE (Format-Preserving-Encryption).
    Pode ser uma das opções da tabela abaixo.
     Valor | Operação
    ------|-----------------
#D_SVAULT_BASE10 | Apenas decimais.
#D_SVAULT_BASE62 | Caracteres que são letras A-Z, a-z ou os números 0–9. */
    char szSecret[D_SVAULT_MAX_TL + 1]; /**< O _secret_ em UTF-8 que deverá respeitar a base definida em bFrom. Deverá ter tamanho mínimo de #D_SVAULT_MIN_TL _code points_ e máximo de #D_SVAULT_MAX_TL _encoding units_ sem contar o terminador nulo. */
    char szMK[MAX_OBJ_ID_FQN_LEN]; /**< Nome da chave utilizada para a proteção do dados. */
} SVAULT_GEN_TOKEN;

/**
Dados para a abertura de sessões com o Dinamo. Essa estrutura é utilizada principalmente pelas funções DSetLBList() e DGetLBList().

*/
    typedef struct tag_HSM_ADDR
{
	char    szAddr[MAX_ADDR_LEN];   /**< Endereço do HSM (Nome ou IP no formato *xxx.xxx.xxx.xxx*). */
	int     nPort;                  /**< Porta TCP (4433). */
	time_t  tmNow;                  /**< Reservado. Para uso interno pela biblioteca. Esse valor não deve ser alterado. */
	int     nqtdcache;              /**< Reservado. Para uso interno pela biblioteca. Esse valor não deve ser alterado. */ /* Amount of sessions in cache.*/
}HSM_ADDR;

/**
Dados do conjunto de HSMs de uma lista de balanceamento de carga Dinamo. Essa estrutura é utilizada principalmente pelas funções DSetLBList() e DGetLBList().

*/
typedef struct tag_LOAD_BALANCE_LIST
{
	HSM_ADDR *pstLBList; /**< Array, do tipo HSM_ADDR, contendo um array com os HSMs participantes desta lista de balanceamento de carga. */
	DWORD dwLBListCount; /**< Quantidade de HSMs especificados em pstLBList. */
}LOAD_BALANCE_LIST;

/**

 Estrutura de descrição de IPs de HSMs.

 */
typedef struct tag_SLP_SRVR_INFO
{
	int nPort;								/**< Porta TCP (4433). */
	char szIP[MAX_IP_LEN + 1];				/**< Endereço do HSM (IP no formato *xxx.xxx.xxx.xxx*). */
	char szId[MAX_HSM_ID_NAME + 1];			/**< Identificador do HSM. */
	char szModel[MAX_HSM_MODEL_NAME + 1];	/**< Modelo do HSM. */
}SLP_SRVR_INFO;

/**
 Estrutura genérica de dados.

 */
typedef struct tag_DBLOB
{
    void *pvData;       /**< Ponteiro para um bloco de bytes. */
    DWORD dwDataLen;    /**< O número de bytes no bloco apontado por pvData. */
} DBLOB;

/* DCert2CertInfo */

typedef struct tag_SPB_CERT_X509_INFO
{
    DWORD        dwVersion;

    char        szAlgId[ND_SPB_MAX_ALG_ID];

    char        szISPB[ND_SPB_ISPB_LEN+1];
    char        szCA[ND_SPB_CA_LEN+1];
    char        szSN[ND_SPB_SN_MAX_LEN+1];

    char        szSubject[ND_SPB_MAX_SUBJECT];
    char        szIssuer[ND_SPB_MAX_ISSUER];

    struct tm    tmNotBefore;
    struct tm    tmNotAfter;

    DBLOB        dbPublicKey;
}SPB_CERT_X509_INFO;

typedef struct tag_CERT_X509_BASIC_INFO
{
    DWORD       dwVersion;

	char        szAlgId[DN_MAX_ALG_ID];

    char        szSubject[DN_MAX_SUBJECT];
    char        szIssuer[DN_MAX_ISSUER];
	char        szSN[DN_MAX_SN];

    struct tm   tmNotBefore;
    struct tm   tmNotAfter;

    DBLOB       dbPublicKey;
	int			nPubKeyHSMAlgId;
	char		szEmail[DN_MAX_EMAIL];
}CERT_X509_BASIC_INFO;


typedef struct tag_IP_FILTER_INFO
{
    char szUser[MAX_USR_LEN + 1];
    char szIp[MAX_IP_LEN + 1];
}IP_FILTER_INFO;


/* DECPrivateKey2Info and DECPublicKey2Info */

#define	DN_EC_MAX_BIG_NUM (1024)

//Field type definitions
#define DN_EC_KEY_FIELD_TYPE_NOT_DEFINED	(0)
#define DN_EC_KEY_FIELD_TYPE_PRIME_FIELD	(1)
#define DN_EC_KEY_FIELD_TYPE_BINARY_FIELD	(2)

//Out format options
#define DN_BN_2_ARRAY_OUT_BIN			(1)
#define DN_BN_2_ARRAY_OUT_HEX			(2)
#define DN_EC_KEY_PUB_X962_EC_POINT		(3)

//In format options
#define DN_EC_KEY_IN_FORMAT_DER	(1)

typedef struct tag_DN_EC_BIG_NUMBER
{
	BYTE	pbData[DN_EC_MAX_BIG_NUM];
	DWORD	dwDataLen;
}DN_EC_BIG_NUMBER;

typedef struct tag_DN_EC_POINT_INFO
{
	DN_EC_BIG_NUMBER	bnX;//Point's x-coordinate
	DN_EC_BIG_NUMBER	bnY;//Point's y-coordinate
}DN_EC_POINT_INFO;

typedef struct tag_DN_EC_GROUP_INFO
{
	int nFieldType; //See definitions above

	DN_EC_BIG_NUMBER	bnP;//In Fp fields this is p for F2M fields it's m

	DN_EC_BIG_NUMBER	bnA;//Parameter a of the equation
	DN_EC_BIG_NUMBER	bnB;//Parameter b of the equation

	DN_EC_BIG_NUMBER	bnCofactor;//Cofactor h

	DN_EC_BIG_NUMBER	bnOrder;//Order n of the generator g
	DN_EC_POINT_INFO	stGeneratorPoint;//Generator g / base point
}DN_EC_GROUP_INFO;

typedef struct tag_DN_EC_PUB_KEY_INFO
{
	DN_EC_GROUP_INFO	stGroupInfo;
	DN_EC_POINT_INFO	stPublicPoint;//Public point - w
}DN_EC_PUB_KEY_INFO;

typedef struct tag_DN_EC_PRIV_KEY_INFO
{
	DN_EC_GROUP_INFO	stGroupInfo;
	DN_EC_BIG_NUMBER	bnPrivatevalue;//Private value - s
}DN_EC_PRIV_KEY_INFO;

/**
 Estrutura com os parâmetros de uma chave pública. Para ser utilizado em DImportKey().
 */
typedef struct tag_RSA_PUB_KEY_PARTS
{
	DBLOB dbModulus; /**< Define o módulo que será utilizado. */
	DBLOB dbPubExponent; /**< Define o expoente público que será utilizado. */
}RSA_PUB_KEY_PARTS;

/**
 Estrutura que contém um big usado em RSA. Para ser utilizado em DRSAPublicKey2Info().
 */
typedef struct DN_RSA_BIG_NUMBER
{
    BYTE    pbData[RSA_8192_LEN];
    DWORD	dwDataLen;
} DN_RSA_BIG_NUMBER;

/**
 Estrutura com os parâmetros de uma chave pública. Para ser utilizado em DRSAPublicKey2Info().
 */
struct DN_RSA_PUB_KEY_INFO
{
    DN_RSA_BIG_NUMBER bnModulus;     /**< Módulo. */
    DN_RSA_BIG_NUMBER bnPubExponent; /**< Expoente público. */
};

#define DN_USER_INFO_CERT_OP_ASSOCIATE (1)
#define DN_USER_INFO_CERT_OP_UNASSOCIATE (2)

/**
Dados para a associação de certificado a um usuário para autenticação de 2 fatores. Essa estrutura é utilizada pela função DSetUserParam().
*/
typedef struct tag_USER_INFO_CERT
{
	char szUserId[MAX_USR_LEN + 1];   /**< Identificador do usuário. Deve ser único e caracteres maiúsculos e minúsculos são diferenciados (case-sensitive). */
	BYTE bOP;  /**< Operação que será executada. <br>
			   Valor | Operação
                ------|-----------------
                #DN_USER_INFO_CERT_OP_ASSOCIATE | Associa um certificado X.509 ao usuário especificado em szUserId. dbCert deverá ser preenchida com um certificado X.509 e seu tamanho.
                #DN_USER_INFO_CERT_OP_UNASSOCIATE | Desassocia um certificado X.509 do usuário especificado em szUserId. dbCert deve ser preenchido com NULL e 0 para o tamanho. */
	DBLOB dbCert; /**< Estrutura DBLOB contendo o certificado X.509 no formato DER ou PEM. */
}USER_INFO_CERT;

/**
Dados para a definição de chave e certificado utilizados pelo HSM para fechar o túnel TLS. Essa estrutura é utilizada pela função DAdmOperation().
*/
typedef struct tag_TLS_BUNDLE_INFO
{
	char			szKEY[MAX_OBJ_ID_FQN_LEN]; /**< Identificador da chave que será utilizada no fechamento do túnel TLS pelo HSM. Preencher com zeros para utilizar Chave/cert padrão.*/
	char			szCERT[MAX_OBJ_ID_FQN_LEN]; /**< Identificador do certificado que será utilizado no fechamento do túnel TLS pelo HSM. Preencher zeros para utilizar Chave/cert padrão.*/
}TLS_BUNDLE_INFO;


/**
Dados para geração de um handle de chave Dinamo. Essa estrutura é utilizada pela função DGetUserKey().
*/
typedef struct tag_GET_USR_KEY_OFFLINE
{
	char szKeyId[MAX_OBJ_ID_LEN]; /**< Identificador da chave dentro do HSM. */
	int nAlgId; /**< Indica o algoritmo associado à chave criptográfica que será gerada. Veja lista de algoritmos em DGenerateKey(). */
	DWORD dwFlags; /**< Parâmetros adicionais da chave. Veja as opções na função DGenerateKey(). */
	BOOL bTempKey; /**< Identifica se a chave é temporária ou não. TRUE para temporária e FALSE para não temporária. */
	BYTE *pbPubKey; /**< Para chaves públicas informar a chave pública no formato DER, em qualquer outro caso passar NULL. Quando esta estrutura for utilizada como parâmetro de saída e este campo for diferente de NULL, liberar este ponteiro com DFree(). */
	DWORD dwPubKeyLen; /**< Se pbPubKey for informado, este campo deverá conter o tamanho do buffer apontado por pbPubKey. Se pbPubKey não for informado, passar 0 neste campo. */
}GET_USR_KEY_OFFLINE;

/**
Detalhes de uma operação de PIX Request HTTP (POST, GET...).
Essa estrutura é utilizada pela função DGetSessionParam().
*/
struct PIX_HTTP_REQUEST_DETAILS
{
    ND_uint64_t name_lookup_time; /**< Tempo decorrido entre o início da requisição até o final da resolução de nome. Tempo em milissegundos. */
    ND_uint64_t connect_time;     /**< Tempo decorrido entre o início da requisição até o final conexão com o host remoto (ou proxy). Se houver redirecionamento o tempo é adicionado. Tempo em milissegundos. */
    ND_uint64_t appconnect_time;  /**< Tempo decorrido entre o início da requisição até o final do handshake SSL/SSH com o host remoto. Tempo em milissegundos. */
    ND_uint64_t pretransfer_time; /**< Tempo decorrido entre o início da requisição até o momento imediatamente antes do envio dos dados. Se houver redirecionamento o tempo é adicionado. Tempo em milissegundos. */
    ND_uint64_t starttransfer_time; /**< Tempo decorrido entre o início da requisição até o momento do recebimento do primeiro byte. Se houver redirecionamento o tempo é adicionado. Tempo em milissegundos. */
    ND_uint64_t total_time;         /**< Tempo total da requisição. Se houver redirecionamento o tempo é adicionado. Tempo em milissegundos. */
    ND_uint64_t redirect_time;      /**< Tempo total levado nos redirecionamentos. Tempo em milissegundos. */

    ND_uint64_t content_length_upload;   /**< Tamanho do content-length no upload dos dados. Recuperado do campo "Content-Length". Recebe -1 caso o tamanho não seja conhecido. Tamanho em bytes.*/
    ND_uint64_t content_length_download; /**< Tamanho do content-length no download dos dados. Recuperado do campo "Content-Length". Recebe -1 caso o tamanho não seja conhecido. Tamanho em bytes.*/
    ND_uint64_t upload_speed;            /**< Velocidade média do upload completo. Velocidade em bytes/segundo.*/
    ND_uint64_t download_speed;          /**< Velocidade média do download completo. Velocidade em bytes/segundo.*/
    ND_uint64_t download_size;           /**< Tamanho total do payload (body) do download. Os metadados e headers não entram nesta contagem. Tamanho em bytes.*/
    ND_uint64_t upload_size;             /**< Tamanho total do payload (body) upload. Tamanho em bytes.*/

    ND_uint64_t redirect_count; /**< Contagem de redirecionamentos feitos.*/
    ND_uint64_t num_connects;   /**< Contagem de conexões criadas para concluir a transferência anterior.*/
    ND_uint64_t request_size;   /**< Tamanho total da requisição enviada. Tamanho em bytes.*/
    ND_uint64_t received_header_size; /**< Tamanho total de todos os headers recebidos. Tamanho em bytes.*/
    ND_uint64_t http_response_code;   /**< Código de resposta HTTP da requisição. Será zero se nenhum código de resposta for recebido.*/
};

#ifdef _WIN32
    #pragma pack(push, 1) /* Align by 1 for portability issues.*/
#else
	#pragma pack(1)
#endif


/* Aligned structures */

typedef struct tag_OBJ_HDR_V1
{
    DWORD  version;
    DWORD  type;
    DWORD  attrib;
    DWORD  len;
} OBJ_HDR_V1;

/*
	Estrutura contendo os atributos SP80057 de um objeto do HSM.
*/
typedef struct tag_OBJ_SP80057_INFO
{
	QWORD qwInit; /**< Data inicial. Data em que o objeto foi inicialmente criado ou registrado no HSM.*/
	QWORD qwActiv; /**< Data de ativação. Data em que o objeto pode começar a ser utilizado.*/
	QWORD qwProc_s; /**< Data inicial de processamento. Data em que a chave simétrica pode começar a processar informações protegidas criptograficamente.*/
	QWORD qwProtect_s; /**< Data final de criptografia de proteção. Data em que a chave simétrica não deverá mais ser utilizada para criptografia de proteção.*/
	QWORD qwDeactiv; /**< Data de desativação do objeto. Data que o objeto não deverá ser mais utilizado. Com exceção de decriptação, verificação ou unwrapping sob circunstâncias específicas. */
	QWORD qwC_occur;  /**< Data inicial estimada que a chave foi comprometida. */
	QWORD qwComprom;  /**< Data em que a data de comprometimento(qwC_occur) foi definida. */
	QWORD qwArchive;  /**< Data em que o objeto foi arquivado. */
	QWORD qwLast_change;  /**< Data da última alteração no objeto. */
	QWORD qwOrig_creat;  /**< Data original de criação.*/
	QWORD qwMask;  /**< Máscara de uso SP.800-57. */
	BYTE  bState;  /**< Estado do objeto KMIP/SP.800-57. */
}OBJ_SP80057_INFO;


/*
	Estados de objetos KMIP/SP.800-57.
*/
#define DN_SL_SP80057_STATE_UNKNOWN     (0)
#define DN_SL_SP80057_STATE_PRE_ACTIVE  (1)
#define DN_SL_SP80057_STATE_ACTIVE      (2)
#define DN_SL_SP80057_STATE_DEACTIVATED (3)
#define DN_SL_SP80057_STATE_COMPROMISED (4)
#define DN_SL_SP80057_STATE_DESTROYED   (5)
#define DN_SL_SP80057_STATE_DESTROYED_C (6)

/*
	Máscara de uso de objetos SP.800-57.
*/
#define DN_SP80057_UM_SIGN                (0x00000001)
#define DN_SP80057_UM_VERIFY              (0x00000002)
#define DN_SP80057_UM_ENCRYPT             (0x00000004)
#define DN_SP80057_UM_DECRYPT             (0x00000008)
#define DN_SP80057_UM_WRAP_KEY            (0x00000010)
#define DN_SP80057_UM_UNWRAP_KEY          (0x00000020)
#define DN_SP80057_UM_EXPORT              (0x00000040)
#define DN_SP80057_UM_MAC_GENERATE        (0x00000080)
#define DN_SP80057_UM_MAC_VERIFY          (0x00000100)
#define DN_SP80057_UM_DERIVE_KEY          (0x00000200)
#define DN_SP80057_UM_CONTENT_COMMITMENT  (0x00000400)
#define DN_SP80057_UM_KEY_AGREEMENT       (0x00000800)
#define DN_SP80057_UM_CERTIFICATE_SIGN    (0x00001000)
#define DN_SP80057_UM_CRL_SIGN            (0x00002000)
#define DN_SP80057_UM_GENERATE_CRYPTOGRAM (0x00004000)
#define DN_SP80057_UM_VALIDATE_CRYPTOGRAM (0x00008000)
#define DN_SP80057_UM_TRANSLATE_ENCRYPT   (0x00010000)
#define DN_SP80057_UM_TRANSLATE_DECRYPT   (0x00020000)
#define DN_SP80057_UM_TRANSLATE_WRAP      (0x00040000)
#define DN_SP80057_UM_TRANSLATE_UNWRAP    (0x00080000)


/* DListObjsFilter */

typedef struct tag_OBJ_LIST_FILTER
{
    DWORD            dwVERB;
    OBJ_HDR_V1        stObjectHeader;
}OBJ_LIST_FILTER;

#define OBJ_LIST_VERB_VERSION        ( 1 << 0 )
#define OBJ_LIST_VERB_TYPE            ( 1 << 1 )
#define OBJ_LIST_VERB_ATTRIB        ( 1 << 2 )
#define OBJ_LIST_OBJS_OR            ( 1 << 31 )

typedef struct tag_OBJ_LIST_FILTER_OUT_DATA
{
    OBJ_HDR_V1    stObjectHeader;
    char        szObjName[MAX_OBJ_ID_FQN_LEN];

    OBJ_HDR_V1    stSlot1Header;
    char        szSlot1ObjName[MAX_OBJ_ID_FQN_LEN];

    OBJ_HDR_V1    stSlot2Header;
    char        szSlot2ObjName[MAX_OBJ_ID_FQN_LEN];

    BYTE        bBlockedStatus;
    ND_uint64_t    stCreationTime;
}OBJ_LIST_FILTER_OUT_DATA;

/**
 Estrutura com os parâmetros de um OATH Blob.
 */
typedef struct tag_ISSUE_OTP_BLOB
{
    BYTE                bSeedLen;                   /**< Define o tamanho da semente OATH. Os seguintes valores são aceitos.
                                                         Valor | Tamanho em bytes
                                                         ------|-----------------
                                                         #ISSUE_OATH_SHA1_LEN | 20
                                                         #ISSUE_OATH_SHA256_LEN | 32
                                                         #ISSUE_OATH_SHA512_LEN | 64 */
    BYTE                pbSeed[MAX_OATH_HMAC_LEN];  /**< Define uma semente OATH. Deve ser do tamanho especificado em bSeedLen. O tamanho máximo aceito é MAX_OATH_HMAC_LEN.Parâmetro utilizado apenas na importação de uma semente nova. */
    BYTE                bTruncationOffset;          /**< Apenas o seguinte valor é suportado:
                                                         Valor | Significado
                                                         ------|-----------------
                                                         #ISSUE_OATH_DYN_TRUNC | Define o algoritmo de “truncagem” como dinâmico.*/
    WORD                wTimeStep;                  /**< Valor do time step em segundos.<br>Além de definir o time step em segundos para blobs TOTP os seguintes valores também são suportados.
                                                         Valor | Significado
                                                         ------|-----------------
                                                         #ISSUE_OATH_DEFAULT_TIME_STEP | Utilizar o valor padrão de time step do  HSM,  atualmente 30 segs.
                                                         #ISSUE_OATH_HOTP_TS | Utilizar este valor quando se tratar de HOTP.*/
    ND_OATH_uint64_t    otT0;                       /**< Valor do tempo inicial.
                                                         Valor | Significado
                                                         ------|-----------------
                                                         #ISSUE_OATH_HOTP_T0 | Utilizar valor padrão do HSM.*/
    BYTE                bUseDefaultMovingFactor;    /**< Define se o valor padrão para moving factor será utilizado. <br>
														 Defina como TRUE para utilizar o moving factor padrão.<br>
														 Defina como FALSE para especificar um moving factor em otMovingFactor. Definir um moving factor não padrão é utilizado apenas em casos especiais. */
    ND_OATH_uint64_t    otMovingFactor;             /**< Define o incremento inicial do cliente antes da utilização. Utilize o valor da tabela abaixo.<br>
														Apenas utilize um valor específico em casos especiais onde saiba o que está fazendo, lembrando de definir bUseDefaultMovingFactor como FALSE.
                                                         Valor | Significado
                                                         ------|-----------------
                                                         #ISSUE_OATH_INIT_MF | Utiliza valor padrão de moving factor.*/
}ISSUE_OTP_BLOB;

/**
 Estrutura com a representação binária do blob OATH mantido internamente pelo HSM.
 */
typedef struct tab_ISSUE_OATH_BLOB_t
{
    BYTE                seed_len;                   /**< Define o tamanho da semente OATH. Os seguintes valores são aceitos.
                                                         Valor | Tamanho em bytes
                                                         ------|-----------------
                                                         #ISSUE_OATH_SHA1_LEN | 20
                                                         #ISSUE_OATH_SHA256_LEN | 32
                                                         #ISSUE_OATH_SHA512_LEN | 64 */
    BYTE                seed[MAX_OATH_HMAC_LEN];    /**< Define uma semente OATH. Deve ser do tamanho especificado em seed_len. O tamanho máximo aceito é MAX_OATH_HMAC_LEN. Parâmetro utilizado apenas na importação de uma semente nova. */
    ND_OATH_uint64_t    moving_factor;              /**< Define o incremento inicial do cliente antes da utilização.<br>Além da definição do incremento manualmente, pode-se utilizar os valores da seguinte tabela.
                                                         Valor | Significado
                                                         ------|-----------------
                                                         #ISSUE_OATH_INIT_MF | Utiliza valor padrão de moving factor. */
    BYTE                truncation_offset;          /**< O seguinte valor é suportado.
                                                         Valor | Tamanho em bytes
                                                         ------|-----------------
                                                         #ISSUE_OATH_DYN_TRUNC | Define o algoritmo de “truncagem” como dinâmico. */
    WORD                time_step;                  /**< Valor do time step em segundos.<br>Além de definir o time step em segundos para blobs TOTP os seguintes valores também são suportados.
                                                         Valor | Significado
                                                         ------|-----------------
                                                         #ISSUE_OATH_DEFAULT_TIME_STEP | Utilizar o valor padrão de time step do  HSM,  atualmente 30 segs.
                                                         ISSUE_OATH_HOTP_TS | Utilizar este valor quando se tratar de HOTP.*/
    ND_OATH_uint64_t    T0;                         /**< Valor do tempo inicial.
                                                         Valor | Significado
                                                         ------|-----------------
                                                         #ISSUE_OATH_HOTP_T0 | Utilizar valor padrão do HSM. */
    DWORD               pad_cks_tag[3];             /**<  Buffer de padding para promover alinhamento do bloco AES, autenticação da chave de envelope do blob e dos campos da estrutura.
                                                          Valor | Significado
                                                         ------|-----------------
                                                         #ISSUE_OATH_INIT_MF | Utiliza valor padrão de moving factor. */
} ISSUE_OATH_BLOB_t;

/**
 Estrutura com a representação binária do blob OATH mantido internamente pelo HSM.
 */
typedef struct tag_ISSUE_OATH_INFO_t
{
	BYTE                seed_len;                   /**< Define o tamanho da semente OATH. Os seguintes valores são aceitos.
														 Valor | Tamanho em bytes
														 ------|-----------------
														 #ISSUE_OATH_SHA1_LEN | 20
														 #ISSUE_OATH_SHA256_LEN | 32
														 #ISSUE_OATH_SHA512_LEN | 64 */
	BYTE                seed[MAX_OATH_HMAC_LEN];    /**< Define uma semente OATH. Deve ser do tamanho especificado em seed_len. O tamanho máximo aceito é MAX_OATH_HMAC_LEN. Parâmetro utilizado apenas na importação de uma semente nova. */
	ND_OATH_uint64_t    moving_factor;              /**< Define o incremento inicial do cliente antes da utilização.<br>Além da definição do incremento manualmente, pode-se utilizar os valores da seguinte tabela.
														 Valor | Significado
														 ------|-----------------
														 #ISSUE_OATH_INIT_MF | Utiliza valor padrão de moving factor. */
	BYTE                truncation_offset;          /**< O seguinte valor é suportado.
														 Valor | Tamanho em bytes
														 ------|-----------------
														 #ISSUE_OATH_DYN_TRUNC | Define o algoritmo de “truncagem” como dinâmico. */
	WORD                time_step;                  /**< Valor do time step em segundos.<br>Além de definir o time step em segundos para blobs TOTP os seguintes valores também são suportados.
														 Valor | Significado
														 ------|-----------------
														 #ISSUE_OATH_DEFAULT_TIME_STEP | Utilizar o valor padrão de time step do  HSM,  atualmente 30 segs.
														 ISSUE_OATH_HOTP_TS | Utilizar este valor quando se tratar de HOTP.*/
	ND_OATH_uint64_t    T0;                         /**< Valor do tempo inicial.
														 Valor | Significado
														 ------|-----------------
														 #ISSUE_OATH_HOTP_T0 | Utilizar valor padrão do HSM. */
} ISSUE_OATH_INFO_t;

/**
 Estrutura com a representação binária do info OATH mantido internamente pelo HSM.
 */
typedef struct tag_ISSUE_OATH_BLOB_t_v1
{
	ISSUE_OATH_INFO_t    stInfo;                         /**< Informações do internas do blob.*/
	DWORD               pad_cks_tag[3];             /**<  Buffer de padding para promover alinhamento do bloco AES, autenticação da chave de envelope do blob e dos campos da estrutura.*/
} ISSUE_OATH_BLOB_t_v1;

/**
 Estrutura com a representação binária do info OATH mantido internamente pelo HSM.
 */
typedef struct tag_ISSUE_OATH_BLOB_t_v2
{
	ISSUE_OATH_INFO_t  stInfo;                         /**< Informações do internas do blob.*/
	BYTE               pbIV[ISSUE_OATH_BLOB_V2_IV_LEN];    /**<  IV utilizado na criptografia do blob.*/
	BYTE              pad_cks_tag[ISSUE_OATH_BLOB_V2_IV_LEN];    /**<  Buffer de padding para promover alinhamento do bloco AES, autenticação da chave de envelope do blob e dos campos da estrutura.*/
} ISSUE_OATH_BLOB_t_v2;

/**
 Estrutura de saída de blobs OATH blobs traduzidos do formato PSKC para o format do HSM. O padrão PSKC (Portable Symmetric Key Container) está descrito na [RFC 6030](https://tools.ietf.org/html/rfc6030).
 */
typedef struct tag_OATH_PSKC_TRANSLATE_OUTPUT
{
    ISSUE_OATH_BLOB_t    stOATHBlob;                    /**< Blob OATH criptografado por chave AES no HSM. */
    char                szKeyId[OATH_MAX_PSK_LEN+1];    /**< ID PSK do blob. */
}OATH_PSKC_TRANSLATE_OUTPUT;

/**
Estrutura de definição de token OTP padrão OATH de evento(HOTP).
*/
typedef struct tag_OATH_SA_v1
{
    BYTE  type; /**< No momento este valor deve ser como definido na tabela.
				Valor | Significado
                 ------|-----------------
                #OATH_SA_v1_type_SHA1 | Define o tipo como SHA1.*/
    BYTE  key_len; /**< Tamanho da chave(semente) do token OTP, utilizado em #key. */
    BYTE  key[MAX_OATH_HMAC_LEN]; /**< Chave(semente) utilizado para definição do OTP padrão OATH. O tamanho da chave deve ser especificado em #key_len. */
    BYTE  truncation_offset; /**< O seguinte valor é suportado:
							 Valor | Significado
                             ------|-----------------
                             #OATH_SA_v1_HOTP_DYN_TRUNC_OFF | Define o algoritmo de “truncagem” como dinâmico. */
} OATH_SA_v1;

typedef struct tag_MOD_OATH_SA_v2
{
    OATH_SA_v1            sa_v1; /**< Estrutura contendo os dados básicos to token. */
    WORD                time_step; /**< Valor do time step em segundos. Além de definir o time step em segundos para blobs TOTP os seguinte valore também é suportado.
							 Valor | Significado
                             ------|-----------------
                             #OATH_SA_v2_default_TIME_STEP | Utilizar o valor padrão de time step do HSM, atualmente 30 segs.*/
    ND_OATH_uint64_t    T0;/**< T0 utilizado pelo token. Definido em segundos.
						   Valor | Significado
                             ------|-----------------
                             #OATH_SA_v2_default_T0_Epoch | Utilizar valor padrão do HSM.*/
} OATH_SA_v2;


typedef struct tag_STAT_CLUSTER_IP
{
    char szIp[MAX_IP_LEN + 1];
}STAT_CLUSTER_IP;


//GMT
typedef struct tag_P11_DATE{
  char       year[4];   /* the year ("1900" - "9999") */
  char       month[2];  /* the month ("01" - "12") */
  char       day[2];    /* the day   ("01" - "31") */
} P11_DATE;

typedef struct tag_CERT_X509_INFO
{
    int            nVersion;

    DBLOB        dbSubject;
    DBLOB        dbIssuer;
    DBLOB        dbSerialNumber;

    P11_DATE    dtNotBefore;
    P11_DATE    dtNotAfter;
}CERT_X509_INFO;

typedef struct tag_HOTP_INFO_EX
{
    DWORD dwStructId;                            //Structure identifier -> SA_ST_ID_HOTP_INFO_EX
    char  szObjId[MAX_OBJ_NAME_LEN + 1];        //HSM HOTP object name
    DWORD dwObjAttr;                            //HSM object attributes
    DWORD dwObjHotpFlags;                        //SoftToken type -> SA_ATTR_OATH_USE_IMEI, SA_ATTR_OATH_USE_TIME ...
    char  szStPin[MAX_HOTP_PIN + 1];            //SoftToken PIN
    char  szStIMEI[MAX_HOTP_IMEI + 1];            //SoftToken related device's serial number
    char  szStAppName[MAX_HOTP_APP_NAME + 1];    //SoftToken application name
    DBLOB *pdbStLogoImage;                        //SoftToken logo image
}HOTP_INFO_EX; //DESCONTINUADO!


//DGetNetInfo
typedef struct tag_SYS_NET_INFO
{
    BYTE pbMac[6];
    char szIp[MAX_IP_LEN + 1];
    char szMask[MAX_IP_LEN + 1];
    char szDefGateway[MAX_IP_LEN + 1];
    BYTE bUp;
    DWORD dwSpeed; //Mb/s
    char szName[MAX_NET_NAME + 1];
} SYS_NET_INFO;

typedef struct tag_SYS_NET_INFO_1
{
    SYS_NET_INFO *pstSysNetInfo;
    DWORD dwSysNetInfoCount;

    char pszStaticRoutes[NET_INFO_MAX_SROUTE_COUNT][NET_INFO_MAX_SROUTE_LEN + 1];
    char szCommunity[NET_INFO_MAX_SNMP_C_STR + 1];
    char szSysContact[NET_INFO_MAX_SNMP_SC_STR + 1];
    char szSyaLocation[NET_INFO_MAX_SNMP_SL_STR + 1];
    char pszTARGETS[NET_INFO_MAX_SNMP_T_COUNT][MAX_NET_NAME + 1];
} SYS_NET_INFO_1;

/**
 Estrutura que contém dados sobre o uptime e status da bateria do hardware de segurança do HSM.

 */
typedef struct tag_SYS_HEALTH
{
    DWORD dwUptime;     /**< Contém o tempo em  que o HSM está executando desde a sua última inicialização (uptime) em segundos. Este campo poderá conter o valor MSGSH_NO_INFO, caso a informação não possa ser recuperada. */
    DWORD dwBatteryOK;  /**< Contém o status da bateria. Poderá conter 0 (zero) para falha e diferente de zero para sucesso. Este campo poderá conter o valor MSGSH_NO_INFO, caso a informação não possa ser recuperada. */
}SYS_HEALTH;

typedef struct tag_SYS_DISK_INFO
{
    DWORD dwBlockSize;
    DWORD dwTotalBlocks;
    DWORD dwFreeBlocks;
}SYS_DISK_INFO;

/**
Estrutura que contém dados sobre status do HSM.

*/
typedef struct tag_SYS_STATUS_INFO
{ 
	DWORD dwSessions; /**< Número de sessões abertas com o HSM. */
	DWORD dwCPU; /**< Uso de CPU média. Descrito em percentual de 0-100. */
	DWORD dwUnit; /**< Unidade de tamanho em bytes, utilizada para informar os tamanhos de memória. */
	DWORD dwMemTotal; /**< Memória total. Descrito em unidades dwUnit. */
	DWORD dwMemUsed; /**< Memória utilizada. Descrito em unidades dwUnit. */
	DWORD dwSwapTotal; /**< Memória Swap total. Descrito em unidades dwUnit. */
	DWORD dwSwapUsed; /**< Memória Swap utilizada. Descrito em unidades dwUnit. */
}SYS_STATUS_INFO;

/**
Estrutura que contém dados sobre os contadores do HSM.

*/
typedef struct tag_SYS_COUNTER_INFO
{
	QWORD qwUsers; /**< Total de usuários criados no HSM. */
	QWORD qwObjects; /**< Total de objetos criados no HSM. */
	QWORD qwSLBeFileSize; /**< Tamanho total do arquivo da base de dados, em bytes. */
	QWORD qwTasks; /**< Total de threads do dispatcher. */
	QWORD qwVMSize; /**< Quantidade de memória virtual utilizada pelo dispatcher, em bytes. */
}SYS_COUNTER_INFO;


#define DN_MAX_HSM_ALIAS      (128)
#define DN_UPACK_MAX_DESCRIPTION  (255 + 1)

/**
Estrutura que contém dados sobre os contadores do HSM.

*/
typedef struct tag_SYS_PENDING_INFO
{
	BYTE bPendingBackup; /**< Indicador de backup pendente. 0 indica que não há backup pendente e qualquer outro valor indica que há backup pendente. */
	char szPendingUpackDescription[DN_UPACK_MAX_DESCRIPTION]; /**< Descrição de upack(update de firmware) presente. */
	char szHsmAlias[DN_MAX_HSM_ALIAS+1]; /**< Alias do HSM. */
}SYS_PENDING_INFO;


typedef struct tag_SYS_HW_STR_INFO
{
    char szSerialNumber[GET_INFO_MAX_SN_LEN + 1];
    char szHardwareString[GET_INFO_MAX_HW_STR_LEN + 1];
    char szTpKey[GET_INFO_MAX_TPKEY_LEN + 1];
}SYS_HW_STR_INFO;

typedef struct tag_SYS_NTP_SVR_INFO
{
    char szAddr[MAX_IP_LEN + 1];
    char szNtpqInfo[GET_INFO_MAX_NTPQ_LEN + 1];
    WORD wKeyIndex;
    DWORD dwKeyLen;
    char szKeyType[GET_INFO_MAX_NTP_KT_LEN + 1];
    char szKeyMat[GET_INFO_MAX_NTP_KM_LEN + 1];
}SYS_NTP_SVR_INFO;

typedef struct tag_SYS_NTP_INFO
{
    BYTE bENABLED;
    SYS_NTP_SVR_INFO pstNtpSvrInfo[GET_INFO_MAX_NTP_SVRS];
}SYS_NTP_INFO;



typedef struct tag_SYS_REPL_INFO
{
	char    szDomain[GET_INFO_MAX_REPL_DOMAIN_NAME + 1];
	DWORD    dwBoundEth;
	QWORD    qwGuid;
	QWORD    qwDateTime;
	QWORD    qwEventType;
	DWORD    dwState;
	DWORD    dwaPeers[GET_INFO_MAX_REPL_NODES + 1]; //Zero terminated IPv4 array. Last item == 0x00000000
	DWORD    dwaPendingAcks[GET_INFO_MAX_REPL_NODES + 1]; //Zero terminated IPv4 array. Last item == 0x00000000
	QWORD    qwSpVal;
	WORD    wSpvv;
	DWORD    dwDiscoveryReset;
	DWORD    dwManagerPulse;
	DWORD    dwRecoveryPulse;
	DWORD    dwDiscoveryPulse;
	DWORD    dwaNodes[GET_INFO_MAX_REPL_NODES + 1]; //Zero terminated IPv4 array. Last item == 0x00000000
}SYS_REPL_INFO;


/**
Estrutura que contém os dados consolidados do HSM.
*/
typedef struct tag_SYS_ALL_INFO
{
	int nFilledCount;
	SYS_STATUS_INFO stStatusInfo;
	DWORD dwFIPSMode;
	SYS_DISK_INFO stDiskInfo;
	SYS_REPL_INFO stReplicationInfo;
	QWORD qwCurrentDateTime;
	SYS_HW_STR_INFO stHardwareInfo;
	SYS_NTP_INFO stNTPInfo;
	SYS_COUNTER_INFO stCounterInfo;
	DWORD dwFIPSReturnCode;
	SYS_PENDING_INFO stPendingInfo;
}SYS_ALL_INFO;


typedef struct tag_REPL_NODE_MSG
{
    BYTE    bOP; //RNM_PROBE, RNM_DOWN...
    DWORD    dwPeer; //IPv4
}REPL_NODE_MSG;


typedef struct tag_HOTP_CHAP
{
    DWORD dwStructId;                            //Structure Id -> SA_ST_ID_HOTP_CHAP
    char szChallenge[SA_HOTP_CHAP_LEN + 1];        //Server created challenge
}HOTP_CHAP;//DEPRECATED!

typedef struct tag_HOTP_SYNC
{
    DWORD dwStructId;                    //Structure Id -> SA_ST_ID_HOTP_SYNC
    char szObjId[MAX_OBJ_NAME_LEN + 1];    //HOTPToken to synchronize
    char szOTP1[SA_TP_MAX_OTP_LEN];        //Expected response from HOTPToken
    char szOTP2[SA_TP_MAX_OTP_LEN];        //Server Counter Response
}HOTP_SYNC;

typedef struct tag_HIP_PARAM
{
  DWORD dwParam;
  DWORD dwHipFlags;
  DWORD dwHipColor;
}HIP_PARAM; //DEPRECATED!

typedef struct tag_HIP_OUTPUT
{
  char      szHipChallenge[1];
  DWORD     dwImageLen;
  BYTE      pbImage[1];
}HIP_OUTPUT; //DEPRECATED!

/**
	Estrura para passagem de parâmetros de bloqueio de usuário para DGetUserParam().
*/
typedef struct tag_USER_BLOCK
{
    char szUserId[MAX_USR_LEN+1]; /**< Identificação do usuário no HSM. O nome do usuário pode conter MAX_USR_LEN caracteres. No caso de o nome do usuário ser menor que MAX_USR_LEN, completar com zeros (\0). */
    int nBlocked; /**< 0 para não usuário bloqueado e diferente de zero para usuário bloqueado. */
    DWORD dwAttempts; /**< Número de tentativas de autenticação inválidas. */
}USER_BLOCK;

/**
 Estrura para passagem de parâmetros de acesso ATOKEN a DOpenSession.
 */
typedef struct tag_DN_A_TOKEN
{
	char pcUserName[MAX_USR_LEN]; /**< Identificação do usuário no HSM. O nome do usuário pode conter MAX_USR_LEN caracteres. No caso de o nome do usuário ser menor que MAX_USR_LEN, completar com zeros (\0). */
	BYTE pbKey[DN_USR_A_TOKEN_KLEN]; /**< Chave de acesso. Deve-se utilizar padding zero. */
}DN_A_TOKEN;

/**
 Estrura para passagem de parâmetros de DManageAToken.
 */

typedef struct tag_DN_A_TOKEN_FULL
{
	DN_A_TOKEN stAToken; /**< Estrutura DN_A_TOKEN. Contém os dados de acesso. */
	QWORD	qwExpiration; /**< Data de expiração no formato date/time; time_t. Quantidade de segundo desde UTC 1 de janeiro de 1970 */
}DN_A_TOKEN_FULL;

/**
 Dados para a abertura de sessões autenticadas com usuário/senha com o Dinamo. Essa estrutura é utilizada principalmente pela função DOpenSession().

 */
struct AUTH_PWD
{
    char szAddr[MAX_ADDR_LEN];      /**< Endereço do HSM (Nome ou IP no formato *xxx.xxx.xxx.xxx*). */
    int  nPort;                     /**< Porta TCP (4433). */
    char szUserId[MAX_USR_LEN];     /**< Identificação do usuário no HSM. O nome do usuário pode conter MAX_USR_LEN caracteres. No caso de o nome do usuário ser menor que MAX_USR_LEN, completar com zeros (\0). */
    char szPassword[MAX_USR_PWD];   /**< Senha do usuário . A senha pode conter MAX_USR_PWD caracteres. No caso da senha ser menor que MAX_USR_PWD, completar com zeros (\0). */
};

/**
Dados para a abertura de sessões autenticadas com usuário/senha com o Dinamo com segundo fator de autenticação. Essa estrutura é utilizada principalmente pela função DOpenSession().

*/
struct AUTH_PWD_EX
{
    char szAddr[MAX_ADDR_LEN]; /**< Endereço do HSM (Nome ou IP no formato *xxx.xxx.xxx.xxx*). */
    int  nPort; /**< Porta TCP (4433). */
    char szUserId[MAX_USR_LEN]; /**< Identificação do usuário no HSM. O nome do usuário pode conter MAX_USR_LEN caracteres. No caso de o nome do usuário ser menor que MAX_USR_LEN, completar com zeros (\0). */
    char szPassword[MAX_USR_PWD]; /**< Senha do usuário . A senha pode conter MAX_USR_PWD caracteres. No caso da senha ser menor que MAX_USR_PWD, completar com zeros (\0). */
    DWORD dwAuthType; /**< Tipo de autenticação.   Valor | Signficado
												   ------|-----------
												   #SA_AUTH_NONE | Utiliza autenticação de usuário e senha.<br>Definir pbStrongAuth como NULL e nStrongAuthLen como 0 (zero).
												   #SA_AUTH_OTP | Utiliza autenticação de usuário, senha e OTP.<br>Definir pbStrongAuth como OTP(One Time Password). Não incluir terminador NULL. Definir nStrongAuthLen como Tamanho do OTP em bytes. Não incluir terminador NULL.
												   #SA_AUTH_CERTIFICATE | Utiliza autenticação de usuário, senha e certificado(autenticação mútua com o HSM).<br>Definir pbStrongAuth como TLS_MUTUAL_AUTH_INFO e nStrongAuthLen como o tamanho de pbStrongAuth. */
    BYTE *pbStrongAuth; /**< Definir de acordo com o tipo de autenticação passado em dwAuthType. */
    int nStrongAuthLen; /**< Tamanho dos dados passados em pbStrongAuth. Ver definição em dwAuthType. */
};

/* HTTP session parameters */

#define MAX_HTTP_ADDR_LEN (2048)
#define MAX_HTTP_API_TOKEN_LEN (128)

/**
Dados para a abertura de sessões HTTP autenticadas com o Dinamo Services. Essa estrutura é utilizada principalmente pela função DOpenSession().
*/
struct AUTH_HTTP
{
    char szAddr[MAX_HTTP_ADDR_LEN + 1];        /**< Endereço do serviço do Dinamo Services. Tamanho máximo de #MAX_HTTP_ADDR_LEN. */
    char szAPIToken[MAX_HTTP_API_TOKEN_LEN + 1]; /**< Token de API. Chave de acesso gerada na Dinamo Services. Tamanho máximo de #MAX_HTTP_API_TOKEN_LEN.*/
    DWORD dwTimeout;                             /**< Timeout das operações em milissegundos. Se for passado 0 não há timeout definido e a operação poderá ficar em espera até obter resposta. Não é recomendado passar 0 neste campo.*/
};

/**
Dados para a abertura de sessões autenticadas com access token. Essa estrutura é utilizada principalmente pela função DOpenSession().

*/
typedef struct tag_AUTH_ATOKEN
{
    char szAddr[MAX_ADDR_LEN]; /**< Endereço do HSM (Nome ou IP no formato *xxx.xxx.xxx.xxx*). */
    int  nPort; /**< Porta TCP (4433). */
	DN_A_TOKEN stAToken; /**< Estrutura com dados do Access Token para autenticação. */
}AUTH_ATOKEN;

/**
 Dados para autenticação mútua com o HSM passado em AUTH_PWD_EX.

*/
typedef struct tag_TLS_MUTUAL_AUTH_INFO
{
	DBLOB dbPrivateKey; /**< Chave privada no formato PEM. */
	char *szPrivateKeyPwd; /**< Senha da chave privada informada em dbPrivateKey. Caso não haja senha, passar NULL ou string vazia. */
	DBLOB dbPrivateKeyCert; /**< Reservado para uso futuro. Definir parâmetros internos como NULL e 0. */
	DBLOB dbHSMCert; /**< Certificado do HSM que será conectado. Pode estar no formato PEM ou DER. Ver DGetHSMTLSCert(). */
}TLS_MUTUAL_AUTH_INFO;

/**
Dados para a criação de novos usuário no Dinamo. Essa estrutura é utilizada pela função DCreateUser().
 */
struct USER_INFO
{
    char szUserId[MAX_USR_LEN+1];   /**< Identificador do usuário. Deve ser único e caracteres maiúsculos e minúsculos são diferenciados (case-sensitive). */
    char szPassword[MAX_USR_PWD+1]; /**< Senha associada ao usuário. Caracteres maiúsculos e minúsculos são diferenciados (case-sensitive). */
    DWORD dwAuthMask;               /**< Máscara de autorização. Deve ser composta a partir de uma máscara de bits de acordo com as permissões previamente definidas. Veja a função DCreateUser. */
};

/*
	Estados de autorização de partição do usuário.
*/

#define ND_PA_ACL_OBJ_OPEN    (ACL_OBJ_READ)
#define ND_PA_ACL_OBJ_EXPORT  (ACL_OBJ_CREATE)
#define ND_PA_ACL_OBJ_DEL     (ACL_OBJ_DEL)
#define ND_PA_ACL_OBJ_BLOCK   (ACL_OBJ_UPDATE)
#define ND_PA_ACL_NS_DEL      (ACL_USR_DELETE)

#define NSAUTH_ACL_FULL        (~0)

/* 
	Estados de autorização de partição do usuário. 
*/
#define ND_PA_STATE_Unknown     (0)
#define ND_PA_STATE_Absent      (1)
#define ND_PA_STATE_Null        (2)
#define ND_PA_STATE_Associated  (3)
#define ND_PA_STATE_Authorized  (4)

/**
Dados da autorização de partição de um usuário. Essa estrutura é utilizada pela função DGetUserParam().
*/
typedef struct tag_USER_PA_INFO
{
	char szUserId[MAX_USR_LEN + 1];   /**< Identificador do usuário. Deve ser único e caracteres maiúsculos e minúsculos são diferenciados (case-sensitive). */
	DWORD dwState; /**< Estado de autorização de partição do usuário. Ver tabela abaixo.
				    Valor | Significado
					 :-----|:-----------
					 #ND_PA_STATE_Unknown | Não foi possível identificar se o usuário tem autorização de partição habilitado. Este estado é considerado um erro.
					 #ND_PA_STATE_Absent | O usuário não tem a opção de autorização de partição habilitada.
					 #ND_PA_STATE_Null | O usuário tem a opção de autorização de partição habilitada mas não um conjunto de cartões M de N associado. Objetos já podem ser criados mas não utilizados.
					 #ND_PA_STATE_Associated | O usuário tem a opção de autorização de partição habilitada e associada. A partição ainda não está autorizada. Objetos podem ser criados mas não utilizados. Outras operações também podem ser feitas de acordo com a máscara de autorização de partição.
					 #ND_PA_STATE_Authorized | O usuário tem a opção de autorização de partição habilitada e associada e autorizada. As chaves podem ser utilizadas mas não removidas ou criadas. */
	DWORD dwACL;   /**< Máscara de autorização de permissão de partição. Composta a partir de uma máscara de bits de acordo com as permissões previamente definidas. Ver tabela abaixo.
				    Valor | Significado
					 :-----|:-----------
					 #ND_PA_ACL_OBJ_OPEN | Permissão para utilizar objetos. Opção implícita e não pode ser alterada.
					 #ND_PA_ACL_OBJ_EXPORT | Permissão para exportar objetos exportáveis.
					 #ND_PA_ACL_OBJ_DEL | Permissão para destruir objetos da partição.
					 #ND_PA_ACL_OBJ_BLOCK | Permissão para bloquear objetos mesmo quando autorizados.
					 #ND_PA_ACL_NS_DEL | Permissão para remover completamente o usuário/partição e consequentemente todos os objetos contidos nele.
					*/
}USER_PA_INFO;



struct MAP_2_OBJ_INFO
{
    DWORD dwObj1AlgId;
    char szObj1Id[MAX_OBJ_NAME_LEN + 1];
    DWORD dwObj2AlgId;
    char szObj2Id[MAX_OBJ_NAME_LEN + 1];
};

typedef struct tab_EXT_MAP_2_OBJ_INFO
{
    DWORD  dwObjAlgId1;
    char   szObjId1[MAX_OBJ_ID_FQN_LEN];
    DWORD  dwObjAlgId2;
    char   szObjId2[MAX_OBJ_ID_FQN_LEN];
} EXT_MAP_2_OBJ_INFO;


struct MODULE_INFO
{
    DWORD dwModuleId;
    char szModuleNameVersion[MAX_MODULE_NAME_VERSION_LEN];
};

typedef struct tag_PKCS11_OBJ_MAP
{
    BYTE  target   [MAX_OBJ_ID_LEN];
    BYTE  associate[MAX_OBJ_ID_LEN];

    DWORD Class; // CKO_DATA, etc;

    BYTE  App  [MAX_P11_OBJ_ID + 1];
    BYTE  Id   [MAX_P11_OBJ_ID + 1];
    BYTE  Label[MAX_P11_OBJ_ID + 1];

    //The three BYTEs below are overloaded
    //must use the MACROs to set the desired parameters.
    //Macros defined below.

    BYTE  Trusted;         // boolean/overloaded
    BYTE  WrapWithTrusted; // boolean/overloaded
    BYTE  Local;           // boolean/overloaded

    DWORD CertificateCategory;
    DWORD JavaMidpSecDomain;
    DWORD KeyGenMechanism;
} PKCS11_OBJ_MAP;

//Trusted -> CKA_TRUSTED, CKA_DERIVE, CKA_ENCRYPT,
//CKA_DECRYPT, CKA_WRAP, CKA_UNWRAP
#define PKCS11_SET_FLAG(x, p)                ((x) |= (1 << (p)))
#define PKCS11_UNSET_FLAG(x, p)                ((x) &= ~(1 << (p)))
#define PKCS11_GET_FLAG(x, p)                ((x) &  (1 << (p)))

//Enable driven option. Disabled by default.
#define PKCS11_SET_OBJ_MAP_CKA_TRUSTED(x)    PKCS11_SET_FLAG(x, 7)
#define PKCS11_UNSET_OBJ_MAP_CKA_TRUSTED(x)    PKCS11_UNSET_FLAG(x, 7)
#define PKCS11_GET_OBJ_MAP_CKA_TRUSTED(x)    PKCS11_GET_FLAG(x, 7)

//Disable driven option. Enabled by default.
#define PKCS11_SET_OBJ_MAP_CKA_DERIVE(x)        PKCS11_UNSET_FLAG(x, 6)
#define PKCS11_UNSET_OBJ_MAP_CKA_DERIVE(x)        PKCS11_SET_FLAG(x, 6)
#define PKCS11_GET_OBJ_MAP_CKA_DERIVE(x)        (!PKCS11_GET_FLAG(x, 6))

#define PKCS11_SET_OBJ_MAP_CKA_ENCRYPT(x)        PKCS11_UNSET_FLAG(x, 5)
#define PKCS11_UNSET_OBJ_MAP_CKA_ENCRYPT(x)        PKCS11_SET_FLAG(x, 5)
#define PKCS11_GET_OBJ_MAP_CKA_ENCRYPT(x)        (!PKCS11_GET_FLAG(x, 5))

#define PKCS11_SET_OBJ_MAP_CKA_DECRYPT(x)        PKCS11_UNSET_FLAG(x, 4)
#define PKCS11_UNSET_OBJ_MAP_CKA_DECRYPT(x)        PKCS11_SET_FLAG(x, 4)
#define PKCS11_GET_OBJ_MAP_CKA_DECRYPT(x)        (!PKCS11_GET_FLAG(x, 4))

#define PKCS11_SET_OBJ_MAP_CKA_WRAP(x)            PKCS11_UNSET_FLAG(x, 3)
#define PKCS11_UNSET_OBJ_MAP_CKA_WRAP(x)        PKCS11_SET_FLAG(x, 3)
#define PKCS11_GET_OBJ_MAP_CKA_WRAP(x)            (!PKCS11_GET_FLAG(x, 3))

#define PKCS11_SET_OBJ_MAP_CKA_UNWRAP(x)        PKCS11_UNSET_FLAG(x, 2)
#define PKCS11_UNSET_OBJ_MAP_CKA_UNWRAP(x)        PKCS11_SET_FLAG(x, 2)
#define PKCS11_GET_OBJ_MAP_CKA_UNWRAP(x)        (!PKCS11_GET_FLAG(x, 2))

//WrapWithTrusted

//Enable driven option. Disabled by default.
#define PKCS11_SET_OBJ_MAP_CKA_WRAP_WITH_TRUSTED(x)        PKCS11_SET_FLAG(x, 7)
#define PKCS11_UNSET_OBJ_MAP_CKA_WRAP_WITH_TRUSTED(x)    PKCS11_UNSET_FLAG(x, 7)
#define PKCS11_GET_OBJ_MAP_CKA_WRAP_WITH_TRUSTED(x)        PKCS11_GET_FLAG(x, 7)

//Local
//Enable driven option. Disabled by default.
#define PKCS11_SET_OBJ_MAP_CKA_LOCAL(x)        PKCS11_SET_FLAG(x, 7)
#define PKCS11_UNSET_OBJ_MAP_CKA_LOCAL(x)    PKCS11_UNSET_FLAG(x, 7)
#define PKCS11_GET_OBJ_MAP_CKA_LOCAL(x)        PKCS11_GET_FLAG(x, 7)

//DAdmOperation options - AO_SET_PWD_SEC_POLICY/AO_GET_PWD_SEC_POLICY

typedef struct tag_PWD_SEC_POLICY
{
    //USE
    BYTE    bMaxInvalidLogins;    //Number of attempts. 0 == sets to HSM internal default.
    BYTE    bExpiration;        //Number of days. 0 == disable policy.
    BYTE    bHistory;            //Number of passwords to track. 0 == disable policy.
    //FORMAT
    BYTE    bMinLength;            //Minimal number of chars (ASCII).
    BYTE    bMinSpecial;        //Minimal number of non-alpha chars.
    BYTE    bUpper;                //Minimal number of upper-case chars.
    BYTE    bLower;                //Minimal number of lower-case chars.
}PWD_SEC_POLICY;

/**
 Estrutura para transportar as partes constituintes de uma chave dividia em 3 partes, incluindo o *checksum* de cada parte e o *checksun* final.
 */
typedef struct tag_EFT_VISA_KEY_PARTS
{
    BYTE    pbKeyPart1[3 * DES_BLOCK];                      /**< Buffer contendo a primeira parte da chave. */
    BYTE    pbKeyPart1Checksum[EFT_VISA_KEY_CHECKSUM_LEN];  /**< Valor de verificação da primeira parte. */
    BYTE    pbKeyPart2[3 * DES_BLOCK];                      /**< Buffer contendo a segunda parte da chave. */
    BYTE    pbKeyPart2Checksum[EFT_VISA_KEY_CHECKSUM_LEN];  /**< Valor de verificação da segunda parte. */
    BYTE    pbKeyPart3[3 * DES_BLOCK];                      /**< Buffer contendo a terceira parte da chave. */
    BYTE    pbKeyPart3Checksum[EFT_VISA_KEY_CHECKSUM_LEN];  /**< Valor de verificação da terceira parte.*/
    BYTE    pbMKCheckSum[EFT_VISA_KEY_CHECKSUM_LEN];        /**< Valor de verificação da chave montada com as três partes informadas nesta estrutura. */
}EFT_VISA_KEY_PARTS;

/**
 Estrutura para transportar as partes constituintes de uma chave dividia em 3 partes, incluindo o *checksum* de cada parte e o *checksun* final.
 */
typedef struct tag_EFT_FULL_CKS_KEY_PARTS
{
    BYTE    pbKeyPart1[3 * DES_BLOCK];                      /**< Buffer contendo a primeira parte da chave. */
    BYTE    pbKeyPart1Checksum[DES_BLOCK];					/**< Valor de verificação da primeira parte. */
    BYTE    pbKeyPart2[3 * DES_BLOCK];                      /**< Buffer contendo a segunda parte da chave. */
    BYTE    pbKeyPart2Checksum[DES_BLOCK];					/**< Valor de verificação da segunda parte. */
    BYTE    pbKeyPart3[3 * DES_BLOCK];                      /**< Buffer contendo a terceira parte da chave. */
    BYTE    pbKeyPart3Checksum[DES_BLOCK];					/**< Valor de verificação da terceira parte.*/
    BYTE    pbMKCheckSum[DES_BLOCK];						/**< Valor de verificação da chave montada com as três partes informadas nesta estrutura. */
}EFT_FULL_CKS_KEY_PARTS;

/**
 Estrura para passagem de parâmetros de geração de ARPC por DCalculateARPC_Ex.
 */

typedef struct tag_DN_CALC_ARPC_EMV_METHOD_1
{
	char	szIssuerMK[MAX_OBJ_ID_BIN_LEN]; /**< Nome da chave do emissor dentro do HSM que será utilizada para gerar o MAC. */
	char	szPAN[MAX_PAN_LEN];				/**< PAN (Primary Account Number). */
	BYTE	pbSEQ[EFT_EMV_SDA_SEQ_LEN];		/**< Buffer contendo o SEQ (PAN Sequence Number). */
	BYTE	pbARQC[DES_BLOCK];				/**< Buffer contendo o ARQC (Authorisation Request Cryptogram). */
	BYTE	pbARC[EFT_EMV_ARC_LEN];			/**< Buffer contendo o ARC (Authorisation Response Code). */
	BYTE	pbNONCE[DES_BLOCK];				/**< Buffer de tamanho DES_BLOCK contendo o diversificador para geração do ARPC. */
	BYTE	bOP;							/**< Tipo da operação de derivação da chave de sessão utilizada no ARPC. Ver bOP em DGenerateEMV_MAC para valores aceitos. */
}DN_CALC_ARPC_EMV_METHOD_1;

typedef struct tag_DN_CALC_ARPC_EMV_METHOD_2
{
	char	szIssuerMK[MAX_OBJ_ID_BIN_LEN]; /**< Nome da chave do emissor dentro do HSM que será utilizada para gerar o MAC. */
	char	szPAN[MAX_PAN_LEN];				/**< PAN (Primary Account Number). */
	BYTE	pbSEQ[EFT_EMV_SDA_SEQ_LEN];		/**< Buffer contendo o SEQ (PAN Sequence Number). */
	BYTE	pbNONCE[DES_BLOCK];				/**< Buffer de tamanho DES_BLOCK contendo o diversificador para geração do ARPC. */
	BYTE	bOP;							/**< Tipo da operação de derivação da chave de sessão utilizada no ARPC. Ver bOP em DGenerateEMV_MAC para valores aceitos. */

	BYTE	pbARQC[DES_BLOCK];				/**< Buffer contendo o ARQC (Authorisation Request Cryptogram). */
	BYTE	pbCSU[EFT_EMV_CSU_LEN];			/**< Buffer contendo o CSU (Card Status Update). */
	DWORD	dwCSULen;						/**< Tamanho dos dados contidos em pbCSU. Pode ser zero para não utilizar CSU. */
	BYTE	pbPAD[EFT_EMV_PAD_LEN];			/**< Buffer contendo o PAD (Proprietary Authentication Data). */
	DWORD	dwPADLen;						/**< Tamanho dos dados contidos em pbPAD. Pode ser zero para não utilizar PAD. */
}DN_CALC_ARPC_EMV_METHOD_2;


/**
Estrutura de derivação de chaves ECDH padrão X9.63.

*/
typedef struct GEN_ECDH_X9_63_ {
	char szTargetKeyName[MAX_OBJ_ID_FQN_LEN]; /**< Nome da chave que será derivada e gravada no HSM. Para gravar a chave derivada no HSM, a definição de szTargetKeyName e
											  dwTargetKeyAttributes são obrigatórias. Para receber o material gerado sem gravar a chave no HSM, preencher
											  com zeros '\0' nas opções szTargetKeyName e dwTargetKeyAttributes.*/
	DWORD dwTargetKeyAlg; /**< Algoritmo da chave que será derivada. Este parâmetro deverá ser sempre definido.*/
	DWORD dwTargetKeyAttributes; /**< Atributos da chave que será derivada. */
	DBLOB dbPubKey; /**< Chave pública no formato DER. O tamanho máximo dos buffers de dbPubKey e dbKDFData juntos não deve ultrapassar DN_ECDH_GEN_KEY_MAX_DATA.*/
	DBLOB dbKDFData; /**< Dados que serão utilizados na derivação da chave. O tamanho máximo dos buffers de dbPubKey e dbKDFData juntos não deve ultrapassar DN_ECDH_GEN_KEY_MAX_DATA.*/
}GEN_ECDH_X9_63;

/**
 Estrutura de parâmetros Dinamo Services Bind. 
 Utilizada para parametrização customizada.
 */

typedef struct tag_DS_BIND_INFO
{
    BYTE bVersion;                            /**< Versão do bind info. Deve ser 
    #D_DS_BIND_VERSION. */
    char szHSM[D_MAX_DS_BIND_B62_ID + 1];     /**< Identificador do HSM em 
    base62. Tamanho mínimo de #D_MIN_DS_BIND_B62_ID e
    máximo de #D_MAX_DS_BIND_B62_ID. */
    char szAccount[D_MAX_DS_BIND_B62_ID + 1]; /**< Identificador da conta em 
    base62. Tamanho mínimo de #D_MIN_DS_BIND_B62_ID e
    máximo de #D_MAX_DS_BIND_B62_ID. */
    BYTE pbPSK[D_DS_BIND_PSK_LEN];            /**< PSK no formato de binário de 
    tamanho fixo de #D_DS_BIND_PSK_LEN. */
    char szURL[D_MAX_DS_BIND_URL + 1];        /**< URL da Dinamo Services. Tamanho 
    máximo de #D_MAX_DS_BIND_URL. */
} DS_BIND_INFO;

#define DN_RCC_MAX_NODE_COUNT (16)
#define DN_RCC_MAX_REPL_MC_VER (256)

/**
 Estrutura de informações de nó de uma operação de cross check.
 Utilizada pela API DHSMTool().
 */
typedef struct tag_CROSS_CHECK_NODE
{
    DWORD dwCount; /**< Quantidade de nós em dwNodes. */
    DWORD dwIp;    /**< IP do HSM relacionado as informações desta estrutura. */
    DWORD pdwNodes[DN_RCC_MAX_NODE_COUNT]; /**< IPs dos nós configurados neste HSM. */
    DWORD dwRCode;  /**< Código de retorno do teste de cross check dos nós. */
    char szVersion[DN_RCC_MAX_REPL_MC_VER]; /**< Versão de firmware deste HSM. */
} CROSS_CHECK_NODE;

/* 
    Blockchain module 
*/

/* DBchainCreateXPrv */

// Types
#define DN_BCHAIN_BTC_MINIKEY       (1) /**< Bitcoin minikey. */
#define DN_BCHAIN_BIP32_SEED_XPRV   (2) /**< BIP32 seed XPrv. */
#define DN_BCHAIN_BIP39_SEED_XPRV   (3) /**< BIP39 seed XPrv. */
#define DN_BCHAIN_BIP32_XPRV        (4) /**< BIP32 XPrv. */

// Version
#define DN_BCHAIN_VER_WIF_MAIN_NET (0x80) /**< Mainnet WIF. */
#define DN_BCHAIN_VER_WIF_TEST_NET (0xEF) /**< Testnet WIF. */

#define DN_BCHAIN_BIP32_SEED_LEN_MAX (765) /**< Tamanho máximo da seed BIP32. */
/**
 Estrutura de informações para geração de uma chave XPrv formato BIP32.
*/
struct DN_BCHAIN_BIP32_SEED_XPRV_DATA
{
    BYTE ver; /**< Versão da chave a ser gerada. Ver DBchainCreateXPrv(). */
    DWORD seed_len; /**< Tamanho da seed. */
    BYTE seed[DN_BCHAIN_BIP32_SEED_LEN_MAX]; /**< Semente utilizada na geração da chave. No formato BIP32. Tamanho máximo de #DN_BCHAIN_BIP32_SEED_LEN_MAX.*/
};

#define DN_BCHAIN_BIP39_SEED_LEN_MAX (765) /**< Tamanho máximo da seed BIP39. */
#define DN_BCHAIN_BIP39_PWD_LEN_MAX (255) /**< Tamanho máximo da senha BIP39. */

/**
 Estrutura de informações para geração de uma chave XPrv formato BIP39.
*/
struct DN_BCHAIN_BIP39_SEED_XPRV_DATA
{
    BYTE ver; /**< Versão da chave a ser gerada. Ver DBchainCreateXPrv(). */
    char seed[DN_BCHAIN_BIP39_SEED_LEN_MAX + 1]; /**< String contendo a semente utilizada na geração da chave. No formato BIP39 UTF-8 NFKD. Tamanho máximo de #DN_BCHAIN_BIP39_SEED_LEN_MAX + 1 terminador nulo.*/
    char pwd[DN_BCHAIN_BIP39_PWD_LEN_MAX + 1];   /**< String contendo a senha utilizada na geração da chave. No formato BIP39 UTF-8 NFKD. Tamanho máximo de #DN_BCHAIN_BIP39_PWD_LEN_MAX + 1 terminador nulo. Pode-se passar string vazia para não utilizar senha.*/
};

#define DN_BCHAIN_KEY_INFO_ST_SL (0)    /**< Objeto comum. */
#define DN_BCHAIN_KEY_INFO_ST_BLKC (1)  /**< Objeto blockchain. */

/* DBchainCreateBip32Ckd */

/**
 Estrutura de informações de uma chave XPrv BIP32.
 */
typedef struct DN_BCHAIN_KEY_INFO
{
    BYTE bStorageType;              /**< Tipo geral do objeto. #DN_BCHAIN_KEY_INFO_ST_SL para objeto comum ou #DN_BCHAIN_KEY_INFO_ST_BLKC para objeto blockchain.*/
    DWORD dwType;                   /**< Tipo do objeto. Se bStorageType for #DN_BCHAIN_KEY_INFO_ST_SL terá valores de algoritmos comuns #ALG_RSA_2048 etc. Se for #DN_BCHAIN_KEY_INFO_ST_BLKC terá valores de tipos blockchain #DN_BCHAIN_BTC_MINIKEY, etc. Ver tipos em DBchainCreateXPrv() */
    BYTE pbBip32Ver[4];             /**< Versão do XPriv BIP32. Zero-padded para objetos não BIP32. */
    BYTE bBip32Depth;               /**< Profundidade do XPriv BIP32. Zero-padded para objetos não BIP32. */
    BYTE pbParentFingerprint[4];    /**< Fingerprint do nó pai do XPriv BIP32. Zero-padded para objetos não BIP32. */
    BYTE pbChildNumber[4];          /**< Número do nó filho do XPriv BIP32. Zero-padded para objetos não BIP32. */
} DN_BCHAIN_KEY_INFO;

/* DBchainGetAddress */

#define DN_BCHAIN_MAX_ADDR_LEN (128) /**< Tamanho máximo de um endereço. */
#define DN_BCHAIN_MAX_HRP      (64)  /**< Tamanho máximo do HRP. */

// Type
#define DN_BCHAIN_AT_BTC_P2PKH      (1) /**< Endereço P2PKH. */
#define DN_BCHAIN_AT_BTC_P2SH       (2) /**< Endereço P2SH. Não implementado. */
#define DN_BCHAIN_AT_BTC_B32_PKH    (3) /**< Endereço BIP32 P2PKH. */
#define DN_BCHAIN_AT_BTC_B32_SH     (4) /**< Endereço BIP32 P2SH. Não implementado. */
#define DN_BCHAIN_AT_ETH_EOA        (5) /**< Endereço ETH EOA. */
#define DN_BCHAIN_AT_ETH_EOA_MC_CKS (6) /**< Endereço ETH EOA MC CKS. EIP55. */
#define DN_BCHAIN_AT_ETH_EOA_ICAP   (7) /**< Endereço ETH EOA ICAP. */

// Version
#define DN_BCHAIN_VER_UNUSED            (0x00) /**< Unused. */
#define DN_BCHAIN_VER_BTC_A1_MAIN_NET   (0x00) /**< Bitcoin A1 mainnet. */
#define DN_BCHAIN_VER_BTC_A3_MAIN_NET   (0x05) /**< Bitcoin A3 mainnet. */
#define DN_BCHAIN_VER_BTC_B32_WITVER    (0x00) /**< Bitcoin B32 witver. */

// HRP
#define DN_BCHAIN_HRP_UNUSED        ""   /**< Unused. */
#define DN_BCHAIN_HRP_BTC_MAIN_NET  "bc" /**< Bitcoin mainnet. */
#define DN_BCHAIN_HRP_BTC_TEST_NET  "tb" /**< Bitcoin testnet. */

/* DBchainSignHash */

#define DN_BCHAIN_MAX_SIG_LEN (128) /**< Tamanho máximo de uma assinatura. */

// Type
#define DN_BCHAIN_SIG_DER_ECDSA (1) /**< Assinatura DER, no formato v || DER. SECG!SEC1 strict DER com low S como descrito em BIP62/66, BIP146, EIP2. Tendo 'v' o tamanho de 1 byte. 'v' é o bit de pariadade de 'r' podendo ter os valores 0 ou 1. */
#define DN_BCHAIN_SIG_RAW_ECDSA (2) /**< Assinatura RAW, no formato v || r || s. Tendo 'v' o tamanho de 1 byte e 'r' e 's' cada uma o tamanho de 32 bytes. 'v' é o bit de pariadade de 'r' podendo ter os valores 0 ou 1. */
#define DN_BCHAIN_SIG_BIP340    (3) /**< Assinatura BIP340 - Schnorr 64 bytes. */

// Hash mode
#define DN_BCHAIN_HASH_BTC_H160      (1) /**< Bitcoin H160. */
#define DN_BCHAIN_HASH_RIPEMD160     (2) /**< RIPEMD160. */ 
#define DN_BCHAIN_HASH_SHA256        (3) /**< SHA256. */
#define DN_BCHAIN_HASH_BTC_SHA256_2X (4) /**< Bitcoin SHA256 2x. */ 
#define DN_BCHAIN_HASH_KECCAK256     (5) /**< KECCAK256. */

// Hash length
#define DN_BCHAIN_HASH_BTC_H160_LEN         (20) /**< Tamanho do hash do Bitcoin H160. */
#define DN_BCHAIN_HASH_RIPEMD160_LEN        (20) /**< Tamanho do hash do RIPEMD160. */
#define DN_BCHAIN_HASH_SHA256_LEN           (32) /**< Tamanho do hash do SHA256. */
#define DN_BCHAIN_HASH_BTC_SHA256_2X_LEN    (32) /**< Tamanho do hash do Bitcoin SHA256 2x. */
#define DN_BCHAIN_HASH_KECCAK256_LEN        (32) /**< Tamanho do hash do KECCAK256. */

#ifdef _WIN32
    #pragma pack(pop)
#else
	#pragma pack()
#endif

/* Library exported functions */

#ifdef __cplusplus
  extern "C" {
#endif  /* __cplusplus */

/**
 \addtogroup session

 @{ */

/**
 Inicializa as bibliotecas cliente Dinamo e as deixa prontas para uso. Deve ser chamada antes de qualquer outra função.

 \param[in] dwReserved    \ReservedParamBrief{0}

 \return \APIReturn_brief

 \remark Essa função deverá ser chamada apenas uma vez em cada instância do programa que carrega as bibliotecas. E antes da finalização do programa a função DFinalize() deve ser chamada.
 */
int AAP_API DInitialize(
    DWORD dwReserved
);




/**

Define a lista de balanceamento de carga. Esta configuração é feita em tempo real.

\param[in] dwParam     Especifica como a definição do balanceamento de carga será feita e por conseqüência a estrutura de dados passada no parâmetro \p pvList.
Valor | Signficado
------|-----------
#DN_LB_LIST | Tipo de pvList: LOAD_BALANCE_LIST. Define uma ou mais listas de balanceamento. Todos os campos da estrutura devem ser preenchidos. Passar o array das listas. A quantidade de itens deve ser informado em \p dwListCount até o máximo de #DN_MAX_LB_SETS. A quantidade de estruturas HSM_ADDR definidas por lista deverá ser no máximo #DN_MAX_LB_HSM_COUNT.
\param[in] pvList      Ponteiro para os dados ou estruturas especificados em \p dwParam.
\param[in] dwListCount   Quantidade de listas passadas em \p pvList.
\param[in] dwReserved     \ReservedParamBrief{0}
\return \APIReturn_brief

\remark Ao definir o balanceamento de carga o as sessões antigas serão fechadas fisicamente assim que forem sendo fechadas. As novas sessões serão criadas utilizando as definições da nova lista de balanceamento. Caso a lista definida seja exatamente igual a lista em execução, a lista de balanceamento não será atualizada. <br> Esta função irá habilitar o balanceamento de carga mesmo que a variável de balanceamento de carga não esteja habilitada.
*/
int AAP_API DSetLBList(	DWORD dwParam,
						void *pvList,
						DWORD dwListCount,
						DWORD dwReserved);

/**

Recupera a lista de balanceamento de carga em execução.

\param[in] dwParam     Especifica como a recuperação do balanceamento de carga será feita e por conseqüência a estrutura de dados passada no parâmetro \p pvList.
Valor | Signficado
------|-----------
#DN_LB_LIST | Tipo de pvList: LOAD_BALANCE_LIST. Recebe uma ou mais listas de balanceamento. A quantidade de listas deve ser igual ou maior do que a quantidade de listas em execução. A quantidade de itens deve ser informado em \p dwListCount. A quantidade de estruturas HSM_ADDR definidas por lista deverá ser #DN_MAX_LB_HSM_COUNT.
\param[in] pvList      Ponteiro para os dados ou estruturas especificados em \p dwParam. Pode ser NULL para recuperar a quantidade de listas configuradas.
\param[in,out] pdwListCount   Como entrada deve conter a quantidade de listas passadas em \p pvList. Como saída conterá a quantidade de listas escritas em \p pvList. Caso \p pvList seja NULL este parâmetro receberá a quantidade de listas esperadas.
\param[in] dwReserved     \ReservedParamBrief{0}
\return \APIReturn_brief

*/
int AAP_API DGetLBList(DWORD dwParam,
						void *pvList,
						DWORD *pdwListCount,
						DWORD dwReserved);

/**
 Estabelece uma sessão com o Dinamo e retorna um contexto que deverá ser usado por todas outras funções.

 \param[out] phSession   Ponteiro para o contexto da sessão. Depois do seu uso deverá ser liberado com a função DCloseSession().
 \param[in] dwParam     Especifica como a autenticação da sessão será feita e por conseqüência a estrutura de dados passada no parâmetro \p pbData.
                   Valor | Signficado
                   ------|-----------
				   #SS_USER_PWD | Tipo de pbData: AUTH_PWD Autenticação por usuário e senha. Todos os campos da estrutura devem ser preenchidos.
				   #SS_USR_PWD_EX | Tipo de pbData: AUTH_PWD_EX <br>Autenticação por usuário e senha com OTP/Certificado opcional. Todos os campos da estrutura devem ser preenchidos, apenas os campos de Autenticação forte são opcionais.
				   #SS_ATOKEN | Tipo de pbData: AUTH_ATOKEN <br>Autenticação por <em>Access Tokens</em>. Todos os campos da estrutura devem ser preenchidos. Veja a API DManageAToken() para informações sobre gerência de tokens de sessão (<em>Access Tokens</em>).
                   #SS_ANONYMOUS | Tipo de pbData: AUTH_PWD_EX ou AUTH_PWD <br>Sem autenticação. Apenas os campos szAddr e nPort da estrutura devem ser preenchidos. No caso de AUTH_PWD_EX preencher dwAuthType com SA_AUTH_NONE.
                   #SS_HTTP | Tipo de pbData: AUTH_HTTP <br>Autenticação via HTTP na Dinamo Services. Todos os campos da estrutura devem ser preenchidos.<br>Não implementado.
 \param[in] pbData      Ponteiro para os dados ou estruturas especificados em \p dwParam.
 \param[in] dwDataLen   Tamanho dos dados ou estrutura especificados em \p dwParam.
 \param[in] dwFlags     Altera determinados comportamentos da função, pode ser zero.
                  Valor | Signficado
                   ------|-----------
                   #ENCRYPTED_CONN | Estabelece uma sessão cifrada (TLS v1.0). Os dados trafegarão em texto claro se essa flag não for especificada.
                   #USER_INTERACTIVE | Apresenta um diálogo para que o usuário entre com o seu identificador (ID) e a sua senha ou o caminho do arquivo contendo a sua chave privada e o seu certificado digital. Ainda não suportada.
                   #LB_BYPASS | Ignora as configurações de balanceamento de carga. Estabelecendo sessão no endereço do HSM indicado por intermédio de \p pbData.
                   #CACHE_BYPASS | Ignora as configurações de cache de sessões e abre esta sessão sem passar pelo cache de sessões.
                   #DS_BYPASS | Ignora as configurações de sessão Dinamo Services.

 \return \APIReturn_brief

 \remark O contexto retornado por essa função deverá ser usado em todas outras chamadas subseqüentes ao HSM e liberado através da função DCloseSession() após o seu uso. Uma conexão TCP é estabelecida nessa chamada e encerrada quando o contexto é liberado.\par
 A sessão é estabelecida em texto claro (sem criptografia) se a flag ENCRYPTED_CONN não for especificada, caso contrário, um túnel TLS v1.0 é fechado entre as duas pontas do canal.\par
 O Dinamo apresenta nativamente um sistema de balanceamento de carga e cache de sessões. Caso o balanceamento de carga esteja ativo e seja necessário garantir uma abertura de sessão em endereço IP específico, utilize o flag LB_BYPASS. Com LB_BYPASS a função DOpenSession irá ignorar a lista de endereços do balanceamento de carga. Não é possível desabilitar ou ignorar por intermédio desta ou outra função de API o cache de sessões do equipamento.\par
 Quando a senha de um usuário estiver expirada a função retornará D_ERR_PWD_EXPIRED. Neste caso, será retornado um handle de sessão válido que poderá ser utilizado apenas para a troca de senha do usuário autenticado. Caso a troca de senha seja feita com sucesso a sessão terá as outras funções habilitadas, caso falhe a troca de senha ou tente fazer qualquer outra operação a sessão será desconectada pelo servidor.
 */
int AAP_API DOpenSession(
    HSESSIONCTX * phSession,
    DWORD dwParam,
    BYTE * pbData,
    DWORD dwDataLen,
    DWORD dwFlags
);

/**
 Altera os parâmetros da sessão.

 \param_hSession
 \param[in] dwParam    Especifica o parâmetro da sessão que deve ser configurado e por conseqüência a estrutura de dados passados no parâmetro \p pbData.
          Valor | Signficado
          :-----|:----------
          #SP_SESSION_TIMEOUT | Tipo de \p pbData: DWORD <br>Timeout global da sessão em milissegundos. Este valor de timeout se aplica apenas ao cliente. . <br>Ainda não suportado.
          #SP_SEND_TIMEOUT | Tipo de \p pbData: DWORD <br>Tempo limite em milissegundos para a função send do subsistema de rede.
          #SP_RECV_TIMEOUT | Tipo de \p pbData: DWORD <br>Tempo limite em milissegundos para a função recv do subsistema de rede.
 \param[in] pbData     Ponteiro para os dados ou estruturas especificados em \p dwParam.
 \param[in] dwDataLen  Tamanho dos dados ou estrutura especificados em \p dwParam.
 \param[in] dwFlags    \ReservedParamBrief{0}

 \return \APIReturn_brief
 */
int AAP_API DSetSessionParam(
    HSESSIONCTX hSession,
    DWORD dwParam,
    BYTE * pbData,
    DWORD dwDataLen,
    DWORD dwFlags
);

/**
 Recupera parâmetros da sessão.

 \param_hSession
 \param[in] dwParam Consulte \p dwParam em DSetSessionParam(). Outros valores de \p dwParam, exclusivos de DGetSessionParam:
             Valor | Signficado
             :-----|:----------
              #SP_SESSION_ID | Tipo de \p pbData: DWORD <br>Identificador da sessão no servidor.<br>Ainda não suportado.
			  #SP_SESSION_CIPHER | Tipo de \p pbData: char * <br>Algoritmos negociados na sessão TLS. Tamanho máximo #MAX_CHANNEL_CIPHER_NAME_LEN<br>
              #SP_SESSION_PIX_HTTP_RET | Tipo de \p pbData: long * <br>Código de resposta HTTP da última requisição PIX HTTP (POST, GET...) feita nesta sessão. Esta operação deve ser chamada logo após a chamada da API de requisição PIX. Deve ser chamada utilizando a mesma sessão. Não fazer outras operações entre estas chamadas.
              #SP_SESSION_PIX_HTTP_REQ_DETAILS | Tipo de \p pbData: #PIX_HTTP_REQUEST_DETAILS * <br>Detalhes da última requisição PIX HTTP (POST, GET...) feita nesta sessão. Esta operação deve ser chamada logo após a chamada da API de requisição PIX. Deve ser chamada utilizando a mesma sessão. Não fazer outras operações entre estas chamadas.
 \param[out] pbData     Ponteiro para os dados ou estruturas especificados em \p dwParam. Esse parâmetro pode ser NULL para que seja especificada a quantidade de memória necessária.
 \param[in,out] pdwDataLen  Ponteiro para o tamanho do buffer, em bytes, especificado em \p pbData. Quando a função retorna, esse parâmetro conterá o tamanho dos dados armazenados em \p pbData.
 \param[in] dwFlags    \ReservedParamBrief{0}

  \return \APIReturn_brief
 */
int AAP_API DGetSessionParam(
    HSESSIONCTX hSession,
    DWORD dwParam,
    BYTE* pbData,
    DWORD* pdwDataLen,
    DWORD dwFlags
);

/**
 Finaliza uma sessão com o Dinamo e libera o seu contexto.

 \param[in,out] phSession  Ponteiro para o contexto da sessão. Quando a função retornar esse parâmetro será igual à NULL.
 \param[in] dwFlags     Altera determinados comportamentos da função, pode ser zero.
         Valor | Signficado
         ------|-----------
         #CLOSE_PHYSICALLY | Força o fechamento físico da sessão. Caso a sessão esteja em cache, ela será removida do cache e fechada fisicamente.

 \return \APIReturn_brief

 \remark O contexto da sessão, depois de liberado se torna inválido para uso em qualquer outra função. Caso o contexto seja usado novamente, a função retornará o código de erro D_INVALID_CONTEXT.
 */
int AAP_API DCloseSession(
    HSESSIONCTX * phSession,
    DWORD dwFlags
);

/**

 Finaliza as bibliotecas do cliente Dinamo.

 \return 0 (ZERO)
 \remark Essa função deve ser chamada na finalização do programa apenas uma vez. Depois de sua execução qualquer outra função chamada terá um comportamento indefinido.
 */
int AAP_API DFinalize();

/** @} End of Sessao grouping*/

/**
 \addtogroup management

 @{ */

/**
 Ponteiro para função de callback para listagem de objetos.
 \param  [in] szKeyName    Nome do objeto.
 \param  [in] pParam       Ponteiro para um parâmetro passado para a função DListObjs().
 \param  [in] bFinal       Flag que indica o último registro.

 \return              0
 */
typedef int (AAP_API * funcListKeyCallback)(char *szKeyName, void *pParam, BOOL bFinal);

/**
 Lista os objetos armazenadas no Dinamo, entre chaves e arquivos.
 */
int AAP_API DListObjs(
    HSESSIONCTX hSession,               /**< \hSession_brief */
    funcListKeyCallback fncallback,     /**< [in] Ponteiro para uma função de callback usada para listar os nomes (identificadores) dos objetos. */
    void *pParam                       /**< [in] Ponteiro para um parâmetro qualquer que será repassado à função de callback */

    /** \return \APIReturn_brief */

    /** \remark As funções da API Dinamo não devem ser chamadas de dentro da função de *callback* (parâmetro ListObjsCallback) usando o mesmo contexto (parâmetro hSession) passado para a função DListObjs(). Quando houver necessidade dever se usar um contexto diferente. */

);

/**
 Cria ou restaura o backup dos objetos (chaves, certificados, etc.) gravados internamente no Dinamo.

 \param_hSession
 \param[in] szBackupFile    Caminho do arquivo de backup.
 \param[in] szPin           Senha de proteção do arquivo de backup. Devem ser caracteres ASCII. O tamanho deve estar entre #MIN_BACKUP_PIN_LEN e #MAX_BACKUP_PIN_LEN.
 \param[in] nDirection      [in] Especifica a ação a ser executada.
                               Valor | Significado
                               ------|------------
                               #MAKE_BACKUP | O arquivo de backup será criado, caso exista, será sobrescrito.
                               #MAKE_RESTORE_WITHOUT_NET_CONFIG | Os dados de backup existentes, não incluindo parâmetros de rede, no arquivo indicado por szBackupFile serão restaurados.
                               #MAKE_RESTORE_WITH_NET_CONFIG | Os dados de backup existentes, incluindo parâmetros de rede, no arquivo indicado por szBackupFile serão restaurados.

 \return \APIReturn_brief

 \remark Essa função cria ou recupera uma cópia de segurança (backup) dos objetos armazenados no sistema para ou de um arquivo cifrado. A chave de criptografia e decriptografia é derivada da senha informada pelo usuário. Esta operação de criptografia/decriptografia é independente do modo de armazenamento do objeto no Dinamo (cifrado ou não-cifrado).  A cópia de segurança é sempre cifrada. A senha utilizada na geração da cópia de segurança deverá ser usada na restauração. É possível indicar que os parâmetros de rede (endereço IP, máscara, e gateway) sejam ou não restaurados. Para restaurar arquivos grandes, acima de 2147483647 bytes é necessário que o servidor HSM esteja com a versão mínima 3.9.0.2 ou acima.
 \note Objetos marcados como não exportáveis no Dinamo também serão incluídos na cópia de segurança. Esta operação não é seletiva, ou seja, todos os objetos existentes na área de armazenamento do Dinamo serão copiados.

 */
int AAP_API DBackupData(
    HSESSIONCTX hSession,
    char * szBackupFile,
    char * szPin,
    int nDirection
);

/**
 Cria ou restaura o backup de um objeto específico no HSM.

 \param_hSession
 \param[in] dwOP            Especifica a ação a ser executada.
                            Valor | Significado
                            ------|------------
                            #D_BACKUP_OBJ | Faz o backup do objeto especificado em \p szObjectId e escreve o conteúdo em \p pbData. \p pdwDataLen deverá conter o tamanho do buffer apontado por \p pbData e ao final da chamada receberá o total de bytes copiados para \p pbData. Caso \p pbData seja NULL, \p pdwDataLen receberá o tamanho do buffer \p pbData necessário para acomodar o backup. Pode-se utilizar um buffer maior ou igual a #D_MAX_BACKUP_OBJ_LEN para evitar uma chamada extra a esta função, apenas para recuperar o tamanho do buffer de backup necessário.
                            #D_RESTORE_OBJ | Restaura o backup do objeto. \p szObjectId deverá conter o nome que o objeto restaurado terá dentro do HSM. \p pbData deverá conter o buffer do backup que será restaurado e \p pdwDataLen o tamanho de \p pbData.
 \param[in] szObjectId		Nome do objeto dentro do HSM.
 \param[in] szPin           Senha de proteção do arquivo de backup. Devem ser caracteres ASCII. O tamanho deve estar entre #MIN_BACKUP_PIN_LEN e #MAX_BACKUP_PIN_LEN.
 \param[in,out] pbData		Buffer contento o backup do objeto. Ver opções em \p dwOP para mais detalhes.
 \param[in,out] pdwDataLen  Tamanho do backup. Ver opções em \p dwOP para mais detalhes.
 \param[in] dwReserved    \ReservedParamBrief{0}

 \return \APIReturn_brief

 \remark Essa função cria ou recupera uma cópia de segurança (backup) de um objeto específico (uma chave por exemplo) para ou de um arquivo cifrado. A cópia de segurança é sempre cifrada com duas camadas: primeiro com a chave Server Master Key (SVMK) do HSM e segundo com a chave de criptografia derivada da senha informada pelo usuário. A senha utilizada na geração da cópia de segurança deverá ser usada na restauração.

 Como o objeto saí cifrado pela SVMK, só poderá ser restaurado em HSMs Dinamo inicializados com esta mesma SVMK. Do ponto de vista de segurança o objeto contido no backup continua protegida pela fronteira criptográfica do HSM.

 Linhas diferentes de modelos de HSM Dinamo podem ter métodos diferentes de derivação de SVMK a partir da semente. Os backups gerados em modelos XP e ST são interoperáveis entre si, mas não com backups de modelo Pocket.

 \note O backup pode ser realizado com objetos exportáveis ou não-exportáveis e este estado é preservado na operação de \p restore. Apenas o objeto especificado em \p szObjectId será incluído no backup.

 */
int AAP_API DBackupObject(	HSESSIONCTX hSession,
							DWORD dwOP,
							char *szObjectId,
							char *szPin,
							BYTE *pbData,
							DWORD *pdwDataLen,
							DWORD dwReserved );

/**
 Ponteiro para função de callback para gravar os eventos gerados pelo servidor.
 \param[in] szEvent      Evento do log.
 \param[in] pParam       Ponteiro para um parâmetro passado na função DgetLogEvents.
 \param[in] bFinal       Indica o fim do envio de eventos.
 \return             0
 */
typedef int (AAP_API * funcLogEventCallback)(char *szEvent, void *pParam, BOOL bFinal);

/**
 Recupera os eventos de log gerados pelo servidor.

 \param_hSession
 \param[in] fncallback     Ponteiro para uma função de callback usada para gravar os eventos gerados pelo servidor.
 \param[in] pParam         Ponteiro para um parâmetro qualquer que será repassado à função de callback.

 \return \APIReturn_brief

 \remark Esta opção permite que um programa receba mensagens de log geradas internamente no Dinamo; o programa passa a receber uma cópia de todas as mensagens de log. Há um limite de 03 (três) receptores simultaneamente em modo de recebimento de notificações de eventos, para evitar degradação de desempenho do HSM. As mensagens enviadas continuam sendo gravadas no arquivo interno do servidor. O primeiro valor hexadecimal mostrado na linha de log é um timestamp e o segundo é um ID usado internamente.
 */
int AAP_API DGetLogEvents(
    HSESSIONCTX hSession,
    funcLogEventCallback fncallback,
    void *pParam
);

/**
 Executa operações administrativas no servidor.

 \param_hSession
 \param[in] dwParam    Especifica a operação que será executada e por conseqüência a estrutura ou dados passados no parâmetro \p pbData.
                           Valor | Signficado
                           ------|-----------
                           #AO_SHUTDOWN | Tipo de \p pbData: NULL <br>Desliga o HSM. Neste momento será preciso uma intervenção manual para que o servidor fique disponível novamente, ou seja, será preciso ligar o equipamento e inserir o cartão de operação.<br>Ainda não suportado
                           #AO_RESTART | Tipo de \p pbData: NULL <br>Reinicia o HSM. Neste momento será preciso uma intervenção manual para que o servidor fique disponível novamente, ou seja, inserir o cartão de operação.<br>Ainda não suportado.
                           #AO_KEEPALIVE | Tipo de \p pbData: NULL <br>Executa uma simples troca de mensagens entre o cliente e o servidor a fim de manter a conexão estabelecida.
                           #AO_SET_DATE_TIME | Tipo de \p pbData: struct tm (time.h) <br>Define data e hora do HSM. Deve ser passado o horário GMT (Greenwich Mean Time) padrão (sem fuso horário).
                           #AO_SET_PWD_SEC_POLICY | Tipo de \p pbData: PWD_SEC_POLICY <br>Define os parâmetros da política de segurança do HSM.
                           #AO_GET_PWD_SEC_POLICY | Tipo de \p pbData: PWD_SEC_POLICY <br>Recupera os parâmetros da política de segurança do HSM.
						   #AO_SET_TLS_BUNDLE | Tipo de \p pbData: TLS_BUNDLE_INFO <br>Define a chave e certificado que serão utilizados pelo TLS do HSM.
 \param[in] pbData     Ponteiro para os dados ou estruturas especificados em \p dwParam.
 \param[in] dwDataLen  Tamanho dos dados ou estrutura especificados em \p dwParam.
 \param[in] dwFlags    Deve ser 0 ou algum dos valores abaixo.
                           Valor | Signficado
                           ------|-----------
                           #AO_KEEPALIVE_FLAG_NOISELESS | Tipo de \p dwParam: AO_KEEPALIVE<br> Faz com que a operação de keep alive não gere logs no HSM.
 \return \APIReturn_brief

 \remark A opção #AO_KEEPALIVE executa um teste para indicação de ‘vida’ (heartbeat) do serviço do Dinamo. O resultado positivo a este teste mostra que o HSM está processando corretamente as requisições de clientes e seu estado interno é consistente e íntegro. Pode ser usado por exemplo pelas equipes de monitoração e suporte para indicação de status OK do Dinamo.
 */
int AAP_API DAdmOperation(
    HSESSIONCTX hSession,
    DWORD dwParam,
    BYTE * pbData,
    DWORD dwDataLen,
    DWORD dwFlags
);

/**
Recupera o certificado do HSM utilizado no TLS.

\param[in] szAddress    Endereço do HSM.
\param[in] nPort		Porta de acesso ao HSM. A porta padrão é #DEFAULT_PORT.
\param[in] dwOutFormat    Formato de saída do certificado.
Valor | Signficado
------|-----------
#CERT_OUT_DER | Exporta o certificado do servidor no formato X.509 DER.
#CERT_OUT_DER | Exporta o certificado do servidor no formato X.509 PEM.
\param[in] ppbOutCert     Ponteiro de ponteiro com o certificado no formato especificado em dwOutFormat. Este ponteiro deve ser liberado com DFree.
\param[in] pdwOutCertLen  Tamanho do certificado apontado em \p ppbOutCert.
\param[in] dwFlags    \ReservedParamBrief{0}

\return \APIReturn_brief
*/
int AAP_API DGetHSMTLSCert(char *szAddress,
							int nPort,
							DWORD dwOutFormat,
							BYTE **ppbOutCert,
							DWORD *pdwOutCertLen,
							DWORD dwFlags);

#define DN_NT_MAX_TARGET_LEN (255)
#define DN_NTOOL_PING (1)
#define DN_NTOOL_TRACERT (2)
#define DN_NTOOL_CROSS_CHECK (100)

/**
Executa ferramentas de teste a partir do HSM.

\param_hSession
\param[in] dwOption Opção de operação.     
Valor | Signficado
------|-----------
#DN_NTOOL_PING | Executa uma operação de PING a partir do HSM. \p pvResult conterá uma string.
#DN_NTOOL_TRACERT | Executa uma operação de TRACERT a partir do HSM. \p pvResult conterá uma string.
#DN_NTOOL_CROSS_CHECK | Executa uma operação de cross-check a partir do HSM. \p pvResult conterá um vetor de estruturas #CROSS_CHECK_NODE.
\param[in] szTarget   Endereço de destino da operação que será executada. Tamanho máximo de #DN_NT_MAX_TARGET_LEN.
\param[out] pvResult     Ponteiro de ponteiro que conterá o resultado do comando executado. Este ponteiro deve ser liberado com DFree.
\param[out] pdwResultLen  Tamanho do buffer retornado em \p pvResult.
\param[in] dwFlags    \ReservedParamBrief{0}

\return \APIReturn_brief
*/
int AAP_API DHSMTool(HSESSIONCTX hSession,
                     DWORD dwOption,
                     const char *szTarget,
                     void **pvResult,
                     DWORD *pdwResultLen,
                     DWORD dwFlags);

/**
 Importa um arquivo para dentro do HSM.

 \param_hSession
 \param[in] szFileId       Identificador do novo arquivo dentro do HSM.
 \param[in] pbFile         Buffer contendo os arquivo que será importado.
 \param[in] dwFileSize     Tamanho do arquivo a ser carregado.
 \param[in] dwReserved    \ReservedParamBrief{0}

 \return \APIReturn_brief

 \remark O arquivo gravado é opaco para o HSM e não será cifrado internamente e será sempre um objeto exportável. <br>
 O tamanho máximo por arquivo aceito pelo HSM é de 512kb.<br>
 Os arquivos enviados para o HSM, descritos na tabela abaixo, terão seus tipos detectados automaticamente.<br>
 Tipo | Formato
------|--------
Certificados X.509 | DER
CRL(Certificate Revocation List) ou LCR(Lista de Certificados Revogados) | DER
Cadeias de certificados PKCS#7 | DER
 */
int AAP_API DWriteFileBuffer(HSESSIONCTX hSession,
                             char *szFileId,
                             BYTE *pbFile,
                             DWORD dwFileSize,
                             DWORD dwReserved);

/**
 Ponteiro para função de callback para ler o arquivo a ser carregado para o HSM.

 \param[in] pbData      Buffer contendo os dados lidos.
 \param[in] pdwDataLen  Ponteiro para um DWORD contendo o número de bytes lidos do arquivo
 \param[in] pParam      Ponteiro para um parâmetro passado para a função DWriteFile().
 \param[in] pbFinal     Flag que indica o fim do arquivo.

 \return    0
 */
typedef int (AAP_API * funcReadLocalFileCallback)(BYTE *pbData, DWORD * pdwDataLen, void *pParam, BOOL *pbFinal);

/**
 Importa um arquivo para dentro do HSM.

 \param_hSession
 \param[in] szFileId       Identificador do novo arquivo dentro do HSM.
 \param[in] dwFileSize     Tamanho do arquivo a ser carregado.
 \param[in] fncallback     Ponteiro para uma função de callback usada para ler o arquivo a ser carregado.
 \param[in] pParam         Ponteiro para um parâmetro qualquer que será repassado à função de callback.

 \return \APIReturn_brief

 \remark O arquivo gravado é opaco para o HSM e não será cifrado internamente e será sempre um objeto exportável. <br>
 O tamanho máximo por arquivo aceito pelo HSM é de 512kb.<br>
 Os arquivos enviados para o HSM, descritos na tabela abaixo, terão seus tipos detectados automaticamente.<br>
 Tipo | Formato
------|--------
Certificados X.509 | DER
CRL(Certificate Revocation List) ou LCR(Lista de Certificados Revogados) | DER
Cadeias de certificados PKCS#7 | DER

 */
int AAP_API DWriteFile(
    HSESSIONCTX hSession,
    char * szFileId,
    DWORD dwFileSize,
    funcReadLocalFileCallback fncallback,
    void *pParam
);

/**
 Ponteiro para função de callback para gravar localmente o arquivo recuperado do HSM.

 \param[in] pbData      Buffer com os dados que serão gravados no arquivo.
 \param[in] dwDataLen   Número de bytes que serão gravados.
 \param[in] pParam      Ponteiro para um parâmetro passado para a função DWriteFile().
 \param[in] bFinal      Flag que indica o fim do arquivo.

 \return             0
 */
typedef int (AAP_API * funcWriteLocalFileCallback)(BYTE *pbData, DWORD dwDataLen, void *pParam, BOOL bFinal);

/**
 Exporta uma arquivo do HSM.

 \param_hSession
 \param[in] szFileId       Identificador do arquivo dentro do HSM.
 \param[in] fncallback     Ponteiro para uma função de callback usada para gravar o arquivo recuperado.
 \param[in] pParam         Ponteiro para um parâmetro qualquer que será repassado à função de callback.

 \return \APIReturn_brief

 \remark Esta API não deve ser usada para exportação de chaves.
*/
int AAP_API DReadFile(
    HSESSIONCTX hSession,
    char * szFileId,
    funcWriteLocalFileCallback fncallback,
    void *pParam
);

/**
 Exporta uma arquivo do HSM para um buffer.

 \param_hSession
 \param[in] szFileId       Identificador do arquivo dentro do HSM.
 \param[out] ppbData       Ponteiro que receberá os dados do arquivo lido. A memória é alocada internamente. A memória deve liberada com DFree().
 \param[out] pdwDataLen    Recebe o tamanho do buffer alocado em \p ppbData.
 \param[in] dwReserved     \ReservedParamBrief{0}

 \return \APIReturn_brief

 \remark Esta API não deve ser usada para exportação de chaves.
*/
int AAP_API DReadFileBuffer(HSESSIONCTX hSession,
                            const char *szFileId,
                            BYTE **ppbData,
                            DWORD *pdwDataLen,
                            DWORD dwReserved);

/**
 Remove um objeto armazenado no Dinamo, seja ele uma chave ou um arquivo.

 \param_hSession
 \param[in] szObjId        Identificador do objeto dentro do HSM. Este identificador não deve conter espaços ou caracteres especiais. Caracteres maiúsculos e minúsculos são diferenciados (case-sensitive).

 \return \APIReturn_brief
 */
int AAP_API DRemoveObj(
    HSESSIONCTX hSession,
    char *szObjId);

/**
 Recupera o conteúdo do log do servidor.

 \param_hSession
 \param[in] dwStart        Posição inicial, em bytes, do log a ser recuperado. Para receber todo o conteúdo do log indique #GET_LOG_START_FULL.
 \param[in] dwOffset       Quantidade, em bytes, a ser recuperada a partir da posição inicial indicada por \p dwStart. Para receber todo o conteúdo do log indique #GET_LOG_END_FULL .
 \param [out] pdwLogSize    Ponteiro para DWORD que irá conter a quantidade, em bytes, do log recuperado.
 \param [out] ppbLog        Ponteiro para ponteiro que irá conter o log recuperado do servidor. A alocação de memória é feita internamente pela biblioteca. A aplicação chamadora é responsável por liberar a memória alocada. Consulte a função DFree().

 \return \APIReturn_brief

 \see DGetStatLogSize(), DTruncateLog()
 */
int AAP_API DGetStatLog (
    HSESSIONCTX hSession,
    DWORD dwStart,
    DWORD dwOffset,
    DWORD *pdwLogSize,
    BYTE **ppbLog
);

/**
 Permite apagar o conteúdo do log do servidor.

 \param_hSession

 \return \APIReturn_brief

 \see DGetStatLogSize(), DGetStatLog()
 */
int AAP_API DTruncateLog (
    HSESSIONCTX hSession
);

/**
 Busca, utilizando protocolo SLP via multicast, os HSMs disponíveis na rede.

 \param[in] dwServiceType  Define o tipo de serviço do HSM que será procurado.
                           Valor | Signficado
                           ------|-----------
                           #DN_FIND_SRVC_TYPE_IP | Lista todos os serviços tipo IP encontrados. Lista todas as interfaces IP disponíveis. O mesmo HSM pode ser listado mais de uma vez com IPs diferentes. O valor de \p dwFilter deve ser #DN_FIND_FILTER_TYPE_ALL.
                           #DN_FIND_SRVC_TYPE_AAP | Lista todos os serviços tipo AAP encontrados. Lista todos os HSMs que estejam com o serviço executando.
                           #DN_FIND_SRVC_TYPE_ALL | Lista todos os tipos de serviço.
 \param[in] dwFilter	  Define o tipo de filtro a ser utilizado na busca.
                           Valor | Signficado
                           ------|-----------
                           #DN_FIND_FILTER_TYPE_POCKET | Lista todos os HSMs Pocket encontrados.
                           #DN_FIND_FILTER_TYPE_HSM | Lista todos os HSM DINAMO ST ou XP encontrados.
                           #DN_FIND_FILTER_TYPE_ALL | Lista todos os HSM DINAMO ST, XP ou Pocket encontrados.
 \param [out] ppvOutputData       Ponteiro de ponteiro, do tipo #SLP_SRVR_INFO, que irá conter a lista de HSMs encontrados. A alocação de memória é feita internamente pela biblioteca. A aplicação chamadora é responsável por liberar a memória alocada. Consulte a função DFree().
 \param [out] pdwOutputDataLen    Ponteiro para DWORD que irá conter a quantidade de estruturas (descritas em \p dwOutputType) retornadas em \p ppvOutputData.
 \param[in] dwFlags    \ReservedParamBrief{0}

 \return \APIReturn_brief

 \remark A busca é feita utilizando protocolo SLP (Service Location Protocol) via multicast. Todos os HSMs que se encontrarem acessíveis e com o serviço executando poderão aparecer nesta lista.

 */
int AAP_API DFindHSM(	DWORD dwServiceType,
						DWORD dwFilter,
						void **ppvOutputData,
						DWORD *pdwOutputDataLen,
						DWORD dwFlags );

/**
 Ponteiro para função de callback para listagem de tokens de sessão em DManageAToken().
 \param  [in] pvToken	   Ponteiro que receberá uma estrutura DN_A_TOKEN_FULL que conterá os dados do token de sessão.
 \param  [in] pParam       Ponteiro para um parâmetro passado para a função DManageAToken().
 \param  [in] bFinal       Flag que indica o último registro.

 \return              0
 */
typedef int (AAP_API * funcListAKeysCallback)(void *pvToken, void *pParam, BOOL bFinal);


/**
 Gerencia tokens de sessão (<em>Access Tokens</em>) do próprio usuário.

 \note No projeto da aplicação leve em conta o fato de os <em>Access Tokens</em> serem \b voláteis, conforme detalhado abaixo.

 Sobre autenticação usando tokens de sessão consulte a função DOpenSession() com a opção #SS_ATOKEN.

 \param_hSession
 \param[in] bOP  Especifica a operação que será executada.
                           Valor | Signficado
                           ------|-----------
                           #DN_A_TOKEN_OP_ISSUE | Emite um token de sessão. Preencher o parâmetro \p qwExpiration de entrada em \p pstATokenFull, que no retorno da API receberá o token emitido. Passar NULL em \p fnCallBack e \p pvCallbackParam.
                           #DN_A_TOKEN_OP_REVOKE | Revoga um token de sessão, caso ele exista. Preencher o parâmetro \p Key de entrada em \p pstATokenFull. Passar NULL em \p fnCallBack e \p pvCallbackParam.
                           #DN_A_TOKEN_OP_LIST | Lista todos tokens ativos deste usuário. Deve ser passado a função de callback em \p fnCallBack. Passar NULL em \p pstATokenFull;
 \param[in,out] pstATokenFull    Ponteiro para uma estrutura do tipo #DN_A_TOKEN_FULL. Ver opção de \p bOP para instruções de preenchimento da estrutura.
 \param [in] fnCallBack       Ponteiro para a função de callback do tipo #funcListAKeysCallback. Pode ser NULL. Ver opção de \p bOP para instruções de preenchimento da estrutura.
 \param [in] pvCallbackParam    Ponteiro para um parâmetro qualquer que será repassado à função de callback. Pode ser NULL.
 \param[in] dwParam    \ReservedParamBrief{0}

 \return \APIReturn_brief

 \remark

 Os <em>Access Tokens</em> são mantidos em <b>memória volátil</b>, e desta maneira são apagados quando o HSM é reiniciado. Apesar de serem voláteis, os <em>Access Tokens</em> são replicados entre HSMs.

 A limpeza de <em>Access Tokens</em> expirados acontece em 2 momentos:
  - quando um usuário que tem um <em>Access Tokens</em> expirado faz uma tentativa de login utilizando <em>Access Tokens</em>. Limpa apenas os \b próprios <em>Access Tokens</em>.
  - utilizando a função DManageATokenCache(). Limpa \b todos os <em>Access Tokens</em> expirados do HSM.

 O limite máximo de <em>Access Tokens</em> emitidos por HSM pode ser visto na tabela abaixo.

Modelo | Limite máximo
------|-----------
Pocket | 1024
XP | 1 Milhão
ST | 1 Milhão

 Esta operação está disponível à partir da versão 3.17 do firmware do HSM. A implementação de <em>Access Tokens</em> anterior à versão 3.17  do firmware é legada.

 As aplicações, que utilizam esta funcionalidade, deverão atualizar o cliente do HSM para a versão 3.2.18 ou superior, juntamente com o firmware do HSM para a versão 3.17 ou superior.

 Não há compatibilidade entre versões novas e antigas de cliente e firmware do HSM.

 */
int AAP_API DManageAToken(	HSESSIONCTX hSession,
							BYTE bOP,
							DN_A_TOKEN_FULL *pstATokenFull,
							funcListAKeysCallback fnCallBack,
							void *pvCallbackParam,
							DWORD dwParam);

#define DN_ATOKEN_CACHE_GET_COUNT (0)
#define DN_ATOKEN_CACHE_GC        (1)

/**
 Gerencia o cache dos tokens de sessão (<em>Access Tokens</em>) de todo HSM. Esta funcionalidade é
 indicada para o controle granular de autenticação de aplicações, onde a emissão de tokens é
 gerenciada pelo security officer.

 Sobre autenticação usando tokens de sessão consulte a função DOpenSession() com a opção #SS_ATOKEN.
 A emissão de <em>Access Tokens</em> é feita utilizando a função DManageAToken().

 \param_hSession
 \param[in] dwOP  Especifica a operação que será executada.
						   Valor | Signficado
						   ------|-----------
						   #DN_ATOKEN_CACHE_GET_COUNT | Recupera a quantidade de tokens de sessão de todo HSM. Passar em \p pOutData um DWORD que receberá a quantidade total de tokens de sessão do HSM.
						   #DN_ATOKEN_CACHE_GC | Executa o Garbage Collector de tokens de sessão do HSM. Esta opção faz a limpeza de todos os Access Tokens do HSM que não forem mais válidos. Passar NULL em \p pOutData.
 \param[out] pOutData		Dados de saída. Ver opções de uso em \p dwOP.
 \param[in] dwParam    \ReservedParamBrief{0}

 \return \APIReturn_brief

 \remark Esta operação está disponível à partir da versão 3.17 do firmware do HSM e a partir da versão 3.2.18 do cliente do HSM. <br>
 A opção DN_ATOKEN_CACHE_GC deve ser chamada periodicamente pela aplicação para manter os níveis do cache de Access Tokens sob controle. 
 O horário de execução do GC deve ser programada levando em conta os momentos de maiores cargas de trabalho do HSM.<br>

 */

int AAP_API DManageATokenCache(HSESSIONCTX hSession,
							   DWORD dwOP,
							   void *pOutData,
							   DWORD dwParam);

/**
 Associa um HSM à uma conta Dinamo Services.

 \param_hSession
 \param[in] szBindKey Chave de vínculo. Gerada no site da Dinamo Services.
 \param[in] dwReserved \ReservedParamBrief{0}
 \return \APIReturn_brief
 */
int AAP_API DDSBindHSM(HSESSIONCTX hSession,
                       const char *szBindKey,
                       DWORD dwReserved);
/**
 Desassocia um HSM de uma conta Dinamo Services.

 \param_hSession
 \param[in] dwReserved \ReservedParamBrief{0}
 \return \APIReturn_brief
 */
int AAP_API DDSUnbindHSM(HSESSIONCTX hSession,
                         DWORD dwReserved);

#define DN_LB_LIST	(1)

        int AAP_API DSetLBList(DWORD dwParam,
                               void *pvList,
                               DWORD dwListCount,
                               DWORD dwReserved);

int AAP_API DGetLBList(DWORD dwParam,
						void *pvList,
						DWORD *pdwListCount,
						DWORD dwReserved);

/* Error codes */

/**
 \deprecated Esta API está descontinuada, utilizar DGetReturnCodeString().
 */
int AAP_API DGetErrorString(int nErrorValue,
                            char *szErrorCode,
                            char *szErrorDesc);

/**
 Enumeração de tipo de mensagens de códigos de retorno.
*/
typedef enum RetCodeMsgType
{
    CODE_MSG = 1, /**< Retorna o texto do código de retorno. */
    DESC_MSG      /**< Retorna a descrição do código de retorno. */
} RetCodeMsgType;

/**

Recupera a descrição de um código de retorno das APIs DINAMO.

\param[in] nErrorValue     Código de retorno.
\param[in] eErrorType      Tipo da string de retorno.
Valor | Signficado
------|-----------
#CODE_MSG | Retorna o texto do código de retorno.
#DESC_MSG | Retorna a descrição do código de retorno.

\return Retorna a string de acordo com o definido em \p eErrorType.
*/
const char *AAP_API DGetReturnCodeString(int nErrorValue,
                                         RetCodeMsgType eErrorType);

/** @} End of Management grouping */

int DIPFilterOperation(    HSESSIONCTX hSession,
                        BYTE    bOP,
                        char *szUser,
                        char *szIP,
                        int (AAP_API * ListIpFilterCallback)( void *pInData, DWORD dwInDataLen, void *pParam, BOOL bFinal),
                        void *pParam,
                        DWORD *pdwStatus,
                        DWORD dwReserved );

int AAP_API DRenameObj(    HSESSIONCTX hSession,
                        char *szOldObjName,
                        char *szNewObjName,
                        DWORD dwFlags );

int AAP_API DUPackPush ( HSESSIONCTX hSession, DWORD dwPackSize,
                        BYTE *pbPack );

int AAP_API DUPackInfo ( DWORD dwPackSize, BYTE *pbPack,
                        DWORD *pdwUPackVersion, BYTE **ppbUPackDescr,
                        BYTE **ppbUPackSignature );

int AAP_API DGetObjInfo( const HSESSIONCTX hSession, const char *szObjId,
                            const int nAlgId, const BYTE *pbData,
                            DWORD *pdwDataLen);

int AAP_API DGenerateMapObj( const HSESSIONCTX hSession, const char *szMapId,
                                const char *szObj1Id, const int nObj1AlgId,
                                const char *szObj2Id, const int nObj2AlgId);

int AAP_API DRemoveMapObj( const HSESSIONCTX hSession, const char *szMapObjId );

int AAP_API DListUserSessions(    HSESSIONCTX hSession,
                                int (AAP_API * ListUserSessionsCallback)( DWORD dwStartTime, char *szInfo, void *pParam, BOOL bFinal),
                                void *pParam);

int AAP_API DListObjsFilter(    HSESSIONCTX hSession,
                                DWORD    dwFilterType,
                                void *pvFilter,
                                int (AAP_API * ListObjCallback)(void *pvIN, void *pParam, BOOL bFinal),
                                void *pParam );

int AAP_API DListLoadedModules(HSESSIONCTX hSession,
                            int (AAP_API * ListLoadedModulesCallback)(char *szModuleInfo,
                                                            void *pParam,
                                                            BOOL bFinal),
                             void *pParam);

/**
 \addtogroup users
 @{ */

/**
 Cria um usuário no HSM de acordo com as informações indicadas.

 \param_hSession
 \param[in] userInfo       Estrutura contendo informações para a criação do usuário. Para mais detalhes, veja as observações.

 \return \APIReturn_brief

 \remarks A máscara de autorização do usuário, contida na estrutura USER_INFO, deverá ser montada a partir da concatenação dos valores abaixo:
 Valor | Significado
 :-----|:-----------
 #ACL_NOP | Usuário apenas com autorizações ordinárias.
 #ACL_OBJ_CREATE | Permissão para criar objetos. A permissão de leitura (#ACL_OBJ_READ) é atribuída implicitamente.
 #ACL_OBJ_DEL | Permissão para remover objetos. A permissão de leitura (#ACL_OBJ_READ) é atribuída implicitamente.
 #ACL_OBJ_READ | Permissão para ler o conteúdo de objetos.
 #ACL_OBJ_UPDATE<br> #ACL_OBJ_WRITE  | Permissão para atualizar atributos dos objetos.<br>#ACL_OBJ_UPDATE = #ACL_OBJ_WRITE
 #ACL_USR_CREATE<br> #ACL_USR_DELETE | Permissão para criar e remover usuários.<br>#ACL_USR_CREATE = #ACL_USR_DELETE
 #ACL_USR_REMOTE_LOG | Permissão para receber notificações de log remota.
 #ACL_USR_LIST | Permissão para listar usuários.
 #ACL_SYS_OPERATOR | Permissão para operar como o usuário ‘master’.
 #ACL_SYS_BACKUP<br> #ACL_SYS_RESTORE | Permissão para criar e restaurar cópias de segurança dos dados do HSM.<br>#ACL_SYS_BACKUP = #ACL_SYS_RESTORE
 #ACL_SYS_UDATE_HSM | Permissão para atualizar o firmware.

 */
int AAP_API DCreateUser(
    HSESSIONCTX hSession,
    struct USER_INFO userInfo
);

/**
 Remove um usuário do HSM.

 \param_hSession
 \param[in] szUserId       Identificador do usuário dentro do HSM. Este identificador não deve conter espaços ou caracteres especiais. Caracteres maiúsculos e minúsculos são diferenciados (case-sensitive).

 \return \APIReturn_brief

 \remarks A remoção dos usuários causa também a remoção de todos os objetos que são de sua posse, o que inclui chaves e arquivos.

 \attention Esta função deve ser usada com cautela, já que todos os objetos de posse do usuário removido também serão excluídos permanentemente do HSM. É recomendável criar uma cópia de segurança antes de executar essa função.
 */
int AAP_API DRemoveUser(
    HSESSIONCTX hSession,
    char * szUserId
);

/**
 Altera configurações dos usuários do Dinamo.

 \param_hSession
 \param[in] dwParam        Especifica o parâmetro da sessão que deve ser configurado e por conseqüência a estrutura de dados passados no parâmetro \p pbData.
                            Valor | Significado
                               :-----|:-----------
                               #UP_USER_NAME | Tipo de \p pbData: char *<br>Nome do usuário associado ao identificador corrente. \p pbData deverá ser um ponteiro para uma string que conterá o nome do usuário.<br>Ainda não suportado.
                               #UP_AUTH_MASK | Tipo de \p pbData: #USER_INFO *<br>Máscara de bits contendo as autorizações do usuário corrente. Veja API DCreateUser().
                               #UP_ACCESS_TYPE | Tipo de \p pbData: DWORD <br>Tipo de acesso permitido para o usuário corrente.<br>Ainda não suportado.
                               #UP_PASSWORD | Tipo de pbDada: char * <br>Altera a senha do usuário corrente. \p pbData deve ser um ponteiro para uma string que conterá a nova senha do usuário.
                               #UP_CERTIFICATE | Tipo de \p pbData: #USER_INFO_CERT *<br> A estrutura poderá ser preenchida com um certificado X.509 v3 codificado em DER ou PEM no caso de associado ao usuário corrente.<br> Para desassociação de token não é necessário preeencher os campos de certificado na estrutura #USER_INFO_CERT.
							   #UP_BLOCK_USR | Tipo de pbDada: char * <br>Bloqueia o usuário especificado em pbData. \p pbData deve apontar para uma string contendo o usuário que deverá ser bloqueado.
							   #UP_UNBLOCK_USR | Tipo de pbDada: char * <br>Desbloqueia o usuário especificado em pbData. \p pbData deve apontar para uma string contendo o usuário que deverá ser desbloqueado.
 \param[in] pbData         Ponteiro para os dados ou estruturas especificados em \p dwParam.
 \param[in] dwDataLen      Tamanho dos dados ou estrutura especificados em \p dwParam.
 \param[in] dwFlags        \ReservedParamBrief{0}

 \return \APIReturn_brief

 \remarks Quando \p dwParam é igual a UP_PASSWORD a nova senha do usuário passa a valer assim que a função retorna, dessa maneira, todas autenticações subseqüentes devem ser feitas com o novo valor.<br>A máscara de autorização do usuário deverá ser montada a partir da concatenação dos valores da tabela descrita em DCreateUser().
 */
int AAP_API DSetUserParam(
    HSESSIONCTX hSession,
    DWORD dwParam,
    BYTE * pbData,
    DWORD dwDataLen,
    DWORD dwFlags
);

/**
 Recupera as configurações dos usuários do Dinamo.

 \param_hSession
 \param[in] dwParam        Consulte \p dwParam em DSetUserParam(). A tabela abaixo descreve as flags específicas para esta API.
	 Valor | Significado
	 :-----|:-----------
	 #UP_BLOCK_USR | Tipo de \p pbData: #USER_BLOCK<br>Estrutura que receberá os dados de bloqueio do usuário. Preencher o membro szUserId da estrutura para entrada. O membro de nBlocked será preenchido pela API.
	 #UP_INVALID_LOGIN_ATTEMPTS | Tipo de \p pbData: #USER_BLOCK<br>Estrutura que receberá os dados de tentativas de login inválido do usuário. Preencher o membro szUserId da estrutura para entrada. O membro de dwAttempts será preenchido pela API. Este valor será retornado quando a opção de tentativas de login inválido for definida na política de senhas.
	 #UP_USR_PA_STATE | Tipo de \p pbData: #USER_PA_INFO<br>Estrutura que receberá os dados de autorização de partição. Preencher o membro szUserId da estrutura para entrada. Os outros membros serão preenchidos pela API.

 \param[in] pbData         Ponteiro para os dados ou estruturas especificados em \p dwParam.
 \param[in] pdwDataLen     Tamanho dos dados ou estrutura especificados em \p dwParam.
 \param[in] dwFlags        \ReservedParamBrief{0}

 \return \APIReturn_brief
 */
int AAP_API DGetUserParam(
    HSESSIONCTX hSession,
    DWORD dwParam,
    BYTE * pbData,
    DWORD * pdwDataLen,
    DWORD dwFlags
);

/**
 Ponteiro para função de callback para listagem de usuários.

 \param  [in] szKeyName    Nome do usuário.
 \param  [in] pParam       Ponteiro para um parâmetro passado para a função DListUsers().
 \param  [in] bFinal       Flag que indica o último registro.

 \return              0
 */
typedef int (AAP_API * funcListUsersCallback)(char *szUserName, void *pParam, BOOL bFinal);

/**
 Lista os usuários do Dinamo.

 \param_hSession
 \param[in] fncallback     Ponteiro para uma função de callback usada para listar os nomes (identificadores) dos usuários.
 \param[in] pParam         Ponteiro para um parâmetro qualquer que será repassado à função de callback

 \return \APIReturn_brief
 */
int AAP_API DListUsers(
    HSESSIONCTX hSession,
    funcListUsersCallback fncallback,
    void *pParam
);

//OATH SA



/**
Associa um token OTP(de tempo ou evento) padrão OATH a um usuário. Após esta chamada o usuário fará autenticação apenas com usuário, senha e OTP.

\param_hSession
\param[in] dwParam                 A seguinte tabela é aceita:
Valor|Significado
:----|:----------
#AT_OATH_TOKEN | Associa um token HOTP(de evento) ao usuário. Passar #OATH_SA_v1 em \a pbData.
#AT_OATH_TOKEN_TOTP | Associa um token TOTP(de tempo) ao usuário. Passar #OATH_SA_v2 em \a pbData.
\param[in] szUserId				   Nome do usuário que terá o token associado.
\param[in] pbData				   Dados contendo os parâmetros do token. Deve ser especificado de acordo com o definido no parâmetro \a dwParam.
\param[in] dwDataLen               Tamanho, em bytes, dos dados passados em \a pbData.
\return \APIReturn_brief

 \remark A partir da versão 4.0.2 do firmware o tamanho da janela de look-ahead de autenticação é 
 definida com o padrão de de 10 intervalos para mais ou para menos. No caso de tokens HOTP os 
 intervalos serão contados por quantidade de eventos, no caso dos tokens TOTP serão contados 
 por quantidade de time-steps.
*/
int AAP_API DAssignToken(const HSESSIONCTX hSession,
						const char * szUserId,
						const DWORD dwParam,
						BYTE * pbData,
						const DWORD dwDataLen);

/**
Desassocia a autenticação com OTP de um usuário. Após esta chamada o usuário fará autenticação apenas com usuário e senha.

\param_hSession
\param[in] dwParam                 A seguinte tabela é aceita:
Valor|Significado
:----|:----------
#AT_OATH_TOKEN | Desassocia um token HOTP(de evento) ou TOTP(de tempo) do usuário.
\param[in] szUserId				   Nome do usuário que terá o seu token desassociado.

\return \APIReturn_brief
*/
int AAP_API DUnassignToken(const HSESSIONCTX hSession,
							const DWORD dwParam,
							const char *szUserId);



/**
Re-sincroniza um token de eventos, padrão OATH, associado a um usuário do HSM.
Recebe dois OTPs consecutivos, gerados pelo token, para sincronizar o estado do token no usuário do HSM.

\param_hSession
\param[in] szUser				   Nome do usuário que terá o seu token re-sincronizado.
\param[in] szOTP1                  Primeiro OTP, para sincronização, gerado pelo token.
\param[in] szOTP2                  Segundo OTP, para sincronização, gerado pelo token.
\param[in] dwParam                 \ReservedParamBrief{0}

\return \APIReturn_brief
*/
int AAP_API DOATHResync(const HSESSIONCTX hSession,
						char *szUser,
						char *szOTP1,
						char *szOTP2,
						DWORD dwParam);


/** @} End of Users grouping */



/* PKCS#11 */

int AAP_API DGeneratePkcs11Map(HSESSIONCTX hSession, char *szP11MapId,
                                BYTE bTemporary, DWORD dwBlobType,
                                DWORD dwFlags, BYTE * pbData,
                                DWORD dwDataLen);

int AAP_API DUpdatePkcs11Map(HSESSIONCTX hSession, char *szP11MapId,
                                DWORD dwBlobType, DWORD dwFlags,
                                DWORD dwUpdateMask, BYTE * pbData,
                                DWORD dwDataLen);

int AAP_API DGetPkcs11Map(HSESSIONCTX hSession, char *szP11MapId,
                          DWORD dwBlobType, DWORD dwFlags,
                          BYTE ** ppbData, DWORD * pdwDataLen);


int AAP_API DListPkcs11Maps(HSESSIONCTX hSession,
                            int (AAP_API * ListKeyCallback)(char *szKeyName,
                                                            void *pParam,
                                                            BOOL bFinal),
                            void *pParam);


#define MNG_OBJ_META_A_KEY_TYPE					(1)
#define MNG_OBJ_META_A_CLASS					(2)
#define MNG_OBJ_META_A_EXTRACTABLE				(3)
#define MNG_OBJ_META_A_SENSITIVE				(4)
#define MNG_OBJ_META_A_N_EXTRACTABLE			(5)
#define MNG_OBJ_META_A_LOCAL					(6)
#define MNG_OBJ_META_A_CERT_TYPE				(7)
#define MNG_OBJ_META_A_RSA_MODULUS				(8)
#define MNG_OBJ_META_A_RSA_PUB_EXP				(9)
#define MNG_OBJ_META_A_PUB_KEY_INFO				(10)
#define MNG_OBJ_META_A_EC_PARAMS				(11)
#define MNG_OBJ_META_A_SUBJECT					(12)
#define MNG_OBJ_META_A_ISSUER					(13)
#define MNG_OBJ_META_A_SN						(14)
#define MNG_OBJ_META_A_TOKEN					(15)
#define MNG_OBJ_META_A_MODIFIABLE				(16)
#define MNG_OBJ_META_A_DERIVE					(17)
#define MNG_OBJ_META_A_WRAP						(18)
#define MNG_OBJ_META_A_UNWRAP					(19)
#define MNG_OBJ_META_A_SIGN						(20)
#define MNG_OBJ_META_A_VERIFY					(21)
#define MNG_OBJ_META_A_ENCRYPT					(22)
#define MNG_OBJ_META_A_DECRYPT					(23)
#define MNG_OBJ_META_A_OBJ_ID					(24)
#define MNG_OBJ_META_A_MODULUS_BITS				(25)
#define MNG_OBJ_META_A_PRIVATE					(26)
#define MNG_OBJ_META_A_LABEL					(27)
#define MNG_OBJ_META_A_ID						(28)
#define MNG_OBJ_META_A_APPLICATION				(29)
#define MNG_OBJ_META_A_TRUSTED					(30)
#define MNG_OBJ_META_A_JMIDP_SEC_DOMAIN			(31)
#define MNG_OBJ_META_A_CERT_CATEGORY			(32)
#define MNG_OBJ_META_A_KEY_GEN_MECHANISM		(33)
#define MNG_OBJ_META_A_WRAP_WITH_TRUSTED		(34)
#define MNG_OBJ_META_A_HSM_ASSOCIATE			(35)
#define MNG_OBJ_META_A_SIGN_RECOVER				(36)
#define MNG_OBJ_META_A_VERIFY_RECOVER			(37)

#define MNG_OBJ_META_A_HSM_OBJ_VERSION			(502)
#define MNG_OBJ_META_A_HSM_OBJ_TYPE				(503)
#define MNG_OBJ_META_A_HSM_OBJ_ATTR				(504)
#define MNG_OBJ_META_A_HSM_OBJ_LEN				(505)
#define MNG_OBJ_META_A_HSM_OBJ_ID				(506)
#define MNG_OBJ_META_A_HSM_OBJ_PVALUE			(507)

#define MNG_OBJ_META_READ_ONLY_ATTR(a) ((MNG_OBJ_META_A_KEY_TYPE == (a)) ||        \
                                        (MNG_OBJ_META_A_CLASS == (a)) ||           \
                                        (MNG_OBJ_META_A_EXTRACTABLE == (a)) ||     \
                                        (MNG_OBJ_META_A_SENSITIVE == (a)) ||       \
                                        (MNG_OBJ_META_A_N_EXTRACTABLE == (a)) ||   \
                                        (MNG_OBJ_META_A_LOCAL == (a)) ||           \
                                        (MNG_OBJ_META_A_CERT_TYPE == (a)) ||       \
                                        (MNG_OBJ_META_A_RSA_MODULUS == (a)) ||     \
                                        (MNG_OBJ_META_A_RSA_PUB_EXP == (a)) ||     \
                                        (MNG_OBJ_META_A_PUB_KEY_INFO == (a)) ||    \
                                        (MNG_OBJ_META_A_EC_PARAMS == (a)) ||       \
                                        (MNG_OBJ_META_A_ISSUER == (a)) ||          \
                                        (MNG_OBJ_META_A_SN == (a)) ||              \
                                        (MNG_OBJ_META_A_TOKEN == (a)) ||           \
                                        (MNG_OBJ_META_A_MODIFIABLE == (a)) ||      \
                                        (MNG_OBJ_META_A_MODULUS_BITS == (a)) ||    \
                                        (MNG_OBJ_META_A_PRIVATE == (a)) ||         \
                                        (MNG_OBJ_META_A_HSM_OBJ_VERSION == (a)) || \
                                        (MNG_OBJ_META_A_HSM_OBJ_TYPE == (a)) ||    \
                                        (MNG_OBJ_META_A_HSM_OBJ_ATTR == (a)) ||    \
                                        (MNG_OBJ_META_A_HSM_OBJ_LEN == (a)) ||     \
                                        (MNG_OBJ_META_A_HSM_OBJ_ID == (a)) ||      \
                                        (MNG_OBJ_META_A_HSM_OBJ_PVALUE == (a)) ||  \
                                        (MNG_OBJ_META_A_DERIVE == (a)) ||          \
                                        (MNG_OBJ_META_A_WRAP == (a)) ||            \
                                        (MNG_OBJ_META_A_UNWRAP == (a)) ||          \
                                        (MNG_OBJ_META_A_SIGN == (a)) ||            \
                                        (MNG_OBJ_META_A_VERIFY == (a)) ||          \
                                        (MNG_OBJ_META_A_ENCRYPT == (a)) ||         \
                                        (MNG_OBJ_META_A_DECRYPT == (a)) ||         \
                                        (MNG_OBJ_META_A_SIGN_RECOVER == (a)) ||    \
                                        (MNG_OBJ_META_A_VERIFY_RECOVER == (a)))

/* DManageObjMetadata */

#define MNG_OBJ_META_GET     (1)
#define MNG_OBJ_META_UPDATE  (3)
#define MNG_OBJ_META_DEL     (4)


int AAP_API DCreateObjMetadata(	HOBJMETACTX *phOutMeta,
									DWORD dwParam );

int AAP_API DDestroyObjMetadata(	HOBJMETACTX *phMeta,
									DWORD dwParam );

int AAP_API DSetObjMetadata(	HOBJMETACTX hInMeta,
								DWORD dwOption,
								void *pvOptionData,
								DWORD dwOptionDataLen,
								DWORD dwParam );

int AAP_API DUnsetObjMetadata(	HOBJMETACTX hInMeta,
								DWORD dwOption,
								DWORD dwParam );

int AAP_API DGetObjMetadata(	HOBJMETACTX hInMeta,
								DWORD dwOption,
								void *pvOptionData,
								DWORD *pdwOptionDataLen,
								DWORD dwParam );

int AAP_API DSetObjMetadataJson(HOBJMETACTX hInMeta,
								char *szData,
								DWORD dwDataLen,
								DWORD dwParam);

int AAP_API DGetObjMetadataJson(HOBJMETACTX hInMeta,
								char *szData,
								DWORD *pdwDataLen,
								DWORD dwParam);

int AAP_API DManageObjMetadata(	HSESSIONCTX hSession,
								BYTE bOP,
								char *szObjName,
								HOBJMETACTX hInMeta,
								HOBJMETACTX *phOutMeta,
								DWORD dwParam );

int AAP_API DFindObjMetadataInit(	HSESSIONCTX hSession,
									HOBJMETACTX hInMeta,
									HOBJMETASEARCHCTX *phMetaSearchCtx,
									DWORD dwParam );

int AAP_API DFindObjMetadataCont(	HOBJMETASEARCHCTX hMetaSearchCtx,
									HOBJMETACTX *phOutMeta,
									DWORD dwOutMetaMaxCount,
									DWORD *pdwOutMetaDataCount,
									DWORD dwParam );

int AAP_API DFindObjMetadataEnd(	HOBJMETASEARCHCTX *phMetaSearchCtx,
									DWORD dwParam );

#define	MNG_OBJ_META_TYPE_ULONG		(1)
#define	MNG_OBJ_META_TYPE_STR		(2)
#define	MNG_OBJ_META_TYPE_BOOL		(3)
#define	MNG_OBJ_META_TYPE_INT_BOOL	(4)

typedef struct tag_OBJ_MET_ATTR
{
	DWORD		dwId;
	const char	*pszString;
	DWORD		dwType;
}OBJ_MET_ATTR;

int DGetObjMetadataTypeInfo(	DWORD dwOption,
								void *pvData,
								DWORD *pdwDataLen,
								DWORD dwReserved );

const OBJ_MET_ATTR * DGetObjMetadataTypeInfoList(int *pnOutLen);


/* P11 HSM Info */

int AAP_API DGetHSMP11Info(	HSESSIONCTX hSession,
							HP11ATTRCTX *phOutMeta,
							DWORD dwParam );

#define MNG_HSM_P11_INFO_SLOT_DESC					(1)
#define MNG_HSM_P11_INFO_MANUFACTURER_ID			(2)
#define MNG_HSM_P11_INFO_SLOT_FLAGS					(3)
#define MNG_HSM_P11_INFO_HDW_VERSION				(4)
#define MNG_HSM_P11_INFO_FMW_VERSION				(5)
#define MNG_HSM_P11_INFO_LABEL						(6)
#define MNG_HSM_P11_INFO_MODEL						(7)
#define MNG_HSM_P11_INFO_SERIAL_NUMBER				(8)
#define MNG_HSM_P11_INFO_TOKEN_FLAGS				(9)
#define MNG_HSM_P11_INFO_UTC_TIME					(10)
#define MNG_HSM_P11_INFO_MAX_SESSION_COUNT			(11)
#define MNG_HSM_P11_INFO_SESSION_COUNT				(12)
#define MNG_HSM_P11_INFO_MAX_RW_SESS_COUNT			(13)
#define MNG_HSM_P11_INFO_RW_SESS_COUNT				(14)
#define MNG_HSM_P11_INFO_MAX_PIN_LEN				(15)
#define MNG_HSM_P11_INFO_MIN_PIN_LEN				(16)
#define MNG_HSM_P11_INFO_TOTAL_PUB_MEMORY			(17)
#define MNG_HSM_P11_INFO_FREE_PUB_MEMORY			(18)
#define MNG_HSM_P11_INFO_TOTAL_PRIV_MEMORY			(19)
#define MNG_HSM_P11_INFO_FREE_PRIV_MEMORY			(20)
#define MNG_HSM_P11_INFO_SVMK_FINGERPRINT			(21)
#define MNG_HSM_INFO_TAMPERED_HSM                   (22)
#define MNG_HSM_INFO_OP_MODE                        (23)
#define MNG_HSM_INFO_DS_BOUND                       (24)
#define MNG_HSM_INFO_DS_HSM                         (25)
#define MNG_HSM_INFO_DS_ACCOUNT                     (26)
#define MNG_HSM_INFO_DS_URL                         (27)
#define MNG_HSM_INFO_DNS1                           (28)
#define MNG_HSM_INFO_DNS2                           (29)

int AAP_API DGetHSMP11InfoAttr(	HP11ATTRCTX hInMeta,
								DWORD dwOption,
								void *pvOptionData,
								DWORD *pdwOptionDataLen,
								DWORD dwParam );

int AAP_API DDestroyHSMP11Info(	HP11ATTRCTX *phMeta,
								DWORD dwParam );

const OBJ_MET_ATTR * DGetHSMP11TypeInfoList(int *pnOutLen);



/* Users */


int AAP_API DGetUserAcl ( HSESSIONCTX hSession, char *szUser,
                         DWORD *pdwUserAcl );

int AAP_API DListUserTrusts(HSESSIONCTX hSession, char *szUserId,
                            BYTE bType,
                            int (AAP_API * ListUserTrustCallback)(char *szUserName,
                                                                    DWORD dwACL,
                                                                    void *pParam,
                                                                    BOOL bFinal),
                            void *pParam);


/* Statistics */

int AAP_API DGetHsmInfo(HSESSIONCTX hSession, BOOL *pbFinal,
                        DWORD dwParam, BYTE * pbData,
                        DWORD* pdwDataLen, DWORD dwFlags);


/* Local operations */

int AAP_API DSetLogParam(HSESSIONCTX hSession, DWORD dwParam,
                         BYTE * pbData, DWORD dwDataLen,
                         DWORD dwFlags);

int AAP_API DGetLogParam(HSESSIONCTX hSession, DWORD dwParam,
                         BYTE * pbData, DWORD *pdwDataLen,
                         DWORD dwFlags);

int AAP_API DGetLibVersion(HSESSIONCTX hSession, char * szVersion,
                           DWORD *pdwVersionLen, DWORD dwFlags);


/* Key management */

int AAP_API DECParam2AlgId(BYTE *pbECParam, DWORD dwECParamLen,
                            int *pnAlgId, DWORD dwFlags);

int AAP_API DECPubKeyDER2AlgId(    BYTE *pbECPubKeyDER,
                                DWORD dwECPubKeyDERLen,
                                int *pnAlgId,
                                DWORD dwFlags );

/**
 \addtogroup keys

 @{ */

/**
 Cria e armazena uma chave criptográfica associada a um algoritmo de acordo com os parâmetros informados, dentro do HSM.

 \param_hSession
 \param[in] szKeyId    Identificador da chave dentro do HSM. Este identificador não deve conter espaços ou caracteres especiais. Caracteres maiúsculos e minúsculos são diferenciados (case-sensitive). Um identificador de objeto no HSM pode ter tamanho máximo, em caracteres, de #MAX_OBJ_ID (já incluído o caracter terminador). Quando está criando chaves na partição de outro usuário (é necessária permissão) o nome deve ser qualificado por inteiro com um FQN (<em>Full Qualified Name: partition_id/obj_id</em>), o tamanho máximo para um FQN é #MAX_OBJ_ID_FQN_LEN (já incluído o caracter terminador).
 \param[in] nAlgId     Define o algoritmo associado à chave criptográfica a ser gerada.<br><br>
                         __Chaves Simétricas__
                         Valor | Significado
                         :-----|:-----------
                         #ALG_DES | DES de 56 bits e com paridade impar.
                         #ALG_3DES_112 | 3DES-EDE (<em>Encrypt-Decrypt-Encrypt</em>) de 112 bits e com paridade impar.
                         #ALG_3DES_168 | 3DES-EDE (<em>Encrypt-Decrypt-Encrypt</em>) de 168 bits e com paridade impar.
                         #ALG_DESX | DESX de 192 bits. O tamanho efetivo é de 118 bits.
                         #ALG_ARC4 | ARC4 com 128 bits.
                         #ALG_ARC5 | ARC5 com 128 bits, bloco de 8 bytes e utilizando 16 rounds.
                         #ALG_AES_128 | AES com 128 bits.
                         #ALG_AES_192 | AES com 192 bits.
                         #ALG_AES_256 | AES com 256 bits.

                         __Chaves Assimétricas RSA__
                         Valor | Significado
                         :-----|:-----------
                         #ALG_RSA_512 |Par de chaves RSA com módulo de 512 bits.
                         #ALG_RSA_1024 | Par de chaves RSA com módulo de 1024 bits.
                         #ALG_RSA_2048 | Par de chaves RSA com módulo de 2048 bits.
                         #ALG_RSA_4096 | Par de chaves RSA com módulo de 4096 bits.
                         #ALG_RSA_1152 | Par de chaves RSA com módulo de 1152 bits.
                         #ALG_RSA_1408 | Par de chaves RSA com módulo de 1408 bits.
                         #ALG_RSA_1536 | Par de chaves RSA com módulo de 1536 bits.
                         #ALG_RSA_1976 | Par de chaves RSA com módulo de 1976 bits.
                         #ALG_RSA_1984 | Par de chaves RSA com módulo de 1984 bits.
                         #ALG_RSA_8192 | Par de chaves RSA com módulo de 8192 bits.
                         #ALG_RSA_2304 | Par de chaves RSA com módulo de 2304 bits.
                         #ALG_RSA_2560 | Par de chaves RSA com módulo de 2560 bits.
                         #ALG_RSA_2816 | Par de chaves RSA com módulo de 2816 bits.
                         #ALG_RSA_3072 | Par de chaves RSA com módulo de 3072 bits.

                         __Chaves Assimétricas ECC__
                         Valor | Significado
                         :-----|:-----------
                         #ALG_ECC_SECP112R1 | curva SECG/WTLS sobre um corpo finito primo de 112 bits (<em>verifiably random elliptic curve domain parameters</em>).
                         #ALG_ECC_SECP112R2 | curva SECG sobre um corpo finito primo de 112 bits (<em>verifiably random elliptic curve domain parameters 2</em>).
                         #ALG_ECC_SECP128R1 | curva SECG sobre um corpo finito primo de 128 bits (<em>verifiably random elliptic curve domain parameters 1</em>).
                         #ALG_ECC_SECP128R2 | curva SECG sobre um corpo finito primo de 128 bits (<em>verifiably random elliptic curve domain parameters 2</em>).
                         #ALG_ECC_SECP160K1 | curva SECG sobre um corpo finito primo de 160 bits (<em>koblitz domain parameters </em>).
                         #ALG_ECC_SECP160R1 | curva SECG sobre um corpo finito primo de 160 bits (<em>verifiably random elliptic curve domain parameters 1</em>).
                         #ALG_ECC_SECP160R2 | curva SECG/WTLS sobre um corpo finito primo de 160 bits (<em>verifiably random elliptic curve domain parameters 2</em>).
                         #ALG_ECC_SECP192K1 | curva SECG sobre um corpo finito primo de 192 bits (<em>koblitz domain parameters </em>).
                         #ALG_ECC_SECP192R1 | curva SECG/X9.62/NIST sobre um corpo finito primo de 192 bits (<em>verifiably random elliptic curve domain parameters 1</em>).
                         #ALG_ECC_SECP224K1 | curva SECG sobre um corpo finito primo de 224 bits (<em>koblitz domain parameters </em>).
                         #ALG_ECC_SECP224R1 | curva SECG/NIST sobre um corpo finito primo de 224 bits (<em>verifiably random elliptic curve domain parameters 1</em>).
                         #ALG_ECC_SECP256K1 | curva SECG sobre um corpo finito primo de 256 bits (<em>koblitz domain parameters </em>).
                         #ALG_ECC_SECP256R1 | curva SECG/X9.62 sobre um corpo finito primo de 256 bits (<em>verifiably random elliptic curve domain parameters 1</em>).
                         #ALG_ECC_SECP384R1 | curva SECG/NIST sobre um corpo finito primo de 384 bits (<em>verifiably random elliptic curve domain parameters 1</em>).
                         #ALG_ECC_SECP521R1 | curva SECG/NIST sobre um corpo finito primo de 521 bits (<em>verifiably random elliptic curve domain parameters 1</em>).
                         #ALG_ECC_X9_62_PRIME192V1 | curva X9.62 sobre um corpo finito primo de 192 bits (<em>version 1 domain parameters</em>).
                         #ALG_ECC_X9_62_PRIME192V2 | curva X9.62 sobre um corpo finito primo de 192 bits (<em>version 2 domain parameters</em>).
                         #ALG_ECC_X9_62_PRIME192V3 | curva X9.62 sobre um corpo finito primo de 192 bits (<em>version 3 domain parameters</em>).
                         #ALG_ECC_X9_62_PRIME239V1 | curva X9.62 sobre um corpo finito primo de 239 bits (<em>version 1 domain parameters</em>).
                         #ALG_ECC_X9_62_PRIME239V2 | curva X9.62 sobre um corpo finito primo de 239 bits (<em>version 2 domain parameters</em>).
                         #ALG_ECC_X9_62_PRIME239V3 | curva X9.62 sobre um corpo finito primo de 239 bits (<em>version 3 domain parameters</em>).
                         #ALG_ECC_X9_62_PRIME256V1 | curva X9.62 sobre um corpo finito primo de 256 bits (<em>version 1 domain parameters</em>).
                         #ALG_ECC_BRAINPOOL_P160R1 | curva Brainpool [RFC 5639](https://tools.ietf.org/html/rfc5639) sobre um corpo finito primo de 160 bits (<em>verifiably random domain parameters 1</em>)
                         #ALG_ECC_BRAINPOOL_P160T1 | curva Brainpool [RFC 5639](https://tools.ietf.org/html/rfc5639) sobre um corpo finito primo de 160 bits (<em>twisted domain parameters 1</em>)
                         #ALG_ECC_BRAINPOOL_P192R1 | curva Brainpool [RFC 5639](https://tools.ietf.org/html/rfc5639) sobre um corpo finito primo de 192 bits (<em>verifiably random domain parameters 1</em>)
                         #ALG_ECC_BRAINPOOL_P192T1 | curva Brainpool [RFC 5639](https://tools.ietf.org/html/rfc5639) sobre um corpo finito primo de 192 bits (<em>twisted domain parameters 1</em>)
                         #ALG_ECC_BRAINPOOL_P224R1 | curva Brainpool [RFC 5639](https://tools.ietf.org/html/rfc5639) sobre um corpo finito primo de 224 bits (<em>verifiably random domain parameters 1</em>)
                         #ALG_ECC_BRAINPOOL_P224T1 | curva Brainpool [RFC 5639](https://tools.ietf.org/html/rfc5639) sobre um corpo finito primo de 224 bits (<em>twisted domain parameters 1</em>)
                         #ALG_ECC_BRAINPOOL_P256R1 | curva Brainpool [RFC 5639](https://tools.ietf.org/html/rfc5639) sobre um corpo finito primo de 256 bits (<em>verifiably random domain parameters 1</em>)
                         #ALG_ECC_BRAINPOOL_P256T1 | curva Brainpool [RFC 5639](https://tools.ietf.org/html/rfc5639) sobre um corpo finito primo de 256 bits (<em>twisted domain parameters 1</em>)
                         #ALG_ECC_BRAINPOOL_P320R1 | curva Brainpool [RFC 5639](https://tools.ietf.org/html/rfc5639) sobre um corpo finito primo de 320 bits (<em>verifiably random domain parameters 1</em>)
                         #ALG_ECC_BRAINPOOL_P320T1 | curva Brainpool [RFC 5639](https://tools.ietf.org/html/rfc5639) sobre um corpo finito primo de 320 bits (<em>twisted domain parameters 1</em>)
                         #ALG_ECC_BRAINPOOL_P384R1 | curva Brainpool [RFC 5639](https://tools.ietf.org/html/rfc5639) sobre um corpo finito primo de 384 bits (<em>verifiably random domain parameters 1</em>)
                         #ALG_ECC_BRAINPOOL_P384T1 | curva Brainpool [RFC 5639](https://tools.ietf.org/html/rfc5639) sobre um corpo finito primo de 384 bits (<em>twisted domain parameters 1</em>)
                         #ALG_ECC_BRAINPOOL_P512R1 | curva Brainpool [RFC 5639](https://tools.ietf.org/html/rfc5639) sobre um corpo finito primo de 512 bits (<em>verifiably random domain parameters 1</em>)
                         #ALG_ECC_BRAINPOOL_P512T1 | curva Brainpool [RFC 5639](https://tools.ietf.org/html/rfc5639) sobre um corpo finito primo de 512 bits (<em>twisted domain parameters 1</em>)

                         __Chaves Assimétricas ECX__
                         Valor | Significado
                         :-----|:-----------
                         #ALG_ECX_ED25519 | curva [RFC 8032](https://tools.ietf.org/html/rfc8032)(apenas assinatura) sobre um corpo finito primo de ~256 bits.
                         #ALG_ECX_ED448 |   curva [RFC 8032](https://tools.ietf.org/html/rfc8032)(apenas assinatura) sobre um corpo finito primo de ~448 bits.
                         #ALG_ECX_X25519 |  curva [RFC 7748](https://tools.ietf.org/html/rfc7748)(apenas *key-agreement*) sobre um corpo finito primo de ~256 bits.
                         #ALG_ECX_X448 |    curva [RFC 7748](https://tools.ietf.org/html/rfc7748)(apenas *key-agreement*) sobre um corpo finito primo de ~448 bits.

                         __Chaves HMAC__
                         Valor | Significado
                         :-----|:-----------
                         #ALG_HMAC_MD5 | Chave HMAC MD5 com tamanho de 16 bytes.
                         #ALG_HMAC_SHA1 | Chave HMAC SHA1 com tamanho de 20 bytes.
                         #ALG_HMAC_SHA2_256 | Chave HMAC SHA2 256 com tamanho de 32 bytes.
                         #ALG_HMAC_SHA2_384 | Chave HMAC SHA2 384 com tamanho de 48 bytes.
                         #ALG_HMAC_SHA2_512 | Chave HMAC SHA2 512 com tamanho de 64 bytes.

 \param[in] dwFlags    Parâmetros adicionais da chave.
                      Valor | Significado
                      :-----|:-----------
                      #EXPORTABLE_KEY | A chave poderá ser exportada do HSM.
                      #TEMPORARY_KEY | A chave somente existirá enquanto a sessão estiver ativa. Ela será destruída após o encerramento da sessão.<br>O parâmetro szKeyId, identificador da chave, deve ser NULL.

                      Além dos valores da tabela anterior é possível adicionar uma definição de perfil de uso de chave.

                      É possível definir o perfil de uso da chave (_Attribute Usage-profile_), utilizando **apenas um** dos valores abaixo. Se nenhum dos valores abaixo for especificado o perfil da chave é definido como livre para qualquer uso. É obrigatório a definição do perfil de uso quando o HSM estiver em modo **RM3**.
                      Valor | Significado
                      :-----|:-----------
                      #AUP_DIG_SIG        | assinatura geração/verificação
                      #AUP_DATA_CRYPTO    | encriptação/decriptação de dados
                      #AUP_KeK            | _wrapping/unwrapping_ de chaves
                      #AUP_MAC            | geração/verificação MAC
                      #AUP_KDF            | função de derivação de chave
                      #AUP_CRYPTOGRAM     | geração/verificação de criptograma
                      #AUP_KEY_TRANSLATE  | tradução de chave
                      #AUP_EFT_CVK        | geração/verificação de CVV
                      #AUP_EFT_VISA_PVK   | geração de PVV
                      #AUP_EFT_IBM_3624   | geração/validação de PIN
                      #AUP_EFT_PEK        | encriptação/decriptação de PIN
                      #AUP_EFT_BDK        | DUKPT
                      #AUP_EFT_IPEK       | DUKPT IPEK
                      #AUP_EMV_IMK        | derivação de ICC MK, IDN
                      #AUP_EMV_IMKDAC     | derivação de ICC DAC
                      #AUP_EMV_IMKENC     | encriptação de dados ICC - PinBlock
                      #AUP_EMV_IMKMAC     | criptograma de dados ICC - EmvMac
                      #AUP_EMV_KeK        | _wrapping_ de ICC MK
                      #AUP_EMV_IMKKDF     | derivação de chave EMV
                      #AUP_EMV_IMKACRYPTO | cálculo ARPC
                      #AUP_EFT_KeK        | _wrapping/unwrapping_ de chave EFT
                      #AUP_EMV_DIG_SIG    | assinatura EMV geração/verificação
                      #AUP_EFT_TR31_KBPK  | chave de proteção de key-block TR31
                      #AUP_EFT_TR34_PK    | assinatura/envelope TR34
                      #AUP_SPB_PK         | SPB assinatura geração/verificação e _wrapping_ de chave
 \param[in] phKey    Ponteiro para o contexto da chave gerada. Depois do seu uso deverá ser liberado com a função DDestroyKey().

 \return \APIReturn_brief

 \attention No Dinamo todas as chaves são armazenadas cifradas, independe do modo de operação (FIPS ou non-FIPS).

 \remark  Aos contextos das chaves simétricas são atribuídos os seguintes valores padrões, quando se aplicarem:
 Parâmetro | Valor
 :-----|:-----------
 Vetor de Inicialização | Será um vetor com todos os bytes igual a zero e com o mesmo tamanho do bloco de operação do algoritmo da chave.
 Modo de Operação de Criptografia Simétrica | Será usado o modo CBC (Cipher Block Chain)
 Padding | Será usado o formato definido no padrão PKCS#5 como padding.

 O tamanho do bloco de operação dos algoritmos segue a tabela abaixo:
 Valor | Tamanho do bloco
 :-----|:----------------
 #ALG_DES | 8 bytes
 #ALG_3DES_112 | 8 bytes
 #ALG_3DES_168 | 8 bytes
 #ALG_AES_128 | 16 bytes
 #ALG_AES_192 | 16 bytes
 #ALG_AES_256 | 16 bytes
 #ALG_ARC5 | 8 bytes

 As chaves RSA no HSM são criadas preferencialmente com expoente público de valor fixo e definido (três bytes na sequência 01 00 01, valor decimal de 216 + 1 = 65537). Opcionalmente pode ser usado um expoente de valor 3 por questão de compatibilidade com sistemas antigos, mas não é recomendado.

 As chaves ECC são definidas conforme os padrões:

 1.	Standards for Efficient Cryptography Group (SECG)
 2.	Wireless Transport Layer Security (WTLS)
 3.	ANSI X9.62:2005 - Public Key Cryptography for the Financial Services Industry, The Elliptic Curve Digital Signature Algorithm (ECDSA)
 4.	NIST FIPS PUB 186-4 - Digital Signature Standard (DSS)
 5.	[RFC 5639](https://tools.ietf.org/html/rfc5639) - Elliptic Curve Cryptography (ECC) Brainpool Standard Curves and Curve Generation
 */
int AAP_API DGenerateKey(
    HSESSIONCTX hSession,
    char *szKeyId,
    int nAlgId,
    DWORD dwFlags,
    HKEYCTX * phKey
);

/**
Gera uma chave criptográfica e retorna o seu material. Esta operação gera uma chave utilizando o HSM e retorna o conteúdo da chave sem persistir a chave no HSM.

\param_hSession
\param[in] nAlgId     Define o algoritmo da chave criptográfica a ser gerada. Esta operação suporta apenas algoritmos de chaves simétricas. Veja lista de algoritmos em DGenerateKey().<br><br>
\param[in] pbData     Buffer que conterá a chave gerada. Pode ser passado NULL para receber o tamanho esperado de pbData em pdwDataLen.
\param[in,out] pdwDataLen Ponteiro contendo o tamanho do buffer pbData. Esta variável conterá o tamanho exato dos dados copiados em pbData. Caso pbData seja NULL ou o tamanho informado não seja suficiente para completar a operação, pdwDataLen conterá o tamanho esperado de pbData.
\param[in] dwReserved Reservado para uso futuro.

\return \APIReturn_brief

*/
int AAP_API DGenerateKeyMaterial(HSESSIONCTX hSession, 
								 int nAlgId,
								 BYTE *pbData,
								 DWORD *pdwDataLen,
								 DWORD dwReserved);

/**
 Recupera o contexto de uma chave, desde que o usuário corrente tenha acesso, armazenada dentro do HSM. Essa função não cria uma nova chave.

 \param_hSession
 \param[in] szKeyId    Identificador da chave dentro do HSM. Este identificador não deve conter espaços ou caracteres especiais. Caracteres maiúsculos e minúsculos são diferenciados (case-sensitive). Veja \p szKeyId em DGenerateKey() para detalhes sobre tamanhos máximos de identificadores.
 \param[in] dwFlags    Passar zero. Caso contrário a seguinte tabela é aceita.
                         Valor | Significado
                         :-----|:-----------
                         #D_GET_USR_KEY_OFFLINE | Gerará um handle de chave baseado em parâmetros específicos e não irá ao HSM para verificar os parâmetros informados. Para usar esta flag uma estrutura GET_USR_KEY_OFFLINE devidamente preenchida deverá ser passada em szKeyId. Notar que não são feitas verificações de correlação dos dados informados. Passar dados inválidos gerará um handle inválido, mesmo se esta função retornar sucesso.
 \param[out] phKey      Ponteiro para o contexto da chave gerada. Depois do seu uso deverá ser liberado com a função DDestroyKey().

 \return \APIReturn_brief

 \see DGenerateKey().
 */
int AAP_API DGetUserKey(
    HSESSIONCTX hSession,
    char *szKeyId,
    DWORD dwFlags,
    HKEYCTX * phKey
);



#define D_IMPORT_ALG_PRIV_KEY_RSA   (0xFFFFFFE1) /* Importa uma chave privada RSA. */
#define D_IMPORT_ALG_PRIV_KEY_ECC   (0xFFFFFFE0) /* Importa uma chave privada ECC(Curvas Elípticas com exceção de ECX). */
#define D_IMPORT_ALG_PRIV_KEY_P8	(0xFFFFFFDF) /* Importa uma chave no formato P8 */
#define D_IMPORT_ALG_PRIV_KEY_ECX	(0xFFFFFFDE) /* Import uma chave privada ECX */

/**
 Importa uma chave criptográfica para dentro do HSM. As chaves podem ser permanentes ou temporárias. As chaves exportadas com a função DExportKey() podem ser importadas sem alteração de formato.

 \param_hSession
 \param[in] szKeyId    Identificador da chave dentro do HSM. Este identificador não deve conter espaços ou caracteres especiais. Caracteres maiúsculos e minúsculos são diferenciados (case-sensitive). Veja \p szKeyId em DGenerateKey() para detalhes sobre tamanhos máximos de identificadores.
 \param[in] hKEKey     Contexto da chave com a qual o blob da chave a ser importada está cifrada  - KEK (key encryption key)
 \param[in] dwBlobType Formato do buffer da chave no parâmetro \p pbData.
                         Valor | Significado
                         :-----|:-----------
                         #PRIVATEKEY_BLOB_STRICT | \importPrivateKeyBlobDescription
                         #PRIVATEKEY_BLOB | Mesmo comportamento de #PRIVATEKEY_BLOB_STRICT mas em versões antigas de HSM pode retornar chaves RSA como uma concatenação de chave privada e chave pública nos formatos definidos no PKCS#1 v1.5, nas seções 7.1 e 7.2. Esta opção é mantida por compatibilidade. Utilizar #PRIVATEKEY_BLOB_STRICT.
                         #PRIVATEKEY_BLOB_P8 | Será importado um par de chaves RSA no formato PRIVATEKEY_BLOB_P8.<br>hKEKey deve ser o contexto de uma chave de simétrica.<br>O formato do blob da chave é o PrivateKeyInfo definido no PKCS#8.
                         #PUBLICKEY_BLOB | Será importada uma chave pública de um par de chaves RSA ou EC no formato PUBLICKEY_BLOB.hKEKey deve ser igual a NULL. O contexto retornado pela importação de chave pública deve ser utilizado apenas nas operações de envelope digital, pois o HSM não cria de forma persistente objetos RSA com apenas a parte pública da chave seguindo o padrão PKCS#1 v2.2 formato DER.Para chaves públicas EC(ECC e ECX) o padrão é o SubjectPublicKeyInfo formato DER.
                         #SIMPLE_BLOB | Será importada uma chave simétrica no formato SIMPLE_BLOB.hKEKey deve ser o contexto de uma chave privada associada à chave pública usada para criptografar o blob a ser importado.O tipo do padding usado para criptografia da chave deve ser 2, como definido no PKCS#1 v1.5 seção 8.1.
                         #PLAINTEXTKEY_BLOB | Será importada uma chave simétrica ou HMAC em claro.Essa flag ainda não é suportada para chaves RSA.
                         #SIMPLE_BLOB_OAEP | Define a importação através de envelope digital usando o padrão PKCS#1 versão 2.1, com esquema de cifragem RSAES-OAEP. A KEK deverá ser uma chave privada no HSM, cuja chave pública correspondente foi utilizada na criação do envelope. O contexto para esta KEK pode ser obtido via uma chamada à DGetUserKey, onde será informado o id da chave RSA do HSM usada para abrir o envelope.Este método de importação pode ser utilizado no modo de operação FIPS.
                         #SYM_WRAPPED_KEY_BLOB | Define uma chave simétrica encriptada por uma KEK (Key Encryption Key) também simétrica.O parâmetro hKEKey deverá conter o contexto de uma chave simétrica com os devidos parâmetros de utilização já definidos, como modo e padding.A chave será decriptada e importada para a base do HSM diretamente, sem formatação específica.
                         #HOTP_BLOB | Define a importação de um objeto tipo HTOP para a partição do usuário.
                         #PUBLICKEY_BLOB_HSM | Será importada uma chave pública de um par de chaves RSA/ECC no formato DER para dentro do HSM. hKEKey deve ser igual a NULL.
                         #PUBLICKEY_RSA_PARTS_HSM | Será importada uma chave pública, a partir do módulo e do expoente público, para dentro do HSM. hKEKey deve ser igual a NULL. Deve ser passado em pbData a estrutura RSA_PUB_KEY_PARTS devidamente preenchida.
                         #WRAPPED_KEY_BLOB | Importa uma chave encriptada por uma KEK (Key Encryption Key).O parâmetro hKEKey deverá conter o contexto de uma simétrica com os devidos parâmetros de utilização já definidos, como modo(de acordo com o algoritmo) e padding. A chave será decriptada e importada para a base do HSM diretamente, sem formatação específica.
 \param[in] nAlgId      Indica o algoritmo associado à chave criptográfica que será gerada. Veja lista de algoritmos em DGenerateKey(). Utilizar D_IMPORT_ALG_PRIV_KEY_RSA quando a chave privada importada for RSA e encriptada por KEK, o algoritmo específico será detectado automáticamente pelo HSM após abertura do BLOB encriptado.
 \param[in] dwFlags    Parâmetros adicionais da chave. Veja as opções na função DGenerateKey().
 \param[in] pbData     Buffer contendo a chave a ser importada.
 \param[in] dwDataLen  Tamanho do bloco de dados com a chave a ser importada.
 \param [out] phKey     Ponteiro para o contexto da chave gerada. Depois do seu uso deverá ser liberado com a função DDestroyKey.

 \return \APIReturn_brief

 \remarks Para chaves de sessão e chaves públicas é recomendável que a flag TEMPORARY_KEY seja usada, evitando que chaves de uso temporário ocupem espaço desnecessário no HSM.

 Formato do #SIMPLE_BLOB:\verbatim EB = 00 || BT || PS || 00 || D \endverbatim

 <br>Estruturas DER de #PRIVATEKEY_BLOB:
 \code
     RSAPrivateKey ::= SEQUENCE {
         version Version,
         modulus INTEGER, -- n
         publicExponent INTEGER, -- e
         privateExponent INTEGER, -- d
         prime1 INTEGER, -- p
         prime2 INTEGER, -- q
         exponent1 INTEGER, -- d mod (p-1)
         exponent2 INTEGER, -- d mod (q-1)
         coefficient INTEGER -- (inverse of q) mod p
     }
 \endcode

 \code
     ECPrivateKey ::= SEQUENCE {
     version        INTEGER { ecPrivkeyVer1(1) } (ecPrivkeyVer1),
     privateKey     OCTET STRING,
     parameters [0] ECParameters {{ NamedCurve }} OPTIONAL,
     publicKey  [1] BIT STRING OPTIONAL
   }
 \endcode



 <br>Estrutura DER de #PUBLICKEY_BLOB:
 \code
     RSAPublicKey ::= SEQUENCE {
         modulus INTEGER, -- n
         publicExponent INTEGER -- e
     }
 \endcode

  <br>Estrutura DER de #PUBLICKEY_BLOB_X509:
 \code
     SubjectPublicKeyInfo ::= SEQUENCE {
                          algorithm AlgorithmIdentifier,
                          publicKey BIT STRING }
 \endcode


 \see Observações de DGenerateKey().
 */
int AAP_API DImportKey(
    HSESSIONCTX hSession,
    char *szKeyId,
    HKEYCTX hKEKey,
    DWORD dwBlobType,
    int nAlgId,
    DWORD dwFlags,
    BYTE * pbData,
    DWORD dwDataLen,
    HKEYCTX * phKey
);

/**
 Exporta uma chave armazenada no HSM para que possa ser transportada. A chave poderá ser novamente importada para o Dinamo com a função DImportKey().

 \param[in] hKey           Contexto da chave a ser exportada.
 \param[in] hKEKey         Contexto da chave com a qual o bloco da chave será cifrado  - KEK (key encryption key).
 \param[in] dwBlobType     Formato do buffer da chave no parâmetro \p pbData. Veja parâmetro \p dwBlobType em DImportKey() para lista de tipos.
 \param[in] dwFlags        \ReservedParamBrief{0}
 \param[in] pbData         Buffer contendo os dados da chave conforme o parâmetro dwBlobType. Esse parâmetro pode ser NULL para que seja especificada a quantidade de memória necessária.
 \param [in,out] pdwDataLen  Ponteiro para o tamanho do buffer, em bytes,  especificado em \p pbData. Quando a função retorna, esse parâmetro conterá o tamanho dos dados armazenados em \p pbData.

 \return \APIReturn_brief

 \remarks Apenas chaves criadas como exportáveis podem ser extraídas com esta função, caso contrário o código de erro [D_INVALID_KEY_STATE](https://docs.hsm.dinamonetworks.io/codigos-retorno/lib_codes_pt_br#d_invalid_key_state) será retornado.
 */
int AAP_API DExportKey(
    HKEYCTX hKey,
    HKEYCTX hKEKey,
    DWORD dwBlobType,
    DWORD dwFlags,
    BYTE * pbData,
    DWORD * pdwDataLen
);

/**
 Importa para o HSM uma chave assimétrica privada RSA envelopada segundo o padrão PKCS#8. A chave privada RSA pode ser importada em texto claro ou protegida por envelope digital. Para detalhes sobre os padrões, consulte os documentos Public-Key Cryptography Standards (PKCS) da RSA Labs. No modo de operação FIPS as chaves RSA só podem ser importadas via o padrão PKCS#8 com uso de envelope digital, derivando uma chave AES 256 a partir de uma senha de no mínimo 01 caracter e no máximo 16, sendo a derivação feita conforme o padrão PKCS#5 versão 2.0.<br>O envelope utilizado poderá ser proveniente de qualquer sistema aderente aos padrões descritos.

 \param_hSession
 \param[in] szKeyId            Indentificador para a chave RSA que será criada na base do HSM. Veja \p szKeyId em DGenerateKey() para detalhes sobre tamanhos máximos de identificadores.
 \param[in] szSecret           Senha utilizada para derivar a chave AES 256. Pode ser passado NULL para não utilizar senha (importação em texto claro) ou uma senha de no máximo 16 caracteres.
 \param[in] dwKeyAlg           Indica o algoritmo associado à chave criptográfica a ser gerada.
                                  Valor | Significado
                                  :-----|:------------
                                 #ALG_RSA_512 |Par de chaves RSA com módulo de 512 bits.
                                 #ALG_RSA_1024 | Par de chaves RSA com módulo de 1024 bits.
                                 #ALG_RSA_2048 | Par de chaves RSA com módulo de 2048 bits.
                                 #ALG_RSA_4096 | Par de chaves RSA com módulo de 4096 bits.
                                 #ALG_RSA_1152 | Par de chaves RSA com módulo de 1152 bits.
                                 #ALG_RSA_1408 | Par de chaves RSA com módulo de 1408 bits.
                                 #ALG_RSA_1536 | Par de chaves RSA com módulo de 1536 bits.
                                 #ALG_RSA_1976 | Par de chaves RSA com módulo de 1976 bits.
                                 #ALG_RSA_1984 | Par de chaves RSA com módulo de 1984 bits.
                                 #ALG_RSA_8192 | Par de chaves RSA com módulo de 8192 bits.
                                 #ALG_RSA_2304 | Par de chaves RSA com módulo de 2304 bits.
                                 #ALG_RSA_2560 | Par de chaves RSA com módulo de 2560 bits.
                                 #ALG_RSA_2816 | Par de chaves RSA com módulo de 2816 bits.
                                 #ALG_RSA_3072 | Par de chaves RSA com módulo de 3072 bits.
 \param[in] dwAttrib            Parâmetros adicionais da chave.
                                  Valor | Significado
                                  :-----|:------------
                                  #EXPORTABLE_KEY | A chave poderá ser exportada em claro do HSM.
 \param[in] pbKeyEnvelope        Buffer que contém o envelope PKCS#8 de entrada.
 \param[in] dwKeyEnvelopeLen     Tamanho em bytes do envelope PKCS#8 de entrada.

 \return \APIReturn_brief
 */
int AAP_API DPKCS8ImportKey(
    HSESSIONCTX hSession,
    char *szKeyId,
    char *szSecret,
    DWORD dwKeyAlg,
    DWORD dwAttrib,
    BYTE *pbKeyEnvelope,
    DWORD dwKeyEnvelopeLen
);

/**
 Exporta uma chave assimétrica privada RSA armazenada no HSM segundo o padrão PKCS#8. A chave privada RSA pode ser exportada em texto claro ou protegida por envelope digital. Para detalhes sobre os padrões, consulte os documentos Public-Key Cryptography Standards (PKCS) da RSA Labs. No modo de operação FIPS as chaves RSA exportáveis só podem ser exportadas via o padrão PKCS#8 com uso de envelope digital, derivando uma chave AES 256 a partir de uma senha com tamanho entre #ND_MIN_P8_PWD_LEN e #ND_MAX_P8_PWD_LEN caracteres, sendo a derivação feita conforme o padrão PKCS#5 versão 2.0.
O envelope de saída poderá ser importado em qualquer sistema aderente aos padrões descritos.

 \param_hSession
 \param[in] szKeyId            Indentificador da chave RSA a ser exportada. Veja \p szKeyId em DGenerateKey() para detalhes sobre tamanhos máximos de identificadores.
 \param[in] szSecret           Senha com tamanho entre #ND_MIN_P8_PWD_LEN e #ND_MAX_P8_PWD_LEN, utilizada para derivar a chave AES 256. Pode ser passado NULL para exportar em texto claro, sem senha.
 \param [out] ppbKeyEnvelope    Ponteiro de ponteiro que irá conter o envelope PKCS#8 de saída. A alocação de memória é feita internamente pela biblioteca. A aplicação chamadora é responsável por liberar a memória alocada. Deve ser utilizada a função DFree() para liberar este buffer.
 \param [out] pdwKeyEnvelopeLen Ponteiro para DWORD que conterá o tamanho em bytes do envelope PKCS#8 de saída.

 \return \APIReturn_brief
 */
int AAP_API DPKCS8ExportKey(
    HSESSIONCTX hSession,
    char *szKeyId,
    char *szSecret,
    BYTE **ppbKeyEnvelope,
    DWORD *pdwKeyEnvelopeLen
);

/**
 Altera parâmetros dos contextos de chaves que, em geral, vão influenciar na sua manipulação.

 \param[in] hKey           Contexto da chave a ser exportada.
 \param[in] dwParam        Define a operação que será executada e por conseqüência a estrutura ou dados passados no parâmetro \p pbData.
                             Valor | significado
                             :-----|:-----------
                             #DKP_IV | Tipo de \p pbData: BYTE * <br>Vetor de inicialização usado com algoritmos de bloco de acordo com o seu modo de operação de criptografia simétrica. <br>O tamanho do vetor de inicialização depende do algoritmo simétrico utilizado, já que tem o mesmo comprimento do bloco de operação. Mais detalhes na sessão Observações. <br><br>Válido apenas para chaves simétricas.
                             #DKP_PADDING | Tipo de \p pbData: DWORD <br>A biblioteca pode trabalhar com os seguintes paddings simétricos:<br>#D_NO_PADDING: Não é feito padding, os dados passados para criptografia já deve ter comprimento múltiplo do tamanho do bloco de operação.<br>#D_PKCS5_PADDING: O padding é feito seguindo o padrão definido no PKCS#5. É o padding padrão, caso nenhum seja definido.<br>#D_ZERO_PADDING: Caso o comprimento dos dados não seja múltiplo do tamanho do bloco de operação, ele é completado com zeros a direita até que tenha um tamanho suportado pelo algoritmo. Este tipo de padding não deve ser usado com dados onde pode haver bytes com valor zero, pois pode gerar ambigüidade na operação de decriptografia. Caso os dados contenham apenas texto ASCII, por exemplo, não há problema. Válido apenas para chaves simétricas.<br>A biblioteca pode trabalhar com os seguintes paddings assimétricos:<br>#D_PKCS1_PADDING: O padding é feito seguindo o padrão definido no PKCS#1 v1.5. É o padding padrão, caso nenhum seja definido.<br>#D_PSS_PADDING: O padding é feito seguindo o padrão PSS definido no PKCS#1 EMSA-PSS-ENCODE com o hash igual ao usado no hash da mensagem, usando o _salt_ com o tamanho máximo disponível no bloco. Opção não disponível para assinaturas legadas.<br>#D_PSS_SALT_LEN_MD_PADDING: O padding é feito seguindo o padrão PSS definido no PKCS#1 EMSA-PSS-ENCODE com o hash igual ao usado no hash da mensagem, usando o _salt_ com o mesmo tamanho da saída do hash utilizado na operação.Opção não disponível para assinaturas legadas.
                             #DKP_MODE | Tipo de \p pbData: DWORD <br>Indica o modo de operação de criptografia do algoritmo de bloco. <br>#MODE_ECB: Eletronic Codebook (ECB) <br>#MODE_CBC: Cipher Block Chain (CBC) <br>#MODE_GCM: Galois/Counter Mode. A tag de autenticação está localizada logo após os dados encriptados/decriptados com o tamanho de (tamanho retornado - tamanho da mensagem em texto claro).<br>#MODE_KW: AESWRAP de acordo com o padrão [RFC-3394](https://tools.ietf.org/html/rfc3394). Utilizado nas operações de encriptação e decriptação de outras chaves. <br><br>#MODE_CFB: Cipher-Feedback. Ainda não suportada. <br>#MODE_OFB: Output-Feedback. Ainda não suportada.<br><br>Válido apenas para chaves simétricas e algoritmos de bloco.
                             #DKP_OWNER | Tipo de \p pbData: char * <br>Atribui a um usuário o privilégio de dono da chave. \p pbData é um ponteiro para uma string com o identificador de um usuário do HSM. <br><br>Ainda não suportada.
                             #DKP_USER | Tipo de \p pbData: char * <br>Atribui a um usuário o privilégio de usuário da chave. \p pbData é um ponteiro para uma string com o identificador de um usuário do HSM.<br><br>Ainda não suportada.
                             #DKP_READ_LOCK | Tipo de \p pbData: NULL <br>Marca a chave como não exportável.<br><br>Ainda não suportada.
 \param[in] pbData         Ponteiro para os dados ou estruturas especificados em \p dwParam.
 \param[in] dwDataLen      Tamanho dos dados ou estrutura especificados em \p dwParam.
 \param[in] dwFlags        #REMOVE_ATTRIBUTE pode ser usado para remover privilégio de um usuário sobre uma chave. Essa flag só deve ser usada em conjunto com #DKP_OWNER ou #DKP_USER.

 \return \APIReturn_brief
 */
int AAP_API DSetKeyParam(
    HKEYCTX hKey,
    DWORD dwParam,
    BYTE * pbData,
    DWORD dwDataLen,
    DWORD dwFlags
);

/**
 Recupera parâmetros dos contextos de chave.

 \param[in] hKey       Contexto da chave a ser exportada
 \param[in] dwParam    Define a operação que será executada e por conseqüência a estrutura ou dados passados no parâmetro \p pbData.
                        Todos os valores descritos em DSetKeyParam() e mais:
                         Valor | significado
                         :-----|:-----------
                         #DKP_ALGID | Tipo de \p pbData: DWORD <br>Recupera o algoritmo criptográfico associado à chave. <br>A lista de valores possíveis é a mesma definida para o parâmetro nAlgId na função DGenerateKey (ver pág. 36). Caso o objeto não seja uma chave criptográfica o valor retornado é  #ALG_OBJ.
                         #DKP_KEYLEN | Tipo de \p pbData: DWORD <br>Recupera o tamanho da chave em bytes.
                         #DKP_ENCRYPTED | Tipo de \p pbData: BOOL <br>Retorna o estado da chave dentro do HSM. Se verdadeiro a chave estará armazenada cifrada dentro do HSM, se falso a chave estará gravada em claro.
                         #DKP_KEY_INFO | Tipo de \p pbData: GET_USR_KEY_OFFLINE <br>Retorna as informações básicas da chave.
                         #DKP_BLOCK_SIZE | Tipo de \p pbData: DWORD <br>Recupera o tamanho do bloco da chave em bytes.
                         #DKP_OBJ_ATTRIBUTES | Tipo de \p pbData: DWORD <br>Recupera os atributos da chave.
 \param[in] pbData      Ponteiro para os dados ou estruturas especificados em \p dwParam
 \param[in] pdwDataLen  Tamanho dos dados ou estrutura especificados em \p dwParam
 \param[in] dwFlags     \ReservedParamBrief{0}

 \return \APIReturn_brief

 \see DGenerateKey().
 */
int AAP_API DGetKeyParam(
    HKEYCTX hKey,
    DWORD dwParam,
    BYTE * pbData,
    DWORD *pdwDataLen,
    DWORD dwFlags
);

/**
 Deriva uma chave a partir do hash informado. Se o hash ainda não estiver completo, ele será finalizado e seu valor utilizado como uma chave simétrica.

 \param[in] hHash      Contexto de hash criado com DCreateHash.
 \param[in] szKeyId    Identificador da chave dentro do HSM. Este identificador não deve conter espaços ou caracteres especiais. Caracteres maiúsculos e minúsculos são diferenciados (case-sensitive). Veja \p szKeyId em DGenerateKey() para detalhes sobre tamanhos máximos de identificadores.
 \param[in] nAlgId     Indica o algoritmo associado à chave criptográfica que será gerada. Veja lista de algoritmos em DGenerateKey().
 \param[in] dwFlags    Parâmetros adicionais da chave. Veja lista de parâmetros adicionais da chave em DGenerateKey().
 \param[in] phKey      Ponteiro para o contexto da chave gerada. Depois do seu uso deverá ser liberado com a função DDestroyKey().

 \return \APIReturn_brief
 */
int AAP_API DDeriveKey(
    HHASHCTX hHash,
    char * szKeyId,
    int nAlgId,
    DWORD dwFlags,
    HKEYCTX * phKey
);

/**
 Duplica o contexto de uma chave, incluindo o seu estado interno.

 \param[in] hKey       Contexto de chave.
 \param[in] dwFlags    \ReservedParamBrief{0}
 \param [out] phKey    Ponteiro para o contexto da chave gerada. Depois do seu uso deverá ser liberado com a função DDestroyKey().

 \return \APIReturn_brief

 \remarks Os contextos das chaves são independentes, sendo assim, ao liberar o contexto original, o novo contexto continua a ser válido.
 */
int AAP_API DDuplicateKey(
    HKEYCTX hKey,
    DWORD dwFlags,
    HKEYCTX * phKey
);

/**
 Usa o valor de uma chave simétrica como dados de entrada para a execução de um hash. O contexto de hash deve ter um contexto limpo para que possa ser usado nessa função, ou seja, não pode ter sido usado com a função DHashData().

 \param[in] hKey       Contexto de chave.
 \param[in] hHash      Contexto de hash criado com DCreateHash().
 \param[in] dwFlags    \ReservedParamBrief{0}

 \return \APIReturn_brief

 \remarks A chave tem que estar marcada como exportável para que essa operação possa ser realizada.
 */
int AAP_API DHashSessionKey(
    HKEYCTX hKey,
    HHASHCTX hHash,
    DWORD dwFlags
);

/**
 Libera o contexto de uma chave depois do seu uso. Depois que este contexto foi liberado ele não pode ser mais usado por qualquer função, se tornando inválido.

 \param[in] phKey      Ponteiro para um contexto de chave que será liberado.
 \param[in] dwFlags    Modificadores da operação.
                             Valor | Significado
                             :-----|:-----------
                             #REMOVE_FROM_HSM | Além de liberar o contexto apontado por \p phKey, remove a chave fisicamente da base do HSM.<br><br>Esse parâmetro deve ser usado apenas quando se tem certeza que a chave não será mais necessária.

 \return \APIReturn_brief
 */
int AAP_API DDestroyKey(
    HKEYCTX * phKey,
    DWORD dwFlags
);

/**
 Gera um CSR (Certificate Signing Request / Requisição de Assinatura de Certificado). É uma função especializada da API de geração de CSR PKCS#10 do HSM.

 \param_hSession
 \param[in] szPrivateKeyName    Identificador da chave privada.<br>
 \param[in] bVersion            Versão do CSR PKCS#10. A seguinte tabela é suportada.
                                     Valor | Significado
                                     :-----|:-----------
                                     #CORE_P10_CSR_VERSION1 | PKCS#10 CSR versão 1.
 \param[in] szDN                DN (Dinstinguished Name), para a geração do CSR, com tamanho máximo #CORE_P10_CSR_DN_MAX_LEN. Os campos de DN deverão ser separados por '/'.
 \param[in] dwOutType           Tipo de saída do CSR. A seguinte tabela é suportada,
                                     Valor | Significado
                                     :-----|:-----------
                                     #P10_CSR_DER | Exporta o CSR no formato DER.
                                     #P10_CSR_PEM | Exporta o CSR no formato PEM.
 \param[out] pdwCSRLen          Ponteiro para o tamanho do buffer alocado em ppbCSR.
 \param[out] ppbCSR             Ponteiro de ponteiro que irá receber o CSR.<br> O tamanho do buffer alocado estará disponível através de pdwCSRLen.<br> A alocação de memória é feita internamente.<br> A aplicação chamadora é responsável por liberar a memória alocada usando a API DFree().
 \param[in] dwParam             Parâmetros adicionais. A seguinte tabela é suportada.
                                     Valor | Significado
                                     :-----|:-----------
                                     0 | Utiliza o hash padrão do HSM na assinatura do CSR.
                                     #CORE_P10_HASH_SHA1 | Utiliza o SHA-1 na assinatura do CSR.
                                     #CORE_P10_HASH_SHA224 | Utiliza o SHA-224 na assinatura do CSR.
                                     #CORE_P10_HASH_SHA256 | Utiliza o SHA-256 na assinatura do CSR.
                                     #CORE_P10_HASH_SHA384 | Utiliza o SHA-384 na assinatura do CSR.
                                     #CORE_P10_HASH_SHA512 | Utiliza o SHA-512 na assinatura do CSR.

\remarks	Exemplos de campo DN.
\code
    /CN=teste
\endcode
\code
    /CN=www.teste.com/O=teste/OU=engenharia
\endcode
 \return \APIReturn_brief
 */
int AAP_API DGeneratePKCS10CSR(HSESSIONCTX hSession,
                               char *szPrivateKeyName,
                               BYTE bVersion,
                               char *szDN,
                               DWORD dwOutType,
                               DWORD *pdwCSRLen,
                               BYTE **ppbCSR,
                               DWORD dwParam);

/**
Associa uma chave privada a um certificado e opcionalmente uma chave pública seguindo dentro das especificações PKCS#11 Base v2.40 seção 4.6.3 e o utilizado pelo Firefox.

\param_hSession.
\param[in] szPriKey             Nome da chave privada que será associada.
\param[in] szPubKey             Nome da chave pública que será associada. Pode passar NULL para não gerar a chave pública associada. Deve ser relacionado a chave privada.
\param[in] szCert				Nome do certificado que será exportado. Deve ser relacionado a chave privada.
\param[in] pvReserved			Reservado para uso futuro. Deve ser NULL.
\param[in] dwReserved          Reservado para uso futuro. Deve ser 0.

\return \APIReturn_brief

\remarks	A associação padrão é baseada na utilizada pelo Firefox que altera os metadados dos objetos de acordo com a tabela abaixo.
Atributo | Valor
:-----|:-----------
CKA_ID | SHA1 do módulo da chave pública. Definido para Chave privada, chave pública e certificado.
CKA_LABEL | Id do certificado. Definido para chave privada e certificado.
CKA_SUBJECT | Subject recuperado do certificado. Definido para chave privada e certificado.

No caso de chaves EC o CKA_ID será o hash SHA1 do valor de CKA_PUBLIC_KEY_INFO.

\see DImportPKCS12().
*/
int AAP_API DAssociatePKCS11Key(HSESSIONCTX hSession,
								char *szPriKey,
								char *szPubKey,
								char *szCert,
								void *pvReserved,
								DWORD dwReserved);

/**
Exporta uma chave privada e um certificado RSA no formato PKCS#12.

\param_hSession.
\param[in] szPkcs12Pwd         Senha do arquivo PKCS#12. Passar NULL para gerar PKCS#12	sem senha.
\param[in] szKeyId             Nome da chave privada que será exportada. Veja \p szKeyId em DGenerateKey() para detalhes sobre tamanhos máximos de identificadores.
\param[in] szCertId            Nome do certificado que será exportado. Deve ser relacionado a chave privada.
\param[in] szReserved		   Reservado para uso futuro. Deve ser NULL.
\param[out] ppbPkcs12          Ponteiro para um ponteiro que conterá o PKCS#12 gerado. Esta área de dados será alocada internamente e deve ser liberada utilizando DFree().
\param[out] pdwPkcs12Len       Ponteiro para o tamanho dos dados escritos em \p ppbPkcs12.
\param[in] dwFlags             Passar 0 ou uma das opções da tabela abaixo.
Atributo | Valor
:-----|:-----------
DN_EXPORT_P12_LEGACY | Exporta a chave e certificado e gera o arquivo PKCS#12 em software.

\return \APIReturn_brief

\remarks A exportação PKCS#12 com a flag #DN_EXPORT_P12_LEGACY utiliza RC2 para criptografia do certificado, TripleDES(CBC) para criptografia de chave e SHA1 como hash padrão.

\see DImportPKCS12Buffer() DImportPKCS12().
*/
int AAP_API DExportPKCS12(	const HSESSIONCTX hSession,
							const char *szPkcs12Pwd,
							const char *szKeyId,
							const char *szCertId,
							const char *szReserved,
							BYTE **ppbPkcs12,
							DWORD *pdwPkcs12Len,
							DWORD dwFlags);

/**
Importa uma chave privada/pública e um certificado a partir de um buffer no formato PKCS#12.

\param_hSession.
\param[in] pbPkcs12            PKCS#12 que será importado.
\param[in] dwPkcs12Len         Tamanho do buffer que contém o PKCS#12 em \p pbPkcs12.
\param[in] szPkcs12Pwd         Senha do PKCS#12. Passar NULL para o caso de não haver senha.
\param[in] szKeyId             Nome da chave privada que será importada. Veja \p szKeyId em DGenerateKey() para detalhes sobre tamanhos máximos de identificadores.
\param[in] dwKeyAttr           Atributos da chave privada que será importada Veja \p dwFlags em DGenerateKey() para detalhes sobre os atributos de chave.
\param[in] szCertId            Nome do certificado que será importado. Deve ser relacionado a chave privada.
\param[in] szPubKeyId		   Nome da chave pública que poderá ser importada. Pode ser NULL caso não queira que a chave pública seja importada.
\param[in] dwFlags          Reservado para uso futuro. Deve ser 0.

\return \APIReturn_brief

\see DExportPKCS12(), DImportPKCS12().
*/
int AAP_API DImportPKCS12Buffer(const HSESSIONCTX hSession,
                                BYTE *pbPkcs12,
                                DWORD dwPkcs12Len,
                                const char *szPkcs12Pwd,
                                const char *szKeyId,
                                DWORD dwKeyAttr,
                                const char *szCertId,
                                const char *szPubKeyId,
                                DWORD dwFlags);

/**
Importa uma chave privada/pública e um certificado a partir de um arquivo no formato PKCS#12.

\param_hSession.
\param[in] szPkcs12File        Nome do arquivo PKCS#12 que será importado.
\param[in] szPkcs12Pwd         Senha do PKCS#12. Passar NULL para o caso de não haver senha.
\param[in] szKeyId             Nome da chave privada que será importada. Veja \p szKeyId em DGenerateKey() para detalhes sobre tamanhos máximos de identificadores.
\param[in] dwKeyAttr           Atributos da chave privada que será importada Veja \p dwFlags em DGenerateKey() para detalhes sobre os atributos de chave.
\param[in] szCertId            Nome do certificado que será importado. Deve ser relacionado a chave privada.

\return \APIReturn_brief

\see DExportPKCS12(), DImportPKCS12Buffer().
*/
int AAP_API DImportPKCS12(const HSESSIONCTX hSession,
                            const char *szPkcs12File,
                          const char *szPkcs12Pwd,
                          const char *szKeyId,
                          const DWORD dwKeyAttr,
                          const char *szCertId);

#define DN_FORM_DER (1) /**< Formato DER. */

/**
Decodifica as informações de uma chave pública RSA. Aceita chaves públicas
no formato PKCS#1 RSAPublicKey ou X.509 SubjectPublicKeyInfo.

\param[in] pbKey               Chave pública.
\param[in] dwKeyLen            Tamanho do buffer \p pbKey.
\param[in] dwInForm            Formato de entrada da chave em \p pbKey. A tabela abaixo é aceita.
Atributo | Valor
:-----|:-----------
#DN_FORM_DER | Chave em formato DER.
\param[out] pbPubKeyInfo           Ponteiro para uma estrutura #DN_RSA_PUB_KEY_INFO.
\param[in] dwReserved   \ReservedParamBrief{0}

\return \APIReturn_brief
*/
int AAP_API DRSAPublicKey2Info(BYTE *pbKey, DWORD dwKeyLen, DWORD dwInForm,
                               void *pvPubKeyInfo, DWORD dwReserved);
/** @} End of Chaves grouping*/

/**
 \addtogroup svault

 @{ */

/**
Faz a tokenização de um dado, gerando um _token blob_ e seu respectivo _token_.

\param_hSession.
\param[in] dwOp         Tipo da operação. Deverá ser 0.
\param[in] pbInData     Dados de entrada para a geração do _token_. Deverá ser utilizada a estrutura #SVAULT_GEN_TOKEN.
\param[out] pbTokenBlob Buffer que conterá o _token blob_. Passar um buffer de tamanho #D_SVAULT_TOKEN_BLOB_LEN na entrada. \p pdwTokenBlobLen conterá o tamanho do buffer de saída. O _token blob_ protege o _secret_ e seus metadados. Este buffer deverá ser guardado e utilizado na chamada à DSVaultGetData() para posterior recuperação do _secret_ ou _token_.
\param[in,out] pdwTokenBlobLen Tamanho de \p pbTokenBlob. Na entrada conterá o tamanho total do buffer \p pbTokenBlob e na saída conterá o tamanho dos dados copiados em \p pbTokenBlob.
\param[out] szToken     String de tamanho #D_SVAULT_MAX_TL + 1 que conterá o _token_ gerado. Pode ser passado NULL para não recuperar o _token_ gerado. O token poderá ser recuperado novamente utilizando a API DSVaultGetData().
\param[in] dwReserved   \ReservedParamBrief{0}

\return \APIReturn_brief

\see DSVaultGetData().
*/
int AAP_API DSVaultGenToken(HSESSIONCTX hSession,
                            DWORD dwOp,
                            BYTE *pbInData,
                            BYTE *pbTokenBlob,
                            DWORD *pdwTokenBlobLen,
                            char *szToken,
                            DWORD dwReserved);

/**
Recupera o _secret_ ou _token_ um dado tokenizado utilizando um _token blob_. Esta API também permite a recuperação do _secret_ ou _token_ mascarados.

\param_hSession.
\param[in] dwOp         Tipo da operação. Poderá ser uma das opções abaixo.
Valor | Significado
:-----|:-----------
#D_SVAULT_GET_OP_SECRET | Recupera o _secret_.
#D_SVAULT_GET_OP_TOKEN  | Recupera o _token_.
\param[in] szMK     Nome da chave utilizada para a proteção do dados.
\param[in] szMask   Padrão de máscara que será aplicado ao _secret_ ou _token_, de acordo com o definido na geração do _token blob_ em DSVaultGenToken(). Buffer com tamanho mínimo de #D_SVAULT_MIN_TL e máximo de #D_SVAULT_MAX_TL contendo a máscara. Pode ser NULL para não utilizar mascaramento.
A máscara é uma string UTF-8 que contém os caracteres que serão aplicados sobre os dados fazendo o mascaramento do mesmo. Passe '\0' nas posições onde queira que o dado seja apresentado. Veja as observações para exemplos.
\param[in] pbTokenBlob Buffer de tamanho #D_SVAULT_TOKEN_BLOB_LEN, gerado pela API DSVaultGenToken(), contendo o _token blob_.
\param[in] dwTokenBlobLen Buffer de tamanho máximo de #D_SVAULT_TOKEN_BLOB_LEN, gerado pela API DSVaultGenToken(), contendo o _token blob_.
\param[out] szData     String que conterá o _token_ ou o _secret_ de acordo com o especificado em \p dwOp. Pode-se utilizar um tamanho de #D_SVAULT_MAX_TL + 1 para cobrir todos os cados atuais.
\param[in,out] pdwDataLen  Tamanho da string \p szData. Deverá conter o tamanho de \p szData e no retorno da API conterá o tamanho total dos dados copiados.
\param[in] dwReserved   \ReservedParamBrief{0}

\return \APIReturn_brief

\remarks
Exemplos de uso de máscara.
Neste exemplo utilizaremos um _secret_ com valor "123456789".

Utilizando a máscara "***" teremos o seguinte resultado.

```
"***456789"
```

Aplicando a máscara "9999" teremos o seguinte resultado.

```
"999956789"
```

Aplicando a máscara "***\0\0\0***" teremos o seguinte resultado.

```
"***456***"
```

\see DSVaultGenToken().
*/
int AAP_API DSVaultGetData(HSESSIONCTX hSession,
                           DWORD dwOp,
                           const char *szMK,
                           const char *szMask,
                           BYTE *pbTokenBlob,
                           DWORD dwTokenBlobLen,
                           char *szData,
                           DWORD *pdwDataLen,
                           DWORD dwReserved);

/** @} End of SVault grouping*/

int AAP_API DRemoveKey(HSESSIONCTX hSession, char *szKeyId);

int AAP_API DCert2CertInfo(    BYTE *pbCert,
                            DWORD dwCertLen,
                            DWORD dwOutType,
                            void *pvCertInfo,
                            DWORD dwFlags );

/* Symmetric/Asymmetric operations */

/**
 \addtogroup cryptography

 @{ */

/**
 Criptografa de dados. O algoritmo usado depende da chave informada no parâmetro hKey.

 \param[in] hKey                Contexto de chave.
 \param[in] hHash               Contexto de hash se os dados forem submetidos à operação de hash antes de serem criptografados. Depois da operação completa, o valor do hash pode ser obtido através da função DGetHashParam().
 \param[in] bFinal              Indica o último bloco de uma série que foi cifrada. TRUE para último bloco ou FALSE caso contrário.
 \param[in] dwFlags             Deve ser passado 0, os valores da tabela abaixo são aceitos para casos específicos.
								 Valor | Significado
								:-----|:-----------
								#D_NO_RSA_PADDING | Não faz/desfaz o padding para chaves RSA. Usar apenas para chaves RSA. Pode ser utilizada juntamente com a flag #D_FORCE_ACTUAL_RSA.
								#D_FORCE_ACTUAL_RSA | Utiliza a chave RSA de maneira direta. Encriptação com chave privada em DEncrypt e decript com DDecrypt. Pode ser utilizada juntamente com a flag #D_NO_RSA_PADDING.
 \param[in,out] pbData          Ponteiro para um buffer que contem os dados a serem criptografados. Quando a função retorna, os dados originais são sobrescritos pelo resultado da operação de criptografia.<br>O tamanho buffer é especificado pelo parâmetro dwBufLen, o número de bytes a serem processados é especificado pelo parâmetro pdwDataLen. O tamanho do buffer deve ser grande o suficiente para conter os dados criptografados mais o padding.
 \param[in,out] pdwDataLen      Ponteiro para um DWORD que contem o tamanho dos dados em \p pbData. Quando parâmetro de entrada, contém o número de bytes que serão processados, quando parâmetro de saída, contém o número de bytes dos dados criptografados.<br>Se o buffer alocado não for suficiente para receber todo o dado cifrado (faltar, por exemplo, espaço para o padding) a função irá falhar retornando #D_MORE_DATA.
 \param[in] dwBufLen            Tamanho do buffer passado em \p pbData. Para operações simétricas que exijam padding o buffer deve ter o tamanho mínimo do comprimento do dado mais o tamanho do bloco de operação do algoritmo a ser utilizado.

 \return \APIReturn_brief

 \remarks Se uma quantidade grande de dados for cifrada, ela pode ser feita em parte, com chamadas subsequentes de DEncrypt. Na última chamada o parâmetro bFinal deve ser passado com valor verdadeiro.\par
Apenas no último bloco o padding é feito (quando se aplicar), assim, os demais blocos devem ter tamanho condizente com o algoritmo usado. O buffer onde os dados são passados deve ter tamanho suficiente para acondicionar também o padding.\par
Essa API suporta operações RSA feitas diretamente nesta função. Os dados para serem operados devem ter comprimento igual ou menor que o tamanho da chave menos 11  bytes. Quando utilizada a chave pública para criptografia o padding utilizado é PKCS#1 tipo 2 e no processo de decriptografia, o padding é verificado e retirado. Para operações com a chave privada, utiliza-se o padding PKCS#1 tipo 1. O HSM irá verificar a formatação do padding mesmo quando a operação não tem padding definido como em #D_NO_RSA_PADDING. As operações de encriptação e decriptação RSA só são habilitadas em modo não restrito (NRM).

 \see DGenerateKey().
 */
int AAP_API DEncrypt(
    HKEYCTX hKey,
    HHASHCTX hHash,
    BOOL bFinal,
    DWORD dwFlags,
    BYTE* pbData,
    DWORD* pdwDataLen,
    DWORD dwBufLen
);

/**
 Decriptografa dados, muitas vezes cifrado pela função DEncrypt. O algoritmo usado depende da chave informada no parâmetro hKey.

 \param[in] hKey            Contexto de chave.
 \param[in] hHash           Contexto de hash se os dados forem submetidos à operação de hash depois de serem decriptografados. Depois da operação completa, o valor do hash pode ser obtido através da função DGetHashParam().
 \param[in] bFinal          Indica o último bloco de uma série que foi cifrada. TRUE para último bloco ou FALSE caso contrário.
 \param[in] dwFlags        Deve ser passado 0, os valores da tabela abaixo são aceitos para casos específicos.
							Valor | Significado
							:-----|:-----------
							#D_NO_RSA_PADDING | Não faz/desfaz o padding para chaves RSA. Usar apenas para chaves RSA. Pode ser utilizada juntamente com a flag #D_FORCE_ACTUAL_RSA.
							#D_FORCE_ACTUAL_RSA | Utiliza a chave RSA de maneira direta. Encriptação com chave privada em DEncrypt e decript com DDecrypt. Pode ser utilizada juntamente com a flag #D_NO_RSA_PADDING.
 \param[in,out] pbData      Ponteiro para um buffer que contem os dados a serem decriptografados. Quando a função retorna, os dados originais são sobrescritos pelo resultado da operação de criptografia.<br>Para operações simétricas de bloco, é necessário que o tamanho dos dados seja sempre múltiplo do bloco usado pelo algoritmo em questão.
 \param[in,out] pdwDataLen  Ponteiro para um DWORD que contem o tamanho dos dados em \p pbData. Quando parâmetro de entrada, contém o número de bytes que serão processados, quando parâmetro de saída, contém o número de bytes dos dados em texto claro.

 \return \APIReturn_brief

 \remarks Se uma quantidade grande de dados for decifrada, ela pode ser feita em parte, com chamadas subsequentes de DDecrypt. Na última chamada o parâmetro bFinal deve ser passado com valor verdadeiro.\par
Apenas no último bloco o padding é desfeito (quando se aplicar), assim, os demais blocos devem ter tamanho condizentes com algoritmo usado, e se o modo de operação de criptografia simétrica CBC estiver sendo usado, o vetor de incialização será zerado. \par
Essa API suporta operações RSA feitas diretamente nesta função. Os dados para serem operados devem ter comprimento igual ao tamanho da chave. Quando utilizada a chave pública para criptografia o padding utilizado é PKCS#1 tipo 2 e no processo de decriptografia, o padding é verificado e retirado. Para operações com a chave privada, utiliza-se o padding PKCS#1 tipo 1. O HSM irá verificar a formatação do padding mesmo quando a operação não tem padding definido como em #D_NO_RSA_PADDING. As operações de encriptação e decriptação RSA só são habilitadas em modo não restrito (NRM).
 */
int AAP_API DDecrypt(
    HKEYCTX hKey,
    HHASHCTX hHash,
    BOOL bFinal,
    DWORD dwFlags,
    BYTE* pbData,
    DWORD* pdwDataLen
);

/**
 Inicializa um contexto de hash para ser usado com um fluxo de dados. Esse contexto é usado para chamadas subseqüentes DHashData(), DHashSessionKey(), entre outras.

 \param_hSession
 \param[in] nAlgId      Define o algoritmo associado ao contexto de hash.
                         Valor | Significado
                         :-----|:-----------
                         #ALG_MD5 | Algoritmo de hash MD5. hKey deve ser NULL.
                         #ALG_SHA1 | Algoritmo de hash SHA1. hKey deve ser NULL.
                         #ALG_SSL_SHA1_MD5 | Hash para autenticação de cliente em SSLv3. hKey deve ser NULL.
						 #ALG_SHA2_224 | Algoritmo de hash SHA2 - 224. hKey deve ser NULL.
                         #ALG_SHA2_256 | Algoritmo de hash SHA2 - 256. hKey deve ser NULL.
                         #ALG_SHA2_384 | Algoritmo de hash SHA2 - 384. hKey deve ser NULL.
                         #ALG_SHA2_512 | Algoritmo de hash SHA2 - 512. hKey deve ser NULL.
						 #ALG_SHA3_224 | Algoritmo de hash SHA3 - 224. hKey deve ser NULL.
						 #ALG_SHA3_256 | Algoritmo de hash SHA3 - 256. hKey deve ser NULL.
						 #ALG_SHA3_384 | Algoritmo de hash SHA3 - 384. hKey deve ser NULL.
						 #ALG_SHA3_512 | Algoritmo de hash SHA3 - 512. hKey deve ser NULL.
						 #ALG_HMAC_MD5 | Algoritmo HMAC MD5. hKey deve ser o contexto para a chave utilizada no HMAC.
                         #ALG_HMAC_SHA1 | Algoritmo HMAC SHA1. hKey deve ser o contexto para a chave utilizada no HMAC.
                         #ALG_HMAC_SHA2_256 | Algoritmo HMAC SHA2 - 256. hKey deve ser o contexto para a chave utilizada no HMAC.
                         #ALG_HMAC_SHA2_384 | Algoritmo HMAC SHA2 - 384. hKey deve ser o contexto para a chave utilizada no HMAC.
                         #ALG_HMAC_SHA2_512 | Algoritmo HMAC SHA2 - 512. hKey deve ser o contexto para a chave utilizada no HMAC.
						 #ALG_CMAC_DES | Algoritmo CMAC 3DES. hKey deve ser o contexto para a chave 3DES utilizada no CMAC.
                         #ALG_CMAC_AES | Algoritmo CMAC AES. hKey deve ser o contexto para a chave AES utilizada no CMAC.
						 #ALG_IDENTITY_FUNC | Função identidade. Os dados de entrada são iguais aos dados de saída. hKey NULL.
 \param[in] hKey         Deve ser passado de acordo com o tipo de algoritmo passado em nAlgId.
 \param[in] dwFlags      \ReservedParamBrief{0}
 \param[out] hHash      Ponteiro para o contexto do hash gerado. Depois do seu uso deverá ser liberado com a função DDestroyHash().

 \return \APIReturn_brief
 */
int AAP_API DCreateHash(
    HSESSIONCTX hSession,
    int nAlgId,
    HKEYCTX hKey,
    DWORD dwFlags,
    HHASHCTX *hHash
);

/**
 Adiciona dados à um determinado contexto de hash. Essa função pode ser chamada diversas vezes para adicionar dados discontinuos.

 \param[in] hHash           Contexto de hash gerado pela função DCreateHash().
 \param[in] pbData          Buffer contendo os dados que serão adicionados ao contexto de hash.
 \param[in] dwDataLen       Número de bytes a ser adicionados.
 \param[in] dwFlags         \ReservedParamBrief{0}

 \return \APIReturn_brief
 */
int AAP_API DHashData(
    HHASHCTX hHash,
    BYTE* pbData,
    DWORD dwDataLen,
    DWORD dwFlags
);

/**
 Altera um contexto de hash criado por DCreateHash().

 \param[in] hHash       Contexto de hash gerado pela função DCreateHash().
 \param[in] dwParam     Define o parâmetro do contexto de hash a ser modificado.
                         Valor | Significado
                         :-----|:-----------
                         DHP_HASH_VALUE | Tipo de \p pbData: BYTE * <br>pbData deverá ser um ponteiro para um buffer contendo o valor do hash a ser associado ao contexto.<br>Depois que for atribuído algum valor a este parâmetro, o valor do hash não poderá mais ser alterado e chamadas futuras de DHashData ou DHashSessionKey falharão retornando o código de erro [D_INVALID_HASH_STATE](https://docs.hsm.dinamonetworks.io/codigos-retorno/lib_codes_pt_br#d_invalid_hash_state).
 \param[in] pbData       Ponteiro para os dados ou estruturas especificados em \p dwParam.
 \param[in] dwDataLen    Tamanho dos dados ou estrutura especificados em \p dwParam.
 \param[in] dwFlags      \ReservedParamBrief{0}

 \return \APIReturn_brief
 */
int AAP_API DSetHashParam(
    HHASHCTX hHash,
    DWORD dwParam,
    BYTE * pbData,
    DWORD dwDataLen,
    DWORD dwFlags
);

/**
 Retorna atributos associados à um determinado contexto de hash. O valor do hash pode ser recuperado usando essa função.

 \param[in] hHash           Contexto de hash gerado pela função DCreateHash().
 \param[in] dwParam         Define o parâmetro do contexto de hash a ser recuperado.
                             Valor | Significado
                             :-----|:-----------
                             DHP_ALGID | Tipo de \p pbData: DWORD<br> Recupera o algoritmo associado a esse contexto quando ele foi criado.
                             DHP_HASH_SIZE | Tipo de \p pbData: DWORD<br> Recupera o comprimento do valor do hash.
                             DHP_HASH_VALUE | Tipo de \p pbData: BYTE *<br> \p pbData será um ponteiro para um buffer contendo o valor do hash associado ao contexto.<br> Depois que esse atributo for retornado, o valor do hash não poderá mais ser alterado e chamadas futuras de DHashData ou DHashSessionKey falharão retornando o código de erro [D_INVALID_HASH_STATE](https://docs.hsm.dinamonetworks.io/codigos-retorno/lib_codes_pt_br#d_invalid_hash_state).
 \param[in] pbData          Ponteiro para os dados ou estruturas especificados em \p dwParam. Esse parâmetro pode ser NULL para que seja especificada a quantidade de memória necessária.
 \param[in,out] pdwDataLen  Ponteiro para o tamanho do buffer, em bytes,  especificado em \p pbData. Quando a função retorna, esse parâmetro conterá o tamanho dos dados armazenados em \p pbData.
 \param[in] dwFlags          \ReservedParamBrief{0}

 \return \APIReturn_brief
 */
int AAP_API DGetHashParam(
    HHASHCTX hHash,
    DWORD dwParam,
    BYTE* pbData,
    DWORD* pdwDataLen,
    DWORD dwFlags
);

/**
 Assina um dado a partir do seu contexto de hash criado com a função DCreateHash().

 \param[in] hHash           Contexto de hash gerado pela função DCreateHash().
 \param[in] hKey            Contexto da chave privada a ser utilizada na assinatura.
 \param[in] dwFlags         Deve-se passar 0 ou algum modificador definido na lista abaixo.
                             Valor | Significado
                             :-----|:-----------
                             DN_SIGN_NO_HASH_OID | \signHashNoOID
                             DN_SIGN_DISABLE_LEGACY_OPERATION | \signHashDisableLegacyOperation
                             DN_SIGN_ECC_P11_FMT | \signHashEccP11Fmt
 \param[out] pbSignature     Buffer que receberá a assinatura. Esse parâmetro pode ser NULL para que seja especificada a quantidade de memória necessária.
 \param[in,out] pdwSigLen    Ponteiro para o tamanho da assinatura, em bytes. Quando a função retorna, esse parâmetro conterá o tamanho dos dados armazenados em pbSignature.

 \return \APIReturn_brief

 \remarks O formato da assinatura padrão gerado pela função DSignHash() está em conformidade com as especificações do PKCS#1 v.1.5, utilizando padding tipo 1 quando for usada uma chave RSA, com o uso de chaves ECDSA a assinatura estará no padrão DER ANSI X9.62/[RFC 3278 seção-8.2](https://tools.ietf.org/html/rfc3278#section-8.2).<br>
 Padrão DER ECDSA:<br>
 \code
 ECDSA-Sig-Value ::= SEQUENCE {
r INTEGER,
s INTEGER
}
\endcode
<br>

 As assinaturas geradas com chaves EdDSA são feitas utilizando o algoritmo de assinatura PureEdDSA como descrito na [RFC 8032](https://tools.ietf.org/html/rfc8032).
 Desta maneira, deve-se utilizar o algoritmo ALG_IDENTITY_FUNC nas APIs de hash para utilizar a função identidade.
 O tamanho máximo de dados aceitos para assinatura é de DN_SIG_EDDSA_MAX_DATA_LEN bytes.

 */
int AAP_API DSignHash(
    HHASHCTX hHash,
    HKEYCTX hKey,
    DWORD dwFlags,
    BYTE* pbSignature,
    DWORD* pdwSigLen
);


/**
 Libera o contexto de um hash depois do seu uso. Depois que este contexto foi liberado ele não pode ser mais usado por qualquer função, se tornando inválido.

 \param[in] phHash      Contexto de hash gerado pela função DCreateHash().

 \return \APIReturn_brief
 */
int AAP_API DDestroyHash(
    HHASHCTX * phHash
);

/**
 Verifica a assinatura do hash associado à um contexto.

 \param[in] hHash           Contexto de hash gerado pela função DCreateHash().
 \param[in] pbSignature     Buffer contendo o a assinatura a ser verificada.
 \param[in] dwSigLen        Número de bytes da assinatura.
 \param[in] hPubKey         Contexto para a chave pública utilizada na verificação da assinatura.
 \param[in] dwFlags         Modificadores do comportamento da função.
                             Valor | Significado
                             :-----|:-----------
                             DN_VERIFY_NO_HASH_OID | Quando essa flag é especificada, o identificador do objeto (OID) não é verificado, como previsto no PKCS#7, atributo DigestInfo.<br> Por padrão, esse valor é sempre verificado. Apenas em operações RSA.
							 DN_VERIFY_ECC_P11_FMT | Utiliza o formato de assinatura ECC PKCS#11 v2.40 seção [2.3.1](http://docs.oasis-open.org/pkcs11/pkcs11-curr/v2.40/errata01/os/pkcs11-curr-v2.40-errata01-os-complete.html#_Toc441850447).

 \return \APIReturn_brief

 \remarks Mais detalhes sobre os formatos de assinatura aceitos por esta API podem ser vistos nas observações da API DSignHash().
 */
int AAP_API DVerifySignature(
    HHASHCTX hHash,
    BYTE* pbSignature,
    DWORD dwSigLen,
    HKEYCTX hPubKey,
    DWORD dwFlags
);

/**
 Duplica o contexto de um hash, incluindo o seu estado interno.

 \param[in] hHash       Contexto de hash gerado pela função DCreateHash().
 \param[in] dwFlag      \ReservedParamBrief{0}
 \param[in] phHash      Ponteiro para o contexto do hash gerado. Depois do seu uso deverá ser liberado com a função DDestroyHash().

 \return \APIReturn_brief

 \remarks Os contextos dos hashs são independentes, sendo assim, ao liberar o contexto original, o novo contexto continua a ser válido.
 */
int AAP_API DDuplicateHash(
    HHASHCTX  hHash,
    DWORD dwFlag,
    HHASHCTX * phHash
);

/**
 Recupera um número determinado de bytes pseudo-aleatórios para uso criptográfico.

 \param_hSession
 \param[out] pbData         Buffer que será preenchido com os bytes pseudo-aleatórios.
 \param[in] dwDataLen       Tamanho em bytes de \p pbData.

 \return \APIReturn_brief
 */
int AAP_API DGetRandom(
    HSESSIONCTX hSession,
    BYTE *pbData,
    DWORD dwDataLen
);

/**
 Gera um segredo compartilhado(*shared secret*)/chave utilizando o protocolo de acordo de chaves (*key-agreement*) [ECDH (*Elliptc Curve Diffie-Hellman*)](https://en.wikipedia.org/wiki/Diffie%E2%80%93Hellman_key_exchange).

 \param_hSession
 \param[in] dwOP                 Modificadores do comportamento da função.
                                 Valor | Significado
                                 :-----|:-----------
                                 DN_GEN_KEY_KDF_RAW_SECRET | Retorna em \p pbOutData a chave secreta ECDH sem derivação. <br><br>Recomendamos derivar uma chave a partir desta, para comunicação com o par. O parâmetro passado em \p pvInData deve ser um ponteiro para um buffer contendo a chave pública do par no formato DER.
								 DN_GEN_KEY_X9_63_SHA256 | Deriva uma chave secreta ECDH no padrão ANSI X9.63 utilizando SHA256. Deve ser passado \p pvInData a estrutura #GEN_ECDH_X9_63. Ver documentação de #GEN_ECDH_X9_63 para detalhes de preenchimento. Retorna opcionalmente em \p pbOutData a chave secreta gerada, ver #GEN_ECDH_X9_63 para mais detalhes.
 \param[in] szPriKey             Identificador da chave privada dentro do HSM. Este identificador não deve conter espaços ou caracteres especiais. Caracteres maiúsculos e minúsculos são diferenciados (<em> case sensitive</em>)
 \param[in] pvInData             Ponteiro para os dados de entrada da função. Deve ser preenchido de acordo com o descrito nas opções de \p dwOP
 \param[in] dwInDataLen          Tamanho em bytes de \p pvInData.
 \param[out] pbOutData          Buffer que receberá a chave/segredo de saída. Esse parâmetro pode ser NULL para que seja retornada a quantidade de memória necessária em \p pdwOutDataLen. Este parâmetro será ignorado quando a operação for de gravar a chave no HSM.
 \param[in,out] pdwOutDataLen   Ponteiro para o tamanho do buffer \p pbOutData, em bytes, que conterá a chave/segredo de saída. Quando a função retorna, esse parâmetro conterá o tamanho dos dados efetivamente armazenados em \p pbOutData. Este parâmetro será ignorado quando a operação for de gravar a chave no HSM.
 \param[in] dwFlags             \ReservedParamBrief{0}

 \return \APIReturn_brief
 */
int AAP_API DGenEcdhKey(
    HSESSIONCTX hSession,
    DWORD dwOP,
    char *szPriKey,
    void *pvInData,
    DWORD dwInDataLen,
    BYTE *pbOutData,
    DWORD *pdwOutDataLen,
    DWORD dwFlags
);

/**
Valida um certificado X.509 no HSM utilizando uma LCR(Lista de Certificados Revogados) e uma cadeia de certificados.

\param_hSession
\param[in] szCRL       Nome da LCR(Lista de Certificados Revogados).
\param[in] szCertId    Nome do certificado que será validado.
\param[in] szVerifyInfo   Nome da cadeia de certificados/certificado para validação do certificado especificado em szCertId. Pode ser passado NULL para não fazer a verificação de cadeia de certificados.

\APIReturn_brief

*/
int AAP_API DCRLCertCheck(	HSESSIONCTX hSession,
							char *szCRL,
							char *szCertId,
							char *szVerifyInfo);

/** @} End of Criptografia grouping */

/* PIN - CVV */

/**
 \addtogroup eft

 @{ */

/**
 \pinBlockTranslateSummary

 \param_hSession
 \param[in] szSrcPEK                Identificador da chave de decriptação dentro do HSM.
 \param[in] szDstPEK                Identificador da chave de encriptação dentro do HSM.
 \param[in] bTransBlockType         Identificador do formato do bloco de saída. De acordo com a tabela abaixo.
                                     Valor | Significado
                                     :-----|:-----------
                                     #TP_TRANSLATE_TYPE_AUTO | Faz uma conversão de forma opaca, traduzindo do bloco com a chave de origem para o bloco com a chave de destino, sem análise do formato ou conteúdo do bloco.<br>PAN Bound: não se aplica.
                                     #TP_TRANSLATE_TYPE_ISO_0 | Utiliza o tipo de bloco ISO PIN Block Format 0 (equivalente ao ANSI PIN Block Format 0 e ao VISA PIN Block Format 1).<br>PAN Bound: sim.
                                     #TP_TRANSLATE_TYPE_ISO_1 | Utiliza o tipo de bloco ISO PIN Block Format 1.<br>PAN Bound: não.
                                     #TP_TRANSLATE_TYPE_ISO_3 | Utiliza o tipo de bloco ISO PIN Block Format 3. <br>PAN Bound: sim.
                                     #TP_TRANSLATE_TYPE_IBM_3624 | Utilizada o tipo de bloco IBM 3624.<br>Não implementado.
 \param[in] szPAN                   PAN (Primary Account Number).
 \param[in] pbInPinBlock            Buffer contendo o PIN Block de entrada. O buffer deve ter o tamanho de um PIN Block, #DES_BLOCK (8 bytes) .
 \param[out] pbOutPinBlock          Buffer que conterá o PIN Block de saída. O buffer deve ter o tamanho de um PIN Block, #DES_BLOCK  (8 bytes).
 \param[in] dwParam                 \ReservedParamBrief{0}

 \return \APIReturn_brief

 \remarks \pinBlockTranslateRemarks
 */
int AAP_API DPINBlockTranslate (
    HSESSIONCTX hSession,
    char *szSrcPEK,
    char *szDstPEK,
    BYTE bTransBlockType,
    char *szPAN,
    BYTE *pbInPinBlock,
    BYTE *pbOutPinBlock,
    DWORD dwParam
);

/**
 Gera um CVV (Card Verification Value), CVV2 ou iCVV utilizando uma chave dentro do HSM.

 Esta API também pode ser usada para a geração dos códigos de verificação de cartão que suportam o protocolo 3-D Secure. No caso da Visa o serviço que implementa o protocolo é o Verified by Visa, e o HSM suporta o padrão CAVV (Cardholder Authentication Verification Value, que é o CVV2 com método ATN). No caso da Mastercard o protocolo 3-D Secure é implementado no serviço SecureCode, o HSM suporta os padrões CVC2 (Card Verification Code  2) e HMAC SHA1.

 \param_hSession
 \param[in] szKeyId             Identificador da chave dentro do HSM. Este identificador não deve conter espaços ou caracteres especiais. Caracteres maiúsculos e minúsculos são diferenciados (case-sensitive).<br>Esta chave é a CVK (Card Verification Key), uma chave 3DES de 112 bits, e deve ser a mesma que será usada para a verificação do CVV. Esta chave pode ser gerada internamente no HSM ou importada manualmente.<br>Normalmente esta chave também é usada na Visa, enviada cifrada pela ZCMK (Zone Contro Master Key).<br>Conforme determinado no manual da Visa, a chave 3DES 112 usada como CVK deve ser diferente da chave usada para geração e verificação de PIN e não deve ser usada para outras aplicações do emissor, com exceção do CVV2 e iCVV.
 \param[in] szPAN               PAN (Primary Account Number). Tamanho de de 12 a 19 caracteres.<br> Para o cálculo de CVV, CVV2 e iCVV, conforme o padrão da Visa, no documento Payment Technology Standards Manual, de 2007, é independente do tamanho do PAN. Para o cálculo de CVC2, conforme o documento da Mastercard SPA Algorithm for the MasterCard Implementation of 3-D Secure – v1.04, o tamanho do PAN deve ser exatamente de 16 dígitos; quando for menor precisa se completado à esquerda com zeros, e quando for maior devem ser usados apenas os 16 dígitos mais à direita.
 \param[in] szExpirationDate    Data de expiração. Tamanho de 4 dígitos.<br>Na geração de CVV e iCVV o formato deve ser YYMM.<br>Na geração de CVV2 o formato deve ser MMYY.<br>No cáculo de CVC2 este campo deve ser uma string terminada em zero com os 4 dígitos menos significativos do Transaction Sequence Number, contido no AVV (Accountholder Authentication Value) convertido no BCD decimal equivalente. Qualquer valor menor que 4 dígitos deve ser completado à esquerda com zeros até inteirar os 4 dígitos. Para mais detalhes consulte o documento da Mastercard SPA Algorithm for the MasterCard Implementation of 3-D Secure – v1.04.<br>No cáculo de CAVV (CVV2 com o Método ATN), este campo deve ser uma string terminada em zero com os 4 dígitos menos significativos do ATN (Authentication Tracking Number). Para mais detalhes consulte o documento da Visa 3-D Secure Functional Requirements Access Control Server v. 1.0.2.
 \param[in] szServiceCode       Service Code. Tamanho de 3 dígitos.<br>Para a geração de iCVV (Alternate Card Verification Value), o Service Code deve ser 999.<br>Para a geração de CVV 2, o Service Code deve ser 000.<br>Para a geração de CVV tradicional, o Service Code normalmente é 101.
 \param[out] szCVV              Buffer de saída que conterá a string do CVV gerado. Tamanho de 3 dígitos.<br>O valor gerado pode também ser um CVV2 ou iCVV, conforme os valores informados de Service Code.
 \param[in] dwParam             \ReservedParamBrief{0}

  \return \APIReturn_brief

  \remarks A API também é compatível com o padrão da bandeira American Express.
 */
int AAP_API DGenerateCVV (
    HSESSIONCTX hSession,
    char *szKeyId,
    char *szPAN,
    char *szExpirationDate,
    char *szServiceCode,
    char *szCVV,
    DWORD dwParam
);

/**
 Verifica um CVV (Card Verification Value), , CVV2 ou iCVV utilizando uma chave dentro do HSM. A API também pode ser usada para a verificação dos códigos de verificação de cartão que suportam o protocolo 3-D Secure. Veja mais detalhes na API DGenerateCVV().

 \param_hSession
 \param[in] szKeyId                 Identificador da chave dentro do HSM. Este identificador não deve conter espaços ou caracteres especiais. Caracteres maiúsculos e minúsculos são diferenciados (case-sensitive).<br>Esta chave é a CVK (Card Verification Key), uma chave 3DES de 112 bits, e deve ser a mesma que foi usada na geração do CVV.
 \param[in] szPAN                   PAN (Primary Account Number). Tamanho de de 12 a 19 caracteres.<br>Veja mais detalhes sobre este campo na API DGenerateCVV().
 \param[in] szExpirationDate        Data de expiração. Tamanho de 4 dígitos.<br>Na verificação de CVV e iCVV o formato deve ser YYMM.<br>Na verificação de CVV 2 o formato deve ser MMYY.<br>Para informações sobre o suporte aos algoritmos do protocolo 3-D Secure veja mais detalhes sobre este campo na API DGenerateCVV().
 \param[in] szServiceCode           Service Code. Tamanho de 3 dígitos.<br>Para a verificação de iCVV (Alternate Card Verification Value), o Service Code deve ser 999.<br>Para a verificação de CVV 2, o Service Code deve ser 000
 \param[in] szCVV                   CVV a ser validado. Tamanho de 3 dígitos.<br>O valor informado pode também ser um CVV2 ou iCVV, conforme os valores informados de Service Code.
 \param[in] dwParam                 \ReservedParamBrief{0}

 \return \APIReturn_brief
 */
int AAP_API DVerifyCVV (
    HSESSIONCTX hSession,
    char *szKeyId,
    char *szPAN,
    char *szExpirationDate,
    char *szServiceCode,
    char *szCVV,
    DWORD dwParam
);

/**
  Faz operações de geração de PIN a partir dos dados de PAN (Personal Account Number) e nome de chave (PGK) informadas, com ou sem uso de offset.

 \param_hSession
 \param[in] szPGK           Identificador da chave dentro do HSM.
 \param[in] szPAN           PAN (Primary Account Number).
 \param[in] dwOperation     Tipo da geração do PIN. Segundo a tabela abaixo.
                              Valor | Significado
                              :-----|------------
                              #GP_DEFAULT_PIN | Gera o PIN padrão baseado no PAN e PGK. O parâmetro szInPin deve ser NULL.
                              #GP_USER_DEF_PIN | Gera um offset referente ao PIN definido pelo chamador. O parâmetro szInPin deve conter uma string contendo o PIN.
                              #GP_RANDOM_PIN | Gera um PIN e offset aleatoriamente baseados no PAN e PGK. \p szInPin deve ser NULL.
 \param[in] nPinLen         Tamanho de PIN a ser utilizado/gerado na operação. Deve ter tamanho entre #MIN_EFT_PIN_LEN e #MAX_EFT_PIN_LEN.
 \param[in] szInPin         PIN de entrada. O buffer deve ter tamanho entre #MIN_EFT_PIN_LEN + 1 e #MAX_EFT_PIN_LEN + 1.
 \param[out] szOffset       Buffer que conterá a string do offset. O buffer deve ter tamanho entre #MIN_EFT_PIN_LEN + 1 e #MAX_EFT_PIN_LEN + 1.
 \param[out] szOutPin       Buffer que conterá a string do PIN de saída. O buffer deve ter tamanho entre #MIN_EFT_PIN_LEN + 1 e #MAX_EFT_PIN_LEN + 1.
 \param[in] dwParam         \ReservedParamBrief{0}

 \return \APIReturn_brief
 */
int AAP_API DGeneratePIN (
    HSESSIONCTX hSession,
    char *szPGK,
    char *szPAN,
    DWORD dwOperation,
    int nPinLen,
    char *szInPin,
    char *szOffset,
    char *szOutPin,
    DWORD dwParam
);

/**
 Verifica a validade de um PIN em um PIN Block. Primeiro o PIN é extraído do PIN Block com a chave PTK, e depois é feita sua verificação com a chave PGK, a mesma que foi usada para geração do PIN, com a função DGeneratePIN().

 \param_hSession
 \param[in] szPTK           Identificador da chave de decriptação do “PIN Block” dentro do HSM. É a PIN Transport Key.
 \param[in] szPGK           Identificador da chave a ser utilizada na verificação do PIN dentro do HSM. É a PIN Generation Key.
 \param[in] szPAN           PAN (Primary Account Number).
 \param[in] szOffset        Offset do PIN. O buffer deve ter tamanho entre #MIN_EFT_PIN_LEN + 1 e #MAX_EFT_PIN_LEN + 1.
 \param[in] pbInPinBlock    Buffer que conterá o Pin Block de entrada que será verificado. O formato de PIN Block esperado é ISO PIN Block Format 0 (equivalente ao ANSI PIN Block Format 0 e ao VISA PIN Block Format 1). O buffer deve ter o tamanho de um PIN Block, #DES_BLOCK (8 bytes).
 \param[in] dwParam         \ReservedParamBrief{0}

 \return \APIReturn_brief
 */
int AAP_API DVerifyPINBlock (
    HSESSIONCTX hSession,
    char *szPTK,
    char *szPGK,
    char *szPAN,
    char *szOffset,
    BYTE *pbInPinBlock,
    DWORD dwParam
);

/**
 Verifica a validade das partes de uma chave VISA com os seus respectivos valores de verificação, no formato descrito no _VISA Payment Technology Standards Manual, october 2007_.

 \param[in] nKeyAlgId       Algoritmo da chave a ser verificada.
 \param[in] pstKeyParts     Ponteiro para uma estrutura EFT_VISA_KEY_PARTS contendo as partes da chave a ser verificada seus valores de verificação por partes.
 \param[in] dwParam         \ReservedParamBrief{0}

 \return \APIReturn_brief

 \remarks Apenas as partes são verificadas com os seus respectivos valores de verificação, a chave completa e montada não é verificada neste teste.
 */
int AAP_API DEFTCheckKeyParts (
    int nKeyAlgId,
    EFT_VISA_KEY_PARTS *pstKeyParts,
    DWORD dwParam
);

/**
 Gera uma chave DUKPT dentro do HSM utilizando uma KSI (Key Serial Identification), um DID (Device ID) e um CTR (Transaction Counter) de uma mesma KSN (Key Serial Number).

 \param_hSession
 \param[in] pbKSI               Buffer de tamanho #MIN_KSI_LEN contendo o KSI (primeiros 05 bytes do KSN).
 \param[in] pbDID_CTR           Buffer de tamanho #MIN_CTR_LEN contendo o DID e CTR (últimos 05 bytes do KSN).
 \param[out] szDUKPT            Buffer de tamanho #MAX_OBJ_ID que conterá o nome da chave DKUPT gerado a partir dos parâmetros informados.
 \param[in] dwParam             Flags de operação de acordo com a tabela abaixo.
                                 Valor | Significado
                                 :-----|:-----------
                                 #NEW_DUKPT_MODE_DUK | Gera uma chave DUK (Derived Unique Key) padrão de acordo com o manual ISO X9.24-1-2004.
                                 #NEW_DUKPT_MODE_PEK | Gera uma chave PEK (PIN Encryption Key) de acordo com o manual ISO X9.24-1-2004 A aplicando o XOR da máscara 0000 0000 0000 FF00 nas partes da chave.
                                 #NEW_DUKPT_MODE_MEK | Gera uma chave MEK (MAC Encryption Key) de acordo com o manual ISO X9.24-1-2004 A aplicando o XOR da máscara 0000 0000 0000 00FF nas partes da chave.
                                 #NEW_DUKPT_MODE_DE | Diversifica a chave gerada no formato Data Encryption. Aplica um XOR da máscara 0000 0000 00FF 0000 0000 0000 00FF 0000 sobre a chave DUKPT gerada, encripta a chave esquerda da DUKPT utilizando a DUKPT gerada e repete a encriptação com a chave direita. Após esta operação junta as partes esquerda e direita encriptadas para formar a Data Encryption Key. Como descrito em IDTECH USER MANUAL SecureMag Encrypted MagStripe Reader (80096504-001 RevL 06/19/14).<br> Deve ser utilizada combinada (via operação OR) com uma das flags: #NEW_DUKPT_MODE_DUK, #NEW_DUKPT_MODE_PEK ou #NEW_DUKPT_MODE_MEK
                                 #NEW_DUKPT_MODE_EXP | Gera uma chave DUKPT exportável. Esta é uma flag de atributo e deve ser utilizada combinada com outras flags. Utilizar apenas se especificamente necessário.
								 #NEW_DUKPT_MODE_TMP | Gera uma chave DUKPT temporária. Esta é uma flag de atributo e deve ser utilizada combinada com outras flags.
								 #NEW_DUKPT_MODE_IPEK | Gera uma chave IPEK (Initially Loaded PIN Entry Device Key) de acordo com o manual ISO X9.24-1-2004 A-6.

 \return \APIReturn_brief
 */
int AAP_API DGenerateDUKPT (
    HSESSIONCTX hSession,
    BYTE *pbKSI,
    BYTE *pbDID_CTR,
    char *szDUKPT,
    DWORD dwParam
);

/**
 Gera o nome da BDK a partir de uma KSI (Key Serial Identification).

 \param[in] pbKSI           Buffer de tamanho #MIN_KSI_LEN contendo o KSI.
 \param[out] szBDKName      Buffer de tamanho #MAX_OBJ_ID que conterá o nome de chave BDK gerado a partir do KSI informado em pbKSI.
 \param[in] dwParam         \ReservedParamBrief{0}

 \return Não retorna valor.
 */
void AAP_API DGenerateBDKName (
    BYTE *pbKSI,
    char *szBDKName,
    DWORD dwParam
);

/**
 Gera o nome da DUKPT a partir de uma KSI e CTR informados.

 \param[in] pbKSI               Buffer de tamanho #MIN_KSI_LEN contendo o KSI (Key Serial Identification).
 \param[in] pbDID_CTR           Buffer de tamanho #MIN_CTR_LEN contendo o CTR (Device ID e Transaction Counter).
 \param[out] szDUKPTName        Buffer de tamanho #MAX_OBJ_ID que conterá o nome de chave DKUPT gerado a partir do KSI e CTR informados em pbKSI e pbCTR.
 \param[in] dwParam             \ReservedParamBrief{0}

 \return Não retorna valor.
 */
void AAP_API DGenerateDUKPTName (
    BYTE *pbKSI,
    BYTE *pbDID_CTR,
    char *szDUKPTName,
    DWORD dwParam
);

/**
 Gera um PVV (Pin Verification Value) a partir de um PAN (Primary Account Number), um PIN (Personal Identification Number) e uma PGK.

 \param_hSession
 \param[in] szPGK       Identificador da chave dentro do HSM.
 \param[in] bPVKI       Identificador de chave variando de #EFT_MIN_PVKI até #EFT_MAX_PVKI.
 \param[in] szPAN       PAN (Primary Account Number).
 \param[in] szPIN       PIN (Personal Identification Number).
 \param[out] szPVV      Buffer que conterá a string  do PVV gerado. Deve ter tamanho mínimo de #EFT_PVV_LEN + 1 (terminador zero).
 \param[in] dwParam     \ReservedParamBrief{0}

 \return \APIReturn_brief
 */
int AAP_API DGeneratePVV (
    HSESSIONCTX hSession,
    char *szPGK,
    BYTE bPVKI,
    char *szPAN,
    char *szPIN,
    char *szPVV,
    DWORD dwParam
);

/**
 Gera um DAC (Data Authentication Code) recebendo como parâmetros o PAN (Primary Account Number), a SEQ (PAN Sequence Number) e a chave IMKDAC (Issuer Master Key) utilizada no DAC.

 \param_hSession
 \param[in] szIMKDAC        Identificador da chave dentro do HSM.
 \param[in] szPAN           PAN (Primary Account Number).
 \param[in] pbSEQ           Buffer de tamanho #EFT_EMV_SDA_SEQ_LEN contendo o SEQ (PAN Sequence Number).
 \param[out] pbDAC          Buffer de tamanho #EFT_EMV_SDA_DAC_LEN contendo o DAC (Data Authentication Code) a ser verificado.
 \param[in] dwParam         \ReservedParamBrief{0}

 \return \APIReturn_brief
 */
int AAP_API DGenerateDAC (
    HSESSIONCTX hSession,
    char *szIMKDAC,
    char *szPAN,
    BYTE *pbSEQ,
    BYTE *pbDAC,
    DWORD dwParam
);

/**
 Verifica um DAC (Data Authentication Code) recebendo como parâmetros o PAN (Primary Account Number), a SEQ (PAN Sequence Number) e a chave IMKDAC (Issuer Master Key) utilizada no DAC.

 \param_hSession
 \param[in] szIMKDAC        Identificador da chave dentro do HSM.
 \param[in] szPAN           PAN (Primary Account Number).
 \param[in] pbSEQ           Buffer de tamanho #EFT_EMV_SDA_SEQ_LEN contendo o SEQ (PAN Sequence Number).
 \param[in] pbDAC           Buffer de tamanho #EFT_EMV_SDA_DAC_LEN contendo o DAC (Data Authentication Code) a ser verificado.
 \param[in] dwParam         \ReservedParamBrief{0}

 \return \APIReturn_brief
 */
int AAP_API DVerifyDAC (
    HSESSIONCTX hSession,
    char *szIMKDAC,
    char *szPAN,
    BYTE *pbSEQ,
    BYTE *pbDAC,
    DWORD dwParam
);

/**
 Assina um SAD (Static Application Data) para cartões SDA (Static Data Authentication) gerando um SSDA (Signed Static Application Data).

 \param_hSession
 \param[in] szIK                Nome da chave privada dentro do HSM que será utilizada para assinar o SAD.
 \param[in] pbDAC               Buffer de tamanho #EFT_EMV_SDA_DAC_LEN contendo o DAC (Data Authentication Code) a ser verificado.
 \param[in] dwSDA_DATALen       Tamanho do buffer apontado por \p pbSDA_DATA .
 \param[in] pbSDA_DATA          Buffer que contém o SDA  (Static Application Data) a ser assinado de tamanho especificado em \p dwSDA_DATALen.
 \param[in,out] pdwSigLen       Ponteiro para um DWORD que contém o tamanho do buffer apontado por \p pbSig.
 \param[out] pbSig              Buffer de tamanho apontado por pdwSigLen que receberá o SSDA (Signed Static Application Data). Pode ser passado NULL para recuperar o tamanho necessário de \p pbSig, que será retornado em \p pdwSigLen.
 \param[in] dwParam             \ReservedParamBrief{0}

 \return \APIReturn_brief
 */
int AAP_API DSignSDA (
    HSESSIONCTX hSession,
    char *szIK,
    BYTE *pbDAC,
    DWORD dwSDA_DATALen,
    BYTE *pbSDA_DATA,
    DWORD *pdwSigLen,
    BYTE *pbSig,
    DWORD dwParam
);

/**
 Gera o Certificado do ICC (Integrated Circuit Card) utilizada em autenticação DDA (Dynamic Data Authentication).

 \param_hSession
 \param[in] bOP                 Tipo da operação a ser aplicada de acordo com a tabela abaixo.
                                   Valor | Signficado
                                   :-----|:----------
                                   #EFT_EMV_DDA_OP_RSA_SIGN1 | RSA + SHA1
 \param[in] szIK                Nome da chave privada dentro do HSM que será utilizada para assinar o Certificado.
 \param[in] szPAN               PAN (Primary Account Number).
 \param[in] dwDDA_DATALen       Tamanho do buffer apontado por \p pbDDA_DATA.
 \param[in] pbDDA_DATA          Buffer que contém os dados do certificado a ser assinado. Passar a estrutura descrita no [EMV Book 2 Tabelas 10 a 14](https://www.emvco.com/wp-content/uploads/2017/05/EMV_v4.3_Book_2_Security_and_Key_Management_20120607061923900.pdf), sem incluir os campos _Recovered Data Header e Trailer_.
 \param[in,out] pdwSigLen       Ponteiro para um DWORD que contém o tamanho do buffer \p pbSig.
 \param[out] pbSig              Buffer que receberá o certificado assinado. Pode ser passado NULL para recuperar o tamanho necessário de \p pbSig, que será retornado em \p pdwSigLen.
 \param[in] dwParam             \ReservedParamBrief{0}

 \return \APIReturn_brief
 */
int AAP_API DGenerateDDA_ICCCert (
    HSESSIONCTX hSession,
    BYTE bOP,
    char *szIK,
    char *szPAN,
    DWORD dwDDA_DATALen,
    BYTE *pbDDA_DATA,
    DWORD *pdwSigLen,
    BYTE *pbSig,
    DWORD dwParam
);

/**
 Gera Master Keysdo ICC (Integrated Circuit Card).

 \param_hSession
 \param[in] bOP                     Tipo da operação a ser aplicada de acordo com a tabela abaixo.
                                     Valor | Significado
                                     :-----|:-----------
                                     #EFT_EMV_GEN_ICC_MK_OP_CBC_EXP | Operação em modo CBC
                                     #EFT_EMV_GEN_ICC_MK_OP_ECB_EXP | Operação em modo ECB
 \param[in] szIK                    Nome da chave dentro do HSM que será utilizada para gerar a Master Key.
 \param[in] szKeK                   Nome da chave de transporte utilizada para encriptar a chave gerada.
 \param[in] szPAN                   PAN (Primary Account Number).
 \param[in] pbSEQ                   Buffer de tamanho #EFT_EMV_SDA_SEQ_LEN contendo o SEQ (PAN Sequence Number).
 \param[in,out] pdwEnvelopeLen      Ponteiro para um DWORD que contém o tamanho do buffer apontado por \p pbEnvelope.
 \param[out] pbEnvelope             Buffer que receberá o envelope com a chave gerada. Pode ser passado NULL para recuperar o tamanho necessário de \p pbSig, que será retornado em \p pdwEnvelopeLen.
 \param[in] dwParam                 \ReservedParamBrief{0}

 \return \APIReturn_brief
 */
int AAP_API DGenerateICCMK (
    HSESSIONCTX hSession,
    BYTE bOP,
    char *szIK,
    char *szKeK,
    char *szPAN,
    BYTE *pbSEQ,
    DWORD *pdwEnvelopeLen,
    BYTE *pbEnvelope,
    DWORD dwParam
);

/**
 \deprecated A API DGenerateEMV_MAC() é funcional e sintáticamente equivalente à API DGenerateEMV_HMAC. A referência à DGenerateEMV_HMAC continue ativa na biblioteca (internamente ela é redirecionada para DGenerateEMV_MAC() ). As aplicações que fazem chamada à DGenerateEMV_HMAC não precisam ser alteradas.

 */
int AAP_API DGenerateEMV_HMAC (
    HSESSIONCTX hSession,
    BYTE bOP,
    char *szIK,
    char *szPAN,
    BYTE *pbSEQ,
    BYTE *pbNONCE,
    DWORD dwDataLen,
    BYTE *pbData,
    BYTE *pbMAC,
    DWORD dwParam
);

/**
 Gera um criptograma padrão EMV ou MAC (Message Authentication Code), utilizado nos comandos EMV.

 \param_hSession
 \param[in] bOP                 Tipo da operação (padding, derivação de chave, etc) a ser aplicada na construção do criptograma (MAC) de acordo com a tabela abaixo.
                                     Valor | Significado
                                     :-----|:-----------
                                     #EMV_OP_ISO_9797_1_M2_COMMON | Padrão ISO 9797-1 Padding Method 2 COMMON.
                                     #EMV_OP_ISO_9797_1_M2_MCHIP | Padrão ISO 9797-1 Padding Method 2 MCHIP.
                                     #EMV_OP_ISO_9797_1_M2_VISA | Padrão ISO 9797-1 Padding Method 2 VISA.
                                     #EMV_OP_ISO_9797_1_M2_VISA_CRYPTOGRAM | Padrão ISO 9797-1 Padding Method 2 VISA_CRYPTOGRAM.
                                     #EMV_OP_ISO_9797_1_M2_RAW | Padrão ISO 9797-1 Padding Method 2 Algorithm 3.Deve ser passado NULL nos parâmetros szPAN, pbSEQ e pbNONCE.
                                     #EMV_OP_ISO_9797_1_M1_VISA_CRYPTOGRAM_PADD_V10 | Padrão ISO 9797-1 Padding Method 1 VISA.
                                     #EMV_OP_ISO_9797_1_M2_ELO | Padrão ISO 9797-1 Padding Method 2 COMMON.
									 #EMV_OP_ISO_9797_1_M2_JCB | Padrão ISO 9797-1 Padding Method 2. Como descrito em JCB IC Card Specification, Version 2.0 - October, 2012.
									 #EMV_OP_ISO_9797_1_M1_JCB | Padrão ISO 9797-1 Padding Method 1. Como descrito em JCB IC Card Specification, Version 2.0 - October, 2012.
									 #EMV_OP_ISO_9797_1_M1_JCB_CRYPTOGRAM | Padrão ISO 9797-1 Padding Method 1. Como descrito em JCB IC Card Specification, Version 2.0 - October, 2012.
 \param[in] szIK                 Nome da chave dentro do HSM que será utilizada para gerar o MAC.
 \param[in] szPAN                PAN (Primary Account Number).
 \param[in] pbSEQ                Buffer de tamanho #EFT_EMV_SDA_SEQ_LEN contendo o SEQ (PAN Sequence Number). Deve ser em formato ASCII.
 \param[in] pbNONCE              Buffer contendo o material diversificador utilizado na geração do MAC, deve ter tamanho #DES_BLOCK.
                                     Tipo da operação conforme parâmetro bOP | NONCE
                                     :---------------------------------------|:---------------------------------------
                                     #EMV_OP_ISO_9797_1_M2_COMMON | ATC (2 bytes)\|\|00\|\|00\|\|00\|\|00\|\|00\|\|00
                                     #EMV_OP_ISO_9797_1_M2_MCHIP | CVN10 e CVN11:<br>ATC (2 bytes)\|\|00\|\|00\|\|UC (<em>Unpredictable Number</em>) <br><br>CVN14 e CVN15:<br> ATC (2 bytes)\|\|00\|\|00\|\|00\|\|00\|\|00\|\|00
                                     #EMV_OP_ISO_9797_1_M2_VISA | 00\|\|00\|\|00\|\|00\|\|00\|\|00\|\|ATC (2 bytes)
                                     #EMV_OP_ISO_9797_1_M2_VISA_CRYPTOGRAM | 00\|\|00\|\|00\|\|00\|\|00\|\|00\|\|00\|\|00 <br>ou<br>NULL
                                     #EMV_OP_ISO_9797_1_M2_RAW | NULL
                                     #EMV_OP_ISO_9797_1_M1_VISA_CRYPTOGRAM_PADD_V10 | 00\|\|00\|\|00\|\|00\|\|00\|\|00\|\|00\|\|00 <br>ou<br>NULL
                                     #EMV_OP_ISO_9797_1_M2_ELO | ATC (2 bytes)\|\|00\|\|00\|\|00\|\|00\|\|00\|\|00
									 #EMV_OP_ISO_9797_1_M2_JCB | 00\|\|00\|\|00\|\|00\|\|00\|\|00\|\|ATC (2 bytes)
									 #EMV_OP_ISO_9797_1_M1_JCB | 00\|\|00\|\|00\|\|00\|\|00\|\|00\|\|ATC (2 bytes)
									 #EMV_OP_ISO_9797_1_M1_JCB_CRYPTOGRAM | 00\|\|00\|\|00\|\|00\|\|00\|\|00\|\|ATC (2 bytes)

                                 O CVN (Cryptogram Version Number) determina a versão do criptograma utilizado e depende de definições de negócio. A aplicação deve utilizar o NONCE seguindo a versão do CVN, quando aplicável.<br>Para maiores informações sobre qual CVN utilizar consulte a administradora do esquema do cartão.

 \param[in] dwDataLen            Tamanho do buffer apontado por \p pbData.
 \param[in] pbData               Buffer de tamanho especificado por \p dwDataLen contendo os dados que serão utilizados na geração do MAC. Observe que o padding será feito pelo HSM, conforme o parâmetro \p bOP, portanto a aplicação chamadora não deve fazer padding nos dados em \p pbData.
 \param[out] pbMAC               Buffer de tamanho #DES_BLOCK que conterá o MAC gerado.
 \param[in] dwParam              \ReservedParamBrief{0}

 \return \APIReturn_brief
 */
int AAP_API DGenerateEMV_MAC (
    HSESSIONCTX hSession,
    BYTE bOP,
    char *szIK,
    char *szPAN,
    BYTE *pbSEQ,
    BYTE *pbNONCE,
    DWORD dwDataLen,
    BYTE *pbData,
    BYTE *pbMAC,
    DWORD dwParam
);

/**
 Verifica o IDN (ICC Dynamic Number).

 \param_hSession
 \param[in] szIK        Nome da chave dentro do HSM que será utilizada para verificar o IDN.
 \param[in] szPAN       PAN (Primary Account Number).
 \param[in] pbSEQ       Buffer de tamanho #EFT_EMV_SDA_SEQ_LEN contendo o SEQ (PAN Sequence Number).
 \param[in] pbATC       Buffer de tamanho #EFT_EMV_IDN_ATC_LEN contendo o ATC (Application Transaction Counter).
 \param[in] pbUN        Buffer de tamanho #EFT_EMV_IDN_UN_LEN contendo o UN (Unpredictable Number).
 \param[in] pbIDN       Buffer de tamanho #EFT_EMV_IDN_LEN contendo o IDN (ICC Dynamic Number).
 \param[in] dwParam     \ReservedParamBrief{0}

 \return \APIReturn_brief
 */
int AAP_API DCheckIDN (
    HSESSIONCTX hSession,
    char *szIK,
    char *szPAN,
    BYTE *pbSEQ,
    BYTE *pbATC,
    BYTE *pbUN,
    BYTE *pbIDN,
    DWORD dwParam
);

/**
 Encripta dados em SMC (Secure Message with Confidentiality) e gera MACs (Message Authenticatino Code) em SMC/SMI (Secure Messaging for Confidentiality/Integrity).

 \param_hSession
 \param[in] bEncOP              Tipo da operação a ser aplicada de acordo com a tabela abaixo.
                                     Valor | Significado
                                     :-----|:-----------
                                     #EMV_OP_ISO_9797_1_M2_COMMON | Padrão ISO 9797-1 Method 2 COMMON.
                                     #EMV_OP_ISO_9797_1_M2_MCHIP | Padrão ISO 9797-1 Method 2 MCHIP.
                                     #EMV_OP_ISO_9797_1_M2_VISA | Padrão ISO 9797-1 Method 2 VISA.
									 #EMV_OP_ISO_9797_1_M2_ELO | Padrão ISO 9797-1 Padding Method 2 COMMON.
									 #EMV_OP_ISO_9797_1_M2_JCB | Padrão ISO 9797-1 Padding Method 2. Como descrito em JCB IC Card Specification, Version 2.0 - October, 2012.
 \param[in] szEncIK             Nome da chave dentro do HSM que será utilizada para encriptar os dados.
 \param[in] pbEncNONCE          Buffer contendo o material diversificador utilizado na encriptação dos dados, deve ter tamanho #DES_BLOCK.
 \param[in] bMacOP              Tipo da operação a ser aplicada de acordo com a tabela abaixo.
                                     Valor | Significado
                                     :-----|:-----------
                                     #EMV_OP_ISO_9797_1_M2_COMMON | Padrão ISO 9797-1 Method 2 COMMON.
                                     #EMV_OP_ISO_9797_1_M2_MCHIP | Padrão ISO 9797-1 Method 2 MCHIP.
                                     #EMV_OP_ISO_9797_1_M2_VISA | Padrão ISO 9797-1 Method 2 VISA.
									 #EMV_OP_ISO_9797_1_M2_ELO | Padrão ISO 9797-1 Padding Method 2 COMMON.
									 #EMV_OP_ISO_9797_1_M2_JCB | Padrão ISO 9797-1 Padding Method 2. Como descrito em JCB IC Card Specification, Version 2.0 - October, 2012.
									 #EMV_OP_ISO_9797_1_M1_JCB | Padrão ISO 9797-1 Padding Method 1. Como descrito em JCB IC Card Specification, Version 2.0 - October, 2012.
									 #EMV_OP_ISO_9797_1_M1_JCB_CRYPTOGRAM | Padrão ISO 9797-1 Padding Method 1. Como descrito em JCB IC Card Specification, Version 2.0 - October, 2012.
 \param[in] szMacIK             Nome da chave dentro do HSM que será utilizada para gerar o MAC.
 \param[in] pbMacNONCE          Buffer contendo o material diversificador utilizado na geração do MAC, deve ter tamanho #DES_BLOCK.
 \param[in] szPAN               PAN (Primary Account Number).
 \param[in] pbSEQ               Buffer de tamanho #EFT_EMV_SDA_SEQ_LEN contendo o SEQ (PAN Sequence Number).
 \param[in] dwDataLen           Tamanho do buffer apontado por \p pbData.
 \param[in] pbData              Buffer de tamanho especificado por dwDataLen contendo os dados que serão utilizados na encriptação/geração do MAC.
 \param[in,out] pdwEncDataLen   Ponteiro para um DWORD que contém o tamanho do buffer apontado por \p pbEncData.
 \param[out] pbEncData          Buffer que conterá os dados encriptados. Pode ser passado NULL para recuperar o tamanho necessário de \p pdwEncDataLen, que será retornado em \p pdwEncDataLen.
 \param[out] pbMAC              Buffer de tamanho #DES_BLOCK que conterá o MAC gerado. Pode ser NULL se \p szMacIK e \p pbMacNONCE forem NULL.
 \param[in] dwParam             \ReservedParamBrief{0}

 \return \APIReturn_brief
 */
int AAP_API DEncryptEMV (
    HSESSIONCTX hSession,
    BYTE bEncOP,
    char *szEncIK,
    BYTE *pbEncNONCE,
    BYTE bMacOP,
    char *szMacIK,
    BYTE *pbMacNONCE,
    char *szPAN,
    BYTE *pbSEQ,
    DWORD dwDataLen,
    BYTE *pbData,
    DWORD *pdwEncDataLen,
    BYTE *pbEncData,
    BYTE *pbMAC,
    DWORD dwParam
);

/**
 Gera CSR (Certificate Signing Request) do Emissor.

 \deprecated Utilize a API DGenerateEMV_CSREx().

 \param_hSession
 \param[in] bOP                 Tipo da operação a ser aplicada de acordo com a tabela abaixo.
                                     Valor | Significado
                                     :-----|:-----------
                                     #EFT_EMV_OP_CSR_VISA | Padrão de processo VISA. O buffer pbCSR conterá CSR + HASH. Sendo HASH de tamanho EFT_EMV_CSR_VISA_HASH_SIZE.
                                     #EFT_EMV_OP_CSR_MASTER | Padrão de processo MASTERCARD. O buffer pbCSR conterá CSR + HASH. Sendo HASH de tamanho EFT_EMV_CSR_MASTER_HASH_SIZE.
                                     #EFT_EMV_OP_CSR_ELO | Padrão de processo ELO. O buffer pbCSR conterá o CSR.
 \param[in] szIK                Nome da chave dentro do HSM que será utilizada para gerar o CSR (Chave do Emissor).
 \param[in] pbTrackNum          Buffer de tamanho #EFT_EMV_CSR_VISA_TRACK_NUM_LEN contendo o Track Number.
 \param[in] pbServiceID         Buffer de tamanho #EFT_EMV_CSR_VISA_SERVICE_ID_LEN contendo o Service ID.
 \param[in] pbIssuerID          Buffer de tamanho #EFT_EMV_CSR_VISA_ISSUER_ID_LEN contendo o Issuer ID.
 \param[in] pbExpDate           Buffer de tamanho #EFT_EXP_DATE_LEN contendo a data de expiração no formato MMYY. Deve estar no formato ASCII.
 \param[in,out] pdwCSRLen       Ponteiro para um DWORD que contém o tamanho do buffer apontado por \p pbCSR.
 \param[out] pbCSR              Buffer que conterá o CSR. Pode ser passado NULL para recuperar o tamanho necessário de \p pbCSR, que será retornado em \p pdwCSRLen.
 \param[in] dwParam             \ReservedParamBrief{0}

 \return \APIReturn_brief
 */
int AAP_API DGenerateEMV_CSR (
    HSESSIONCTX hSession,
    BYTE bOP,
    char *szIK,
    BYTE *pbTrackNum,
    BYTE *pbServiceID,
    BYTE *pbIssuerID,
    BYTE *pbExpDate,
    DWORD *pdwCSRLen,
    BYTE *pbCSR,
    DWORD dwParam
);

/**
 Gera CSR (Certificate Signing Request) do Emissor;

 \param_hSession
 \param[in] bOP                 Tipo da operação a ser aplicada de acordo com a tabela abaixo.
                                     Valor | Significado
                                     :-----|:-----------
                                     #EFT_EMV_OP_CSR_VISA | Padrão de processo VISA. O buffer \p pdbCSR conterá a CSR e \p pbHash o HASH. \p pbHash deverá ser previamente alocado com tamanho #EFT_EMV_CSR_VISA_HASH_SIZE.
                                     #EFT_EMV_OP_CSR_MASTER | Padrão de processo MASTERCARD. O buffer \p pdbCSR conterá a CSR e \p pbHash o HASH. \p pbHash deverá ser previamente alocado com #EFT_EMV_CSR_MASTER_HASH_SIZE.
                                     #EFT_EMV_OP_CSR_ELO | Padrão de processo ELO. O buffer \p pdbCSR conterá o CSR. \p pbHash deverá ser NULL e não será retornado HASH.
									 #EFT_EMV_OP_CSR_JCB | Padrão de processo JCB. O buffer \p pdbCSR conterá o CSR. \p pbHash deverá ser NULL e não será retornado HASH. Segue o padrão JCB CA Interface Guide, 04/01/2014 no file layout descrito na seção 5.1.2.2.
 \param[in] szIK                Nome da chave dentro do HSM que será utilizada para gerar o CSR (Chave do Emissor).
 \param[in] pbTrackNum          Buffer de tamanho #EFT_EMV_CSR_VISA_TRACK_NUM_LEN contendo o Track Number. Caso #EFT_EMV_OP_CSR_JCB seja definido em bOP este campo deverá conter o Serial Number de tamanho #EFT_EMV_CSR_VISA_TRACK_NUM_LEN.
 \param[in] pbServiceID         Buffer de tamanho #EFT_EMV_CSR_VISA_SERVICE_ID_LEN contendo o Service ID.
 \param[in] pbIssuerID          Buffer de tamanho #EFT_EMV_CSR_VISA_ISSUER_ID_LEN contendo o Issuer ID.
 \param[in] pbExpDate           Buffer de tamanho #EFT_EXP_DATE_LEN contendo a data de expiração no formato MMYY. Deve estar no formato ASCII.
 \param[out] pdbCSR             Ponteiro para um DBLOB que conterá o CSR e seu tamanho. O membro \p pvData deverá ser liberado com DFree() após seu uso.
 \param[out] pbHash             Buffer que conterá o HASH. Ver tabela em \b bOP para os valores esperados neste parâmetro.
 \param[in] dwParam             \ReservedParamBrief{0}

 \return \APIReturn_brief
 */
int AAP_API DGenerateEMV_CSREx (
    HSESSIONCTX hSession,
    BYTE bOP,
    char *szIK,
    BYTE *pbTrackNum,
    BYTE *pbServiceID,
    BYTE *pbIssuerID,
    BYTE *pbExpDate,
    DBLOB *pdbCSR,
    BYTE *pbHash,
    DWORD dwParam
);

/**
 Gera um segmento de dados para um comando de alteração de PIN (Personal Identification Number) a partir de PIN Blocks. Este comando é tipicamente um APDU (Application Protocol Data Unit) para um cartão ISO-7816.

 \param_hSession
 \param[in] bOP                 Identificador do tipo de derivação das chaves de operação para geração do bloco de saída. De acordo com a tabela abaixo.
                                     Valor | Significado
                                     :-----|:-----------
                                     #PBC_EMV_PIN_BLOCK_OP_MCHIP | Serão geradas chaves operacionais e o bloco de saída de acordo com o "M/Chip 4 Version 1.1 Issuer Guide, chapter 6", "M/Chip Lite 2.1 Card Application Specifications for Debit and Credit, section: 2.7 Secure Messaging" e "M/Chip 4 Version 1.1, Section 7.2.8".
                                     #PBC_EMV_PIN_BLOCK_OP_VISA | Serão geradas chaves operacionais e o bloco de saída de acordo com o "EMV book 2 v4.2, A1.4.1 option A e A1.4.2 option B", "VISA ICC specification 1.4.0 apêndice B.4/EMV Book 2 v4.2 A1.3" - para as chaves de cartão e sessão, respectivamente. "VISA ICC spec 1.4.0, B.3.3 Data Encipherment Calculation, C.11.1 PIN Data Generated Using the Current PIN e C.11.2 PIN Data Generated Without Using the Current PIN", para o bloco.
                                     #PBC_EMV_PIN_BLOCK_OP_VISA_CRYPTOGRAM | Serão geradas chaves operacionais e o bloco de saída de acordo com o "EMV book 2 v4.2, A1.4.1 option A e A1.4.2 option B" - para as chaves de cartão e sessão(a chave de sessão é igual à chave de ICC). "VISA ICC spec 1.4.0, B.3.3 Data Encipherment Calculation, C.11.1 PIN Data Generated Using the Current PIN e C.11.2 PIN Data Generated Without Using the Current PIN", para o bloco.
                                     #PBC_EMV_PIN_BLOCK_OP_ELO | Serão geradas chaves operacionais e blocos de saída de acordo com o Manual ELO Chip Card, CCD Cryptographic Algorithms, A5, seção TDES Keys Usage Algorithm (Script Processing Command Data Encryption in Change PIN script cmd), Algorithm no. 4.
									 #PBC_EMV_PIN_BLOCK_OP_JCB | Serão geradas chaves operacionais e blocos de saída de acordo com o Manual JCB IC Card Specification, Version 2.0 - October, 2012.
 \param[in] pbNONCE             Buffer contendo o material diversificador, deve ter tamanho #DES_BLOCK.
                                     Identificador usado no parâmetro bOP | NONCE
                                     :------------------------------------|:-----
                                     #PBC_EMV_PIN_BLOCK_OP_MCHIP | Codifique como determina o manual MCHIP:<br>ATC (2 bytes) \|\|00\|\|00\|\|00\|\|00\|\|00\|\|00.
                                     #PBC_EMV_PIN_BLOCK_OP_VISA | 00\|\|00\|\|00\|\|00\|\|00\|\|00\|\|ATC (2 bytes).
                                     #PBC_EMV_PIN_BLOCK_OP_VISA_CRYPTOGRAM | 00\|\|00\|\|00\|\|00\|\|00\|\|00\|\|00\|\|00.
                                     #PBC_EMV_PIN_BLOCK_OP_ELO | ATC (2 bytes)\|\|00\|\|00\|\|00\|\|00\|\|00\|\|00
									 #PBC_EMV_PIN_BLOCK_OP_JCB | 00\|\|00\|\|00\|\|00\|\|00\|\|00\|\|ATC (2 bytes). JCB IC Card Specification, Version 2.0 - October, 2012.
 \param[in] szTransportKey      Identificador da chave de transporte dentro do HSM. Esta chave deve ser do tipo DES ou 3DES.
 \param[in] szISSUER_MK         Identificador da chave "Issuer MK" dentro doHSM. Esta chave deve ser do tipo 3DES 112 bits. Esta chave pode ser igual a chave "Issuer SMC MK" em determinados casos.
 \param[in] szISSUER_SMC_MK     Identificador da chave "Issuer SMC MK" dentro do HSM. Esta chave deve ser do tipo 3DES 112 bits.
 \param[in] szPAN               PAN (Primary Account Number).
 \param[in] pbSEQ               Buffer de tamanho EFT_EMV_SDA_SEQ_LEN contendo o SEQ (PAN Sequence Number). Deve ser em formato ASCII.
 \param[in] pbOLD_PB            Buffer contendo o PIN Block com o PIN atual. O buffer deve ter o tamanho DES_BLOCK (8 bytes). Deve ser passado NULL caso o PIN Block com a senha atual não seja necessário. São suportados blocos no formato ISO 0/1/2/3.
 \param[in] pbNEW_PB            Buffer contendo o PIN Block com o novo PIN. O buffer deve ter o tamanho de um #DES_BLOCK (8 bytes). São suportados blocos no formato ISO 0/1/2/3.
 \param[out] pbOutBlock         Buffer que conterá o segmento de dados de saída. Pode se utilizar um buffer de tamanho máximo #PBC_EMV_PIN_BLOCK_MAX_OUTPUT que será suficiente para todos os casos.
 \param[in,out] pdwOutBlockLen  Ponteiro para um DWORD contendo o tamanho do buffer disponibilizado em \p pbOutPinblock. Ele conterá o tamanho dos dados escritos em \p pbOutPinblock em caso de sucesso. Em caso de falha conterá o tamanho necessário de \p pbOutPinblock.
 \param[in] dwParam              \ReservedParamBrief{0}

 \return \APIReturn_brief

 \remarks Caso o erro D_ERR_OPERATION_FAILED seja retornado, pode ser indicativo de que:
     1.	A chave de transporte esteja errada;
     2.	Os PIN Blocks de entrada sejam desconhecidos ou inválidos;
     3.	Tenha ocorrido falha na derivação das chaves de ICC ou sessão;
     4.	O tipo de operação não seja válido.
 */
int AAP_API DGenerateEMV_PinBlock (
    HSESSIONCTX hSession,
    BYTE bOP,
    BYTE *pbNONCE,
    char *szTransportKey,
    char *szISSUER_MK,
    char *szISSUER_SMC_MK,
    char *szPAN,
    BYTE *pbSEQ,
    BYTE *pbOLD_PB,
    BYTE *pbNEW_PB,
    BYTE *pbOutBlock,
    DWORD *pdwOutBlockLen,
    DWORD dwParam
);

/**


 */
int AAP_API DDeriveEMV_Key (
    HSESSIONCTX hSession,
    char *szSrcKey,
    WORD wBufferLen,
    BYTE *pbBuffer,
    BYTE bOP,
    DWORD dwAttrib,
    char *szDstKey,
    HKEYCTX *phKey,
    DWORD dwParam
);

/**
 Calcula um ARPC (Authorisation Response Cryptogram) seguindo o padrão EMV Book 2 (v4.2, 2008), Section 8.2.1, ARPC Method 1.

 \param_hSession
 \param[in] szIssuerMK          Nome da chave do emissor dentro do HSM que será utilizada para gerar o MAC.
 \param[in] szPAN               PAN (Primary Account Number).
 \param[in] pbSEQ               Buffer de tamanho #EFT_EMV_SDA_SEQ_LEN contendo o SEQ (PAN Sequence Number).
 \param[in] pbARQC              Buffer de tamanho #DES_BLOCK contendo o ARQC (Authorisation Request Cryptogram).
 \param[in] pbARC               Buffer de tamanho 2 (dois bytes) contendo o ARC (Authorisation Response Code).
 \param[out] pbARPC             Buffer de tamanho #DES_BLOCK que conterá o ARPC gerado.
 \param[in] dwParam             \ReservedParamBrief{0}

 \return \APIReturn_brief

 \remarks O cálculo do Método 2 do ARPC EMV Book 2 (v4.2, 2008), Section 8.2.1, ARPC Method 2 pode ser feito utilizando a função DGenerateEMV_MAC().
 */
int AAP_API DCalculateARPC (
    HSESSIONCTX hSession,
    char *szIssuerMK,
    char *szPAN,
    BYTE *pbSEQ,
    BYTE *pbARQC,
    BYTE *pbARC,
    BYTE *pbARPC,
    DWORD dwParam
);


#define DN_CALC_ARPC_EMV_4_2_M1_ICC		(1)
#define DN_CALC_ARPC_EMV_4_2_M1_SK		(2)
#define DN_CALC_ARPC_EMV_4_2_M2			(3)

/**
 Calcula um ARPC (Authorisation Response Cryptogram).

 \param_hSession
 \param[in] dwOp            Tipo da operação ARPC que será executada.
									Valor|Significado
                                     :----|:----------
                                     #DN_CALC_ARPC_EMV_4_2_M1_ICC | Calcula um ARPC no padrão EMV Book 2 (v4.2, 2008), Section 8.2.1, ARPC Method 1 utilizando a chave do emissor dentro do HSM. Utilizar a estrutura #DN_CALC_ARPC_EMV_METHOD_1 como parâmetro de pvInData.
                                     #DN_CALC_ARPC_EMV_4_2_M1_SK | Calcula um ARPC no padrão EMV Book 2 (v4.2, 2008), Section 8.2.1, ARPC Method 1 utilizando a chave de sessão derivada da chave do emisor dentro do HSM. Utilizar a estrutura #DN_CALC_ARPC_EMV_METHOD_1 como parâmetro de pvInData.
                                     #DN_CALC_ARPC_EMV_4_2_M2 | Calcula um ARPC no padrão EMV Book 2 (v4.2, 2008), Section 8.2.1, ARPC Method 2 utilizando a chave de sessão derivada da chave do emisor dentro do HSM. Utilizar a estrutura #DN_CALC_ARPC_EMV_METHOD_2 como parâmetro de pvInData.
 \param[in] pvInData        Dados de entrada para cálculo do ARPC, de acordo com o descrito no parâmetro \p dwOP.
 \param[out] pbARPC         Buffer de tamanho #DES_BLOCK que conterá o ARPC gerado.
 \param[in] dwParam         \ReservedParamBrief{0}

 \return \APIReturn_brief

 \remarks O cálculo do Método 2 do ARPC EMV Book 2 (v4.2, 2008), Section 8.2.1, ARPC Method 2 também pode ser feito utilizando a função DGenerateEMV_MAC().
 */
int AAP_API DCalculateARPC_Ex (	HSESSIONCTX hSession,
								DWORD dwOp,
								void *pvInData,
								BYTE *pbARPC,
								DWORD dwParam );

/**
 Gera um MAC (Message Authentication Code) no padrão ISO/IEC 9797-1 Method 2. Esta operação é feita offline na biblioteca, fora do HSM.

 \param[in] dwType       Tipo da operação a ser feita, de acordo com a tabela abaixo.
 \param[in] pbKey        Buffer contendo a chave utilizada para a geração do MAC, deve ter o tamanho referente ao tipo de chave informado em \p dwAlg.
 \param[in] dwAlg        Tipo da chave utilizada na geração do MAC.
 \param[in] pbMsg        Buffer que passará pelo processo de MAC.
 \param[in] dwMsgLen     Tamanho do buffer \p pbMsg.
 \param[out] pbMAC       Buffer que conterá o MAC gerado, deve ter tamanho #DES_BLOCK.

 \return \APIReturn_brief
 */
int AAP_API DMAC_ISO9797_1_Met2(
    DWORD dwType,
    BYTE *pbKey,
    DWORD dwAlg,
    const BYTE *pbMsg,
    DWORD dwMsgLen,
    BYTE *pbMAC
);

/**
 Importa uma chave ZMK (Zone Master Key), também conhecida como ZCMK (Zone Control Master Key) no padrão VISA. A importação é feita por partes, com os seus respectivos valores de verificação como descrito no _VISA Payment Technology Standards Manual, october 2007 Chapter 7 e Appendix C_.

\param_hSession
 \param[in] szKeyId         Nome da chave que será importada no HSM.
 \param[in] nKeyAlgId       Algoritmo da chave a ser importada.
 \param[in] pstKeyParts     Ponteiro para uma estrutura EFT_VISA_KEY_PARTS contendo as partes da chave que será importada e seus KCVs (Key Check Value).
 \param[in] dwParam         \ReservedParamBrief{0}

 \return \APIReturn_brief

 */
int AAP_API DEFTImportKey(HSESSIONCTX hSession, char *szKeyId,
                          int nKeyAlgId, EFT_VISA_KEY_PARTS *pstKeyParts,
                          DWORD dwParam);

int AAP_API DEFTExportKey(    HSESSIONCTX hSession, BYTE bExportMode,
                            char *szKEKId, char *szKeyId,
                            BYTE *pbEncryptedBlock, DWORD *pdwEncryptedBlockLen,
                            BYTE *pbKeyCheckValue, DWORD dwParam);

int AAP_API DEFTKeKImport(    HSESSIONCTX hSession, BYTE bOP, DWORD dwAlgId,
                            char *szKeKName, char *szKeyName, DWORD dwAttr,
                            BYTE *pbKCV1, BYTE *pbKCV2, BYTE *pbKCV3,
                            BYTE *pbKCVFinal, BYTE *pbBlob, DWORD dwFlags );

/* DEFTExportZPK */

#define DN_EXP_ZPK_FLAG_FULL_CKS		(1)
/**
 Exporta uma chave ZPK (Zone PIN Key) ou ZMK (Zone Master Key). A exportação é feita por partes, com os seus respectivos valores de verificação como descrito no _VISA Payment Technology Standards Manual, october 2007_.

\param_hSession
 \param[in] szKeyId         Nome da chave que será importada no HSM.
 \param[out] pnKeyAlg     Algoritmo da chave a exportada.
 \param[out] pnKeySize      Tamanho da chave exportada.
 \param[out] pstKeyParts     Ponteiro para uma estrutura EFT_VISA_KEY_PARTS que conterá as partes da chave a exportada e seus KCVs (Key Check Value).
 \param[in] dwParam         As seguintes opções são aceitas.
                            Valor|Significado
                            :----|:----------
                            0 | Gera o KCV (Key Check Value) da chave como definido na _ANSI X.9.24_ com tamanho de 3 bytes. 
                            #DN_EXP_ZPK_FLAG_FULL_CKS | Gera o KCV (Key Check Value) da chave como definido na _ANSI X.9.24_ com tamanho de 8 bytes. 

 \return \APIReturn_brief

 \remarks Pode ser utilizada para exportação de chaves que sigam o padrão de exportação por partes descrito no documento _VISA Payment Technology Standards Manual, october 2007 Chapter 7 e Appendix C_. Pode ser utilizado para chaves ZPK (Zone PIN Key), ZMK (Zone Master Key)/ZCMK (Zone Control Master Key), por exemplo. 

 */
int AAP_API DEFTExportZPK(HSESSIONCTX hSession, char *szKeyId,
                          int *pnKeyAlg, int *pnKeySize,
                          EFT_VISA_KEY_PARTS *pstKeyParts, DWORD dwParam);

/**
 \tr31ExpSummary

\param_hSession
 \param[in] szKBPK         \tr31KbpkKey
 \param[in] szKey          \tr31ExpKey
 \param[in] pvReserved     \ReservedParamBrief{NULL}
 \param[in] wUsage         \tr31ExpUsage As seguintes opções são aceitas.
 Valor | Significado
 :----|:------------
#EFT_ME_TR31_EXP_USAGE_AUTO | Define o identificador automaticamente. Os seguintes valores são utilizados: #EFT_ME_TR31_EXP_USAGE_D0 para chave simétrica e #EFT_ME_TR31_EXP_USAGE_D1 para chave assimétrica.
#EFT_ME_TR31_EXP_USAGE_B0 | BDK Base Derivation Key
#EFT_ME_TR31_EXP_USAGE_B1 | Initial DUKPT Key
#EFT_ME_TR31_EXP_USAGE_B2 | Base Key Variant Key
#EFT_ME_TR31_EXP_USAGE_C0 | CVK Card Verification Key
#EFT_ME_TR31_EXP_USAGE_D0 | Symmetric Key for Data Encryption
#EFT_ME_TR31_EXP_USAGE_D1 | Asymmetric Key for Data Encryption
#EFT_ME_TR31_EXP_USAGE_D2 | Data Encryption Key for Decimalization Table
#EFT_ME_TR31_EXP_USAGE_E0 | EMV/chip Issuer Master Key: Application cryptograms
#EFT_ME_TR31_EXP_USAGE_E1 | EMV/chip Issuer Master Key: Secure Messaging for Confidentiality
#EFT_ME_TR31_EXP_USAGE_E2 | EMV/chip Issuer Master Key: Secure Messaging for Integrity
#EFT_ME_TR31_EXP_USAGE_E3 | EMV/chip Issuer Master Key: Data Authentication Code
#EFT_ME_TR31_EXP_USAGE_E4 | EMV/chip Issuer Master Key: Dynamic Numbers
#EFT_ME_TR31_EXP_USAGE_E5 | EMV/chip Issuer Master Key: Card Personalization
#EFT_ME_TR31_EXP_USAGE_E6 | EMV/chip Issuer Master Key: Other
#EFT_ME_TR31_EXP_USAGE_I0 | Initialization Vector (IV)
#EFT_ME_TR31_EXP_USAGE_K0 | Key Encryption or wrapping
#EFT_ME_TR31_EXP_USAGE_K1 | TR-31 Key Block Protection Key
#EFT_ME_TR31_EXP_USAGE_K2 | TR-34 Asymmetric key
#EFT_ME_TR31_EXP_USAGE_K3 | Asymmetric key for key agreement/key wrapping
#EFT_ME_TR31_EXP_USAGE_M0 | ISO 16609 MAC algorithm 1 (using TDEA)
#EFT_ME_TR31_EXP_USAGE_M1 | ISO 9797-1 MAC Algorithm 1
#EFT_ME_TR31_EXP_USAGE_M2 | ISO 9797-1 MAC Algorithm 2
#EFT_ME_TR31_EXP_USAGE_M3 | ISO 9797-1 MAC Algorithm 3
#EFT_ME_TR31_EXP_USAGE_M4 | ISO 9797-1 MAC Algorithm 4
#EFT_ME_TR31_EXP_USAGE_M5 | ISO 9797-1:1999 MAC Algorithm 5
#EFT_ME_TR31_EXP_USAGE_M6 | ISO 9797-1:2011 MAC Algorithm 5/CMAC
#EFT_ME_TR31_EXP_USAGE_M7 | HMAC
#EFT_ME_TR31_EXP_USAGE_M8 | ISO 9797-1:2011 MAC Algorithm 6
#EFT_ME_TR31_EXP_USAGE_P0 | PIN Encryption
#EFT_ME_TR31_EXP_USAGE_S0 | Asymmetric key pair for digital signature
#EFT_ME_TR31_EXP_USAGE_S1 | Asymmetric key pair, CA key
#EFT_ME_TR31_EXP_USAGE_S2 | Asymmetric key pair, nonX9.24 key
#EFT_ME_TR31_EXP_USAGE_V0 | PIN verification, KPV, other algorithm
#EFT_ME_TR31_EXP_USAGE_V1 | PIN verification, IBM 3624
#EFT_ME_TR31_EXP_USAGE_V2 | PIN Verification, VISA PVV
#EFT_ME_TR31_EXP_USAGE_V3 | PIN Verification, X9.132 algorithm 1
#EFT_ME_TR31_EXP_USAGE_V4 | PIN Verification, X9.132 algorithm 2
 \param[in] bMode           \tr31ExpMode As seguintes opções são aceitas.
 Valor | Significado
 :----|:------------
#EFT_ME_TR31_EXP_MODE_AUTO | Define o identificador de modo de uso automaticamente. O seguinte valor é utilizado #EFT_ME_TR31_EXP_MODE_N.
#EFT_ME_TR31_EXP_MODE_B | Ambos Encriptação & Decriptação / Wrap & Unwrap
#EFT_ME_TR31_EXP_MODE_C | Ambos Geração & Verificação
#EFT_ME_TR31_EXP_MODE_D | Decriptação / Unwrap Apenas
#EFT_ME_TR31_EXP_MODE_E | Encriptação / Wrap Apenas
#EFT_ME_TR31_EXP_MODE_G | Geração Apenas
#EFT_ME_TR31_EXP_MODE_N | Sem restrições especiais (exceto as restrições definidas pelo identificador de uso da chave)
#EFT_ME_TR31_EXP_MODE_S | Assinatura Apenas
#EFT_ME_TR31_EXP_MODE_T | Ambos Assinatura & Decriptação
#EFT_ME_TR31_EXP_MODE_V | Verificação Apenas
#EFT_ME_TR31_EXP_MODE_X | Chave usada para derivar outra(s) chave(s)
#EFT_ME_TR31_EXP_MODE_Y | Chave usada para criar variantes de chaves

 \param[in] bExport           \tr31ExpExport As seguintes opções são aceitas.
 Valor | Significado
 :----|:------------
#EFT_ME_TR31_EXP_AUTO | Define o identificador de exportabilidade automaticamente. O seguinte valor é utilizado #EFT_ME_TR31_EXP_X9_24.
#EFT_ME_TR31_EXP_X9_24 | Exportável sob uma KEK (Key Encryption Key) em um formato de encontro com o definido nos requisitos do _X9.24 Partes 1 ou 2_.
#EFT_ME_TR31_EXP_NON_EXPORTABLE | Não exportável pelo recebedor do _Key Block_, ou local de armazenamento. Não impede a exportação de chaves derivadas de uma chave não exportável.
#EFT_ME_TR31_EXP_KEK_EXPORTABLE | Sensível, Exportável sob uma KEK (Key Encryption Key) em um formato não necessariamente de acordo com os requisitos do _X9.24 Partes 1 ou 2_.
 \param[out] pbOutBlock      Buffer que conterá o _key block_.
 \param[in,out] pdwOutBlockLen  Ponteiro para o tamanho do buffer passado \p pbOutBlock. Após o retorno da API conterá o tamanho real do _key block_ armazenado em \p pbOutBlock. Caso o tamanho não seja o suficiente, essa variável conterá o tamanho necessário de \p pbOutBlock.
 \param[in] dwParam             \ReservedParamBrief{0}

 \return \APIReturn_brief

 \remarks Essa API exporta uma chave usando os métodos de geração de _key_block_ abaixo.
 Algoritmo da KBPK | Método de exportação
 :----|:------------
 3DES | 5.3.2.1 Key Derivation Binding Method - TDEA
 AES | 5.3.2.3 Key Block Binding Method – AES
 */
int AAP_API DEFTExportTR31(HSESSIONCTX hSession,
                           const char *szKBPK,
                           const char *szKey,
                           void *pvReserved,
                           WORD wUsage,
                           BYTE bMode,
                           BYTE bExport,
                           BYTE *pbOutBlock,
                           DWORD *pdwOutBlockLen,
                           DWORD dwParam);

/**
 \tr31ImpDescription

\param_hSession
 \param[in] szKBPK          \tr31KbpkKey
 \param[in] szKey           \tr31ImpKey
 \param[in] dwKeyAttributes Parâmetros adicionais da chave. Veja as opções na função DGenerateKey().
 \param[in] pbKeyBlock      Buffer contendo o _key block_.
 \param[in] dwKeyBlockLen   Tamanho do buffer passado \p pbKeyBlock.
 \param[in] dwParam         \ReservedParamBrief{0}

 \return \APIReturn_brief

 \remarks Essa API importa chaves protegidas pelos métodos de geração do _key_block_.
 Algoritmo da KBPK | Método
 :----|:------------
 3DES | 5.3.2.1 Key Derivation Binding Method - TDEA
 AES | 5.3.2.3 Key Block Binding Method – AES
 */
int AAP_API DEFTImportTR31(HSESSIONCTX hSession,
                           const char *szKBPK,
                           const char *szKey,
                           DWORD dwKeyAttributes,
                           BYTE *pbKeyBlock,
                           DWORD dwKeyBlockLen,
                           DWORD dwParam);
/** @} End of EFT grouping */

/* Digital signature */

int AAP_API DPowerSignHash(HSESSIONCTX hSession, char *szKeyId,
                           int nHashAlgId, DWORD dwDataLen,
                           BYTE *pbDataBuffer, DWORD *pdwSignLen,
                           BYTE **ppbSignData);

/**
 \addtogroup pkcs7

 @{ */

/**
 Gera uma assinatura ou co-assinatura seguindo o padrão PKCS\#7 (Cryptographic Message Syntax Standard).

 \param_hSession
 \param[in] szKeyName           Nome da chave dentro do HSM que será utilizada para fazer a assinatura.
 \param[in] szKeyCert           Nome do certificado (correspondente a chave szKeyName) dentro do HSM que será utilizado na assinatura.
 \param[in] szCerts             Nome da cadeia de certificados (PKCS\#7) ou certificado X.509 da Autoridade Certificadora (correspondente a chave szKeyName) dentro do HSM que será utilizada na assinatura.
 \param[in] dwAttrib            Flag contendo as opções de assinatura.
                                     Valor|Significado
                                     :----|:----------
                                     #TAC_MOD_CORE_P7_TEXT | Incluir cabeçalho MIME de texto.
                                     #TAC_MOD_CORE_P7_NOCERTS | Não incluir certificado de assinatura.
                                     #TAC_MOD_CORE_P7_DETACHED | Gerar assinatura separada.
                                     #TAC_MOD_CORE_P7_BINARY | Tratar arquivo como binário sem tradução de MIME type.
                                     #TAC_MOD_CORE_P7_NOATTR | Não utilizar atributos de autenticação.
                                     #TAC_MOD_CORE_P7_NOSMIMECAP | Omitir S/MIME Capabilities.
                                     #TAC_MOD_CORE_P7_COSIGN | Gera uma co-assinatura. Este flag só deve usada se o conteúdo em pbContent for um pacote PKCS\#7 assinado (formato DER), assim é acrescentada uma nova assinatura.
 \param[in] pbContent           Buffer contendo os dados que serão assinados. Seu tamanho deve ser especificado em dwContentLen.
 \param[in] dwContentLen        Tamanho do buffer em bytes passado em pbContent.
 \param[out] pdwSignatureLen    Ponteiro para o tamanho em bytes do buffer ppbSignature.
 \param[out] ppbSignature       Ponteiro para um ponteiro que receberá a assinatura PKCS\#7 (formato DER). Este ponteiro deverá ser liberado após seu uso com DFree().
 \param[in] dwParam             \ReservedParamBrief{0}

 \return \APIReturn_brief

 \remarks Para gerar uma mensagem PKCS\#7 com co-assinatura, o chamador deve submeter em pbContent uma mensagem PKCS\#7 assinada (em formato DER). Este processo deve ser repetido  iterativamente tantas vezes quantas forem as co-assinaturas necessárias. Ao fazer uma co-assinatura a flag #TAC_MOD_CORE_P7_NOATTR é automaticamente desabilitada. \par
 O padrão adotado é o PKCS\#7  v. 1.5.
 */
int AAP_API DPKCS7Sign (
    HSESSIONCTX hSession,
    char *szKeyName,
    char *szKeyCert,
    char *szCerts,
    DWORD dwAttrib,
    BYTE *pbContent,
    DWORD dwContentLen,
    DWORD *pdwSignatureLen,
    BYTE **ppbSignature,
    DWORD dwParam
);

/** @} End of PKCS7 grouping */


/* (CNS) Social Connectivity */
int AAP_API DGenerateCNSCert (    HSESSIONCTX hSession,
                                char *szKeyID, char *szUsrID, char *szUsrName,
                                WORD wModulusLen, BYTE *pbModulus,
                                BYTE bExponentLen, BYTE *pbExponent,
                                DWORD *pdwCertLen, BYTE *pbCert, DWORD dwParam );

/* Hash */
int AAP_API DSignHashedData(    HKEYCTX hKey, BYTE *pbData, DWORD dwDataLen,
                                int nHashId, DWORD dwFlags, BYTE* pbSignature,
                                DWORD* pdwSigLen );

BOOL DDoRSAPadding(	HSESSIONCTX hSession,
					DWORD dwPadding,
					BYTE*pbBlock,
					BYTE *pbData,
					DWORD* pdwDataLen,
					DWORD dwBlockSize,
					DWORD dwFlag );

int AAP_API DBatchSign(	HKEYCTX hKey,
						BYTE *pbBlock,
						DWORD dwBlockCount,
						DWORD dwFlags );

/* Base64 */

char * AAP_API DByteArray2Base64(	BYTE *pbData,
									DWORD dwDataLen,
									char *szBase64,
									DWORD *pdwBase64Len,
									BOOL bNoNewLines );

BYTE * AAP_API DBase642ByteArray(	char *szBase64,
									DWORD dwBase64Len,
									BYTE *pbData,
									DWORD *pdwDataLen);


/**
 \addtogroup xml

 @{ */

/**

\deprecated Esta API está descontinuada, use a função DSignXml2().

 Assina digitalmente um documento XML usando os padrões de assinatura digital XML do W3C e RFC 3275.

 \param[in] hKey                    Contexto da chave privada a ser utilizada na assinatura.
 \param[in] hHash                   Contexto de hash gerado pela função DCreateHash().
 \param[in] szCertId                Nome do certificado digital equivalente utilizado para assinatura do documento XML.
 \param[in] dwSizeUnsignedXml       Tamanho, em bytes, do XML original em \p pbUnsignedXml.
 \param[in] pbUnsignedXml           Buffer contendo o XML original.
 \param[in] dwFilterLen             Tamanho, em bytes, do filtro indicado por \p pbFilter.
 \param[in] pbFilter                Filtro para assinatura digital de partes do documento. A utilização de filtro é opcional. Caso não utilize filtros, passe 0 (zero) em \p dwFilterLen. Consulte observações para maiores informações sobre filtros.
 \param[out] pdwSizeSignedXml       Ponteiro para o tamanho do XML assinado, em bytes. Quando a função retorna, esse parâmetro conterá o tamanho dos dados armazenados em \p ppbSignedXml.
 \param[out] ppbSignedXml           Ponteiro de ponteiro com o retorno para o XML assinado. A alocação de memória é feita internamente. A aplicação chamadora é responsável por liberar a memória alocada usando a API DFree(). Consulte observações para maiores informações.

 \return \APIReturn_brief

 \remark Não é necessário indicar o contexto da sessão. O mesmo é obtido por intermédio de \p hKey.

O buffer \p ppbSignedXml para retorno do XML assinado será alocado internamente. A aplicação deverá fazer a liberação da memória usando a API DFree().
A função DSignXml() irá retornar [D_ERR_INVALID_CERTIFICATE](https://docs.hsm.dinamonetworks.io/codigos-retorno/hsm_codes_pt_br#err_invalid_certificate) caso o certificado digital indicado não seja correspondente com a chave \p hKey. Se o XML original não estiver bem formado, a função irá retornar [D_ERR_CANNOT_ALLOC_RES](https://docs.hsm.dinamonetworks.io/codigos-retorno/hsm_codes_pt_br#err_cannot_alloc_res).\par

A representação física ou forma canônica usada na assinatura está de acordo com a recomendação W3C, Versão 1.0 de 15 Março de 2001 (http://www.w3.org/TR/2001/REC-xml-c14n-20010315). As transformações usadas na assinatura (Enveloped e C14N) estão de acordo com a seção 6.6.4 da recomendação XML W3C de 12 de fevereiro de 2002 - Enveloped Signature Transform (http://www.w3.org/2000/09/xmldsig#enveloped-signature) e com a canonicalização descrita anteriormente (http://www.w3.org/TR/2001/REC-xml-c14n-20010315).\par

É possível realizar assinatura digital de parte do XML, através de filtros, utilizando os parâmetros \p dwFilterLen e \p pbFilter.

O filtro adota o seguinte formato: <tt>namespace|qualificador|id</tt>. O caracter separador é o <tt>|</tt> (pipe). O \p namespace é aquele definido no atributo xmlns, o \p qualificador pode estar presente em mais de uma tag e o \p id deve ser único no documento. Um filtro vazio indica que a assinatura abrange todo o documento. A construção de um filtro válido depende da estrutura do XML. \par

Num XML onde o namespace está definido os filtros válidos são:
 - <tt>""</tt> (sem URI)
 - <tt>#XML_FILTER_NULL_URI</tt> (gera URI nulo)
 - <tt>"namespace|qualificador|id"</tt>

Num XML sem definição de namespace os filtros válidos são:
 - <tt>""</tt> (sem URI)
 - <tt>#XML_FILTER_NULL_URI</tt> (gera URI nulo)
 - <tt>"|qualificador|id"</tt>

<br>

Exemplo de XML com namespace:

```
<?xml version="1.0"?>
<NFe xmlns="http://www.portalfiscal.inf.br/nfe">
<infNFe Id="XFGR143576863578" versao="1.01">
...
</infNFe>
</NFe>
```
Neste exemplo o namespace é <tt>http://www.portalfiscal.inf.br/nfe</tt>, o qualificador da tag é <tt>infNFe</tt> e o id é <tt>XFGR143576863578</tt>.

Filtros válidos:
 - <tt>""</tt> (sem URI)
 - <tt>"http://www.portalfiscal.inf.br/nfe|infNFe|XFGR143576863578"</tt>

 <br>

Exemplo de XML sem namespace:

```
<?xml version="1.0"?>
<NFe>
<infNFe Id="XFGR143576863578" versao="1.01">
...
</infNFe>
</NFe>
```
Neste exemplo não há namespace (campo vazio no filtro), o qualificador da tag é \p infNFe e o \p id é XFGR143576863578. Note a presença do primeiro separador para marcar o namespace vazio.

Filtros válidos:
 - <tt>""</tt> (sem URI)
 - <tt>#XML_FILTER_NULL_URI</tt> (gera URI nulo)
 - <tt>"|infNFe|XFGR143576863578"</tt>

*/

int AAP_API DSignXml(
    HKEYCTX hKey,
    HHASHCTX hHash,
    char *szCertId,
    DWORD dwSizeUnsignedXml,
    BYTE *pbUnsignedXml,
    DWORD dwFilterLen,
    BYTE *pbFilter,
    DWORD *pdwSizeSignedXml,
    BYTE **ppbSignedXml
);

/**

 Assina digitalmente um documento XML usando os padrões de assinatura digital XML do W3C e RFC 3275.

 \param_hSession
 \param[in] bHashMode               Tipo de hash utilizado na assinatura. Os valores da tabela abaixo são aceitos.
 Valor|Significado
:----|:----
#ALG_MD5_InclC14N                |  MD5 com canonicalização InclC14N
#ALG_SHA1_InclC14N               |  SHA1 com canonicalização InclC14N
#ALG_SHA256_InclC14N             |  SHA256 com canonicalização InclC14N
#ALG_SHA384_InclC14N             |  SHA384 com canonicalização InclC14N
#ALG_SHA512_InclC14N             |  SHA512 com canonicalização InclC14N
#ALG_SHA224_InclC14N             |  SHA224 com canonicalização InclC14N
#ALG_MD5_ExclC14N                |  MD5 com canonicalização ExclC14N
#ALG_SHA1_ExclC14N               |  SHA1 com canonicalização ExclC14N
#ALG_MD5_InclC14NWithComments    |  MD5 com canonicalização InclC14NWithComments
#ALG_SHA1_InclC14NWithComments   |  SHA1 com canonicalização InclC14NWithComments
#ALG_MD5_ExclC14NWithComments    |  MD5 com canonicalização ExclC14NWithComments
#ALG_SHA1_ExclC14NWithComments   |  SHA1 com canonicalização ExclC14NWithComments
#ALG_SHA256_ExclC14N             |  SHA256 com canonicalização ExclC14N
#ALG_SHA256_InclC14NWithComments  |  SHA256 com canonicalização InclC14NWithComment
#ALG_SHA256_ExclC14NWithComments  |  SHA256 com canonicalização ExclC14NWithComment
#ALG_SHA384_ExclC14N             |  SHA384 com canonicalização ExclC14N
#ALG_SHA384_InclC14NWithComments  |  SHA384 com canonicalização InclC14NWithComment
#ALG_SHA384_ExclC14NWithComments  |  SHA384 com canonicalização ExclC14NWithComment
#ALG_SHA512_ExclC14N             |  SHA512 com canonicalização ExclC14N
#ALG_SHA512_InclC14NWithComments  |  SHA512 com canonicalização InclC14NWithComment
#ALG_SHA512_ExclC14NWithComments  |  SHA512 com canonicalização ExclC14NWithComment
#ALG_SHA224_ExclC14N             |  SHA224 com canonicalização ExclC14N
#ALG_SHA224_InclC14NWithComments  |  SHA224 com canonicalização InclC14NWithComment
#ALG_SHA224_ExclC14NWithComments  |  SHA224 com canonicalização ExclC14NWithComment

\param[in] dwFlags					Flags contendo as opções de assinatura. A tabela abaixo é aceita.
									Valor|Significado
									 :----|:----------
									 #XML_SIGN_FLAGS_NOL| Desabilita a geração de XML de apenas 1 linha("single line"). Esta opção gera o XML de saída em múltiplas linhas.
									 #XML_SIGN_FLAGS_NO_RNS| Desabilita o uso de namespaces relativos.
 \param[in] szKeyId                 Nome da chave privada utilizada para assinatura.
 \param[in] szCertId                Nome do certificado digital equivalente utilizado para assinatura do documento XML.
 \param[in] dwSizeUnsignedXml       Tamanho, em bytes, do XML original em \p pbUnsignedXml.
 \param[in] pbUnsignedXml           Buffer contendo o XML original.
 \param[in] dwFilterLen             Tamanho, em bytes, do filtro indicado por \p pbFilter.
 \param[in] pbFilter                Filtro para assinatura digital de partes do documento. A utilização de filtro é opcional. Caso não utilize filtros, passe 0 (zero) em \p dwFilterLen. Consulte observações para maiores informações sobre filtros.
 \param[out] pdwSizeSignedXml       Ponteiro para o tamanho do XML assinado, em bytes. Quando a função retorna, esse parâmetro conterá o tamanho dos dados armazenados em \p ppbSignedXml.
 \param[out] ppbSignedXml           Ponteiro de ponteiro com o retorno para o XML assinado. A alocação de memória é feita internamente. A aplicação chamadora é responsável por liberar a memória alocada usando a API DFree(). Consulte observações para maiores informações.

 \return \APIReturn_brief

 \remark Não é necessário indicar o contexto da sessão. O mesmo é obtido por intermédio de \p hKey.

O buffer \p ppbSignedXml para retorno do XML assinado será alocado internamente. A aplicação deverá fazer a liberação da memória usando a API DFree().
A função DSignXml() irá retornar [D_ERR_INVALID_CERTIFICATE](https://docs.hsm.dinamonetworks.io/codigos-retorno/hsm_codes_pt_br#err_invalid_certificate) caso o certificado digital indicado não seja correspondente com a chave \p hKey. Se o XML original não estiver bem formado, a função irá retornar [D_ERR_CANNOT_ALLOC_RES](https://docs.hsm.dinamonetworks.io/codigos-retorno/hsm_codes_pt_br#err_cannot_alloc_res).\par

A representação física ou forma canônica usada na assinatura está de acordo com a recomendação W3C, Versão 1.0 de 15 Março de 2001 (http://www.w3.org/TR/2001/REC-xml-c14n-20010315). As transformações usadas na assinatura (Enveloped e C14N) estão de acordo com a seção 6.6.4 da recomendação XML W3C de 12 de fevereiro de 2002 - Enveloped Signature Transform (http://www.w3.org/2000/09/xmldsig#enveloped-signature) e com a canonicalização descrita anteriormente (http://www.w3.org/TR/2001/REC-xml-c14n-20010315).\par

É possível realizar assinatura digital de parte do XML, através de filtros, utilizando os parâmetros \p dwFilterLen e \p pbFilter.

O filtro adota o seguinte formato: <tt>namespace|qualificador|id</tt>. O caracter separador é o <tt>|</tt> (pipe). O \p namespace é aquele definido no atributo xmlns, o \p qualificador pode estar presente em mais de uma tag e o \p id deve ser único no documento. Um filtro vazio indica que a assinatura abrange todo o documento. A construção de um filtro válido depende da estrutura do XML. \par

Num XML onde o namespace está definido os filtros válidos são:
 - <tt>""</tt> (sem URI)
 - <tt>#XML_FILTER_NULL_URI</tt> (gera URI nulo)
 - <tt>"namespace|qualificador|id"</tt>

Num XML sem definição de namespace os filtros válidos são:
 - <tt>""</tt> (sem URI)
 - <tt>#XML_FILTER_NULL_URI</tt> (gera URI nulo)
 - <tt>"|qualificador|id"</tt>

<br>

Exemplo de XML com namespace:

```
<?xml version="1.0"?>
<NFe xmlns="http://www.portalfiscal.inf.br/nfe">
<infNFe Id="XFGR143576863578" versao="1.01">
...
</infNFe>
</NFe>
```
Neste exemplo o namespace é <tt>http://www.portalfiscal.inf.br/nfe</tt>, o qualificador da tag é <tt>infNFe</tt> e o id é <tt>XFGR143576863578</tt>.

Filtros válidos:
 - <tt>""</tt> (sem URI)
 - <tt>#XML_FILTER_NULL_URI</tt> (gera URI nulo)
 - <tt>"http://www.portalfiscal.inf.br/nfe|infNFe|XFGR143576863578"</tt>

 <br>

Exemplo de XML sem namespace:

```
<?xml version="1.0"?>
<NFe>
<infNFe Id="XFGR143576863578" versao="1.01">
...
</infNFe>
</NFe>
```
Neste exemplo não há namespace (campo vazio no filtro), o qualificador da tag é \p infNFe e o \p id é XFGR143576863578. Note a presença do primeiro separador para marcar o namespace vazio.

Filtros válidos:
 - <tt>""</tt> (sem URI)
 - <tt>#XML_FILTER_NULL_URI</tt> (gera URI nulo)
 - <tt>"|infNFe|XFGR143576863578"</tt>

*/
int AAP_API DSignXml2(HSESSIONCTX hSession,
					BYTE bHashMode,
					DWORD dwFlags,
					const char *szKeyId,
					const char *szCertId,
					DWORD dwSizeUnsignedXml,
					BYTE *pbUnsignedXml,
					DWORD dwFilterLen,
					BYTE *pbFilter,
					DWORD *pdwSizeSignedXml,
					BYTE **ppbSignedXml);

/**
 Verifica a assinatura de um documento XML assinado digitalmente usando os padrões de assinatura digital XML do W3C e RFC 3275.

 \deprecated As aplicações devem utilizar a API estendida DVerifySignedXmlEx(), que faz a verificação do documento XML assinado consultando uma lista indicada de certificados revogados.
 */
int AAP_API DVerifySignedXml ( HSESSIONCTX hSession, char *szCertsId,
                              DWORD dwSizeSignedXml, BYTE *pbSignedXml,
                              DWORD dwFilterLen, BYTE *pbFilter);

/**
 Verifica a assinatura de um documento XML assinado digitalmente usando os padrões de assinatura digital XML do W3C e RFC 3275.

 \param_hSession
 \param[in] szCertsId           Nome da cadeia PKCS#7 – armazenada internamente no HSM - do certificado utilizado na assinatura do documento XML.
 \param[in] dwSizeSignedXml     Tamanho, em bytes, do XML assinado em \p pbSignedXml.
 \param[in] pbSignedXml         XML assinado.
 \param[in] dwFilterLen         Tamanho, em bytes, do filtro indicado por \p pbFilter.
 \param[in] pbFilter            Filtro para assinatura digital de partes do documento XML. Consulte observações para maiores informações.
 \param[in] szCRL               \pixSigVerifyCRL

 \return \APIReturn_brief

 \remark A função DVerifySignedXmlEx() irá retornar [ERR_VERIFY_XML_FAILED](https://docs.hsm.dinamonetworks.io/codigos-retorno/hsm_codes_pt_br#err_verify_xml_failed) caso a assinatura digital não esteja válida ou correta. Se o XML assinado não estiver bem formado, a função irá retornar [ERR_INVALID_XML](https://docs.hsm.dinamonetworks.io/codigos-retorno/hsm_codes_pt_br#err_invalid_xml).\par

É possível realizar a verificação da assinatura digital de parte do XML, através de filtros, utilizando os parâmetros \p dwFilterLen e \p pbFilter. Veja as anotações sobre filtros na API DSignXml(). Se um XML foi assinado com filtro a verificação deve indicar o mesmo filtro.

 \see DSignXml() .
 */
int AAP_API DVerifySignedXmlEx (
    HSESSIONCTX hSession,
    char *szCertsId,
    DWORD dwSizeSignedXml,
    BYTE *pbSignedXml,
    DWORD dwFilterLen,
    BYTE *pbFilter,
    char *szCRL
);

/** @} End of XML grouping*/


/**
 \addtogroup pix

 @{ */

 /**

  Assina digitalmente um XML no formato ISO 20.022 seguindo o padrão PIX definido no SPI (Sistema de Pagamentos Instantâneos).

  \param_hSession
  \param[in] szKeyId						\pixCPIAKey
  \param[in] szCertId						\pixCPIACert
  \param[in] dwFlags						Opções de assinatura. Passar 0. Caso precise de alguma opção adicional os 
  seguintes valores são aceitos.
  Valor|Significado
:----|:----
#PIX_SIGN_RNS                |  Habilita o uso de namespaces relativas.
  \param[in] dwSizeUnsignedPIXEnvelope       Tamanho, em bytes, do XML original em \p pbUnsignedPIXEnvelope.
  \param[in] pbUnsignedPIXEnvelope           Buffer contendo o XML original.
  \param[out] pdwSizeSignedPIXEnvelope       Ponteiro para o tamanho do XML assinado, em bytes. Quando a função retorna, esse parâmetro conterá o tamanho dos dados armazenados em \p ppbSignedPIXEnvelope.
  \param[out] ppbSignedPIXEnvelope           Ponteiro de ponteiro com o retorno para o XML assinado. A alocação de memória é feita internamente. A aplicação chamadora é responsável por liberar a memória alocada usando a API DFree(). Consulte observações para maiores informações.

  \return \APIReturn_brief

  \remarks
  Recomendamos utilizar a tag de assinatura utilizando o fechamento completo, como visto abaixo, por motivos de performance.
  \code{.xml}<Sgntr></Sgntr>\endcode
  A tag com fechamento simples também é aceita, ver abaixo.
  \code{.xml}<Sgntr/>\endcode

 */
int AAP_API DPIXSign(HSESSIONCTX hSession,
					const char *szKeyId,
					const char *szCertId,
					DWORD dwFlags,
					DWORD dwSizeUnsignedPIXEnvelope,
					BYTE *pbUnsignedPIXEnvelope,
					DWORD *pdwSizeSignedPIXEnvelope,
					BYTE **ppbSignedPIXEnvelope);


/**
Verifica a assinatura de um documento XML assinado digitalmente no formato ISO 20.022 seguindo o padrão PIX definido no SPI (Sistema de Pagamentos Instantâneos).

  \param_hSession
  \param[in] szChainId						\pixSigVerifyChain
  \param[in] szCRL							\pixSigVerifyCRL
  \param[in] dwFlags						\ReservedParamBrief{0}
  \param[in] dwSizeSignedPIXEnvelope		Tamanho, em bytes, do XML assinado em \p pbSignedPIXEnvelope.
  \param[in] pbSignedPIXEnvelope			XML assinado.

  \return \APIReturn_brief

 */
int AAP_API DPIXVerify(HSESSIONCTX hSession,
						const char *szChainId,
						const char *szCRL,
						DWORD dwFlags,
						DWORD dwSizeSignedPIXEnvelope,
						BYTE* pbSignedPIXEnvelope);

/**

 Assina digitalmente um XML no formato XMLDSig seguindo o padrão DICT definido no SPI (Sistema de Pagamentos Instantâneos).

 \param_hSession
 \param[in] szKeyId							\pixCPIAKey
 \param[in] szCertId						\pixCPIACert
 \param[in] dwFlags							\ReservedParamBrief{0}
 \param[in] dwSizeUnsignedDictEnvelope       Tamanho, em bytes, do XML original em \p pbUnsignedDictEnvelope.
 \param[in] pbUnsignedDictEnvelope           Buffer contendo o XML original.
 \param[out] pdwSizeSignedDictEnvelope       Ponteiro para o tamanho do XML assinado, em bytes. Quando a função retorna, esse parâmetro conterá o tamanho dos dados armazenados em \p ppbSignedDictEnvelope.
 \param[out] ppbSignedDictEnvelope           Ponteiro de ponteiro com o retorno para o XML assinado. A alocação de memória é feita internamente. A aplicação chamadora é responsável por liberar a memória alocada usando a API DFree(). Consulte observações para maiores informações.

 \return \APIReturn_brief

 \remarks
 Não incluir a tag de assinatura, ela será adicionada automaticamente.

*/
int AAP_API DPIXDictSign(HSESSIONCTX hSession,
						 const char *szKeyId,
						 const char *szCertId,
						 DWORD dwFlags,
						DWORD dwSizeUnsignedDictEnvelope,
						BYTE *pbUnsignedDictEnvelope,
						DWORD *pdwSizeSignedDictEnvelope,
						BYTE **ppbSignedDictEnvelope);


/**
Verifica a assinatura de um documento XML assinado digitalmente no formato XMLDSig seguindo o padrão DICT definido no SPI (Sistema de Pagamentos Instantâneos).

  \param_hSession
  \param[in] szChainId						\pixSigVerifyChain
  \param[in] szCRL							\pixSigVerifyCRL
  \param[in] dwFlags						\ReservedParamBrief{0}
  \param[in] dwSizeSignedDictEnvelope		Tamanho, em bytes, do XML assinado em \p pbSignedDictEnvelope.
  \param[in] pbSignedDictEnvelope			XML assinado.

  \return \APIReturn_brief

 */
int AAP_API DPIXDictVerify(HSESSIONCTX hSession,
						   const char *szChainId,
						   const char *szCRL,
						   DWORD dwFlags,
						   DWORD dwSizeSignedDictEnvelope,
						   BYTE* pbSignedDictEnvelope);

/**

  \pixJWSSignAPIDescription

  \param_hSession
  \param[in] szKeyId						\pixJWSKey
  \param[in] dwFlags						Opções de assinatura. Deve ser passado 0.
  \param[in] dwHeaderLen					Tamanho, em bytes, do Header JWS em \p pbHeader.
  \param[in] pbHeader						\pixJWSSignHeader Valores aceitos para _alg_.
  Valor|Significado
	:----|:----------
RS256 | RSA 2048 PKCS#1v5
RS384 | RSA 3072 PKCS#1v5
RS512 | RSA 4096 PKCS#1v5
PS256 | RSA 2048 PSS 
PS384 | RSA 3072 PSS 
PS512 | RSA 4096 PSS 
ES256 | ECC SECP256R1
ES384 | ECC SECP384R1
ES512 | ECC SECP521R1
  
  \param[in] dwPayloadLen					Tamanho, em bytes, do Payload JWS em \p pbPayload.
  \param[in] pbPayload						Buffer contendo o Payload JWS para assinatura.
  \param[in,out] pdwJWSLen					Ponteiro para o tamanho do buffer \p pbJWS, em bytes. Quando a função retorna, esse parâmetro conterá o tamanho dos dados armazenados em \p pbJWS.
  \param[out] pbJWS							Buffer que conterá o JWS assinado. Se for passado NULL a API retornará 0 e \p pdwJWSLen conterá o tamanho necessário estimado de \p pbJWS.

  \return \APIReturn_brief

  \remarks
  Utiliza o formato _Compact Serialization_ descrito na Section-3.1 da [RFC 7515](https://tools.ietf.org/html/rfc7515#section-3.1).

 */
int AAP_API DPIXJWSSign(HSESSIONCTX hSession,
						const char *szKeyId,
						DWORD dwFlags,
						DWORD dwHeaderLen,
						BYTE *pbHeader,
						DWORD dwPayloadLen,
						BYTE *pbPayload,
						DWORD *pdwJWSLen,
						BYTE *pbJWS);

/**
  \pixJWSCheckAPIDescription

  \param_hSession
  \param[in] szChain						\pixSigVerifyChain
  \param[in] szCRL							\pixSigVerifyCRL
  \param[in] dwJWSLen						Tamanho, em bytes, da assinatura JWS em \p pbJWS.
  \param[in] pbJWS							JWS assinado.
  \param[in] dwFlags						Opções de validação. Deve ser passado 0.
  \param[in,out] pdwHeaderLen				Ponteiro para o tamanho do buffer \p pbHeader, em bytes. Quando a função retorna, esse parâmetro conterá o tamanho dos dados armazenados em \p pbHeader.
  \param[out] pbHeader						Buffer que conterá o Header do JWS. Se for passado NULL a API retornará 0 e \p pdwHeaderLen conterá o tamanho necessário estimado de \p pbHeader.
  \param[in,out] pdwPayloadLen				Ponteiro para o tamanho do buffer \p pbPayload, em bytes. Quando a função retorna, esse parâmetro conterá o tamanho dos dados armazenados em \p pbPayload.
  \param[out] pbPayload						Buffer que conterá o Payload do JWS. Se for passado NULL a API retornará 0 e \p pdwPayloadLen conterá o tamanho necessário estimado de \p pbPayload.

  \return \APIReturn_brief

 */
int AAP_API DPIXJWSCheck(HSESSIONCTX hSession,
						 const char *szChain,
						 const char *szCRL,
						 DWORD dwJWSLen,
						 BYTE *pbJWS,
						 DWORD dwFlags,
						 DWORD *pdwHeaderLen,
						 BYTE *pbHeader,
						 DWORD *pdwPayloadLen,
						 BYTE *pbPayload);

/**

  Faz uma requisição segura HTTP POST seguindo o padrão PIX definido no SPI (Sistema de Pagamentos Instantâneos).

  \pixRequestImportant

  \param_hSession
  \param[in] szKeyId					\pixCPICKey
  \param[in] szCertId				    \pixCPICCert	
  \param[in] szPIXCertChainId			\pixICOMChain
  \param[in] szURL						\pixICOMURL
  \param[in] dwCountRequestHeaderList	Quantidade de linhas preenchidas em \p pszRequestHeaderList.
  \param[in] pszRequestHeaderList		\pixHeaderEditingInfo
  \pixPostDefaultHeader
  \param[in] dwSizeRequestData			Tamanho dos dados passados em \p pbRequestData.
  \param[in] pbRequestData				Dados enviados na requisição.
  \param[in] dwTimeOut					Tempo de timeout da operação em milisegundos. Pode ser passado 0 para não ter tempo de timeout.
  \param[out] pdwSizeResponseHeaders	Ponteiro que conterá o tamanho dos dados armazenados no buffer \p ppbResponseHeaders, em bytes.
  \param[out] ppbResponseHeaders		Buffer alocado internamente que conterá o _header_ retornado pela requisição. O tamanho alocado estará definido em \p pdwSizeResponseHeaders. Este ponteiro deverá ser liberado utilizando a API DFree().
  \param[out] pdwSizeResponseBody		Ponteiro que conterá o tamanho dos dados armazenados no buffer \p ppbResponseBody, em bytes.
  \param[out] ppbResponseBody			Buffer alocado internamente que conterá o _body_ retornado pela requisição. O tamanho alocado estará definido em \p pdwSizeResponseBody. Este ponteiro deverá ser liberado utilizando a API DFree().
  \param[in] dwParam
  Valor|Significado
	:----|:----------
	0| Opção padrão. Não verifica o certificado com o nome do host.
	#PIX_VERIFY_HOST_NAME| Verifica certificado com o nome do host.
    #PIX_BASIC_HTTP_HEADER | Usa o header HTTP inicial básico. \pixPostPutBasicHeader
    #PIX_GZIP | Faz a compressão gzip automática dos dados de requisição. Inclui automaticamente os headers necessários (Content-Encoding e Accept-Encoding).

  \return \APIReturn_brief

  \remarks

  \pixRequestRemarks
 

  \see DFree() DPIXGet() DPIXDelete()
 */
int AAP_API DPIXPost(HSESSIONCTX 	   hSession,
					 const char *    szKeyId,
					 const char *    szCertId,
					 const char *    szPIXCertChainId,
					 const char *    szURL,
					 DWORD		   dwCountRequestHeaderList,
					 const char *    pszRequestHeaderList[],
					 DWORD           dwSizeRequestData,
					 BYTE*           pbRequestData,
					 DWORD 	       dwTimeOut,
					 DWORD * 	       pdwSizeResponseHeaders,
					 BYTE ** 	       ppbResponseHeaders,
					 DWORD * 	       pdwSizeResponseBody,
					 BYTE ** 	       ppbResponseBody,
					 DWORD           dwParam);


/**

  Faz uma requisição segura HTTP PUT seguindo o padrão PIX definido no SPI (Sistema de Pagamentos Instantâneos).

  \pixRequestImportant

  \param_hSession
  \param[in] szKeyId					\pixCPICKey
  \param[in] szCertId				    \pixCPICCert
  \param[in] szPIXCertChainId			\pixICOMChain
  \param[in] szURL						\pixICOMURL
  \param[in] dwCountRequestHeaderList	Quantidade de linhas preenchidas em \p pszRequestHeaderList.
  \param[in] pszRequestHeaderList		\pixHeaderEditingInfo
  \pixPutDefaultHeader
  \param[in] dwSizeRequestData			Tamanho dos dados passados em \p pbRequestData.
  \param[in] pbRequestData				Dados enviados na requisição.
  \param[in] dwTimeOut					Tempo de timeout da operação em milisegundos. Pode ser passado 0 para não ter tempo de timeout.
  \param[out] pdwSizeResponseHeaders	Ponteiro que conterá o tamanho dos dados armazenados no buffer \p ppbResponseHeaders, em bytes.
  \param[out] ppbResponseHeaders		Buffer alocado internamente que conterá o _header_ retornado pela requisição. O tamanho alocado estará definido em \p pdwSizeResponseHeaders. Este ponteiro deverá ser liberado utilizando a API DFree().
  \param[out] pdwSizeResponseBody		Ponteiro que conterá o tamanho dos dados armazenados no buffer \p ppbResponseBody, em bytes.
  \param[out] ppbResponseBody			Buffer alocado internamente que conterá o _body_ retornado pela requisição. O tamanho alocado estará definido em \p pdwSizeResponseBody. Este ponteiro deverá ser liberado utilizando a API DFree().
  \param[in] dwParam
  Valor|Significado
	:----|:----------
	0| Opção padrão. Não verifica o certificado com o nome do host.
    #PIX_VERIFY_HOST_NAME| Verifica certificado com o nome do host.
    #PIX_BASIC_HTTP_HEADER | Usa o header HTTP inicial básico. \pixPostPutBasicHeader
    #PIX_GZIP | Faz a compressão gzip automática dos dados de requisição. Inclui automaticamente os headers necessários (Content-Encoding e Accept-Encoding).

  \return \APIReturn_brief

  \remarks

  \pixRequestRemarks


  \see DFree() DPIXPut() DPIXGet() DPIXDelete()
 */
int AAP_API DPIXPut(HSESSIONCTX 	   hSession,
					const char *    szKeyId,
					const char *    szCertId,
					const char *    szPIXCertChainId,
					const char *    szURL,
					DWORD		   dwCountRequestHeaderList,
					const char *    pszRequestHeaderList[],
					DWORD           dwSizeRequestData,
					BYTE*           pbRequestData,
					DWORD 	       dwTimeOut,
					DWORD * 	       pdwSizeResponseHeaders,
					BYTE ** 	       ppbResponseHeaders,
					DWORD * 	       pdwSizeResponseBody,
					BYTE ** 	       ppbResponseBody,
					DWORD           dwParam);

/**

  Faz uma requisição segura HTTP GET seguindo o padrão PIX definido no SPI (Sistema de Pagamentos Instantâneos).

  \pixRequestImportant

  \param_hSession
  \param[in] szKeyId					\pixCPICKey
  \param[in] szCertId				    \pixCPICCert
  \param[in] szPIXCertChainId			\pixICOMChain
  \param[in] szURL						\pixICOMURL
  \param[in] dwCountRequestHeaderList	Quantidade de linhas preenchidas em \p pszRequestHeaderList.
  \param[in] pszRequestHeaderList		\pixHeaderEditingInfo
  \pixGetDeleteDefaultHeader
  \param[in] dwTimeOut					Tempo de timeout da operação em milisegundos. Pode ser passado 0 para não ter tempo de timeout.
  \param[out] pdwSizeResponseHeaders	Ponteiro que conterá o tamanho dos dados armazenados no buffer \p ppbResponseHeaders, em bytes.
  \param[out] ppbResponseHeaders		Buffer alocado internamente que conterá o _header_ retornado pela requisição. O tamanho alocado estará definido em \p pdwSizeResponseHeaders. Este ponteiro deverá ser liberado utilizando a API DFree().
  \param[out] pdwSizeResponseBody		Ponteiro que conterá o tamanho dos dados armazenados no buffer \p ppbResponseBody, em bytes.
  \param[out] ppbResponseBody			Buffer alocado internamente que conterá o _body_ retornado pela requisição. O tamanho alocado estará definido em \p pdwSizeResponseBody. Este ponteiro deverá ser liberado utilizando a API DFree().
  \param[in] dwParam
	Valor|Significado
	:----|:----------
	0| Opção padrão. Não verifica o certificado com o nome do host.
    #PIX_VERIFY_HOST_NAME| Verifica certificado com o nome do host.
    #PIX_BASIC_HTTP_HEADER | Usa o header HTTP inicial básico. \pixGetDeleteBasicHeader
    #PIX_GZIP | Inclui o header Accept-Encoding: gzip caso basic header esteja habilitado.

  \return \APIReturn_brief

  \remarks

  \pixRequestRemarks

  \see DFree() DPIXPost() DPIXGet() DPIXDelete()
 */
int AAP_API DPIXGet(HSESSIONCTX 	hSession,
					const char * 	szKeyId,
					const char * 	szCertId,
					const char *    szPIXCertChainId,
					const char *    szURL,
					DWORD		dwCountRequestHeaderList,
					const char * pszRequestHeaderList[],
					DWORD 	    dwTimeOut,
					DWORD * 	    pdwSizeResponseHeaders,
					BYTE ** 	    ppbResponseHeaders,
					DWORD * 	    pdwSizeResponseBody,
					BYTE ** 	    ppbResponseBody,
					DWORD        dwParam);

/**

  Faz uma requisição segura HTTP DELETE seguindo o padrão PIX definido no SPI (Sistema de Pagamentos Instantâneos).

  \pixRequestImportant

  \param_hSession
  \param[in] szKeyId					\pixCPICKey
  \param[in] szCertId				    \pixCPICCert
  \param[in] szPIXCertChainId			\pixICOMChain
  \param[in] szURL						\pixICOMURL
  \param[in] dwCountRequestHeaderList	Quantidade de linhas preenchidas em \p pszRequestHeaderList.
  \param[in] pszRequestHeaderList		\pixHeaderEditingInfo
  \pixGetDeleteDefaultHeader
  \param[in] dwTimeOut					Tempo de timeout da operação em milisegundos. Pode ser passado 0 para não ter tempo de timeout.
  \param[out] pdwSizeResponseHeaders	Ponteiro que conterá o tamanho dos dados armazenados no buffer \p ppbResponseHeaders, em bytes.
  \param[out] ppbResponseHeaders		Buffer alocado internamente que conterá o _header_ retornado pela requisição. O tamanho alocado estará definido em \p pdwSizeResponseHeaders. Este ponteiro deverá ser liberado utilizando a API DFree().
  \param[out] pdwSizeResponseBody		Ponteiro que conterá o tamanho dos dados armazenados no buffer \p ppbResponseBody, em bytes.
  \param[out] ppbResponseBody			Buffer alocado internamente que conterá o _body_ retornado pela requisição. O tamanho alocado estará definido em \p pdwSizeResponseBody. Este ponteiro deverá ser liberado utilizando a API DFree().
  \param[in] dwParam
	Valor|Significado
	:----|:----------
	0| Opção padrão para certificados SPB. Não verifica o certificado com o nome do host.
	#PIX_VERIFY_HOST_NAME| Verifica certificado com o nome do host.
    #PIX_BASIC_HTTP_HEADER | Usa o header HTTP inicial básico. \pixGetDeleteBasicHeader
    #PIX_GZIP | Inclui o header Accept-Encoding: gzip caso basic header esteja habilitado.

  \return \APIReturn_brief

  \remarks
  
  \pixRequestRemarks

  \see DFree() DPIXPost() DPIXPut() DPIXGet()
 */
int AAP_API DPIXDelete(HSESSIONCTX 	hSession,
					   const char * 	szKeyId,
					   const char * 	szCertId,
					   const char *    szPIXCertChainId,
					   const char *    szURL,
					   DWORD		dwCountRequestHeaderList,
					   const char * pszRequestHeaderList[],
					   DWORD 	    dwTimeOut,
					   DWORD * 	    pdwSizeResponseHeaders,
					   BYTE ** 	    ppbResponseHeaders,
					   DWORD * 	    pdwSizeResponseBody,
					   BYTE ** 	    ppbResponseBody,
					   DWORD        dwParam);

/** @} End of PIX grouping*/

/* Library version */

int AAP_API DVersion ( DWORD dwType, DWORD *pdwMajor,
                      DWORD *pdwMinor, DWORD *pdwRevision,
                      DWORD *pdwBuild );

/**
 \addtogroup memory

 @{
*/

/**
 Aloca um buffer de memória de acordo com o tamanho especificado.

 \param[in] dwsize      Tamanho, em bytes, da memória a ser alocada.

 \return A função retorna um ponteiro, do tipo void, para a região de memória alocada. Caso não seja possível o retorno será ZERO (NULL).

 \remark A memória alocada por DAlloc deve obrigatoriamente ser liberada através do uso da função DFree().

 \see DFree()
 */
void * AAP_API DAlloc (
    DWORD dwsize
);

/**
 Libera um buffer de memóra previamente alocado por DAlloc().

 \param[in] p       Região de memória alocada previamente por DAlloc()

 \return Não retorna valor.
 */
void AAP_API DFree (
    void *p
);

/** @} End of Memória grouping */

//Free and clean CERT_X509_INFO structure members
void AAP_API DCleanCERT_X509_INFO ( CERT_X509_INFO *pstCert );


/* Logs and monitoring */

int AAP_API DLogLineFormat ( char *szIn, char *szOut );

int AAP_API DGetStatLogSize (
    HSESSIONCTX hSession,
    DWORD *pdwLogLen
);

int AAP_API DGetHSMLogInit (    HSESSIONCTX hSession,
                                DWORD dwStart,
                                DWORD dwOffset,
                                HLOGCTX *phLogCtx,
                                DWORD dwParam );

int AAP_API DGetHSMLogCont (    HLOGCTX hLogCtx,
                                BYTE *pbLog,
                                DWORD *pdwLogSize );

int AAP_API DGetHSMLogEnd (    HLOGCTX *phLogCtx );


int AAP_API DGetStatInfo ( HSESSIONCTX hSession, DWORD *pdwSessions,
                          DWORD *pdwCPU, DWORD *pdwUnit,
                          DWORD *pdwMemTotal, DWORD *pdwMemUsed,
                          DWORD *pdwSwapTotal, DWORD *pdwSwapUsed );

int AAP_API DGetNetInfo ( HSESSIONCTX hSession, BYTE **ppbNetInfo, DWORD *pdwNetInfoCount, DWORD dwFlags );


/* Digital certificate */

int AAP_API DCertEncodingConvert (  BYTE *pbCert,
                                    DWORD dwCertLen,
                                    DWORD dwOutFormat,
                                    BYTE **ppbOutCert,
                                    DWORD *pdwOutCertLen,
                                    DWORD dwReserved );


int AAP_API DECPrivateKey2Info(	BYTE *pbEC,
								DWORD dwECLen,
								DWORD dwInForm,
								void *pvPrivKeyInfo,
								DWORD dwOutForm,
								DWORD dwReserved );


int AAP_API DECPublicKey2Info(	BYTE *pbEC,
								DWORD dwECLen,
								DWORD dwInForm,
								void *pvPubKeyInfo,
								DWORD dwOutForm,
								DWORD dwReserved );

/**
 \addtogroup oath

 @{ */

/**
 Gera ou importa um blob OATH para uso no HSM.

 \param_hSession
 \param[in] szMasterKeyId           Nome da chave mestre, utilizada para proteger os blobs, de tamanho máximo #MAX_OBJ_ID_FQN_LEN.
 \param[in] dwParamBlobType         A tabela seguinte é aceita.
                                         valor|Significado
                                         :----|:----------
                                         #ISSUE_OATH_GENERATE_HOTP | Tipo de \p pvParamBlob: estrutura #ISSUE_OTP_BLOB.<br> Gera blob HOTP no HSM. A semente é gerada dentro do HSM.<br> Os seguintes parâmetros da estrutura devem ser preenchidos: \p bSeedLen e \p bTruncationOffset. Os demais devem estar zerados.
                                         #ISSUE_OATH_GENERATE_TOTP | Tipo de \p pvParamBlob: estrutura #ISSUE_OTP_BLOB.<br> Gera blob TOTP no HSM. A semente é gerada dentro do HSM.<br> Os seguintes parâmetros da estrutura devem ser preenchidos: \p bSeedLen, \p bTruncationOffset, \p wTimeStep e \p otT0. Os demais devem estar zerados.
                                         #ISSUE_OATH_IMPORT_HOTP | Tipo de \p pvParamBlob: estrutura #ISSUE_OTP_BLOB.<br> Importa um blob HOTP. A semente é passada por parâmetro. Os seguintes parâmetros da estrutura devem ser preenchidos: \p bSeedLen, \p pbSeed e \p bTruncationOffset. Os demais devem estar zerados.
                                         #ISSUE_OATH_IMPORT_TOTP | Tipo de \p pvParamBlob: estrutura #ISSUE_OTP_BLOB.<br> Importa um blob TOTP. Semente é passada por parâmetro.<br> Os seguintes parâmetros da estrutura devem ser preenchidos: \p bUseDefaultMovingFactor, \p bSeedLen, \p pbSeed, \p bTruncationOffset, \p wTimeStep e \p otT0. Os demais devem estar zerados.
 \param[in] pvParamBlob             Ponteiro para os dados ou estruturas especificados em \p dwParamBlobType.
 \param[in] dwParamBlobLen          Tamanho dos dados ou estrutura especificados em \p dwParamBlobType.
 \param[out] pbOTPBlob              Buffer de tamanho mínimo de #ISSUE_OATH_OUTPUT_MAX_BLOB_LEN que conterá o blob gerado.
 \param[in,out] pdwOTPBlobLen       Tamanho do buffer apontado por \p pbOTPBlob. Na entrada deve conter o tamanho do buffer \p pbOTPBlob na saída conterá o tamanho do blob escrito no buffer alocado.
 \param[in] dwFlags                 \ReservedParamBrief{0}

 \return \APIReturn_brief
 */
int AAP_API DOATHIssueBlob(
    HSESSIONCTX hSession,
    char *szMasterKeyId,
    DWORD dwParamBlobType,
    void *pvParamBlob,
    DWORD dwParamBlobLen,
    BYTE *pbOTPBlob,
    DWORD *pdwOTPBlobLen,
    DWORD dwFlags
);




/**
 Verifica um valor OTP para determinado blob OATH.

 \param_hSession
 \param[in] szMasterKeyId           Nome da chave mestre, utilizada para proteger os blobs, de tamanho máximo #MAX_OBJ_ID_FQN_LEN.
 \param[in] szOTP                   OTP a ser verificado de tamanho mínimo #ISSUE_OATH_MIN_OTP_LEN e máximo #ISSUE_OATH_MAX_OTP_LEN.
 \param[in,out] pbOATHBlob          Ponteiro para um buffer contendo o blob que terá o OTP verificado. Este buffer será reescrito com o buffer atualizado.
 \param[in,out] pdwOATHBlobLen      Tamanho do buffer \p pbOATHBlob. Na entrada conterá o tamanho de \p pbOATHBlob e na saída o tamanho de dados escritos em \p pbOATHBlob.
 \param[in] dwFlags                 A partir da versão 4.0.2 do firmware pode-se passar, neste parâmetro, o tamanho da janela de look-ahead de autenticação. 
 O padrão é de 10 intervalos para mais ou para menos. No caso de tokens HOTP os intervalos serão contados por 
 quantidade de eventos, no caso dos tokens TOTP serão contados por quantidade de time-steps.
 Valor|Significado
:----|:----------
0 | Utiliza o valor default de 10 intervalos.
1 à MAX_OTP_LOOK_AHEAD_INTERVAL | Define o valor da janela de look-ahead de autenticação.

Também é possível passar neste parâmetro a flag #OATH_UPDATE_BLOB, para permitir a atualização do formato do OATH blob. 
Quando a flag #OATH_UPDATE_BLOB é utilizada, deve-se passar o OATH blob atual em \p pbOATHBlob em um buffer suficientemente grande para comportar o blob atualizado. 
\p pdwOATHBlobLen deverá conter o valor do tamanho do buffer passado em \p pbOATHBlob.
O tamanho de \p pbOATHBlob necessário, é retornado em \p pdwOATHBlobLen na chamada onde o erro #D_OATH_BLOB_UPDATE é retornado.
A atualização precisa ser apenas feita após receber o erro #D_OATH_BLOB_UPDATE. Ver Anotações para mais detalhes.


\return \APIReturn_brief

\remark Caso seja retornado o erro #D_OATH_BLOB_UPDATE a função retornará em \p pdwOATHBlobLen o tamanho do buffer que deverá ser utilizado para atualização do OATH blob em uma chamada posterior.
Ver detalhes na especificação de #OATH_UPDATE_BLOB.
 */
int AAP_API DOATHCheckOTP(
    HSESSIONCTX hSession,
    char *szMasterKeyId,
    char *szOTP,
    BYTE *pbOATHBlob,
    DWORD *pdwOATHBlobLen,
    DWORD dwFlags
);

/**
Gera o próximo OTP à partir de um blob OATH. O OATH blob não será alterado.

\param_hSession
\param[in] szMasterKeyId           Nome da chave mestre, utilizada para proteger os blobs, de tamanho máximo #MAX_OBJ_ID_FQN_LEN.
\param[in] bOTPLen                 Tamanho do OTP que será gerado, podendo ser um valor entre #ISSUE_OATH_MIN_OTP_LEN e #ISSUE_OATH_MAX_OTP_LEN.
\param[in] pbOATHBlob				Ponteiro para um buffer contendo o blob que será utilizado para a geração do OTP. Este buffer não será alterado.
\param[in] dwOATHBlobLen			Tamanho do buffer \p pbOATHBlob.
\param[out] szOTP                   Buffer que conterá o OTP gerado. Deverá ter o tamanho mínimo de \p bOTPLen + 1(terminador nulo).
\param[in] dwFlags                 \ReservedParamBrief{0}

\return \APIReturn_brief
*/
int AAP_API DOATHGetNextOTP(
	HSESSIONCTX hSession,
	char *szMasterKeyId,
	BYTE bOTPLen,
	BYTE *pbOATHBlob,
	DWORD dwOATHBlobLen,
	char *szOTP,
	DWORD dwFlags
);

/**
 Recupera as informações internas de um blob OATH.

 \param_hSession
 \param[in] szMasterKey             Nome da chave mestre, utilizada para proteger os blobs, de tamanho máximo #MAX_OBJ_ID_FQN_LEN.
 \param[in] pbInBlob                Ponteiro para um buffer contendo o blob para extração das informações.
 \param[in] dwInBlobLen             Tamanho do buffer \p pbInBlob.
 \param[in] dwOutBlobType           Indica o tipo de dado de saída. A seguinte tabela é aceita.
                                         Valor|Significado
                                         :----|:----------
                                         #OATH_ISSUE_OATH_BLOB_t | Tipo de pbOutInfo: #ISSUE_OATH_BLOB_t. O Buffer de pbInBlob precisa ser um blob tipo V1 com tamanho #ISSUE_OATH_OUTPUT_BLOB_V1_LEN.
										 #OATH_ISSUE_OATH_INFO_t | Tipo de pbOutInfo: #ISSUE_OATH_INFO_t. Esta opção aceita blobs do tipo V1 e V2 com tamanhos #ISSUE_OATH_OUTPUT_BLOB_V1_LEN e #ISSUE_OATH_OUTPUT_BLOB_V2_LEN, respectivamente.
 \param[out] pbOutInfo              Ponteiro para um buffer que receberá as informações do blob. Deve ser de acordo com o descrito em \p dwOutBlobType.
 \param[in,out] pdwOutInfoLen       Tamanho do buffer apontado por \p pdwOutInfoLen.
 \param[in] dwParam                 \ReservedParamBrief{0}

 \return \APIReturn_brief

 */
int AAP_API DOATHGetBlobInfo(
    const HSESSIONCTX hSession,
    char *szMasterKey,
    BYTE *pbInBlob,
    DWORD dwInBlobLen,
    DWORD dwOutBlobType,
    BYTE *pbOutInfo,
    DWORD *pdwOutInfoLen,
    DWORD dwParam
);

/**
 Re-sincroniza um blob OATH através da apresentação de dois valores de OTP contínuos. Apenas para HOTP(OTP por evento).

 \param_hSession
 \param[in] szMasterKeyId           Nome da chave mestre, utilizada para proteger os blobs, de tamanho máximo #MAX_OBJ_ID_FQN_LEN.
 \param[in] szOTP1                  OTP a ser verificado de tamanho mínimo #ISSUE_OATH_MIN_OTP_LEN e máximo #ISSUE_OATH_MAX_OTP_LEN.
 \param[in] szOTP2                  Segundo OTP a ser verificado de tamanho mínimo #ISSUE_OATH_MIN_OTP_LEN e máximo #ISSUE_OATH_MAX_OTP_LEN.
 \param[in,out] pbOATHBlob          Ponteiro para um buffer contendo o blob a ser sincronizado. Este buffer será reescrito com o buffer sincronizado.
 \param[in,out] pdwOATHBlobLen      Tamanho do buffer \p pbOATHBlob. Na entrada conterá o tamanho de \p pbOATHBlob e na saída o tamanho de dados escritos em \p pbOATHBlob.
 \param[in] dwFlags                 Aceita a flag #OATH_UPDATE_BLOB, para permitir a atualização do formato do OATH blob. 
Quando a flag #OATH_UPDATE_BLOB é utilizada, deve-se passar o OATH blob atual em \p pbOATHBlob em um buffer suficientemente grande para comportar o blob atualizado. 
\p pdwOATHBlobLen deverá conter o valor do tamanho do buffer passado em \p pbOATHBlob.
O tamanho de \p pbOATHBlob necessário, é retornado em \p pdwOATHBlobLen na chamada onde o erro #D_OATH_BLOB_UPDATE é retornado.
A atualização precisa ser apenas feita após receber o erro #D_OATH_BLOB_UPDATE. Ver Anotações para mais detalhes.

 \return \APIReturn_brief

 \remark A partir da versão 4.0.2 do firmware a janela será estendida em 200 intervalos para mais e para menos. No caso de tokens HOTP os intervalos serão contados por 
 quantidade de eventos, no caso dos tokens TOTP serão contados por quantidade de time-steps.
 Caso seja retornado o erro #D_OATH_BLOB_UPDATE a função retornará em \p pdwOATHBlobLen o tamanho do buffer que deverá ser utilizado para atualização do OATH blob em uma chamada posterior.
Ver detalhes na especificação de #OATH_UPDATE_BLOB.
 */
int AAP_API DOATHBlobResync(
    HSESSIONCTX hSession,
    char *szMasterKeyId,
    char *szOTP1,
    char *szOTP2,
    BYTE *pbOATHBlob,
    DWORD *pdwOATHBlobLen,
    DWORD dwFlags
);

/**
 Importa sementes envelopadas no padrão PSKC (_Portable Symmetric Key Container_), [RFC 6030](https://tools.ietf.org/html/rfc6030).

 \param_hSession
 \param[in] szMasterKey             Nome da chave mestre, utilizada para proteger os blobs, de tamanho máximo #MAX_OBJ_ID_FQN_LEN de saída.
 \param[in] pbPSK                   Buffer de tamanho máximo #OATH_MAX_PSK_LEN contendo a chave de transporte que protege as sementes informadas em \p pbPSKC.
 \param[in] bPSKLen                 Tamanho do buffer pbPSK.
 \param[in] pbPSKC                  Buffer PSKC contendo as sementes que serão transformadas em blobs no formato do HSM.
 \param[in] dwPSKCLen               Tamanho do buffer pbPSKC.
 \param[out] pvBlobList             Ponteiro para ponteiro que apontará para um buffer alocado internamente contendo um array de estruturas OATH_PSKC_TRANSLATE_OUTPUT. Esta estrutura conterá internamente os blobs das sementes traduzidas para o formato do HSM e o identificador de cada semente como na tag "<pskc:Key Id=>".
 \param[out] pdwBlobListQuantity    Ponteiro para a quantidade de blobs retornados no buffer \p pvBlobList.
 \param[in] dwParam                 \ReservedParamBrief{0}

 \return \APIReturn_brief
 */
int AAP_API DOATHPskcTranslate(
    HSESSIONCTX hSession,
    char *szMasterKey,
    BYTE *pbPSK,
    BYTE bPSKLen,
    BYTE *pbPSKC,
    DWORD dwPSKCLen,
    void **pvBlobList,
    DWORD *pdwBlobListQuantity,
    DWORD dwParam
);

/** @} End of OATH grouping*/

//DOATHIssueHOTPBlob is DEPRECATED. Use DOATHIssueBlob instead.
int AAP_API DOATHIssueHOTPBlob(
    HSESSIONCTX hSession,
    char *szMasterKeyId,
    DWORD dwParamBlobType,
    void *pvParamBlob,
    DWORD dwParamBlobLen,
    BYTE *pbOTPBlob,
    DWORD *pdwOTPBlobLen,
    DWORD dwFlags
);

//DOATHCheckHOTP is DEPRECATED. Use DOATHCheckOTP instead.
int AAP_API DOATHCheckHOTP( HSESSIONCTX hSession,
                            char *szMasterKeyId,
                            char *szOTP,
                            BYTE *pbOATHBlob,
                            DWORD *pdwOATHBlobLen,
                            DWORD dwFlags );

//Users
void AAP_API DGenerateHOTPOffline(BYTE *pbSecret,
									DWORD dwSecretLen,
									ND_OATH_uint64_t nuiMovingFactor,
									int nCodeDigits,
									BOOL bAddChecksum,
									int nTruncOff,
									char *szResult);


/**
 \addtogroup spb

  @{ */

/**
 Inicia uma operação de codificação de mensagens SPB.

 \param_hSession
 \param[in] szSrcISPB               Identificador da instituição de origem com tamanho máximo MAX_OBJ_ID_FQN_LEN.<br> O identificador da origem deverá ter o seguinte formato: ISPB\@DOMINIO, sendo a parte do domínio opcional.<br> O tamanho exato para ISPB é #ND_SPB_ISPB_LEN e o tamanho máximo para DOMINIO é #ND_SPB_DOMAIN_MAX_LEN.
                                        O tamanho máximo para o identificador é #ND_SPB_ID_MAX_LEN.<br> Exemplo: 12345678\@MES01 onde \a 12345678 é o ISPB da instituição e \a MES01 é o identificador do DOMÍNIO.<br> Também pode ser passado o nome do map correspondente, fora do padrão de nomenclatura do módulo SPB.
 \param[in] szDstISPB               Identificador da instituição de destino tamanho máximo #MAX_OBJ_ID_FQN_LEN.<br> O identificador do destino deverá ter o seguinte formato: ISPB\@DOMINIO, sendo a parte do domínio opcional.<br> O tamanho para ISPB é #ND_SPB_ISPB_LEN e o tamanho máximo para DOMINIO é #ND_SPB_DOMAIN_MAX_LEN.
                                        O tamanho máximo para o identificador é #ND_SPB_ID_MAX_LEN.<br> Exemplo: 12345678\@MES01 onde \a 12345678 é o ISPB da instituição e \a MES01 é o identificador do DOMÍNIO.<br> Também pode ser passado o nome do map correspondente, fora do padrão de nomenclatura do módulo SPB.
 \param[in] dwTotalDataLen          Tamanho em bytes total da mensagem a ser codificada.
 \param[in] bErrorCode              Código de erro da mensagem para ser colocado no cabeçalho de segurança, normalmente em mensagens de resposta.
 \param[in] bSpecialTreatment       Código de tratamento especial da mensagem, conforme manual do Banco Central.
 \param[out] hSPBCtx                Ponteiro para contexto da operação de codificação SPB. Depois do seu uso deverá ser liberado com a função DSPBEncodeEnd().
 \param[in] dwFlags                 Define detalhes da codificação, podendo assumir os seguintes valores descritos na tabela abaixo.
                                    Valor | Signficado
                                    ------|-----------
                                    0 | Utiliza o padrão SPB(Sistema de Pagamentos Brasileiro).
                                    #ND_SPB_ENCODE_GEN_01 | Gera uma mensagem GEN 01.
									#ND_SPB_USE_CIP1 | Utiliza o padrão CIP(Camara Interbancaria de Pagamentos). Quando esta flag não está definida o padrão SPB(Sistema de Pagamentos Brasileiro) é utilizado.
									#ND_SPB_USE_ANY | Aceita o padrão CIP e SPB. A detecção é feita internamente.
                                    #ND_SPB_ENCODE_HEADER_V3 | Codifica a mensagem utilizando o cabeçalho de segurança versão 3. No futuro esta opção será definida por padrão. O cabeçalho V3 está disponível a partir da versão 5.0.16 do firmware do HSM.
 \return \APIReturn_brief

 \remark Deve-se chamar DSPBEncodeCont() e DSPBEncodeEnd() para envio de mensagem e finalização da codificação. Mesmo em caso de erro, sempre liberar o contexto da operação utilizando DSPBEncodeEnd().
 \SPBCertTypes_brief
 */
int AAP_API DSPBEncodeInit (
    HSESSIONCTX hSession,
    char *szSrcISPB,
    char *szDstISPB,
    DWORD dwTotalDataLen,
    BYTE bErrorCode,
    BYTE bSpecialTreatment,
    HSPBCTX *hSPBCtx,
    DWORD dwFlags
);

/**
 Envia partes ou toda a mensagem para codificação no HSM.

 \param[in] hSPBCtx                 Contexto adquirido através da função DSPBEncodeInit().
 \param[in] pbDataIn                Buffer contendo parte ou toda a mensagem a ser codificada.<br> O tamanho por chamada é de #DN_SPB_MAX_NOTIFY_DATA_SEG bytes.<br> Pode-se enviar tamanhos menores caso seja o último ou o único pedaço da mensagem.
 \param[in] dwDataInLen             Tamanho em bytes do buffer \p pbDataIn.
 \param[out] pbDataOut              Buffer que receberá os dados da mensagem codificada.<br> Deverá ter tamanho igual ou maior a \p pbDataIn.<br> Caso seja o último pedaço, adicionar espaço no tamanho para possível padding/tag. Recomenda-se utilizar um tamanho mínimo de #DN_SPB_MAX_RCV_NOTIFY_DATA_SEG bytes para garantir o recebimento de todos os dados retornados.
 \param[in,out] pdwDataOutLen       Ponteiro para um DWORD que contém o tamanho de \p pbDataOut.<br> Na entrada deve conter o tamanho do buffer apontado por pbDataOut, na saída contém o tamanho dos dados que foram codificados em pbDataOut.

 \return \APIReturn_brief

 \remark Mesmo em caso de erro, sempre liberar o contexto da operação utilizando DSPBEncodeEnd().
 */
int AAP_API DSPBEncodeCont (
    HSPBCTX hSPBCtx,
    BYTE *pbDataIn,
    DWORD dwDataInLen,
    BYTE *pbDataOut,
    DWORD *pdwDataOutLen
);

/**
 Finaliza uma operação de codificação SPB e recebe o cabeçalho de segurança.

 \param[in] hSPBCtx                 Ponteiro para o contexto adquirido através da função DSPBEncodeInit().
 \param[out] pbSPBHeader            Buffer que conterá o cabeçalho de segurança damensagem codificada.<br> Deverá ter tamanho igual ou maior a #DN_SPB_MSG_HEADER_V2_LEN bytes.
 \param[in,out] pdwSPBHeaderLen     Ponteiro para um DWORD que na entrada deverá conter o tamanho do buffer apontado por pbSPBHeader, e na saída conterá o tamanho do cabeçalho escrito em pbSPBHeader.

 \return \APIReturn_brief
 */
int AAP_API DSPBEncodeEnd (
    HSPBCTX *hSPBCtx,
    BYTE *pbSPBHeader,
    DWORD *pdwSPBHeaderLen
);

/**
 Inicia uma operação de decodificação de mensagens SPB.

 \param_hSession
 \param[in] szSrcISPB               Identificador da instituição de origem com tamanho máximo #MAX_OBJ_ID_FQN_LEN.
                                       O identificador da origem deverá ter o seguinte formato: ISPB\@DOMINIO, sendo a parte do domínio opcional.
                                       O tamanho exato para ISPB é #ND_SPB_ISPB_LEN e o tamanho máximo para DOMINIO é #ND_SPB_DOMAIN_MAX_LEN.
                                       O tamanho máximo para o identificador é #ND_SPB_ID_MAX_LEN.
                                       Exemplo: 12345678\@MES01 onde \a 12345678 é o ISPB da instituição e \a MES01 é o identificador do DOMÍNIO.
                                       Também pode ser passado o nome do map correspondente, fora do padrão de nomenclatura do módulo SPB.
 \param[in] szDstISPB               Identificador da instituição de destino com tamanho máximo #MAX_OBJ_ID_FQN_LEN.
                                       O identificador do destino deverá ter o seguinte formato: ISPB\@DOMINIO.
                                       O tamanho para ISPB é #ND_SPB_ISPB_LEN e o tamanho máximo para DOMINIO é #ND_SPB_DOMAIN_MAX_LEN.
                                       O tamanho máximo para o identificador é #ND_SPB_ID_MAX_LEN.
                                       Exemplo: 12345678\@MES01 onde \a 12345678 é o ISPB da instituição e \a MES01 é o identificador do DOMÍNIO.
                                       Também pode ser passado o nome do map correspondente, fora do padrão de nomenclatura do módulo SPB.
 \param[in] pbHeader                Buffer contendo o cabeçalho de segurança da mensagem SPB a ser decodificada.
 \param[in] dwHeaderLen             Tamanho em bytes do buffer pbHeader.
 \param[in] bAcceptExpiredCert      Byte para aceitar certificados expirados na decodificação da mensagem. Passar 1 para aceitar e 0 para não aceitar.
 \param[in] bAutoUpdateCert         Habilita ou desabilita a atualização automática de certificados na base do HSM caso a mensagem seja de troca de certificado.
                                        Atualmente são tratadas as seguintes mensagens: GEN0006 (resposta), GEN0007, GEN0008 (resposta) e GEN0018. O certificado é importado e ativado automaticamente, exceto no caso da GEN0018 (certificado do Banco Central), onde o certificado é importado mas não ativado.  Passar 1 para habilitado e 0 para desabilitado.
 \param[in] dwMessageDataLen        Tamanho total da mensagen SPB a ser decodificada.
 \param[out] hSPBCtx                Ponteiro para o contexto da operação de decodificação SPB. Depois do seu uso deverá ser liberado com a função DSPBDecodeEnd().
 \param[in] dwFlags                 Define detalhes da decodificação, podendo assumir os seguintes valores descritos na tabela abaixo.
                                    Valor | Signficado
                                    ------|-----------
                                    0 | Utiliza o padrão SPB(Sistema de Pagamentos Brasileiro).
                                    #ND_SPB_OUT_NO_PADDING | Retira o padding do final da mensagem SPB após a decriptação.
                                    #ND_SPB_OUT_WITH_PADDING | Mantem o padding no final da mensagem SPB após a decriptação.
									#ND_SPB_USE_CIP1 | Utiliza o padrão CIP(Camara Interbancaria de Pagamentos). Quando esta flag não está definida o padrão SPB(Sistema de Pagamentos Brasileiro) é utilizado.
									#ND_SPB_USE_ANY | Aceita o padrão CIP e SPB. A detecção é feita internamente.

 \return \APIReturn_brief

 \remark Deve-se chamar DSPBDecodeCont() e DSPBDecodeEnd() para envio de mensagem e finalização da codificação.Mesmo em caso de erro, sempre liberar o contexto da operação utilizando DSPBDecodeEnd(). O tratamento da GEN0006R1 (resposta da GEN0006) está disponível a partir da versão 5.0.16 do firmware.
 \SPBCertTypes_brief
 */
int AAP_API DSPBDecodeInit (
    HSESSIONCTX hSession,
    char *szSrcISPB,
    char *szDstISPB,
    BYTE *pbHeader,
    DWORD dwHeaderLen,
    BYTE bAcceptExpiredCert,
    BYTE bAutoUpdateCert,
    DWORD dwMessageDataLen,
    HSPBCTX *hSPBCtx,
    DWORD dwFlags
);

/**
 Envia partes ou toda a mensagem para decodificacao no HSM.

 \param[in] hSPBCtx             Contexto adquirido atraves da funcao DSPBDecodeInit.
 \param[in] pbDataIn            Buffer contendo parte ou toda a mensagem a ser decodificada.
                                    O tamanho por chamada é de #ND_SPB_MAX_NOTIFY_DATA_SEG bytes. Pode-se enviar tamanhos menores caso seja o ultimo ou o unico pedaco da mensagem.
 \param[in] dwDataInLen         Tamanho em bytes do buffer \p pbDataIn.
 \param[out] ppbDataOut         Ponteiro de ponteiro que ira receber os dados codificados.
                                     O tamanho do buffer alocado estara disponivel atraves de pdwDataOutLen.A alocacao de memoria e feita internamente.
                                     A desalocacao e feita na proxima chamada a DSPBDecodeCont() ou DSPBDecodeEnd().
 \param[out] pdwDataOutLen      Ponteiro para o tamanho do buffer alocado internamente em ppbDataOut.

 \return \APIReturn_brief
 */
int AAP_API DSPBDecodeCont (
    HSPBCTX hSPBCtx,
    BYTE *pbDataIn,
    DWORD dwDataInLen,
    BYTE **ppbDataOut,
    DWORD *pdwDataOutLen
);

/**
 Finaliza uma operacao de decodificacao SPB e recebe o cabecalho de seguranca.

 \param[in] hSPBCtx         Ponteiro para o contexto adquirido atraves da funcao DSPBDecodeInit().

 \return \APIReturn_brief
 */
int AAP_API DSPBDecodeEnd(
  HSPBCTX *hSPBCtx
);

/**
 Gera uma chave privada no padrão SPB. É uma função especializada da API de geração de chave do HSM.<br> A aplicação gera a chave (RSA 2048 ou como estabelecido no manual atualizado do Bacen) com a identificação seguindo a lei de formação interna, descrita na apresentação do módulo SPB.

 \param_hSession
 \param[in] szID                Identificador da instituição à qual se destina a chave privada.<br> O identificador da instituição deverá ter o seguinte formato: "ISPB@DOMINIO", sendo a parte do domínio opcional.<br>O tamanho exato para ISPB é ND_SPB_ISPB_LEN e o tamanho máximo para DOMINIO é #ND_SPB_DOMAIN_MAX_LEN.<br> O tamanho máximo para o identificador é #ND_SPB_ID_MAX_LEN.<br> Exemplo: 12345678\@MES01 onde \a 12345678 é o ISPB da instituição e \a MES01 é o identificador do DOMÍNIO.
 \param[out] szPrivateKeyName   Buffer de tamanho de #MAX_OBJ_ID_FQN_LEN ou mais.<br> Este buffer receberá uma string contendo o identificador do par de chaves gerado dentro do HSM.<br> Este identificador deverá ser mantido pela aplicação para posterior utilização em DSPBGenerateCSR() e/ou outras.
 \param[in] dwKeyParam          Parâmetros adicionais da chave. Veja as opções na função DGenerateKey().
 \param[in] dwParam             \ReservedParamBrief{0}

 \return \APIReturn_brief
 */
int AAP_API DSPBGenerateKey (
    HSESSIONCTX hSession,
    char *szID,
    char *szPrivateKeyName,
    DWORD dwKeyParam,
    DWORD dwParam
);

/**
 Gera um CSR (Certificate Signing Request / Requisição de Assinatura de Certificado) para SPB. É uma função especializada da API de geração de CSR PKCS#10 do HSM.<br> Não há regras de validação de certificados SPB; isto está a cargo da aplicação, que poderá gerar CSRs para sistemas diferentes, como SPB e CIP.

 \param_hSession
 \param[in] szPrivateKeyName    Identificador da chave privada.<br> Normalmente a string gerada em DSPBGenerateKey().
 \param[in] bVersion            Versão do CSR PKCS#10. A seguinte tabela é suportada.
                                     Valor | Significado
                                     :-----|:-----------
                                     #CORE_P10_CSR_VERSION1 | PKCS#10 CSR versão 1.
 \param[in] szSPBSubject        DN (Dinstinguished Name), para a geração do CSR, com tamanho máximo #CORE_P10_CSR_DN_MAX_LEN. Os campos de DN deverão ser separados por '/'.
 \param[in] dwOutType           Tipo de saída do CSR. A seguinte tabela é suportada,
                                     Valor | Significado
                                     :-----|:-----------
                                     #P10_CSR_DER | Exporta o CSR no formato DER.
                                     #P10_CSR_PEM | Exporta o CSR no formato PEM.
 \param[out] pdwCSRLen          Ponteiro para o tamanho do buffer alocado em ppbCSR.
 \param[out] ppbCSR             Ponteiro de ponteiro que irá receber o CSR.<br> O tamanho do buffer alocado estará disponível através de pdwCSRLen.<br> A alocação de memória é feita internamente.<br> A aplicação chamadora é responsável por liberar a memória alocada usando a API DFree().
 \param[in] dwParam             Parâmetros adicionais. A seguinte tabela é suportada.
                                     Valor | Significado
                                     :-----|:-----------
                                     0 | Utiliza o hash padrão do HSM na assinatura do CSR.
                                     #CORE_P10_HASH_SHA1 | Utiliza o SHA-1 na assinatura do CSR.
                                     #CORE_P10_HASH_SHA224 | Utiliza o SHA-224 na assinatura do CSR.
                                     #CORE_P10_HASH_SHA256 | Utiliza o SHA-256 na assinatura do CSR.
                                     #CORE_P10_HASH_SHA384 | Utiliza o SHA-384 na assinatura do CSR.
                                     #CORE_P10_HASH_SHA512 | Utiliza o SHA-512 na assinatura do CSR.
\remarks	Exemplos de campo DN.
\code
    /CN=BANCO TESTE S/A P001/OU=SISBACEN-00888/OU=ISPB-54444619/O=ICP-Brasil/L=Sao Paulo/S=Sao Paulo/C=BR
\endcode
 \return \APIReturn_brief
 */
int AAP_API DSPBGenerateCSR(
    HSESSIONCTX hSession,
    char *szPrivateKeyName,
    BYTE bVersion,
    char *szSPBSubject,
    DWORD dwOutType,
    DWORD *pdwCSRLen,
    BYTE **ppbCSR,
    DWORD dwParam
);

/**
 Importa um certificado SPB e o associa a um par de chaves dentro do HSM (via um objeto map), caso exista tal chave.\par
 A aplicação não precisa informar se é um certificado próprio ou de terceiro, o HSM se encarrega de fazer uma busca por chave privada correspondente à chave pública no certificado; e se encontrar faz associação no map apropriado. Quando uma chave privada correspondente não é encontrada fica assumido que o certificado é de um terceiro. Esta busca interna pelo HSM deixa a operação mais rápida, atômica e segura, já que a biblioteca não precisa fazer operações de exportação e buscas locais.\par
 O certificado é criado na base do HSM com a lei de formação de nome definida. O HSM faz o parse no certificado para recuperar campos como ISPB.\par
 Se o HSM encontrar a chave privada um map é criado identificado por MD5(CA+NS), coloca no slot1 o id da chave e no slot2 o id do certificado recém importado. Retorna erro se já existir o map. Este é o caso de um certificado próprio.\par
 Se o firmware não encontrar a chave privada um map é criado identificado por MD5(CA+NS), deixa o slot1 vazio e no slot2 o id do certificado recém importado. Retorna erro se já existir o map. Este é o caso de um certificado de terceiro.

 \param_hSession
 \param[in] bActivate           Ativa automaticamente o certificado no momento da importação.<br> Passar 1 para ativar e 0 para importar sem ativar o certificado.
 \param[in] szUser              Nome do usuário, para importação do certificado, com tamanho máximo (#MAX_USR_LEN+1).<br> Pode ser NULL caso a importação seja feita no próprio usuário da sessão corrente.
 \param[in] pbCertificate       Buffer contendo o certificado a ser importado. O certificado pode estar no formato PEM ou DER.
 \param[in] dwCertificateLen    Tamanho do buffer apontado por pbCertificate.
 \param[in] szDomain            Domínio de mensagem do certificado a ser ativado. Deve ter tamanho máximo de (#ND_SPB_DOMAIN_MAX_LEN + 1).<br> Pode ser NULL caso não haja um domínio definido.
 \param[in] dwParam             A seguinte tabela de flags é suportada.
                                     Valor | Significado
                                     :-----|:-----------
                                     0 | Utiliza o padrão SPB(Sistema de Pagamentos Brasileiro).
									#ND_SPB_USE_CIP1 | Utiliza o padrão CIP(Camara Interbancaria de Pagamentos).
									#ND_SPB_USE_ANY | Aceita o padrão CIP e SPB. A detecção é feita internamente.

 \return \APIReturn_brief
 \remark \SPBCertTypes_brief
 */
int AAP_API DSPBImportCertificate(
    HSESSIONCTX hSession,
    BYTE bActivate,
    char *szUser,
    BYTE *pbCertificate,
    DWORD dwCertificateLen,
    char *szDomain,
    DWORD dwParam
);

/**
 Importa um par de chaves e um certificado a partir de um arquivo PKCS#12.\par
 O certificado e a chave privada são criados na base do HSM com a lei de formação de nome definida. O HSM faz o parse no certificado para recuperar campos como CA e NS.\par
 No processo de importação um \a map é criado identificado por <em>MD5(CA+NS)</em>, no slot1 vai o id da chave e no slot2 o id do certificado. Retorna erro se já existir o map, ou seja, se o certificado e a chave privada já existiram na base do HSM. \par
 Esta API detecta automaticamente se é um certificado SPB ou CIP.

 \param_hSession
 \param[in] bActivate       Ativa automaticamente o certificado no momento da importação.<br> Passar 1 para ativar e 0 para importar sem ativar o certificado.
 \param[in] szUser          Nome do usuário onde a chave será criada. Pode ser NULL caso a chave seja criada no próprio usuário autenticado.
 \param[in] szPkcs12File    Nome do arquivo PKCS#12 para importação.
 \param[in] szPkcs12Pwd     Senha do arquivo PKCS#12 para importação.
 \param[in] szDomain        Domínio de mensagem do certificado a ser ativado. Deve ter tamanho máximo de (#ND_SPB_DOMAIN_MAX_LEN + 1).<br>cPode ser NULL caso não haja um domínio definido.
 \param[in] dwKeyAttr       Parâmetros adicionais da chave. Veja as opções na função DGenerateKey().

 \return \APIReturn_brief
 */
int AAP_API DSPBImportPKCS12(	HSESSIONCTX hSession,
								BYTE bActivate,
								char *szUser,
								char *szPkcs12File,
								char *szPkcs12Pwd,
								char *szDomain,
								DWORD dwKeyAttr);

/**
 Exporta um par de chaves e um certificado no formato PKCS#12 a partir de um HSM.\par
 Esta chamada aceita idenficador de certificado/chave privada nos formatos CA\@SN e ISPB\@DOM.

 \param_hSession.
 \param[in] szPkcs12Pwd         Senha do arquivo PKCS#12. Passar NULL para gerar PKCS#12	sem senha.
 \param[in] szISPB              Identificador do certificado/chave privada no formato CA\@SN, ISPB ou ISPB\@DOM.
 \param[in] szReserved		   Reservado para uso futuro (deve ser NULL).
 \param[out] ppbPkcs12          Ponteiro para um ponteiro que conterá o PKCS#12 gerado. Esta área de dados será alocada internamente e deve ser liberada utilizando DFree().
 \param[out] pdwPkcs12Len       Ponteiro para o tamanho dos dados escritos em \p ppbPkcs12.
 \param[in] dwReserved          \ReservedParamBrief{0}

 \return \APIReturn_brief
*/
int AAP_API DSPBExportPKCS12(	const HSESSIONCTX hSession,
								const char *szPkcs12Pwd,
								const char *szISPB,
								const char *szReserved,
								BYTE **ppbPkcs12,
								DWORD *pdwPkcs12Len,
								DWORD dwReserved);

/**
 Ativa um certificado SPB no HSM.

 \param_hSession
 \param[in] szIdCert    Identificador do certificado a ser ativado.<br> O identificador do certificado deverá ter o seguinte formato: CA\@SN.<br> O tamanho para CA é #ND_SPB_CA_LEN e o tamanho para SN é #ND_SPB_SN_MAX_LEN.<br> O tamanho máximo para o identificador é #ND_SPB_ID_MAX_LEN.<br> Exemplo: 03\@12345678 onde 03 é o identificador da CA e 12345678 é o número de série do certificado.
 \param[in] szDomain    Domínio de mensagem do certificado a ser ativado. Deve ter tamanho máximo de (#ND_SPB_DOMAIN_MAX_LEN + 1).<br> Pode ser NULL caso não haja um domínio definido.
 \param[in] dwParam     Reservado para uso Futuro.

 \return \APIReturn_brief
 */
int AAP_API DSPBActivateCertificate (
    HSESSIONCTX hSession,
    char *szIdCert,
    char *szDomain,
    DWORD dwParam
);

/**
 Ativa um certificado SPB no HSM.

 \param_hSession
 \param[in] szIdCert            Identificação do certificado a ser recuperado.<br> O identificador do certificado poderá ter os seguintes formatos: ID, CA\@SN ou ISPB\@DOMINIO.<br> O tamanho exato para CA é #ND_SPB_CA_LEN e o tamanho máximo para SN é #ND_SPB_SN_MAX_LEN.<br> O tamanho máximo para o identificador é #ND_SPB_ID_MAX_LEN. Exemplo: 03\@12345678 onde \a 03 é o identificador da CA e \a 12345678 é o ISPB da instituição.<br> O tamanho exato para ISPB é #ND_SPB_ISPB_LEN e o tamanho máximo para DOMINIO é #ND_SPB_DOMAIN_MAX_LEN.<br> O tamanho máximo para o identificador é #ND_SPB_ID_MAX_LEN.<br> Exemplo: 12345678\@MES01 onde \a 12345678 é o ISPB da instituição e \a MES01 é o identificador do DOMÍNIO.
 \param[out] ppbCertificate     Ponteiro de ponteiro que irá receber o certificado.<br> O tamanho do buffer alocado estará disponível através de pdwCertificateLen.<br> A alocação de memória é feita internamente pela biblioteca.<br> A aplicação chamadora é responsável por liberar a memória alocada usando a API DFree().
 \param[out] pdwCertificateLen  Ponteiro para o tamanho do buffer apontado por ppbCertificate.
 \param[in] dwParam             \ReservedParamBrief{0}

 \return \APIReturn_brief
 */
int AAP_API DSPBGetCertificate (
    HSESSIONCTX hSession,
    char *szIdCert,
    BYTE **ppbCertificate,
    DWORD *pdwCertificateLen,
    DWORD dwParam
);

/**
 API auxiliar que calcula (localmente) um nome de objeto no formato padrão do módulo SPB.

 \param[in] szISPB              ISPB da instituição. Deve ter tamanho de (#ND_SPB_ISPB_LEN +1).
 \param[in] szDomain            Domínio de mensagem do certificado a ser ativado. Deve ter tamanho máximo de (#ND_SPB_DOMAIN_MAX_LEN + 1).<br> Pode ser NULL caso não haja um domínio definido.
 \param[in] dwKeyType           Tipo do nome a ser gerado. Os valores da tabela seguinte serão aceitos:
                                     Valor | Significado
                                     :-----|:-----------
                                      #SPB_GENERATE_KEY_NAME | Gera um nome para uma chave.
                                      #SPB_GENERATE_CER_NAME | Gera um nome para um certificado.
 \param[out] szOutObjName       Buffer de tamanho #MAX_OBJ_ID_FQN_LEN que conterá o nome de objeto calculado.
 \param[in] dwParam             \ReservedParamBrief{0}

 \return \APIReturn_brief
 */
int AAP_API DSPBCalculateObjectId (
    char *szISPB,
    char *szDomain,
    DWORD dwKeyType,
    char *szOutObjName,
    DWORD dwParam
);

/**
 API auxiliar que recupera as informações de um MAP SPB.

 \param_hSession
 \param[in] szIdCert        Identificação do certificado a ser recuperado.<br> O identificador do certificado poderá ter os seguintes formatos: ID, CA\@SN ou ISPB\@DOMINIO.<br>
                                O tamanho exato para CA é #ND_SPB_CA_LEN e o tamanho máximo para SN é #ND_SPB_SN_MAX_LEN.<br> O tamanho máximo para o identificador é #ND_SPB_ID_MAX_LEN.<br> Exemplo: 03\@12345678 onde \a 03 é o identificador da CA e \a 12345678 é o número de série do certificado.<br> O tamanho exato para ISPB é #ND_SPB_ISPB_LEN e o tamanho máximo para DOMINIO é #ND_SPB_DOMAIN_MAX_LEN.<br> O tamanho máximo para o identificador é #ND_SPB_ID_MAX_LEN.<br> Exemplo: 12345678\@MES01 onde \a 12345678 é o ISPB da instituição e \a MES01 é o identificador do DOMÍNIO.
 \param[out] pstExtMap      Ponteiro para um #EXT_MAP_2_OBJ_INFO que conterá as informações do MAP requisitado.
 \param[in] dwParam         \ReservedParamBrief{0}

 \return \APIReturn_brief
 */
int AAP_API DSPBMapInfo (
    HSESSIONCTX hSession,
    char *szIdCert,
    EXT_MAP_2_OBJ_INFO *pstExtMap,
    DWORD dwParam
);

/**
 API auxiliar que cria ou altera um map SPB. O map é identificado a partir dos dados de CA e NS do certificado fornecido.

 \param_hSession
 \param[in] szISPB      ISPB da instituição. Deve ter tamanho máximo de #MAX_OBJ_ID_FQN_LEN.
 \param[in] szKeyId     Nome da chave privada da instituição. Deve ter tamanho máximo de #MAX_OBJ_ID_FQN_LEN.<br> Pode ser NULL caso esteja definindo apenas o certificado.
 \param[in] szCertId    Nome do certificado da instituição. Deve ter tamanho máximo de #MAX_OBJ_ID_FQN_LEN.
 \param[in] dwParam     A seguinte tabela de flags é suportada.
                        Valor | Significado
                        :-----|:-----------
                        0 | Utiliza o padrão SPB(Sistema de Pagamentos Brasileiro).
                        #ND_SPB_USE_CIP1 | Utiliza o padrão CIP(Camara Interbancaria de Pagamentos).
						#ND_SPB_USE_ANY | Aceita o padrão CIP e SPB. A detecção é feita internamente.

 \return \APIReturn_brief
 */
int AAP_API DSPBSetISPBMap (
    HSESSIONCTX hSession,
    char *szISPB,
    char *szKeyId,
    char *szCertId,
    DWORD dwParam
);

/** @} End of SPB grouping*/

/* Esta API pertence ao grupo SPB, mas precisa da documentacao*/
int AAP_API DSPBGetCertificateList (
    HSESSIONCTX hSession,
    char *szDomain,
    BOOL bActive,
    DBLOB **pdbList,
    DWORD *pdwListLen,
    DWORD dwParam
);

/**
 \addtogroup blockchain

  @{ */

/**
 Cria uma chave Extended Private Key (XPrv) para a blockchain no padrão [BIP32](https://github.com/bitcoin/bips/blob/master/bip-0032.mediawiki).

 \param_hSession
 \param[in] bType       Tipo de geração da chave.
                        Valor | Significado
                        :-----|:-----------
                        #DN_BCHAIN_BTC_MINIKEY | Bitcoin minikey. \p pcbData deve ser NULL e \p dwDataLen deve ser 0.
                        #DN_BCHAIN_BIP32_SEED_XPRV | BIP32 seed XPrv. \p pcbData deve conter a estrutura #DN_BCHAIN_BIP32_SEED_XPRV_DATA preenchida.
                        #DN_BCHAIN_BIP39_SEED_XPRV | BIP39 seed XPrv. \p pcbData deve conter a estrutura #DN_BCHAIN_BIP39_SEED_XPRV_DATA preenchida.
                        #DN_BCHAIN_BIP32_XPRV | BIP32 XPrv. \p dwDataLen deve ser um BYTE contendo a versão da chave. Ver anotações para mais detalhes.
 \param[in] dwAttributes  Parâmetros adicionais da chave. Veja as opções na função DGenerateKey(). Esta API inclui automaticamente a flag #BCHAIN_KEY, que é necessária para as operações de blockchain.
 \param[in] szId        Nome da chave no HSM. Deve ter tamanho máximo de #MAX_OBJ_ID_FQN_LEN.
 \param[in] pcbData     Buffer contendo os dados necessários para a geração da chave. Os dados de entrada devem ser passados de acordo com a opção \p bType e o tamanho dos dados passados aqui devem ser especificados em \p dwDataLen.
 \param[in] dwDataLen   Tamanho dos dados passados em \p pcbData.
 \param[in] dwReserved  \ReservedParamBrief{0}

 \return \APIReturn_brief

 \remarks

 Valor | Significado
 :-----|:-----------
#DN_BCHAIN_VER_WIF_MAIN_NET | WIF main net.
#DN_BCHAIN_VER_WIF_TEST_NET | WIF test net.
 */
int AAP_API DBchainCreateXPrv(HSESSIONCTX hSession, BYTE bType, DWORD dwAttributes,
                              const char *szId, const BYTE *pcbData, DWORD dwDataLen,
                              DWORD dwReserved);

/**
 Faz uma operação de Child Key Derivation (CKD). Deriva uma chave Extended Private Key (XPrv) para a blockchain no padrão [BIP32](https://github.com/bitcoin/bips/blob/master/bip-0032.mediawiki).

 \param_hSession
 \param[in] bVersion    Versão da chave.
                        Valor | Significado
                        :-----|:-----------
                        #DN_BCHAIN_VER_WIF_MAIN_NET | WIF main net.
                        #DN_BCHAIN_VER_WIF_TEST_NET | WIF test net.
 \param[in] dwIndex     Índice da chave que será derivada.
 \param[in] dwAttributes Parâmetros adicionais da chave. Veja as opções na função DGenerateKey(). Esta API inclui automaticamente a flag #BCHAIN_KEY, que é necessária para as operações de blockchain.
 \param[in] cszPar      Nome da chave pai no HSM. Deve ter tamanho máximo de #MAX_OBJ_ID_FQN_LEN.
 \param[in] cszDst      Nome da chave que será derivada no HSM. Deve ter tamanho máximo de #MAX_OBJ_ID_FQN_LEN.
 \param[out] pKeyInfo   Ponteiro para a estrutura #DN_BCHAIN_KEY_INFO que conterá as informações da chave gerada.
 \param[in] dwReserved  \ReservedParamBrief{0}

 \return \APIReturn_brief
 */
int AAP_API DBchainCreateBip32Ckd(HSESSIONCTX hSession, BYTE bVersion, DWORD dwIndex,
                                  DWORD dwAttributes, const char *cszPar,
                                  const char *cszDst, DN_BCHAIN_KEY_INFO *pKeyInfo,
                                  DWORD dwReserved);

/**
 Recupera o endereço de uma chave.

 \param_hSession
 \param[in] bType       Tipo do endereço a ser gerado. Pode ser um dos valores abaixo.
                        Valor | Significado
                        :-----|:-----------
                        #DN_BCHAIN_AT_BTC_P2PKH         | Endereço P2PKH.
                        #DN_BCHAIN_AT_BTC_P2SH          | Endereço P2SH. Não implementado.
                        #DN_BCHAIN_AT_BTC_B32_PKH       | Endereço BIP32 P2PKH.
                        #DN_BCHAIN_AT_BTC_B32_SH        | Endereço BIP32 P2SH. Não implementado.
                        #DN_BCHAIN_AT_ETH_EOA           | Endereço ETH EOA.
                        #DN_BCHAIN_AT_ETH_EOA_MC_CKS    | Endereço ETH EOA MC CKS. EIP55.
                        #DN_BCHAIN_AT_ETH_EOA_ICAP      | Endereço ETH EOA ICAP.

 \param[in] bVersion    Versão do endereço.
                        Valor | Significado
                        :-----|:-----------
                        #DN_BCHAIN_VER_UNUSED           | Unused.
                        #DN_BCHAIN_VER_BTC_A1_MAIN_NET  | Bitcoin A1 mainnet.
                        #DN_BCHAIN_VER_BTC_A3_MAIN_NET  | Bitcoin A3 mainnet.
                        #DN_BCHAIN_VER_BTC_B32_WITVER   | Bitcoin B32 witver.

 \param[in] cszHrp      HRP (Human Readable Part) da chave. Os valores da tabela são aceitos. Deve ter tamanho máximo de #DN_BCHAIN_MAX_HRP.
                        Valor | Significado
                        :-----|:-----------
                        #DN_BCHAIN_HRP_UNUSED       | Unused.
                        #DN_BCHAIN_HRP_BTC_MAIN_NET | Bitcoin mainnet.
                        #DN_BCHAIN_HRP_BTC_TEST_NET | Bitcoin testnet.
 \param[in] cszPk       Chave privada que será gerado o endereço.

 \param[in,out] pbAddress   Buffer que receberá o endereço. Pode ser NULL para obter o tamanho necessário. É recomendado utilizar o tamanho máximo de #DN_BCHAIN_MAX_ADDR_LEN.
 \param[in,out] pdwAddressLen   Tamanho do buffer \p pbAddress. Caso o buffer \p pbAddress seja NULL, este parâmetro receberá o tamanho necessário.
 \param[in] dwReserved  \ReservedParamBrief{0}

 \return \APIReturn_brief
 */
int AAP_API DBchainGetAddress(HSESSIONCTX hSession, BYTE bType, BYTE bVer,
                              const char *cszHrp, const char *cszPk,
                              BYTE *pbAddress, DWORD *pdwAddressLen,
                              DWORD dwReserved);

/**
 Assina um hash.

 \param_hSession
 \param[in] bType       Tipo da assinatura a ser gerada. Pode ser um dos valores abaixo.
                        Valor | Significado
                        :-----|:-----------
                        #DN_BCHAIN_SIG_DER_ECDSA  | Assinatura DER, no formato v || DER. SECG!SEC1 strict DER com low S como descrito em BIP62/66, BIP146, EIP2. Tendo 'v' o tamanho de 1 byte. 'v' é o bit de pariadade de 'r' podendo ter os valores 0 ou 1.
                        #DN_BCHAIN_SIG_RAW_ECDSA  | Assinatura RAW, no formato v || r || s. Tendo 'v' o tamanho de 1 byte e 'r' e 's' cada uma o tamanho de 32 bytes. 'v' é o bit de pariadade de 'r' podendo ter os valores 0 ou 1.
                        #DN_BCHAIN_SIG_BIP340     | Assinatura BIP340 - Schnorr 64 bytes.

 \param[in] bHashMode   Tipo do hash.
                        Valor | Significado
                        :-----|:-----------
                        #DN_BCHAIN_HASH_BTC_H160      | Bitcoin H160.
                        #DN_BCHAIN_HASH_RIPEMD160     | RIPEMD160.
                        #DN_BCHAIN_HASH_SHA256        | SHA256
                        #DN_BCHAIN_HASH_BTC_SHA256_2X | Bitcoin SHA256 2x.
                        #DN_BCHAIN_HASH_KECCAK256     | KECCAK256.
 \param[in] pbHash      Hash calculado de acordo com o informado em \p bHashMode.
 \param[in] dwHashLen   Tamanho do hash informado em \p pbHash.
 \param[in] cszPk       Nome da chave privada.
 \param[in,out] pbSig   Buffer que receberá a assinatura. Pode ser NULL para obter o tamanho necessário. É recomendado utilizar o tamanho máximo de #DN_BCHAIN_MAX_SIG_LEN.
 \param[in,out] pdwSigLen   Tamanho do buffer \p pbSig. Caso o buffer \p pbSig seja NULL, este parâmetro receberá o tamanho necessário.
 \param[in] dwReserved  \ReservedParamBrief{0}

 \return \APIReturn_brief
 */
int AAP_API DBchainSignHash(HSESSIONCTX hSession, BYTE bType, BYTE bHashMode,
                            BYTE *pbHash, DWORD dwHashLen, const char *cszPk,
                            BYTE *pbSig, DWORD *pdwSigLen, DWORD dwReserved);

/** @} End of Blockchain grouping*/

#ifdef __cplusplus
  }
#endif

#endif /* #ifndef NETDFENCE_H_INCLUDED */
