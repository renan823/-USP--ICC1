#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *alocar (int n, int t) {
	void *ptr;

	if ((ptr = (void *) malloc(n * t)) == NULL) {
		exit(1);
	}

	return (ptr);
}

FILE *abrirArquivo (char *nome, char *modo) {
	FILE *arquivo;

	if ((arquivo = fopen(nome, modo)) == NULL) {
		exit(1);
	}

	return (arquivo);
}


void saida (char *palavra, char *nome) {
	FILE *arquivo = abrirArquivo(nome, "r");

	char *string = alocar(1024, sizeof(char));
	int i = 0;

	while ((string[i] = fgetc(arquivo)) && string[i] != EOF) {
		i++;
	}

	string[i] = '\0';

	char *substring = strstr(string, palavra);

	int posInicialPalavra = substring - string;
	int posFinalPalavra = posInicialPalavra + strlen(palavra);

	for (int i = 0; i < posInicialPalavra; i++) {
		printf("%c", string[i]);
	}

	for (int i = posFinalPalavra; i < strlen(string); i++) {
		if (i == posFinalPalavra && string[i] == ' ') {
			continue;
		}

		printf("%c", string[i]);
	}

	printf("\n");
}

int main (void) {
	char *palavra, *nome;

	palavra = (char *) alocar(20, sizeof(char));
	nome = (char *) alocar(30, sizeof(char));

	scanf("%s %s", palavra, nome);

	saida(palavra, nome);

	free(palavra);
	free(nome);
}
/*
char c = fgetc(arquivo);

	char *caracteres = alocar(strlen(palavra), sizeof(char));
	int i = 0;
	int achou = 0;
	char ultimo = '\n';

	while (c != EOF) {
		if (i == strlen(palavra)) {
			i = 0;
		}

		if (strlen(caracteres) != strlen(palavra)) {
			caracteres[i] = c;
			i++;
		} else {
			if (achou == 0) {
				if (caracteres[0] == 32) {
					if (ultimo == 32) {
						printf("%c e %c", caracteres[0], ultimo);
					} else {
						//oi
					}
				} else {
					printf("%c", caracteres[0]);
				}
			} else {
				achou--;
			}

			ultimo = caracteres[0];

			for (int j = 1; j < strlen(palavra); j++) {
				caracteres[j-1] = caracteres[j];
			}

			caracteres[strlen(palavra)-1] = c;
			i++;
		}

		if (strcmp(palavra, caracteres) == 0) {
			achou = strlen(caracteres);
		} 

		c = fgetc(arquivo);

		if (c == EOF) {
			printf("%s", caracteres);
		}
	}
	printf("\n");


	fclose(arquivo);

*/