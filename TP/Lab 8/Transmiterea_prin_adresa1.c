#include <stdio.h>
#include <stdlib.h>
void o_functie (int parametru)
{
    //afisam valoarea parametrului la inceoutul functiei
    printf("In functie, la inceput %d\n", parametru);
    //modificam parametrul in interiorul functiei
    parametru++;
    //afisam inca o data parametrul la finalul functiei
    printf("In functie, la final %d\n", parametru);
}
int main(void)
{   int variabila=100;
//afisam variabila inainte de apelul functiei
    printf("Inainte de apelul functiei %d\n",variabila);
    //apelam functia
    o_functie(variabila);
    //afisam variabila dupa apelul functiei
    printf("Dupa apelul functiei%d",variabila);
    return 0;
}