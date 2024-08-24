#include <stdio.h>
#include <stdlib.h>

FILE *abrirArquivo (char *nome, char *modo) {
	FILE *arquivo;

	if ((arquivo = fopen(nome, modo)) == NULL) {
		exit(1);
	}

	return (arquivo);
}

int main (int argc, char *argv[]) {
	char c;

	FILE *arquivo = abrirArquivo(argv[1], "w");

	do {
		scanf("%c", &c);
		fprintf(arquivo, "%c", c);
	} while (c != '$');

	fclose(arquivo);

	return (0);
}