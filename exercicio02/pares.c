#include <stdio.h>

int main () {
    int n;

    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("eh par!\n");
    } else {
        printf("eh impar!\n");
    }

    return 0;
}