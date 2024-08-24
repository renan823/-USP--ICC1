#include <stdio.h>

int main (void) {

	int A[10], B[10], na, nb, *a, *b, flag, empty;

	scanf("%d", &na);
	for (a = A; a < &A[na]; a++) {
		scanf("%d", a);
	}

	scanf("%d", &nb);
	for (b = B; b < &B[nb]; b++) {
		scanf("%d", b);
	}

	printf("intersecao: ");
	empty = 1;
	for (a = A; a < &A[na]; a++) {
		for (b = B; b < &B[nb]; b++) {
			if (*a == *b) {
				printf("%d ", *a);
				empty = 0;
				break;
			}
		}
	}
	if (empty) {
		printf("vazio");
	}
	printf("\n");

	printf("a - b: ");
	empty = 0;
	for (a = A; a < &A[na]; a++) {
		flag = 0;
		for (b = B; b < &B[nb]; b++) { 
			if (*a == *b) {
				flag = 1;
				empty++;
				break;
			} 
		}
		if (!flag) {
			printf("%d ", *a);
		}
	}
	if (empty == na) {
		printf("vazio");
	}
	printf("\n");

	return (0);
}