#include <stdio.h>

/*
 *This program displays
 *any arguments that were passed to it
 */

int main(int argc, char **argv)
{
	int i;
	for(int i = 0; i < argc; i++)
	{
		printf("arg %d is %s\n",i, argv[i]);//prints arg on index i
	}
	printf("\n\n");

	for(int i = 0;i < argc; i++)
	{
		printf("arg %d is %s\n",i,*argv);
		argv++;
	}
	return 0;
}
