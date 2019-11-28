#include "lista.h"

void ListaVazia(TipoLista *Lista) { //Cria uma lista vazia
    Lista->Primeiro = 0; //Primeiro índice  0
    Lista->Ultimo = Lista->Primeiro; //Lista vazia; ultimo é o primeiro
}

void CadastraCelula(TipoCelula x, TipoLista *Lista) { //Cadastra o espaço na lista
    if(Lista->Ultimo >= 100){ //Verifica se a lista já atingiu o maximo
        printf("Numero maximo de celulas atingido.\n");
    } else{
        Lista->Celulas[Lista->Ultimo] = x; //Coloca espaço em ultimo lugar da lista
        Lista->Ultimo++; //Adiciona 1 ao índice do ultimo
    }
}
