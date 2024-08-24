#include <stdio.h>

int main (void) {
	int a, b, c, d;

	scanf("%d %d %d %d", &a, &b, &c, &d);

	if (a == b && b == c && c ==d) {
		if (a != 0) {
			printf("quadrado!\n");
		} else {
			printf("nenhum!\n");
		}
	} else if (a == c && b == d){
		printf("retangulo!\n");
	} else {
		printf("nenhum!\n");
	}

	return 0;
}