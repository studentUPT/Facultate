#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

int main()
{
    FILE *f, *g;
    if ((f = fopen("C:/Users/Mihai/Documents/GitHub/Facultate/TP/Lab11/in_p3.txt", "r")) != NULL) {
        g = fopen("C:/Users/Mihai/Documents/GitHub/Facultate/TP/Lab11/out_p3.txt", "w");
        int xy[MAX][MAX], min = 9999999, dist, minX, minY, cont = 0;
        while(!feof(f)) {
            fscanf(f, "%d%d", &xy[cont][0], &xy[cont][1]);
            if (min >= (xy[cont][2] = sqrt(pow(xy[cont][0], 2) + pow(xy[cont][1], 2))))
                min = xy[cont][2];
            cont++;
        }
        fprintf(g, "Punctele cele mai apropiat de origine sunt: ");
        for (int i = 0; i < cont; i++) {
            if (xy[i][2] == min) 
                fprintf(g, "(%d,%d), ", xy[i][0], xy[i][1]);
        }
        fclose(f); fclose(g);
    } else printf("Fisierul nu a fost deschis");
    return 1;
}