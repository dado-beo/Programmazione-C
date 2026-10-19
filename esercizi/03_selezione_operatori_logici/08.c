#include <stdio.h>

int main(void) {
    int valoreIntero;

    printf("Inserisci un numero intero: ");
    scanf("%d", &valoreIntero);

    if ( valoreIntero > 0 && valoreIntero % 2 == 0 ) {
        printf("Il numero %d e' POSITIVO e PARI.\n", valoreIntero);
    } else if ( valoreIntero > 0 && valoreIntero % 2 != 0 ) {
        printf("Il numero %d e' POSITIVO e DISPARI.\n", valoreIntero);
    } else if ( valoreIntero < 0 && valoreIntero % 2 == 0 ) {
        printf("Il numero %d e' NEGATIVO e PARI.\n", valoreIntero);
    } else if ( valoreIntero < 0 && valoreIntero % 2 != 0 ) {
        printf("Il numero %d e' NEGATIVO e DISPARI.\n", valoreIntero);
    } else {
        printf("Il numero %d e' ZERO (ne' positivo ne' negativo).\n", valoreIntero);
    }

    return 0;
}