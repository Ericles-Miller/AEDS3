#include<stdio.h>
#include<stdlib.h>

int multsoma(int a, int b)
{
    if(b==1)
    {
        return a;
    }

    while (b>1)
    {
        return a+ multsoma(a,b-1);
    }
    
}

int main()
{
    int n,n2;

    printf("\nDigite um numero:");
    scanf("%i",&n);

    printf("\nDigite um numero:");
    scanf("%i",&n2);

    printf("O resultado e:%i",multsoma(n,n2));


    return 0;
}