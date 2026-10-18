#include <stdio.h>

int main(void) {
    float x, y, h; // basi e altezza del trapezio
    float area;

    printf("Inserisci la base1 del trapezio: ");
    scanf("%f", &x);
    printf("Inserisci la base2 del trapezio: ");
    scanf("%f", &y);
    printf("Inserisci l'altezza del trapezio: ");
    scanf("%f", &h);

    area = (x + y) * h / 2;

    printf("Base1 = %f\n", x);
    printf("Base2= %f\n", y);
    printf("Altezza = %f\n", h);
    printf("Area = %f", area);

    return 0;
}