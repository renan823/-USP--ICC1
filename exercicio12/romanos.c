#include <stdio.h>
#include <string.h>
#define N 10000

void inteiroParaRomano (int valor) {
	char romanos[13][3] = {
		{'M', '\0'}, 
		{'C', 'M', '\0'}, 
		{'D', '\0'}, 
		{'C', 'D', '\0'}, 
		{'C', '\0'}, 
		{'X', 'C', '\0'}, 
		{'L', '\0'}, 
		{'X', 'L', '\0'}, 
		{'X', '\0'}, 
		{'I', 'X', '\0'}, 
		{'V', '\0'}, 
		{'I', 'V', '\0'}, 
		{'I', '\0'}
	};
	int numeros[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

	for (int j = 0; j < 13; j++) {
		while (valor - numeros[j] >= 0) {
			printf("%s", romanos[j]);
			valor -= numeros[j];
		}
		if (valor == 0) {
			break;
		}
	}

	printf("\n");
}

int main (void) {
	int n, valores[N];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &valores[i]);
	}

	for (int i = 0; i < n; i++) {
		inteiroParaRomano(valores[i]);
	}

	return (0);
}
/**
	
*/