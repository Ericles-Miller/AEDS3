//Soma de dois inteiros positivos através de incrementos
#include<stdio.h>

int sum(int m, int n){
	if(n==0) return m;
	return 1+sum(m, --n);
}

int main(){
	printf("%d", sum(9,90));
	return 0;
}
