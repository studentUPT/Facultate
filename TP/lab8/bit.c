#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void afisare(int *x, int *y, float (**nr1), float (**nr2)) {
	int i;
	for (i = 0; i <= *x; i++) {
		printf("%5.2f ", (*nr1)[i]);
	}
	printf("\n-------------\n");
	for (i = 0; i <= *y; i++) {
		printf("%5.2f ", (*nr2)[i]);
	}
}
void citire(float (**nr1), float (**nr2), int *x, int *y, char *fisier) {
	FILE *f;
	*nr1 = (float*)malloc(sizeof(float));
	*nr2 = (float*)malloc(sizeof(float));
	float n;
	f = fopen(fisier, "r");
	if (f == NULL) {
		printf("Error");
		exit(1);
	}
	
		while (!feof(f)) 
		{
			fscanf(f,"%f", &n);
			if (n <= 10) {
				(*nr1)[(*x)++] = n;
				*nr1 = realloc(*nr1, sizeof(float *)*(*x));
				printf("\n sizeof = %d", sizeof(*nr1));
			}
			else {
				(*nr2)[(*y)++] = n;
				*nr2 = realloc(*nr2, sizeof(float*)*(*y));
			}
        fwrite()
		}
	
	fclose(f);
	
}

void afisare_biti(int n) {
	int i;
	for (i = 15; i>=0; i--) {
		putchar(n & 1 << i ? '1' : '0');
	}
	printf("\n -------\nn=%d \n --------", n);
}

void inverseaza(int n, int x) {
	int i;
	for(i=0; i<=x; i++)
	n = n ^ (1 << i);
	afisare_biti(n);
}
void seton(int n, int x, int y) {
	int i;
	for (i = x; i <= y; i++) {
		n = (1 << i) | n;
	}
	afisare_biti(n);
}

int main(int argc, char *argv[]) {
	int n, x=0, y=0;
	float *nr1, *nr2;
	//gargv[1] = "Fisier.txt";
	citire(&nr1, &nr2, &x, &y, argv[1]);
	afisare(&x, &y, &nr1, &nr2);
	printf("n= ");
	scanf("%d", &n);
	afisare_biti(n);
	printf("\n numarul bitilor care trebuie inversati: ");
	scanf("%d", &x);
	inverseaza(n, x-1);
	printf("\n Care bit sa fie setat pe 1? ");
	scanf("%d %d", &x, &y);
	seton(n, x-1, y-1);
	_getch();
	return 0;
}