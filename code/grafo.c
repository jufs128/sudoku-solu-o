#include "grafo.h"

int** InicializaMatriz (int n, int p) { //Inicializa a matriz
    int j, i;

    int **m = (int**)malloc(n*sizeof(int*)); //Ponteiro de ponteiros
    for(i = 0; i < n; i++){
        m[i] = (int*)malloc(n*sizeof(int)); //Para cada ponteiro (linha) cria outro (coluna)
        for(j = 0; j < p; j++){
            m[i][j] = 0; //Inicializa toda como 0
        }
    }

    return m;
}

Grafo InicializaGrafo (int n) { //Inicializa o grafo
    Grafo G = malloc(sizeof *G); //Cria a variável do grafo
    G->V = n*n; //Numero de vértices é N ao quadrado
    G->A = 0; //Numero de arestas é inicialmente 0
    G->matriz = InicializaMatriz(n*n,n*n); //Inicializa a matriz do grafo
    G->MatVertCor = InicializaMatriz(n*n,n); //Inicializa a matriz da relação entre vertices e cores
    return G;
}

void CriaAresta (Grafo G, TipoCelula x, TipoCelula y) { //Coloca a aresta desejada na matriz do grafo
    if (G->matriz[x.Id][y.Id] == 0){ //Verifica se a aresta já existe
        G->matriz[x.Id][y.Id] = 1; //Coloca como 1 na matriz
        G->A++; //Adiciona 1 ao número de arestas
    }
}
