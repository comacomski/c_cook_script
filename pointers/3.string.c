#include <stdio.h>

int main(int argc,char **argv)
{
	char str1[]="Hello World";//c automaticly adds '\0' (null) operator
	printf("%s %c %d %d %d\n",str1,str1[0], &str1, str1, &str1[0]);
	return 0;
}
