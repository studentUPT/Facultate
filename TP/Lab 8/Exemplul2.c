#include <stdio.h>
#include <stdlib.h>
//DEFINESC O FUNCTIE cu un parametru int care e void
void tip_void_un_param(int nr){

}
    //definesc o functie cu un parametru de tip int,dar care returneaza int
    int tip_int_un_param(int nr){
    return 0;
}
//definim o functie cu doi parametrii de tip int
void tip_void_doi_param(int nr,int nr1){
}
int main(void)
{
    //definim un pointer la functii cu un parametru int
    void (*un_pointer) (int nr);
    //este permis sa atribuim pointerului adresa primei functii
    un_pointer=&tip_void_un_param;
    //nu este permis sa atribuim pointerului adresa celei de-a doua functii,
    //deoarece functia a doua returneaza tip int, iar pointerul indica spre functii ce returneaza void
    //daca decomentati linia de mai jos, veti primi mesaj de avertizare de la compilator
    //un_pointer=&tip_int_un_param;
    /* Nu este permis sa atribuim pointerului nici adresa celei de-a treia functii,
    deoarece functia a treia are doi parametrii,in timp ce pointerul indica spre functii cu un
    singur parametru de tip int
    Daca decomentati linia de mai jos, veti primi mesaj de avertizare de la compilator
    */
    //un_pointer=&tip_void_doi_param;
    return 0;
}