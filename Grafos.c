/*Definição

*Como representar um conjunto de objetos
e as suas relacoes?
-Diversos tipos de aplicacoes necessitam disso
-Um grafo e um modelo matematico que
representa as relacoes entre objetos de um
determinado conjunto.

Grafos em computação
*Forma de solucionar problemas computáveis
*Buscam o desenvolvimento de algoritmos mais
eficientes
-Qual a melhor rota da minha casa até o restaurante?
-Duas pessoas tem amigos em comum?


*Um grafo G(V,A) é definido por dois conjuntos:
– Conjunto V de vértices (não vazio)
● Itens representados em um grafo;
– Conjunto A de arestas
● Utilizadas para conectar pares de vértices, usando um
critério previamente estabelecido.

ex: G(V,A)
V = {1,2,3,4}
A = {{1,2},{1,4},{2,3},{2,4}}


*Vértice é cada um dos itens representados
no grafo.
– O seu significado depende da natureza do
problema modelado
– Pessoas, uma tarefa em um projeto, lugares em
um mapa, etc.

ex: arvore é um tipo de grafo

Aresta (ou arco) liga dois vértices
*Diz qual a relação entre eles
*Dois vértices são adjacentes se existir uma aresta
ligando eles.
-Pessoas (parentesco entre elas ou amizade), tarefas de
um projeto (pré-requisito entre as tarefas), lugares de
um mapa (estradas que existem ligando os lugares), etc.

Praticamente qualquer objeto pode ser
representado como um grafo.
*Exemplo: sistema de distribuição de água

exemplo deixado no slide 7 
*Exemplo: rede social - slide 8

As arestas podem ou não ter direção
*Existe um orientação quanto ao sentido da
aresta
-Em um grafo direcionado ou digrafo, se uma
aresta liga os vértices A a B, isso significa que
podemos ir de A para B, mas não o contrário


Grau
*Indica o número de arestas que conectam
um vértice do grafo a outros vértices
-número de vizinhos que aquele vértice possui
no grafo (que chegam ou partem dele)
*No caso dos dígrafos, temos dois tipos de
grau:
-grau de entrada: número de arestas que
chegam ao vértice;
-grau de saída: número de arestas que partem
do vértice.
olhe os slide 11 

Laço
*Uma aresta é chamada de laço se seu vértice
de partida é o mesmo que o de chagada
-A aresta conecta o vértice a ele mesmo

Caminho
*Um caminho entre dois vértices é uma sequência
de vértices onde cada vértice está conectado ao
vértice seguinte por meio de uma aresta.
*Comprimento do caminho: número de
vértices que precisamos percorrer de um
vértice até o outro


Ciclo
*Caminho onde o vértice inicial e o final são o mesmo
vértice.
-Note que um ciclo é um caminho fechado sem vértices
repetidos (somente o nó origem abre e fecha o ciclo).
**arvores não tem ciclo 

Grafo trivial
*Possui um único vértice e nenhuma aresta


Grafo simples ex arore 
*Grafo não direcionado, sem laços e sem
arestas paralelas (multigrafo)

Grafo completo
*Grafo simples onde cada vértice se conecta
a todos os outros vértices do grafo.


Grafo regular
*Grafo onde todos os seus vértices possuem o
mesmo grau (número de arestas ligadas a ele)
*Todo grafo completo é também regular


Subgrafo
*Gs(Vs,As) é um subgrafo de G(V,A) se o conjunto
de vértices Vs for um subconjunto de V, Vs ⊇ V, e
se o conjunto de arestas As for um subconjunto de
A, As ⊇ A.

Grafo bipartido
*Um grafo G(V,A) onde o seu conjunto de
vértices pode ser divididos em dois
subconjuntos X e Y sem intersecção.
-As arestas conectam apenas os vértices que
estão em subconjuntos diferentes

Grafo conexo e desconexo
*Grafo conexo: existe um caminho ligando
quaisquer dois vértices. -- ex arvore 
*Quando isso não acontece, temos um
grafo desconexo

Grafos isomorfos
*Dois grafos, G1(V1,A1) e G2(V2,A2), são
ditos isomorfos se existe uma função que
faça o mapeamento de vértices e arestas
de modo que os dois grafos se tornem
coincidentes.
-Em outras palavras, dois grafos são isomorfos
se existe uma função f onde, para cada dois
vértices a e b adjacentes no grafo G1, f(a) e
f(b) também são adjacentes no grafo G2.
exemplo do slide 23

Grafo ponderado
*É um grafo que possui pesos (valor
numérico) associados a cada uma de suas
arestas.

Grafo Euleriano
*Grafo que possui um ciclo que visita todas
as suas arestas apenas uma vez, iniciando
e terminando no mesmo vértice.  --- pode repetir nós mas não arestas 


Grafo Euleriano
*Grafo que possui um caminho aberto (não
é um ciclo) que visita todas as suas arestas
apenas uma vez. logo seu nó de inicio não é o seu nó de fim.


Grafo Hamiltoniano
*Grafo que possui um caminho que visita
todos os seus vértices apenas uma vez.
*Pode ser um ciclo

Como representar um grafo no
computador?
*Existem duas abordagens muito utilizadas:
-Matriz de Adjacência
-Lista de Adjacência*Qual a representação que deve ser
utilizada?
-Depende da aplicação!


Matriz de adjacência
*Utiliza uma matriz N x N para armazenar o
grafo, onde N é o número de vértices
-Alto custo computacional, O(N2)
*Uma aresta é representada por uma marca
na posição (i , j) da matriz
-Aresta liga o vértice i ao j
olhe os slides 32


Lista de adjacência
*Utiliza uma lista de vértices para descrever
as relações entre os vértices.
- Um grafo contendo N vértices utiliza um array
de ponteiros de tamanho N para armazenar os
vértices do grafo
-Para cada vértice é criada uma lista de arestas,
onde cada posição da lista armazena o índice
do vértice a qual aquele vértice se conecta
olha os slides 34


Qual representação utilizar?
*Lista de adjacência é mais indicada para
um grafo que possui muitos vértices mas
poucas arestas ligando esses vértices.
*A medida que o número de arestas cresce e
não havendo nenhuma outra informação
associada a aresta (por exemplo, seu peso),
o uso de uma matriz de adjacência se torna
mais eficiente


Vamos usar uma lista de adjacência (Lista de arestas:
lista sequencial, ligadas a cada um dos vértices). A estrutura do
grafo deverá conter as seguintes informações:
*N: número de vértices do grafo.
*v: vetor de vértices, onde serão conectadas as listas de
arestas.
*carimbo: funciona como um relógio interno, na inicialização
de qualquer algoritmo atribuímos o valor 0 a este atributo,
cada vez que um registro de tempo for solicitado, retornamos
o valor corrente e incrementamos o relógio em uma unidade.


A estrutura do vértice deverá conter as seguintes informações:
*lista: ponteiro para a primeira aresta da lista.
*cor: as arestas quando processadas por uma busca em
profundidade, podem levar a um vértice ainda não explorado
(cor branca), em processamento (cor cinza) ou já explorados
(cor preta)
*ti: funciona como um relógio interno, quando iniciamos a
exploração do primeiro vértice, associamos o tempo inicial 0 a
este vértice, quando iniciamos a exploração de um primeiro
vértice adjacente, associamos o tempo 1 e assim por diante.
*tf: quando terminamos de visitar um vértice, registramos um
tempo de fim.
*vant: vértice anterior, usado para registrar o vértice que
explorou o vértice corrente (usada em busca em
profundidade).


estrutura do grafo

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "fila.h"

typedef enum vcor VCor;
enum vcor {
    BRANCO = 0, /*NAO EXPLORADO */
    CINZA,      /* SENDO EXPLORADO */
    PRETO       /* EXPLORADO */
};

