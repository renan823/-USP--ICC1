#include <stdio.h>
#include <stdlib.h>

void *alocar (int items, int tamanho) {
	void *p;

	if ((p = (void *) malloc(items * tamanho)) == NULL) {
		exit(1);
	}

	return (p);
}

void realocar (char *conteudo, int tamanho, int tamanho_str) {
	if ((conteudo = (char *) realloc(conteudo, tamanho + sizeof(char) * tamanho_str)) == NULL) {
		exit(1);
	}

	return (tamanho + sizeof(char) * tamanho_str);
}

int tamanho_string (int cod) {
	int tam = 0;
	int cont = 2;

	do {
		if (cod % cont == 0) {
			tam += cont;
			while (cod % cont == 0) {
				cod /= cont;
			}
		}
		cont++;
	} while (cod > 1);

	return (tam);
}

void entrada (int n, int *ip, int *cod, char **conteudo) {
	int tamanho

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &ip[i], &cod[i]);

		int tam = tamanho_string(cod[i]);

		printf("%d\n", tam);

		conteudo = realocar_string(conteudo, tam, i, tamanho);

		scanf("%s", conteudo[i]);
	}
}

void saida (int n, int *ip, int *cod, char **conteudo) {
	for (int i = 0; i < n; i++) {
		printf("%d %d %s\n", ip[i], cod[i], conteudo[i]);
	}
}

int main (void) {

	int n;

	int *ip, *cod;

	char **conteudo;

	scanf("%d", &n);

	if (n > 0) {
		ip = (int *) alocar(n, sizeof(int));
		cod = (int *) alocar(n, sizeof(int));

		entrada(n, ip, cod, conteudo);

		saida(n, ip, cod, conteudo);
	} else {
		printf("Sem produtos a serem cadastrados\n");
	}

	return (0);
}