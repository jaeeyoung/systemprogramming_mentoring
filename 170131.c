#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
int counter=0;
#define NUM_THREAD 10000
void * thr_main(void *arg)
{
	counter++;
	return((void *)1);
}

int main(void)
{
	int err, i;
	pthread_t tid[NUM_THREAD];
	void *tret;

	for(int i=0; i<NUM_THREAD;++i)
	{
		err=pthread_create(&tid[i], NULL, thr_main, (void *)((intptr_t)i));
		if(err !=0 ) exit(1);
	}
	for (i=0; i<NUM_THREAD; ++i)
	{
		err = pthread_join(tid[i], &tret);
		if(err!=0) exit(2);
	}
	printf("done %d!\n", counter);
	return 0;
}
