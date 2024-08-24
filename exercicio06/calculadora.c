#include <stdio.h>

int main (void) {

	char acao = 'c';
	double x, y;

	do {
		printf("------------MENU------------\n");
		printf("+ : adição\n");
		printf("- : subtração\n");
		printf("* : multiplicação\n");
		printf("/ : divisão\n");
		printf("c : sair do programa\n");
		printf("----------------------------\n");

		printf("Digite a operação: \n");
		scanf(" %c", &acao);

		if ((acao == '+') || (acao == '-') || (acao == '*') || (acao == '/')) {
			printf("Digite os 2 operandos: \n");
			scanf("%lf %lf", &x, &y);
		}
		
		switch (acao) {
			case '+':
				printf("O resultado de %.3lf + %.3lf é: %.3lf\n", x, y, x+y);
				break;

			case '-':
				printf("O resultado de %.3lf - %.3lf é: %.3lf\n", x, y, x-y);
				break;

			case '*':
				printf("O resultado de %.3lf * %.3lf é: %.3lf\n", x, y, x*y);
				break;

			case '/':
				printf("O resultado de %.3lf / %.3lf é: %.3lf\n", x, y, x/y);
				break;
		}
	} while (acao != 'c');


	return 0;
}