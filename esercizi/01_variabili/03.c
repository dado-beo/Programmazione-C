#include <stdio.h>

int main(void) {
    float x,y;
    float area;

    printf("Inserisci il primo lato del rettangolo: ");
    scanf("%f", &x);
    printf("Inserisci il secondo lato del rettangolo: ");
    scanf("%f", &y);

    area = x * y;

    printf("Lato 1 = %f\n", x);
    printf("Lato 2 = %f\n", y);
    printf("Area = %f", area);
    return 0;
}