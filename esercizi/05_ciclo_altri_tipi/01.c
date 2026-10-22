#include <stdio.h>

int main(void) {
    int n;
    int somma = 0;

    do {
        printf("\nInserisci un numero intero (0 per concludere): ");
        scanf("%d", &n);

        somma += n;
    } while(n != 0);

    printf("La somma è: %d\n", somma);

    return 0;
}