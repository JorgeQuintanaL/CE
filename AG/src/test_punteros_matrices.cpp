#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <vector>

#define VARS 10

using namespace std;

class estudiante
{
    public:
        int edad, nota;

        estudiante(int _edad, int _nota)
        {
            edad = _edad;
            nota = _nota;
        }

        void imprimir_datos()
        {
            cout << "Edad: " << edad << " Nota: " << nota << endl;
        }
};

int main()
{
    int arreglo[VARS][VARS];
    estudiante andres(23, 5);
    estudiante jorge(29, 4);
    estudiante ivonne(30, 5);

    vector<estudiante*> puntero_estudiantes;
    puntero_estudiantes.push_back(&andres);
    puntero_estudiantes.push_back(&jorge);
    puntero_estudiantes.push_back(&ivonne);

    for ( vector<estudiante*>::iterator i = puntero_estudiantes.begin(); i != puntero_estudiantes.end(); ++i )
    {
        (*i)->imprimir_datos();
    } 
/*
    for (int i = 0; i < VARS; i++)
    {
        cout << ((puntero_enteros+i)) << endl;
    }

    for (int i = 0; i<VARS; i++)
    {
        for (int j = 0; j<VARS; j++)
        {
            *((puntero_arreglo+(i*VARS))+j) = 20;
        }
    }
    

    for (int i = 0; i<VARS; i++)
    {
        for (int j = 0; j<VARS; j++)
        {
            cout << i << " " << j << " " << *((puntero_arreglo+(i*VARS))+j) << " ";
        }
        cout << endl;
    }
*/
    return 0;
}