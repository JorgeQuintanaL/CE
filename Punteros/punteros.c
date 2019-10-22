#include "stdio.h"

void main()
{
	int vect[10];
	
	for (int i = 0; i<10; i++)
	{	
		vect[i] = i;
	}

	int *puntero1, *puntero2;

	puntero1 = &vect[0];
	puntero2 = &vect[9];

	printf("Puntero 1 contiene: %d", *puntero1);
}
