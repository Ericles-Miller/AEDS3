#include<stdio.h>

int soma_linear(int a[],int n)
{
    if(n==1)
    return a[n];
    
    typedf struct nome n;
    struct{

    }
n->

    return soma_linear(a, n-1) + a[n-1];
}

void vet_invet(int a[],int i, int j)
{
    if(i<=j)
    {
        int aux=a[i];
        a[i]=a[j];
        a[j]=aux;
        vet_invet(a,i+j, j-1);
    }
}


int main()
{
    int vet[]={4,2,3,5,7,8,9,5,6,9};
    int soma=0;

    soma= somalinear(vet , 10);
    vet_invet(vet,0,9);-0
    

return 0;
}