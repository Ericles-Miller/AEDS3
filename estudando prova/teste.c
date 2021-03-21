#include<stdio.h>
#include<stdlib.h>

int main()
{
int i=3, j=5;
 int *p, *q;
 p = &i;//recebe o endere�o de i
 q = &j;//recebe o endere�o de j

 printf("%i",p);//end de i que esta apontado para p
 printf("\n%i",*p);//conteudo de i que esta apontado em p
 printf("\n%i",q);//end de j que esta apontado par q
 printf("\n%i",*q);//conteudo de j que esta apontado em p
 printf("\n%i",&i);//endereço de i
 printf("\n%i",&j);//end de j
 printf("\n%i",&p);//end de p
 printf("\n%i",&q);//den de q
 printf ("\n%d %d %d\n", *p - *q , **&p, 3* - *p/(*q)+7);//-2 , cont do cont de p=3,-6
return 0;
}
