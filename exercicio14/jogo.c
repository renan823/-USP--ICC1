#include <stdio.h>
#include <stdlib.h>

//Renan Trofino Silva - 2024

/*
A função 'alocar' realiza uma aloção genérica, ou seja, sem tipo definido.
O quanto de memória a ser alocado será definido pelos parâmetros 'items' e
'tamanho_tipo', que correspondem, respectivamente, ao número de items na matriz e o
tamanho do tipo dos dados que irão ser armazenados.
Caso a alocação seja bem sucedida, o ponteiro alocado será retornado.
Caso contrário, uma mensagem será exibida e o programa finalizado.
*/
void *alocar (int items, int tamanho_tipo) {
	void *p;

	if ((p = (void *) malloc(items * tamanho_tipo)) == NULL) {
		printf("Not enough memory\n");
		exit(1);
	}

	return (p);
}

/*
A função 'desalocar' recebe como parâmetro o endereço da matriz anteriormente alocada,
liberando assim o espaço para uso.
Nada é retornado. 
*/
void desalocar (char *p) {
	free(p);
}

/*
A função 'entrada_dimensoes' é responsável por receber as dimensões da matriz via 
input do usuário. Os valores recebidos serão armazenados nos ponteiros 'n' e 'm',
já criados na função 'main', que são, respectivamente, o número de linhas e colunas da matriz.
Nada é retornado.
*/
void entrada_dimensoes (int *n, int *m) {
	scanf("%d %d", n, m);
}

/*
A função 'entrada_dados' recebe as entradas do usuário para preencher a matriz anteriormente
alocada. A matriz, o número de linhas e colunas são passados como parâmetro.
Nada é retornado, uma vez que a matriz preenchida é um ponteiro declarado na função 'main'.
*/
void entrada_dados (char *mapa, int linhas, int colunas) {
	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			scanf(" %c", &mapa[i * colunas + j]);
		}
	}
}

/*
A função 'mapear' é responsável por encontrar os possíveis locais disponíveis no tabuleiro.
Para isso, o mapa e suas dimensões são passados por parametro.
Para cada item no mapa é verificado o número de vizinhos vagos. 
Se o número de casas vizinhas vagas for para, então é possivel colocar a peça '*', 
senão, não.
Nada é retornado.
*/
void mapear (char *mapa, int linhas, int colunas) {
	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			if (mapa[i * colunas + j] == '.') {
				int cont = 0;

				if (j > 0 && mapa[i * colunas + (j-1)] == 'X') {
					cont++;
				}

				if (j < colunas && mapa[i * colunas + (j+1)] == 'X') {
					cont++;
				}

				if (i > 0 && mapa[(i-1) * colunas + j] == 'X') {
					cont++;
				}

				if (i < linhas && mapa[(i+1) * colunas + j] == 'X') {
					cont++;
				}

				
				if (cont % 2 == 0) {
					mapa[i * colunas + j] = '*';
				}
			} 
		}
	}
}

/*
A função 'saida' recebe a matriz (mapa) e suas dimensões e então exibe,
linha por linha, os items da matriz.
Nada é retornado
*/
void saida (char *mapa, int linhas, int colunas) {
	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			printf("%c", mapa[i * colunas + j]);
		}
		printf("\n");
	}
}

/*
A função 'main' é responsável por unir todas as funcionalidades 
das outras funções, declarando também as variáveis de dimensão (n, m)
e a matriz a ser alocada (mapa)
*/
int main (void) {

	int n, m;
	char *mapa;

	entrada_dimensoes(&n, &m);

	mapa = (char *) alocar(n * m, sizeof(char));

	entrada_dados(mapa, n, m);

	mapear(mapa, n, m);

	saida(mapa, n, m);

	desalocar(mapa);
	mapa = NULL;

	return (0);
}