#include <stdio.h>

int main (void) {
	int n;

	//curvas fechadas O->N, N->L, S->O, S->L
	//curvas para a esquerda, ja que o lago eh na direita dela
	//curvas 270 => x , curvas 90 => n - x
	//angulos internos sao 180(n-2)


	//270x + 90n - 90x = 180n - 360
	//180x = 90n -360
	//x = (90n - 360)/180
	//x = (n - 4)/2


	scanf("%d", &n);

	printf("%d\n", (n - 4)/2);
	
}