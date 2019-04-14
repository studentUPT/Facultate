//Sa se creeze o baza de date cu produse definite prin nume si pret. 
//Operatiile necesare sunt introducere si afisare si ele se vor da pe rand de la tastatura, 
//utilizatorului fiindu-i prezentat un meniu de unde poate alege operatia dorita.
#include <stdio.h>

typedef struct {
	char nume[50];
	float pret;
}Produs;

int main()
{
	Produs produse[100];
	int i, opt,n=0;
	
	while(1) {                       //initial 0 produse
        printf("1.Introducere\n");   //bucla infinita
        printf("2.Afisare\n");       //afisare meniu
        printf("0.Iesire\n");
		printf("operatia: "); scanf("%d", &opt);  //cere operatia
		switch (opt){
            case 1:  // intorducere la pozitia n (imediat dupa ultimul din produse)
                getchar();  //citeste \n ramas de la citirea codului de operatie
                printf("nume: "); gets(produse[n].nume);
                printf("pret: "); scanf("%g", &produse[n].pret);
                n++;    //creste numarul de produse
                break;
            case 2:  //afisare produse
                for(i = 0; i < n; i++) {
                    printf("%s %g\n", produse[i].nume, produse[i].pret);
                }
                break;
            case 0: return 0; //iesire din program
            default: printf("operatie necunoscuta\n");
		}
	}
}