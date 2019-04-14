#include <stdio.h>

#include <string.h>

typedef struct {
    char nume[50];
    float pret;
}
Produs;

/*void citire(Produs * prod, int * nr) {

    ( * nr) ++;
    printf("Dati numele produsului: ");
    fflush(stdin);
    gets((prod + * nr) -> nume);
    printf("Dati pretul produsului: ");
    scanf("%g", & prod[ * nr].pret);

}
*/
int citire_duplicat( char produs, Produs * prod, int * nr) {

    int i;
    for (i = 0; i <= * nr; i++) {
        if (strcmp(prod[i].nume, produs) == 0) {
            return i;
        }
    }
    return -1;

}

void afisare(Produs * prod, int nr) {

    printf("\n%10s \t %5.2f",
        (prod + nr) -> nume,
        prod[nr].pret);

}

void cautare(Produs * prod, int * nr, char nu[50]) {

    int i, ok = 0;
    for (i = 0; i <= nr; i++) {
        if (strcmp((prod + i) -> nume, nu) == 0) {
            ok++;
            afisare(prod, i);
        }
    }
    if (!ok) {
        printf("Produsul nu exista!");

    }
}
void stergere(Produs * prod, int * nr, char nu[50]) {

    int i, j;
    for (i = 0; i <= * nr; i++) {
        if (strcmp(prod[i].nume, nu) == 0) {
            ( * nr) --;
            for (j = i++; j <= * nr; j++) {
                prod[j] = prod[j + 1];
            }
            i--;
        }
    }
}
void sortare(Produs * prod, int nr) {

    int i, ok;
    Produs aux;

    do {
        ok = 1;
        for (i = 0; i < nr; i++) {
            if (prod[i].pret < prod[i + 1].pret) {
                ok = 0;
                aux = prod[i];
                prod[i] = prod[i + 1];
                prod[i + 1] = aux;

            }
        }

    } while (!ok);
}


int main() {
    int op = 0, pr,
        n = -1, i, verif;
    char num[20];
    Produs p[20];


    do {
        printf("\n0. Exit");
        printf("\n1. Adaugare");
        printf("\n2. Afisare");
        printf("\n3. Cautare");
        printf("\n4. Stergere");
        printf("\n5. Sortare");
        printf("\nOptiunea aleasa este: ");
        scanf("%d", & op);
        switch (op) {
            case 0:
                return 0;
            case 1:
                getchar();
                printf("Dati produsul: ");
                scanf("%s", num);
                verif = citire_duplicat( num, &p, &n);
                if(verif >=0) {
                    printf("Introduceti pretul nou: ");
                    scanf("%g", &p[verif].pret);
                    n--;
                } else{
                    strcpy(p[n].nume,num);
                    printf("Dati pretul: "); 
                    scanf("%g", &p[n].pret);
                }
                n++;
                
                break;
            case 2:
                for (i = 0; i <= n; i++) {
                    afisare(p, i);
                }
                break;
            case 3:
                getchar();
                printf("Ce produs cautati? ");
                gets(num);
                cautare(p, n, num);
                break;
            case 4:
                printf("Dati produsul pe care doriti sa il stergeti: ");
                scanf("%s", num);
                stergere(p, & n, num);

                break;
            case 5:
                sortare(p, n);
                for (i = 0; i <= n; i++)
                    afisare(p, i);
                break;
            default:
                printf("\n Optiune gresita");
                break;

        }
    } while (op != 0);
}