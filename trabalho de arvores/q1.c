#include<stdio.h>
#include<stdlib.h>

typedef struct  _bloco bloco;
struct _bloco
{
    int dado;
    bloco *esq;
    bloco *dir;
};

typedef struct _arvore arvore;
struct _arvore
{
    bloco *raiz;//raiz
};

void inserir(bloco **t, int dado)
{   

  // se t aponta para null, a inserção é na raiz...   
  if (*t == NULL) {    
    *t = (bloco *) malloc(sizeof(bloco));   
    if (*t == NULL) return;   
    (*t)->esq= NULL;   
    (*t)->dir = NULL;   
    (*t)->dado = dado;   
  }   
  // Se o dado a ser inserido for menor que o nó atual, recursividade à esquerda   
  if (dado < (*t)->dado) 
  {   
     inserir(&((*t)->esq), dado);   
  }   
  else
  {   
    // Se o dado a ser inserido for menor que o nó atual, recursividade à direita   
    if (dado > (*t)->dado) {               
       inserir(&((*t)->dir), dado);   
    }   
  }   
}

bloco minimo(bloco T)// procura o nó com valor mínimo 
{
    if(arvore_vazia(T)){   
       return NULL;   
    }
    else{   
          if( arvore_vazia(T->esq) ) 
              return T;   
          else   
              return minimo(T->esq);   
             
        }   
}

bloco max(bloco t)//procuro no com valor max
{
    if(arvore_vazia(t))
        return NULL;
    
    else {
        if(arvore_vazia(t->dir))
            return t;
        else
            return max(t->dir);   
        }
}

bloco busca_elemento(bloco t, int dado)
{   
     bloco achou;   
     if (arvore_vazia(t)) 
        return NULL;   

     if (t->dado == dado) 
        return t;   
         achou = busca_elemento(t->esq, dado);

     if (arvore_vazia(achou))   
         achou = busca_elemento(t->dir, dado);   
     return achou;   
}

int remover(bloco **r, int valor)
{
    bloco *aux;

    if(*r !=NULL)
    {
            if(valor< (*r)->dado)
                return remover(&(*r)->esq,valor);
        
        else if(valor > (*r)->dado)
            return remover(&(*r)->dir,valor);

        else if((*r)->esq ==NULL && (*r)->dir == NULL)//quando nao tem ninguem p/ apontar
        {
            free(*r);
            *r=NULL;
            return 1;
        }

        else if((*r)->esq != NULL && (*r)->dir == NULL)
        {
            aux=*r;
            aux->esq=NULL;
            free(aux);
            return 1;
        }

        else if((*r)->esq == NULL && (*r)->dir != NULL)
        {
            aux= *r;
            aux->dir=NULL;
            free(aux);
            return 1;
        }

        else
        {
            aux=max((*r)->esq);
            (*r)->dado=aux->dado;//copiar dados de aux para *r
            return remover(&(*r)->esq, aux->dado);
        }
    } 
}  

void imprimir_caminho(bloco **r,int dado)
{
    bloco *aux;

    if(*r!= NULL)
    {
        if(dado < (*r)->dado)
        {
            printf("%d -",(*r)->dado);
            return imprimir_caminho(&(*r)->esq);
        }
        else if(dado > (*r)->dado)
        {
            printf("%d -",(*r)->dado);
            return imprimir_caminho(&(*r)->dir);
        }

        else if((*r)->esq ==NULL && (*r)->dir == NULL)
            printf("%d -",(*r)->dado);

        else if((*r)->esq == NULL && (*r)->dir != NULL)
            printf("%d -",(*r)->dado);
        
        else if ((*r)->esq != NULL && (*r)->dir == NULL)
            printf("%d -",(*r)->dado);    
    }  
}
    
