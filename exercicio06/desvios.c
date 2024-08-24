#include <stdio.h>

int main (void) {

	int n, i;
	i = 0;

	scanf("%d", &n);

	loop:
		i++;
		if (i < n) {
			goto loop;
		}

	printf("%d\n", i);

	return 0;
}