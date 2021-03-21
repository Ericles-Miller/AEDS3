#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void mergisort(int a[],int i ,int f)
{
    int meio=(i+f)/2;

    if(i<f)
    {
        mergisort(a,i,meio);
        mergisort(a,meio+1,f);
        merge(a,i,meio,f);
    }

}

void merge(int a ,int i, int m,int f)
{
    int counti=i, contf=m+1, countx=0;

    int aux[f-i+1];

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

int main()
{
    int vet[]={3,5,7,8,33,42,55,78};
    clock_t t;
    srand(time(NULL));
    
    t=clock();
    mergisort(vet,0,7);
    t= clock()-t;
    printf("\nTempo de execucao: %lf",
    ((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double
    

return 0;
}