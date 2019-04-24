#include <stdio.h>
#include <stdlib.h>
#define N 100

void swap(void*x, void *y) {
	void* temp;
	temp = x;
	x = y;
	y = temp;

}


int main() {

	int arr[N];
	int a = 3, b = 5;
	swap(&a, &b);
	printf("%d  %d", a, b);

	
	
	return 0;

}