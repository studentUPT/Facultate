//O functie care permite cautarea unui subsir intr-un sir

#include <stdio.h>

#define MAX 20


int citire(char (*s)[]) { 
    int i;
    for (i = 0; (*s)[i] != '\0'; i++);
    return i;
}

int cautare(char (*s1)[], char (*s2)[]) {

    int i, j,
        k = 0,
         l1= citire(&(*s1)),
         l2 = citire(&(*s2));


    if (citire(&(*s1)) < citire(&(*s2))) {
        return -1;
     
    } 
    for (i = 0; i < l1; i++) {
        for(j = 0; j < l2 && (*s1)[i+j] == (*s2)[j]; j++) {
            if(++k == l2) return 1;
            
        }
    }
    return -1;
}


int main() {

    char sir1[MAX],
        sir2[MAX];
    printf("s1: ");
    gets(sir1);

    printf("s2: ");
    gets(sir2);

    printf("%d", citire( &sir1, &sir2));

    return 0;
}