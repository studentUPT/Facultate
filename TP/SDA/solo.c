#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void errorread(void){ printf("\nThe file was'n read"); exit(1);}

typedef struct sublista
{
   char locatie[20], agentie[20];
   int pret;
   struct sublista *next;
}subnode;

typedef  struct lista
{
   char tara[20];
   struct lista *next;
   struct sublista *subnode;
}node;

node *srchname(node *head, char *tara){
   node *q=head;
   while (q!=NULL&&strcmp(q->tara, tara))
   q=q->next;
   if(q!=NULL && (strcmp(q->tara, tara)==0))
   return q;
   return NULL;
}

node* addnode(node *head, char *tara)
{  node *q1, *q2, *aux;
   aux=(node*)malloc(sizeof(node));
   strcpy(aux->tara, tara);
   for(q1=q2=head; q1!=NULL && (strcmp(q1->tara, aux->tara)<0); q2=q1, q1=q1->next);
   aux->next=q1;
   if(q1==q2)
   return aux;
   else
   q2->next=aux;
   return head;

}

subnode *addsubnode(subnode *head, char *loc, char *agent, int pret)
{
   subnode *q1, *q2, *aux;
   aux=(subnode*)malloc(sizeof(subnode));
   strcpy(aux->locatie, loc);
   strcpy(aux->agentie, agent);
   aux->pret=pret;
   for(q1=q2=head; q1!=NULL&& (aux->pret < q1->pret); q2=q1, q1=q1->next);
   aux->next=q1;
   if(q1==q2)
   return aux;
   else 
   q2->next=aux;
   return head;
}
node *readlist(node* head){
   node *list;
   FILE *f;
   char tara[20], loc[20], agent[20];
   int pret;
   f=fopen("D:/GitHub/Facultate/TP/SDA/Fisier.txt", "rt");
   if(!f) errorread();
   else{
      while(!feof(f)){
         fscanf(f,"%s%s%s%d", tara, loc, agent, &pret);
         if(head==NULL)
         head=addnode(head,tara);
         else{
         list=srchname(head, tara);

         if(list==NULL){
            list=addnode(head, tara);
            list->subnode=addsubnode(list->subnode, loc, agent, pret);
         }
         else{
            list->subnode=addsubnode(list->subnode, loc, agent, pret);
         }

      }
      }
      fclose(f);
   }
   return head;
   
}

void show(node *head)
   {     node *q=head;
      subnode*qs;
         printf("\nTara: \n\t Locatie Agentie Pret");
            while(q!=NULL){
                printf("\n%s", q->tara);
                qs=q->subnode;
                   while(qs!=NULL){
                        printf("\n\t%s %s %d", qs->locatie, qs->agentie, qs->pret);
                        qs=qs->next;
                      }
             q=q->next;
            }

   }
int main() 
{ 
   node *head=NULL;
   head=readlist(head);
   show(head);
return 0;
}