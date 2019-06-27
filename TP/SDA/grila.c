#include <stdio.h>

int main() {
	int arr[2][6]={{1, 2, 3, 4, 5, 6}, {6,5,4,3,2,1}};
	int *ptr=arr[0];
	int sum=0;
	
	for(int i=0; i<12; i++)
	{
	
	    printf("\t%d", *(ptr+i));
	    sum+= *(ptr+i);
	    if(i==5)
		printf("\n");
	}
	printf("\n\n%d", sum);
	return 0;
}