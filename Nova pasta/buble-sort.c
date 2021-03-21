#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int v[], int n)
{ 
    int aux;
    if (n < 1)
      return; 
 
    for (int i=0; i<n; i++) 
        if (v[i] > v[i+1]) 
        {
           aux=v[i];
           v[i]= v[i+1];
           v[i+1]=aux;
        }
    bubbleSort(v, n-1); 
}

int main()
{
    int vet[8]={1,3,5,4,9,2,5,6},i,tam=8;

    for(i=0; i<tam; i++)
    {
        printf("%d-",vet[i]);
    }
    for(i=0;i<=tam;i++)
    {   
        bubbleSort(vet,tam-1);
        vet[i+1];
    }
    printf("\n");
    for(i=0; i<tam; i++)
        printf("%d- ",vet[i]);

    return 0;
}