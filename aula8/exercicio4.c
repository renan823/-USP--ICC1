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
	FILE *arquivo, *copia;

	arquivo = abrirArquivo(argv[1], "rb");
	copia = abrirArquivo(argv[2], "wb");

	//ler os bytes (mesmo tamanho do char)

	char c;
	c = fgetc(arquivo);
	while (!feof(arquivo)) {
		putc(c, copia);
		c = fgetc(arquivo);
	}

}