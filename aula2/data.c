#include <stdio.h>

int main () {

    int date;

    scanf("%d", &date);

    int day = date / 1000000;
    int month = (date / 10000) % 100;
    int year = date % 10000;

    printf("%02d/%02d/%d\n", day, month, year);

    return 0;
}