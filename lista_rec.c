#include <stdio.h>
#include <stdlib.h>
#include "lista_rec.h"

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

/* Funcao auxiliar recursiva para imprimir o encadeamento */
void imprime_nos (ListaNo* p)
{
   if (p != NULL) {
      printf("info = %d\n", p->info); /* Imprime o primeiro elemento */
      imprime_nos(p->prox);           /* Imprime o subencadeamento   */
   }
}

/* Funcao imprime recursiva: imprime valores dos elementos de forma recursiva */
void lst_imprime_rec (Lista* l)
{
   imprime_nos (l->prim);
}

/* Funcao auxiliar recursiva para imprimir o encadeamento na ordem inversa*/
void imprime_nos_rev (ListaNo* p)
{
   if (p != NULL) {
      imprime_nos_rev(p->prox);        /* Imprime o subencadeamento   */
      printf("info = %d\n", p->info);  /* Imprime o primeiro elemento */
   }
}

/* Funcao imprime recursiva: imprime valores dos elementos de forma recursiva na ordem inversa*/
void lst_imprime_rec_rev (Lista* l)
{
   imprime_nos_rev (l->prim);
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
/* Funcao auxiliar para retirar elemento da lista de forma recursiva*/
static ListaNo* retira_nos (ListaNo* p,int v) {

   ListaNo* t;      /* ponteiro temporario para poder liberar o elemento retirado*/

   if (p != NULL){
      if (p->info == v) { /* verifica se o elemento eh o primeiro */
        t = p;
        p = p->prox;      /* primeiro no eh alterado */
        free (t);
      }
      else p->prox = retira_nos(p->prox,v); /* retira elemento da subencadeamento */
   }
   return p;
}

/* Funcao retira: retira elemento da lista de forma recursiva */
void lst_retira_rec (Lista* l,int v)
{
    l->prim = retira_nos (l->prim,v);
}

static void libera_nos (ListaNo* p)
{
    if (p != NULL)
    {
        libera_nos (p->prox);
        free(p);
    }
}

void lst_libera_rec (Lista* l)
{
  libera_nos (l->prim);
  free (l);
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

/* Verifica se uma lista e igual a outra, retorna 1 se sao iguais e 0 se sao diferentes*/
int lst_igual (Lista* l1, Lista* l2)
{
    ListaNo* p1;
    ListaNo* p2;
    for (p1 = l1->prim, p2 = l2->prim;
         p1 != NULL && p2 != NULL;
         p1 = p1->prox, p2 = p2->prox)
         {
             if (p1->info != p2->info) return 0;
         }
    return (p1 == p2);
}

/* Verifica se uma lista e igual a outra, retorna 1 se sao iguais e 0 se sao diferentes*/
static int nos_iguais (ListaNo* p1, ListaNo* p2)
{
    if (p1 == NULL && p2 == NULL) return 1;
       else if (p1 == NULL || p2 == NULL) return 0;
            else return (p1->info == p2->info) && nos_iguais(p1->prox, p2->prox);
}

/* Verifica se uma lista e igual a outra de forma recursiva, retorna 1 se sao iguais e 0 se sao diferentes*/
int lst_igual_rec (Lista* l1, Lista* l2)
{
    return nos_iguais(l1->prim , l2->prim);
}
