#include <stdio.h>
#define QL 3
#define QC 4

int main (void) {

	//linha x coluna (Ql, Qc)

	int matriz[QL][QC] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
	int *p, sum;

	p = matriz;
	sum = 0;

	//printf("%d\n", *(((1 * QC)+2)+p)); //usando o ponteiro para acessar m[1][2]

	for (int i = 0; i < QL; i++) {
		for (int j = 0; j < QC; j++) {
			sum += matriz[i][j];
		}
	}
	printf("soma com for: %d\n", sum);

	sum = 0;
	for (p = matriz; p <= &matriz[QL-1][QC-1]; p++) {
		sum += *p;
	}

	printf("soma com ponteiro: %d\n", sum);

	//tamanho em bytes = 1 indice * 2 indice * sizeof(tipo)

	//Na memoria, tudo eh linear ...|[1][2][3][4]|[5][6][7][8]|[9][10][11][12]|...
	//Um endereco base eh "escolhido" pelo compilador (o endereco base he ponteiro)

	//M[i][j] = ((i * Qnt colunas) + j) + endereco base
	//O compilador realisa essa operacao, a storage mapping function 
	//Um array eh um arranjo linear de memoria 

	//como calcular o indice do array dado um endereco?

	//inicializacao -> char str[4] = "USP"; OU char str[4] = {'U', 'S', 'P', '\0'};;
	//string precisa do '\0', pra indicar que ela termina

	//inicializacao -> int m[2][2] = {1, 2, 3, 4}; OU int m[2][2] = {{1, 2}, {3, 4}};

	//A 1 dimensao do array pode ser omitida, entao o compilador calcula a dimensao apartir 
	//do numero de elementos e da segunda dimensao do array -> m[][2] = {{1, 2}, {2, 3}};
	//Nao eh boa pratica omitir essa informacao (voce sabe o tamanho? coloque!)

	return (0);
}