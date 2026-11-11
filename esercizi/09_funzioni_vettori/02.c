#include <stdio.h>

#define DIM 5

// Prototipi delle funzioni
void riempi_vettore(int v[]);
void ricerca_occorrenze(int v[], int x, int *p1, int *p2);

int main (void) {
    int vet[DIM];
    int valore_da_cercare;
    int prima_occ, ultima_occ;

    // Carica il vettore
    riempi_vettore(vet);

    // Chiede all'utente di inserire un valore
    printf("Inserisci il valore da cercare: ");
    scanf("%d", &valore_da_cercare);

    // Ricerca il valore nel vettore passando gli indirizzi di prima_occ e ultima_occ
    ricerca_occorrenze(vet, valore_da_cercare, &prima_occ, &ultima_occ);

    // Visualizza i risultati in base a quanto richiesto
    if (prima_occ == -1) {
        printf("nessuna occorrenza\n");
    } else if (prima_occ == ultima_occ) {
        printf("unica occorrenza in posizione %d\n", prima_occ);
    } else {
        printf("prima occorrenza in posizione %d\n", prima_occ);
        printf("ultima occorrenza in posizione %d\n", ultima_occ);
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

void ricerca_occorrenze(int v[], int x, int *p1, int *p2) {
    // Inizializza i parametri di output a -1 (valore assente)
    *p1 = -1;
    *p2 = -1;

    for (int i = 0; i < DIM; i++) {
        if (v[i] == x) {
            // Se p1 è ancora -1, significa che è la prima volta che troviamo 'x'
            if (*p1 == -1) {
                *p1 = i;
            }
            // Aggiorniamo sempre p2 ogni volta che troviamo 'x'
            // Alla fine del ciclo conterrà l'indice dell'ultima occorrenza
            *p2 = i; 
        }
    }
}