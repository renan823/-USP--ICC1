#include <stdio.h>

int main () {

    float a, b, c;

    scanf("%f %f %f", &a, &b, &c);

    float media = (a + b + c) / 3;

    printf("a media eh: %.2f\n", media);

    return 0;
}