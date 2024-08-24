#include <stdio.h>

int main (void) {
	unsigned long int x = 0;
	unsigned short int a, b, c;

	scanf("%hd %hd %hd", &a, &b, &c);

	x |= c;
	x <<= 16;

	x |= b;
	x <<= 16;

	x |= a;

	printf("%ld\n", x);

	return 0;
}