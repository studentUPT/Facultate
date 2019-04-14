//Functie care returneaza nr de caractere c dintr-un sir sir3 (*sir3 si c se transmit ca parametri)

#include <stdio.h>
#include <string.h>

    
    int returnare (char sir3[20], char c){
    int i=0, k=0;

    while(sir3[i] != '\0'){
        if(sir3[i] == c) k++; i++;
    }
    return k;

    
}

int main(){

    char sir[20], c;
    printf("Sirul este: ");
    gets(sir);
    printf("Caracterul cautat este: ");
    scanf("%c", &c);
    printf("\n");
    printf("%d", returnare(sir, c));   
    return 0;
}