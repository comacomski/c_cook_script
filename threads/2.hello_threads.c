/*
 *Compiler : gcc
 *Author : Mico Antonic
 *
 * compile on Ubuntu using:
 * gcc -o hello_threads hello_threads.c -lpthread
 * */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>// For working with POSIX threads
#include <unistd.h>// For pause() and sleep()

static void * thread_fn_callback(void *arg)
{
	char *input = (char *)arg;
	while(1){
		printf("%s\n",input);
		sleep(1);
	}
}
void thread1_create()
{
	pthread_t pthread1;//opaque object, dont bother about its internal members
       /*Take some argument to be passed to the thread fn
	* Look after that you always pass the persistent memory 
	* as an argument o the thread, do not pass caller's 
	* local variables or stack memory*/
	static char *thread_input1 = "I am thread no. 1\n";
	/*Return 0 on success, otherwise returns errorcode,
	 * all pthread functions return -ve error code on failure
	 * they do not set global 'errno' variable*/
	int rc = pthread_create(&pthread1,
			NULL,
			thread_fn_callback,
			(void *) thread_input1);//Fork point
	if(rc!=0){
		printf("Error occured, thread could not be created, errno = %d",rc);
		exit(0);
	}	
}

int main()
{
	thread1_create();
	while(1){
		printf("I am main thread.\n");
		sleep(1);
	}
	return 0;
}
