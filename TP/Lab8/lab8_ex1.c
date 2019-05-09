#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float sinus(int n) {
    return sin(n);
}
float cosinus(int n) {
    return cos(n);
}
float sin_cos(int n) {
    return sin(n)*cos(n);
}
int x_patrat(int n) {
    return n*n;
}
int main()
{
    int A,B,N,i;
    printf("A? "); scanf("%d", &A);
    printf("B? "); scanf("%d", &B);
    printf("N? "); scanf("%d", &N);
    float (*pointer_sin)(int);
    float (*pointer_cos)(int);
    float (*pointer_sincos)(int);
    int (*pointer_x_patrat)(int);
    pointer_sin = &sinus;
    pointer_cos = &cosinus;
    pointer_sincos = &sin_cos;
    pointer_x_patrat = &x_patrat;
    for (i=A;i<=B;i+=(double)abs(A-B)/(N-1)) {
        printf("sin(%d)=%.4f\t", i, (*pointer_sin)(i));
        printf("cos(%d)=%.4f\t", i, (*pointer_cos)(i));
        printf("sin*cos(%d)=%.4f\t", i, (*pointer_sincos)(i));
        printf("%d*%d=%d\n", i, i, (*pointer_x_patrat)(i));
    }
    return 0;
}
