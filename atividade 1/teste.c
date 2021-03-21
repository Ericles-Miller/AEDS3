#include<stdio.h>
#include<stdlib.h>


void desenhaUmamarca( int tam , int rotulo)
{
    for(int i=0 ; i<tam; i++)
    {
        printf("-");
    }
        if(rotulo >=0)
        printf("%i",rotulo);
        printf("\n");
}

void desenhaMarcas(int tam)
{
    if(tam>0)
    {
        desenhaMarcas(tam -1);
        desenhaUmamarca(tam,-1);
        desenhaMarcas(tam-1);
    }
}

void desenhaRegua(int comp, int tamMarca)
{
    desenhaUmamarca(tamMarca, 0);

    for(int i=1; i<=comp; i++)
    {
        desenhaMarcas(tamMarca-1);
        desenhaUmamarca(tamMarca ,i);
    }
}

int main()
{
    int n=4, t=3;
    desenhaRegua(n,t);

    return 0;
}
