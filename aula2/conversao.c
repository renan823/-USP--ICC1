#include <stdio.h>

int main () {

    int num; 
    char letter;

    scanf("%c %d", &letter, &num);

    printf("numero correspondente: %d\n", letter);
    printf("caracter correspondente: %c\n", num);
    printf("octal: %o\n", num);
    printf("hexadecimal: %x\n", num);

    return 0;
}