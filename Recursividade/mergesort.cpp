#include<iostream>
using namespace std;


void merge(int A[], int i, int meio, int f){
	int conti=i, contf=meio+1, contaux=0;//lado esquerdo e direito
	int aux[f-i+1];//vet auxiliar
	while(conti<=meio && contf<=f){
		if (A[conti]<A[contf]) aux[contaux]=A[conti++];
		else aux[contaux]=A[contf++];
		contaux++;
	}
	while(conti<=meio) aux[contaux++]=A[conti++];
	while(contf<=f) aux[contaux++]=A[contf++];
	for(conti=i, contaux=0; conti<=f; conti++) A[conti]=aux[contaux++];
}


void mergesort(int A[], int i, int f){
	int meio=(i+f)/2;
	if (i<f){
		mergesort(A, i, meio);
		mergesort(A, meio+1, f);
		merge(A, i, meio, f);
	}
}

int main(){
	int V[]={49,88,13,56,85,29,44,16,91,27,98};
	int l;
	mergesort(V, 0, sizeof(V)/sizeof(int));
	for (l=1; l<sizeof(V)/sizeof(int)+1; l++){
		cout<<V[l]<<", ";
	}
	return 0;
}


