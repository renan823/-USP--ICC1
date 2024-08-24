#include <stdio.h>

int main (void) {

	int n;

	scanf("%d", &n);

	int fatorial = 1;

	for (int i = 1; i <= n; i++) {
		fatorial *= i;
	}

	printf("%d\n", fatorial);

	return 0;
}