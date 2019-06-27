#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct agentie {
	char nume_agentie[20], localitate[20];
	int pret;
	struct agentie* urm1; //sau agentie? nu cred..
}sublista;

typedef struct tara {
	char nume_tara[20];
	sublista* prim1;
	struct nod* urm;
}nod;

sublista* agentie = NULL;
nod* prim = NULL;

sublista* adauga_agentie(sublista* agentie, char ag[20], char local[20], int pr) {
	sublista* q1, *q2, *p;
	p = (sublista*)malloc(sizeof(sublista));
	strcpy(p->nume_agentie, ag);
	strcpy(p->localitate, local);
	p->pret = pr;
	p->urm1 = NULL;
	for (q1 = q2 = agentie; q1 != NULL && (q1->pret < p->pret); q2 = q1, q1 = q1->urm1);
	p->urm1 = q1;
	if (q1 == q2)
		return p;
	else {
		q2->urm1 = p;
		return agentie;
	}
}

nod* adauga_tara(nod* prim, char num[20]) {
	nod* q1, *q2, *p;
	p = (nod*)malloc(sizeof(nod));
	p->urm = NULL;
	p->prim1 = NULL;
	strcpy(p->nume_tara, num);
	for (q1 = q2 = prim; q1 != NULL && strcmp(q1->nume_tara, p->nume_tara) < 0; q2 = q1, q1 = q1->urm);
	p->urm = q1;
	if (q1 == q2)
		return p;
	else {
		q2->urm = p;
		return prim;
	}
}

void afisare(nod* prim) {
	nod* q;
	sublista* p;
	for (q = prim; q != NULL; q = q->urm) {
		printf("\n%s:\n", q->nume_tara);
		for (p = q->prim1; p != NULL; p = p->urm1)
			printf("%s\t%s\t%d\n", p->nume_agentie, p->localitate, p->pret);
	}
}


nod* cauta_tara(nod* prim, char num[20]) {
	nod* q;
	for (q = prim; q != NULL && strcmp(q->nume_tara, num) != 0; q = q->urm);
	if (q != NULL && strcmp(q->nume_tara, num) == 0)
		return q;
	return NULL;
}

nod* citire_fisier(nod *prim) {
	nod* pac;
	char num[20], ag[20], local[20];
	int pr;
	FILE* f;
	//f = fopen("oferte.txt", "rt");
	if ((f = fopen("Fisier.txt", "rt")) == NULL) {
		printf("Fisierul nu poate fi deschis. ");
		exit(EXIT_FAILURE);
	}
	else {
		while (!feof(f)) {
			fscanf(f, "%s %s %s %d", num, ag, local, &pr);
			if ((pac = cauta_tara(prim, num)) == NULL) {
				prim = adauga_tara(prim, num);
				pac = cauta_tara(prim, num);
			}
			pac->prim1 = adauga_agentie(pac->prim1, ag, local, pr);
		}
		fclose(f);
	}
	return prim;
}

int main() {
	nod* prim = NULL;
	prim = citire_fisier(prim);
	afisare(prim);
	return 0;
}