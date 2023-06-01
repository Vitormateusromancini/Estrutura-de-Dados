/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "vetd.h"

VetorDin* le_valores (char* arquivo)
{
    float x;
    int cont = 0;
    VetorDin* vd;
    FILE* f = fopen(arquivo,"rt");
    if (f == NULL) return NULL;
    vd = vd_cria();
    while(fscanf(f,"%f",&x) == 1)
    {
        printf("Elemento %d: %f\n",cont,x);
        cont++;
        vd_insere(vd,x);
    }
    fclose(f);
    return(vd);
}

int main()
{
    VetorDin* vetor;
    char nome_arq[20] = "reais.txt";
    vetor = le_valores (nome_arq);
    printf("Num elementos armazenados: %d\n",vd_tam(vetor));
    printf("Dimensao do vetor        : %d\n",vd_tam_max(vetor));
    printf("Elemento Indice 5      : %f\n",vd_acessa (vetor,5));
    vd_libera(vetor);
    return 0;
}