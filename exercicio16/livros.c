#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char titulo[100];
	char autor[50];
	int ano;
	int quantidade;
} Livro;

void *alocar (int items, int tamanho) {
	void *ponteiro;

	if ((ponteiro = (void *) malloc(items * tamanho)) == NULL) {
		exit(1);
	}

	return (ponteiro);
}

int adicionar (Livro *livros, Livro l, int tamanho, int pos) {
	printf("%d %lu\n", tamanho, sizeof(l));
	if ((livros = (Livro *) realloc(livros, tamanho + sizeof(l))) == NULL) {
		exit(1);
	}

	livros[pos] = l;

	return (tamanho + sizeof(l));
}

void desalocar (Livro *livros, int n) {
	for (int i = 0; i < n; i++) {
		free(livros[i].titulo);
		free(livros[i].autor);
	}

	free(livros);
}

char *lerString (int tamanho) {
	char *string = alocar(tamanho, sizeof(char));

	for (int i = 0; i < tamanho+1; i++) {

		if (i == 0) {
			scanf(" %c", &string[i]);
		} else {
			scanf("%c", &string[i]);
		}
		
		if (string[i] == ',' || string[i] == '\n') {
			string[i] = '\0';
			break;
		}
	}

	if ((string = (char *) realloc(string, sizeof(char) * strlen(string))) == NULL) {
		exit(1);
	}

	return (string);
}

Livro *entrada (int *n) {
	Livro *livros;
	int tamanho = 0;

	for (int i = 0; i < *n; i++) {
		int ano;
		char *titulo = lerString(100);
		char *autor = lerString(50);
		scanf("%d", &ano);

		Livro l = { titulo, autor, ano };

		if (i == 0) {
			livros = (Livro *) alocar(1, sizeof(l));
			livros[i] = l;

			tamanho += sizeof(l);
		} else {
			tamanho = adicionar(livros, l, tamanho, i);
		}
	}

	return (livros);
}

int main (void) {
	int n;

	scanf("%d", &n);

	entrada(&n);

	return (0);
}
