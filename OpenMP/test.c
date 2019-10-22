#include "omp.h"
#include <stdio.h>

#define ITERATIONS 1e6
#define THREADS 8

int calculateFactorial(int a, int ID)
{
	int start, end;
	start = (ITERATIONS / omp_get_num_threads()) * ID;
	end = (ITERATIONS / omp_get_num_threads()) * (ID + 1);
	int i = start;

	do{

	}

}

void main()
{
	#pragma omp parallel num_threads(4)
	{
		int ID = omp_get_thread_num();
		printf(" Hola (%id) ", ID);
		printf(" World (%id) ", ID);
	}
}
