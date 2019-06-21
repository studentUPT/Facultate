#include <stdio.h>
#include <stdlib.h>
#include "swapprint.c"

void selection(int *arr, int n)
{
    int i, j, min_ind;
    for ( i = 0; i < n-1; i++)
    {
        min_ind=i;
        for ( j = i+1; j < n; j++)  
            if(arr[j]<arr[min_ind])
            min_ind=j;
        swap(&arr[min_ind], &arr[i]);
        
    }
    return;
}