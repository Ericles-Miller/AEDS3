#include<stdio.h>
#include<stdlib.h>

typedef struct  _bloco bloco;
struct _bloco
{
    int dado;
    bloco *left;
    bloco *hight;
};

typedef struct _arvore arvore;
struct _arvore
{
    bloco *root;//raiz
};

int inserir (bloco **r, int dads)//ponteiro que aponta para ponteiro
{
    if(*r==NULL)//se conteudo de r for null
    {
        bloco *aux=(bloco*)malloc(sizeof(bloco));

        if(aux==NULL) return 0;

        aux->dado =dads;//recebe valor do parametro
        aux->left=aux->hight=NULL;//esq e dir recebem nulo
        *r=aux;
        return 1;
    }
    if(dads<(*r)->dado)
        return inserir(&(*r)->left,dads);//grava na direita

    else if (dads>(*r)->dado)
    {
        return inserir(&(*r)->hight,dads);//grava na esquerda
    }

}

int remove(bloco **r, int dads)
{
    if(*r!=NULL)
    {
        if(dads < (*r)->dado)//de dado for menor q raiz
            return remove(&(*r)->left,dads);
        
        else if(dads > (*r)->dado)//se dado for maior q raiz
            return remove((*r)->hight);
        
        if((*r)->left ==NULL && (*r)->hight ==NULL) 
        {
            free(*r);//remove raiz
            *r=NULL;
        }

        else if((*r)->hight == NULL && (*r)->left != NULL)
        {
            bloco *aux =*r;//aux e raiz
            *r=aux->left;//recebe ende da esq
            aux->left = NULL;//removeda esquerda
            free(aux);
        }

        else if((*r)->hight != NULL && (*r)->left == NULL)
        {
            bloco *aux=*r;
            *r=aux->hight;
            aux->hight=NULL;//remove da direita
            free(aux);
        }

        else if((*r)->hight != NULL && (*r)->left != NULL)
        {
            int pdado= search_menor((*r)->hight);//pesq para ser raiz
            return remove(&(*r)->hight,pdado);
        }
        return 1;
    }
    return 0;
}

/*int comp(int *a, int *b)
{
    if(a < b)
    {
        return 1;
    }
    else if( a> b)
    {
        return -1;
    }
    else
        return 0;
}*/

bloco * search_menor(bloco *r)
{
    while(r->hight!=NULL)
        r=r->hight;
    return r;    
}


int main()
{
    arvore a;

    a.root=NULL;

    inserir (&a.root,7);
    inserir (&a.root,4);
    inserir (&a.root,2);
    inserir (&a.root,5);
    inserir (&a.root,8);
    inserir (&a.root,9);
//**********************************************//

    remove(&a.root,2);
    remove(&a.root,4);   
    remove(&a.root,7);
    remove(&a.root,5);
    remove(&a.root,8);
    remove(&a.root,9); 

return 0;
}



