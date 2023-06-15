/* TAD: Lista */

/* Tipo Exportado */

typedef struct listahet ListaHet;
typedef struct listahetno ListaHetNo;

/* função de inicialização: retorna uma lista vazia */
ListaHet* lst_het_cria (void);

void lst_het_libera (ListaHet* l);

/* inserção no início: retorna a lista atualizada */
void lst_het_insere (ListaHet* l, ListaHetNo* p);

/* Cria um no com um retangulo */
ListaHetNo* cria_ret (float b, float h);

/* Cria um no com um triangulo */
ListaHetNo* cria_tri (float b, float h);

/* Cria um no com um circulo */
ListaHetNo* cria_circ (float r);

/* função imprime: imprime valores dos elementos */
void lst_het_imprime (ListaHet* l);

/*funcao que calcula a maior area da figura geometrica */
float max_area (ListaHet* l);

