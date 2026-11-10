#include <stdio.h>

#define DIM 3

// Prototipi di funzione
void riempi_vettore(int v[]);
void visualizza_vettore_valori_pari(int v[]);
void visualizza_vettore_valori_dispari(int v[]);

int main (void) {
    int vet[DIM];

    riempi_vettore(vet);
    visualizza_vettore_valori_pari(vet);
    visualizza_vettore_valori_dispari(vet);

    return 0;
}

void riempi_vettore(int v[]) {
    printf("Inserisci %d valori:\n", DIM);
    for (int i = 0; i < DIM; i++) {
        printf("v[%d] = ", i);
        scanf("%d", &v[i]);
    }
}

void visualizza_vettore_valori_pari(int v[]) {
    printf("\nContenuto del vettore (valori pari):\n");
    for (int i = 0; i < DIM; i++) {
        if (v[i] % 2 == 0) {
            printf("v[%d] = %d\n", i, v[i]);
        }
    }
}

void visualizza_vettore_valori_dispari(int v[]) {
    printf("\nContenuto del vettore (valori dispari):\n");
    for (int i = 0; i < DIM; i++) {
        if (v[i] % 2 != 0) {
            printf("v[%d] = %d\n", i, v[i]);
        }
    }
}