//Exemplul 1
#include <stdio.h>
#include <stdlib.h>

void f1(int n1, int n2) {
    printf("%d si %d\n", n1, n2);
}
void f2(int n3, int n4) {
    printf("%d si %d\n", n3, n4);
}

int main()
{
    int x,y;
    void (*un_pointer) (int x, int y);
    un_pointer=&f1;
    f1(100,200);
    (*un_pointer) (100,200);
    return 0;
}
