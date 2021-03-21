//Multiplicação de dois inteiros através de somas sucessivas
#include<stdio.h>

int prod(int m, int n){
	if (n==1) return m;
	return m+prod(m, --n);
}

int main(){
	printf("%d", prod(9,11));
	return 0;
}
