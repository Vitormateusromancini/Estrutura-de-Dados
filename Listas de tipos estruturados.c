/*A unica mudanca e que na definicao do
conteudo de cada no da lista devemos
definir a informacao a ser armazenada.
„Y Ate aqui os nos representavam um numero
inteiro.
„Y Veremos como incluir uma estrutura em
cada no da lista e algumas funcoes que
demonstram como tratar esse tipo de
informação.*/

typedef struct retangulo{
    float b;
    float h;
};

/*Para inserir no início de uma lista simplesmente
encadeada, temos que alocar espaço para a
estrutura Retangulo e após para o próprio nó
da lista.*/
/* insercao no início: informando a base (b) e altura (h) */
void lst_insere (Lista* l, float b, float h)
{
    Retangulo* r = (Retangulo*) malloc(sizeof(Retangulo));
    ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo));  /*nó da lista - uma  lista de encadeamneto simples*/
    r->b = b;   /*base recebe de parametro da funcao */
    r->h = h;   /*altura ecebe de parametro da funcao */
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
