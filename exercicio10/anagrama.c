#include <stdio.h>
#define N 100000

int palindromo (char *a, int n) {
	char *i, *p;
	int count, flag;
	flag = 0;

	for (p = a; p < &a[n]; p++) {
		count = 0;
		for (i = a; i < &a[n]; i++) {
			if (*i == *p) {
				count++;
			}
		}
		if (count % 2 != 0) {
			if (!flag) {
				flag = 1;
			} else {
				return (0);
			}
		} 
	}

	return (1);
}

int main (void) {

	char A[N];
	int n;

	scanf("%d", &n);
	scanf("%s", A);

	if (palindromo(&A, n)) {
		printf("Sim\n");
	} else {
		printf("Nao\n");
	}

	return 0;
}
