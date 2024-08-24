#include <stdio.h>
#include <stdlib.h>

/*
A função aloca é responsavel por alocar dinamicamente um vetor
Nesse caso, é um grande vetor acessado por mapping functions
*/
double *aloca (int linhas, int colunas) {
	double *p;

	if ((p = (double *) malloc(linhas * colunas * sizeof(double))) == NULL) {
		printf("erro\n");
		exit(1);
	}

	return (p);
}

void entrada_dados (double *matriz, int linhas, int colunas) {
	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			scanf("%lf" matriz[i * colunas + j]);
		}
	}
}

int main (void) {



	return (0);
}