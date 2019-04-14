/*Programul va folosi alocarea dinamica pentru memorarea celor N numere. 
Nu se stie de la inceput cate numere vor fi introduse.
Programul va incepe direct cu citirea numerelor, fara a-l citi pe N.
Citirea se va incheia in momentul in care se introduce numarul 0.
La final afiseaza cele N numere in ordine inversa.
Programul va folosi alocarea dinamica astfel incat spatiul de memorie consumat sa fie minim.*/


#include<stdio.h>
#include<stdlib.h>

int main() {
	int *N, *aux;
	int i = 0, n;
	N = (int*)malloc(1);

	printf("Cititi numerele: \n");
	do {
		scanf("%d", &n);

		aux = (int*)realloc(N, (i+1) * sizeof(int));
		if (!aux) {
			printf("Nu pot redimensiona spatiul alocat.\n");
			exit(EXIT_FAILURE);
		}
		else {
			N = aux;
			N[i] = n;
			i++;
		}
	} while (n != 0);

	printf("Afisare in ordine inversa: ");
	for (i = i - 2; i >= 0; i--) {
		printf("%d", N[i]);
	}

	free(N);
	return 0;
}