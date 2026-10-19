#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, temp;

    printf("Inserisci un numero intero: ");
    scanf("%d", &n);

    // Convertiamo n in valore assoluto per gestire correttamente anche i numeri negativi
    temp = abs(n);

    if (temp / 1000 != 0) { // Equivalentemente: temp >= 1000
        printf("il numero e' composto da piu' di 3 cifre\n");
    } else if (temp / 100 != 0) { // Equivalentemente: temp >= 100
        printf("il numero e' composto da 3 cifre\n");
    } else if (temp / 10 != 0) { // Equivalentemente: temp >= 10
        printf("il numero e' composto da 2 cifre\n");
    } else {
        printf("il numero e' composto da 1 cifra\n");
    }

    return 0;
}