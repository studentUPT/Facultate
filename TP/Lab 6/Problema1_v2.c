
#include <stdio.h>
#include <stdlib.h>

typedef enum { sarata, dulce }tip_apa;

typedef struct {
	unsigned int per_gest : 3;
	unsigned int nrPui_mediu : 3;
}mamifer;

typedef struct {
	unsigned int nr_picioare : 4;
	unsigned int zboara : 1;
	unsigned int periculoasa : 1;
}insecta;

typedef struct {
	tip_apa tip : 1;
	unsigned int ad_max : 4;
	unsigned int v_max : 4;
}peste;

typedef struct {
	unsigned int anvergura : 3;
	unsigned int alt_max : 4;
	unsigned int v_max : 4;
}pasare;

typedef union {
	mamifer m;
	insecta i;
	peste pe;
	pasare pa;
}TIP;

struct {
	unsigned int v_medie : 7;
	unsigned int tip : 2;
	TIP t;
}s;

int main()
{
	unsigned int x, v_medie;
	printf("Tip vietuitoare:\n");
	printf("(1) Mamifer\t(2) Insecta\t(3) Peste\t(4) Pasare\n"); scanf("%d", &x);
	s.tip = x;
	if (x >= 1 && x <= 4) {
		printf("Durata medie de viata: "); scanf("%d", &v_medie);
		s.v_medie = v_medie;
		switch (s.tip) {
		case 1:
			printf("Perioada de gestatie: "); scanf("%d", &x);
			s.t.m.per_gest = x;
			printf("Numarul mediu de pui pe care-l naste: "); scanf("%d", &x);
			s.t.m.nrPui_mediu = x;
			break;
		case 2:
			printf("Numarul de picioare: "); scanf("%d", &x);
			s.t.i.nr_picioare = x;
			printf("Poate sa zboare?\t(1) Da  (2) Nu: "); scanf("%d", &x);
			s.t.i.zboara = x;
			printf("Este periculoasa pentru om?\t(1) Da  (2) Nu: "); scanf("%d", &x);
			s.t.i.periculoasa = x;
			break;
		case 3:
			printf("Tipul de apa:\t(0) Sarata  (1) Dulce: "); scanf("%d", &x);
			s.t.pe.tip = x;
			printf("Adancimea maxima la care se poate intalni: "); scanf("%d", &x);
			s.t.pe.ad_max = x;
			printf("Viteza maxima de inot: "); scanf("%d", &x);
			s.t.pe.v_max = x;
			break;
		case 4:
			printf("Anvergura maxima: "); scanf("%d", &x);
			s.t.pa.anvergura = x;
			printf("Altitudinea maxima de zbor: "); scanf("%d", &x);
			s.t.pa.alt_max = x;
			printf("Viteza maxima de zbor: "); scanf("%d", &x);
			s.t.pa.v_max = x;
			break;
		default: break;
		}
		switch (s.tip) {
			case 1:
				printf("Mamifer\n");
				printf("Durata medie de viata: %d\n", s.v_medie);
				printf("Perioada de gestatie: %d\n", s.t.m.per_gest);
				printf("Numarul mediu de pui pe care il naste: %d\n", s.t.m.nrPui_mediu);
				break;
			case 2:
				printf("Insecta\n");
				printf("Numarul de picioare: %d\n", s.t.i.nr_picioare);
				if (s.t.i.zboara)
					printf("Zboara\n");
				else printf("Nu zboara\n");
				if (s.t.i.periculoasa)
					printf("Este periculoasa pentru om\n");
				else printf("Nu este periculoasa pentru om\n");
				break;
			case 3:
				printf("Peste\n");
				if (s.t.pe.tip)
					printf("Tipul de apa: sarata\n");
				else printf("Tipul de apa: dulce\n");
				printf("Altitudinea maxima la care se poate gasi: %d\n", s.t.pe.ad_max);
				printf("Viteza maxima de inot: %d\n", s.t.pe.v_max);
				break;
			case 4:
				printf("Anvergura aripilor: %d\n", s.t.pa.anvergura);
				printf("Altitudinea maxima de zbor: %d\n", s.t.pa.alt_max);
				printf("Viteza maxima de zbor: %d\n", s.t.pa.v_max);
				break;
			default: break;
		}
	}
	else printf("Tip gresit");
	getch();
	return 1;
}