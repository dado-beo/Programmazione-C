#include <stdio.h>

#define DIM 5

// Prototipi delle funzioni
void riempi_vettore(int v[]);
int cerca_valore_nel_vettore(int v[], int x);


int main (void) {
    int vet[DIM];
    int x;

    riempi_vettore(vet);
    
    printf("Inserisci il valore da cercare nel vettore: ");
    scanf("%d", &x);
    int trovato =cerca_valore_nel_vettore(vet, x);

    if (!trovato) {
        printf("Il valore %d non è presente nel vettore.\n", x);
    } else {
        printf("Il valore %d è presente nel vettore.\n", x);
    }

    return 0;
}

void riempi_vettore(int v[]) {
    printf("Inserisci %d valori: \n", DIM);
    for (int i = 0; i < DIM; i++) {
        printf("v[%d] = ", i);
        scanf("%d", &v[i]);
    }
}

int cerca_valore_nel_vettore(int v[], int x) {
    int trovato = 0; // Variabile per indicare se il valore è stato trovato

    for (int i = 0; i < DIM; i++) {
        if (v[i] == x) {
            trovato = 1; // Imposto trovato a 1 se il valore è stato trovato
            break;
        }
    }

    return trovato;
}