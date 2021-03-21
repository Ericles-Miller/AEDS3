#include<stdio.h>
#include<stdlib.h>

typedef struct _no no;
struct _no
{
    char c;
    no *esq,*dir;
};

typedef struct _tree tree;
struct _tree
{
    no *root;
};

/*typedef struct _no2 no2;
struct _no2
{
    char c;
    no2 *esq,*dir;
};

typedef struct _tree2 tree2;
struct _tree2
{
    no2 root;
}*/

///////////////////1° arvore /////////////////////////////
int inserir(no **r,no **r2,char c)
{
    no *aux;

    if(*r== NULL )
    {
        aux=(no*)malloc(sizeof(no));
        if(!aux)
            return 0;
        aux->c=c;
        aux->dir=aux->esq=NULL;
        *r=aux;//raiz
        return 1;
    }
    
    else if ((*r)->esq == NULL)
        return inserir(&(*r)->esq,c);

    else if ((*r)->dir == NULL)
        return inserir(&(*r)->dir,c);
    
    else if ((*r)->esq!=NULL && (*r)->dir!= NULL)
        aux->dir=aux->esq=NULL;
        return inserir(&(*r),c);   
}

int remove(no **r,char c)
{
    no *aux;
    no2 *aux2;

    if((*r)->esq!=NULL)
        return remove(&(*r)->esq,c);

    if((*r)->dir != NULL)
        return remove(&(*r)->dir,c);
    
    else if ((*r)->esq != NULL && (*r)->dir == NULL)
    {
        aux=*r;
        inserir(&(*r),(*r)->esq);
        *r=aux->esq;
        aux->esq=NULL;
        free(aux);
        return 1;
    }

    else if ((*r)->esq == NULL && (*r)->dir !=NULL)
    {
        aux=*r;
        inserir(&(*r),(*r)->dir);
        *r=aux->dir;
        aux->dir=NULL;
        free(aux);
        return 1;
    }     

    else if ((*r)->esq == NULL && (*r)->dir == NULL)
    {   
        inserir(&(*r),(*r)->c);
        free(*r);
        *r=NULL
        return 1;
    }         
 } 

int main()