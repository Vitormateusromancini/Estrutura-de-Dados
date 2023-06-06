#include<stlib.h>

/*Lista*/

/*Cada elemento inserido requer uma
alocação de memória.*/

/*Numa lista simplesmente encadeada,
junto com a informação a ser
armazenada, um ponteiro para o
próximo elemento da lista (ou nó) deve
ser incluído.*/

/*Tem um ponteiro indicando o início da lista
(prim).

Cada elemento (nó) da lista tem,
conceitualmente, dois campos: a informação
armazenada e um ponteiro para o próximo
elemento da lista.

A partir do primeiro elemento da lista posso
alcancar o segundo e assim por diante.
O ultimo elemento da lista contem, como
proximo no um ponteiro invalido, ou seja, NULL
*/

/*Para construirmos um TAD-Lista,
consideramos dois tipos de estruturas:*/

/*uma lista que armazene números
inteiros, podemos ter uma estrutura para
representar a lista*/

typedef struct lista Lista;

 struct lista{	
 	ListaNo* prim;
};

/*outra para representa um nó
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

/*Função de percorre a lista:
– Uso para mostrar na tela todos os elementos
da lista
– Não permite

/* funcao imprime: imprime valores dos elementos */
void lst_imprime (Lista* l)
{
   ListaNo* p;   /* variavel auxiliar para percorrer a lista */
   for (p = l->prim; p != NULL; p = p->prox)
      printf("info = %d\n", p->info);
}

/*
Função que verifica se determinado
elemento pertence a lista:
– Retorna 1, se o elemento pertence a lista e
0, caso contrário
/* funcao busca: busca um elemento na lista */
int lst_busca (Lista* l, int v)
{
   ListaNo* p;
   for (p=l->prim; p!=NULL; p=p->prox)
     if (p->info == v) return 1;
   return 0;  /* nao encontrou o elemento */
}
/*Manutenção da lista ordenada:
– Caso desejemos manter uma lista
com uma determinada ordenação,
necessitamos encontrar a posição
correta da inserção, para depois
efetivá-la
Se for o primeiro elemento recai na inserção no
início da lista, caso contrário se insere após o
anterior.
/* insere elementos mantendo a lista em ordem crescente */
void lst_insere_ordenado (Lista* l, int v) {
   ListaNo* ant = NULL;       /*ponteiro para elemento anterior */
   ListaNo* p = l->prim;      /* ponteiro para percorrer a lista*/
   ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo));
   novo->info = v;
   /* localiza o ponto de insercao */
   while (p != NULL && p->info < v) {
        ant = p;
        p = p->prox;
   }
   /* encadeia elemento */
   if (ant == NULL) { /* insere elemento do inicio */
      novo->prox = l->prim;
      l->prim = novo;
      }
   else { /* insere elemento do meio da lista */
      novo->prox = ant->prox;
      ant->prox = novo;
    }
}
	
/*Função que retira um elemento da lista: pode ser no primeiro da lista ou no meio 
/* funcao retira: retira elemento da lista */
void lst_retira (Lista* l,int v) {
   ListaNo* ant = NULL;     /*ponteiro para elemento anterior */
   ListaNo* p = l->prim;    /* ponteiro para percorrer a lista*/
   /* procura elemento na lista, guardando anterior */
   while (p != NULL && p->info != v) {
        ant = p;
        p = p->prox;
   }
   /* verifica se achou elemento */
   if (p == NULL) return; /* nao achou: lista original nao se altera*/
   /* retira elemento */
   if (ant == NULL) {
      /* retira elemento do inicio */
      l->prim = p->prox;
      }
   else {
      /* retira elemento do meio da lista */
      ant->prox = p->prox;
    }
   free(p);
}
/*Função que verifica se a lista está vazia e
libera a memória ocupada
/* funcao vazia: retorna 1 se vazia ou 0 se nao vazia */
int lst_vazia (Lista* l)
{
   if (l->prim == NULL)
      return 1;
   else
      return 0;
}
void lst_libera (Lista* l)
{
   ListaNo* p = l->prim;
   while (p != NULL) {
      ListaNo* t = p->prox; /* guarda referencia para o proximo elemento */
      free(p);  /* libera a memoria apontada por p */
       p = t;   /* faz p apontar para o proximo */
   }
   free(l);
}
	
	/*olhar os outros slides de listas com os arquivos disponiveis no moodle*/
	
