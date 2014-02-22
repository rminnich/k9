/* 
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#include "astro.h"

double	nutfp[] =
{
	  .2088,	0,
	-1.2730,	0,
	  .1258,	0,
	 -.0496,	0,
	  .0214,	0,
	  .0124,	0,
	      0,

	 9.2109,	0,
	 -.0904,	0,
	  .5519,	0,
	  .0215,	0,
	 -.0093,	0,
	 -.0066,	0,
	      0,

	 -.2037,	0,
	  .0675,	0,
	 -.0342,	0,
	 -.0261,	0,
	 -.0149,	0,
	  .0114,	0,
	  .0060,	0,
	  .0058,	0,
	 -.0057,	0,
	 -.0052,	0,
	      0,

	  .0884,	0,
	  .0183,	0,
	  .0113,	0,
	 -.0050,	0,
	      0,
};

char	nutcp[] =
{
	2,0,0,0,
	2,2,-2,0,
	0,0,0,1,
	2,2,-2,1,
	2,2,-2,-1,
	1,2,-2,0,

	1,0,0,0,
	2,0,0,0,
	2,2,-2,0,
	2,2,-2,1,
	2,2,-2,-1,
	1,2,-2,0,

	2,2,0,0,
	0,0,1,0,
	1,2,0,0,
	2,2,1,0,
	0,0,1,-2,
	2,2,-1,0,
	0,0,0,2,
	1,0,1,0,
	1,0,-1,0,
	2,2,-1,2,

	2,2,0,
	1,2,0,
	2,2,1,
	2,2,-1,
};
