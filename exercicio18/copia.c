#include <stdio.h>
#include <stdlib.h>

void *alocar (int items, int tamanho) {
	void* ponteiro;

	if ((ponteiro = (void *) malloc(items * tamanho)) == NULL) {
		printf("Erro: sem memória para alocar\n");
		exit(1);
	}

	return (ponteiro);
}

FILE *abrirArquivo (char *nome, char *modo) {
	FILE *arquivo;

	if ((arquivo = fopen(nome, modo)) == NULL) {
		exit(1);
	}

	return (arquivo);
}

int main (void) {
	char c, *nome;

	nome = (char *) alocar(100, sizeof(char));

	scanf("%s", nome);

	FILE *arquivo = abrirArquivo(nome, "r");

	c = fgetc(arquivo);
	while (c != EOF) {
		printf("%c", c);
		c = fgetc(arquivo);
	}

	printf("\n");

	free(nome);
	
	fclose(arquivo);

	return (0);
}