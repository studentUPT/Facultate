#include <stdio.h>
/*Functia primeste un pointer, dar il foloseste de fapt pentru a accesa locatia de memorie unde rezida variabila
care se doreste a fi modificara. */

void inca_o_functie(int *parametru){
    //Afisam valoarea variabilei la inceputul functiei.
    printf("In functie, la inceput: %d. \n", *parametru);
    //Modificam variabila in interiorul functiei(prin intermediul pointerului).
    (*parametru)++;
    //Afisam inca o data variabila la finalul functiei.
    printf("In functie, la final: %d.\n", *parametru);
}

int main(void){
    int variabila = 100;
    //Afisam variabila inainte de apelul functiei.
    printf("Inainte de apelul functiei:%d.\n", variabila);
    //Apelam functia. Trimitem adresa variabilei ca parametru.
    inca_o_functie(&variabila);
    //Afisam variabila dupa apelul functiei.
    printf("Dupa apelul functiei: %d.\n", variabila);
    return 0;
}