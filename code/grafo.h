#ifndef GRAFO_H
#define GRAFO_H
#include "lista.h"

struct grafo{
    int V; //Quantidade de vértices
    int A; //Quantidade de arestas
    int **matriz; //Matriz de adjacência
    int **MatVertCor; //Matriz de disponibilidade de cor por vértice
};

typedef struct grafo *Grafo; //Ponteiro de grafo

int** InicializaMatriz (int n, int p); //Inicializa matriz de dimensão

Grafo InicializaGrafo (int n); //Inicializa o grafo para sudoku de dimensão n

void CriaAresta (Grafo G, TipoCelula x, TipoCelula y); //Cria aresta entre dois vértices

#endif // GRAFO_H
