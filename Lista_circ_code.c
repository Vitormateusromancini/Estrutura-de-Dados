#include <stdio.h>
#include "lista_circ.h"


int main (void)
{
int conteudo, elem, i;
Lista* l;
l = lst_cria();
printf("\n Digite o numero de elementos da lista: ");
scanf("%d", &elem);
for (i=1 ; i <= elem ; i++)
{
 printf("\n Digite um elemento da lista: ");
 scanf("%d", &conteudo);
 lst_insere (l, conteudo);
}
printf("\n Imprimindo a Lista de Encadeamento Simples \n");
lst_imprime(l);
printf("\n Convertendo a Lista de Encadeamento Simples em Lista Circular");
lst_converte(l);
printf("\n Imprimindo a Lista Circular \n");
lst_imprime_circular(l);
lst_libera_circ(l);

return 0;
}

