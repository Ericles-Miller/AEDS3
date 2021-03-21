#include<iostream>
using namespace std;

void rg1(int size, int r){
	int i;
	for (i=0; i<size; i++){
		cout<<"-";
	}
	if (r>=0) cout<<r;
	cout<<endl;
}

void rg3(int size){
	if (size>0){
		rg3(size-1);
		rg1(size, -1);
		rg3(size-1);
	}
}


void rg(int length, int sizem){
	int j;
	rg1(sizem, 0);
	for(j=1; j<=length; j++){
		rg3(sizem-1);
		rg1(sizem, j);
	}
}

int main(){
	rg(5, 6);
	return 0;
}
