#include <stdio.h>

int main (void) {

	int a, b, *pa, *pb, t;

	scanf("%d %d", &a, &b);

	pa = &a;
	pb = &b;

	t = *pa;

	*pa = b;
	*pb = t;

	printf("%d %d\n", a, b);

	return 0;
}