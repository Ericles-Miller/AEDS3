#include<iostream>
using namespace std;
int qt=0;
void hanoi(int n, char a, char b, char c){
	if (n>0){
		hanoi(n-1, a, c, b);
		qt++;
		printf("Mover de %c para %c\t\t%d\n", a, c, qt);
		hanoi(n-1, b, a, c);
	}
}

int main(){
	hanoi(20, 'a', 'b', 'c');
	return 0;
}
