#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *nome, *prof;
	float altura;
} Pessoa;

void *alocar (int n, int tam) {
	void *ptr;

	if ((ptr = (void *) malloc(n * tam)) == NULL) {
		printf("Erro: sem memória\n");
		exit(1);
	}

	return (ptr);
}

void *realocar (void *ptr, int n, int tam) {
	if ((ptr = (void *) realloc(ptr, n * tam)) == NULL) {
		printf("Erro: sem memória\n");
		exit(1);
	}

	return (ptr);
}

Pessoa *cadastrar () {
	Pessoa *p = (Pessoa *) alocar(1, sizeof(Pessoa));

	p->nome = (char *) alocar(30, sizeof(char));
	p->prof = (char *) alocar(30, sizeof(char));

	scanf(" %s %s %f", p->nome, p->prof, &p->altura);

	p->nome = (char *) realocar(p->nome, strlen(p->nome), sizeof(char));
	p->prof = (char *) realocar(p->prof, strlen(p->prof), sizeof(char));

	return (p);
}

int main (void) {
	int n;
	scanf("%d", &n);

	double media = 0.0;

	Pessoa **pessoas = (Pessoa **) alocar(n, sizeof(Pessoa *));

	for (int i = 0; i < n; i++) {
		pessoas[i] = cadastrar();

		media += pessoas[i]->altura;
	}

	media /= n;

	for (int i = 0; i < n; i++) {
		if (pessoas[i]->altura > media) {
			printf("\nNome: %s\n", pessoas[i]->nome);
			printf("Profissão: %s\n", pessoas[i]->prof);
			printf("Altura: %.2lf\n", pessoas[i]->altura);
		}

		free(pessoas[i]->nome);
		free(pessoas[i]->prof);
		free(pessoas[i]);
	}

	free(pessoas);
}