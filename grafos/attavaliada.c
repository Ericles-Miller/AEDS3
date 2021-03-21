#include<stdio.h>
#include<stdlib.h>

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

int busca(int A[], int i, int f, int x)//verificar
{
	int meio=(i+f)/2;
	if (A[meio]==x) return meio;
	if (i==f) return -1;
	if (A[meio]<x) return busca(A, meio+1, f, x);
	else return busca(A, i, meio-1,x);
}

void imprime(t *a){
    if(a!=NULL){
        printf("%c",a->dado);
        imprime(a->esq);
        imprime(a->dir);
    }
}


int remove(n **r; int val)//valor
{
	if (*r != NULL){
		if (val<(*r)->data) 
            return remove(&(*r)->left, val);//vai para left
		
        if (val>(*r)->data) //vai p/ rigth
            return remove(&(*r)->right, val);

		if2 ((*r)->left == NULL && (*r)->left == NULL)//arvore vazia
        {
			free(*r);
			*r=NULL;
		}

		else if ((*r)->right==NULL && (*r)->left!=NULL)
        {
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
}*/


int main(){
	t tree1;
	create(tree1);
}

