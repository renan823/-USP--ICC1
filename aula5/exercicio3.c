#include <stdio.h>
#include <stdlib.h>

/*
A função alocar é responsável por alocar dinamicamente uma matriz usando o numeor de linhas e colunas.
O ponteiro duplo **p é alocado de acordo com o numero de linhas, servindo para armazenar as futuras posições do
vetor de doubles.
Para alocar, um espaço de memoria do tamanho linhas * colunas * tamanho do tipo é selecionado para o vetor.
Em seguida, o grande vetor será dividido de acordo com a quantidade de colunas na matriz.
Essa abordagem garante apenas dois usos do malloc, melhorando a eficiencia.
Desse modo, cada ponteiro do vetor de ponteiros p irá apontar para o endereco de memoria que corresponde
ao começo de uma nova linha no vetor. 

vetro, na memoria, é algo como: [][][]/[][][]/[][][], sendo dividido pelo numero de colunas 
*/
double **alocar (int linhas, int colunas) {
	double **p;
	double *vetor;

	if ((p = (double **) malloc(linhas * sizeof(double *))) == NULL) {
		printf("erro\n");
		exit(1);
	}

	if ((vetor = (double *) malloc(linhas * colunas * siozeof(double))) == NULL) {
		printf("erro\n");
		exit(1);
	}

	for (int i = 0; i < colunas; i++) {
		p[i] = & vetor[i * colunas];
	}

	return (p);
}



int main (void) {
	return (0);
}