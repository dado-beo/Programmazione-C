#include <stdio.h>

#define DIM 4 // Imposto a 4 per replicare l'esempio della traccia

// Prototipi delle funzioni
void riempi_vettore(int v[]);
void unisci_vettori(int v1[], int v2[], int v3[]);
void visualizza_vettore(int v[], int dim);

int main(void) {
    // Dichiara due vettori della stessa dimensione
    int v1[DIM];
    int v2[DIM];
    
    // Dichiara un terzo vettore con dimensione doppia
    int v3[DIM * 2];

    // Invoca la funzione per caricare da tastiera il primo vettore
    printf("--- Caricamento Vettore 1 ---\n");
    riempi_vettore(v1);

    // Invoca la funzione per caricare da tastiera il secondo vettore
    printf("\n--- Caricamento Vettore 2 ---\n");
    riempi_vettore(v2);

    // Invoca la funzione per copiare i valori
    unisci_vettori(v1, v2, v3);

    // Invoca la funzione per visualizzare, applicata al terzo vettore
    printf("\n--- Vettore 3 (Unito) ---\n");
    // Passiamo DIM * 2 (cioè 8) come dimensione
    visualizza_vettore(v3, DIM * 2); 

    return 0;
}

void riempi_vettore(int v[]) {
    printf("Inserisci %d valori: \n", DIM);
    for (int i = 0; i < DIM; i++) {
        printf("[%d] = ", i);
        scanf("%d", &v[i]);
    }
}

void unisci_vettori(int v1[], int v2[], int v3[]) {
    // 1. Copia i valori del primo vettore (v1) in v3
    for (int i = 0; i < DIM; i++) {
        v3[i] = v1[i];
    }
    
    // 2. Copia i valori del secondo vettore (v2) di seguito in v3
    for (int i = 0; i < DIM; i++) {
        // v2 parte dall'indice 0, ma in v3 dobbiamo scriverli spostati in avanti.
        // Aggiungendo 'DIM' all'indice, iniziamo a scrivere esattamente 
        // da dove avevamo finito con v1.
        v3[i + DIM] = v2[i]; 
    }
}

void visualizza_vettore(int v[], int dim) {
    // A differenza delle versioni precedenti, qui il limite del ciclo non è la 
    // costante DIM, ma la variabile 'dim' passata come parametro
    for (int i = 0; i < dim; i++) {
        printf("Indice %d: valore %d\n", i, v[i]);
    }
}