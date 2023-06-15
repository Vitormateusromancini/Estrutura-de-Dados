/*A estrutura de Fila é idêntica a que usamos no
nosso dia a dia: o primeiro que entra em uma
fila é o primeiro a ser atendido.
– Um elemento deve ser sempre introduzido no
final da fila.
– O único elemento que pode ser retirado da
fila é o do início.
– FIFO (First In , First Out).

Considere uma fila que armazena valores
reais.
O TAD-Fila será composto de 5 operações:
– Criar uma fila vazia.
– Inserir um elemento no final da fila
– Remover um elemento do início da fila
– Verificar se a fila está vazia
– Liberar a estrutura da fila

-sistemas operacionais usam filas

O header desse TAD pode ter a seguinte
configuração.


*****inserir o código*******

Numa implementação usando vetores, só
pode ser feita com vetores estáticos se eu
souber seu número máximo de elementos.
Caso contrário devo fazer uso de vetores
dinâmicos:
– Necessito saber qual elemento está no início
da fila.
– Onde foi inserido o último elemento da fila, ou
seja, o final da fila
– Como fazer com que a fila “ande”
Se a estrutura que eu usar para representar a
fila for a seguinte:

*****inserir o código********/

int ini; /*indice de inicio da fila ---n precisa ser zero*/
int dim;
float* vet;

/*Podemos ver que em um determinado momento a
parte ocupada pela fila pode chegar a última
posição.
– Os elementos antes de ini não fazem mais parte da fila
e suas posições podem ser reaproveitadas.
– Para isso normalmente fazemos uso do incremento
circular nas posições do vetor, isso é feito pela seguinte
fórmula:
● i = (i == (dim – 1)) ? 0 : i + 1; ou i = (i + 1) % dim;
onde dim é a dimensão corrente do vetor
● fim = (ini + n) % dim; onde ini é o próximo
elemento a ser retirado da fila e n é o número de
elementos armazenados na fila

Desse modo, em algum momento posso ter de 4
elementos na fila (20.0, 22.8, 21.2 e 24.3)
distribuídos no vetor, por exemplo, dois no início e
dois no final do vetor, vejamos:Desse modo, em algum momento posso ter de 4
elementos na fila (20.0, 22.8, 21.2 e 24.3)
distribuídos no vetor, por exemplo, dois no início e
dois no final do vetor, vejamos:

Função para criar a fila (escolhe a dimensão
inicial e cria uma fila vazia).
*/

Fila* fila_cria (void){
  Fila*f = (Fila*) malloc(sizeof(Fila));
  f->dim = 4;
  return f;
}

/*
Função para inserir um elemento no fim da fila

***********inserir o codigo**********/

void fila_insere(Fila* f, float v){
  int fim;
  if (f->n==f->dim)
  {
    f->dim *= 2;
    f->vet = (float*) realloc(f->vet,f->dim*sizeof(float));
    
    
 /*
 Funções para retirar um elemento da fila,
verificar se a fila está vazia e liberar a fila.



***********inserir o codigo*********



    
    
  
  
  
  
