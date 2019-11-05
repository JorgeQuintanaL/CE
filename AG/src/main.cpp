#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <vector>

#define TAMANO_POB 5
#define ITERATIONS 100

using namespace std;

class agente
{
    public:
        float ajuste, valor;

        agente(float _valor)
        {
            valor = _valor;
        }
        void calcular_ajuste()
        {
            ajuste = pow(valor, 2);
        }
        void imprimir_ajuste()
        {
            cout << "Valor: " << valor << ". Fitness: " << ajuste << "." << endl;
        }
};

int main()
{
    //Declaración de variables y arreglos
    vector<agente*> puntero_poblacion;
    vector<float*> puntero_fitness;

    //Inicialización de la población
    for ( int i = 0; i < TAMANO_POB; i++ )
    {
        float val = rand() % 100 + 1;
        agente* agente_ = new agente(val);
        puntero_poblacion.push_back(agente_);
    }

    //Ordenamiento de la población de acuerdo con el fitness
    int ind_i = 0;
    int ind_j = 1;
    float mayor, menor;
    agente *aux;

    for ( int i = ind_i; i < puntero_poblacion.size(); i++ )
    {
        vector<agente*>::iterator i_ = next(puntero_poblacion.begin(), i);
        (*i_)->calcular_ajuste();
        mayor = (*i_)->ajuste;
        for ( int j = ind_j; j < puntero_poblacion.size(); j++ )
        {
            vector<agente*>::iterator j_ = next(puntero_poblacion.begin(), j);
            (*j_)->calcular_ajuste();
            menor = (*j_)->ajuste;
            if (mayor <= menor)
            {
                aux = puntero_poblacion[j];
                puntero_poblacion[j] = puntero_poblacion[i];
                puntero_poblacion[i] = aux;
            }
        }
        ind_j++;
    }

    for (vector<agente*>::iterator i = puntero_poblacion.begin(); i < puntero_poblacion.end(); ++i )
    {
        cout << "Valor: " << (*i)->valor << " Fitness: " << (*i)->ajuste << endl;
    }

   return 0;
}