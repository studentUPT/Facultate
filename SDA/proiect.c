#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 30
#define DIM2 15

/*
Definirea structurilor aferente pentru listele de pacienti
cu sublistele de afectiuni
*/

typedef struct afect {
    int afect_nr;
    char afect_nume[DIM];
    char afect_data_prezentare_medic[DIM];
    struct afect* afect_urm;
}afect;

typedef struct pacient{
    int pacient_nr;
    char pacient_nume[DIM];
    char pacient_prenume[DIM];
    char pacient_cnp[DIM2];
    char pacient_data_nastere[DIM2];
    char pacient_adresa[2*DIM];
    afect* pacient_afect;
    struct pacient* pacient_urm;
}pacient;


afect* afect_adaugare(afect *rad, int nr_af, char* nume_af, char* data_prez) { //Functie pentru adaugarea unei afectiuni noi in sublista cu afectiuni
    afect *aux, *q1, *q2;
    aux = (afect*)malloc(sizeof(afect)); //alocare dinamica pt nod de tip afectiune
    //copierea informatiilor de adaugat in nodul aux
    aux->afect_nr = nr_af;
    strcpy(aux->afect_nume, nume_af);
    strcpy(aux->afect_data_prezentare_medic, data_prez);
    //Adaugarea nodului nou folosind tehnica celor doi pointeri
    for (q1 = q2 = rad; q1 != NULL && strcmp(q1->afect_data_prezentare_medic, data_prez) == 1; q2 = q1, q1 = q1->afect_urm);
    if (q1 == q2) {
        aux->afect_urm = q1;
        rad = aux;
    } else {
        q2->afect_urm = q1;
        rad = aux;
    }
    return rad;
}

afect* afect_cautare(afect* rad, char* nume_af) { //Functie care cauta daca exista deja afectiunea
    afect* q;
    for(q = rad; q != NULL && strcmp(q->afect_nume, nume_af);q=q->afect_urm);
    return q;
}

pacient* pacient_adaugare(pacient *rad, int nr_pac, char* nume_pac, char* prenume_pac, char* cnp_pac, char* data_nastere, char* adr_pac) { //Functie pentru adaugarea unui nou pacient in lista cu pacienti
    pacient *aux, *q1, *q2;
    //Alocare dinamica pt nod de tip pacient
    aux = (pacient*)malloc(sizeof(pacient));
    //Copierea informatiilor de adaugat in nodul aux
    aux->pacient_nr = nr_pac;
    strcpy(aux->pacient_nume, nume_pac);
    strcpy(aux->pacient_prenume, prenume_pac);
    strcpy(aux->pacient_cnp, cnp_pac);
    strcpy(aux->pacient_adresa, adr_pac);
    strcpy(aux->pacient_data_nastere, data_nastere);
    aux->pacient_afect = NULL;
    //Adaugare folosind tehnica celor doi pointeri
    for(q1 = q2 = rad; q1!=NULL && strcmp(q1->pacient_nume, nume_pac) == -1 || (q1 != NULL && strcmp(q1->pacient_nume, nume_pac) == 0 && strcmp(q1->pacient_prenume, prenume_pac) == -1); q2 = q1, q1 = q1->pacient_urm);
    if (q1 == q2) {
        aux->pacient_urm = q1;
        rad = aux;
    } else {
        q2->pacient_urm = aux;
        aux->pacient_urm = q1;
    }
    return rad;
}

pacient* pacient_cautare(pacient* rad, char* nume_pac, char *prenume_pac) { //Functie care cauta daca exista deja pacientul in lista
    pacient* q;
    for (q = rad; q!=NULL && strcmp(q->pacient_nume, nume_pac) || (q!=NULL && strcmp(q->pacient_nume, nume_pac) == 0 && strcmp(q->pacient_prenume, prenume_pac)); q = q->pacient_urm);
    return q;
}

afect* afect_citire(afect* rad, int nr_pacient) { //Functie care citeste si adauga afectiunile in sublista cu afectiuni
    char nume_af[DIM], data_prez_med[DIM];
    int nr_af, nr_pac;
    FILE *g = NULL;
    g = fopen("afectiuni.txt", "rt");
    while(!feof(g)) {
        fcsanf(g, "%d %d %s %s", &nr_pac, &nr_af, &nume_af, &data_prez_med);
        if(nr_pac==nr_pacient) {
            if(afect_cautare(rad, nume_af) == NULL)
                rad = afect_adaugare(rad, nr_af, nume_af, data_prez_med);
        }
    }
    fclose(g);
    return rad;
}

pacient* pacient_citire(pacient* rad) {
    FILE *f=NULL, *g=NULL;
    int nr_pac;
    char nume_pac[DIM], pren_pac[DIM], cnp_pac[DIM2], data_n_pac[DIM2], adr_pac[2*DIM];
    pacient* q2; afect* q1;
    f = fopen("pacienti.txt", "rt");
    g = fopen("afectiuni.txt", "rt");
    if (f!=NULL && g!=NULL) {
        fclose(g);
        while(!feof(f)) {
            fscanf(f, "%d %s %s %s %s %s", &nr_pac, &nume_pac, &pren_pac, &cnp_pac, &data_n_pac, &adr_pac);
            if(pacient_cautare(rad, nume_pac, pren_pac) == NULL)
                rad = pacient_adaugare(rad, nr_pac, nume_pac, pren_pac, cnp_pac, data_n_pac, adr_pac);
                q2 = pacient_cautare(rad, nume_pac, pren_pac);
                q1 = q2->pacient_afect;
                q1 = afect_citire(q1, nr_pac);
                q2->pacient_afect = q1;
        }
        fclose(f);
    } else {
        printf("\nNu au fost gasite fisierele aferente!");
        if(f!=NULL) fclose(f);
        if(g!=NULL) fclose(g);
    }
    return rad;
}

int main()
{

    return 0;
}