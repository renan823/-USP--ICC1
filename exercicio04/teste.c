#include <stdio.h>

int main (void) {

	short unsigned int a, b, c;

	scanf("%hd %hd %hd", &a, &b, &c);

	unsigned int r = ((c << 16) + (b << 8) + (a));

	printf("%d\n", r);

	return 0;
}