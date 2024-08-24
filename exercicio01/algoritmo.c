#include <stdio.h>

int main () {

    int caso; //case nao pode ser variavel
    char nome1, nome2, caracter; 
    //char nao pode ser nome de variavel
    //variavel nao pode comecar com numero 

    scanf("%d\n", &caso);
    scanf("%c\n", &nome1);
    scanf("%c\n", &nome2);
    scanf("%c", &caracter);

    int resposta;
    resposta = caso;

    printf("a resposta eh ");
    printf("%d\n", resposta);

    return 0;
}