/* TAD: Lista */

/* Tipo Exportado */

typedef struct lista Lista;
typedef struct listano ListaNo;

/* função de inicialização: retorna uma lista vazia */
Lista* lst_cria (void);
/* inserção no início: retorna a lista atualizada */
void lst_insere (Lista* l, int v);

/* funcao imprime: imprime valores dos elementos de forma recursiva */
void lst_imprime_rec (Lista* l);

/* funcao imprime: imprime valores dos elementos de forma recursiva na ordem inversa*/
void lst_imprime_rec_rev (Lista* l);

/* função vazia: retorna 1 se vazia ou 0 se não vazia */
int lst_vazia (Lista* l);

/* função busca: busca um elemento na lista */
int lst_pertence (Lista* l, int v);

/* função retira: retira elemento da lista de forma recursiva */
void lst_retira_rec (Lista* l,int v);

/* Funcao que libera o espaco alocado a lista de forma recursiva */
void lst_libera_rec (Lista* l);

/* insere elementos mantendo a lista em ordem crescente */
void lst_insere_ordenado (Lista* l, int v);

/* Verifica se uma lista e igual a outra, retorna 1 se sao iguais e 0 se sao diferentes*/
int lst_igual (Lista* l1, Lista* l2);

/* Verifica se uma lista e igual a outra de forma recursiva, retorna 1 se sao iguais e 0 se sao diferentes*/
int lst_igual_rec (Lista* l1, Lista* l2);
