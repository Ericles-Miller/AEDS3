#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define tam 100000000

/*int randon_integer(int low, int high)
{
    int k;
    srand((unsigned)time(NULL));
    k=(rand()% high)+low;
    return k;
}
*/
void max_min(int a[])
{
    int i ,max=a[0], min=a[0];

    for (i=1; i<tam; i++)
    {
        if(a[i]>max)
        {
            max=a[i];
          //  printf("\nMax:%i",max);
        }
        else
        {
            min=a[i];
           // printf("\n\nMin:%i");
        }

    }
}

int main()
{
    int *vet= (int*)malloc(sizeof(int)*tam);
    int i,j;
    clock_t t;
    srand(time(NULL));
    //geração aleatório dos valores do vetor
    for(i=0; i<tam; i++)
    {
        vet[i]=rand()%1000000;
    }
    t=clock();
    max_min(vet);
    t= clock()-t;
    printf("\nTempo de execucao: %lf",((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double
    return 0;
}
