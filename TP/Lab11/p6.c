#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f, *g;
    if ((f = fopen("C:/Users/Mihai/Documents/GitHub/Facultate/TP/Lab11/in_p6.txt", "r")) != NULL) {
        g = fopen("C:/Users/Mihai/Documents/GitHub/Facultate/TP/Lab11/indexate_p6.txt", "w");
        float x, ind;
        while (!feof(f)) {
            fscanf(f, "%f", &x);
            if (x < 1000)
                fprintf(g, "%.2f\n", x + 0.15 * x);
            else fprintf(g, "%.2f\n", x);
        }
        fclose(f); fclose(g);
    } else printf("FIsierul nu a fost deschis!\n");
}