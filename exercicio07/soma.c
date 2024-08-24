#include <stdio.h>

int main (void) {

	int n, m, bit;
	unsigned long int num1, num2;

	num1 = 0;
	num2 = 0;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &bit);
		//printf("bit: %d, num1: %ld\n", bit, num1);
		num1 <<= 1;
		num1 |= bit;
	}

	for (int j = 0; j < m; j++) {
		scanf("%d", &bit);
		//printf("bit: %d, num2: %ld\n", bit, num2);
		num2 <<= 1;
		num2 |= bit;
	}

	printf("%ld\n", num1+num2);

	return 0;
}