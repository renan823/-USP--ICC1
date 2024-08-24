#include <stdio.h>
#include <stdlib.h>

/*
entrada_dimensoes eh uma função que recebe as dimensoes da matriz, armazenando-as em ponteiros
(recebidos por parametros)
Nada eh retornado
*/
void entrada_dimensoes (int *linhas, int *colunas) {
	scanf("%d %d", linhas, colunas);
}

/*
entrada_dados eh uma função que recebe os dados da matriz, baseado nas N linhas e M colunas 
recebidos por parametro
Por meio do ponteiro para ponteiro **matriz, eh possivel acessar a memoria na posicao [i][j],
entao não eh necessario receber como derreferencia, uma vez que o ponteiro irá mudar o valor diretamente,
sendo dispensavel apos o termino da função
*/
void entrada_dados (double **matriz, int linhas, int colunas) {
	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			scanf("%lf", &matriz[i][j]);
		}
	}
}

/*
aloca eh uma função que permite a alocação dinamica para alocar uma matriz de N linhas por M colunas
A matriz alocada eh retornada
*/
double **aloca (int linhas, int colunas) {
	double **p;

	if ((p = (double **) malloc(linhas * sizeof(double *))) == NULL) {
		printf("erro\n");
		exit(1);
	}

	for (int i = 0; i < linhas; i++) {
		p[i] = (double *) malloc(colunas * sizeof(double));

		if (p[i] == NULL) {
			printf("erro\n");
		exit(1);
		}
	}

	return (p);
}

/*
desaloca eh uma funcao que recebe o endereco da matriz (ou seja, recebe o endereco do
ponteiro para ponteiro para double, por isso o ***matriz, onde o ultimo * eh a derreferencia do endereco),
o numero de linhas e o numero de colunas.
A função irá limpar a memoria anteriormente alocada, começando pelos ponteiros para double, depois para o
ponteiro para ponteiro para double.
Para cada iteração do loop, o free() irá liberar a memoria do ponteiro que está na posição i do ponteiro para ponteiro
Ao terminar o loop, free() irá liberar a memoria do ponteiro para ponteiros (desalocando o endereco apontado por matriz)
Depois, o conteudo apontado por mat será null
*/
void desaloca (double ***matriz, int linhas, int colunas) {
	for (int i = 0; i < linhas; i++) {
		free((*matriz)[i]);
		(*matriz)[i] = NULL;
	}
	free(*matriz);
	*matriz = NULL;
}

void saida (double **matriz, int linhas, int colunas) {
	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			printf("%.2lf ", matriz[i][j]);
		}
		printf("\n");
	}
}


int main (void) {
	int n, m;
	double **matriz = NULL;

	entrada_dimensoes(&n, &m);

	matriz = aloca(n, m);

	entrada_dados(matriz, n, m);

	saida(matriz, n, m);

	desaloca(&matriz, n, m);

	return (0);
}