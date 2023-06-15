
/* TAD: Lista */

/* Tipo Exportado */

/* TAD: Lista */

/* Tipo Exportado */

typedef struct lista Lista;
typedef struct listano ListaNo;

/* função de inicialização: retorna uma lista vazia */
Lista* lst_cria (void);
/* inserção no início: retorna a lista atualizada */
void lst_insere (Lista* l, int v);

/* função imprime: imprime valores dos elementos */
void lst_imprime (Lista* l);

/* função vazia: retorna 1 se vazia ou 0 se não vazia */
int lst_vazia (Lista* l);

/* função busca: busca um elemento na lista */
int lst_pertence (Lista* l, int v);

/* função retira: retira elemento da lista */
void lst_retira (Lista* l,int v);

void lst_libera (Lista* l);

/* insere elementos mantendo a lista em ordem crescente */
void lst_insere_ordenado (Lista* l, int v);


/* Função que converte uma lista de encadeamento simples em uma lista circular */
void lst_converte(Lista* l);

/* Funcao que libera uma lista circular */
void lst_libera_circ (Lista* l);

/* função imprime: imprime valores dos elementos de uma lista circular*/
void lst_imprime_circular (Lista* l);
