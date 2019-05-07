#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
int main()
{
    FILE *f, *g;
    if ((f = fopen("C:/Users/Mihai/Documents/GitHub/Facultate/TP/Lab11/in_p8.txt", "r")) != NULL) {
        g = fopen("C:/Users/Mihai/Documents/GitHub/Facultate/TP/Lab11/out_p8.txt", "w");
        char line[MAX];
        while (!feof(f)) {
            fgets(line, MAX, f);
            if (!feof(f))
                line[strlen(line) - 1] = '\0';
            fprintf(g, "\"%s\"", line);
            fprintf(g, "\n");
        }
        fclose(f); fclose(g);    } else printf("Fisierul nu a fost deschis\n");
    return 1;
}