/*Program pentru redimensionarea unui bloc de 100 de intregi la 200 cu realloc */
#include <stdio.h>
#include <stdlib.h>

int main(){
    int *a, *aux;
    /*Initial alocam memorie pentru 100 de intregi. */
    a = (int *) malloc(100 *sizeof(int));
    if(!a){
        printf("Nu pot aloca memorie. \n");
        exit(EXIT_FAILURE);
    }
    /*Pe urma redimensionam blocul alocat la 200 de intregi.
    Pastram adresa returnata de realloc intr-un pointer auxiliar, 
    pentru a nu-l suprascrie pe a. */

    aux = (int *) realloc(a, 200 * sizeof(int));
    /*Daca redimensionarea a esuat, eliberez locul alocat initial,
    dupa care inchei programul cu mesaj de eroare. */
    if(!aux){
        printf("Nu pot redimensiona blocul. \n");
        free(a);
        exit(EXIT_FAILURE);
    }
    /*Daca aloc a reusit, copiez adresa din aux in a si continui executia. */
    else{
        a = aux;
    }
    /*Eliberez blocul la final. */
    free(a);
    return 0; 
}
