#include <stdio.h>
#include <string.h>

/*
strings são arrays de caracteres, terminados em \0
c não possui o tipo string, mas permite usar strings constantes (por exemplo, frase pra printar)
variaveis string podem ser alocadas na stack e na heap

aspas duplas, para o compilador, são strings

existem funções çpara string já na stdio

gets(str) -> recebe uma string do teclado - NÃO USAR! - Não é seguro
puts(str) -> imprime o conteúdo de str no monitor
printf("%s", str);
scanf("%s", str); - sem o endereço

scanf tem sérios problemas com strings, por causa do buffer que armazena
os caracteres incluindo o <enter>, que será lido (e ignorado)
para resolver problemas, geralmente, usa-se uma mascara com espaço ' %c'
a mascara é um regexp

função fgets
lê a string até encontrar um \n, ou tamanho n -1 ou \0

char *fgets (char *str, int tamanho, FILE *fp)
os argumentos são: array de caracteres, qnt de caracteres e o buffer do teclado (stdin)
fgets retorna um ponteiro que aponta para o array passado por parametro

também é possivel usar com alocação dinamica
char *p;
p = malloc(10*sizeof(char));
fgets(p, 10, stdin);
printf("\n%s", p);
free(p);

strcpy(s1, s2) -> copia s2 em s1
strcat(s1, s2) -> concatena s2 ao final de s1
strlen(s1) -> retorna o tamanho de s1 (long unsigned int)
strcmp(s1, s2) -> retorna 0 se s1 e s2 são iguais, menor que 0
se s1 < s2 e maior que 0 se s1 > s2 (comparações lexicograficas);
lexicograficalmente significa ordem do "dicionario" - nesse caso, tabela ASCII
*/

int main (void) {
	//char str[100];

	if (strcmp("oi", "oi")) {
		printf("diferentes");
	} else { 
		printf("iguais\n");
	}
}