#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <vector>

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
            cout << valor << ", " << ajuste << endl;
        }
};

void inicializar_poblacion(agente **poblacion)
{
    for (int i = 0; i<5; i++)
    {
       *(poblacion+i) = new agente((rand() % 10 + 1));
    }
}

void ordenar_poblacion(float *fitness)
{
    float ajuste_0, index_0, ajuste_1, index_1;
    for (int i = 0; i<4; i++)
    {
        ajuste_1 = *((fitness+(i+1))+1);
        index_1 = *(fitness+(i+1));
        ajuste_0 = *((fitness+i)+1);
        index_0 = *(fitness+i);
        if (ajuste_1 < ajuste_0)
        {
            *((fitness+i)+1) = ajuste_1;
            fitness[i][0] = index_1;
            fitness[i+1][1] = ajuste_0;
            fitness[i+1][0] = index_0;
        }
    }
}

int main()
{
    int i = 0;
    int iteraciones = 100;
    agente *poblacion[5];
    float fitness[5][2];
    inicializar_poblacion(poblacion);
    for (int i = 0; i<5; i++)
    {
        poblacion[i]->calcular_ajuste();
        fitness[i][0] = i;
        fitness[i][1] = poblacion[i]->ajuste;
        //cout << fitness[i][0] << " " << fitness[i][1] << endl;
    }
    
    ordenar_poblacion(fitness);
    for (int i = 0; i<5; i++)
    {
        cout << fitness[i][0] << " " << fitness[i][1] << endl;
    }
}