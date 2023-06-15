/* TAD: Lista */

/* Tipo Exportado */

typedef struct lista Lista;
typedef struct listano ListaNo;

/* função de inicialização: retorna uma lista vazia */
Lista* lst_cria (void);
/* inserção no início: retorna a lista atualizada */
void lst_insere (Lista* l, float b, float h);

/* função imprime: imprime valores dos elementos */
void lst_imprime (Lista* l);

void lst_libera (Lista* l);

