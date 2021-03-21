#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//variáveis globais
int vet[7];//vetor contendo a ordenação topológica do grafo
int ctdVet=0; //contadora do vetor

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

void criaGT(Digrafo *g, Digrafo *gt)
{
    No *perc;
    int v;
    for(v=0; v<g->vertices; v++)
    {
        for(perc = g->adj[v];perc != NULL; perc=perc->prox)
        {
            insereAresta(gt,perc->rotulo,v);
        }
    }

}

void buscaProfundidade(Digrafo g)
{
    int i;

    for(i=0; i<g.vertices; i++)
    {
        g.visitado[i] = 0;
    }
    for(i=0; i<g.vertices; i++)
    {
        if(g.visitado[i] == 0)
            busca(g,i);
    }
}
void busca(Digrafo g, int a)
{
    No *aux = g.adj[a];
    g.visitado[a] = 1;
    //printf("%d",aux->rotulo);
     vet[ctdVet++] = a;
    while(aux != NULL)
    {
        if(g.visitado[aux->rotulo]==0)
            busca(g,aux->rotulo);
        aux = aux->prox;
    }
}

void buscaGt(Digrafo gt){
    int i;
    for(i=0;i<gt.vertices;i++){
        gt.visitado[i] = 0;
    }
    for(i=0;i<gt.vertices;i++){
        busca(gt,vet[i]);
    }
}

int main()
{
    Digrafo g;
    Digrafo gt;
    if(!inicializaGrafo(&g, 7))
        printf("Erro1");
    if(!inicializaGrafo(&gt, 7))
        printf("Erro1.1");
    if(!insereAresta(&g,0,1))
        printf("Erro2");
    if(!insereAresta(&g,0,3))
        printf("Erro3");
    if(!insereAresta(&g,1,2))
        printf("Erro4");
    if(!insereAresta(&g,1,4))
        printf("Erro5");
    if(!insereAresta(&g,3,4))
        printf("Erro6");
    if(!insereAresta(&g,3,5))
        printf("Erro7");
    if(!insereAresta(&g,4,5))
        printf("Erro8");
    if(!insereAresta(&g,4,6))
        printf("Erro9");

    criaGT(&g,&gt);
    printf("Grafo g\n");
    imprime(g);
    printf("\nGrafo g invertido \n");
    imprime(gt);
    printf("\n");
    buscaProfundidade(g);
    for(int i=0;i<7;i++)
        printf("%d\n",vet[i]);

    buscaGt(gt);
    system("pause");
    return 0;
}

/**Para Segunda
=> Pesquisar e implementar a busca em largura para resolver o seguinte proble:
"Dados dois vertices A e B, existe um caminho entre eles no grafo"
OBS: não pode destruir as arestas.*/

s