#include <stdio.h>
#include <math.h>
#include <pthread.h>
 
void *func1()
{
    int i;
    double x;
    for(i = 0; i < 1e12; i++){
        x = x + sin(i);
    }
}
 
 
void *func2()
{
    int i;
    double x;
    for(i = 0; i < 2e12; i++){
        x = x + cos(i);
    }
}
 
 
void func3()
{
    int i;
    double x;
    for(i = 0; i < 2e12; i++){
        x = x + cos(i);
    }
}
 
void func4()
{
    int i;
    double x;
    for(i = 0; i < 2e12; i++){
        x = x + cos(i);
    }
}
int main()
{   pthread_t hilo[10], hilo2;
    void *arg1, *arg2;
    int h1, h2, i;
 
    for(i = 0; i < 10; i++)  
        h1 = pthread_create(&hilo[i], NULL, func1, arg1);
    h2 = pthread_create(&hilo2, NULL, func2, arg2);
 
    func3();
    func4();
 
    for(i = 0; i < 10; i++)      
        pthread_join(hilo[i], NULL);
    pthread_join(hilo2, NULL);
 
     
}