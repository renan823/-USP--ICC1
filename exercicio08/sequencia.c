#include <stdio.h>

int main (void) {

	int n;
	float s = 0;

	scanf("%d", &n);

	while (n) {
		if (n % 2 == 0) {
			s -= (1.0/n);
		} else {
			s += (1.0/n);
		}
		n--;
	}

	printf("%.4f\n", s);

	return 0;
}