#include <stdio.h>
#include <stdlib.h>

//Renan Trofino Silva 2024

/*
A função alocar recebe vetor, um ponteiro double não inicializado, e n, um interio que indica 
a quantidade de números a serem adicionados no vetor;

O vetor ira receber, por meio da alocação dinamica, o espaço de memoria necessário para armazenar 
n vezes o tamanho do tipo (que é double)

Nada é retornado
*/
void alocar (double **vetor, int n) {
	if (*vetor = (double *) malloc(n * sizeof(double)) == NULL) {
		printf("Sem memória\n");
		exit(1);
	}	
}

/*
A função entrada recebe vetor, um ponteiro já inicializado double, e n, um inteiro que indica
a quantidade de elementos no vetor;

Para cada elemento no vetor será pedido um número ao usuário. O número é inserido na posição
correspondente no vetor;

Nada é retornado
*/
void entrada (double *vetor, int n) {
	for (int i = 0; i < n; i++) {
		scanf("%lf\n", &vetor[i]);
	}
}

/*
A função saida receber vetor, um vetor double com valores, e n, um inteiro que indica
a quantidade de elementos no vetor;

Cada elemento é exibido na tela, com uma quebra de linha

Nada é retornado;
*/
void saida (double *vetor, int n) {
	for (int i = 0; i < n; i++) {
		printf("%lf\n", vetor[i]);
	}

}

/*
A função main junta as outras funções e cuida de receber o interio n, digitado pelo usuário, bem como
se responsabiliza pela declaração do vetor que será posteriormente preenchido
*/
int main (void) {
	double *vetor;
	int n;

	scanf("%d", &n);

	alocar(&vetor, n);

	entrada (vetor, n);

	saida(vetor, n);

	free(vetor);
	vetor=NULL;

	return (0);
}