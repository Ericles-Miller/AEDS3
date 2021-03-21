#include<iostream>
using namespace std;

void inv(int A[], int start, int end){
	if (start<=end) {
		int aux=A[start];
		A[start]=A[end];
		A[end]=aux;
		inv(A, start+1, end-1);
	} 
}

int main(){
	int B[]={1,2,3,4,5,6,7,8,9,10};
	int i;
	inv(B, 0, 9);
	for (i=0; i<sizeof(B)/sizeof(int); i++){
		cout<<B[i]<<", ";
	}
	return 0;
}
