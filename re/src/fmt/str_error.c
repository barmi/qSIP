/**
 * @file str_error.c System error messages
 *
 * Copyright (C) 2010 Creytiv.com
 */
#define _GNU_SOURCE 1
#define __EXTENSIONS__ 1
#include <string.h>
#include <re_types.h>
#include <re_fmt.h>


/**
 * Look up an error message string corresponding to an error number.
 *
 * @param errnum Error Code
 * @param buf    Buffer for storing error message
 * @param sz     Buffer size
 *
 * @return Error message string
 */
const char *str_error(int errnum, char *buf, size_t sz)
{
	char *s = buf;

	if (!buf || !sz)
		return NULL;

	buf[0] = '\0';
#ifdef HAVE_STRERROR_R

#ifdef __GLIBC__
	s = strerror_r(errnum, buf, sz);
#else
	(void)strerror_r(errnum, buf, sz);
	s = buf;
#endif

#elif defined (__BORLANDC__)
	switch (errnum)
	{
	case EAUTH:
		return "Authorization error";
	case ENODATA:
		return "No data available";
	case EPROTO:
		return "Protocol error";
	case EBADMSG:
		return "Bad message";
	case EOVERFLOW:
		return "Value too large for defined data type";
	case ELIBBAD:
		return "Error loading shared library";
	case EDESTADDRREQ:
		return "Destination address required";
	case EPROTONOSUPPORT:
		return "Protocol not supported";
	case ENOTSUP:
		return "Operation not supported";
	case EAFNOSUPPORT:
		return "Address family not supported by protocol";
	case EADDRNOTAVAIL:
		return "Cannot assign requested address";
	case ECONNABORTED:
		return "Software caused connection abort";
	case ECONNRESET:
		return "Connection reset by peer";
	case ENOTCONN:
		return "Transport endpoint is not connected";
	case ETIMEDOUT:
		return "Connection timed out";
	case ECONNREFUSED:
		return "Connection refused";
	case EALREADY:
		return "Operation already in progress";
	case EINPROGRESS:
		return "Operation now in progress";

	case E_SIP_SESSION_CLOSED_BYE:
		return "End of call (BYE received)";
	case E_SIP_SESSION_CLOSED_CANCEL:
		return "End of call (CANCEL received)";
	default:
		strncpy(buf, strerror(errnum), sz);
		{
			// get rid of trailing \n character
			char* last;
			buf[sz - 1] = '\0';
			last = &buf[strlen(buf)-1];
			if (*last == '\n') {
				*last = '\0';
			}
		}
		s = buf;
		break;
	}
#elif defined (WIN32) & !defined (__MINGW32__)
	(void)strerror_s(buf, sz, errnum);
	s = buf;
#else
	/* fallback */
	(void)errnum;
	s = "unknown error";
	return s;
#endif

	buf[sz - 1] = '\0';

	return buf;
}
