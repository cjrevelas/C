#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *function()
{
	printf("Thread started executing the function\n");

	// Ensure that the threads run in parallel
	sleep(3);

	printf("Thread finished executing the function\n");
}

int main()
{
	pthread_t t1, t2;

	// Create the new threads and assign them the "function" task
	pthread_create(&t1, NULL, &function, NULL);
	pthread_create(&t2, NULL, &function, NULL);

	// Wait for the threads to end their task
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);


	return 0;
}
