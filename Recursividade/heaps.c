/*heap: dado um no pai de indice(i) os filhos da esquerda 
e direita são respectivamente(i*2+1) e (i*2+2).

propriedade de heap de maximo:Os valore dos nos pais são sempre maiores do que os valores dos nos filhos

vet{9,8,7,5,6,4,4,0,3,2,1};*/

////////////////////////////////////////////////
#include<stdio.h>
#id heapificar(int v[])
{   
    int i;
    for (i=tamanho/2; i>=0; i--)
    {   
        printf("\n-%d-\n",i);
        constroi_heap_max(v,i);
    }
    
}

 int constroi_heap_max(int v[], int i)
{
    int e = i*2+1;//recebe penultima pos
    int maior, aux;
    int d = i*2+2;//recebi ultima pos

    maior=i;

    if( e <tamanho && v[e]>v[maior] )
        maior= e;

    if( d<tamanho && v[d]> v[maior])
        maior= d;

    if (maior != i )
    {
        aux= v[i];
        v[i]=v[maior];
        v[maior]= aux;
        constroi_heap_max(v,maior);
    }
}

int main()
{
    int vet[]={3,2,5,8,1,0,9,7};

    for ( int i = 0; i <8; i++)
    {
        printf("%d-",vet[i]);
    }
    
    heapificar(vet);
    printf("\n------------------\n");
    
    for ( int i = 0; i <tamanho; i++)
    {
        printf("%d-",vet[i]);
    }
    return 0;
}
