#include <stdio.h>

#define DIM 3

// Prototipi di funzione
void riempi_vettore(int v[]);
void visualizza_vettore(int v[]);

int main (void) {
    int vet[DIM];

    riempi_vettore(vet);
    visualizza_vettore(vet);

    return 0;
}

void riempi_vettore(int v[]) {
    int i;
    printf("Inserisci %d valori:\n", DIM);
    for (i = 0; i < DIM; i++) {
        printf("v[%d] = ", i);
        scanf("%d", &v[i]);
    }
}

void visualizza_vettore(int v[]) {
    int i;
    printf("\nContenuto del vettore:\n");
    for (i = 0; i < DIM; i++) {
        printf("v[%d] = %d\n", i, v[i]);
    }
}
