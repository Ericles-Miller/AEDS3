#include <stdio.h>
#include <stdlib.h>

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

int bfs(Digrafo *g,int n)
{
    No *aux;
    int f_inic=0;
    int f_end=0;

    int *fila=(int*)malloc(sizeof(int)*g->vertices);
    if (fila==NULL)
        return 0;
    fila[f_inic]=0;
    g->visitado[n]=1;

    while (f_inic <= f_end )
    {
        for (aux=g->adj[fila[f_inic]]; aux!=NULL; aux=aux->prox)//aux recebe o adj
        //do elem do  inicio da fila ate q ele seja nulo
        {    printf("\n%d",aux->rotulo);
            if(g->visitado[aux->rotulo]!=1)
            {
                printf("%d",aux->rotulo);
                fila[++f_end]=aux->rotulo;//
                g->visitado[aux->rotulo]=1;
            }
        }

        f_inic+1;
    }

    return 1;



}

void dfs_visit(Digrafo *g, int n)
{
    No *aux;

    printf("%d,",n);

    for (aux=g->adj[n]; aux!=NULL; aux=aux->prox)
    {
        if (g->visitado[aux->rotulo]==0)
        {
            g->visitado[aux->rotulo]=1;
           // printf("teste %d",gt->visitado);
            dfs_visit(g,aux->rotulo);
        }
    }
}

void dfs(Digrafo *g)//busca em profundidade
{
    for (int j=0; j<g->vertices; j++)
    {
        if (g->visitado[j]==0)
        {
            g->visitado[j]++;
            dfs_visit(g,j);
             if(i==7) j=0;
        }
    }
}


int main()
{
    Digrafo g;
    int a = inicializaGrafo(&g, 6);
    printf("%d\n", a);
    int b=inserearesta(&g,0,1);
    int c=inserearesta(&g,0,3);
    int d=inserearesta(&g,1,2);
    int i=inserearesta(&g,1,4);
    int e=inserearesta(&g,3,4);
    int f=inserearesta(&g,3,5);
    int h=inserearesta(&g,4,5);
    printf("%d %d %d %d %d %d %d\n\n", b, c, d, e, f, h, i);
    imprime(g);


    printf("\n----------------------------\n");
    dfs(&g);
    //bfs(&g,0);
   // printf("%d",k);
    return 0;
}

/**Para Segunda
=> Pesquisar e implementar a busca em largura para resolver o seguinte proble:
"Dados dois vertices A e B, existe um caminho entre eles no grafo"
OBS: não pode destruir as arestas.*/
