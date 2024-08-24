#include <stdio.h>
#define N 1000

void entrada (int A[N][N], int B[N][N], int *n, int *m) {
	scanf("%d %d", n, m);

	for (int i = 0; i < *n; i++) {
		for (int j = 0; j < *n; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	for (int i = 0; i < *m; i++) {
		for (int j = 0; j < *m; j++) {
			scanf("%d", &B[i][j]);
		}
	}
}

void multiplicar (int A[N][N], int B[N][N], int n, int m) {
	if (n != m) {
		printf("Matrizes de tamanho incompativel\n");
	} else {
		printf("Matriz multiplicada:\n");
		int C[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				C[i][j] = 0;
				for (int k = 0; k < n; k++) {
					C[i][j] = C[i][j] + A[i][k] * B[k][j];
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", C[i][j]);
			}
			printf("\n");
		}
	}	
}

void exibir (int A[N][N], int B[N][N], int n, int m) {
	int digA = 1;
	int digB = 1;

	printf("Matrizes:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", A[i][j]);
			if (i != j && A[i][j] != 0) {
				digA = 0;
			}
		}
		printf("\n");
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", B[i][j]);
			if (i != j && B[i][j] != 0) {
				digB = 0;
			}
		}
		printf("\n");
	}

	if (digA) {
		printf("A matriz 1 eh diagonal\n");
	} else {
		printf("A matriz 1 nao eh diagonal\n");
	}

	if (digB) {
		printf("A matriz 2 eh diagonal\n");
	} else {
		printf("A matriz 2 nao eh diagonal\n");
	}
}

int main (void) {

	int A[N][N], B[N][N], n, m;

	entrada (A, B, &n, &m);

	exibir (A, B, n, m);

	multiplicar (A, B, n, m);

	return (0);
}