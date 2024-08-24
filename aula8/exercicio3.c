#include <stdio.h>
#include <stdlib.h>

FILE *abrirArquivo (char *nome, char *modo) {
	FILE *arquivo;

	if ((arquivo = fopen(nome, modo)) == NULL) {
		printf("Erro: arquivo não encontrado\n");
		exit(1);
	}

	return (arquivo);
}

int main (int argc, char *argv[]) {
	char entrada, c;
	int linhas = 0;

	FILE *arquivo = abrirArquivo(argv[1], "r");

	do {
		while (fscanf(arquivo, "%c", &c) != EOF) {
			printf("%c", c);

			if (c == '\n') {
				linhas++;
			}

			if (linhas == 20) {
				linhas = 0;
				break;
			}
		}

		scanf("%c", &entrada);
	} while (entrada == '\n' && fscanf(arquivo, "%c", &c) != EOF);

	fclose(arquivo);
	return (0);
}