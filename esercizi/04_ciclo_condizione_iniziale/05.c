#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int x, y;
    int prodotto = 0;
    int contatore;

    printf("Inserisci il primo numero (x): ");
    scanf("%d", &x);
    printf("Inserisci il secondo numero (y): ");
    scanf("%d", &y);

    contatore = abs(y);

    while (contatore > 0) {
        prodotto += abs(x);
        contatore--;
    }

    if ((x < 0 && y > 0) || (x > 0 && y < 0)) {
        prodotto = -prodotto;
    }

    printf("Il prodotto di %d per %d e': %d\n", x, y, prodotto);

    return 0;
}