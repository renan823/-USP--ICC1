#include <stdio.h>
#include <stdlib.h>

void *alocar (int items, int tamanho) {
	void *p;
	if ((p = (void *) malloc(items * tamanho)) == NULL) {
		exit(1);
	}

	return (p);
}

void desalocar (int *p) {
	free(p);
}

int entrada_tamanho () {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		if (i * i == n) {
			n = i;
			break;
		}
	}

	return (n);
}

void entrada_dados (int n, int *matriz) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &matriz[i * n + j]);
		}
	}
}

void saida (int n, int *matriz) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", matriz[i * n + j]);
		}
		printf("\n");
	}
}

int main (void) {

	int n, *matriz;

	n = entrada_tamanho();

	matriz = (int *) alocar(n * n, sizeof(int));

	entrada_dados(n, matriz);

	saida(n, matriz);

	desalocar(matriz);
	matriz = NULL;

	return (0);
}