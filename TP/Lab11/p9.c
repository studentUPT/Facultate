#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

void swap(int *a, int *b) {
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    FILE *f, *g;
    if ((f = fopen("C:/Users/Mihai/Documents/GitHub/Facultate/TP/Lab11/in_p9.txt", "r")) != NULL) {
        g = fopen("C:/Users/Mihai/Documents/GitHub/Facultate/TP/Lab11/out_p9.txt", "w");
        int xy[MAX][MAX], cont = 0;
        while(!feof(f)) {
            fscanf(f, "%d%d", &xy[cont][0], &xy[cont][1]);
            xy[cont][2] = sqrt(pow(xy[cont][0], 2) + pow(xy[cont][1], 2));
            cont++;
        }
        for (int i = 0; i < cont - 1; i++) {
            for (int j = i + 1; j < cont; j++) {
                if (xy[i][2] > xy[j][2]) {
                    swap(&xy[i][0], &xy[j][0]);
                    swap(&xy[i][1], &xy[j][1]);
                    swap(&xy[i][2], &xy[j][2]);
                }
            }
        }
        fprintf(g, "Punctele sortate dupa distanta:\n");
        for (int i = 0; i < cont; i++) {
            fprintf(g, "(%d,%d), dist = %d\n", xy[i][0], xy[i][1], xy[i][2]);
        }
        fclose(f); fclose(g);
    } else printf("Fisierul nu a fost deschis");
    return 1;
}