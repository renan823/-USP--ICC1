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

char *lerString (int n) {
	char *string = (char *) alocar(n, sizeof(char));

	scanf(" %s", string);

	if ((string = (char *) realloc(string, strlen(string) * sizeof(char))) == NULL) {
		exit(1);
	}

	string[strlen(string)-1] = '\0';

	return (string);
}

Conta *entradaDados (int n) {
	Conta *contas = alocar(n, sizeof(Conta));

	for (int i = 0; i < n; i++) {
		contas[i].nome = lerString(30);
		contas[i].cpf = lerString(11);

		scanf("%d, %f, %f", &contas[i].idade, &contas[i].saldo, &contas[i].credito);
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
	printf("Pessoas endividadas:");
	for (int i = 0; i < n; i++) {
		if ((contas[i].credito) > (contas[i].saldo)) {
			printf("\nNome: %s\n", contas[i].nome);
			printf("CPF: %s\n", contas[i].cpf);
			printf("Divida: %.2f\n", (contas[i].credito) - (contas[i].saldo));
			
			c++;
		}
	}

	if (c == 0) {
		printf("\nNenhuma pessoa endividada encontrada.\n");
	}
}

int main (void) {
	int n;

	scanf("%d", &n);

	Conta *contas = entradaDados(n);

	saida(contas, n);

	free(contas);

	return (0);
}