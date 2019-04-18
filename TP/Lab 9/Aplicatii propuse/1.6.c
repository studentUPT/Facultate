//Se citesc 2 valori naturale nr si bit(0<=bit<=15). 
//Sa se marcheze cu 1 bitul bit al lui nr.

#include <stdio.h>
#include <stdlib.h>

int main(){
    int nr, bit;
    printf("dati nr: ");
    scanf("%d", &nr);
    for(int poz=15; poz>=0; poz--)
    printf("%d",((nr>>poz)&1));
    printf("\nal catelea bit?");
    scanf("%d", bit);
    printf("%d", nr|(1<<bit));
    return 0;
}