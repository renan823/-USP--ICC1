#include <stdio.h>

/*
Dividir o problema em partes menores
(o problema continua o mesmo)

Uma função que chama ela mesma, passando
menos dados conforme avança na recursao

é direta se p chama p
é indireta se p chama q que chama p

a recursão vai e volta, até chegar na solução trivial (que já é conhecida)

é interessante construir uma equação recursiva antes
que ajuda no trabalho com a função mesmo
*/

int somar (int n) {
	if (n == 1) {
		return (1);
	}

	return (n + somar(n-1));
}

//F(n) = (F(n-1) * n);
//F(0) = 1 F(1) = 1;
long int fatorial (int n) {
	if (n == 0 || n == 1) {
		return (1);
	}

	return (n * fatorial(n-1));
}

//n = (n-1) + (n-2);
//f(0) = 0 f(1) = 1
long int fibonacci (int n) {
	if (n <= 1) {
		return (n);
	}

	return (fibonacci(n-1) + fibonacci(n-2));
}

int main (void) {
	printf("%d\n", somar(5));
	printf("%ld\n", fatorial(5));
	
	for (int i = 0; i <= 5; i++) {
		printf("%ld\n", fibonacci(i));
	}

	return (0);
}