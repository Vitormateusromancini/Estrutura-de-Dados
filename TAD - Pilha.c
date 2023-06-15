/*A ideia fundamental da pilha é que todo acesso
aos seus elementos é feito através do topo.
– Cada elemento introduzido na pilha passa a
ser o elemento do topo.
– O único elemento que pode ser retirado da
pilha é o topo.
– Lembre-se de uma pilha de pratos.
– LIFO (Last In , First Out).
– Funções principais Push (empilhar) e Pop
(desempilhar)


Um exemplo típico de pilhas é a própria pilha de
execução da linguagem C (já vimos como ela
funciona nos exemplos de recursividade).


Considere uma pilha que armazena valores
reais.
O TAD-Pilha sera composto de 5 operacoes:
-Criar uma pilha vazia.
-Inserir um elemento no topo (push)
-Remover um elemento do topo (pop)
-Verificar se a pilha esta vazia
-Liberar a estrutura da pilha

A interface pilha.h pode conter o seguinte
código.


******inserir o código********* */

typedef struct pilhavet Pilhavet;

PilhaVet* pilha_vet_cria (void);

/*A melhor implementação é através de um
Vetor Dinâmico, pois tem-se a cada instante o
tamanho da pilha através da informação do
elemento que está no topo da mesma.
– Veja que o nó da pilha é exatamente igual a um
elemento do Vetor Dinâmico para armazenar
números reais.

******inserir o código*********

Função para criar a pilha (escolhe a dimensão
inicial e cria uma pilha vazia).


******inserir o código*********

Para inserir um elemento na pilha (usa a
próxima posição livre do vetor e realoca
memória se necessário).

******inserir o código*********


Retira o elemento do topo da pilha,
fornecendo seu valor como retorno.


******inserir o código*********

Para verificar que a pilha esteja vazia e libera
a memória alocada a ela.

******inserir o código*********
