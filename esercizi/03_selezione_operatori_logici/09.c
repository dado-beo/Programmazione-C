#include <stdio.h>

int main(void) {
    int ore, minuti, secondi;

    printf("Inserisci il tempo in ore, minuti e secondi separati da spazio: ");
    scanf("%d %d %d", &ore, &minuti, &secondi);

    if( ore >= 0 && ore <= 23 && minuti >= 0 && minuti <= 59 && secondi >= 0 && secondi <= 59 ) {
        printf("Il tempo inserito e' valido: %02d:%02d:%02d\n", ore, minuti, secondi);
    } else {
        printf("Errore: il tempo inserito non e' valido.\n");
    }

    return 0;
}