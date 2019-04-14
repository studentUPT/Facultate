#include <stdio.h>
#include <stdlib.h>
void alta_functie(int *parametru)
{
    printf("In functie, la inceput: %p\n",parametru);
    //modificam parametrul
    parametru=(int *)malloc (sizeof(int));
    printf("In functie, la final: %p\n",parametru);
}
int main(void)
{   int *variabila;
    variabila=(int *)malloc (sizeof(int));
    //apelam functia
    alta_functie(variabila);
    printf("Dupa apelul functiei %p\n",variabila);
    free(variabila);
    return 0;
}