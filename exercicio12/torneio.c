#include <stdio.h>

int posicao (int v[], int n, int valor, int freq[]) {
	int pos = 1;

	for (int i = 0; i < n; i++) {
		if (v[i] > valor) {
			pos++;
		}
	}

	for(int i = 0 ; i < n ; i++){
		if(v[i] > valor){
			pos -= (freq[v[i]] - 1) ; 
		}
	}

	return pos;

}

int main (void) {
	int n; 
	scanf("%d", &n);

	int v[n+2]; int freq[1010] = {0} ;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]); freq[v[i]]++ ; 
	}

	for (int j = 0; j < n; j++) {
		printf("%dº Atleta, %d Pontos, %dº Colocado\n", j+1, v[j], posicao(v, n, v[j], freq));
	}
	return (0);
}