#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *alocar (int items, int tamanho) {
	void* ponteiro;

	if ((ponteiro = (void *) malloc(items * tamanho)) == NULL) {
		printf("Erro: sem memória para alocar\n");
		exit(1);
	}

	return (ponteiro);
}


int main (void) {
	char *A = alocar(130, sizeof(char));
	char *B = alocar(130, sizeof(char));
	char *split = alocar(20, sizeof(char));

	fgets(A, 130, stdin);
	fgets(B, 130, stdin);
	fgets(split, 20, stdin);

	split[strlen(split)-1] = '\0';

	char *sA = strstr(A, split);
	char *sB = strstr(B, split);

	for (int i = 0; i < strlen(A); i++) {
		if (A[i] == '\n' || A[i] == '\r') {
			A[i] = '\0';
			break;
		}
	}

	for (int i = 0; i < strlen(B); i++) {
		if (B[i] == '\n' || B[i] == '\r') {
			B[i] = '\0';
			break;
		}
	}

	int temEspaco = 0;

	if (sA == NULL) {
		printf("%s", A);
		temEspaco = 1;
	} else {
		int tamanho = sA - A;
		//ir ate a frase spliter
		for (int i = 0; i < tamanho-1; i++) {
			printf("%c", A[i]);
		}
		temEspaco = 1;
	}

	if (sB != NULL) {
		if (temEspaco) {
			printf(" ");
		}
		int inicio = sB - B;
		//comecar depois do espaco branco extra
		for (int i = inicio + 1 + strlen(split); i < strlen(B); i++) {
			printf("%c", B[i]);
		}
	}

    printf("\n");

    return (0);
}
