#ifndef LISTA_H
#define LISTA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    int Id; //id do espaço
    int Valor; //Valor do espaço
    int NumPoss; //Numero de cores possíveis para o espaço
} TipoCelula;

typedef struct {
    TipoCelula Celulas[100]; //Lista de alunos; maximo de 100
    int Primeiro; //Primeiro indice
    int Ultimo; //Ultimo indice
} TipoLista;

void ListaVazia(TipoLista *Lista);

void CadastraCelula(TipoCelula x, TipoLista *Lista);

#endif // LISTA_H
