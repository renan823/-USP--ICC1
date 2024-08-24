#include <stdio.h>

int main (void) {

	unsigned long long int n, f;

	scanf("%llu", &n);

	f = 1;

	while (n) {
		f *=n;
		n--;
	}

	printf("%llu\n", f);

	return 0;
}