/*Se citeste valoarea unui nr natural nr. Sa se verifice si sa se afiseze daca nr este sau nu o putere a lui 2
Daca nr este o putere a lui 2, atunci reprezentarea acestuia in baza 2 va avea un singur bit de 1, restul fiind 0, deci am putea numara cati biti de 1 are in baza 2
Exista insa o solutie mai rapida
Aceasta se bazeaza pe ideea ca daca un nr este putere a lui 2, deci de forma 0000000000100000, atunci nr-1 are reprezentarea de forma
0000000000011111, adica bitul 1 s-a transformat in 0,iar bitii de la dreapta sunt toti 1, asadar o expresie care are forma
nr&(nr-1) va furniza rezultatul 0 daca si numai daca nr este o putere a lui 2.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{   int nr;
    printf("dati nr\n");
    scanf("%d",&nr);
    if((nr&nr-1)==0)
        printf("%d este o putere a lui 2",nr);
    else
        printf("%d nu este o putere a lui 2",nr);
    return 0;
}