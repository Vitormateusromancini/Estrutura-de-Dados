#include <stdio.h>
#include <stdlib.h>


/*fun��es oferecidas pelo modulo str */

/*fun��o comprimento */
int comprimento(char*str);

int main()
{
	char str1[51];
	printf("Digite uma sequenciade caracteres:");
	scanf("%50[^\n]",str1);
	printf("Comprimento da concatena��o %d\n",comprimento(str1));
	

	return 0;
}
