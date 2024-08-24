#include <stdio.h>

//D(n) = n D(n-1) = (n-1)
void decrescente (int n) {
	if (n == 0) {
		printf("%d ", n);
		return;
	}

	printf("%d ", n);

	decrescente(n-1);

	return;
}

//C(1) = 0 C(n) = (n-1)
void crescente (int n) {
	if (n == 0) {
		printf("%d ", n);
		return;
	}

	crescente(n-1);

	printf("%d ", n);

	return;
}

int main (void) {

	crescente(5);
	printf("\n");

	decrescente(5);
	printf("\n");

	return (0);
}