/*Uma vez que a informação pode ser representada
por um ponteiro, posso armazenar diferentes
informações utilizando a mesma estrutura de nós.
– Por exemplo, imagine manipulando dados de diferentes
objetos geométricos para os quais desejamos saber a
área. Por questões de simplicidade, trataremos apenas
com Retângulos, Triângulos e Círculos, cujas áreas
podem ser calculadas como:*/

/*Definimos um tipo para cada objeto e um
identificador para o tipo de estrutura que será
utilizada.*/

#include <stdio.h>
#include <stdlib.h>
#include "lista_het.h"

#define PI 3.14159  /*area do circulo*/

typedef enum tipo Tipo;
enum tipo {
    RET,
    TRI,
    CIRC
};

typedef struct retangulo{
    float b;
    float h;
    } Retangulo;

typedef struct triangulo{
    float b;
    float h;
    } Triangulo;

typedef struct circulo{
    float r;
    } Circulo;
/*O nó da lista deve ser composto por 3 campos.
– Um identificador de qual objeto está armazenado no
nó.
– Um ponteiro para a estrutura que contém a informação.
– Um ponteiro para o próximo elemento da lista.*/
typedef struct listahet Listahet;
typedef struct listahetno ListahetNo;
struct listahet {
   ListaHetNo* prim;
};

struct listahetno {
    Tipo tipo;
    void* info;
    ListaHetNo* prox;
};
/*A função para criação do nó deve ter três
variações.
– Observe como fica para um triângulo, as outras
seguem a mesma lógica de inicializar o ponteiro para o
tipo em questão.
/* Cria um no com um triangulo */
ListaHetNo* cria_tri (float b, float h)
{
    /* aloca triangulo */
    Triangulo* t = (Triangulo*) malloc(sizeof(Triangulo));
    t->b = b;
    t->h = h;
    /* aloca no */
    ListaHetNo* p = (ListaHetNo*) malloc(sizeof(ListaHetNo));
    p->tipo = TRI;
    p->info = t; /*apontador pra o triangulo*/
    p->prox = NULL;
    return p;
}
/*A função auxiliar para o cálculo das áreas. --- ele vai chamar a lista que esta a função ex: triangulo, circulo....
– Lembre de definir o valor de PI: #define PI 3.14159
/* funcao auxiliar para o calculo da area correspondente ao no */
static float area (ListaHetNo* p)
{
    switch (p->tipo){
    case RET: {
        Retangulo* r = (Retangulo*) p->info; /* o apontador  r  receber a informação info especificamente do retangulo*/
        return r->b*r->h; /*retorna a area do retangulo*/
    }
    break;
    case TRI: {
        Triangulo* t = (Triangulo*) p->info;
        return (t->b*t->h)/2; /*retorna a area do triangulo*/
    }
    break;
    case CIRC: {
        Circulo* c = (Circulo*) p->info;
        return PI*c->r*c->r; /*retorna a area da circunferencia*/
    }
    break;
 }
}
/*A função para o cálculo da maior área entre os
objetos armazenados na lista.
/*funcao que calcula a maior area da figura geometrica */
float max_area (ListaHet* l)
{
    float amax = 0.0;
    float a;
    ListaHetNo* p;
    for (p = l->prim; p!= NULL; p = p->prox)
    {
        a = area(p);
        if (a > amax) amax = a;
    }
    return amax;
}
