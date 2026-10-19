#include <stdio.h>

int main(void) {
    float base, altezza;
    float areaTriangolo;

    printf("Inserisci la base del triangolo: ");
    scanf("%f", &base);
    printf("Inserisci l'altezza del triangolo: ");
    scanf("%f", &altezza);

    if( base > 0 && altezza > 0 ) {
        areaTriangolo = (base * altezza) / 2;
        printf("L'area del triangolo è: %.2f\n", areaTriangolo);
    } else {
        printf("Errore: base e altezza devono essere valori positivi.\n");
    }

    return 0;
}