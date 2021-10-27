#include <stdio.h>

#define LENGTH 3

char *words[LENGTH];

int main(int argc, char **argv)
{
	char *pc;
	char **ppc;//pointer to a char pointer

	printf("multiple indirection example:\n");

	words[0]="zero";
	words[1]="one";
	words[2]="two";
	for(int i = 0; i < LENGTH;i++)
	{
		printf("%s\n",words[i]);
	}
	/*
	 * A pointer to an array of strings is the 
	 * same as a pointer to a pointer to a character
	 * */
	printf("\nNow print the chars in each string:\n");
	ppc = words;
	for(int i = 0;i<LENGTH;i++)
	{
		ppc=words+i;
		pc=*ppc;
		while(*pc!=0)
		{
			printf("%c ",*pc);
			pc++;
		}
		printf("\n");
	}


	return 0;
}
