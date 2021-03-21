#include <stdio.h>
#include <stdlib.h>

int vet[7];
int i=0;
typedef struct _no
{
    int rotulo;
    struct _no *prox;
} No;
typedef struct
{
    int arestas, vertices;
    int *visitado;
    int *grauEntrada;
    int *grauSaida;
    No **adj;
} Digrafo; //grafo direcionado
//visitado : 0- não visitado, 1- visitado
//grauEntrada : quantas arestas entram em cada vertice
//grauSaida : quantas arestas saem de cada vertice
int inicializaGrafo(Digrafo *g, int vertice)
{
    int i;
    g->vertices = vertice;
    g->visitado = (int*)malloc(vertice*sizeof(int));
    g->grauEntrada = (int*)malloc(vertice*sizeof(int));
    g->grauSaida = (int*)malloc(vertice*sizeof(int));
    if(g->visitado == NULL || g->grauEntrada == NULL || g->grauSaida == NULL)
        return 0;
    g->adj = (No**)malloc(vertice*sizeof(No*));
    if (g->adj == NULL)
        return 0;
    for(i=0; i<vertice; i++)
    {
        g->adj[i]=NULL;
        g->grauEntrada[i]=g->grauSaida[i]=0;
        g->visitado[i]=0;
    }
    g->arestas=0;
    return 1;
}
int inserearesta(Digrafo *g, int a, int b)
{
    if(a<g->vertices && b<g->vertices)
    {
        No *aux = (No*)malloc(sizeof(No));
        if (!aux)
            return 0;
        aux->rotulo = b;
        aux->prox = g->adj[a];
        g->adj[a] = aux;
        g->grauEntrada[b]++;
        g->grauSaida[a]++;
        g->arestas++;
        return 1;
    }
    return 0;
}
void imprime(Digrafo g)
{
    int i;
    No *aux;
    for(i=0; i<g.vertices; i++)
    {
        printf("%d->", i);
        for(aux=g.adj[i]; aux!=NULL; aux=aux->prox)
            printf("%d->", aux->rotulo);
        printf("\n");
    }
}
void grafo_transitorio(Digrafo *g,Digrafo *gt)
{
    No* perc;
    int v;
    for(v=0; v<g->vertices; v++)
    {
        for (perc=g->adj[v]; perc!=NULL; perc=perc->prox)
        {
            inserearesta(gt,perc->rotulo,v);
        }
    }
}

void dfs_visit(Digrafo *gt, int n)
{
    No *aux;

    printf("%d,",n);
    vet[i]=n;
    i++;
    for (aux=gt->adj[n]; aux!=NULL; aux=aux->prox)
    {
        if (gt->visitado[aux->rotulo]==0)
        {
            gt->visitado[aux->rotulo]=1;
           // printf("teste %d",gt->visitado);
            dfs_visit(gt,aux->rotulo);
        }
    }
}

void dfs(Digrafo *gt)//busca em profundidade
{
   // printf("-- %d --",n);
    for (int j=0; j<gt->vertices; j++)
    {

        if (gt->visitado[j]==0)
        {
            gt->visitado[j]++;
            dfs_visit(gt,j);
             if(i==7) j=0;
        }
    }
}

int main()
{
    Digrafo g,gt;
    int a = inicializaGrafo(&g,8);
    int at = inicializaGrafo(&gt,8);
    //printf("%d\n", a);
    int b=inserearesta(&g,0,1);
    int c=inserearesta(&g,1,2);
    int d=inserearesta(&g,1,4);
    int i=inserearesta(&g,1,5);
    int e=inserearesta(&g,2,3);
    int f=inserearesta(&g,2,6);
   int g1=inserearesta(&g,3,7);
    int h=inserearesta(&g,3,2);
    int j=inserearesta(&g,4,5);
    int l=inserearesta(&g,4,0);
    int m=inserearesta(&g,5,6);
    int n=inserearesta(&g,6,7);
    int o=inserearesta(&g,6,5);
    int p=inserearesta(&g,7,7);
//terminar de preencher o grafo
    //printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d \n", b, c, d, i, e, f,g1, h, j,l,m,n,o,p);
    grafo_transitorio(&g,&gt);
    imprime(g);
    printf("\n-------------------------\n");
    imprime(gt);
    printf("\n-------------------------\n");
    dfs(&g);
    printf("\n-------------------------\n");
    dfs(&gt);
    for (int i = 0; i<8; i++)
    {
        printf("\n%d,",vet[i]);
    }

return 0;
}
