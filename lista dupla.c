/*Cada elemento da lista tem um apontador
para o seu sucessor e para seu
antecessor.
Com isso consigo acessar tanto o
elemento imediatamente anterior quanto
o imediatamento posterior da lista.
Para construirmos um TAD-Lista-Dupla, também
consideramos dois tipos de estruturas, da mesma
forma que na lista de encadeamento simples:*/

typedef struct lista2 Lista2;
typedef struct listano2 ListaNo2;

struct lista2 {
   ListaNo* prim;
   ListaNo2* ult;
};

struct listano2 {
   int info;
   ListaNo* prox;
   ListaNo2* prox;
};

/*como a lista esta vazia ele vai apontar para um elemento inexistente NULL
Funcao de criacao:
Retorna uma lista sem nenhum elemento*/
/* Funcao de inicializacao: retorna uma lista vazia */
Lista2* lst2_cria (void)
{
    Lista2* l = (Lista2*) malloc(sizeof(Lista2));
    l->prim = NULL; /*aponta pro primeiro elemento NULL*/
    l->ult = NULL;  /*aponta pro ÚLTIMO elemento NULL*/
    return l;
}

/*AGORA TEM QUE CRIAR UMA AREA DE MEMORIA PRO PRIMEIRO ELEMENtO*/
/* Funcao que insere um elemento no inicio da lista duplamente encadeada */
void lst2_insere_inicio (Lista2* l, int v)
{
    ListaNo2* novo = (ListaNo2*) malloc(sizeof(ListaNo2));
    novo->info = v;
    novo->prox = l->prim;
    novo->ant = NULL;  
    if (l->prim != NULL) /*testa se a lista esta vazia */
        l->prim->ant = novo;   /* o novo eh o anteriror do antigo primeiro*/
    else
        l->ult = novo;  /* novo tambem eh o ultimo*/ 
    l->prim = novo;     /* novo eh o primeiro*/
}

/* Funcao que insere um elemento no final da lista duplamente encadeada */
void lst2_insere_final (Lista2* l, int v)
{
    ListaNo2* novo = (ListaNo2*) malloc(sizeof(ListaNo2));
    novo->info = v;
    novo->ant = l->ult;
    novo->prox = NULL;  
    if (l->ult != NULL) /*testa se a lista esta vazia */
        l->ult->prox = novo; /* o novo eh o proximo do antigo primeiro*/
    else
        l->prim = novo;  /* novo tambem eh o primeiro*/ 
    l->ult = novo;       /* novo eh o ultimo*/
}