typedef enum atipo ATipo;
enum atipo {
    ARVORE = 0,  /* ARESTA PERTENCENTE A ÁRVORE */
    TRAS,        /* ARESTA QUE TEVE QUE SER PERCORRIDA NO SENTIDO INVERSO */
    OUTRA       /* CRUZADA ou A FRENTE */
};

struct grafo {
   int n; /* numero de vertices */
   Vertice* v; /*vetor de vertices */
   /* demais atributos do grafo */
   int carimbo;
   /* demais atributos do grafo */
};

struct vertice {
   Aresta* lista; /* ponteiro para a primeira Aresta da lista */
   /* demais atributos dos vertices*/
   VCor cor; /* cor associada ao vertice */
   int ti;    /* tempo inicial */
   int tf;    /* tempo final  */
   int vant;  /* vertice anterior */
   /* demais atributos dos vertices*/
   float custo; /*guarda a distancia topologica do grafo, quando
                  percorremos atraves da busca em largura, ou
                  o custo do caminho mínimo desse vertice ate
                  o que foi considerado sua origem*/
};

struct aresta {
    int v;  /* vertice destino da aresta */
    Aresta* prox; /* vetor de vertices */
    /* demais atributos das arestas */
    ATipo tipo;   /* tipo da aresta */
    /* demais atributos das arestas */
    int distancia; /* distancia entre dois vertices */
};
/* TAD: Lista */

