#include <stdio.h>

#define N 1500000

int main (void) {
	int q;
	long double n;
	int primos[N];

	for (int i = 0; i < N; i++) {
		primos[i] = 1;
	}

	for (int i = 2; i * i < N; i++) {
		if (primos[i]) {
			for (int j = i * i; j <= N; j+=i) {
				primos[j] = 0;
			}
		}
	}

	scanf("%d", &q);

	for (int i = 0; i < q; i++) {
		scanf("%Lf", &n);
		if (primos[(int) n]) {
			printf("Sim\n");
		} else {
			printf("Nao\n");
		}
	}


	return 0;
}