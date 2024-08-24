#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *abrirArquivo (char *nome, char *modo) {
	FILE *arquivo;

	if ((arquivo = fopen(nome, modo)) == NULL) {
		printf("Erro: Não foi possível abrir o arquivo\n");
		exit(1);
	} 

	return (arquivo);
}

int main (int argc, char *argv[]) {

	FILE *arquivo;
	int n;

	if (strcmp(argv[2], "ler") == 0) {
		arquivo = abrirArquivo(argv[1], "rb");

		while (!feof(arquivo)) {
			if (!(fread(&n, sizeof(int), 1, arquivo))) {
				break;
			}

			printf("%d\n", n);
		}

	} else if (strcmp(argv[2], "gravar") == 0) {
		arquivo = abrirArquivo(argv[1], "wr");
		do {
			scanf("%d", &n);
			fwrite(&n, sizeof(int), 1, arquivo);
		} while (n != 0);
	}

	fclose(arquivo);

	return (0);
}