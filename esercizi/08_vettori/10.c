#include <stdio.h>

#define DIM 5

// Prototipi delle funzioni
void carica_dispari_positivi(int v[]);
void visualizza_vettore(int v[]);

int main(void) {
    int vet[DIM];

    carica_dispari_positivi(vet);

    visualizza_vettore(vet);

    return 0;
}

// Carica nel vettore i primi DIM numeri positivi e dispari (1, 3, 5, 7, ...)
void carica_dispari_positivi(int v[]) {
    for (int i = 0; i < DIM; i++) {
        v[i] = 2 * i + 1;
    }
}

void visualizza_vettore(int v[]) {
    printf("Contenuto del vettore (Indice -> Valore):\n");
    for (int i = 0; i < DIM; i++) {
        printf("Indice [%d] = %d\n", i, v[i]);
    }
}