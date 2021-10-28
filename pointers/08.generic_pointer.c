#include <stdio.h>

int data[3];
char *words[3];

int main(int argc, char **argv)
{
	void *gp;

	char *word = "rijec";
	printf("%s\n",word);

	for(int i = 0; i < 3;i++)
	{
		data[i] = i;
	}
	words[0] = "zero";
	words[1] = "one";
	words[2] = "two";
	
	gp = data;
	printf("\nAddress of array data is:%p\n",gp);
	for(int i = 0; i < 3; i++)
	{
		printf("Value pointed to by gp is %d\n",*(int *)gp);
		gp = (int*)gp+1;
	}
	gp=words;
	printf("\nAddress of array of strings words is:%p\n",gp);
	for(int i = 0;i < 3; i++)
	{
		printf("Value pointed to by gp is:%s\n",*(char **)gp);
		gp  = (char **)gp+1;
	}

	return 0;
}