/* Tipo Exportado */
typedef struct grafo Grafo;
typedef struct vertice Vertice;
typedef struct aresta Aresta;

/*Função para criar um grafo:

/* funcao que cria um grafo com um numero determinado de vertices */
Grafo* grafo_cria (int n) {
    Grafo* g = (Grafo*) malloc(sizeof(Grafo));
    if (g == NULL) {
        printf("ERRO NA ALOCACAO DINAMICA DE MEMORIA");
        exit(1);
    }
    g->n = n;
    g->carimbo = -1;
    g->v = (Vertice*) malloc(n*sizeof(Vertice));
    for (int i = 0 ; i < n ; i++) g->v[i].lista = NULL;
    return g;

/*Criando um grafo de 6 vértices: exemplo no slide 41*/

  int main (void) {

    Grafo* g = grafo_cria(6); /* cria um grafo com seis vertices */
    grafo_insere_aresta (g,0,1);
    grafo_insere_aresta (g,0,3);
    grafo_insere_aresta (g,1,2);
    grafo_insere_aresta (g,1,4);
    grafo_insere_aresta (g,2,4);
    grafo_insere_aresta (g,2,5);
    grafo_insere_aresta (g,3,1);
    grafo_insere_aresta (g,4,3);
    grafo_insere_aresta (g,5,4);
    grafo_imprime (g);
/*Função para criar arestas:
/* funcao que insere uma aresta no grafo */
void grafo_insere_aresta (Grafo* g, int orig, int dest) {
    Aresta* a = (Aresta*) malloc(sizeof(Aresta));
    Aresta* aux = g->v[orig].lista; /* ponteiro auxiliar para percorrer a lista de aresta*/
    if (a == NULL) {
        printf("ERRO NA ALOCACAO DINAMICA DE MEMORIA");
        exit(1);
    }
    a->v = dest;
    a->distancia = rand()%100;
    a->prox = NULL;
    if (g->v[orig].lista == NULL) { /* nenhuma aresta alocada nesse no */
        g->v[orig].lista = a;
    }
    else { /* ja tem alguma aresta inserida no vertice, busco o local de insercao e
               refaco as ligacoes */
        while (aux->prox != NULL) aux = aux->prox;
        aux->prox = a;
    }
}  

/*olhe os slides 44 e 45 
    
 Agora vamos ver um exemplo de DFS, depth-first search
(Busca em Profundidade) no grafo dado inserido:*/

static void idfs (Grafo* g, int i) {
    Aresta* a; /*apontador para percorrer a lista de arestas*/
    g->v[i].cor = CINZA;
    g->v[i].ti = tempo(g);
    for (a = g->v[i].lista; a != NULL; a = a->prox) {
        int j = a->v;
        if (g->v[j].cor == BRANCO) {
            g->v[j].vant = i;
            a->tipo = ARVORE;
            idfs (g , j);
        }
        else if(g->v[j].cor == CINZA)
                a->tipo = TRAS;
             else a->tipo = OUTRA;
    }
    g->v[i].cor = PRETO;
    g->v[i].tf = tempo(g);

