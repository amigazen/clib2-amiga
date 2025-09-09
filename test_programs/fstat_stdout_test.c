/*
 * $Id: fstat_stdout_test.c,v 1.2 2016-11-22 17:23:50 obarthel Exp $
 *
 * :ts=4
 */

#include <sys/stat.h>

#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>

/****************************************************************************/

int
main(int argc,char ** argv)
{
	struct stat st;
	int fd;

	fd = dup(STDOUT_FILENO);
	if(fd < 0)
	{
		perror("dup(STDOUT_FILENO)");
		return(EXIT_FAILURE);
	}

	if(fstat(fd,&st) < 0)
	{
		perror("fstat(fd,&st)");
		return(EXIT_FAILURE);
	}

	return(EXIT_SUCCESS);
}
