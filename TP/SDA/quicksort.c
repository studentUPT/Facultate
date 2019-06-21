#include <stdio.h>
#include <stdlib.h>
#include "insert.c"

int partition(int *arr, int start, int end)
{
    int pivot=arr[end];
    int i=(start-1);
    for(int j=start; j<=end-1; j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[end]);
    return(i+1);
}
void quicksort(int *arr, int start, int end){
    if(start<end)
    {
        int pi=partition(arr, start, end);

        quicksort(arr, start, pi-1);
        quicksort(arr, pi+1, end);
    }

}


void quick(int *arr, int start, int end)
{
    int curent, last_greater;
    int i, pivot;
    if(start<end){
    pivot=arr[end];
    while(arr[last_greater]<pivot)
    last_greater++;
    for(curent=0; curent<end; curent++ )
    {   if(arr[curent]<pivot){
        
             swap(&arr[curent], &arr[last_greater]);
           
         }
        
    }
    swap(&arr[last_greater], &arr[end]);
    quick(arr, start, last_greater-1);
    quick(arr, last_greater+1, end);
    }


}