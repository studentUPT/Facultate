/*5) Să se scrie un program care sa administreze un parc de automobile. Informaţiile relative la un automobil sunt: numărul de locuri, puterea (în cai putere), marca, culoarea, anul fabricaţiei maşinii.
a) se vor citi informatiile relative la cele n automobile din parcul de autoturisme. Se vor afisa doar acele automobilele care au 5 locuri; 
b) sa se ordoneze crescator dupa putere automobilele – se vor afisa datele ordonate; 
c) sa se scrie o functie care afiseaza toate automobilele fabricate într-un anumit an dat ca parametru. */
#include<stdio.h>
#include<conio.h>
typedef struct					//declarare structura
{
	char marca[20];
	char model[20];
	char cul[20];
	int an;
	struct					//definire structura
	{
		char nl;
		int put;
	}date;					//lista variabile la structura
}automobil;						//nume structura
typedef automobil masini[20];			//tip de date propriu
void citire(masini a, int *n)			//introducere date
{
	int i;
	printf("Dati nr. de automobile: ");
	scanf("%d",n);
	for(i=0; i<*n; i++)
	{
		printf("Introduceti datele despre automobilul %d\n",i+1);
		printf("\tmarca: ");
		scanf("%s",a[i].marca);
		printf("\tmodelul: ");
		scanf("%s",a[i].model);
		printf("\tculoarea: ");
		scanf("%s",a[i].cul);
		printf("\tanul: ");
		scanf("%d",&a[i].an);
		printf("\tnumarul de locuri: ");
		scanf("%d",&a[i].date.nl);
		printf("\tputerea in cai putere: ");
		scanf("%d",&a[i].date.put);
	}
}
 
void afisare(masini a,int n)			//afisare date
{
	int i;
	 for (i=0;i<n;i++)
	{
		printf("Automobil [%d]:\n",i+1);
		printf("\tmarca:     %s\n",a[i].marca);
		printf("\tmodelul:   %s\n",a[i].model);
		printf("\tculoarea:  %s\n",a[i].cul);
		printf("\tan fabr.:  %d\n",a[i].an);
		printf("\tnr locuri: %d\n",a[i].date.nl);
		printf("\tputerea:   %d\n\n",a[i].date.put);
	 }
}
void an(masini a,int n,int p)
{
	int i;
	for(i=0;i<n-1;i++)
	 {
		 if(a[i].an=p)			//atribuire valori membrilor structurii
		{
			printf("Automobil [%d]:\n",i+1);
			printf("\tmarca:     %s\n",a[i].marca);
			printf("\tmodelul:   %s\n",a[i].model);
			printf("\tculoarea:  %s\n",a[i].cul);
			printf("\tan fabr.:  %d\n",a[i].an);
			printf("\tnr locuri: %d\n",a[i].date.nl);
			printf("\tputerea:   %d\n\n",a[i].date.put);
		 }
	}
}
void main()
{	
	masini a;
	int n,aux,i,j,p;
	citire(a,&n);
	afisare(a,n);
	for(i=0;i<n;i++)
	{ 
		if(a[i].date.nl=5)		//atribuire valori membrilor structurii	
		{
			printf("Automobil [%d]:\n",i+1);
			printf("\tmarca:     %s\n",a[i].marca);
			printf("\tmodelul:   %s\n",a[i].model);
			printf("\tculoarea:  %s\n",a[i].cul);
			printf("\tan fabr.:  %d\n",a[i].an);
			printf("\tnr locuri: %d\n",a[i].date.nl);
			printf("\tputerea:   %d\n\n",a[i].date.put);
		}
	}
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		{
			if(a[i].date.put>a[j].date.put)
             {
				aux=i;
				i=j;
				j=aux;
			}
		}
	afisare(a,n);
	printf("\n\tDati anul dupa care vor fi afisate masinile: ");
	scanf("%d",&p);
	an(a,n,p);
 
	getchar();
	int k;
	scanf("%d", &k);

}