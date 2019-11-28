# sudoku-solucao
  O programa recebe as dimensões do sudoku e de seus quadrantes, seguido do próprio jogo com 0 para os espaços em branco, e o resolve.
          
  *OBS.: Não resolve para todas as instâncias. Quando o algoritmo não consegue encontrar solução, retorna "sem solução" e onde a solução parou."*
  
## Implementação
  As relações de conflito entre blocos do Sudoku foram implementadas por meio de um grafo (arestas entre espaços em que há conflito), o qual é representado por uma matriz de adjacência. Os dados (valor atual, número de valores possíveis, e id) de cada espaço foram guardados numa lista sequencial. Além disso, foi feita uma matriz espaços x valores, sendo que um valor (x,y) = 0 se o espaço x pode ser o valor y e (x,y) = 1 se x não pode ser y.
  
## Entrada
  A entrada começa com três inteiros N (o jogo pe NxN), I (número de colunas do quadrante) e J (número de linhas do quadrante). Depois, a instância do Sudoku a ser resolvida. Exemplo:
  
#### Entrada:
4 2 2             
0 3 0 4         
0 0 0 0         
0 0 0 0         
3 0 2 0         

#### Saída:
solução         
2 3 1 4         
4 1 3 2         
1 2 4 3         
3 4 2 1         

## Compilação
Na pasta archives está incluso um Makefile, basta digitar make na linha de comando.

## Execução
A função funciona passando o nome do arquivo .txt como parâmetro, mas, caso isso não seja feito, pede para o usuário digitar o nome do arquivo no início da execução.

*Obs.: Inclua o .txt no nome do arquivo, isto é, nome.txt e não somente nome.*
