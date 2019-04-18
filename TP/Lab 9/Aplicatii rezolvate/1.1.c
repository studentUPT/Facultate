//Se considera un numar natural retinut in variabila nr.
//Sa se verifice daca nr are valoare para sau impara

#include <stdio.h>
int main(){
    int nr;
    printf("dati numarul: ");
    scanf("%d", &nr);
    if((nr & 1) == 1)
    printf("Numarul este impar");
    else
    printf("Numarul este par");
    
    return 0;
}