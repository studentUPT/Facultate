#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j;
    FILE *f, *g;
    if ((f=fopen("C:/Users/Mihai/Documents/GitHub/Facultate/TP/Lab11/in_p1.txt", "r")) != NULL) {
        fscanf(f, "%d", &n);
        g = fopen("C:/Users/Mihai/Documents/GitHub/Facultate/TP/Lab11/out_p1.txt", "w");
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                if (i==j)
                    fprintf(g, "0");
                else if (i > j)
                    fprintf(g, "+");
                else fprintf(g, "-");
            fprintf(g, "\n");
        }  
        fclose(f); fclose(g);
    } else printf("Fisierul nu a fost deschis\n");
    return 1;
}