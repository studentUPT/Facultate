/*	O matrice rară (cu circa 90% din elemente 0) este păstrată economic sub forma unei structuri, care conţine următoarele câmpuri: 
a.	int l,c - numărul de linii/coloane al matricei rare 
b.	int n - numărul de elemente nenule 
c.	int linii[] - vectorul ce păstrează liniile în care se află elemente nenule 
d.	int coloane[] - vectorul ce păstrează coloanele în care se află elemente nenule 
e.	float nenul[] - vectorul ce păstrează elementele nenule 
Să se definească funcţii pentru: 
a.	citirea unei matrici rare 
b.	afişarea unei matrici rare (ca o matrice, cu tot cu zerouri) 
c.	adunarea a două matrici rare. */


 #include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define N 30
typedef struct {
int lines,columns;
float elements;
}element;
typedef struct {
int l,c,n,linii[N],coloane[N];
float nenul[N];
}matrice;
element el[N];
element el0[N];
void citire_mat(matrice m)
{
    int n=0,i=0,j=0,count=0,index=-1,ok=0,aux;
    float e;
    printf("Introduceti %d elemente:\n",m.l*m.c);
    while(ok<m.l*m.c)
    {
        scanf("%f",&e);
        ok++;
        if(e==0) {
            count++;
            if(j<=m.c && i<=m.l && j!=m.c-1)
                j++;
            else if (j==m.c-1 && i!=m.l)
            {
            j=0;
            i++;}
        }

    else{
        index++;
        m.coloane[index]=j;
        m.linii[index]=i;
        m.nenul[index]=e;
            if(j<=m.c && i<=m.l && j!=m.c-1)
                j++;
        else if(j==m.c-1 && i!=m.l)
           {
               j=0;
               i++;
           }
    }
    }
    for(aux=0;aux<=index;aux++)
    {
        el[aux].lines=m.linii[aux];
        el[aux].columns=m.coloane[aux];
        el[aux].elements=m.nenul[aux];
    }
}
void afisare_mat(matrice m)
{
    int i,j,index=0;
    for(i=0;i<m.l;i++){
        printf("\n");
            for(j=0;j<m.c;j++)
            {
                if(i==el[index].lines && j==el[index].columns)
                {
                    printf("%.1f ",el[index].elements);
                    index++;
                }
                else
                printf("0.0");


            }
    }
    printf("\n");
}
void suma(matrice m,matrice n)
{
    int i,j,index0=0,index=0;
   for(i=0;i<m.l;i++){
        printf("\n");
            for(j=0;j<m.c;j++)
            {if(i==el0[index0].lines && j==el0[index0].columns && i==el[index].lines && j==el[index].columns)
        {
            printf("%.1f ",el0[index0].elements+el[index].elements);
                    index++;
                    index0++;
        }
        else if(i==el0[index0].lines&&j==el0[index0].columns)
        {
            printf("%.1f ",el0[index0].elements);
            index0++;
        }
        else if(i==el[index].lines&&j==el[index].columns)
        {
            printf("%.1f ",el[index].elements);
            index++;
        }
        else
            printf("0.0");

    }

    }
    printf("\n");
}
int main(void)
{  matrice m,n ;
int o,i;
    do{
        printf("1.Citire matrice\n");
        printf("2.Afisare matrice\n");
        printf("3.Adunarea a doua matrici rare\n");
        printf("0.Iesire\n");
        printf("Dati optiunea\n");
        scanf("%d",&o);
        switch(o)
        {
        case 0:
            exit(0);
            break;
        case 1:
            printf("Introduceti nr linii\n"); scanf("%d",&m.l );
            printf("Introduceti nr coloane\n");scanf("%d",&m.c );
            citire_mat(m);
            break;
        case 2:
            printf("Matricea este\n");
            afisare_mat(m);
            break;
        case 3:
            printf("Introduceti nr de linii ale celor doua matrici \n");
            scanf("%d",&m.l );
            n.l=m.l;
            printf("Introduceti nr de coloane ale celor doua matrici \n");
            scanf("%d",&m.c );
            n.c=m.c;
            printf("Introduceti prima matrice\n");
            citire_mat(m);
            afisare_mat(m);
            for(i=0;i<N;i++) el0[i]=el[i];
            printf("Introduceti a doua matrice\n");
            citire_mat(n);
            afisare_mat(n);
            printf("Suma \n");
            suma(m,n);
            break;
                    }
    }while(o!=0);
    return 0;
}