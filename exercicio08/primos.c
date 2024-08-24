#include <stdio.h>

int main (void) {

	int a, b, min, max, flag;

	min = 0;
	max = 0;

	scanf("%d %d", &a, &b);

	for (int i = a; i <= b; i++){
		flag = 0;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				flag = 1;
				break;
			}
		}

		if (!flag && i > 1) {
			if (!min) {
				min = i;
			}
			max = i;
		}
	}

	if (min) {
		printf("menor primo: %d\nmaior primo: %d\n", min, max);
	} else {
		printf("nenhum primo no intervalo\n");
	}

	return 0;
}