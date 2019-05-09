#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float sinus(float n) {
    return sin(n);
}
float cosinus(float n) {
    return cos(n);
}
float maxx(float (*un_pointer_la_functie) (float x)) {
    int i;
    float valoare;
    float max = 0;
    for(i=0;i<10;i++) {
        valoare = (*un_pointer_la_functie)(i);
        if (max<valoare)
            max=valoare;
    }
    return max;
}

int main()
{
    printf("maxim pentru sinus: %f.\n", maxx(&sinus));
    printf("maxim pentru cosinus: %f.\n", maxx(&cosinus));
    return 0;
}
