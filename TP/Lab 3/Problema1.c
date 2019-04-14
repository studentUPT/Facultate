//P1. O functie care returneaza numarul de caractere dintr-un sir s2

#include <stdio.h>

#define MAX 100

int returneaza(char (*sir2)[]) {
    
    int i;
    for (i = 0; (*sir2)[i] != '\0'; i++);
    return i;
}


int main() {

    char sir[MAX];
    printf("Sirul este: ");
    scanf("%s", sir);

    printf("Lungimea sirului este: %d", returneaza( &sir));

    return 0;
}
