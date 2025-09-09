/*
 * $Id: execvp_test.c,v 1.3 2016-11-22 17:23:50 obarthel Exp $
 *
 * :ts=4
 */

#include <unistd.h>

int
main(int argc,char ** argv)
{
	if(argc > 1)
		execvp(argv[1],&argv[1]);

	return(0);
}
