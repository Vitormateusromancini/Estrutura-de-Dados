#include <stdio.h>
#include <stdlib.h>


/*funções oferecidas pelo modulo str */

/*função comprimento */
int comprimento(char*str);

int main()
{
	char str1[51];
	printf("Digite uma sequenciade caracteres:");
	scanf("%50[^\n]",str1);
	printf("Comprimento da concatenação %d\n",comprimento(str1));
	

	return 0;
}
