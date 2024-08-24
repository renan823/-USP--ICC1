#include <stdio.h>

#define N 26

int main (void) {

	char string[N], *p;

	fgets(string, N, stdin);
	
	p = string;
	while (*p != '\0' && *p != '\n') {
		p++;
	}

	*p = '\0';

	for (p = string; p < &string[N-1] && *p != '\0'; p++) {
		if (*p) {
			printf("%c\n", *p);
		}
	}
	
	return 0;
}