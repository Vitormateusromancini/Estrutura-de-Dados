#include <stdio.h>
#include "lista_rec.h"

int main (void)
{
Lista* l;
Lista* l2;
int igual;
l = lst_cria();
lst_insere(l, 23);
lst_insere(l, 45);
lst_insere(l, 56);
lst_insere(l, 78);
l2 = lst_cria();
lst_insere(l2, 23);
lst_insere(l2, 45);
lst_insere(l2, 56);
lst_insere(l2, 78);
printf("Lista 1\n");
lst_imprime_rec(l);
printf("Lista 2\n");
lst_imprime_rec(l2);
printf("Verifica se a lista 1 eh igual a lista2 (copia de 1)\n");
igual = lst_igual(l,l2);
if (igual == 0) printf("**************************Lista Diferentes\n");
else printf("************************Lista Identicas\n");
lst_retira_rec(l, 78);
printf("\n Retirando o elemento 78\n");
printf("Lista 1\n");
lst_imprime_rec(l);
printf("Verifica se a lista 1 eh igual a lista2 \n");
igual = lst_igual(l,l2);
if (igual == 0) printf("**************************Lista Diferentes\n");
else printf("************************Lista Identicas\n");
lst_retira_rec(l, 45);
printf("\n Retirando o elemento 45\n");
printf("Lista 1\n");
lst_imprime_rec(l);
lst_retira_rec(l, 23);
printf("\n Retirando o elemento 23\n");
printf("Lista 1\n");
lst_imprime_rec(l);
lst_insere_ordenado(l,78);
printf("\n Inserindo o elemento 78 de forma ordenada\n");
printf("Lista 1\n");
lst_imprime_rec(l);
lst_insere_ordenado(l,23);
printf("\n Inserindo o elemento 23 de forma ordenada\n");
printf("Lista 1\n");
lst_imprime_rec(l);
lst_insere_ordenado(l,45);
printf("\n Inserindo o elemento 45 de forma ordenada\n");
printf("Lista 1\n");
lst_imprime_rec(l);
printf("\n Imprimindo a Lista em Ordem Inversa de Forma Recursiva\n");
printf("Lista 1\n");
lst_imprime_rec_rev(l);
printf("Verifica se a lista 1 eh igual a lista2 de forma recursiva\n");
igual = lst_igual_rec(l,l2);
if (igual == 0) printf("**************************Lista Diferentes\n");
else printf("************************Lista Identicas\n");
lst_libera_rec(l);
return 0;
}

