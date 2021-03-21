#include<stdio.h>
#include<stdio.h>
#define T 5

void mergisort(int a[],int i ,int f)//inicio e fim
{   
    
    int meio=(i+f)/2;//inicio e fim
    int pivo=a[i];
    int pivo2=a[f];
    if(i<f)
    {
        mergisort(a,i,meio);//vai p/ esquerda e divide em sub problema
        mergisort(a,meio+1,f);//vai p/direita e idem
        merge(a,i,meio,f);//chama a fun de baixo
    }

}

void merge(int a[] ,int i, int m,int f)//meio fim e inicio
{
    int counti=i, contf=m+1, countx=0;

    int aux[f-m+1];

    while (counti <=m && contf <=f)
    {
        if(a[counti]<a[contf])

        aux[countx]= a[counti++];

        else aux[countx]=a[contf++];

        countx++;
    }

    while (counti<=m)
    {
        aux[countx++]=a[counti];
    }
    while (contf<=f)
    {
        aux[countx++]=a[contf++];
    }

    for(counti =i, countx=0; contf<=f; counti++)
    {
        a[counti]=aux[countx++];
    }

}



int busca_bin(vet[],int t,int x)
{
    int i=0,f=t-1,m;

    while (i<=f)
    {
       m = (i+f)/2;//4
		if(v[m]== x)//meio do vet
		{
			return v[m];
		}
		else
		if(  < v[m] )//antes do meio do vet
		{
			i2 = m -1;//regressa uma posiç
		}
		else //depoisdo meio do vet
		{
			i1 = m + 1;//aumenta uma  posicao
		}
	}

		return NULL;//se nao existir x
    }
}

int main()
{
    int i,f,s[T]={1,2,3,4,5}, x=5;
    



return 0;
}