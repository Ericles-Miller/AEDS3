//lista simplesmente encadeada

//Dada uma lista ordenada
//Construa um método de pesquisa binária
#include<stdio.h>

struct node{
	int val;
	struct node *next;
};

typedef struct node n;

typedef struct{
	n *start, *end;
	int size;
}list;


void create(list *S){
	S->size=0;
	S->start=S->end=NULL;
}

int insert(list *S, int value){
	n *aux=(n*) malloc(sizeof(n));
	if (!aux) return 0;
	aux->val=valor;
	aux->next=NULL;
	if(S->start=NULL){
		S->start=S->end=aux;
		S->size++;
	}
	else{
		S->end->next=aux;
		S->end=aux;
	}
}

int remove(list *S){
	n *aux=S->start;
	if (S->start==NULL) return 0;
	if (S->start==S->end){
		S->start=S->end=NULL;
		free(aux);
		S->size--;
		return 1;
	}
	S->start=aux->next;
	aux->next=NULL;
	free(aux);
	S->size--;
	return 1;
}


int main(){
	list l;
	l.size=0;
	l.start=l.end=NULL;
	create(&l);
	insert(&l, 2);
	insert(&l, 3);
	insert(&l, 4);
	remove(&l);
}
