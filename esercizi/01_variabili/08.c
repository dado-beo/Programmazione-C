#include <stdio.h>

int main(void) {
    char c;
    char precedente, successivo;
    printf("Inserisci un carattere: ");
    scanf("%c", &c);
    
    precedente = c - 1;
    successivo = c + 1;

    printf("Il carattere precedente è: %c\n", precedente);
    printf("Il carattere successivo è: %c\n", successivo);

    return 0;
}