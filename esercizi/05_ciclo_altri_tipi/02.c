#include <stdio.h>

int main(void) {
    int n;
    int fattoriale = 1;

    do {
    printf("\nInserisci un numero: ");
    scanf("%d", &n);
    } while (n <= 0);

    int nModificato = n;

    do {
        fattoriale *= nModificato;
        nModificato--;
    } while (nModificato != 1);
    
    printf("\nIl fattoriale del numero %d è: %d.", n, fattoriale);

    return 0;
}