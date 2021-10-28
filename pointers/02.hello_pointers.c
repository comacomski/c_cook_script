#include <stdio.h>

int main(int argc,char **argv)
{
	int num;//declaration of integer
	int *numPtr;//declaration of pointer
	int num2;
	num=100;
	numPtr=&num;//&num= address of variable num
	num2=*numPtr;//*numPtr = value on numPtr address
	printf("num=%d, numPtr=%d, address of num=%d, num2=%d", num, numPtr, &num, num2);
	return 0;
}
