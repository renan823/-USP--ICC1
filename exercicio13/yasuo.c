#include <stdio.h>

void input (char mapa[20][20], int *n, int *m) {
	scanf("%d %d", n, m);

	for (int i = 0; i < *n; i++) {
		for (int j = 0; j < *m; j++) {
			scanf(" %c", &mapa[i][j]);
		}
	}
}

int mapear (char mapa[20][20], char lugares[20][20], int n, int m) {
	int vagas = n * m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mapa[i][j] == 'c' ) {
				for (int k = 0; k < n; k++) {
					if (lugares[k][j] != 'x') {
						lugares[k][j] = 'x';
					
						vagas--;
					}
				}
				for (int k = 0; k < m; k++) {
					if (lugares[i][k] != 'x') {
						lugares[i][k] = 'x';
						
						vagas--;
					}
				}
			} else {
				if (lugares[i][j] != 'x') {
					if (mapa[i][j] == 'f') {
					lugares[i][j] = 'x';
				} else {
					lugares[i][j] = 'o';
				}
				}
			}
		}
	}
	
	return vagas;
}

void output (char mapa[20][20], int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%c ", mapa[i][j]);
		}
		printf("\n");
	}
}

int main (void) {

	char mapa[20][20];
	int n, m;

	input(mapa, &n, &m);

	char lugares[20][20];

	int vagas = mapear(mapa, lugares, n, m);

	if (vagas > 0) {
		output(lugares, n, m);
	} else {
		printf("Eh um dia triste para os mono Yasuo\n");
	}

	return (0);
}