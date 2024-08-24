#include <stdio.h>

#define N 10000

int main (void) {

	int A[N], a, *p;

	scanf("%d", &a);

	for (int i = 0; i < a; i++) {
		scanf("%d", &A[i]);
	}

	for (p = &A[a]-1; p >= &A[0]; p--) {
		printf("%d ", *p);
	}

	return 0;
}