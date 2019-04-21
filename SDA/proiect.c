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
    //Se verifica daca nu exista numele sau daca exista numele, dar nu exista prenumele
    for (q = rad; q!=NULL && strcmp(q->pacient_nume, nume_pac) || (q!=NULL && strcmp(q->pacient_nume, nume_pac) == 0 && strcmp(q->pacient_prenume, prenume_pac)); q = q->pacient_urm);
    //Returneaza NULL daca nu exista perechea (Nume Prenume) in lista
    return q;
}

afect* afect_citire(afect* rad, int nr_pacient) { //Functie care citeste afectiunile
    char nume_af[DIM], data_prez_med[DIM];
    int nr_af, nr_pac;
    FILE *g = NULL;
    g = fopen("afectiuni.txt", "rt");
    while(!feof(g)) {
        fscanf(g, "%d %d %s %s", &nr_pac, &nr_af, &nume_af, &data_prez_med);
        if(nr_pac==nr_pacient) {
            if(afect_cautare(rad, nume_af) == NULL)
                rad = afect_adaugare(rad, nr_af, nume_af, data_prez_med);
        }
    }
    fclose(g);
    return rad;
}

/* Functia pacient_citire ->
Incarca informatiile despre pacienti intr-o baza de date reprezentata sub forma unui lista
cu subliste. Daca baza de date a fost initializata deja se afiseaza un mesaj de
atentionare.
*/
pacient* pacient_citire(pacient* rad) { //Functie care citeste un pacient si ii adauga toate afectiunile din fisierul "afectiuni.txt" 
    FILE *f=NULL, *g=NULL;
    int nr_pac;
    char nume_pac[DIM], pren_pac[DIM], cnp_pac[DIM2], data_n_pac[DIM2], adr_pac[2*DIM];
    pacient* q2; afect* q1;
    f = fopen("pacienti.txt", "rt");
    g = fopen("afectiuni.txt", "rt");
    if (f!=NULL && g!=NULL) {
        fclose(g);
        while(!feof(f)) {
            //Citeste datele din fisierul "pacienti.txt"
            fscanf(f, "%d %s %s %s %s %s", &nr_pac, &nume_pac, &pren_pac, &cnp_pac, &data_n_pac, &adr_pac);
            //Cauta daca exista deja pacientul in lista
            if(pacient_cautare(rad, nume_pac, pren_pac) == NULL) {
                //Daca nu exista, il adauga in lista
                rad = pacient_adaugare(rad, nr_pac, nume_pac, pren_pac, cnp_pac, data_n_pac, adr_pac);
            }
            //Daca a existat, il cautam in lista pentru a vedea daca a avut afectiuni in trecut, pentru a le adauga in continuare
            q2 = pacient_cautare(rad, nume_pac, pren_pac);
            //Ii adauga afectiunile de care a suferit de-a lungul timpului
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

/* Functia afisare_punct2 ->
Tipareste in ordine alfabetica toti pacientii acestui medic de familie si afectiunile de care
ei au suferit de-a lungul timpului, in ordine invers cronologica.
*/
void afisare_punct2(pacient* rad) { 
    afect* q1;
    pacient* q2;
    for(q2 = rad; q2!=NULL; q2 = q2->pacient_urm) {
        //Se afiseaza datele pacientului
        printf("\t%d. %s %s, CNP:%s, Data Nasterii:%s, Adresa:%s", q2->pacient_nr, q2->pacient_nume, q2->pacient_prenume, q2->pacient_cnp, q2->pacient_data_nastere, q2->pacient_adresa);
        for (q1=q2->pacient_afect; q1!=NULL; q1 = q1->afect_urm) {
            //Se afiseaza fiecare afectiune in decursul anilor
            printf("\n\t - %d. %s ; %s", q1->afect_nr, q1->afect_nume, q1->afect_data_prezentare_medic);
        }
        printf("\n");
    }
}

/* Functia afisare_punct3 ->
Afiseaza numele pacientilor ce au suferit de o anumita afectiune (afectiunea se citeste de
la tastatura)
*/
void afisare_punct3(pacient* rad) {
    afect* q1;
    pacient* q2;
    char nume_afec[DIM];
    printf("Dati numele afectiunii: "); scanf("%s", &nume_afec);
    //Se parcurge lista si se verifica daca una dintre afectiunile de care a suferit pacientul coincide cu cea citita de la tastatura
    for (q2 = rad; q2!=NULL; q2 = q2->pacient_urm) {
        q1 = q2->pacient_afect;
        if(afect_cautare(q1, nume_afec) != NULL)
            printf("\n - %s %s", q2->pacient_nume, q2->pacient_prenume);
    }
}

/* Functia pacient_stergere ->
Sterge un anumit pacient, datorita mutarii sale la un alt medic de familie
*/
pacient* pacient_stergere(pacient* rad) {
    pacient *q1, *q2;
    char nume_pac[DIM], pren_pac[DIM];
    printf("\nIntroduceti numele pacientului:"); scanf("%s", &nume_pac);
    printf("\nIntroduceti prenumele pacientului:");  scanf("%s", &pren_pac);
    if(pacient_cautare(rad, nume_pac, pren_pac) != NULL) {
        //
        for (q1 = q2 = rad; q1!=NULL && strcmp(q1->pacient_nume, nume_pac) || (q1!=NULL && strcmp(q1->pacient_nume, nume_pac) == 0 && strcmp(q1->pacient_prenume, pren_pac)); q2 = q2, q1 = q1->pacient_urm);
        if(q1==q2) {
            rad = rad->pacient_urm;
        } else {
            q2->pacient_urm = q1->pacient_urm;
        }
        free(q1);
        printf("\nPacientul a fost sters!");
    } else printf("\nPacientul nu se afla in lista!");
    return rad;
}

/* Functia pacient_tratare ->
Tratare pacient – introducere de la tastatura a infomatiilor unui pacient care tocmai s-a
prezentat la medic. Daca pacientul tratat nu se afla in lista pacientilor el este adaugat.
*/
int pacient_nr_max(pacient* rad) { //Functie care preia indicele ultimului pacient din lista, pentru a adauga pacienti cu numar UNIC
    pacient* q;
    int mx=0;
    for(q = rad; q!=NULL; q = q->pacient_urm)
        if(q->pacient_nr > mx) 
            mx = q->pacient_nr;
    return mx;
}
pacient* pacient_tratare(pacient* rad) {
    afect* q1; pacient* q2;
    int nr_af, nr_pac, opt = -1;
    char nume_af[DIM], data_prez_med[DIM], nume_pac[DIM], pren_pac[DIM], cnp_pac[DIM2], data_n_pac[DIM2], adr_pac[2*DIM];
    printf("\nIntroduceti numele pacientului:"); scanf("%s", &nume_pac);
    printf("\nIntroduceti prenumele pacientului:"); scanf("%s", &pren_pac);
    if (pacient_cautare(rad, nume_pac, pren_pac) != NULL)
        printf("\nPacientul se afla deja in lista!");
    else {
        nr_pac = pacient_nr_max(rad) + 1;
        printf("\nIntroduceti CNP-ul pacientului:"); scanf("%s", &cnp_pac);
        printf("\nIntroduceti data de nastere a pacientului:"); scanf("%s", &data_n_pac);
        printf("\nIntroduceti adresa pacientului:"); scanf("%s", &adr_pac);
        rad = pacient_adaugare(rad, nr_pac, nume_pac, pren_pac, cnp_pac, data_n_pac, adr_pac);
        q2 = pacient_cautare(rad, nume_pac, pren_pac);
        q1 = q2->pacient_afect;
        do {
            printf("\nDoriti sa adaugati o afectiune?");
            printf("\n1. Da");
            printf("\n2. Nu"); scanf("%d", &opt);  
            if(opt == 1) {
                printf("\nIntroduceti numele afectiunii:"); scanf("%s", &nume_af);
                if (afect_cautare(q1, nume_af) == NULL) {
                    printf("\nIntroduceti numarul afectiunii:"); scanf("%d", &nr_af);
                    printf("\nIntroduceti data prezentarii la medic (aaaa.ll.zz):"); scanf("%s", &data_prez_med);
                    q1 = afect_adaugare(q1, nr_af, nume_af, data_prez_med);
                } else printf("\nAfectiunea se afla deja in lista!\n");
            }
            else if(opt!=2) printf("\nOptiunea nu este valida!\n");
        } while(opt!=2);
        q2->pacient_afect = q1;
    }
    return rad;
}

/* Functia afisare_punct6 ->
Listare pacienti tratati intr-o anumita periada citita de la tastatura.
*/
void afisare_punct6(pacient* rad) {
    afect* q1; pacient* q2;
    int k;
    char per1[DIM2], per2[DIM2];
    printf("\nIntroduceti data inceperii perioadei (aaaa.ll.zz): "); scanf("%s", &per1);
    printf("\nIntroduceti data sfarsirii perioadei (aaaa.ll.zz): "); scanf("%s", &per2);
    for(q2 = rad; q2!=NULL; q2 = q2->pacient_urm) {
        k = 0;
        for (q1 = q2->pacient_afect; q1!=NULL; q1 = q1->afect_urm)
            if (strcmp(per1, q1->afect_data_prezentare_medic) <= 0 && strcmp(per2, q1->afect_data_prezentare_medic) >= 0)
                    k=1;
        if(k==1)
            printf("\n %s %s", q2->pacient_nume, q2->pacient_prenume);
    }
}

/* Functia actualizare ->
Actualizare continut fisiere.
*/
void actualizare(pacient* rad) {
    afect* q1;
    pacient* q2;
    FILE *f=NULL, *g=NULL;
    f = fopen("pacienti1.txt", "wt");
    g = fopen("afectiuni1.txt", "wt");
    for (q2 = rad; q2 != NULL; q2 = q2->pacient_urm) {
        fprintf(f, "%d %s %s %s %s %s \n", q2->pacient_nr, q2->pacient_nume, q2->pacient_prenume, q2->pacient_cnp, q2->pacient_data_nastere, q2->pacient_adresa);
        for (q1 = q2->pacient_afect; q1 != NULL; q1 = q1->afect_urm)
            fprintf(g, "%d %d %s %s \n", q2->pacient_nr, q1->afect_nr, q1->afect_nume, q1->afect_data_prezentare_medic);
    }
    fclose(f); fclose(g);
    printf("\nDatele au fost actualizate cu succes in fisierele aferente!");
}
int main()
{
    pacient* lista = NULL;
    int opt;
    do {
        printf("\n\nMeniu \n");
	    printf("\n1. Incarcare date din fisierele aferente ");
        printf("\n2. Afisare pacienti in ordine alfabetica ");
        printf("\n3. Afisare pacientilor ce sufera de o anumita afectiune ");
        printf("\n4. Stergere pacient ");
        printf("\n5. Adauga pacient, daca acesta nu se afla in datele incarcate ");
        printf("\n6. Afisare pacienti dintr-o anumita perioada ");
        printf("\n7. Incarcare date in fisierele aferente ");
        printf("\n8. Iesire");
        printf("\nIntroduceti optiunea : "); scanf("%d",&opt);
        if (opt==1) {
            if (lista == NULL) {
                lista = pacient_citire(lista);
                if (lista != NULL) printf("\nPacientii au fost adaugati in lista!");
            } else printf("\nPacientii au mai fost incarcati o data!");
        } else if (opt==2) {
            if (lista!=NULL) 
                afisare_punct2(lista);
            else printf("\nNu au fost adaugati pacientii!");
        } else if (opt==3) {
            if (lista!=NULL) {
                afisare_punct3(lista);
            } else printf("\nNu au fost adaugati pacientii!");
        } else if (opt==4) {
            if (lista!=NULL) {
                lista = pacient_stergere(lista);
            } else printf("\nNu au fost adaugati pacientii!");
        } else if (opt==5) {
            if (lista!=NULL) {
                lista = pacient_tratare(lista);
            } else printf("\nNu au fost adaugati pacientii!");
        } else if (opt==6) {
            if (lista!=NULL) {
                afisare_punct6(lista);
            } else printf("\nNu au fost adaugati pacientii!");
        } else if (opt==7) {
            if (lista!=NULL) {
                actualizare(lista);
            } else printf("\nNu au fost adaugati pacientii!");
        } else if (opt<1 && opt>8) printf("\nOptiunea este invalida!");
    } while(opt!=8);
    return 0;
}