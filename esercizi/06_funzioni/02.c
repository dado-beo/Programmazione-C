#include <stdio.h>
#include <stdlib.h>

// Prototipo della funzione
float calcola_potenza(float base, int esponente);

int main(void) {
    float base, risultato;
    int esponente;

    printf("Inserisci la base e l'esponente (intero con segno): ");
    scanf("%f %d", &base, &esponente);

    risultato = calcola_potenza(base, esponente);

    printf("La potenza e': %.4f\n", risultato);

    return 0;
}

float calcola_potenza(float base, int esponente) {
    float pot = 1.0;
    int exp = abs(esponente); 

    for (int i = 0; i < exp; i++) {
        pot *= base;
    }

    // Se l'esponente originale era negativo, restituiamo il reciproco (1 / pot)
    if (esponente < 0) {
        return 1.0 / pot;
    }

    return pot;
}