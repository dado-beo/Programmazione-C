#include <stdio.h>

int main(void) {
    int r, c;

    do {
        printf("Inserisci il numero di righe (r): ");
        scanf("%d", &r);
        printf("Inserisci il numero di colonne (c): ");
        scanf("%d", &c);

        if (r <= 0 || c <= 0) {
            printf("Errore! Sia le righe che le colonne devono essere maggiori di zero.\n\n");
        }
    } while (r <= 0 || c <= 0);

    printf("\n");

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("X");
        }
        printf("\n");
    }

    return 0;
}