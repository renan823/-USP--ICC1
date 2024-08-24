#include <stdio.h>

int main (void) {
	double p1, p2, l1, l2, l3, l4;

	scanf("%lf %lf %lf %lf %lf %lf", &p1, &p2, &l1, &l2, &l3, &l4);

	double ml = (l1+l2+l3+l4) / 4;

	if (((p1+p2+ml)/3) < 3 || ml == 0) {
		printf("Reprovado\n");
	} else if (((p1+p2+ml)/3) < 5) {
		printf("Recuperacao\n");
	} else {
		printf("Aprovado\n");
	}

	return 0;
}