#include <stdio.h>

#define DIM 3

// Prototipi di funzione
void riempi_vettore(int v[]);
void visualizza_vettore_indice_pari(int v[]);
void visualizza_vettore_indice_dispari(int v[]);

int main (void) {
    int vet[DIM];

    riempi_vettore(vet);
    visualizza_vettore_indice_pari(vet);
    visualizza_vettore_indice_dispari(vet);

    return 0;
}

void riempi_vettore(int v[]) {
    printf("Inserisci %d valori:\n", DIM);
    for (int i = 0; i < DIM; i++) {
        printf("v[%d] = ", i);
        scanf("%d", &v[i]);
    }
}

void visualizza_vettore_indice_pari(int v[]) {
    printf("\nContenuto del vettore (indici pari):\n");
    for (int i = 0; i < DIM; i += 2) {
        printf("v[%d] = %d\n", i, v[i]);
    }
}

void visualizza_vettore_indice_dispari(int v[]) {
    printf("\nContenuto del vettore (indici dispari):\n");
    for (int i = 1; i < DIM; i += 2) {
        printf("v[%d] = %d\n", i, v[i]);
    }
}

