#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
int main()
{
    FILE *g;
    char name[MAX]; char litera[2];
    int vect[123] = { 0 };
    g = fopen("C:/Users/Mihai/Documents/GitHub/Facultate/TP/Lab11/out_p7.txt", "w");
    scanf("%s", &name);
    litera[1] = '\0';
    for (int i = 0; i < strlen(name); i++) {
        litera[0] = name[i];
        vect[litera[0]]++;
    }
    for (int i = 65; i <= 90; i++)
        if (vect[i] > 0)
            fprintf(g, "Litera %c apare de %d ori\n", i, vect[i]);
    for (int i = 97; i <= 122; i++) {
        if (vect[i] > 2 && (i == 't'))
            fprintf(g, "Litera %c apare de %d ori\n", i, vect[i] - 2);
        else if (vect[i] > 1 && (i == 'x'))
            fprintf(g, "Litera %c apare de %d ori\n", i, vect[i] - 1);
        else if (vect[i] > 0 && i != 't' && i != 'x')
            fprintf(g, "Litera %c apare de %d ori\n", i, vect[i]);

    }
    fclose(g);
    return 1;
}