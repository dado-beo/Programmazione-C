#include <stdio.h>

int main(void) {
    int righe, colonne;

    do {
        printf("Inserisci il numero di righe: ");
        scanf("%d", &righe);
        printf("Inserisci il numero di colonne: ");
        scanf("%d", &colonne);

        if (righe <= 0 || colonne <= 0) {
            printf("Errore! Sia le righe che le colonne devono essere maggiori di zero.\n\n");
        }
    } while (righe <= 0 || colonne <= 0);

    printf("\n");

    int valore = 0;

    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            printf("%6d", valore);
            valore++;
        }
        printf("\n"); 
    }

    return 0;
}