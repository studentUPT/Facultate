#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 30

typedef struct list {
    char adr[MAX];
    int nr;
    struct list * urm;
} nod;

nod * email = NULL;

nod * adauga (nod * lista, char * nume, int nr_ori) {
    nod *q1, *q2,
        *aux;
    aux = (nod *) malloc (sizeof (nod));
    strcpy(aux -> adr, nume);
    aux -> nr = nr_ori;
    aux -> urm = NULL;
    for (q1 = q2 = lista; q1 != NULL && (strcmp(q1 -> adr, aux -> adr) < 0); q2 = q1, q1 = q1 -> urm);
    if (q1 == q2) {
        aux -> urm = lista;
        lista = aux;
    } else {
        q2 -> urm = aux;
        aux -> urm = q1;
    }
    return lista;
}

void citire () {
    char nume[MAX];
    int nr_ori;
    FILE * f;

    f = fopen("SDA/TEST/e_mail.txt", "rt");
    while (!feof(f)) {
        fscanf(f, "%s %d", nume, &nr_ori);
        email = adauga(email, nume, nr_ori);
    }
    fclose(f);
}

void afisare (nod * lista) {
    nod * q;
    for (q = lista; q != NULL; q = q -> urm) {
        printf("\n%s %d",
            q -> adr,
            q -> nr
        );
    }
}

void filtrare (nod * lista) {
    nod * q;
    for (q = lista; q != NULL; q = q -> urm) {
        if(q->nr >= 3)
            printf("\n%s",
                q->adr
            );
    }
}

nod *stergere(nod * lista){
    nod *q1, *q2;
    char x[MAX];
    printf("\n Adresa cautata:");
    scanf("%s", x);
    for (q1 = q2 = lista; q1 != NULL && (strcmp(q1 -> adr, x)); q2 = q1, q1 = q1 -> urm);
    if (q1 != NULL && strcmp(q1 -> adr, x) == 0) {
        if (q1 == q2) {
            lista = lista -> urm;
        } else {
            q2 -> urm = q1 -> urm;
            free(q1);
        }
    }
    
    return lista;
}


int main() {
    citire();
    afisare(email);
    printf("\n sunt o tarfa de program");
    filtrare(email);
    printf("\n sunt o tarfa de program");
    email = stergere(email);
    afisare(email);
    return 0;
}
