#include<stdio.h>
int main()
{
    int i ,a=5,soma=0;

    while (a!=0)
    {
        soma+=a;
        a--;
    }

    printf("%d",soma);

return 0;
}