#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define BIT_LEN (sizeof(int)*8)

void printbits(unsigned n);
int maxmsl(unsigned n);
int main(){
    unsigned int n;
    printf("\n Valoare: ");
    scanf("%x", &n);
    printf("%x\n\n", maxmsl(n));
    printbits(n);
    return 0;
}
void printbits(unsigned n){
    for(int i=sizeof(n)*8-1; i>=0; i-- ){
        if((n&1<<i) ==0){
            printf("0");
        }
        else printf("1");
    }

}
int maxmsl(unsigned n){
    unsigned mask, max=n;

    for(int i=0; i<sizeof(n)*2; i++){
        mask=n&(~(~0>>(BIT_LEN-4)));
        n=n|(mask>>(BIT_LEN-4));
        if(n>max)
        max=n;
    }
    return max;
}