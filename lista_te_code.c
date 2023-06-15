#include <stdio.h>
#include "lista_te.h"

int main (void)
{
Lista* l;
int i, elem;
float b,h;
l = lst_cria();
printf("\n Digite o numero de elementos da lista: ");
scanf("%d", &elem);
for (i=1 ; i <= elem ; i++)
{
 printf("\n Digite a base de um retangulo: ");
 scanf("%f", &b);
 printf("\n Digite a altura de um retangulo: ");
 scanf("%f", &h);
 lst_insere (l, b, h);
}
lst_imprime(l);

lst_libera(l);
return 0;
}

