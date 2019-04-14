#include <stdio.h>

typedef struct{
    unsigned int ani:7;
    unsigned int gestatie:4;
    unsigned int pui:4;
}mamifer;

typedef struct{
     unsigned int nr_ani:7;
     unsigned int picioare:15;
     unsigned int zburatoare:1;
     unsigned int periculoasa:1;
}insecta;

typedef struct{
    unsigned int an:7;
    unsigned int apa:1;
    float adancime;
    float viteza_i;
}peste;

typedef struct{
    unsigned int a:7;
    unsigned int anv_aripi:4;
    float altitudine;
    float viteza_z;
}pasare;

void citire_mamifer(mamifer *m, int *nr){

    (*nr)++;

    printf("\nIntroduceti durata de viata:");
    scanf("%d", m[*nr].ani);
    printf("\nIntroduceti perioada de gestatie: ");
    scanf("%d", m[*nr].gestatie);
    printf("\nIntroduceti numarul mediu de pui: ");
    scanf("%d", m[*nr].pui);
}

void afisare_mamifer(mamifer *m, int nr){
    printf("%d \5t %d \5t %d",
            m[nr].ani,
            m[nr].gestatie,
            m[nr].pui
         );
}

void citire_insecta(insecta *ins, int *nr){

    (*nr)++;
    printf("\nIntroduceti durata de viata:");
    scanf("%d", ins[*nr].nr_ani);
    printf("\nIntroduceti numarul de picioare: ");
    scanf("%d", ins[*nr].picioare);
    printf("\nEste o insecta zburatoare? (1-DA, 0-NU) ");
    scanf("%d", ins[*nr].zburatoare);
    printf("\nEste periculoasa? (1-DA, 0-NU) ");
    scanf("%d", ins[*nr].periculoasa);
    
}

void afisare_insecta(insecta *ins, int nr){
  
    printf("%d \5t %d \5t %d \5t %d",
        ins[nr].nr_ani,
        ins[nr].picioare,
        ins[nr].zburatoare,
        ins[nr].periculoasa
        );

}

void citire_peste(peste *p, int *nr){
    
    (*nr)++;

    printf("\nIntroduceti durata de viata: ");
    scanf("%d", p[*nr].an);
    printf("\nTipul de apa (1-sarata, 0-dulce) ");
    scanf("%d", p[*nr].apa);
    printf("\nIntroduceti adancimea maxima la care se gaseste: ");
    scanf("%g", &p[*nr].adancime);
    printf("\nIntroduceti viteza de inot");
    scanf("%g", &p[*nr].viteza_i);
}

void afisare_peste(peste *p, int nr){

    printf("%d \5t %d \5t %g \5t %g \5t",
            p[nr].an,
            p[nr].apa,
            p[nr].adancime,
            p[nr].viteza_i    
        );
}

int main(){

    int n=-1,i, op;
    mamifer m[20];
    insecta ins[20];
    peste p[20];
    
    do {
        printf("\n0. Exit");
        printf("\n1. Mamifer");
        printf("\n2. Insecta");
        printf("\n3. Peste");
        printf("\n4. Pasare");
        printf("\nOptiunea aleasa este: ");
        scanf("%d", & op);
        switch (op) {
            case 0:
                return 0;
            case 1:
                citire_mamifer (m, & n);
                for (i = 0; i <= n; i++)
                afisare_mamifer(m, i);
                break;
            case 2:
                citire_insecta( ins, & n);
                for (i = 0; i <= n; i++)
                afisare_insecta(ins, i);
                break;
            default:
                printf("\n Optiune gresita\n");
                break;

        }

    } while (op != 0);

}
