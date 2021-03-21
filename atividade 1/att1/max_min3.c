#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n 100000000


void max_min(int a[])
{
    int i ,max, min,fimdoanel;

    if((n&1)>0)
    {
        a[n]=a[n-1];
        fimdoanel =n;
    }

    else fimdoanel= n-1;

    if(a[0]>a[1])
    {
        max=a[0];
        min=a[1];
    }

    else {
        max =a[1];
        min=a[0];
    }
    i=3;

    while (i<=fimdoanel)
    {
        if (a[i-1]>a[i])
        {
            if(a[i-1]>max)
            {
                max=a[i-1];
            }
        }
        if(a[i]<min)
        {
            min =a[i];
        }
        else
        {
            if(a[i-1]<min)
            {
                min=a[i-1];
            }
            if(a[i]>max)
            {
                max=a[i];
            }

        }
        i+=2;
    }
    printf("\nMax:%i",max);
    printf("\nMin:%i",min);
}

int main()
{
    int *vet= (int*)malloc(sizeof(int)*n);
    int i,j;
    clock_t t;
    srand(time(NULL));
    //geração aleatório dos valores do vetor
    for(i=0; i<n; i++)
    {
        vet[i]=rand()%1000000;
    }
    t=clock();
    max_min(vet);
    t= clock()-t;
    printf("\nTempo de execucao: %lf",((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double
    return 0;
}


