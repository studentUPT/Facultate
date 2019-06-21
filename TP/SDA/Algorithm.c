#include <stdio.h>
#include <stdlib.h>
#include "heap.c"


int main(){
    int op;
    int arr[15];
    int n=sizeof(arr)/sizeof(arr[0]);
    do{
    for(int i=0; i<n; i++)
    {
        arr[i]=rand();
    }
    printf("\n1 Selection\n2 Bubble\n3 insertion \n4 quicksort\n5 cocktail\n ");
    scanf("%d", &op);
    switch(op){
        case 1:
         selection(arr, n);
    show(arr, n);
        break;
        case 2:
        bubble(arr, n);
            show(arr, n);
        break;
        case 3:
                insert(arr, n);
                show(arr, n);
            break;
        case 4:  
            quick(arr, 0, n-1);
            show(arr,n);
        break;
        case 5:
        cocktail(arr,n);
        show(arr,n);
        break;
        case 0:
        exit(0);
        break;

    }
   



    }while(op);
    return 0;

}