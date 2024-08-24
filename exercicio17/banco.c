#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *nome, *cpf;
	int idade;
	float saldo, credito;
} Conta;

void *alocar (int items, int tamanho) {
	void* ponteiro;

	if ((ponteiro = (void *) malloc(items * tamanho)) == NULL) {
		printf("Erro: sem memória para alocar\n");
		exit(1);
	}

	return (ponteiro);
}

void desalocar (Conta *contas, int n) {
	for (int i = 0; i < 0; i++) {
		free(contas[i].nome);
		free(contas[i].cpf);
	}

	free(contas);
}

Conta *entradaDados (int n) {
	printf("aqui");
	Conta *contas = alocar(n, sizeof(Conta));

	for (int i = 0; i < n; i++) {
		char *dados = (char *) alocar(100, sizeof(char));
		char *split;
		int i = 0;

		contas[i].nome = (char *) alocar(30, sizeof(char));
		contas[i].cpf = (char *) alocar (11, sizeof(char));

		fgets(dados, sizeof(dados), stdin);

		split = strtok(dados, ",");

		//gambiarra?
		while (split != NULL) {
			if (i == 0) {
				strcpy(contas[i].nome, split);
			} else if (i == 1) {
				strcpy(contas[i].cpf, split);
			} else if (i == 2) {
				contas[i].idade = atoi(split);
			} else if (i == 3) {
				contas[i].saldo = atof(split);
			} else {
				contas[i].credito = atof(split);
			}

			i++;
		}

		if ((contas[i].nome = (char *) realloc(contas[i].nome, strlen(contas[i].nome) * sizeof(char))) == NULL) {
			exit(1);
		}

		free(dados);
	}

	return (contas);
}

void saida (Conta *contas, int n) {
	for (int i = 0; i < n; i++) {
		printf("Dados da pessoa %d:\n", i+1);
		printf("Nome: %s\n", contas[i].nome);
		printf("CPF: %s\n", contas[i].cpf);
		printf("Idade: %d\n", contas[i].idade);
		printf("Saldo: %.2f\n", contas[i].saldo);
		printf("Credito: %.2f\n", contas[i].credito);
		printf("\n");
	}

	int c = 0;
	printf("Pessoas endividadas:\n");
	for (int i = 0; i < n; i++) {
		if ((contas[i].credito) > (contas[i].saldo)) {
			printf("Nome: %s\n", contas[i].nome);
			printf("CPF: %s\n", contas[i].cpf);
			printf("Divida: %.2f\n", (contas[i].credito) - (contas[i].saldo));
			printf("\n");

			c++;
		}
	}

	if (c == 0) {
		printf("Nenhuma pessoa endividada encontrada\n");
	}
}

int main (void) {

	int n;

	scanf("%d", &n);

	Conta *contas = entradaDados(n);

	saida(contas, n);

	desalocar(contas, n);

	return (0);
}