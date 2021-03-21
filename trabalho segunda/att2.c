#include<stdio.h>

int main()
{
    int a=5,i,soma=0;
    
    while (a!=0)
    {
        soma+=a;
        a--;
    }
    printf("%d",soma);
    
return 0;
}