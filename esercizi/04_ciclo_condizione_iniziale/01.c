#include <stdio.h>

int main(void) {
    int n;
    int numeroAttuale, max;

    printf("Quanti numeri interi vuoi inserire? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Errore: devi inserire una quantita' N maggiore di 0.\n");
        return 1;
    }

    printf("Inserisci il primo numero intero: ");
    scanf("%d", &max);
    n--;

    while (n > 0) {
        printf("Inserisci un numero intero: ");
        scanf("%d", &numeroAttuale);

        if (numeroAttuale > max) {
            max = numeroAttuale;
        }

        n--;
    }

    printf("\nIl massimo valore inserito e': %d\n", max);

    return 0;
}