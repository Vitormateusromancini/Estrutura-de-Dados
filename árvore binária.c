/*Diversas aplicações necessitam que se
represente um conjunto de objetos e as
suas relações hierárquicas
 *Uma árvore é uma abstração
matemática usada para representar
estruturas hierárquicas não lineares dos
objetos modelados


É um tipo especial de grafo
--Definida usando um conjunto de nós (ou
vértices) e arestas
--Qualquer par de vértices está conectado a
apenas uma aresta
--Grafo não direcionado(quando tem dois vertices conectados 
eles n tem uma direção definida isso significa que pode 
ir para um  lado ou outro), conexo e acíclico (sem ciclos)

-Vértice
* Cada uma das entidades representadas na
árvore (depende da natureza do problema).
* Basicamente, qualquer problema em que
exista algum tipo de hierarquia pode ser
representado por uma árvore 
Exemplo
-Estrutura de pastas do computador
-relações de descendência (pai, filho, etc.)
-diagrama hierárquico de uma organização;
-campeonatos de modalidades desportivas;
-taxonomia


*Em computação
-busca de dados armazenados no computador
-representação de espaço de soluções
Exemplo: jogo de xadrez: modelagem de algoritmos


Um dos conceitos relativos as arvores que é importante saber são:

**Raiz
-nó mais alto na árvore, o único que não possui pai
**Pai ou ancestral
-nó antecessor imediato de outro nó
**Filho
-é o nó sucessor imediato de outro nó


Principais conceitos relativos as árvores

 *Nó folha ou terminal
-qualquer nó que não possui filhos

*Nó interno ou não-terminal
-nó que possui ao menos UM filho

*Caminho
-sequência de nós de modo que existe sempre
uma aresta ligando o nó anterior com o
seguinte


*Observação

-Dado um determinado nó da árvore, cada
filho seu é considerado a raiz de uma nova
sub-árvore
-Qualquer nó é a raiz de uma sub-árvore
consistindo dele e dos nós abaixo dele
-Conceito recursivo


*Representação recursiva da árvore:
– Vazia (isto é, sem nenhum nó), ou;
– Um nó seguido de duas subárvores (a da
esquerda e a da direita).


 Principais conceitos relativos as árvores
*Nível
-É dado pelo o número de nós que existem no
caminho entre esse nó e a raiz (nível 0)
- Nós são classificados em diferentes níveis
* Altura
- Também chamada de profundidade
- Número total de níveis de uma árvore
- Comprimento do caminho mais longo da raiz
até uma das suas folhas


Na computação, assim como na natureza, existem
vários tipos diferentes de árvores.
-Cada uma delas foi desenvolvida pensando diferentes
tipos de aplicações
- árvore binária de busca
- árvore AVL (é uma árvore binária de busca, AVL vem de seus
criadores soviéticos Adelson Velsky e Landis)
- árvore Rubro-Negra (árvore binária de busca balanceada)
- árvore B, B+ e B* (árvore de busca balanceada)
- Árvore 2-3
- árvore 2-3-4
 -quadtree
 - octree
 
----Arvore binaria-------


  É um tipo especial de árvore
-Cada nó pode possuir nenhuma, uma ou no
máximo duas sub-árvores
- Sub-árvore da esquerda e a da direita
- Usadas em situações onde, a cada passo, é
preciso tomar uma decisão entre duas direções

 
 Existem três tipos de árvores binárias
*Estritamente binária
*Completa
* Cheia

---Árvore estritamente binária---
-Cada nó possui sempre ou 0 (no caso de nó
folha) ou 2 sub-árvores
- Nenhum nó tem filho único

--- Árvore binária completa---
-A diferença de altura entre as sub-árvores
de qualquer nó é no máximo 1
- Se a altura da árvore é D, cada nó folha
está no nível D ou D-1


 ----Árvore binária cheia----
-Árvore estritamente binária onde todos os nó
folhas estão no mesmo nível
 
 **Como implementar uma árvore no
computador?
*Existem duas abordagens muito
utilizadas
- Usando um array (alocação estática)
- Usando uma lista encadeada (alocação
dinâmica)

***Usando um array (alocação estática)
-Necessário definir o número máximo de nós
- Tamanho do array
- Usa 2 funções para retornar a posição dos filhos à
esquerda e à direita de um pai

***Lista encadeada (alocação dinâmica)
-Espaço de memória alocado em tempo de execução
- A árvore cresce à medida que novos elementos são
armazenados, e diminui à medida que elementos são
removidos

***Definição
-Uso de alocação dinâmica
- Para guardar o primeiro nó da árvore utilizamos
um ponteiro para ponteiro
- Um ponteiro para ponteiro pode guardar o
endereço de um ponteiro
- Assim, fica fácil mudar quem é a raiz da árvore
(se necessário)


 */


#include <stdio.h>
#include <stdlib.h>
#include "arvore_bin.h"

struct arvno {
    char info;
    ArvNo* esq;
    ArvNo* dir;
};

