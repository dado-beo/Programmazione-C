#include <stdio.h>

#define DIM 3

// Prototipi di funzione
void riempi_vettore(int v[]);
void visualizza_vettore_valore_massimo(int v[]);

int main (void) {
    int vet[DIM];

    riempi_vettore(vet);
    visualizza_vettore_valore_massimo(vet);

    return 0;
}

void riempi_vettore(int v[]) {
    printf("Inserisci %d valori:\n", DIM);
    for (int i = 0; i < DIM; i++) {
        printf("v[%d] = ", i);
        scanf("%d", &v[i]);
    }
}

void visualizza_vettore_valore_massimo(int v[]) {
    int i;
    int massimo = v[0]; // Inizializzo il massimo con il primo elemento del vettore

    // Ciclo per trovare il valore massimo
    for (i = 1; i < DIM; i++) {
        if (v[i] > massimo) {
            massimo = v[i];
        }
    }

    printf("\nIl valore massimo nel vettore è: %d\n", massimo);
}