#include <stdio.h>

int main (void) {

	int n, contador = 0;

	scanf("%d", &n);

	//considerando fatores primos
	for (int i = 5; n/i >= 1; i *=5) {
		contador += n/i;
	}

	printf("%d\n", contador);

	return 0;
}