/*Se citeste de la tastatura un numar n, urmat de n numere reale. Cele n numere reale se vor
memora intr-un tablou. La final se mai citeste un numar real x. Sa se afiseze acele numere din tablou
care se afla in intervalul deschis (x-1, x+1). */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    float *a, x;
    int n, i;
    /*Citim n de la tastaura. */
    printf("Cate numere? ");
    scanf("%d", &n);
    /*Dupa ce il stim pe n, alocam din zona dinamica un bloc de memorie
    in care sa putem pastra n float-uri. */
    a = (float *) malloc (n * sizeof(float));
    /* Daca alocarea de memorie a esuat,
    incheiem executia cu un mesaj de eroare. */
    if(!a){
        printf("Nu pot aloca memeorie. \n");
        exit(EXIT_FAILURE);
    }
    /*Daca am ajuns aici inseamna ca alocarea de memorie a reusit.
    Citim cele n numere reale. */
    for(i = 0; i < n; i++){
        printf("a[%d]: ", i);
        scanf("%f", &a[i]);
    }
    /*Citim numarul x. */
    printf("x: ");
    scanf("%f", &x);
    /*Afisam numerele in intervalul cerut. */
    printf("Numerele din intervalul (%.2f, %.2f) sunt: ", x-1, x+1);
    for(i = 0; i < n; i++){ 
        if(fabs(x - a[i]) <1)
            printf("%.2f", a[i]);
        printf("\n");

    }
    /*Obligatoriu eliberam blocul de memorie alocat dinamic. */
    free(a);
    return 0;
}