#include<iostream>
#include<cstdlib>
#define bb 100000
using namespace std;
int st;

typedef struct node{
	int rotulo;
	struct node *prox;
}no;

typedef struct {// digraph: directed graph
	int arestas, vertices;
	int *visitado;
	int *indeg, *outdeg;
	no **adj;
	int *x, *y;
}gr;

int inicializa(gr *g, int v){
	g->vertices=v;
	g->visitado=(int*) malloc(v*sizeof(int));
	g->indeg=(int*) malloc(v*sizeof(int));
	g->outdeg=(int*) malloc(v*sizeof(int));
	g->x=(int*) malloc(v*sizeof(int));
	g->y=(int*) malloc(v*sizeof(int));
	if(g->visitado==NULL || g->indeg==NULL || g->outdeg==NULL) return 0;
	g->adj=(no**)malloc(v*sizeof(no*));
	if(g->adj==NULL) return 0;
	int i;
	for(i=0; i<v; i++){
		g->adj[i]=NULL;
		g->indeg[i]=g->outdeg[i]=g->visitado[i]=0;
		g->x[i]=g->y[i]=0;
	}
	g->arestas=0;
	return 1;
}

int novaaresta(gr *g, int a, int b){
	if (a<g->vertices && b<g->vertices){
		no* aux=(no*) malloc (sizeof(no));
		if (!aux) return 0;
		aux->rotulo=b;
		aux->prox=g->adj[a];
		g->adj[a]=aux;
		g->indeg[b]++;
		g->outdeg[a]++;
		g->arestas++;
		return 1;
	}
	return 0;
}

void top_visit(gr *g, int i, int *v){
	no *j;
	for(j=g->adj[i]; j!=NULL; j=j->prox){
		if (g->visitado[j->rotulo] == 0){
			g->visitado[j->rotulo]=1;
			top_visit(g, j->rotulo, v);
		}
	}
	v[st]=i;
	st--;
	
}

void top(gr *g, int *v){
	st=g->vertices-1;
	for (int i=0; i<g->vertices; i++){
		if (g->visitado[i]==0){
			top_visit(g, i, v);
		}
	}
}

void print(gr *g){
	int j;
	no *k;
	cout<<"Lista de Adjacencias"<<endl;
	for (j=0; j<g->vertices; j++){
		cout<<j<<" -> ";
		for(k=g->adj[j]; k!=NULL; k=k->prox){
			cout<<k->rotulo<<" -> ";
		}
		cout<<endl;	
	}
}

void felineindex(gr *g){
	int *x,*y;
	x=(int*) malloc(g->vertices*sizeof(int));
	y=(int*) malloc(g->vertices*sizeof(int));
	top(g, x);// topological sort stored on x
	int heads[g->vertices][g->vertices], d[g->vertices], roots[g->vertices], iny[g->vertices];// lists heads, d(in degree), roots
	
	int headsend[g->vertices], rootsend=-1, yend=-1;// define variables for the start of the lists and set them to -1 (empty)
	for(int j=0; j<g->vertices; j++){
		headsend[j]=-1;
		d[j]=0;
		iny[j]=0;
	}
	
	for(int j=0; j<g->vertices; j++){// defines heads and d values
		for(no *k=g->adj[j]; k!=NULL; k=k->prox){
			heads[j][++headsend[j]]=k->rotulo;
			d[k->rotulo]++;
		}
	}
	
	for(int j=0; j<g->vertices; j++){
		if (d[j]==0){
			roots[++rootsend]=j;
		}
	}
	
	while(rootsend>-1){
		int u;
		//get the root with higher topologic order index and add it to y
		for(int j=g->vertices-1; j>=0; j--){
			if (d[x[j]]==0 && iny[x[j]]==0){
				u=x[j];
				break;
			}
		}
		y[++yend]=u;
		iny[u]=1;
		
		//remove u from roots
		int roots2[g->vertices];
		for(int j=0, i=0; j<=rootsend; j++){
			if(roots[j]!=u){
				roots2[i]=roots[j];
				i++;
			}
		}
		
		rootsend--;
		for(int j=0; j<=rootsend; j++){
			roots[j]=roots2[j];
		}
		
		
		for(int j=0; j<=headsend[u]; j++){
			d[heads[u][j]]--;
			if(d[heads[u][j]]==0){
				roots[++rootsend]=heads[u][j];
			}
		}	
	}
	
//	for(int j=0; j<g->vertices; j++){
//		cout<<x[j]<<"\t\t"<<y[j]<<endl;
//	}
//	cout<<endl<<endl<<endl;
	
	int x2[g->vertices], y2[g->vertices];
	for(int j=0; j<g->vertices; j++){
		x2[x[j]]=j+1;
		y2[y[j]]=j+1;
	}
	for(int j=0; j<g->vertices; j++){
		g->x[j]=x2[j];
		g->y[j]=y2[j];
	}
	for(int j=0; j<g->vertices; j++){
		cout<<g->x[j]<<"\t\t"<<g->y[j]<<endl;
	}	
}

int reachable(gr* g, int a, int b){
	if (a==b) return 0;
	if(g->x[a]<=g->x[b] && g->y[a]<=g->y[b]){
		for(no *j=g->adj[a]; j!=NULL; j=j->prox){
			if(reachable(g, j->rotulo, b)) return 1;
		}
	}
	return 0;
}
		


int main(){
	setlocale(LC_ALL, "Portuguese");
	gr G;
	inicializa(&G, 6000);
	int *a;
	FILE *q;
	q=fopen("arq.txt", "rt");
	if(q==NULL){
		cout<<"!!!!!!!!!!!";
	}

	char prim[1000];//string na primeira linha
	fgets(prim, 999, q);
	int ver;//numero de vertices
	fscanf(q, "%d\n", &ver);
	cout<<prim<<"Número de vértices: "<<ver<<endl;
	/////////////////////////////////////////////////////////////////////
	char st[6*ver];
	int size;// quantideade de elementos em verticess
	int verticess[ver];// lista de vértices adjacentes
	for(int j=0; j<ver; j++){
		fgets(st, 6*ver, q);	
		char aux[5];
		int k=0, h=0, numm;//numm indice, k indice do vetor aux, h indice vetor vertice;
		for(int i=0; st[i]!='#'; i++){
			if(st[i]==' '){
				aux[k++]='\n';
				verticess[h++]=atoi(aux);
				k=0;
			}
			else{
				aux[k++]=st[i];
			}
		}
		for(int i=1; i<h; i++){
			//cout<<verticess[i]<<", ";
			novaaresta(&G, verticess[0], verticess[i]);
		}
	//	cout<<endl<<h<<endl<<endl<<endl;
	}
	
	felineindex(&G);
	
	
	cout<<"!!";
	FILE *test;
	test=fopen("test.txt", "rt");
	int teste[bb][4];
	for(int a=0; a<bb; a++){
		fscanf(test, "%d %d %d\n", &teste[a][0], &teste[a][1], &teste[a][2]);
	}
	cout<<"!!!";
	int ae;
	ae=reachable(&G, 5383, 866);
	cout<<ae;
	
	
	
	
	return 0;
}
