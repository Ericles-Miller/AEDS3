#include<stdio.h>
#include<stdlib.h>

int f2(int n)
{
if (n == 0)
return (1);
if (n == 1)
return (1);
else
return(f2(n-1)+ 2 * f2(n-2));
}

int main()
{
    int n=5;
    printf("%d",f2(n));
    return 0;
}
