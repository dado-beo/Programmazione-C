#include <stdio.h>

int main(void) {
    int sommaRichiesta;
    int contaCinquanta = 0, contaVenti = 0;
    int sommaErogata;
    int resto;

    printf("somma --> ");
    scanf("%d", &sommaRichiesta);

    contaCinquanta = sommaRichiesta / 50;
    resto = sommaRichiesta % 50;

    contaVenti = resto / 20;

    sommaErogata = (contaCinquanta * 50) + (contaVenti * 20);

    if (contaCinquanta > 0) {
        printf("banconote da 50: %d\n", contaCinquanta);
    }

    if (contaVenti > 0) {
        printf("banconote da 20: %d\n", contaVenti);
    }

    printf("Somma erogata: %d\n", sommaErogata);

    return 0;
}