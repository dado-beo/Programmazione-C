#include <stdio.h>

int main(void) {
    int n;

    do {
        printf("Inserisci un numero intero n (n >= 1): ");
        scanf("%d", &n);

        if (n < 1) {
            printf("Errore! Il valore di n deve essere maggiore o uguale a 1.\n\n");
        }
    } while (n < 1);

    printf("\nNumeri primi compresi tra 1 e %d:\n\n", n);

    int contatorePrimi = 0; // Traccia quanti numeri primi sono stati stampati

    for (int x = 1; x <= n; x++) {
        int divisori = 0;

        // Conteggio dei divisori compresi tra 1 e x
        for (int i = 1; i <= x; i++) {
            if (x % i == 0) {
                divisori++;
            }
        }

        if (divisori == 1 || divisori == 2) {
            printf("%5d", x);
            contatorePrimi++;

            // Va a capo ogni 10 numeri stampati
            if (contatorePrimi % 10 == 0) {
                printf("\n");
            }
        }
    }

    // Va a capo finale se la serie non termina esattamente a multiplo di 10
    if (contatorePrimi % 10 != 0) {
        printf("\n");
    }

    return 0;
}