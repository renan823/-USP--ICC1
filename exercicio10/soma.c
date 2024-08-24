#include <stdio.h>

#define N 30

int pot (int x, int n) {
	if (n == 0) {
		return 1;
	}

	while (n-1) {
		x += x ;
		n--;
	}

	return x;
}

int main (void) {
	int m, n, *p, *a, sum, vm[N], vn[N], i;
	sum = 0;

	scanf("%d %d", &n, &m);

	i = n-1;
	a = vn;
	for (p = vn; p < a+n; p++) {
		scanf("%d", p);
		sum += (*p * pot(2, i));
		i--;
	}

	i = m-1;
	a = vm;
	for (p = vm; p < a+m; p++) {
		scanf("%d", p);
		sum += (*p * pot(2, i));
		i--;
	}

	printf("%d\n", sum);

	return 0;
}
