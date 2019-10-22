//gcc pi_omp.c -o pi_omp -fopenmp
#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
 
#define ITERATIONS 1e06
#define THREADS 16
 
int calculatePi(double *piTotal, int ID)
{   int start, end;   
    
    /*
        La variable start se inicializa en el número de iteraciones dividido entre el número de threads
        multiplicado por el thread ID. Asimismo, la variable end se inicializa 
    */
    start = (ITERATIONS/omp_get_num_threads()) * ID;
    end = (ITERATIONS/omp_get_num_threads()) * (ID + 1);
    int i = start;
 
    do{
        *(piTotal + ID) = *(piTotal + ID) + (double)(4.0 / ((i*2)+1));
        i++;
        *(piTotal + ID) = *(piTotal + ID) - (double)(4.0 / ((i*2)+1));
        i++;
    }while(i < end);
 
    return 0;
}
 
 
int main()
{
    int i, threads = THREADS; //Ambas variables toman el valor de 16
    double pi[threads]; //Arreglo de tipo doble de 16 posiciones
    
    //Se itera desde i = 0 hasta el número de threads, tamaño del arreglo pi, para inicializar todas
    //las posiciones en 0
    for(i = 0; i < THREADS; i++)
        pi[i] = 0;
    
    //Se define el pragma con 16 como en número de threads
    #pragma omp parallel num_threads(threads)
    {
        //ID toma el valor del ID del thread
        int ID = omp_get_thread_num();
        //Se ejecuta calculatePI con argumentos pi, arreglo de 16 posiciones, y ID, el ID del thread
        calculatePi(pi, ID);
    }
     
    for(i = 1; i < THREADS; i++)
    {
        //Finalmente, se acumula el valor de pi en la posición 0 sumando los demás componentes
        pi[0] = pi[0] + pi[i];
    }
       
    printf("\npi: %2.10f \n", pi[0]);
}