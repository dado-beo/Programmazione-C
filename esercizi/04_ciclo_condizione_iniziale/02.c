#include <stdio.h>

int main(void) {
    int n;
    int nAttuale, max1, max2;
    int num1, num2;

    printf("Quanti numeri interi vuoi inserire? ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Errore: devi inserire una quantita' N maggiore o uguale a 2.\n");
        return 1;
    }

    printf("Inserisci il primo numero intero: ");
    scanf("%d", &num1);
    printf("Inserisci il secondo numero intero: ");
    scanf("%d", &num2);
    n -= 2; 

    if (num1 >= num2) {
        max1 = num1;
        max2 = num2;
    } else {
        max1 = num2;
        max2 = num1;
    }

    while (n > 0) {
        printf("Inserisci un numero intero: ");
        scanf("%d", &nAttuale);

        if (nAttuale > max1) {
            max2 = max1;     
            max1 = nAttuale; 
        } else if (nAttuale > max2) {
            max2 = nAttuale; 
        }

        n--; 
    }

    printf("\nI due massimi valori inseriti sono:\n");
    printf("Primo Massimo: %d\n", max1);
    printf("Secondo Massimo: %d\n", max2);

    return 0;
}