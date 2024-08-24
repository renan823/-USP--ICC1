#include <stdio.h> 
#include <math.h>

#define PI 3.14159265358979323846

double radianos (int degrees) {
	return degrees * PI / 180.0;
}

int main (void) {

	int i;
	double l;

	scanf("%d %lf", &i, &l);

	double p = i * l / 2;

	int angulo = (360 / i) / 2;

	double a = (l/2) / tan(radianos(angulo));

	printf("%lf\n", a * p);

	return 0;
}