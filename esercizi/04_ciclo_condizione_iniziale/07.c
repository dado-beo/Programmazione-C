#include <stdio.h>

int main(void) {
    int n, n_originale;
    int fattoriale = 1;

    printf("Inserisci un numero intero non negativo: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Errore: il fattoriale non e' definito per numeri negativi.\n");
        return 1;
    }

    n_originale = n;

    while (n > 0) {
        fattoriale *= n;
        n--;
    }

    printf("Il fattoriale di %d (%d!) e': %d\n", n_originale, n_originale, fattoriale);

    return 0;
}