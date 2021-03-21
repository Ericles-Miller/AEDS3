#include<stdio.h>

int fib(int n){
	if (n==1 || n==0) return 1;
	return fib(n-1)+fib(n-2);
}

int main(){
	int i, k;
	for (i=0; i<20; i++){
		k=fib(i);
		printf("%d, ", k);
	}
	return 0;
}
