#include <stdio.h>

int main(void) {
    int n;
    int numeroAttuale;
    int min, max;

    int sommaPosizioniDispari = 0;
    int sommaPosizioniPari = 0;
    int sommaTot = 0;

    int pos = 1;

    printf("Quanti numeri interi vuoi inserire? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Errore: devi inserire una quantita' N maggiore di 0.\n");
        return 1;
    }

    while (pos <= n) {
        printf("Inserisci il numero intero: ");
        scanf("%d", &numeroAttuale);

        if (pos == 1) {
            min = numeroAttuale;
            max = numeroAttuale;
        } else {
            if (numeroAttuale < min) {
                min = numeroAttuale;
            }
            if (numeroAttuale > max) {
                max = numeroAttuale;
            }
        }

        if (pos % 2 != 0) {
            sommaPosizioniDispari += numeroAttuale;
        } else {
            sommaPosizioniPari += numeroAttuale;
        }

        sommaTot += numeroAttuale;

        pos++; 
    }

    printf("\nmin = %d\n", min);
    printf("max = %d\n", max);
    printf("somma dispari = %d\n", sommaPosizioniDispari);
    printf("somma pari = %d\n", sommaPosizioniPari);
    printf("somma totale = %d\n", sommaTot);

    return 0;
}