#include<stdio.h>
int i,j;
void perm(char A[], int n, int out){
	if (out==n){
		for(i=0; i<sizeof(A), i++){
			printf("%d, ", A[i]);
		}
	}
	for(j=0; j<n, j++){
			perm(A, n, ++out);
		}
}

int main(){
	char hg[]="hugo";
	perm(hg, 0);
	return 0;
}
