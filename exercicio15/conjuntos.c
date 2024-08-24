#include <stdio.h>
#include <stdlib.h>

void *alocar (int items, int tamanho) {
	void *p;

	if ((p = (void *) malloc(items * tamanho)) == NULL) {
		exit(1);
	}

	return (p);
}

void sort (int *p, int n) {
	int swaps;
	int temp;

	do {
		swaps = 0;
		for (int i = 0; i < n-1; i++) {
			if (p[i] > p[i+1]) {
				temp = p[i];
				p[i] = p[i+1];
				p[i+1] = temp;

				swaps++;
			}
		}
	} while (swaps);
}

void entrada (int *vetor, int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		scanf("%d", &vetor[i]);
	}
}

void saida(int *vetor, int tamanho) {
	if (tamanho > 0) {
		for (int i = 0; i < tamanho; i++) {
			printf("%d ", vetor[i]);
		}
		printf("\n");
	} else {
		printf("vazio\n");
	}
}

int *uniao (int *va, int *vb, int ta, int tb, int *tu) {
	int *uni = (int *) alocar(ta+tb, sizeof(int));

	for (int i = 0; i < ta; i++) {
		uni[i] = va[i];
		(*tu)++;
	}

	int achou = 0;

	for (int i = 0; i < tb; i++) {
		achou = 0;

		for (int j = 0; j < *tu; j++) {
			if (vb[i] == uni[j]) {
				achou = 1;
				break;
			}
		}

		if (!achou) {
			uni[*tu] = vb[i];
			(*tu)++;
		}
	}

	if ((uni = (int *) realloc(uni, (*tu) * sizeof(int))) == NULL) {
		exit(1);
	}

	sort(uni, *tu);

	return (uni);
}

int *interseccao (int *va, int *vb, int ta, int tb, int *ti) {
	int *inter = (int *) alocar(ta, sizeof(int));

	for (int i = 0; i < ta; i++) {
		for (int j = 0; j < tb; j++) {
			if (va[i] == vb[j]) {
				inter[*ti] = va[i];
				(*ti)++;
				break;
			}
		}
	}

	if ((*ti) == 0) {
		return (va);
	}

	if ((inter = (int *) realloc(inter, (*ti) * sizeof(int))) == NULL) {
		exit(1);
	}

	sort(inter, *ti);

	return (inter);
}

int *diferenca (int *va, int *vb, int ta, int tb, int *td) {
	int *dif = (int *) alocar(ta, sizeof(int));
	int achou = 0;

	for (int i = 0; i < ta; i++) {
		achou = 0;
		for (int j = 0; j < tb; j++) {
			if (va[i] == vb[j]) {
				achou = 1;
				break;
			}
		}
		if (!achou) {
			dif[*td] = va[i];
			(*td)++;
		}
	}

	if ((*td) == 0) {
		return (va);
	}

	if ((dif = (int *) realloc(dif, (*td) * sizeof(int))) == NULL) {
		exit(1);
	}

	sort(dif, *td);

	return (dif);
}

int * conta (int *va, int *vb, int ta, int tb, int *td) {
	int ti = 0, tu = 0;

	int *un = uniao(va, vb, ta, tb, &tu);

	printf("A uniao B: ");
	saida(un, tu);
	
	int *inter = interseccao(va, vb, ta, tb, &ti);

	int *dif = diferenca(un, inter, tu, ti, td);

	if (td == 0 || ti == 0) {
		*td = tu;
		return (un);
	}

	return (dif);
}

int main (void) {
	int *a, *b, ta, tb, td = 0;

	scanf("%d", &ta);
	a = (int *) alocar(ta, sizeof(int));
	entrada(a, ta);

	scanf("%d", &tb);
	b = (int *) alocar(tb, sizeof(int));
	entrada(b, tb);

	sort(a, ta);
	sort(b, tb);

	printf("conjunto A: ");
	saida(a, ta);

	printf("conjunto B: ");
	saida(b, tb);

	int *resultado = conta(a, b, ta, tb, &td);

	printf("(A uniao B) - (A interseccao B): ");
	saida(resultado, td);

	return (0);
}