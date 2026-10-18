#include <stdio.h>

int main(void) {
    float valoreCasa;
    int codice;

    printf("Inserisci il valore della casa: ");
    scanf("%f", &valoreCasa);
    printf("Inserisci il codice della casa (1-4): ");
    scanf("%d", &codice);

    switch(codice) {
        case 1:
            valoreCasa *= 1.05; // Aumenta del 5%
            break;
        case 2:
            valoreCasa *= 1.10; // Aumenta del 10%
            break;
        case 3:
            valoreCasa *= 1.15; // Aumenta del 15%
            break;
        case 4:
            valoreCasa *= 1.20; // Aumenta del 20%
            break;
        default:
            printf("Codice non valido!\n");
    }
    return 0;
}