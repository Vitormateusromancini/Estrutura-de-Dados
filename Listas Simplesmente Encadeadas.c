#include<stlib.h>

/*Lista*/

/*Cada elemento inserido requer uma
aloca��o de mem�ria.*/

/*Numa lista simplesmente encadeada,
junto com a informa��o a ser
armazenada, um ponteiro para o
pr�ximo elemento da lista (ou n�) deve
ser inclu�do.*/

/*Tem um ponteiro indicando o in�cio da lista
(prim).

Cada elemento (n�) da lista tem,
conceitualmente, dois campos: a informa��o
armazenada e um ponteiro para o pr�ximo
elemento da lista.

A partir do primeiro elemento da lista posso
alcancar o segundo e assim por diante.
O ultimo elemento da lista contem, como
proximo no um ponteiro invalido, ou seja, NULL
*/

/*Para construirmos um TAD-Lista,
consideramos dois tipos de estruturas:*/

/*uma lista que armazene n�meros
inteiros, podemos ter uma estrutura para
representar a lista*/

typedef struct lista Lista;

 struct lista{	
 	ListaNo* prim;
};

/*outra para representa um n�
dessa lista (autoreferenciada)*/

typedef struct listano ListaNo;

struct listano{
 	int info;
 	ListaNo* prox;
};

/*Funcao de criacao: Retorna uma lista sem nenhum elemento
*/

Lista* lst_cria (void)
{
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->prim = NULL;
    return l;
    
/* insercao no inicio: retorna a lista atualizada */
void lst_insere (Lista* l, int v)
{
   ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo));
   novo->info = v;
   novo->prox = l->prim; /* o novo vai apontar pro ultimo valor  */
   l->prim = novo; /* o penultimo vai apontar pro novo  */
}

int main (void)
{
	Lista*l;
	lst_insere(l,23);
	
/*vai inserir esse valor 23 na lista e assim por diante os proximos valores*/

	lst_insere(l,45);
	
	return0;
}

/*Fun��o de percorre a lista:
� Uso para mostrar na tela todos os elementos
da lista
� N�o permite

/* funcao imprime: imprime valores dos elementos */
void lst_imprime (Lista* l)
{
   ListaNo* p;   /* variavel auxiliar para percorrer a lista */
   for (p = l->prim; p != NULL; p = p->prox)
      printf("info = %d\n", p->info);
}

/*
Fun��o que verifica se determinado
elemento pertence a lista:
� Retorna 1, se o elemento pertence a lista e
0, caso contr�rio
/* funcao busca: busca um elemento na lista */
int lst_busca (Lista* l, int v)
{
   ListaNo* p;
   for (p=l->prim; p!=NULL; p=p->prox)
     if (p->info == v) return 1;
   return 0;  /* nao encontrou o elemento */
}
