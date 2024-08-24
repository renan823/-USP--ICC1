#include <stdio.h>

int main (void) {

	int n, *pn, **ppn;

	scanf("%d", &n);

	pn = &n;
	ppn = &pn;

	printf("Valor inicial da variavel: %d\n", n);

	printf("Valor do ponteiro antes do incremento: %d\n", *pn);

	*pn += 10;

	printf("Valor do ponteiro depois do incremento: %d\n", *pn);

	printf("Valor do ponteiro para ponteiro antes do incremento: %d\n", **ppn);

	**ppn += 10;

	printf("Valor do ponteiro para ponteiro depois da mudanca: %d\n", **ppn);

	printf("Valor final da variavel: %d\n", n);

	return 0;
}