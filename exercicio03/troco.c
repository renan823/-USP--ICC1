#include <stdio.h>

int main (void) {

	int valor;

	scanf("%d", &valor);

	int notas[8] = {200, 100, 50, 20, 10, 5, 2, 1};

	for (int i = 0; i < 8; i++) {
		int contador = 0;

		while (valor - notas[i] >= 0) {
			valor-=notas[i];
			contador++;
		}

		if (notas[i] != 1) {
			printf("%d nota(s) de R$ %d\n", contador, notas[i]);
		} else {
			printf("%d moeda(s) de R$ %d\n", contador, notas[i]);
		}
	}


	return 0;
}