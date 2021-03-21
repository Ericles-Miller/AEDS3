#include<stdio.h>
#include<stdlib.h>
#define beguin 0
#define end 7

/*void quick_short(int a[],int inicio, int fim)
{
    if( inicio<fim)
    {
        int p=particiona(a,inicio,fim);
        quick_short(a,inicio,p-1);
        quick_short(a,p+1,fim);
    }
}*/

int particiona(int a[],int inicio,int fim)
{
    int pivo=a[fim],aux;

    if(a[fim-1]<pivo)
    {
        aux=a[fim-1];
        a[fim-1]=a[inicio];
        a[inicio]=aux;
        return particiona(a,inicio+1,fim);
    }

    else if(a[inicio]==a[fim])
    {
        return 0;
    }
    else if(a[fim-1]>=pivo)
    {
        aux=a[fim-1];
        a[fim-1]=pivo;
        a[fim]=aux;
        return particiona(a,inicio,fim-1);
    }
}

int main()
{
    int vet[8]={1,2,9,6,3,5,8,4};

    for (int i=0; i<8; i++)
    {
        printf("%d -",vet[i]);
    }
    printf("\n");

    int p=particiona(vet,beguin,end);

    for (int j=0; j<8; j++)
    {
        printf("%d -",vet[j]);
    }
    return 0;
}
