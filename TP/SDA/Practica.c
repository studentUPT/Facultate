#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data
{   
    int zi, luna, an, id;
    struct Data *next;
}Data;

typedef struct Persoana
{
    char nume[22];
    int varsta,id;
    struct Data *sublist;
    struct Persoana *next;
}persoana;


persoana *addnode(persoana *head, char *nume, int varsta, int id)
{   persoana *q1, *q2, *aux;
    aux=(persoana*)malloc(sizeof(persoana));
    strcpy(aux->nume, nume);
    aux->varsta=varsta;
    aux->id=id;
    aux->sublist=NULL;
    for(q1=q2=head; q1!=NULL && q1->id>aux->id; q2=q1, q1=q1->next);
    aux->next=q1;
    if(q1==q2)
        head=aux;
    else
        q2->next=aux;  
    return head;    

}
Data* addsubnode(Data *subhead, int zi, int luna, int an, int id){
    Data *q1, *q2, *aux;
    aux=(Data*)malloc(sizeof(Data));
    aux->zi=zi;
    aux->luna=luna;
    aux->an=an;
    aux->id=id;
    for(q1=q2=subhead; q1!=NULL && q1->an>aux->an; q2=q1, q1=q1->next);
    aux->next=q1;
    if(q1==q2)
    subhead=aux;
    else
    q2->next=aux;
    return subhead;
    
}

Data *readsublist(Data *subhead, int id_node)
{
    FILE *f=NULL;
    int zi, luna, an, id;
    Data *d=NULL;
    f=fopen("D:/GitHub/Facultate/TP/SDA/s.txt", "rt");
    if(!f)
    {
        printf("Error subfile\n");
        exit(1);
    }
    else
    {
        while(!feof(f))
        {
            fscanf(f, "%d%d%d%d", &zi, &luna, &an, &id);
            if(id==id_node)
            d=addsubnode(d, zi, luna, an, id);
        }
        fclose(f);
    }
    return d;
}

persoana *read(persoana *head)
{
    FILE *f=NULL;
    int varsta, id=0;
    char nume[20];
    persoana *p;
    Data *d;
    f=fopen("file.txt", "rt");
    if(!f){
        printf("Error file"); exit(1);
    }
    else{
        while (!feof(f))    
        {
            fscanf(f, "%s%d%d", nume, &varsta, &id);
            head=addnode(head, nume, varsta, id);
            d=head->sublist;
            d=readsublist(d, id);
            head->sublist=d;
        }
        fclose(f);
    }
    return head;
}

void show(persoana *head)
{   Data *d;
    persoana *q=head;
    while(q!=NULL)
    {
        printf("\n============\nNume: %s\nVarsta: %d\nID: %d", q->nume, q->varsta, q->id);
        d=q->sublist;
        while (d!=NULL)
        {
            printf("\nzi: %d luna: %d an:%d", d->zi, d->luna, d->an);
            d=d->next;
        }
        q=q->next;
        
    }
}

int main(){
persoana *head = NULL;
Data *subhead=NULL;
head=read(head);
show(head);

return 0;

}