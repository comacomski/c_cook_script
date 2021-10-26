#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
	char str1[]="Hello";//string as array of chars
	char *str2="Goodbye";//string as char pointer

	printf("%d %d %s\n",&str1, str1, str1);//&str1=address of first char in array, str1 same as &str1
	printf("%d %d %s\n",&str2, str2, str2);//&str2=address where is pointer variable stored 
	return 0;
}
