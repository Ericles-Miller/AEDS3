#include<stdio.h>
#include<stdlib.h>

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

void merge(int a[] ,int i, int m,int f)
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

int main()
{
    int vet[]={3,5,7,8,33,42,55,78};
    int i;
    mergisort(vet,0,7);

    for (i=0; i<8; i++)
    {
        printf("%d\n", vet[i]);
    }
    

return 0;
}
