#include <stdio.h>
#define N 100000

int input (int *numeros) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n-1; i++) {
		scanf("%d", &numeros[i]);
	}

	return n;
}

int find (int *numeros, int n) {
	int soma = (n * (n + 1))/2;
	int valor = 0;

	for (int i = 0; i < n-1; i++) {
		valor += numeros[i];
	}

	return (soma - valor);
}

void output (int n) {
	printf("Numero desaparecido: %d\n", n);
}

int main (void) {
	int numeros[N];
	
	int n = input(&numeros);

	output(find(&numeros, n));
	
	return (0);
}