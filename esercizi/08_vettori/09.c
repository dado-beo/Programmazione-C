#include <stdio.h>

#define DIM 5

// Prototipi delle funzioni
void carica_multipli(int v[], int x);
void visualizza_vettore(int v[]);

int main(void) {
    int vet[DIM];
    int x;

    printf("Inserisci il valore x per generare i multipli: ");
    scanf("%d", &x);

    carica_multipli(vet, x);

    visualizza_vettore(vet);

    return 0;
}

// calcola e carica i multipli di x nel vettore
void carica_multipli(int v[], int x) {
    for (int i = 0; i < DIM; i++) {
        v[i] = x * (i + 1); // I multipli partono da x * 1, x * 2, ecc.
    }
}

void visualizza_vettore(int v[]) {
    printf("\nContenuto del vettore (Indice -> Valore):\n");
    for (int i = 0; i < DIM; i++) {
        printf("Indice [%d] = %d\n", i, v[i]);
    }
}