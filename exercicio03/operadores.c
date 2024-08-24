#include <stdio.h>

int main (void) {

	int a, b;

	scanf("%d %d", &a, &b);

	if ((a > b) && ((a-b) % 3 == 0)) {
		printf("%d\n", a+b);
	} else if ((b > a) && (a+b > 400)) {
		printf("%d\n", a+b);
	} else if ((a == b) && (a % 2 != 0)) {
		printf("%d\n", a+b);
	} else {
		printf("Nenhuma condicao foi satisfeita\n");
	}

	return 0;
}

/*
1) Se n1 ´e maior que n2 E n1 menos n2 ´e divis´ıvel por 3.
2) Se n2 ´e maior que n1 E n1 + n2 ´e maior que 400.
3) Se n1 ´e igual `a n2 E n1 ´e ´ımpar.
*/