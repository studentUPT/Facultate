#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct info{
    int an, id;
    struct info *next;
}subnode;

typedef struct masina
{
    char producator[22], model[22];
    int id;
    struct masina *next;
    struct info *subnode;
}node;

node *search(node*head, char *prod)
{
    node*q=head;
    while(q!=NULL){
        if(strcmp(q->producator, prod)==0)
        return q;
    }
    return NULL;
}
node*addnode(node*head, char *prod, char *model, int id)
{
    node *q1, *q2, *aux;
    aux=(node*)malloc(sizeof(node));
    strcpy(aux->producator, prod);
    strcpy(aux->model, model);
    aux->id=id;
    aux->subnode=NULL;
    for(q1=q2=head; q1!=NULL && q1->id <aux->id; q2=q1, q1=q1->next);
    aux->next=q1;
    if(q1==q2)
         head=aux;
    else
         q2->next=aux;
    return head;
}
subnode* addsubnode(subnode *subhead, int an, int id)
{
    subnode *q1, *q2, *aux;
    aux=(subnode*)malloc(sizeof(subnode));
    aux->an=an;
    aux->id=id;
    for(q1=q2=subhead; q1!=NULL && q1->an < aux->an; q2=q1, q1=q1->next);
    aux->next=q1;
    if(q1==q2)
    subhead=aux;
    else
    q2->next=aux;
    return subhead;
}
subnode* readsubnode(subnode *subhead,int id_node)
{   subnode* sq;
    FILE *f=NULL;
    int an, id;
    f=fopen("D:/GitHub/Facultate/TP/SDA/info.txt","rt");
    if(!f)
    {
        printf("error subfile");
        exit(1);
    }
    else{
            while (!feof(f))
            {
                fscanf(f, "%d%d", &an, &id);
                if(id==id_node)
                subhead=addsubnode(subhead, an, id);
            }
            fclose(f);
    }
    return subhead;
}
node *readnode(node *head)
{   subnode *subhead=NULL;
node* find=NULL;
    FILE *f=NULL;
    char prod[22], model[22];
    int id;
    f=fopen("D:/GitHub/Facultate/TP/SDA/car.txt", "rt");
    if(!f)
    {
        printf("Error file");
        exit(1);
    }
    else
    {
        while (!feof(f))
        {
            fscanf(f,"%s%s%d", prod, model, &id);
            find=search(head, prod);
            if(find==NULL){
            find=addnode(head, prod, model, id);
            find=search(head, prod);
            }
            find->subnode=readsubnode(find->subnode, id);

        }
        fclose(f);
    }
    return head;
}
void show(node*head)
{
    node *q=head;
    subnode *sq;
    while(q!=NULL)
    {
        printf("\n==========\nProducator : %s\nModel : %s\n", q->producator, q->model);
        sq=q->subnode;
        while(sq!=NULL)
        {
            printf("---------\nAn : %d\n ID : %d",sq->an, sq->id);
            sq=sq->next;
        }
        q=q->next;
    }
}
int main ()
{
    node *head=NULL;
    subnode* subhead=NULL;

    head=readnode(head);
    show(head);

    return 0;
}