/* soapClient.c
   Generated by gSOAP 2.8.2 from mbatch_server.h
   Copyright(C) 2000-2011, Robert van Engelen, Genivia Inc. All Rights Reserved.
   The generated code is released under one of the following licenses:
   GPL OR Genivia's license for commercial use.
*/

#if defined(__BORLANDC__)
#pragma option push -w-8060
#pragma option push -w-8004
#endif
#include "soapH.h"
#ifdef __cplusplus
extern "C" {
#endif

SOAP_SOURCE_STAMP("@(#) soapClient.c ver 2.8.2 2011-06-20 21:40:23 GMT")


SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__send(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns1__send *ns1__send, struct ns1__sendResponse *ns1__sendResponse)
{	struct __ns1__send soap_tmp___ns1__send;
	if (!soap_endpoint)
		soap_endpoint = "http://localhost:8080/WebServiceBatch/BatchFile";
	if (!soap_action)
		soap_action = "";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__send.ns1__send = ns1__send;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__send(soap, &soap_tmp___ns1__send);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__send(soap, &soap_tmp___ns1__send, "-ns1:send", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__send(soap, &soap_tmp___ns1__send, "-ns1:send", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__sendResponse)
		return soap_closesock(soap);
	soap_default_ns1__sendResponse(soap, ns1__sendResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_ns1__sendResponse(soap, ns1__sendResponse, "ns1:sendResponse", "ns1:sendResponse");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__checkStatus(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns1__checkStatus *ns1__checkStatus, struct ns1__checkStatusResponse *ns1__checkStatusResponse)
{	struct __ns1__checkStatus soap_tmp___ns1__checkStatus;
	if (!soap_endpoint)
		soap_endpoint = "http://localhost:8080/WebServiceBatch/BatchFile";
	if (!soap_action)
		soap_action = "";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__checkStatus.ns1__checkStatus = ns1__checkStatus;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__checkStatus(soap, &soap_tmp___ns1__checkStatus);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__checkStatus(soap, &soap_tmp___ns1__checkStatus, "-ns1:checkStatus", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__checkStatus(soap, &soap_tmp___ns1__checkStatus, "-ns1:checkStatus", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__checkStatusResponse)
		return soap_closesock(soap);
	soap_default_ns1__checkStatusResponse(soap, ns1__checkStatusResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_ns1__checkStatusResponse(soap, ns1__checkStatusResponse, "ns1:checkStatusResponse", "ns1:checkStatusResponse");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__checkStatusMessage(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns1__checkStatusMessage *ns1__checkStatusMessage, struct ns1__checkStatusMessageResponse *ns1__checkStatusMessageResponse)
{	struct __ns1__checkStatusMessage soap_tmp___ns1__checkStatusMessage;
	if (!soap_endpoint)
		soap_endpoint = "http://localhost:8080/WebServiceBatch/BatchFile";
	if (!soap_action)
		soap_action = "";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__checkStatusMessage.ns1__checkStatusMessage = ns1__checkStatusMessage;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__checkStatusMessage(soap, &soap_tmp___ns1__checkStatusMessage);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__checkStatusMessage(soap, &soap_tmp___ns1__checkStatusMessage, "-ns1:checkStatusMessage", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__checkStatusMessage(soap, &soap_tmp___ns1__checkStatusMessage, "-ns1:checkStatusMessage", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__checkStatusMessageResponse)
		return soap_closesock(soap);
	soap_default_ns1__checkStatusMessageResponse(soap, ns1__checkStatusMessageResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_ns1__checkStatusMessageResponse(soap, ns1__checkStatusMessageResponse, "ns1:checkStatusMessageResponse", "ns1:checkStatusMessageResponse");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__validRegister(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns1__validRegister *ns1__validRegister, struct ns1__validRegisterResponse *ns1__validRegisterResponse)
{	struct __ns1__validRegister soap_tmp___ns1__validRegister;
	if (!soap_endpoint)
		soap_endpoint = "http://localhost:8080/WebServiceBatch/BatchFile";
	if (!soap_action)
		soap_action = "";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__validRegister.ns1__validRegister = ns1__validRegister;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__validRegister(soap, &soap_tmp___ns1__validRegister);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__validRegister(soap, &soap_tmp___ns1__validRegister, "-ns1:validRegister", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__validRegister(soap, &soap_tmp___ns1__validRegister, "-ns1:validRegister", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__validRegisterResponse)
		return soap_closesock(soap);
	soap_default_ns1__validRegisterResponse(soap, ns1__validRegisterResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_ns1__validRegisterResponse(soap, ns1__validRegisterResponse, "ns1:validRegisterResponse", "ns1:validRegisterResponse");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__invalidRegister(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns1__invalidRegister *ns1__invalidRegister, struct ns1__invalidRegisterResponse *ns1__invalidRegisterResponse)
{	struct __ns1__invalidRegister soap_tmp___ns1__invalidRegister;
	if (!soap_endpoint)
		soap_endpoint = "http://localhost:8080/WebServiceBatch/BatchFile";
	if (!soap_action)
		soap_action = "";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__invalidRegister.ns1__invalidRegister = ns1__invalidRegister;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__invalidRegister(soap, &soap_tmp___ns1__invalidRegister);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__invalidRegister(soap, &soap_tmp___ns1__invalidRegister, "-ns1:invalidRegister", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__invalidRegister(soap, &soap_tmp___ns1__invalidRegister, "-ns1:invalidRegister", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__invalidRegisterResponse)
		return soap_closesock(soap);
	soap_default_ns1__invalidRegisterResponse(soap, ns1__invalidRegisterResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_ns1__invalidRegisterResponse(soap, ns1__invalidRegisterResponse, "ns1:invalidRegisterResponse", "ns1:invalidRegisterResponse");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__totalRegister(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns1__totalRegister *ns1__totalRegister, struct ns1__totalRegisterResponse *ns1__totalRegisterResponse)
{	struct __ns1__totalRegister soap_tmp___ns1__totalRegister;
	if (!soap_endpoint)
		soap_endpoint = "http://localhost:8080/WebServiceBatch/BatchFile";
	if (!soap_action)
		soap_action = "";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__totalRegister.ns1__totalRegister = ns1__totalRegister;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__totalRegister(soap, &soap_tmp___ns1__totalRegister);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__totalRegister(soap, &soap_tmp___ns1__totalRegister, "-ns1:totalRegister", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__totalRegister(soap, &soap_tmp___ns1__totalRegister, "-ns1:totalRegister", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__totalRegisterResponse)
		return soap_closesock(soap);
	soap_default_ns1__totalRegisterResponse(soap, ns1__totalRegisterResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_ns1__totalRegisterResponse(soap, ns1__totalRegisterResponse, "ns1:totalRegisterResponse", "ns1:totalRegisterResponse");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__sentMessage(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct ns1__sentMessage *ns1__sentMessage, struct ns1__sentMessageResponse *ns1__sentMessageResponse)
{	struct __ns1__sentMessage soap_tmp___ns1__sentMessage;
	if (!soap_endpoint)
		soap_endpoint = "http://localhost:8080/WebServiceBatch/BatchFile";
	if (!soap_action)
		soap_action = "";
	soap->encodingStyle = NULL;
	soap_tmp___ns1__sentMessage.ns1__sentMessage = ns1__sentMessage;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns1__sentMessage(soap, &soap_tmp___ns1__sentMessage);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__sentMessage(soap, &soap_tmp___ns1__sentMessage, "-ns1:sentMessage", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__sentMessage(soap, &soap_tmp___ns1__sentMessage, "-ns1:sentMessage", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__sentMessageResponse)
		return soap_closesock(soap);
	soap_default_ns1__sentMessageResponse(soap, ns1__sentMessageResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_ns1__sentMessageResponse(soap, ns1__sentMessageResponse, "ns1:sentMessageResponse", "ns1:sentMessageResponse");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

#ifdef __cplusplus
}
#endif

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of soapClient.c */
