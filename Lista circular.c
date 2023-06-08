/*

O último elemento aponta para o primeiro
elemento da lista.


Para percorrer uma lista circular devo me
certificar que ela não está vazia.
*/
/* funcao imprime: imprime valores dos elementos de uma lista circular*/
void lst_imprime_circular (Lista* l)
{
    ListaNo* p = l->prim; /* variavel auxiliar para percorrer a lista */
    if (lst_vazia(l)) return;
    do
    {
        printf("info = %d\n", p->info);
        p = p->prox;
    } while(p != l->prim);

}


/* função busca: busca um elemento na lista */
Lista* lst_busca (Lista* l, int v)
{
   ListaNo* p;
   for (p=l; p!=NULL; p=p->prox)
     if (p->info == v) return 1;
   return 0;  /* não achou o elemento */
}

