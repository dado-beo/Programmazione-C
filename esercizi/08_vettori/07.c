#include <stdio.h>

#define DIM 5

// Prototipi delle funzioni
void riempi_vettore(int v[]);
int calcola_somma(int v[]);
long long calcola_prodotto(int v[]);
float calcola_media(int v[]);

int main(void) {
    int vet[DIM];

    riempi_vettore(vet);

    int somma = calcola_somma(vet);
    long long prodotto = calcola_prodotto(vet);
    float media = calcola_media(vet);

    printf("\nla somma e' %d il prodotto e' %lld la media e' %.2f\n", somma, prodotto, media);

    return 0;
}

void riempi_vettore(int v[]) {
    printf("Inserisci %d valori interi:\n", DIM);
    for (int i = 0; i < DIM; i++) {
        printf("v[%d] = ", i);
        scanf("%d", &v[i]);
    }
}

int calcola_somma(int v[]) {
    int somma = 0;
    for (int i = 0; i < DIM; i++) {
        somma += v[i];
    }
    return somma;
}

long long calcola_prodotto(int v[]) {
    long long prodotto = 1;
    for (int i = 0; i < DIM; i++) {
        prodotto *= v[i];
    }
    return prodotto;
}

// calcolo della media (riutilizza calcola_somma)
float calcola_media(int v[]) {
    return (float)calcola_somma(v) / DIM;
}