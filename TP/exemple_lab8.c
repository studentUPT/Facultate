#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void f1(int n1, int n2) {
	printf("O functie care are doi parametri de tip int: %d si %d.\n", n1, n2);
}
void f2(int n3, int n4) {
	printf("A doua functie cu doi parametri de tip int: %d si %d.\n", n3, n4);
}
void exemplu1() {
	void(*pointer) (int x, int y);
	pointer = &f1;
	f1(100, 200);
	//invocam prima functie prin intermediul folosind pointerul
	(*pointer) (300, 400);
	//atribuim pointerului adresa celei dea doua functie 
	pointer = &f2;
	f2(500, 600);
	(*pointer) (700, 800);
}
void f3(int nr){}
int f4(int nr){
	return 0;

}
void f5(int nr, int nr1){}
void exemplu2() {
	void(*un_pointer) (int nr);
	un_pointer = &f3;
	
}

void stea() {printf("*");}
void plus() {printf("+");}
void minus() { printf("-"); }
void dolar() { printf("$"); }

void exemplu3() {
	int i;
	void(*p[4]) (void);
	p[0] = &stea;
	p[1] = &plus;
	p[2] = &minus;
	p[3] = &dolar;
	for (i = 0; i < 4; i++)
		(*p[i])();
	for (i = 3; i >= 0; i--)
		(*p[i])();
	printf("\n");
}

float sinus(int n) {return sin(n);}
float cosin(int n) { return cos(n); }
float ma(float(*un_pointer_la_functie) (int)) {
	int i;
	float valoare, max = 0;
	for ( i = 0; i < 100; i++)
	{
		valoare = (*un_pointer_la_functie) (i);
		if (max < valoare)
			max = valoare;
	}
	return max;
}
void exemplu4() {
	printf("Maximul functiei sinus: %f. \n", ma(&sinus));
	printf("Maximul functiei cosinus %f.\n", ma(&cosin));
}

#include <stdio.h>
#include <stdlib.h>
typedef struct complex {
	char tip;
	union {
		struct {
			float x;
			float y;
		}cartez;
		struct {
			float unghi;
			float raza;
		}polar;
	}coord;
}complex;

void citire(complex *c) {
	do {
		printf("sistemul de coordonate? 0=cartezian, 1=polar");
		scanf("&hhd", c->tip);
		switch (c->tip) {
		case 0:
			printf("x?");
			scanf("%f", &(c->coord.cartez.x));
			printf("y?");
			scanf("%f", &(c->coord.cartez.y));
			break;
		case 1:
			printf("unghi?");
			scanf("%f", &(c->coord.polar.unghi));
			printf("Raza?");
			scanf("%f", &(c->coord.polar.raza));
			break;
		default: printf("optiune invalida.\n");

		}
	} while ((c->tip != 0) && (c->tip != 1));
}
void citire_polar(complex *c) {
	printf("unghi? ");
	scanf("%f", &(c->coord.polar.unghi));
	printf("raza? ");
	scanf("%f", &(c->coord.polar.raza));
}
void afisare_polar(complex *c) {
	printf("unghi: %f, raza: %f\n", c->coord.polar.unghi, c->coord.polar.raza);
}
void citire_cartez(complex *c) {
	printf("x? ");
	scanf("%f", &(c->coord.cartez.x));
	printf("y? ");
	scanf("%f", &(c->coord.cartez.y));
}
void afisare_cartez(complex *c) {
	printf("x: %f, y: %f", c->coord.cartez.x, c->coord.cartez.y);
}
void p_func_struct() {
	void *n=NULL;
	citire(n);
	citire_polar(n);
	afisare_polar(n);
	citire_cartez(n);
	afisare_cartez(n);
}
int main() {
	int op;
	do {
		printf("1. Exemplu1 \n");
		printf("2. Exemplu2 \n");
		printf("3. Exemplu3 \n");
		printf("4. Exemplu4 \n");
		printf("5. Pointer la functii utilizate in structuri\n");
		printf("6. Transmitere prin adresa a parametrilor de functii \n");
		printf("0. Exit \n");
		printf("\n----------------\nOptiunea dvs este: ");
		scanf("%d", &op);
		switch (op) {
		case 1: exemplu1();
			break;
		case 2:exemplu2();
			break;
		case 3:exemplu3();
			break;
		case 4:exemplu4();
			break;
		case 5: p_func_struct();
			break;
		case 6:
			break;
		case 0: return 0;
			break;
		default:
			printf("Optiune invalida!\n");
			break;
		}
	} while (op);
	return 0;
}