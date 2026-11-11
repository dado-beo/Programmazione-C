#include <stdio.h>

#define DIM 5

// Prototipi delle funzioni
void riempi_vettore(int v[]);
int verifica_uguali(int v[]);

int main(void) {
    int vet[DIM];
    int risultato;

    riempi_vettore(vet);

    // Invoca la funzione per verificare se i valori sono tutti uguali
    risultato = verifica_uguali(vet);

    // Visualizza il messaggio corrispondente
    if (risultato == 1) {
        printf("valori uguali\n");
    } else {
        printf("valori diversi\n");
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

int verifica_uguali(int v[]) {
    // Confrontiamo tutti gli elementi con il primo elemento (in posizione 0)
    for (int i = 1; i < DIM; i++) {
        // Se ne troviamo anche solo uno diverso dal primo, i valori non sono tutti uguali
        if (v[i] != v[0]) {
            return 0; 
        }
    }
    
    // Se il ciclo termina senza aver trovato differenze, i valori sono tutti uguali
    return 1; 
}