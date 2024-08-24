#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *titulo;
	char *autor;
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
	int rep = 0;
	int tamanho = 0;

	Livro *livros;

	for (int i = 0; i < *n; i++) {
		char *titulo = lerString(100);
		char *autor = lerString(50);

		int ano;
		scanf("%d", &ano);

		Livro l = { titulo, autor, ano, 1 };

		if (i == 0) {
			livros = (Livro *) alocar(1, sizeof(l));
			tamanho += sizeof(l);
			livros[0] = l;
		} else {
			int achou = 0;

			for (int j = 0; j < i; j++) {
				if ((strcmp(titulo, livros[j].titulo) == 0)) {
					livros[j].quantidade++;
					rep++;
					achou = 1;
					printf("asndjansdsnd\n");
					break;
				} 
			}
			printf("%d\n", achou);
			
			if (!achou) {
				printf("asndjansdsnd\n");
				if ((livros = (Livro *) realloc(livros, tamanho + sizeof(l))) == NULL) {
					exit(1);
				}

				printf("asndjansdsnd\n");

				livros[i-rep] = l;
				tamanho += sizeof(l);
			}
		}
	}

	*n -= rep;

	return (livros);
}

void saida (Livro *livros, int n) {
	printf("%d\n", n);
	printf("Catalogo de Livros: \n");

	for (int i = 0; i < n; i++) {
		printf("Titulo: %s\n", livros[i].titulo);
		printf("Autor: %s\n", livros[i].autor);
		printf("Ano: %d\n", livros[i].ano);
		printf("Quantidade: %d\n", livros[i].quantidade);
		
		if (i+1 != n) {
			printf("\n");
		}
	}
}

int main (void) {
	int n;

	scanf("%d", &n);

	Livro *livros = entrada(&n);

	saida(livros, n);

	desalocar(livros, n);

	return (0);
}