#include <stdio.h>

#define DIM 4 // Usiamo 4 per replicare l'esempio della traccia

// Prototipi delle funzioni
void riempi_vettore_ordinato(int v[]);
void merge_vettori(int v1[], int v2[], int v3[]);
void visualizza_vettore(int v[], int dim);

int main(void) {
    // Dichiara due vettori della stessa dimensione
    int v1[DIM];
    int v2[DIM];
    
    // Dichiara un terzo vettore con dimensione doppia
    int v3[DIM * 2];

    // Invoca la funzione per caricare e verificare il primo vettore
    printf("--- Caricamento Vettore 1 ---\n");
    riempi_vettore_ordinato(v1);

    // Invoca la funzione per caricare e verificare il secondo vettore
    printf("\n--- Caricamento Vettore 2 ---\n");
    riempi_vettore_ordinato(v2);

    // Invoca la funzione per fondere i due vettori mantenendo l'ordine
    merge_vettori(v1, v2, v3);

    // Invoca la funzione per visualizzare il risultato finale
    printf("\n--- Vettore 3 (Unito e Ordinato) ---\n");
    visualizza_vettore(v3, DIM * 2);

    return 0;
}

void riempi_vettore_ordinato(int v[]) {
    printf("Inserisci %d valori in ordine crescente:\n", DIM);
    for (int i = 0; i < DIM; i++) {
        // Usiamo un costrutto do-while per ripetere la richiesta in caso di errore
        do {
            printf("[%d] = ", i);
            scanf("%d", &v[i]);
            
            // Il controllo si fa solo a partire dal secondo elemento (i > 0)
            // Se l'elemento inserito è minore di quello precedente, c'è un errore
            if (i > 0 && v[i] < v[i - 1]) {
                printf("ERRORE: %d non e' ordinato (deve essere >= %d)\n", v[i], v[i - 1]);
            }
            
        } while (i > 0 && v[i] < v[i - 1]); // Ripete se la condizione di errore è vera
    }
}

void merge_vettori(int v1[], int v2[], int v3[]) {
    int i = 0; // Indice per scorrere v1
    int j = 0; // Indice per scorrere v2
    int k = 0; // Indice per scrivere in v3

    // 1. Fase di fusione (Merge): finché ci sono elementi in ENTRAMBI i vettori
    while (i < DIM && j < DIM) {
        // Confrontiamo l'elemento attuale di v1 con quello di v2
        if (v1[i] < v2[j]) {
            v3[k] = v1[i]; // Vince v1, lo copiamo
            i++;           // Facciamo avanzare solo l'indice di v1
        } else {
            v3[k] = v2[j]; // Vince v2, lo copiamo
            j++;           // Facciamo avanzare solo l'indice di v2
        }
        k++; // L'indice del vettore destinazione avanza sempre
    }

    // 2. Svuotamento rimasugli di v1: 
    // Se v2 è finito ma v1 ha ancora elementi, li copiamo tutti così come sono
    while (i < DIM) {
        v3[k] = v1[i];
        i++;
        k++;
    }

    // 3. Svuotamento rimasugli di v2:
    // Se v1 è finito ma v2 ha ancora elementi, li copiamo tutti così come sono
    while (j < DIM) {
        v3[k] = v2[j];
        j++;
        k++;
    }
}

void visualizza_vettore(int v[], int dim) {
    for (int i = 0; i < dim; i++) {
        printf("Indice %d: valore %d\n", i, v[i]);
    }
}