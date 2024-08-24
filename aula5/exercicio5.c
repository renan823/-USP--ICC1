#include <stdio.h>
#include <stdlib.h>

void *alocar (int size) {
	void *p;

	if ((p = (void *) malloc(size)) == NULL) {
		printf("Error: not enough memory\n");
		exit(1);
	}

	return (p);
}

int main (void) {

	int *n;
	n = (int *) alocar(4 * sizeof(int));

	return (0);
}