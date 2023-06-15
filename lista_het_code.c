#include <stdio.h>
#include "lista_het.h"

int main (void)
{
ListaHet* l;
l = lst_het_cria();
int fig, elem, i;
float b,h,r;
ListaHetNo* p;

printf("\n Digite o numero de elementos da lista: ");
scanf("%d", &elem);
for (i=1 ; i <= elem ; i++)
{
 printf("\n Digite a o tipo de elemento a ser inserido: ");
 printf("\n 1-Retangulo; 2-Triangulo e 3 Circulo: ");
 scanf("%d", &fig);
 if (fig < 1 || fig > 3) {
    printf("\n Tipo de elemento fora dos limites");
    return (1);
 }
 switch (fig){
    case 1: {
        printf("\n Digite a base de um retangulo: ");
        scanf("%f", &b);
        printf("\n Digite a altura de um retangulo: ");
        scanf("%f", &h);
        p = cria_ret (b,h);
        lst_het_insere (l,p);
    }
    break;
    case 2: {
        printf("\n Digite a base de um triangulo: ");
        scanf("%f", &b);
        printf("\n Digite a altura de um triangulo: ");
        scanf("%f", &h);
        p = cria_tri (b,h);
        lst_het_insere (l,p);
    }
    break;
    case 3: {
        printf("\n Digite o raio de um circulo: ");
        scanf("%f", &r);
        p = cria_circ (r);
        lst_het_insere (l,p);
    }
    break;
 }

}
lst_het_imprime(l);
printf("\n Maior area das figuras da lista: %f ", max_area(l));
lst_het_libera(l);

return 0;
}

