#include <stdio.h>

int main(void) {
    int n;
    int i = 1;
    int conta = 0; 

    printf("Inserisci un intero maggiore di 0: ");
    scanf("%d", &n);
    while (n <= 0) {
        printf("Valore non valido, inserisci un intero maggiore di 0: ");
        scanf("%d", &n);
    }

    printf("%d:", n);

    while (i <= n) {
        if (n % i == 0) {
            printf(" %d", i);
            conta++; 
        }
        i++; 
    }
    printf("\n");

    if (conta == 2) {
        printf("%d e' un numero primo\n", n);
    }

    return 0;
}