#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void geranum(int a[], int qtd, int lim)
{
    srand(time(NULL));
    int v, i;
    for (i = 2; i <qtd; i+2){
        v=rand()%lim;
        a[i]= v;
    }
}
void max_min(int a[])
{
    int i,max=a[0], min=a[0];
    for (i=1; i<10; i++)
    {
        if ((a[i])>max){
            max=a[i];
            printf("-- max:%i",max);
        }
        if((a[i])<min){
            min=a[i];
            printf("--%i",min);
        }
    }
}
int main()
{
    int a[10];
    int i,j;
    clock_t t;
    //geração aleatório dos valores do vetor
    geranum(a,10,11);
    for (i = 0; i<10; i++)
    {
        printf("%i",a[i]);
    }
    t=clock();
    max_min(a);
    t=clock()-t;
    // printf("Tempo de execucao: %lf", ((double)t)); //conversão para double
    return 0;
}