struct arv {
 ArvNo* raiz;
};

/* Tipo Exportado */
typedef struct arvno ArvNo;
typedef struct arv Arv;

/* Criando a árvore


criar uma estrutura de Ãrvore BinÃ¡ria Somente com o NÃ³ Raiz*/
Arv* arv_cria (ArvNo* r)
{
  Arv* a = (Arv*) malloc(sizeof(Arv));
  a->raiz = r;
  return a;
}

/* criar uma estrutura de arvore binaria */
ArvNo* arv_criano (char c, ArvNo* esq, ArvNo* dir)
{
  ArvNo* p = (ArvNo*) malloc(sizeof(ArvNo));
  p->info = c;
  p->esq = esq;
  p->dir = dir;
  return p;
}

/*para criar a arvore tem que colocar na função man (arvore_bin_code.c)*/ 
 
int main (void) {

Arv* a;
Arv* b;
ArvNo* r;
a = arv_cria(NULL);

/*Considere a árvore do slide 28 :
– Se representarmos
a árvore vazia por <>
– E as não vazias por
<raiz sae sad>
– A árvore da figura pode ser representada como:(slide 28)
*/


/*A função para imprimir a árvore usando a
notação anterior é a seguinte:*/
/* Estrutura auxiliar para imprimir uma arvore Binaria */
static void imprime (ArvNo* r)
{
   printf("<");
   if (r != NULL)
   {
      printf("%c ", r->info); /* imprime a informação */
      imprime(r->esq);  /* mostra a sae  */
      imprime(r->dir);  /* mostra a sad  */
   }
   printf(">");
}
/* Imprime uma arvore Binaria */
void arv_imprime (Arv* a)
{
    imprime(a->raiz);
}

/*Liberando a árvore
-Uso de 2 funções: uma percorre e libera os nós,
outra trata a raiz
/* Estrutura auxiliar para liberar a memoria ocupada pela arrvore Binaria */
static void libera (ArvNo* r)
{
   if (r != NULL)
   {
      libera(r->esq);       /* libera a sae  */
      libera(r->dir);       /* libera a sad  */
      free(r);              /*  libera a raiz */
   }
}

/* Libera a memoria ocupada pela arvore binaria */
void arv_libera (Arv* a)
{
      libera(a->raiz);   /* libera hierarquia de nos  */
      free(a);              /*  libera a raiz */
}

/*Remoção (liberação de memória): passo a passo  (slide 31)*/

/*Informações básicas sobre a árvore
--Altura
*Número total de níveis de uma árvore*/

/* Estrutura auxiliar para r a altura da Ãrvore BinÃ¡ria */
static int altura (ArvNo* r) {
   if (r == NULL) return -1;
   else return 1 + max2(altura(r->esq) , altura(r->dir));
}
/* Retorna a altura da Ãrvore BinÃ¡ria */
int arv_altura (Arv* a) {
   return altura(a->raiz);
}
/*
--Informações básicas sobre a árvore
*Altura (slide 33)


**Informações básicas sobre a árvore
-Número de nós
- Quantidade de elementos na árvore

/* Estrutura auxiliar para contar o numero de nos */
static int num_nos (ArvNo* r) {
    if (r == NULL)
       return 0;
    else
        return (1 + num_nos(r->esq) + num_nos(r->dir));
}

/* Retorna o numero de nÃ³s em uma Ãrvore BinÃ¡ria */
int arv_num_nos (Arv* a) {
    return num_nos (a->raiz);
}

/*Informações básicas sobre a árvore
-Número de nós(slide 35)

**Percorrer todos os nós é uma operação
muito comum em árvores binárias
-Cada nó é visitado uma única vez
* Isso gera uma sequência linear de nós, cuja ordem
depende de como a árvore foi percorrida
- Não existe uma ordem natural para se
percorrer todos os nós de uma árvore binária

-Isso pode ser feito para executar alguma ação
em cada nó
* Essa ação pode ser mostrar (imprimir) o valor do
nó, modificar esse valor, etc.



  Podemos percorrer a árvore de 3 formas:

-Percurso pré-ordem
* visita a raiz, o filho da esquerda e o filho da direita

- Percurso em-ordem
* visita o filho da esquerda, a raiz e o filho da direita

- Percurso pós-ordem
* visita o filho da esquerda, o filho da direita e a raiz

- Essas são os percursos mais importantes
- Existem outras formas de percurso

Ordem de visitação
*Raiz
* Subárvore esquerda
* Subárvore direita
/* Estrutura auxiliar para imprimir uma arvore Binaria */
static void imprime (ArvNo* r)
{
   printf("<");
   if (r != NULL)
   {
      printf("%c ", r->info); /* imprime a informação */
      imprime(r->esq);  /* mostra a sae  */
      imprime(r->dir);  /* mostra a sad  */
   }
   printf(">");
}
/* Imprime uma arvore Binaria */
void arv_imprime (Arv* a)
{
    imprime(a->raiz);
}
