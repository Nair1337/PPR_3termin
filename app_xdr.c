/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "app.h"

bool_t
xdr_print_data (XDR *xdrs, print_data *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->buffer, 1024,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->size))
		 return FALSE;
	return TRUE;
}
