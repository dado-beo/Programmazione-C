#include <stdio.h>

int main(void) {
    int x, n;
    int esponente_originale;
    int potenza = 1;

    printf("Inserisci la base (x): ");
    scanf("%d", &x);
    printf("Inserisci l'esponente (n >= 0): ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Errore: l'esponente deve essere un numero intero non negativo.\n");
        return 1;
    }

    esponente_originale = n;

    while (n > 0) {
        potenza *= x;
        n--;
    }

    printf("La potenza di %d elevato a %d e': %d\n", x, esponente_originale, potenza);

    return 0;
}