#include <stdio.h>
#include <math.h>

int main (void) {

	for (int i = 1000; i <= 9999; i++) {
		if (sqrt(i) == ((i/100) + (i%100))) {
			printf("%d\n", i);
		}
	}

	return 0;
}