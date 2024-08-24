#include <stdio.h> 

int main (void) {

	int day, action;

	scanf("%d %d", &day, &action);

	if (day > 7) {
		printf("Dia nao registrado\n");
	}

	for (int i = day; i <= 7; i++) {
		switch (i) {
			case 1:
				printf("Segunda: Aula de computacao\n");
				break;
			case 2:
				printf("Terca: Treino de volei\n");
				break;
			case 3:
				printf("Quarta: Aula de calculo\n");
				break;
			case 4:
				printf("Quinta: Lista de GA\n");
				break;
			case 5:
				printf("Sexta: Festa da Sacim\n");
				break;
			case 6: 
				printf("Sabado: Jantar em familia\n");
				break;
			case 7:
				printf("Domingo: Depressao pos final de semana\n");
				break;
		}

		if (action) {
			break;
		}
	}


	return 0;
}