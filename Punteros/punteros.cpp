#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int vect[10], *puntero1, *puntero2;

	for (int i=0; i<10; i++)
	{
		vect[i] = i;
		puntero1 = &vect[i];
		cout << "Puntero 1 contiene: " << *puntero1 << endl;
	}
}
