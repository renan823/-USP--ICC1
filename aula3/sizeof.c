#include <stdio.h>

int main () {

    printf("Tam char: %lu\n", sizeof(char));
    printf("Tam int: %lu\n", sizeof(int));
    printf("Tam float: %lu\n", sizeof(float));
    printf("Tam double: %lu\n", sizeof(double));
    printf("Tam unsigned char: %lu\n", sizeof(unsigned char));
    printf("Tam signed char: %lu\n", sizeof(signed char));
    printf("Tam unsigned int: %lu\n", sizeof(unsigned int));
    printf("Tam signed int: %lu\n", sizeof(signed int));
    printf("Tam short int: %lu\n", sizeof(short int));
    printf("Tam long int: %lu\n", sizeof(long int));
    printf("Tam long long int: %lu\n", sizeof(long long int));

    return 0;
}