#include<iostream>
using namespace std;

int busca(int A[], int i, int f, int x){
	int meio=(i+f)/2;
	if (A[meio]==x) return meio;
	if (i==f) return -1;
	if (A[meio]<x) return busca(A, meio+1, f, x);
	else return busca(A, i, meio-1,x);
}

int main(){
	int V[]={1,2,3,4,5,6,8,9};
	cout<<busca(V, 0, (sizeof(V)/sizeof(int))-1, 7);
	return 0;
}


