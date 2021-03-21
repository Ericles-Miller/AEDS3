#include<iostream>
using namespace std;

int fib(int n){
	if (n==1 || n==0) return 1;
	return(fib(n-1)+fib(n-2));
}

int main(){
	int i;
	for (i=0; i<20; i++){
		cout<<fib(i)<<", ";
	}
	return 0;
}
