#include <stdio.h>
#define N 10000

void sort (int *p, int n) {
	//bubble sort
	int swaps;
	int temp;

	do {
		swaps = 0;
		for (int i = 0; i < n-1; i++) {
			if (p[i] > p[i+1]) {
				temp = p[i];
				p[i] = p[i+1];
				p[i+1] = temp;

				swaps++;
			}
		}
	} while (swaps);

	printf("vetor ordenado:");
	for (int i = 0; i < n; i++) {
		printf("%d ", p[i]);
	}
	printf("\n");
}

void upper (int *p, int n) {
	printf("Vetor maiusculo:");
	for (int i = 0; i < n; i++) {
		printf("%c ", p[i] - 32);
	}
	printf("\n");

}

void fibonacci (int *p, int n) {
	int seq[50], s = 0;

	while (s < 50) {
		if (s == 0 || s == 1) {
			seq[s] = 1;
		} else {
			seq[s] = seq[s-1] + seq[s-2];
		}
		s++;
	}

	printf("Numeros de Fibonacci:");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 50; j++) {
			if (p[i] == seq[j]) {
				printf("%d ", p[i]);
				break;
			}
		}
	}
	printf("\n");
}

int main (void) {

	int A[N], n = 0, i = 0, count = 0;
	char acao;

	do {
		scanf("%d", &n);

		if (n != 1) {
			A[i] = n;
			count++;
		} 

		i++;
	} while (n != 1);

	scanf(" %c", &acao);

	switch (acao) {
		case 'a': 
			sort(&A, count);
			break;
		case 'b':
			fibonacci(&A, count);
			break;
		case 'c':
			upper(&A, count);
			break;
		default:
			printf("Comando inexistente\n");
	}

	return 0;
}