#ifndef FUNC_H
#define FUNC_H
#include "grafo.h"

void ColocarArestas(Grafo G, int N, int I, int J, TipoLista *Lista); //Cria as relações de conflito entre os espaços

int AtualizaCoresPoss(Grafo G, TipoLista *L, int N); //Atualiza as cores possíveis para cada espaço

int AchaIndice(Grafo G, TipoLista *L, int N); //Acha o primeiro indice que pode ter a cor atribuída

int DeterminaCor(Grafo G, TipoLista *L, int id, int N); //Acha a cor que deve ser atribuída ao espaço

int Resolvido(Grafo G,TipoLista *L); //Verifica se já foi resolvido

int MudaValor(Grafo G, TipoLista *Lista, int id, int Cor, int N); //Altera o valor do vértice para a cor escolhida

int Solucao(Grafo G, TipoLista *Lista, int N); //Acha a solução da instância

int ChecarSolucao(Grafo G, TipoLista *Lista); //Verifica a solução

#endif // FUNC_H
