#include <stdio.h>

// Prototipo
void inserisciOrario(int* ora, int* minuti, int* secondi);

int main(void) {
    int ora, minuti, secondi;

    inserisciOrario(&ora, &minuti, &secondi);

    printf("%02d:%02d:%02d\n", ora, minuti, secondi);

    return 0;
}

void inserisciOrario(int* ora, int* minuti, int* secondi) {
    do {
        printf("Inserisci ora (0-23), minuti (0-59) e secondi (0-59): ");
        scanf("%d %d %d", ora, minuti, secondi);

        if (*ora < 0 || *ora > 23 || 
            *minuti < 0 || *minuti > 59 || 
            *secondi < 0 || *secondi > 59) {
            printf("ERRORE: orario non corretto\n");
        }
    } while (*ora < 0 || *ora > 23 || 
             *minuti < 0 || *minuti > 59 || 
             *secondi < 0 || *secondi > 59);
}