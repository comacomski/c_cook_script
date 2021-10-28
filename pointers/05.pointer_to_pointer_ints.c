#include <stdio.h>

#define LENGTH 3

int data[LENGTH];

int main(int argc, char **argv)
{
	int *pi;
	int **ppi;

	printf("multiple indirection example:\n");

	for(int i=0;i<LENGTH;i++)
	{
		data[i]=i;
	}
	for(int i=0;i<LENGTH;i++)
	{
		printf("%d\n",data[i]);
	}
	pi=data;//set the pointer to an integer to the start of the data array
	ppi=&pi;//set the pointer to a pointer to pi itself

	for(int i=0;i<LENGTH;i++)
	{
		printf("\n Loop [%d] array address is %p\n",i,data);
		printf("item pointed to by pi is %d\n",*pi);
		printf("item pointed to by ppi is %p\n",*ppi);
		printf("item pointed to by double indirection of ppi is %d\n",**ppi);
		printf("the address of pi is %p and the value of ppi (what it points to) is %p\n", &pi,ppi);
	}
	return 0;
}
