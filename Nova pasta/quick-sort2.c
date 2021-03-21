#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a[8]={15,2,4,6,3,5,8,6},end=7,beguin=0;
    int pivo=a[end],aux,i;

   /* for (i=0; i<8; i++)
    {
       printf("%d-",a[i]);
    }*/

    for (i=0; i<8; i++) // n
    {
        if (a[end-1]<pivo) //n-1
        {
            aux=a[end-1]; //n-1
            a[end-1]=a[beguin];//n-1
            a[beguin]=aux; // n-1
            beguin++;//n-1
        }

        else if(a[end-1]>pivo)
        {
            aux=a[end-1];
            a[end-1]=pivo;
            a[end]=aux;
            end--;
        }
    }
    /*printf("\n\n");
    for(i=0; i<8; i++)
    {
        printf("%d-",a[i]);
    }

    //particiona(vet,beguin,end);*/
    return 0;
}
