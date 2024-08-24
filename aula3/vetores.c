#include <stdio.h>

int main () {
    unsigned long long int n;

    scanf("%llu", &n);

    printf("char: %llu\n", n);
    printf("int: %llu\n", n*4);
    printf("double: %llu\n", n*8);

    return 0;
}