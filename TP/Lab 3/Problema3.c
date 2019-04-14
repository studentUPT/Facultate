//Functie care compara 2 siruri de caractere s1 si s2

#include<stdio.h>

#define MAX 20


int comparare(char sir1[20], char sir2[20]) {
    int ok, i;
    for (i = 0; sir1[i] && sir2[i] && sir1[i] == sir2[i]; i++)
        if (!sir1[i] && !sir2[i])
            ok = 0;
        else
    if (sir1[i] < sir2[i])
        ok = -1;
    else ok = 1;

    if (ok > 0)
        printf("%s > %s \n", sir1, sir2);
    else if (ok == 0)
        printf("%s == %s \n", sir1, sir2);
    else printf("%s < %s \n", sir1, sir2);

}

int main(void) {
    char sir1[20], sir2[20];
    printf("Primul sir: ");
    gets(sir1);
    printf("Al doilea sir: ");
    gets(sir2);
    comparare(sir1, sir2);
    return 0;


}