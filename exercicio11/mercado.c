#include <stdio.h>

int main (void) {


	int n, qta, qtv, p;
	double pc, pv, total, max;
	total = 0;
	max = 0;
	p = 0;

	scanf("%d", &n);

	if (n > 0) {
		for (int i = 0; i < n; i++) {
			scanf("%lf %lf %d %d", &pc, &pv, &qta, &qtv);

			if (((pv * qtv) - (pc * qta)) > max) {
				max = (pv * qtv) - (pc * qta);
				p = i;
			}

			total += (pv * qtv) - (pc * qta);
		}

		if (total < 0) {
			printf("prejuizo: %.2lf\n", -total);
		} else {
			printf("lucro: %.2lf\n", total);
		}

		printf("produto: %d lucro relativo: %.2lf\n", p+1, max);
	} else {
		printf("Sem atividades registradas hoje\n");
	}

	return 0;
}