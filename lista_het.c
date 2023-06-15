#include <stdio.h>
#include <stdlib.h>
#include "lista_het.h"

#define PI 3.14159

typedef enum tipo Tipo;
enum tipo {
    RET,
    TRI,
    CIRC
};

typedef struct retangulo{
    float b;
    float h;
    } Retangulo;

typedef struct triangulo{
    float b;
    float h;
    } Triangulo;

typedef struct circulo{
    float r;
    } Circulo;

struct listahet {
   ListaHetNo* prim;
};

struct listahetno {
    Tipo tipo;
    void* info;
    ListaHetNo* prox;
};


/* função de inicialização: retorna uma lista vazia */
ListaHet* lst_het_cria (void)
{
    ListaHet* l = (ListaHet*) malloc(sizeof(ListaHet));
    l->prim = NULL;
    return l;
}

void lst_het_libera (ListaHet* l)
{
   ListaHetNo* p = l->prim;
   while (p != NULL) {
      ListaHetNo* t = p->prox; /* guarda referência para o próximo elemento */
      free(p);  /* libera a memória apontada por p */
      p = t;   /* faz p apontar para o próximo */
   }
   free(l);
}

/* inserção no início: retorna a lista atualizada */
void lst_het_insere (ListaHet* l, ListaHetNo* p)
{
   p->prox = l->prim;
   l->prim = p;
}

/* Cria um no com um retangulo */
ListaHetNo* cria_ret (float b, float h)
{
    /* aloca retangulo */
    Retangulo* r = (Retangulo*) malloc(sizeof(Retangulo));
    r->b = b;
    r->h = h;
    /* aloca no */
    ListaHetNo* p = (ListaHetNo*) malloc(sizeof(ListaHetNo));
    p->tipo = RET;
    p->info = r;
    p->prox = NULL;
    return p;
}

/* Cria um no com um triangulo */
ListaHetNo* cria_tri (float b, float h)
{
    /* aloca triangulo */
    Triangulo* t = (Triangulo*) malloc(sizeof(Triangulo));
    t->b = b;
    t->h = h;
    /* aloca no */
    ListaHetNo* p = (ListaHetNo*) malloc(sizeof(ListaHetNo));
    p->tipo = TRI;
    p->info = t;
    p->prox = NULL;
    return p;
}

/* Cria um no com um circulo */
ListaHetNo* cria_circ (float r)
{
    /* aloca circulo */
    Circulo* c = (Circulo*) malloc(sizeof(Circulo));
    c->r = r;
    /* aloca no */
    ListaHetNo* p = (ListaHetNo*) malloc(sizeof(ListaHetNo));
    p->tipo = CIRC;
    p->info = c;
    p->prox = NULL;
    return p;
}

/* função imprime: imprime valores dos elementos */
void lst_het_imprime (ListaHet* l)
{
   ListaHetNo* p;   /* variável auxiliar para percorrer a lista */
   for (p = l->prim; p != NULL; p = p->prox)
   {
    switch (p->tipo){
    case RET: {
        Retangulo* r = (Retangulo*) p->info;
        printf("\n O retangulo tem base = %f e altura = %f: ", r->b,r->h);
    }
    break;
    case TRI: {
        Triangulo* t = (Triangulo*) p->info;
        printf("\n O triangulo tem base = %f e altura = %f: ", t->b,t->h);
    }
    break;
    case CIRC: {
        Circulo* c = (Circulo*) p->info;
        printf("\n O Circulo tem raio = %f: ", c->r);
    }
    break;
  }
 }
}

/* funcao auxiliar para o calculo da area correspondente ao no */
static float area (ListaHetNo* p)
{
    switch (p->tipo){
    case RET: {
        Retangulo* r = (Retangulo*) p->info;
        return r->b*r->h;
    }
    break;
    case TRI: {
        Triangulo* t = (Triangulo*) p->info;
        return (t->b*t->h)/2;
    }
    break;
    case CIRC: {
        Circulo* c = (Circulo*) p->info;
        return PI*c->r*c->r;
    }
    break;
 }
}


/*funcao que calcula a maior area da figura geometrica */
float max_area (ListaHet* l)
{
    float amax = 0.0;
    float a;
    ListaHetNo* p;
    for (p = l->prim; p!= NULL; p = p->prox)
    {
        a = area(p);
        if (a > amax) amax = a;
    }
    return amax;
}

