/*Definiti o structura pentru memorarea urmatoarelor informatii despre animale:
-nr picioare: nr intreg, minim 0 (ex. sarpe), maxim 1000 (ex. miriapod)
-periculos pentru om: da/nu
-abrevierea stiintifica a speciei: sir de maxim 8 caractere
-varsta maxima ina ni: numar intreg, minim 0, maxim 2000
Definiti structura in asa fel incat sa ocupe spatiul minim de memorie posibil. 
Afisati spatiul de memorie ocupat folosind operatorul sizeof
Cititi informatiile despre un animal si apoi afisatiile pe ecran*/
#include <stdio.h>

#include <string.h>

typedef struct animal {
    unsigned int
        periculos: 11,
        picioare: 10,
        varsta: 11;
    float greutate;
    char abv[8];
}
animal;

void citire(animal * a, int * nr) {

    ( * nr) ++;
    unsigned int value;
    printf("E periculos pentru om? (1-DA,0-NU)");
    scanf("%d", &value); a[ * nr].periculos = value;
    printf("Introduceti nr de picioare: ");
    scanf("%d", &value);  a[ * nr].picioare = value;
    printf("Introduceti greutatea animalului: ");
    scanf("%g", &a[ * nr].greutate);
    printf("Introduceti abrevierea stiintifica: ");
    scanf("%s", a[ * nr].abv);
    printf("Introduceti varsta maxima: ");
    scanf("%d", &value); a[ * nr].varsta = value;
    int i;

    for (i = 0; i <= *nr; i++) {
        printf("\ndangerous: %u\nlegs: %u\nweight: %.3f kg\nabbv: %s\nage: %u\n-----------",
            a[i].periculos,
            a[i].picioare,
            a[i].greutate,
            a[i].abv,
            a[i].varsta
        );
    }
}


int main() {

    animal a[30];
    int n = -1, i;
    citire(a, &n);
    printf("\nSpatiul ocupat in octeti: %d",sizeof(animal) );
   

    return 0;
}