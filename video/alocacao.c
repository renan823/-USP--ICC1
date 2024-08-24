#include <stdio.h>
#include <stdlib.h>

int main (void) {
	int *a, *b;
	int n = 4;

	a = (int *) calloc(n, sizeof(int)); // [0, 0, 0, 0]
	
	if ((b = (int *) malloc(n * sizeof(int))) == NULL) {
		exit(1);
	}

	//Se tudo deu certo, b foi alocado, mas contém lixo de memória

	a[1] = 7; //coloca uma valor na posição 0 de a
	b[0] = 10; // coloca um valor na posição 0 de b

	b = (int *) realloc(b, (n * sizeof(int)) + (2 * sizeof(int))); //adiciona mais 2 espaços em b

	free(a);
	a = NULL;

	return(0);
}


/*
Exercicio:
	Faça um programa em C que receba um número inteiro 'N'.
	'N' é o número de items de um vetor de inteiros, que deve ser preenchido pelo usuário.
	Faça também uma função para adicionar um elemento (qualquer) no fim do vetor.
	Exiba o vetor antes e depois da alteração.
*/