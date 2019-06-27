#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct Data
{
	int zi, luna, an, id;
	struct Data *next;
}Data;


typedef struct Persoana
{
	char nume[22];
	int varsta, id;
	struct Data *sublist;
	struct Persoana *next;
}persoana;

persoana *search(persoana *head, int id)
{
	persoana *q = head;
	while (q != NULL) {
		if (q->id == id)
			return q;
		q = q->next;
	}
	return NULL;
}

persoana *addnode(persoana *head, char *nume, int varsta, int id)
{
	persoana *q1, *q2, *aux;
	aux = (persoana*)malloc(sizeof(persoana));
	strcpy(aux->nume, nume);
	aux->varsta = varsta;
	aux->id = id;
	aux->sublist = NULL;
	for (q1 = q2 = head; q1 != NULL && q1->id < aux->id; q2 = q1, q1 = q1->next);
	aux->next = q1;
	if (q1 == q2)
		head = aux;
	else
		q2->next = aux;
	return head;

}
Data* addsubnode(Data *subhead, int zi, int luna, int an, int id) {
	Data *q1, *q2, *aux;
	aux = (Data*)malloc(sizeof(Data));
	aux->zi = zi;
	aux->luna = luna;
	aux->an = an;
	aux->id = id;
	for (q1 = q2 = subhead; q1 != NULL && q1->an < aux->an; q2 = q1, q1 = q1->next);
	aux->next = q1;
	if (q1 == q2)
		subhead = aux;
	else
		q2->next = aux;
	return subhead;

}

Data *readsublist(Data *subhead, int id_node)
{
	FILE *f = NULL;
	int zi, luna, an, id;
	Data *d = NULL;
	f = fopen("D:/GitHub/Facultate/TP/SDA/s.txt", "rt");
	if (!f)
	{
		printf("Error subfile\n");
		exit(1);
	}
	else
	{
		while (!feof(f))
		{
			fscanf(f, "%d%d%d%d", &zi, &luna, &an, &id);
			if (id == id_node)
				d = addsubnode(d, zi, luna, an, id);
		}
		fclose(f);
	}
	return d;
}

persoana *read(persoana *head)
{
	FILE *f = NULL;
	int varsta, id = 0;
	char nume[20];
	persoana *p;
	Data *d = NULL;
	f = fopen("D:/GitHub/Facultate/TP/SDA/file.txt", "rt");
	if (!f) {
		printf("Error file"); exit(1);
	}
	else {
		while (!feof(f))
		{
			fscanf(f, "%s%d%d", nume, &varsta, &id);
			head = addnode(head, nume, varsta, id);
			p = search(head, id);
			if(p!=NULL)
				p->sublist =readsublist(p->sublist, id);
			
			
		}
		fclose(f);
	}
	return head;
}

void show(persoana *head)
{
	Data *d;
	persoana *q = head;
	while (q != NULL)
	{
		printf("\n============\nNume: %s\nVarsta: %d\nID: %d", q->nume, q->varsta, q->id);
		d = q->sublist;
		while (d != NULL)
		{
			printf("\nzi: %d luna: %d an:%d", d->zi, d->luna, d->an);
			d = d->next;
		}
		q = q->next;

	}
}
persoana * deletenode(persoana *head, char *nume)
{
	persoana *p, *q = head;
	while (q != NULL) {
		if (!strcmp(head->nume, nume)) {
			q = head->next;
			free(head);
			return q;
		}
		else
			if (!strcmp(q->nume, nume)) {
			p = q->next;
			q->next = q->next->next;
			free(p);
			p = NULL;
			return head;
			}
		q = q->next;
	}
}
void printbyid(persoana *head, int  id) {
	persoana *q = head;
	Data *qs;
	while (q) {
		if (q->id == id) {
			printf("\nNUME: %s \n\t VARSTA: %d ID: %d", q->nume, q->varsta, q->id);
			qs = q->sublist;
			while (qs) {
				printf("\n\t\tZI: %d LUNA: %d AN: %d ", qs->zi, qs->luna, qs->an);
				qs = qs->next;
			}
		}
		q = q->next;
	}


}
int main() {
	persoana *head = NULL;
	Data *subhead = NULL;
	head = read(head);
	show(head);
	printbyid(head, 1);
	
	head = deletenode(head, "igor");
	show(head);

	_getch();
	return 0;

}