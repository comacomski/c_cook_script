/*
 *Compiler : gcc
 *Description: C program that demonstrates basic usage of 2 Joinable threads.
 *Author : Mico Antonic
 *
 * compile on Ubuntu using:
 * gcc -o joinable_thread_example joinable_thread_example.c -lpthread
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>/*For working with POSIX threads*/
#include <unistd.h>/*For pause() and sleep()*/
#include <errno.h>/*For using Global variable errno*/

pthread_t pthread2;
pthread_t pthread3;
pthread_attr_t attr;
void * thread_fn_callback(void *arg)//thread callback function must be in this form
{ 		
	int th_id = *(int *)arg;//converting argument into int
	free(arg);
	int rc=0;
	while(rc!=th_id){//This loop is just for demonstration purposes, just to simulate that this thread need some amount of time for his work
		printf("Thread %d doing some work\n",th_id);
		sleep(1);
		rc++;
	}
	//We must store the result in the heap memory
	int *result = calloc(1,sizeof(int));
	*result = th_id * th_id;
	return ((void *)result);
}
void thread_create(pthread_t *pthread_handle,int th_id)
{
	int *_th_id = calloc(1,sizeof(int));
	*_th_id = th_id;
	//pthread_attr_t *attr=calloc(1,sizeof(pthread_attr_t));//pthread type for setting type of a thread
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);//or PTHREAD_CREATE_DETACHED
	pthread_create(pthread_handle,&attr,thread_fn_callback,(void *)_th_id);//creation of the thread, fork point
}

int main(int argc, char **argv)
{
	void *thread_result2;
	void *thread_result3;
		
	thread_create(&pthread2, 2);
	thread_create(&pthread3, 10);
	/*main is waiting for threads to join(to terminate)
	 * 2nd argument of pthread_join function is collecting results*/
	printf("main fn blocked on pthread_join for thread with thread_id=2\n");
	pthread_join(pthread2,&thread_result2);
	if(thread_result2){
		printf("pthread2 returned result: %d\n",*(int *)thread_result2);
		free(thread_result2);
		thread_result2=NULL;
	}
	printf("main fn blocked on pthread_join for thread with thread_id=3\n");
	pthread_join(pthread3,&thread_result3);
	if(thread_result3){
		printf("pthread3 returned result: %d\n",*(int *)thread_result3);
		free(thread_result3);
		thread_result3=NULL;
	}
	return 0;
}
