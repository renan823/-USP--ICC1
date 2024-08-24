#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char *nome;
	int farinha, ovos, oleo, acucar, chocolate;
} Receita;

typedef struct {
	int farinha, ovos, oleo, acucar, chocolate;
} Estoque;

void *alocar (int items, int tamanho) {
	void* ponteiro;

	if ((ponteiro = (void *) malloc(items * tamanho)) == NULL) {
		printf("Erro: sem memória para alocar\n");
		exit(1);
	}

	return (ponteiro);
}

void estocar (Estoque *es) {
	int f, ov, ol, a, c;
	scanf("%d %d %d %d %d", &f, &ov, &ol, &a, &c);

	es->farinha += f;
	es->ovos += ov;
	es->oleo += ol;
	es->acucar += a;
	es->chocolate += c;
}

void fazerReceita (Receita *receitas, int qnt, Estoque *es) {
	int rec, achou = 0;
	scanf("%d", &rec);

	if (rec < qnt) {
		if (receitas[rec].farinha > es->farinha && !achou) {
			printf("Farinha insuficiente\n");
			achou = 1;
		}
		if (receitas[rec].ovos > es->ovos && !achou) {
			printf("Ovos insuficientes\n");
			achou = 1;
		}
		if (receitas[rec].oleo > es->oleo && !achou) {
			printf("Oleo insuficiente\n");
			achou = 1;
		}
		if (receitas[rec].acucar > es->acucar && !achou) {
			printf("Acucar insuficiente\n");
			achou = 1;
		}
		if (receitas[rec].chocolate > es->chocolate && !achou) {
			printf("Chocolate insuficiente\n");
			achou = 1;
		}
 
		if (!achou) {
			printf("%s feita com sucesso!\n", receitas[rec].nome);

			es->farinha -= receitas[rec].farinha;
			es->oleo -= receitas[rec].oleo;
			es->ovos -= receitas[rec].ovos;
			es->acucar -= receitas[rec].acucar;
			es->chocolate -= receitas[rec].chocolate;
		}

	} else {
		printf("Receita nao encontrada!\n");
	}
}

void exibir (Estoque es, Receita *receitas, int qnt) {
	printf("Quantidade no estoque:\n");
	printf("Acucar: %d\n", es.acucar);
	printf("Chocolate: %d\n", es.chocolate);
	printf("Farinha: %d\n", es.farinha);
	printf("Oleo: %d\n", es.oleo);
	printf("Ovos: %d\n", es.ovos);
	printf("Receitas cadastradas: %d\n", qnt);
}

int main (void) {

	char op;
	int qnt = 0;

	Estoque estoque = { 0, 0, 0, 0 };
	Receita *receitas = NULL;

	do {
		scanf(" %c", &op);

		switch (op) {
			case 'R':
				if ((receitas = realloc(receitas, sizeof(Receita) * (qnt + 1))) == NULL) {
					exit(1);
				}

				receitas[qnt].nome = alocar(20, sizeof(char));

				getc(stdin);

				scanf("%s", receitas[qnt].nome);
				scanf("%d %d %d %d %d", 
					&receitas[qnt].farinha, 
					&receitas[qnt].ovos, 
					&receitas[qnt].oleo, 
					&receitas[qnt].acucar,
					&receitas[qnt].chocolate
				);

				qnt++;
				break;
			case 'C':
				estocar(&estoque);
				break;
			case 'F':
				fazerReceita(receitas, qnt, &estoque);
				break;
			case 'S':
				exibir(estoque, receitas, qnt);
				break;
			default: 
				printf("Codigo invalido\n");
		}

	} while (op != 'S');

	return (0);
}