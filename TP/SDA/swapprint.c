#include <stdio.h>
#include <stdlib.h>


void swap(int *xp, int *yp)
{
    int temp=*xp;
    *xp=*yp;
    *yp=temp;
}

void show(int *arr, int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}