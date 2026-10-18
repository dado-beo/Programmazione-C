#include <stdio.h>

int main(void) {
    int n1, n2;
    char operatore;

    printf("Inserisci due numeri interi: ");
    scanf("%d %d", &n1, &n2);
    printf("Inserisci un operatore (+, -, *, /): ");
    scanf(" %c", &operatore); // Nota lo spazio prima di %c per

    switch(operatore) {
        case '+':
            printf("%d + %d = %d\n", n1, n2, n1 + n2);
            break;
        case '-':
            printf("%d - %d = %d\n", n1, n2, n1 - n2);
            break;
        case '*':
            printf("%d * %d = %d\n", n1, n2, n1 * n2);
            break;
        case '/':
            if(n2 != 0) {
                printf("%d / %d = %f\n", n1, n2, (float)n1 / n2);
            } else {
                printf("Errore: divisione per zero!\n");
            }
            break;
        default:
            printf("Operatore non valido!\n");
    }
    return 0;
}