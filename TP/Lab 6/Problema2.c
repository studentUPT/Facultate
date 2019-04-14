#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50


typedef struct{
    char nume[MAX],
         val[MAX];
}string;

typedef struct{
    char nume[MAX],
         val;
}caracter;

typedef struct{
    char nume[MAX];
    int val;
}intreg;

typedef struct{
    char nume[MAX];
    float val;
} real;

typedef union {
    string strings;
    caracter chars;
    intreg ints;
    real reals;
} record;



void citire_s(char *s, char *nume, char *val){
    int i = 0, k = 1;
    printf("Citim sir: ");
    scanf("%[^\n]s", s);
    printf("\nSirul introdus este: %s", s);
    for(i = 0; s[i] != '='; i++, k++) {
        nume[i] = s[i];
    }
    nume[i] = '\0';
    for(i = 0; s[i] != '\0'; i++)
    {
        val[i] = s[i+k];
    }

}

void typeOf(char *str, char *type) {
    int i,
        string = 0, real = 0;
    strcpy(type, "integer");
    for(i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            real++;
        }
        if (real != 1 && (str[i] == ' ' || str[i] > '9' || str[i] < '0') ) {
            string++;
        }
    }
    if(string) {
        if (strlen(str) == 1 || (str[0] == 39 && str[2] == 39) ) {
            strcpy(type, "char");
        } else
            strcpy(type, "string");
    } else if(real)
        strcpy(type, "float");
}

int main() {

    record records;

    char s[MAX],
         n[MAX],
         v[MAX],
         type[MAX];

    citire_s(s,n,v);

    typeOf(v, type);
    printf("\n type: %s", type);

    switch (type[0]) {
        case 's':
            strcpy(records.strings.nume, n);
            strcpy(records.strings.val,v);
            printf("\n name: %s value: %s", records.strings.nume, records.strings.val);
            break;
        case 'c':
            strcpy(records.chars.nume, n);
            records.chars.val = v[0];
            printf("\n name: %s value: %s", records.chars.nume, records.chars.val);
            break;
        case 'i':
            strcpy(records.ints.nume, n);
            records.ints.val = atoi(v);
            printf("\n name: %s value: %s", records.ints.nume, records.ints.val);
            break;
        case 'f':
            strcpy(records.reals.nume, n);
            records.reals.val = atof(v);
            printf("\n name: %s value: %s", records.reals.nume, records.reals.val);
            break;
    }
    return 0;
}
