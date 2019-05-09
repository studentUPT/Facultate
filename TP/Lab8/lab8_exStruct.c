#include <stdio.h>
#include <stdlib.h>

struct complex {
    char tip;
    union {
        struct {
            float x;
            float y;
        }cartez;
        struct {
            float unghi;
            float raza;
        }polar;
    }coord;
    void (*citire)(struct complex *c);
    void (*afisare)(struct complex *c);
};

void citire_polar(struct complex *c) {
    printf("unghi? "); scanf("%f", &(c->coord.polar.unghi));
    printf("raza? "); scanf("%f", &(c->coord.polar.raza));
}
void afisare_polar(struct complex *c) {
    printf("Unghi: %f, raza: %f\n", c->coord.polar.unghi, c->coord.polar.raza);
}
void citire_cartez(struct complex *c) {
    printf("x? "); scanf("%f", &(c->coord.cartez.x));
    printf("y? "); scanf("%f", &(c->coord.cartez.y));
}
void afisare_cartez(struct complex *c) {
    printf("x: %f, y:%f\n", c->coord.cartez.x, c->coord.cartez.y);
}

int main()
{
    int i; char tip;
    for (i=0;i<10;i++) {
        
    }
    return 0;
}
