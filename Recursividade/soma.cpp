#include<iostream>
using namespace std;

int sum(int A[], int n){
	if (n==1) return A[0];
	return A[n-1]+sum(A,n-1);
}

int main(){
	int B[]={1,2,3,4,5,6,7,8,9,10};
	int soma;
	soma=sum(B, sizeof(B)/sizeof(int));
	cout<<soma;
	return 0;
}

