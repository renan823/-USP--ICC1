#include <stdio.h>
#include <stdlib.h>

void *alocar (int items, int tamanho) {
	void *ponteiro;

	if ((ponteiro = (void *) malloc(items * tamanho)) == NULL) {
		printf("Sem memória para alocar...\n");
		exit(1);
	}

	return(ponteiro);
}

int adicionar (int *vetor, int item, int n) {
	if ((vetor = (int *) realloc(vetor, sizeof(int) * (n+1))) == NULL) {
		printf("Sem memória para alocar...\n");
		exit(1);
	}

	vetor[n] = item;

	return(n+1);
}

void desalocar (int *vetor) {
	free(vetor);
}

void entrada (int *numeros, int n) {
	for (int i = 0; i < n; i++) {
		scanf("%d", &numeros[i]);
	}
}

void saida (int *numeros, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", numeros[i]);
	}
	printf("\n");
}

int main (void) {
	int *numeros, n;

	scanf("%d", &n);
	numeros = (int *) alocar(n, sizeof(int));

	entrada(numeros, n);

	printf("Vetor inicial: ");
	saida(numeros, n);

	n = adicionar(numeros, 7, n);
	n = adicionar(numeros, 10, n);

	printf("Vetor após adicionar os valores: ");
	saida(numeros, n);

	desalocar(numeros);
	numeros = NULL;

	return(0);
}