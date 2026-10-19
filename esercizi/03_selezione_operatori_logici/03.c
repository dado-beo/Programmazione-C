#include <stdio.h>

int main(void) {
    float x, y, h;
    float areraTrapezio;

    printf("Inserisci x, y, h separati da spazio: ");
    scanf("%f %f %f", &x, &y, &h);

    if( x > 0 && y > 0 && h > 0 ) {
        areraTrapezio = (x + y) * h / 2;
        printf("La base (x) è: %.2f\n", x);
        printf("La base (y) è: %.2f\n", y);
        printf("L'altezza (h) è: %.2f\n", h);
        printf("L'area del trapezio è: %.2f\n", areraTrapezio);
    } else {
        printf("Errore: x, y e h devono essere valori positivi.\n");
    }

    return 0;
}