#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *function()
{
	// Dynamic allocatin of an integer number to be returned
	int *number_address = malloc(sizeof(int));

	printf("Allocated address (function): %p\n", number_address);

	*number_address = 5;

	return (void *)(number_address);
}


int main()
{
	pthread_t t1;
	int *result;

	pthread_create(&t1, NULL, &function, NULL);

	pthread_join(t1, (void **) &result);

	printf("Allocated address (main): %p\n", result);

	printf("Number returned: %d\n", *result);

	free(result);

	return 0;
}
