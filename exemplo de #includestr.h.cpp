#include <stdio.h>
#include <stdlib.h>
#include "str.h"
/*com esse include ele vai para o arquivo str.h*/

/*str.h*/

/*prototipo da função usada no programa tad_exemplo*/

int comprimento(char*str);

/*str.c*/


int comprimento(char*s)
{
	int n = 0;
	int i;
	for(i=0;s[i]!='\0';i++) n++;
	return n;
}

/*tad_exemplo.c*/

int main()
{
	char str1[51];
	printf("Digite uma sequenciade caracteres:");
	scanf("%50[^\n]",str1);
	printf("Comprimento da strring digitada = %d\n",comprimento(str1));
	

	return 0;
}





