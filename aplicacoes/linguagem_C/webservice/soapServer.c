/* soapServer.c
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

SOAP_SOURCE_STAMP("@(#) soapServer.c ver 2.8.2 2011-06-20 21:40:23 GMT")


SOAP_FMAC5 int SOAP_FMAC6 soap_serve(struct soap *soap)
{
#ifndef WITH_FASTCGI
	unsigned int k = soap->max_keep_alive;
#endif
	do
	{
#ifndef WITH_FASTCGI
		if (soap->max_keep_alive > 0 && !--k)
			soap->keep_alive = 0;
#endif
		if (soap_begin_serve(soap))
		{	if (soap->error >= SOAP_STOP)
				continue;
			return soap->error;
		}
		if (soap_serve_request(soap) || (soap->fserveloop && soap->fserveloop(soap)))
		{
#ifdef WITH_FASTCGI
			soap_send_fault(soap);
#else
			return soap_send_fault(soap);
#endif
		}

#ifdef WITH_FASTCGI
		soap_destroy(soap);
		soap_end(soap);
	} while (1);
#else
	} while (soap->keep_alive);
#endif
	return SOAP_OK;
}

#ifndef WITH_NOSERVEREQUEST
SOAP_FMAC5 int SOAP_FMAC6 soap_serve_request(struct soap *soap)
{
	soap_peek_element(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:send"))
		return soap_serve___ns1__send(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:checkStatus"))
		return soap_serve___ns1__checkStatus(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:checkStatusMessage"))
		return soap_serve___ns1__checkStatusMessage(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:validRegister"))
		return soap_serve___ns1__validRegister(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:invalidRegister"))
		return soap_serve___ns1__invalidRegister(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:totalRegister"))
		return soap_serve___ns1__totalRegister(soap);
	if (!soap_match_tag(soap, soap->tag, "ns1:sentMessage"))
		return soap_serve___ns1__sentMessage(soap);
	return soap->error = SOAP_NO_METHOD;
}
#endif

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__send(struct soap *soap)
{	struct __ns1__send soap_tmp___ns1__send;
	struct ns1__sendResponse ns1__sendResponse;
	soap_default_ns1__sendResponse(soap, &ns1__sendResponse);
	soap_default___ns1__send(soap, &soap_tmp___ns1__send);
	soap->encodingStyle = NULL;
	if (!soap_get___ns1__send(soap, &soap_tmp___ns1__send, "-ns1:send", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__send(soap, soap_tmp___ns1__send.ns1__send, &ns1__sendResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_ns1__sendResponse(soap, &ns1__sendResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns1__sendResponse(soap, &ns1__sendResponse, "ns1:sendResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns1__sendResponse(soap, &ns1__sendResponse, "ns1:sendResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__checkStatus(struct soap *soap)
{	struct __ns1__checkStatus soap_tmp___ns1__checkStatus;
	struct ns1__checkStatusResponse ns1__checkStatusResponse;
	soap_default_ns1__checkStatusResponse(soap, &ns1__checkStatusResponse);
	soap_default___ns1__checkStatus(soap, &soap_tmp___ns1__checkStatus);
	soap->encodingStyle = NULL;
	if (!soap_get___ns1__checkStatus(soap, &soap_tmp___ns1__checkStatus, "-ns1:checkStatus", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__checkStatus(soap, soap_tmp___ns1__checkStatus.ns1__checkStatus, &ns1__checkStatusResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_ns1__checkStatusResponse(soap, &ns1__checkStatusResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns1__checkStatusResponse(soap, &ns1__checkStatusResponse, "ns1:checkStatusResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns1__checkStatusResponse(soap, &ns1__checkStatusResponse, "ns1:checkStatusResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__checkStatusMessage(struct soap *soap)
{	struct __ns1__checkStatusMessage soap_tmp___ns1__checkStatusMessage;
	struct ns1__checkStatusMessageResponse ns1__checkStatusMessageResponse;
	soap_default_ns1__checkStatusMessageResponse(soap, &ns1__checkStatusMessageResponse);
	soap_default___ns1__checkStatusMessage(soap, &soap_tmp___ns1__checkStatusMessage);
	soap->encodingStyle = NULL;
	if (!soap_get___ns1__checkStatusMessage(soap, &soap_tmp___ns1__checkStatusMessage, "-ns1:checkStatusMessage", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__checkStatusMessage(soap, soap_tmp___ns1__checkStatusMessage.ns1__checkStatusMessage, &ns1__checkStatusMessageResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_ns1__checkStatusMessageResponse(soap, &ns1__checkStatusMessageResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns1__checkStatusMessageResponse(soap, &ns1__checkStatusMessageResponse, "ns1:checkStatusMessageResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns1__checkStatusMessageResponse(soap, &ns1__checkStatusMessageResponse, "ns1:checkStatusMessageResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__validRegister(struct soap *soap)
{	struct __ns1__validRegister soap_tmp___ns1__validRegister;
	struct ns1__validRegisterResponse ns1__validRegisterResponse;
	soap_default_ns1__validRegisterResponse(soap, &ns1__validRegisterResponse);
	soap_default___ns1__validRegister(soap, &soap_tmp___ns1__validRegister);
	soap->encodingStyle = NULL;
	if (!soap_get___ns1__validRegister(soap, &soap_tmp___ns1__validRegister, "-ns1:validRegister", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__validRegister(soap, soap_tmp___ns1__validRegister.ns1__validRegister, &ns1__validRegisterResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_ns1__validRegisterResponse(soap, &ns1__validRegisterResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns1__validRegisterResponse(soap, &ns1__validRegisterResponse, "ns1:validRegisterResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns1__validRegisterResponse(soap, &ns1__validRegisterResponse, "ns1:validRegisterResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__invalidRegister(struct soap *soap)
{	struct __ns1__invalidRegister soap_tmp___ns1__invalidRegister;
	struct ns1__invalidRegisterResponse ns1__invalidRegisterResponse;
	soap_default_ns1__invalidRegisterResponse(soap, &ns1__invalidRegisterResponse);
	soap_default___ns1__invalidRegister(soap, &soap_tmp___ns1__invalidRegister);
	soap->encodingStyle = NULL;
	if (!soap_get___ns1__invalidRegister(soap, &soap_tmp___ns1__invalidRegister, "-ns1:invalidRegister", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__invalidRegister(soap, soap_tmp___ns1__invalidRegister.ns1__invalidRegister, &ns1__invalidRegisterResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_ns1__invalidRegisterResponse(soap, &ns1__invalidRegisterResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns1__invalidRegisterResponse(soap, &ns1__invalidRegisterResponse, "ns1:invalidRegisterResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns1__invalidRegisterResponse(soap, &ns1__invalidRegisterResponse, "ns1:invalidRegisterResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__totalRegister(struct soap *soap)
{	struct __ns1__totalRegister soap_tmp___ns1__totalRegister;
	struct ns1__totalRegisterResponse ns1__totalRegisterResponse;
	soap_default_ns1__totalRegisterResponse(soap, &ns1__totalRegisterResponse);
	soap_default___ns1__totalRegister(soap, &soap_tmp___ns1__totalRegister);
	soap->encodingStyle = NULL;
	if (!soap_get___ns1__totalRegister(soap, &soap_tmp___ns1__totalRegister, "-ns1:totalRegister", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__totalRegister(soap, soap_tmp___ns1__totalRegister.ns1__totalRegister, &ns1__totalRegisterResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_ns1__totalRegisterResponse(soap, &ns1__totalRegisterResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns1__totalRegisterResponse(soap, &ns1__totalRegisterResponse, "ns1:totalRegisterResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns1__totalRegisterResponse(soap, &ns1__totalRegisterResponse, "ns1:totalRegisterResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__sentMessage(struct soap *soap)
{	struct __ns1__sentMessage soap_tmp___ns1__sentMessage;
	struct ns1__sentMessageResponse ns1__sentMessageResponse;
	soap_default_ns1__sentMessageResponse(soap, &ns1__sentMessageResponse);
	soap_default___ns1__sentMessage(soap, &soap_tmp___ns1__sentMessage);
	soap->encodingStyle = NULL;
	if (!soap_get___ns1__sentMessage(soap, &soap_tmp___ns1__sentMessage, "-ns1:sentMessage", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __ns1__sentMessage(soap, soap_tmp___ns1__sentMessage.ns1__sentMessage, &ns1__sentMessageResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_ns1__sentMessageResponse(soap, &ns1__sentMessageResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns1__sentMessageResponse(soap, &ns1__sentMessageResponse, "ns1:sentMessageResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns1__sentMessageResponse(soap, &ns1__sentMessageResponse, "ns1:sentMessageResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

#ifdef __cplusplus
}
#endif

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of soapServer.c */