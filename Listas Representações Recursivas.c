/* Uma lista pode ser definida de forma
recursiva, como:
– Vazia (isto é, sem nenhum nó), ou;
– Um nó seguido de um subencadeamento


Exemplo, imprimir elementos da lista:
– Se o encadeamento é vazio não tenho nada a imprimir;
– Senão, imprimo a informação e chamo a função para
imprimir o subencadeamento

Funcao auxiliar recursiva para imprimir o encadeamento */
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

/* Se quisermos imprimir a lista na ordem
inversa?
– É simples se usarmos o conceito da recursão.

Funcao auxiliar recursiva para imprimir o encadeamento na ordem inversa*/
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

/*Para retirar um elemento da lista?
– Fica mais simples também, pois só precisamos retirar o
primeiro elemento do subencadeamento, tenho de ter o
cuidado de retornar o ponteiro para um, eventual, novo
primeiro nó.

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

/*Para destruir (liberar) a lista?
– Se o encadeamento não for vazio, liberamos primeiro o
subencadeamento e depois liberamos a lista.
*/
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

