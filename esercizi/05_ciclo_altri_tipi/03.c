#include <stdio.h>

int main(void) {
    float base1, base2, altezza;

    do {
        printf("\nInserisci la prima base: ");
        scanf("%f", &base1);
        printf("Inserisci la seconda base: ");
        scanf("%f", &base2);
        printf("Inserisci l'altezza: ");
        scanf("%f", &altezza);

        if (base1 <= 0 || base2 <= 0 || altezza <= 0) {
            printf("Errore! Tutti i valori inseriti devono essere maggiori di zero!\n\n");
        }

    } while (base1 <= 0 || base2 <= 0 || altezza <= 0); 

    float area = ((base1 + base2) * altezza) / 2.0;

    printf("\nL'area del trapezio è: %.2f\n", area);

    return 0;
}