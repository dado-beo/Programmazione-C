#include <stdio.h>

#define DIM 5

// Prototipi delle funzioni
void riempi_vettore(int v[]);
void visualizza_vettore(int v[]);
void scambia(int *p1, int *p2);
int ordina_decrescente(int v[]);

int main(void) {
    int vet[DIM];
    int scambi_effettuati;

    // Invoca la funzione per caricare il vettore
    riempi_vettore(vet);

    // Visualizza il vettore prima dell'ordinamento
    printf("\nVettore iniziale:\n");
    visualizza_vettore(vet);

    // Invoca la funzione di ordinamento e salva il numero di scambi
    scambi_effettuati = ordina_decrescente(vet);

    // Visualizza il vettore dopo l'ordinamento
    printf("\nVettore ordinato:\n");
    visualizza_vettore(vet);

    // Visualizza la quantità di scambi effettuati
    printf("\n%d scambi effettuati\n", scambi_effettuati);

    return 0;
}

void riempi_vettore(int v[]) {
    printf("Inserisci %d valori: \n", DIM);
    for (int i = 0; i < DIM; i++) {
        printf("v[%d] = ", i);
        scanf("%d", &v[i]);
    }
}

void visualizza_vettore(int v[]) {
    for (int i = 0; i < DIM; i++) {
        printf("Indice %d: valore %d\n", i, v[i]);
    }
}

void scambia(int *p1, int *p2) {
    // Utilizza una variabile temporanea per scambiare i valori
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int ordina_decrescente(int v[]) {
    int contatore_scambi = 0;
    
    // Algoritmo di ordinamento Bubble Sort adattato per l'ordine decrescente
    for (int i = 0; i < DIM - 1; i++) {
        for (int j = 0; j < DIM - 1 - i; j++) {
            // Se l'elemento corrente è MINORE del successivo, li scambiamo
            if (v[j] < v[j + 1]) {
                // Invoca la funzione passando l'indirizzo degli elementi
                scambia(&v[j], &v[j + 1]);
                contatore_scambi++;
            }
        }
    }
    
    return contatore_scambi;
}