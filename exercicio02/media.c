#include <stdio.h>

int main (void) {

    int n;
    float media = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        float num;
        scanf("%f", &num);

        media += num;
    }

    media = media / n;

    printf("a media eh: %.2f\n", media);

    return 0;
}