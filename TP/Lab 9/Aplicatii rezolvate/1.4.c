/*Se citeste valoare unui numar natural nr. Sa se scrie reprezentarea acestuia in baza 2
Stim ca in memorie nr este deja reprezentat in baza 2, deci ii vom scrie bitii de la stanga la dreapta
Presupunand ca nr este pe 16 biti, deci ii numerotam de la dreapta la stanga cu valori de la 0 la 15
Pentru a obtine bitul de pe pozitia poz (0<= poz<=15), folosim expresia (nr>>poz)&1
Asadar utilizam expresia pt fiecare poz intre 0 si 15.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{   int nr;
    printf("dati nr\n");
    scanf("%d",&nr);
    for(int poz=15;poz>=0;poz--)
    printf("%d",((nr>>poz)&1));
    return 0;
}