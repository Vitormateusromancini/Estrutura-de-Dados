/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include "vetd.h"
#include <stdlib.h>
#include <stdio.h>


struct vetordin
{
    int n;      /* numero de elementos armazenados */
    int nmax;   /* dimensao do vetor */
    float* v;   /* vetor dos elementos */
};


VetorDin* vd_cria (void)
{
    VetorDin* vd = (VetorDin*) malloc(sizeof(VetorDin));
    vd->n = 0;
    vd->nmax = 4;
    vd->v = (float*) malloc(vd->nmax*sizeof(float));
    return vd;
}

static void realoca (VetorDin* vd)
{
    vd->nmax *= 2;    /* dobra a dimenso do vetor */
    vd->v = (float*) realloc(vd->v , vd->nmax*sizeof(float));
}

void vd_insere (VetorDin* vd , float x)
{
    if (vd->n == vd->nmax)   /* verifica se a capacidade do vetor se esgotou */
        realoca(vd);
    vd->v[vd->n] = x;
    vd->n++;
}

int vd_tam (VetorDin* vd)
{
    return vd->n;
}

int vd_tam_max (VetorDin* vd)
{
    return vd->nmax;
}

float vd_acessa (VetorDin* vd , int i)
{
    if (i<0 || i>= vd->n)
    {
        printf("valor fora dos limites do vetor *******  FIM   ******\n");
        exit(5);
    }
    return vd->v[i];
}

void vd_libera (VetorDin* vd)
{
    free(vd->v);   /* libera o vetor de float */
    free(vd);       /* libera a estrutura */
}