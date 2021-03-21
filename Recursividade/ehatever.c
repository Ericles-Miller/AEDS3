#include<stdio.h>

struct node{
	int data;
	struct node *left, *right;
};

struct tree{
	struct node *root;
};

typedef struct node n;
typedef struct tree t;



void create(n *node1){
	node1 = (n*) malloc(sizeof(n));
	(*node1).
}
