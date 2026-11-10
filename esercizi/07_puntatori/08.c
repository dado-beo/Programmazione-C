#include <stdio.h>

void caricaLati(float* base, float* altezza);
void calcolaPerimetroArea(float base, float altezza, float* perimetro, float* area);

int main(void) {
    float base, altezza;
    float perimetro, area;

    caricaLati(&base, &altezza);

    calcolaPerimetroArea(base, altezza, &perimetro, &area);

    printf("il perimetro vale %.2f l'area vale %.2f\n", perimetro, area);

    return 0;
}

void caricaLati(float* base, float* altezza) {
    do {
        printf("Inserisci la base e l'altezza del rettangolo: ");
        scanf("%f %f", base, altezza);

        if (*base <= 0 || *altezza <= 0) {
            printf("ERRORE: lati non positivi\n");
        }
    } while (*base <= 0 || *altezza <= 0);
}

void calcolaPerimetroArea(float base, float altezza, float* perimetro, float* area) {
    *perimetro = 2 * (base + altezza);
    *area = base * altezza;
}