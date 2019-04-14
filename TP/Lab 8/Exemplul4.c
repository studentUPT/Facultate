#include <stdio.h>
#include <math.h>

/*Functia sinus.*/
float sinus(int n){
    return sin(n);
}
/*Functia cosinus.*/
float cosin(int n){
    return cos(n);
}
/*Functie care calculeaza maximul unei alte functii. Folosim pointeri la functie
pentru a preciza care este functia pentru care se calculeaza maximul. */
float max(float (*un_pointer_la_functie)(int)){
    int i;
    float valoare;
    /*Initial maximul este zero.*/
    float max = 0;
    /*Calculam maximul din 10 valori. */
    for(i = 0; i < 10; i++){
        /*Calculam valoarea functiei in punctul i. */
        valoare = (*un_pointer_la_functie) (i);
        /*Daca este cazul, actualizam maximul. */
        if( max < valoare)
        max = valoare;
    }
    /*Returnam maximul gasit. */
    return max;
}

int main(void){
    /*Afisam maximul functiei sinus. Practic apelam functia max si ii trimitem ca
    si parametru adresa functiei sinus. */
    printf("Maxim pentru sinus: %f.\n", max(&sinus));
    /*Afisam si maximul functiei cosinus. Apelam din nou functia max, dar de data aceasta ii trimitem ca si parametru adresa functiei cosin. */
    printf("Maxim pentru cosinus: %f.\n", max(&cosin));
    return 0;
}
