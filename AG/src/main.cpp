#include <iostream>
#include <bitset>
#include <algorithm>
#include <cmath>

#define INITIAL_GRID_SIZE 100
#define LENGTH 32
#define EXPLO 100

using namespace std;

class sp
{
    private:
        float start, end;
        int grid_size;
        double solution_space[INITIAL_GRID_SIZE];
        string search_space[INITIAL_GRID_SIZE];

    public:
        sp(float _start, float _end, int _grid_size)
        {
            start = _start;
            end = _end;
            grid_size = _grid_size;
            solution_space[grid_size];
            search_space[grid_size];
        }

        void generate_solution_space()
        {
            for (int i = 0; i < grid_size; i++)
            {
                solution_space[i] = start + ((end - start) / grid_size) * i * EXPLO;
            }
        }

        void generate_search_space()
        {
            for (int i = 0; i < grid_size; i++)
            {
                search_space[i] = bitset<LENGTH>(solution_space[i]).to_string();
            }
        }

        void print_solution_space()
        {
            for (int i = 0; i < grid_size; i ++)
            {
                cout << solution_space[i] << endl;
            }
        }

        void print_search_space()
        {
            for (int i = 0; i < grid_size; i ++)
            {
                cout << search_space[i] << endl;
            }
        }
};

class agent
{
    private:
        float fitness, value;

    public:
        agent(float _value)
        {
            value = _value;
        }

        void compute_fitness(float (*y)(float))
        {
            fitness = y(value);
        }
};

float x2(float x)
{
    return pow(x, 2);
}

int main()
{
    sp test_quadratic(1, 100, 10);
    test_quadratic.generate_solution_space();
    test_quadratic.generate_search_space();
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