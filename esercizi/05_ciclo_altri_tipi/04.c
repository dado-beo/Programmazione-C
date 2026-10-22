#include <stdio.h>

int main(void) {
    int a, b;

    do {
        printf("Inserisci il primo numero positivo (a): ");
        scanf("%d", &a);
        printf("Inserisci il secondo numero positivo (b): ");
        scanf("%d", &b);

        if (a <= 0 || b <= 0) {
            printf("Errore! Entrambi i numeri devono essere maggiori di zero.\n\n");
        }
    } while (a <= 0 || b <= 0);

    int tempA = a;
    int tempB = b;

    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }

    printf("\nIl MCD di %d e %d è: %d\n", tempA, tempB, a);

    return 0;
}