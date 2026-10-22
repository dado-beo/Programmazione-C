#include <stdio.h>

int main(void) {
    int n;

    do {
        printf("Inserisci la dimensione n (n > 1): ");
        scanf("%d", &n);

        if (n <= 1) {
            printf("Errore! Il valore di n deve essere maggiore di 1.\n\n");
        }
    } while (n <= 1);

    printf("\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                // Diagonale principale
                printf("0 ");
            } else if (j > i) {
                // Sopra la diagonale principale
                printf("X ");
            } else {
                // Sotto la diagonale principale
                printf("Y ");
            }
        }
        printf("\n");
    }

    return 0;
}