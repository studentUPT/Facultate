#include <stdio.h>
#include <stdlib.h>
#include "quicksort.c"

void cocktail(int *arr, int n)
{
    int swapped=1;
    int start=0, end=n-1;

    while(swapped)
    {
        swapped=0;

        for (int i = 0; i < end; ++i)
        {
            if(arr[i]>arr[i+1]){
            swap(&arr[i], &arr[i+1]);
            swapped=1;
            }
        }

       if(!swapped)
        break;

        --end;

        for (int i=end-1; i>=start; --i)
        {
            if(arr[i]<arr[i+1]){
            swap(&arr[i], &arr[i+1]);
            swapped=1;
        }
        }
        
        ++start;
    
    }

}