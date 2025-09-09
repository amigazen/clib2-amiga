/*
 * $Id: strtok_test.c,v 1.2 2016-11-22 17:23:50 obarthel Exp $
 *
 * :ts=4
 */

/****************************************************************************/

#include <string.h>
#include <stdio.h>

/****************************************************************************/

int
main(int argc,char ** argv)
{
	char test[256];
	char * one;
	char * two;
	char * three;

	strcpy(test,"   one    two    three");

	strtok(test," ");

	one		= strtok(NULL," ");
	two		= strtok(NULL," ");
	three	= strtok(NULL," ");

	printf("one = %p '%s'\n",one,one);
	printf("two = %p '%s'\n",two,two);
	printf("three = %p '%s'\n",three,three);

	return(0);
}
