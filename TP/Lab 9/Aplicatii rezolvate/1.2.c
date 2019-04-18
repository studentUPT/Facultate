//Se citeste valoare unui numar natural nr<=15.
 //Sa se afiseze valoarea 2^nr

 #include <stdio.h>
 
 int main(){
    int nr;

    printf("dati numarul: ");
    scanf("%d", &nr);
    printf("%d",(1<<nr));
    return 0;
 }
