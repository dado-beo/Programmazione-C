#include <stdio.h>

int main(void) {
    int righe, colonne;

    do {
        printf("Inserisci il numero di colonne (base > 1): ");
        scanf("%d", &colonne);
        printf("Inserisci il numero di righe (altezza > 1): ");
        scanf("%d", &righe);

        if (colonne <= 1 || righe <= 1) {
            printf("Errore! Sia le colonne che le righe devono essere maggiori di 1.\n\n");
        }
    } while (colonne <= 1 || righe <= 1);

    printf("\n");

    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            if (i == 0 || i == righe - 1 || j == 0 || j == colonne - 1) {
                printf("*");
            } else {
                printf("A");
            }
        }
        printf("\n");

    return 0;
}