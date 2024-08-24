#include <stdio.h>
#include<string.h>
#define N 100000

int main (void) {
	char A[N], *i, *j;
	int n, size, flag;

	scanf("%d\n", &n);

	for (int k = 0; k < n; k++) {
		fgets(A, N, stdin);

		flag = 0;
		size = 0;

		i = A;
		while (*i != '\0' && *i != '\n') {
			size++;
			i++;
		}

		if (size % 2 == 0) {
			j = &A[size/2]-1;
			i = &A[size/2];
		} else {
			j = &A[(int) size/2]-1;
			i = &A[(int) size/2]+1;
		}

		while (j >= &A[0] && i < &A[size]) {
			if (*i != *j) {
				flag = 1;
				break;
			}

			j--;
			i++;
		}
		i = A;
		while (*i != '\0' && *i != '\n' && *i != '\r') {
			printf("%c", *i);
			i++;
		}

		if (flag) {
			printf(" nao eh um palindromo\n");
		} else {
			printf(" eh um palindromo\n");
		}
	}
	
	return 0;
}
