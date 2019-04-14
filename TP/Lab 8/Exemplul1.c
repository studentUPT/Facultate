#include <stdio.h>
#include <stdlib.h>
//Definim doua functii cu doi parametriide tip int si care sunt void
void f1(int n1, int n2)
{
    printf("O functie care are doi parametrii de tip int: %d si %d\n",n1,n2);
}
void f2(int n3, int n4)
{
    printf("O functie care are doi parametrii de tip int: %d si %d\n",n3,n4);
}
int main(void)
{ //definesc un pointer la functii cu doi parametrii de tip int
    //numele parametrilor nu este relevant (este formal), conteaza doar tipul lor
    void (*un_pointer) (int x,int y);
    //atribuie pointerului adresa orimei functii
    un_pointer=&f1;
    //invocam prima functie direct
    f1(100,200);
    //invocam prima functie prin intermediul poiterului. In loc de numele functiei, folosim operatorul *
        (*un_pointer) (300,400);
    //atribuim pointerului adresa celei de-a doua functii
      un_pointer=&f2;
        //invocam a doua functie direct
    f2(500,600);
        //invocam a doua functie prin intermediul poiterului.
        (*un_pointer) (700,800);
        return 0;
}