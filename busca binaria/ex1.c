#include<stdio.h>
#include<stdlib.h>

int busc_bin(int vet[],int i, int f ,int x)
{
    int meio =(i+f)/2;

    if(vet[meio]==x)
    return meio;

    if(i==f)
    return -1;

    if(vet[meio]<x)
    {
        return busc_bin(vet,meio+1,f,x);
    }
    else
    {
         return busc_bin(a,i,meio-1,x);
    }
    
}

int main()
{
    int vet[]={3,5,7,8,33,42,55,78};
    int x;
    x =busc_bin(vet,0,7,79);

    printf("n%i",x);

return 0;
}