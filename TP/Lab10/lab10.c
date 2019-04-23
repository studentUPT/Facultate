#include <stdio.h>
#include <stdlib.h>

int nr_ones(long n) {
	int nm = 0;
	for (int i = 0; i < 32; i++)
		if (n & (1 << i)) nm++;
	return nm;
}
int nr_ones2(long n) {
	int nm = 0;
	do {
		n &= n - 1;
		nm++;
	} while (n);
	return nm;
}
long pow2(long n) {
	return (n & (n - 1)) == 0;
}
long pow_max(long n) {
	return n ^ (n & (n - 1));
}
void repr_binara(long nr) {
	int i;
	printf("Numarul %i reprezentat binar:\n", nr);
	for (i = 15; i >= 0; i--) {
		printf("%i", (nr >> i) & 1);
	}
	printf("\n");
}
int index(long n) {
	n = n | (n >> 1);
	n = n | (n >> 2);
	n = n | (n >> 4);
	n = n | (n >> 8);
	n = n | (n >> 16);
	return nr_ones2(n) - 1;
}
int main()
{
	long nr;
	scanf("%i", &nr);
	repr_binara(nr);
	printf("Nr de 1 din repr: %d\n", nr_ones2(nr));
	if (pow2(nr)) printf("%i este putere a lui 2\n", nr);
	else printf("%i nu este putere a lui 2\n", nr);
	printf("Cea mai mare putere a lui 2 care divide pe n este: %i\n", pow_max(nr));
	printf("Indexul celui mai semnificativ bit este: %d\n", index(nr));
	return 1;
}