#include <stdio.h>
/*Definim patru functii fara parametru care returneaza void
Fiecare functie afiseaza cate un caracter pe ecran. */

void stea(void)
{
    printf("*");
}

void plus(void)
{
    printf("+");
}

void minus(void)
{
    printf("-");
}
void dolar(void)
{
    printf("$");
}

int main(void)
{
    int i;
    void (*p[4])(void);
    /*Initializam vectorul cu adresele celor patru functii.*/
    p[0] = &stea;
    p[1] = &plus;
    p[2] = &minus;
    p[3] = &dolar;
    /*Folosim vectorul de pointeri pentru a apela pe rand functiile. */
    for (i = 0; i < 4; i++)
        (*p[i])();
    /*Apelam functiile in ordine inversa, folosind din nou vectorul de functii.*/
    for (i = 3; i >= 0; i--)
        (*p[i])();
    return 0;
}