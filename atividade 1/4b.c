#include<stdio.h>
#include<stdlib.h>

int soma(int x,int y)
{

    if(y==1)
    {
        return ++x;
    }

    while(y>1)
    {
        return soma(++x,y-1);
    }


}

int main()
{
    int y,x;

    printf("Digite um numero:");
    scanf("%i",&x);

    printf("Digite um numero:");
    scanf("%i",&y);

    printf("O resultado e:%i",soma(x,y));

    return 0;
}
