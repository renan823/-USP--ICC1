#include <stdio.h>

void ordenar (double p[25], int n) {
	//bubble sort
	int swaps;
	double temp;

	do {
		swaps = 0;
		for (int i = 0; i < n-1; i++) {
			if (p[i] < p[i+1]) {
				temp = p[i];
				p[i] = p[i+1];
				p[i+1] = temp;

				swaps++;
			}
		}
	} while (swaps);
}

void entrada (double medias[100], double ativ[25], int *n, int *m) {
	scanf("%d %d", n, m);
	double s;

	//zerar o vetor ativ
	for (int i = 0; i < *m; i++) {
		ativ[i] = 0;
	}

	for (int i = 0; i < *n; i++) {
		medias[i] = 0;
		for (int j = 0; j < *m; j++) {
			scanf("%lf", &s);
			medias[i] += s;
			ativ[j] += s;
		}
		medias[i] /= *m;
	}

	//dividir cada valor por n
	for (int i = 0; i < *m; i++) {
		ativ[i] /= *n;
	}
}

void saida (double medias[100], double ativ[25], int n, int m) {
	for (int i = 0; i < n; i++) {
		printf("Media do aluno %d = %.2lf : ", i+1, medias[i]);

		if (medias[i] >= 5.0) {
			printf("Aprovado\n");
		} else {
			printf("Reprovado\n");
		}
	}

	printf("\n");

	for (int i = 0; i < m; i++) {
		printf("%.2lf ", ativ[i]);
	}
	printf("\n");
}

int main (void) {

	double medias[100], ativ[25];
	int n, m;

	entrada(medias, ativ, &n, &m);

	ordenar (ativ, m);

	saida (medias, ativ, n, m);

	return (0);
}