#include <process_copy.h>



int pram_check(int argc, const char* sfile, int pronum) 
{
	if ( argc < 3 ) 
	{
		printf("error: pram too less.\n");
		exit(0);
	}

	if ( 0 != access(sfile, F_OK) ) 
	{
		printf("error: source file not exist.\n");
		exit(0);
	}

	if ( pronum <= 0 || pronum > 100 ) 
	{
		printf("error: process number should > 0 and < 100");
		exit(0);
	}
	
	return 0;
}
