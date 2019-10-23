#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <vector>

#define VARS 10

using namespace std;

int main()
{
    int arreglo[VARS][VARS];
    for (int i = 0; i<VARS; i++)
    {
        for (int j = 0; j<VARS; j++)
        {
            arreglo[i][j] = i+j;
        }
    }

    for (int i = 0; i<VARS; i++)
    {
        for (int j = 0; j<VARS; j++)
        {
            cout << **((arreglo+i)+j) << endl;
        }
    }
    return 0;
}