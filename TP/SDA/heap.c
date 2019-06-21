#include <stdio.h>
#include <stdlib.h>
#include "cocktail.c"


void heapy(int *arr, int n, int i)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<n&&arr[l]>arr[largest])
         largest=l;

    if (r<n&&arr[r]>arr[largest])       
    {
        largest=r;
    }
    if(largest!=i)
    {
        swap(&arr[i], &arr[largest]);
        heapy(arr,n,largest);
    }
    

}
void heap(int *arr, int n)
{
    int i;
    for(i=n/2-1; i>=0; i--)
    {
        heapy(arr,n,i);
    }
    for(i=n-1; i>=0; i--)
    {
        swap(&arr[0], &arr[i]);
        
        heapy(arr, i, 0);
    }

}