#include <stdio.h>

#include <string.h>

typedef struct {
    char nume[80],
        data_n[15];
}
elev;

void citire(elev * e, int * nr) {

    ( * nr) ++;

    printf("Dati numele elevului: ");
    fflush(stdin);
    gets(e[ * nr].nume);
    printf("Dati data nasterii: ");
    gets(e[ * nr].data_n);
}

void afisare(elev * e, int nr) {

    printf("\n%5s \t %5s",
        e[nr].nume,
        e[nr].data_n
    );
}
void sortare(elev * e, int nr) {

    int i, ok;
    elev aux;

    do {
        ok = 1;
        for (i = 0; i < nr; i++) {
            if (strcmp(e[i].nume, e[i + 1].nume) > 0) {

                aux = e[i];
                e[i] = e[i + 1];
                e[i + 1] = aux;
                ok = 0;

            }
        }
    } while (ok != 0);
}

int main() {
    int op = 0,
        n = -1, i;
    elev e[80];


    while (1) {

        printf("\n0. Exit");
        printf("\n1. Adaugare");
        printf("\n2. Afisare");
        printf("\n3. Sortare");
        printf("\nOptiunea aleasa este: ");
        scanf("%d", &op);
        switch (op) {
            case 0:
                return 0;
            case 1:
                citire( & e[0], &n);
                break;
            case 2:
                for (i = 0; i <= n; i++) {
                    afisare(e, i);
                }
                break;
            case 3:
                sortare(e, n);
                break;
            default:
                printf("Optiune gresita!\n ");
                break;

        }
    }

}