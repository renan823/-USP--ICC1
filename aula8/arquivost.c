#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int i;
	float f;
	char str[5];
} Dados;

FILE *abrirArquivo (char *nome, char *modo) {
	FILE *arquivo;

	if ((arquivo = fopen(nome, modo)) == NULL) {
		printf("Erro: Não foi possível abrir o arquivo\n");
		exit(1);
	} 

	return (arquivo);
}

int main (void) {
	FILE *arquivo = abrirArquivo("structs.dat", "wb");

	Dados d;
	d.i = 2;
	d.f = 3.75263;
	d.str[0] = 'A';
	d.str[1] = '\0';
	strcat(d.str, "BCD");

	Dados rd;

	fwrite(&d, sizeof(Dados), 1, arquivo);

	free(arquivo);
	arquivo = NULL;

	arquivo = abrirArquivo("structs.dat", "rb");

	fread(&rd, sizeof(Dados), 1, arquivo);

	printf("%s\n", rd.str);

	fclose(arquivo);
	return (0);
}
