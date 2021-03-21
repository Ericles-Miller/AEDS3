#include<stdio.h>
#include<stdlib.h>

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

int ctd, ctn;
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

void Tarjan(Digrafo *g, int *sc)
{
    int i;
    ctd = t = k = ctn = 0;
    for(i=0; i<g->vertices; i++)
    {
        g->visitado[i] = 0;
        vet[i] = 0;
    }
    for(int j=0; j<g->vertices; j++)
    {
        if(g->visitado[j]==0)
            buscaTarjan(g, j, sc);
    }
}

int minimo(int a, int b)
{
    if (a<b)
        return a;
    else if (a>b)
        return b;
}

void buscaTarjan(Digrafo *g, int u, int *sc)
{
    g->visitado[u] = 1;
    pre[u] = ctd;
    lo[u]=ctd;
    ctd++;
    ctn++;
    vet[ctd] = u;
    novet[u] = 1;
    for(No *w = g->adj[u]; w!=NULL; w=w->prox)
    {
        if(g->visitado[w->rotulo] == 0)
        {
            buscaTarjan(g, w->rotulo, sc);
            lo[u] = minimo(lo[u],lo[w->rotulo]);

        }
        else if (novet[w->rotulo]==1)
        {
            lo[u] = minimo(lo[u],pre[w->rotulo]);
        }
    }
    if(lo[u] == pre[u])
    {
        int v;
        do
        {
            v = vet[ctn];
            vet[ctn] = 0;
            novet[v] = 0;
            sc[ctn] = v;
            ctn--;
        }
        while (v!=u);
    }
}
int main()
{
    Digrafo g,gt;
    int a = inicializaGrafo(&g,8);
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

    imprime(g);

return 0;
}