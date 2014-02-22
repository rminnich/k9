/* 
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#include <lib9.h>

extern	int	_SEGATTACH(int, char*, void*, unsigned long);

int
segattach(int attr, char *class, void *va, unsigned long len)
{
	return _SEGATTACH(attr, class, va, len);
}

