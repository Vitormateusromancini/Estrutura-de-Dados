#include <stdio.h>
#include <stdlib.h>
#include "lista_te.h"

typedef struct retangulo Retangulo;
struct retangulo {
    float b;
    float h;
};

struct lista {
   ListaNo* prim;
};

struct listano {
   Retangulo* info;
   ListaNo* prox;
};


/* função de inicialização: retorna uma lista vazia */
Lista* lst_cria (void)
{
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->prim = NULL;
    return l;
}

/* insercao no início: informando a base e altura */
void lst_insere (Lista* l, float b, float h)
{
    Retangulo* r = (Retangulo*) malloc(sizeof(Retangulo));
    ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo));
    r->b = b;
    r->h = h;
    novo->info = r;
    novo->prox = l->prim;
    l->prim = novo;
}

/* função imprime: imprime valores dos elementos */
void lst_imprime (Lista* l)
{
   ListaNo* p;   /* variável auxiliar para percorrer a lista */
   for (p = l->prim; p != NULL; p = p->prox)
      printf("base = %f e altura = %f\n", p->info->b,p->info->h);
}


void lst_libera (Lista* l)
{
   ListaNo* p = l->prim;
   while (p != NULL) {
      ListaNo* t = p->prox; /* guarda referência para o próximo elemento */
      free(p);  /* libera a memória apontada por p */
      p = t;   /* faz p apontar para o próximo */
   }
   free(l);
}

