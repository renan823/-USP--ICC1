#include <stdio.h>

int main (void) {

	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		float a, b;
		int t;

		scanf("%f %f %d", &a, &b, &t);

		if (t == 0) {
			printf("A corrida ainda nao comecou\n");
		} else {
			if (a == b) {
				if (a == 0) {
					printf("Os dois pilotos nao querem competir\n");
				} else {
					if (t > 0) {
						printf("Os karts empataram, percorrendo cada %.2fkm\n", a);
					}
				}
			}

			if (a != b && a == 0) {
				printf("O piloto A desistiu inesperadamente\n");
			}

			if (a != b && b == 0) {
				printf("O piloto B desistiu inesperadamente\n");
			}

			if (a != 0 && b != 0 && t < 0) {
				printf("De alguma forma os pilotos voltaram no tempo\n");
			}
			
			if (a > b && b != 0 && t > 0) {
				printf("O kart A venceu e percorreu %.2fkm a mais que o kart B\n", (a-b)*t);
			}

			if (b > a && a != 0 && t > 0) {
				printf("O kart B venceu e percorreu %.2fkm a mais que o kart A\n", (b-a)*t);
			}
		}
	}

	return 0;
}