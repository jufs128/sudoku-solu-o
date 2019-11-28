#include "func.h"

int main(int argc, char *argv[]) {
    //Medir tempo
    //clock_t tempoInicial;
    //clock_t tempoFinal;
    //tempoInicial = clock();

    char NomeArq[100];
    if(argc > 1){ //Verifica se o nome do arquivo foi colocado como parâmetro
        strcpy(NomeArq,argv[1]); //Copia o nome para string NomeArq
    } else { //Se não foi colocado, pede para inserir
        printf("Digite o nome do arquivo de entrada: ");
        scanf("%s",NomeArq); //Lê da stdin
    }
    FILE *arq;
    arq = fopen(NomeArq,"r"); //Abre o arquivo para leitura
    if(arq==NULL){ //Se arquivo inserido não está na pasta
        printf("Erro ao abrir arquivo de entrada.\n"); //Dá erro
        return 1;
    }

    int N,I,J;
    fscanf(arq,"%d %d %d",&N,&I,&J); //Lê o tamanho do jogo (N*N) e dimensão dos quadrantes (I*J)

    TipoCelula C;
    TipoLista *ListaCelulas = malloc(sizeof(TipoLista)); //Lista de alunos
    ListaVazia(ListaCelulas); //Inicialmente lista está vazia
    Grafo G = InicializaGrafo(N); //Inicializa grafo
    int c,x,y,aux;

    for (c = 0; c < (N*N); c++){ //Para (N*N) espaços
        fscanf(arq,"%d",&aux); //Lê os valores

        C.Id = c; //id é a ordem de entrada
        C.Valor = aux; //Valor é o que foi lido

        if(aux == 0){ //Se valor lido é 0
            C.NumPoss = N; //Pode ser, inicialmente qualquer cor (vai ser atualizado em Solucao
        } else{ //Se valor já está inserido
            C.NumPoss = 1; //Só pode ser aquela cor
            for(x = 0; x < N; x++){
                if(x != (aux - 1)){ //Para qualquer cor que não seja a entrada
                    G->MatVertCor[c][x] = 1; //Não pode ser
                }
            }
        }

        CadastraCelula(C, ListaCelulas); //Cadastra o espaço na lista
    }

    ColocarArestas(G, N, I, J, ListaCelulas); //Cria as relações entre os espaços

    int s = Solucao(G, ListaCelulas, N); //Acha a solução da instância

    if(ChecarSolucao(G,ListaCelulas) == 1){ //Se a solução não está correta
        printf("sem "); //coloca o sem antes de solução
    }

    printf("solução\n");

    for(c = 0; c < (N*N); c++){ //Imprime a solução encontrada
        printf("%d ",ListaCelulas->Celulas[c].Valor);
        if(((c+1)%N) == 0){ //Se é o fim da linha do sudoku
            printf("\n"); //próxima linha
        }
    }

    //tempoFinal = clock();
    //printf("%f,",(tempoFinal- tempoInicial) * 1000.0 / CLOCKS_PER_SEC);

    return 0;
}
