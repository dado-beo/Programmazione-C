#include <stdio.h>
#include <stdlib.h>

// Prototipo della funzione
int contaCifre(int n);

int main(void) {
    int numero, nCifre;

    printf("Inserisci un numero intero: ");
    scanf("%d", &numero);

    nCifre = contaCifre(numero);

    printf("Il numero %d e' composto da %d cifre.\n", numero, nCifre);

    return 0;
}

int contaCifre(int n) {
    int nCifre = 0;
    int temp = abs(n); 

    do {
        nCifre++;
        temp /= 10;
    } while (temp > 0);

    return nCifre;
}