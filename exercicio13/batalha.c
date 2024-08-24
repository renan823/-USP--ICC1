#include <stdio.h>
#define M 100

int inputMapa (char mapa[M][M]) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %c", &mapa[i][j]);
		}
	}

	return n;
}

int inputAtaques (int ataques[M][2]) {
	int c, a;
	char l;
	scanf("%d", &a);

	for (int i = 0; i < a; i++) {
		scanf(" %c %d", &l, &c);
		ataques[i][0] = l;
		ataques[i][1] = c-1;
	}

	return a;
}

void batalhar (char mapa[M][M], int ataques[M][2], int n, int a) {
	for (int i = 0; i < a; i++) {
		//ascii A = 65, logo linha - 65 = posicao na matriz
		if (mapa[ataques[i][0]-65][ataques[i][1]] == 'N') {
			printf("acerto!\n");

			mapa[ataques[i][0]-65][ataques[i][1]] = 'X';
		} else {
			printf("erro!\n");
		}
	}
}

void output (char mapa[M][M], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c ", mapa[i][j]);
		}
		printf("\n");
	}
}

int main (void) {
	char mapa[M][M];
	int ataques[M][2];

	int n = inputMapa(mapa);
	int a = inputAtaques(ataques);

	batalhar(mapa, ataques, n, a);

	output(mapa, n);

	return (0);
}