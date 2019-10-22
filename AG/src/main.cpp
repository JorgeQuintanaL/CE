#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <math.h>

using namespace std;

class sp
{
    public:
        int start_x, end_x;

        sp(int _start_x, int _end_x)
        {
            start_x = _start_x;
            end_x = _end_x;
        }
};

class agente
{
    public:
        float ajuste, valor[10];

        agente(float _valor)
        {
            valor[0] = _valor;
        }

        void calcular_ajuste(int i)
        {
            ajuste = pow(valor[i], 2);
            cout << valor[i] << ", " << ajuste << endl;
        }
        void variar(float end_x, float start_x)
        {
            float delta = 0;
            int i = 0;
            while ((valor[i] <= end_x) && (valor[i] >= start_x))
            {
                delta += rand();
                valor[i] += delta;
            }
        }
};

int main()
{
    int i = 0;
    sp test(-5, 5);
    agente jorge(4);
    jorge.calcular_ajuste(i);
    while (jorge.ajuste >= 1e-10)
    {
        jorge.variar(test.start_x, test.end_x);
        jorge.calcular_ajuste(i);
        i++;
    }
    //test_quadratic.print_solution_space();
    //test_quadratic.print_search_space();

    
    /*
    int arreglo[5] = {1, 2, 3, 4, 5};
    string binary[5];
    unsigned long decimal[5];
    
    for (int i = 0; i < 5; i++)
    {
        binary[i] = bitset<4>(i).to_string();
        decimal[i] = bitset<4>(binary[i]).to_ulong();
    }

    for (int i = 0; i < 5; i++)
    {
        cout << "Original: " << i << endl;
        cout << "Convertido: " << binary[i] << endl;
        cout << "Recuperado: " << decimal[i] << endl;
    }
    //random_shuffle(&arreglo[0], &arreglo[3]);

    
    for (int i = 0; i < 5; i++)
    {
        cout << "Arreglo modificado: " << arreglo[i] << endl;
    }
    */
}