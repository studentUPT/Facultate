#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

inline double fsin(double x) { return sin(x); }
inline double fcos(double x) { return cos(x); }
inline double fsinxcos(double x) { return sin(x)* cos(x); }
inline double fxx(double x) { return x * x; }

void tab(double (*fptr)(double), double a, double b, double n) {
	double i;
	for (i = a; i <= b; i += abs(a - b) / (n - (double)1))
		printf("sin(%.4lf) = %.4lf\n", i, (*fptr)(i));
}
int main()
{
	int a, b, n;
	scanf("%d %d %d", &a, &b, &n);
	printf("\nsin(x): \n");
	tab(&fsin, a, b, n);
	return 1;
}