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
