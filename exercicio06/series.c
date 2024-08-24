#include <stdio.h>

int main (void) {

	int x, cont;
	long double s, exp, fat;

	scanf("%d", &x);

	s = x; // primeiro termo

	for (int i = 0; i < 19; i++) {

		exp = 1;
		cont = (2 * i);

		while (cont) {
			exp *= x;
			cont--;
		}

		fat = 1;
		cont = ((2 * i) + 1);

		while (cont) {
			fat *= cont;
			cont--;
		}

		if (i % 2 == 0) {
			fat *= (-1); //vai afetar o sinal geral
		} 

		printf("%d %Lf\n", (2 * i) + 1, fat);

		s += (exp/fat);
	}

	printf("%Lf\n", s);
	
	return 0;
}