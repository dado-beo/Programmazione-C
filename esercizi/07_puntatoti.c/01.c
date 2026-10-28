#include <stdio.h>

// Prototipo
void incrementa(int* valore);

int main (void) {
    int numero;

    printf("Inserire un valore intero: ");
    scanf("%d", &numero);

    incrementa(&numero);

    printf("Il valore aggiornato e': %d\n", numero);

    return 0;
}

void incrementa(int* valore) {
    // Si usano le parentesi per dire: "incrementa il valore che si trova 
    // all'indirizzo puntato, e non l'indirizzo stesso".
    (*valore)++; 
}