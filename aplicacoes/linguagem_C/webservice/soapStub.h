/* soapStub.h
   Generated by gSOAP 2.8.2 from mbatch_server.h
   Copyright(C) 2000-2011, Robert van Engelen, Genivia Inc. All Rights Reserved.
   The generated code is released under one of the following licenses:
   GPL OR Genivia's license for commercial use.
*/

#ifndef soapStub_H
#define soapStub_H
#define SOAP_NAMESPACE_OF_ns2	""
#define SOAP_NAMESPACE_OF_ns2	""
#define SOAP_NAMESPACE_OF_ns1	"http://service.okto.com.br/"
#define SOAP_NAMESPACE_OF_ns3	"http://jaxb.dev.java.net/array"
#include "stdsoap2.h"
#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************\
 *                                                                            *
 * Enumerations                                                               *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Types with Custom Serializers                                              *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Classes and Structs                                                        *
 *                                                                            *
\******************************************************************************/


#if 0 /* volatile type: do not declare here, declared elsewhere */

#endif

#ifndef SOAP_TYPE_ns1__totalRegister
#define SOAP_TYPE_ns1__totalRegister (7)
/* ns1:totalRegister */
struct ns1__totalRegister
{
	char *client;	/* optional element of type xsd:string */
	char *user;	/* optional element of type xsd:string */
	char *password;	/* optional element of type xsd:string */
	int idBatch;	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ns1__totalRegisterResponse
#define SOAP_TYPE_ns1__totalRegisterResponse (8)
/* ns1:totalRegisterResponse */
struct ns1__totalRegisterResponse
{
	int return_;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ns1__BatchException
#define SOAP_TYPE_ns1__BatchException (9)
/* ns1:BatchException */
struct ns1__BatchException
{
	char *message;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns1__checkStatusMessage
#define SOAP_TYPE_ns1__checkStatusMessage (10)
/* ns1:checkStatusMessage */
struct ns1__checkStatusMessage
{
	char *client;	/* optional element of type xsd:string */
	char *user;	/* optional element of type xsd:string */
	char *password;	/* optional element of type xsd:string */
	int idMessage;	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ns1__checkStatusMessageResponse
#define SOAP_TYPE_ns1__checkStatusMessageResponse (11)
/* ns1:checkStatusMessageResponse */
struct ns1__checkStatusMessageResponse
{
	char *return_;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns1__sentMessage
#define SOAP_TYPE_ns1__sentMessage (12)
/* ns1:sentMessage */
struct ns1__sentMessage
{
	char *client;	/* optional element of type xsd:string */
	char *user;	/* optional element of type xsd:string */
	char *password;	/* optional element of type xsd:string */
	int idBatch;	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ns1__sentMessageResponse
#define SOAP_TYPE_ns1__sentMessageResponse (13)
/* ns1:sentMessageResponse */
struct ns1__sentMessageResponse
{
	int return_;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ns1__validRegister
#define SOAP_TYPE_ns1__validRegister (14)
/* ns1:validRegister */
struct ns1__validRegister
{
	char *client;	/* optional element of type xsd:string */
	char *user;	/* optional element of type xsd:string */
	char *password;	/* optional element of type xsd:string */
	int idBatch;	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ns1__validRegisterResponse
#define SOAP_TYPE_ns1__validRegisterResponse (15)
/* ns1:validRegisterResponse */
struct ns1__validRegisterResponse
{
	int return_;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ns1__checkStatus
#define SOAP_TYPE_ns1__checkStatus (16)
/* ns1:checkStatus */
struct ns1__checkStatus
{
	char *client;	/* optional element of type xsd:string */
	char *user;	/* optional element of type xsd:string */
	char *password;	/* optional element of type xsd:string */
	int idBatch;	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ns1__checkStatusResponse
#define SOAP_TYPE_ns1__checkStatusResponse (17)
/* ns1:checkStatusResponse */
struct ns1__checkStatusResponse
{
	char *return_;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns1__send
#define SOAP_TYPE_ns1__send (18)
/* ns1:send */
struct ns1__send
{
	char *client;	/* optional element of type xsd:string */
	char *user;	/* optional element of type xsd:string */
	char *password;	/* optional element of type xsd:string */
	char *startTime;	/* optional element of type xsd:string */
	char *endTime;	/* optional element of type xsd:string */
	int __sizefile;	/* sequence of elements <file> */
	struct ns3__stringArray *file;	/* optional element of type ns3:stringArray */
	int idMessage;	/* required element of type xsd:int */
	char *mail;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ns1__sendResponse
#define SOAP_TYPE_ns1__sendResponse (21)
/* ns1:sendResponse */
struct ns1__sendResponse
{
	int return_;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ns1__invalidRegister
#define SOAP_TYPE_ns1__invalidRegister (22)
/* ns1:invalidRegister */
struct ns1__invalidRegister
{
	char *client;	/* optional element of type xsd:string */
	char *user;	/* optional element of type xsd:string */
	char *password;	/* optional element of type xsd:string */
	int idBatch;	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ns1__invalidRegisterResponse
#define SOAP_TYPE_ns1__invalidRegisterResponse (23)
/* ns1:invalidRegisterResponse */
struct ns1__invalidRegisterResponse
{
	int return_;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ns3__stringArray
#define SOAP_TYPE_ns3__stringArray (19)
/* ns3:stringArray */
struct ns3__stringArray
{
	int __sizeitem;	/* sequence of elements <item> */
	char **item;	/* optional element of type xsd:string */
};
#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (25)
/* SOAP-ENV:Detail */
struct SOAP_ENV__Detail
{
	char *__any;
	struct ns1__BatchException *ns1__BatchException;	/* optional element of type ns1:BatchException */
	int __type;	/* any type of element <fault> (defined below) */
	void *fault;	/* transient */
};
#endif

#endif

#ifndef SOAP_TYPE___ns1__send
#define SOAP_TYPE___ns1__send (32)
/* Operation wrapper: */
struct __ns1__send
{
	struct ns1__send *ns1__send;	/* optional element of type ns1:send */
};
#endif

#ifndef SOAP_TYPE___ns1__checkStatus
#define SOAP_TYPE___ns1__checkStatus (36)
/* Operation wrapper: */
struct __ns1__checkStatus
{
	struct ns1__checkStatus *ns1__checkStatus;	/* optional element of type ns1:checkStatus */
};
#endif

#ifndef SOAP_TYPE___ns1__checkStatusMessage
#define SOAP_TYPE___ns1__checkStatusMessage (40)
/* Operation wrapper: */
struct __ns1__checkStatusMessage
{
	struct ns1__checkStatusMessage *ns1__checkStatusMessage;	/* optional element of type ns1:checkStatusMessage */
};
#endif

#ifndef SOAP_TYPE___ns1__validRegister
#define SOAP_TYPE___ns1__validRegister (44)
/* Operation wrapper: */
struct __ns1__validRegister
{
	struct ns1__validRegister *ns1__validRegister;	/* optional element of type ns1:validRegister */
};
#endif

#ifndef SOAP_TYPE___ns1__invalidRegister
#define SOAP_TYPE___ns1__invalidRegister (48)
/* Operation wrapper: */
struct __ns1__invalidRegister
{
	struct ns1__invalidRegister *ns1__invalidRegister;	/* optional element of type ns1:invalidRegister */
};
#endif

#ifndef SOAP_TYPE___ns1__totalRegister
#define SOAP_TYPE___ns1__totalRegister (52)
/* Operation wrapper: */
struct __ns1__totalRegister
{
	struct ns1__totalRegister *ns1__totalRegister;	/* optional element of type ns1:totalRegister */
};
#endif

#ifndef SOAP_TYPE___ns1__sentMessage
#define SOAP_TYPE___ns1__sentMessage (56)
/* Operation wrapper: */
struct __ns1__sentMessage
{
	struct ns1__sentMessage *ns1__sentMessage;	/* optional element of type ns1:sentMessage */
};
#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (57)
/* SOAP Header: */
struct SOAP_ENV__Header
{
#ifdef WITH_NOEMPTYSTRUCT
	char dummy;	/* dummy member to enable compilation */
#endif
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (58)
/* SOAP Fault Code: */
struct SOAP_ENV__Code
{
	char *SOAP_ENV__Value;	/* optional element of type xsd:QName */
	struct SOAP_ENV__Code *SOAP_ENV__Subcode;	/* optional element of type SOAP-ENV:Code */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (60)
/* SOAP-ENV:Reason */
struct SOAP_ENV__Reason
{
	char *SOAP_ENV__Text;	/* optional element of type xsd:string */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (61)
/* SOAP Fault: */
struct SOAP_ENV__Fault
{
	char *faultcode;	/* optional element of type xsd:QName */
	char *faultstring;	/* optional element of type xsd:string */
	char *faultactor;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *detail;	/* optional element of type SOAP-ENV:Detail */
	struct SOAP_ENV__Code *SOAP_ENV__Code;	/* optional element of type SOAP-ENV:Code */
	struct SOAP_ENV__Reason *SOAP_ENV__Reason;	/* optional element of type SOAP-ENV:Reason */
	char *SOAP_ENV__Node;	/* optional element of type xsd:string */
	char *SOAP_ENV__Role;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *SOAP_ENV__Detail;	/* optional element of type SOAP-ENV:Detail */
};
#endif

#endif

/******************************************************************************\
 *                                                                            *
 * Typedefs                                                                   *
 *                                                                            *
\******************************************************************************/

#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
typedef char *_QName;
#endif

#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (6)
typedef char *_XML;
#endif


/******************************************************************************\
 *                                                                            *
 * Externals                                                                  *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Server-Side Operations                                                     *
 *                                                                            *
\******************************************************************************/


SOAP_FMAC5 int SOAP_FMAC6 __ns1__send(struct soap*, struct ns1__send *ns1__send, struct ns1__sendResponse *ns1__sendResponse);

SOAP_FMAC5 int SOAP_FMAC6 __ns1__checkStatus(struct soap*, struct ns1__checkStatus *ns1__checkStatus, struct ns1__checkStatusResponse *ns1__checkStatusResponse);

SOAP_FMAC5 int SOAP_FMAC6 __ns1__checkStatusMessage(struct soap*, struct ns1__checkStatusMessage *ns1__checkStatusMessage, struct ns1__checkStatusMessageResponse *ns1__checkStatusMessageResponse);

SOAP_FMAC5 int SOAP_FMAC6 __ns1__validRegister(struct soap*, struct ns1__validRegister *ns1__validRegister, struct ns1__validRegisterResponse *ns1__validRegisterResponse);

SOAP_FMAC5 int SOAP_FMAC6 __ns1__invalidRegister(struct soap*, struct ns1__invalidRegister *ns1__invalidRegister, struct ns1__invalidRegisterResponse *ns1__invalidRegisterResponse);

SOAP_FMAC5 int SOAP_FMAC6 __ns1__totalRegister(struct soap*, struct ns1__totalRegister *ns1__totalRegister, struct ns1__totalRegisterResponse *ns1__totalRegisterResponse);

SOAP_FMAC5 int SOAP_FMAC6 __ns1__sentMessage(struct soap*, struct ns1__sentMessage *ns1__sentMessage, struct ns1__sentMessageResponse *ns1__sentMessageResponse);

/******************************************************************************\
 *                                                                            *
 * Server-Side Skeletons to Invoke Service Operations                         *
 *                                                                            *
\******************************************************************************/

SOAP_FMAC5 int SOAP_FMAC6 soap_serve(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_request(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__send(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__checkStatus(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__checkStatusMessage(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__validRegister(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__invalidRegister(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__totalRegister(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__sentMessage(struct soap*);

/******************************************************************************\
 *                                                                            *
 * Client-Side Call Stubs                                                     *
 *                                                                            *
\******************************************************************************/


SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__send(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns1__send *ns1__send, struct ns1__sendResponse *ns1__sendResponse);

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__checkStatus(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns1__checkStatus *ns1__checkStatus, struct ns1__checkStatusResponse *ns1__checkStatusResponse);

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__checkStatusMessage(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns1__checkStatusMessage *ns1__checkStatusMessage, struct ns1__checkStatusMessageResponse *ns1__checkStatusMessageResponse);

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__validRegister(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns1__validRegister *ns1__validRegister, struct ns1__validRegisterResponse *ns1__validRegisterResponse);

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__invalidRegister(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns1__invalidRegister *ns1__invalidRegister, struct ns1__invalidRegisterResponse *ns1__invalidRegisterResponse);

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__totalRegister(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns1__totalRegister *ns1__totalRegister, struct ns1__totalRegisterResponse *ns1__totalRegisterResponse);

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__sentMessage(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns1__sentMessage *ns1__sentMessage, struct ns1__sentMessageResponse *ns1__sentMessageResponse);

#ifdef __cplusplus
}
#endif

#endif

/* End of soapStub.h */
