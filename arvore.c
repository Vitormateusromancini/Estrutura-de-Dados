/*Diversas aplica��es necessitam que se
represente um conjunto de objetos e as
suas rela��es hier�rquicas
 *Uma �rvore � uma abstra��o
matem�tica usada para representar
estruturas hier�rquicas n�o lineares dos
objetos modelados


� um tipo especial de grafo
--Definida usando um conjunto de n�s (ou
v�rtices) e arestas
--Qualquer par de v�rtices est� conectado a
apenas uma aresta
--Grafo n�o direcionado(quando tem dois vertices conectados 
eles n tem uma dire��o definida isso significa que pode 
ir para um  lado ou outro), conexo e ac�clico (sem ciclos)

-V�rtice
* Cada uma das entidades representadas na
�rvore (depende da natureza do problema).
* Basicamente, qualquer problema em que
exista algum tipo de hierarquia pode ser
representado por uma �rvore 
Exemplo
-Estrutura de pastas do computador
-rela��es de descend�ncia (pai, filho, etc.)
-diagrama hier�rquico de uma organiza��o;
-campeonatos de modalidades desportivas;
-taxonomia


*Em computa��o
-busca de dados armazenados no computador
-representa��o de espa�o de solu��es
Exemplo: jogo de xadrez: modelagem de algoritmos


Um dos conceitos relativos as arvores que � importante saber s�o:

**Raiz
-n� mais alto na �rvore, o �nico que n�o possui pai
**Pai ou ancestral
-n� antecessor imediato de outro n�
**Filho
-� o n� sucessor imediato de outro n�


Principais conceitos relativos as �rvores

 *N� folha ou terminal
-qualquer n� que n�o possui filhos

*N� interno ou n�o-terminal
-n� que possui ao menos UM filho

*Caminho
-sequ�ncia de n�s de modo que existe sempre
uma aresta ligando o n� anterior com o
seguinte


*Observa��o

-Dado um determinado n� da �rvore, cada
filho seu � considerado a raiz de uma nova
sub-�rvore
-Qualquer n� � a raiz de uma sub-�rvore
consistindo dele e dos n�s abaixo dele
-Conceito recursivo


*Representa��o recursiva da �rvore:
� Vazia (isto �, sem nenhum n�), ou;
� Um n� seguido de duas sub�rvores (a da
esquerda e a da direita).


 Principais conceitos relativos as �rvores
*N�vel
-� dado pelo o n�mero de n�s que existem no
caminho entre esse n� e a raiz (n�vel 0)
- N�s s�o classificados em diferentes n�veis
* Altura
- Tamb�m chamada de profundidade
- N�mero total de n�veis de uma �rvore
- Comprimento do caminho mais longo da raiz
at� uma das suas folhas


Na computa��o, assim como na natureza, existem
v�rios tipos diferentes de �rvores.
-Cada uma delas foi desenvolvida pensando diferentes
tipos de aplica��es
- �rvore bin�ria de busca
- �rvore AVL (� uma �rvore bin�ria de busca, AVL vem de seus
criadores sovi�ticos Adelson Velsky e Landis)
- �rvore Rubro-Negra (�rvore bin�ria de busca balanceada)
- �rvore B, B+ e B* (�rvore de busca balanceada)
- �rvore 2-3
- �rvore 2-3-4
 -quadtree
 - octree
