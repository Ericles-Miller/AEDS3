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



int create(t tr){
	tr.root = (n*) malloc (sizeof(n));
	*(tr.root).left = NULL;
	*(tr.root).right = NULL;
	
}


int remove(n **r; int val){
	if (*r != NULL){
		if (val<(*r)->data) return remove(&(*r)->left, val);
		if (val>(*r)->data) return remove(&(*r)->right, val);
		if ((*r)->left == NULL && (*r)->left == NULL){
			free(*r);
			*r=NULL;
		}
		else if ((*r)->right==NULL && (*r)->left!=NULL){
			n *aux = *r;
			*r=aux->left;
			aux->left=NULL;
			free(aux);
		}
		else if((*r)->left==NUL && (*r)->right != NULL){
			n *aux = *r;
			*r = aux->right;
			aux->right = NULL;
			free(aux);
		}
		else if((*r)->right != NULL && (*r)->left != NULL){
			int pval = searchsmall((*r)->right);
			return remove (&(*r)->right, pval);
		}
		return 1;
	}
	return 0;
}





