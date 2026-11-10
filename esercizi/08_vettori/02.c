#include <stdio.h>

#define DIM 3

// Prototipi di funzione
void riempi_vettore(int v[]);
void visualizza_vettore_decrescente(int v[]);

int main (void) {
    int vet[DIM];

    riempi_vettore(vet);
    visualizza_vettore_decrescente(vet);

    return 0;
}

void riempi_vettore(int v[]) {
    printf("Inserisci %d valori:\n", DIM);
    for (int i = 0; i < DIM; i++) {
        printf("v[%d] = ", i);
        scanf("%d", &v[i]);
    }
}