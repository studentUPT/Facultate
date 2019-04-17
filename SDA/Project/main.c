#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct afectiuni{
    char * denumire;
    int nr_pagini;
    struct capitol *urm1; 
} cap;


typedef struct carte{
    char *nume;
    struct carte *sl2;
} aut;

aut *prim=NULL;