#include <stdio.h>

// Prototipo della funzione
int MCD(int a, int b);

int main(void) {
    int a, b;
    int mcd_risultato;

    do {
        printf("Inserisci il primo numero intero positivo (a): ");
        scanf("%d", &a);
        printf("Inserisci il secondo numero intero positivo (b): ");
        scanf("%d", &b);

        if (a <= 0 || b <= 0) {
            printf("ERRORE! Entrambi i numeri devono essere maggiori di zero.\n\n");
        }
    } while (a <= 0 || b <= 0);

    mcd_risultato = MCD(a, b);

    printf("\nIl MCD di %d e %d e': %d\n", a, b, mcd_risultato);

    return 0;
}

int MCD(int a, int b) {
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    
    return a;
}