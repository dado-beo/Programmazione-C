#include <stdio.h>

// Prototipo
int orarioBooleano(int ora, int minuti, int secondi);

int main() {
    int ora, minuti, secondi;

    printf("Inserisci ora, minuti, secondi: ");
    scanf("%d %d %d", &ora, &minuti, &secondi);

    int risultato = orarioBooleano(ora, minuti, secondi);

    if (risultato == 1) {
        printf("L'orario %02d:%02d:%02d e' nel formato corretto.\n", ora, minuti, secondi);
    } else {
        printf("L'orario %02d:%02d:%02d non e' nel formato corretto.\n", ora, minuti, secondi);
    }

    return 0;
}

int orarioBooleano(int ora, int minuti, int secondi) {
    int booleano;

    if ((ora >= 0 && ora <= 23) && (minuti >= 0 && minuti <= 59) && (secondi >= 0 && secondi <= 59)) {
        booleano = 1;
    } else {
        booleano = 0;
    }

    return booleano;
}