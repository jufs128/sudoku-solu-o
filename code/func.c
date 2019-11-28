#include "func.h"

void ColocarArestas(Grafo G, int N, int I, int J, TipoLista *Lista){ //Cria as relações de conflito entre os espaços
    int i,j;
    for (i = 0; i < G->V; i++){
        for (j = (i % N); j < G->V; j = j + N){ //Relacionar com a coluna
            if (i != j) //Não há conflito com si mesmo
                CriaAresta(G,Lista->Celulas[i],Lista->Celulas[j]);
        }

        for (j = (N*(i/N)); j < ((N*((i/N)+1))); j++){ //Relacionar com a linha
            if (i != j)
                CriaAresta(G,Lista->Celulas[i],Lista->Celulas[j]);
        }

        //Relacionar com o quadrante
        j = (i - (i % I)); //j na primeira coluna do quadrante
        int m = j/N; // parte inteira da divisão de j por N (numero da linha)
        j = j - ((m % J) * N); //j na primeira linha do quadrante
        int x,y;
        for (x = 0; x < J; x++){ //Nas J linhas do quadrante
            for (y = 0; y < I; y++){ //Nas I colunas do quadrante
                if (i != j)
                    CriaAresta(G,Lista->Celulas[i],Lista->Celulas[j]);
                j++;
            }
            j = j - I; //Volta para primeira coluna do quadrante
            j = j + N; //Próxima linha do quadrante
        }

    }
}



int AtualizaCoresPoss(Grafo G, TipoLista *L, int N){ //Atualiza as cores possíveis para cada espaço
    int i,j;
    for(i = 0; i < G->V; i++){
        for(j = 0; j < G->V; j++){ //Entre todos os vértices
            if ((i != j) && (L->Celulas[i].Valor == 0)) { //Para células sem cor atribuída
                if((G->matriz[i][j] == 1) && (L->Celulas[j].Valor != 0)){
                    //Se há uma relação, sendo que o valor do que relaciona não é zero
                    if(G->MatVertCor[i][L->Celulas[j].Valor - 1] == 0) { //Se cor não estiver marcada como inválida
                        G->MatVertCor[i][L->Celulas[j].Valor - 1] = 1; //Marca a cor como inválida
                        L->Celulas[i].NumPoss--; //Diminui o número de cores possíveis

                        if(L->Celulas[i].NumPoss == 0){ //Se não há cores possíveis
                            return 1; //Retorna falso; erro no sudoku
                        }
                    }
                }
            }
        }
    }

    return 0;
}

int AchaIndice(Grafo G, TipoLista *L, int N){ //Acha o primeiro indice que pode ter a cor atribuída
    int i, id = -1; //Valor inicial de id é -1 (nenhum slot do vetor)
    for(i = 0; i < G->V; i++){
        if((L->Celulas[i].Valor == 0) && (L->Celulas[i].NumPoss == 1)){ //Se não tem valor atribuído e só uma possibilidade de cor
            id = i; //id é i
            break; //Quebra o loop
        }
    }
    return id; //Retorna id
}

int DeterminaCor(Grafo G, TipoLista *L, int id, int N){ //Acha a cor que deve ser atribuída ao espaço
    int i;
    for(i = 0; i < N; i++){
        if(G->MatVertCor[id][i] == 0){ //Seleciona a cor que é aceita pelo espaço
            return i; //Retorna o indice da cor
        }
    }
}

int Resolvido(Grafo G,TipoLista *L){ //Verifica se todos os valores foram atribuídos
    int i;

    for(i = 0; i < G->V; i++){
        if(L->Celulas[i].Valor == 0){ //Se algum valor for 0
            return 1; //Não foi atribuído; não terminou
        }
    }

    return 0; //Se nenhum é 0, terminou
}

int MudaValor(Grafo G, TipoLista *Lista, int id, int Cor, int N){ //Altera o valor de um espaço
    int i;

    if(Cor < N){ //Se Cor é maior que o número de cores disponíveis, pula
        Lista->Celulas[id].Valor = Cor + 1; //A Cor recebida é índice da matriz, então adiciona 1 para o valor real
        Lista->Celulas[id].NumPoss = 1; //A única possibilidade é a cor atribuída
        return 0; //Fez a mudança
    }
    return 1; //Não fez a mudança
}

int Solucao(Grafo G, TipoLista *Lista, int N){ //Acha a solução do sudoku
    int a, id, cor;
    do{
        a = AtualizaCoresPoss(G,Lista,N); //Atualiza as possibilidades de cores para os vértices
        if(a == 1){ //Se encontrou erro
            return 1; //Solução falha
        }

        id = AchaIndice(G, Lista, N); //Acha o indice do vértice a ser analisado
        if(id != -1){ //Se encontrou espaço válido
            cor = DeterminaCor(G, Lista, id, N); //Cor a ser atribuída
            if (MudaValor(G,Lista,id,cor,N) == 1){ //Se foi incapaz de mudar a cor
                return 1; //Solução falha
            }
        } else{ //Se não encontrou
            return 1; //Solução falha
        }
    } while (Resolvido(G,Lista) == 1); //Enquanto não tiver resolvido

    return 0; //Após o processo, volta
}

int ChecarSolucao(Grafo G, TipoLista *Lista){ //Checa se a solução está correta
    int i, j;
    for(i = 0; i < G->V; i++){ //Para todos os espaços
        if(Lista->Celulas[i].Valor == 0){ //Checa se valor não foi atribuído
            return 1; //Solução falha
        }

        for(j = 0; j < G->V; j++){ //Relação com os outros
            if(G->matriz[i][j] == 1){ //Se há conflito
                if(Lista->Celulas[i].Valor == Lista->Celulas[j].Valor){ //Verificar se algum tem valor igual
                    return 1; //Se tem, solução falha
                }
            }
        }
    }

    return 0; //Se não encontrou erro, soluçao correta
}
