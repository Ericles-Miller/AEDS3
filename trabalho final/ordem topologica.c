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
} Digrafo;
//grafo direcionado
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

int insereAresta(Digrafo *g, int a, int b)
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

 void ordem_top(Digrafo *g, v,int e)
 {  
     int y= NULL;
     int heads=(int*)malloc(sizeof(int)*g->vertices);
     int d=(int*)malloc(sizeof(int)*g->vertices);

    for ( g->adj=0; g->adj!=NULL; g->adj=g->adj->prox)
    {
        
    }
    

 }

int main()
{
    x=ordem_top(v,e);
}