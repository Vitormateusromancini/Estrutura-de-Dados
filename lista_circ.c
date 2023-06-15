#include <stdio.h>
#include "lista_circ.h"



struct lista {
   ListaNo* prim;
};

struct listano {
   int info;
   ListaNo* prox;
};


/* função de inicialização: retorna uma lista vazia */
Lista* lst_cria (void)
{
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->prim = NULL;
    return l;
}

/* inserção no início: retorna a lista atualizada */
void lst_insere (Lista* l, int v)
{
   ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo));
   novo->info = v;
   novo->prox = l->prim;
   l->prim = novo;
}

/* função imprime: imprime valores dos elementos */
void lst_imprime (Lista* l)
{
   ListaNo* p;   /* variável auxiliar para percorrer a lista */
   for (p = l->prim; p != NULL; p = p->prox)
      printf("info = %d\n", p->info);
}

/* função vazia: retorna 1 se vazia ou 0 se não vazia */
int lst_vazia (Lista* l)
{
   if (l->prim == NULL)
      return 1;
   else
      return 0;
}

/* função busca: busca um elemento na lista */
Lista* lst_busca (Lista* l, int v)
{
   ListaNo* p;
   for (p=l; p!=NULL; p=p->prox)
     if (p->info == v) return 1;
   return 0;  /* não achou o elemento */
}

/* função retira: retira elemento da lista */
void lst_retira (Lista* l,int v) {

   ListaNo* ant = NULL; /*ponteiro para elemento anterior */
   ListaNo* p = l->prim;      /* ponteiro para percorrer a lista*/

   /* procura elemento na lista, guardando anterior */
   while (p != NULL && p->info != v) {
        ant = p;
        p = p->prox;
   }
   /* verifica se achou elemento */
   if (p == NULL) return; /* não achou: lista original nao se altera*/
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


void lst_libera (Lista* l)
{
   ListaNo* p = l->prim;
   while (p != NULL) {
      ListaNo* t = p->prox; /* guarda referência para o próximo elemento */
      free(p);  /* libera a memória apontada por p */
       p = t;   /* faz p apontar para o próximo */
   }
}

/* insere elementos mantendo a lista em ordem crescente */
void lst_insere_ordenado (Lista* l, int v)
{
   ListaNo* ant = NULL; /*ponteiro para elemento anterior */
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

/* Função que converte uma lista de encadeamento simples em uma lista circular */
void lst_converte(Lista* l)
{
    ListaNo* p = l->prim; /* variável auxiliar para percorrer a lista */
    if (p != NULL)
    while (p->prox != NULL)
    {
       p = p->prox;
    }
    p->prox = l->prim;
    return;
}

void lst_libera_circ (Lista* l)
{
   ListaNo* p = l->prim;
   ListaNo* t;
   if (p != NULL)
    while (p != l->prim)
    {
      t = p->prox; /* guarda referência para o próximo elemento */
      free(p);  /* libera a memória apontada por p */
      p = t;   /* faz p apontar para o próximo */
    }
}

/* funcao imprime: imprime valores dos elementos de uma lista circular*/
void lst_imprime_circular (Lista* l)
{
    ListaNo* p = l->prim; /* variavel auxiliar para percorrer a lista */
    if (lst_vazia(l)) return;
    do
    {
        printf("info = %d\n", p->info);
        p = p->prox;
    } while(p != l->prim);

}
