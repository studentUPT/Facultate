#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void citeste(char **nume,int *varsta){
  char s[50]; int nr=0;
  printf("Introduceti numele: ");
  scanf("%40s",s);
   printf("Introduceti varsta: "); 
   scanf("%d",&nr);
    *varsta=nr;
}
void scrie(char *nume,int varsta)
{
    printf("%s,%d\n",nume,varsta);
}
int main(void)
{   char *nume;
    int varsta;
    citeste(&nume,&varsta);
    scrie(nume,varsta);
    free(nume);

    return 0;
}