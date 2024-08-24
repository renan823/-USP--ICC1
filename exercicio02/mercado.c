#include <stdio.h>

int main (void) {

	int itens, acao;

	acao = 0;
	itens = 0;

	do {
		int item;
		item = 0;

		scanf("%d", &acao);

		switch (acao) {
			case 1:
				scanf("%d", &item);
				itens++;
				break;
			case 2: 
				printf("%d\n", itens);
				break;
		}
	} while (acao != 3);

	return 0;
}