/*
 * $Id: translate_test.c,v 1.2 2016-11-22 17:23:50 obarthel Exp $
 *
 * :ts=4
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dos.h>

extern char __current_path_name[];

int
main(int argc,char ** argv)
{
	struct name_translation_info nti;
	char * name;
	int error;
	int i;

	/*strcpy(__current_path_name,"/absolute_path_name/whatever");*/

	for(i = 1 ; i < argc ; i++)
	{
		name = argv[i];

		printf("'%s' -> ",name);

		error = __translate_unix_to_amiga_path_name(&name,&nti);
		/*error = __translate_amiga_to_unix_path_name(&name,&nti);*/
		if(error == 0)
			printf("'%s'\n",name);
		else
			printf("%s\n",strerror(error));
	}

	return(0);
}
