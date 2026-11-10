#include <stdio.h>

#define DIM 3

// Prototipi delle funzioni
void riempi_vettore(int v[]);
void calcola_min_max(int v[], int *p1, int *p2);

int main(void) {
    int vet[DIM];
    int min, max;

    riempi_vettore(vet);

    calcola_min_max(vet, &min, &max);

    printf("\nIl minimo e' %d e il massimo e' %d\n", min, max);

    return 0;
}

void riempi_vettore(int v[]) {
    printf("Inserisci %d valori:\n", DIM);
    for (int i = 0; i < DIM; i++) {
        printf("v[%d] = ", i);
        scanf("%d", &v[i]);
    }
}

void calcola_min_max(int v[], int *p1, int *p2) {
    // Inizializziamo i valori puntati da p1 e p2 con il primo elemento del vettore
    *p1 = v[0];
    *p2 = v[0];

    for (int i = 1; i < DIM; i++) {
        if (v[i] < *p1) {
            *p1 = v[i]; 
        }
        if (v[i] > *p2) {
            *p2 = v[i]; 
        }
    }
}