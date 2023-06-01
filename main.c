/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
typedef struct vetordin VetorDin;

VetorDin* vd_cria (void);
void vd_insere (VetorDin* vd , float x);
int vd_tam (VetorDin* vd);
int vd_tam_max (VetorDin* vd);
float vd_acessa (VetorDin* vd , int i);
void vd_libera (VetorDin* vd);