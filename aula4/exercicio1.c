#include <stdio.h>
#define M 3
#define N 4

int input (double matrix[M][N]) {
	double *p;
	int n;

	scanf("%d", &n);

	for (p = matrix; p <= &matrix[M-1][N-1]; p++) {
		scanf("%lf", p);
	}

	return n;
}

double sum (double matrix[M][N], int n) {
	double *p, result;
	result = 0;

	for (p = matrix; p <= &matrix[M-1][N-1]; p++) {
		if (*p > n) {
			result += *p;
		}
	}

	return result;
}

void output (double result, int n) {
	printf("A soma dos numeros maiores que %d eh: %.2lf\n", n, result);
}

int main (void) {

	double matrix[M][N];

	int n = input(matrix);

	output(sum(matrix, n), n);

	return (0);
}