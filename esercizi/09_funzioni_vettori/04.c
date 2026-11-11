#include <stdio.h>

#define DIM 5

// Prototipi delle funzioni
void riempi_vettore(int v[]);
int verifica_ordinamento(int v[]);

int main(void) {
    int vet[DIM];
    int risultato;

    // Invoca la funzione per caricare il vettore da tastiera
    riempi_vettore(vet);

    // Invoca la funzione per verificare l'ordine crescente
    risultato = verifica_ordinamento(vet);

    // Visualizza il messaggio corrispondente
    if (risultato == 1) {
        printf("il vettore e' ordinato\n");
    } else {
        printf("il vettore non e' ordinato\n");
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

int verifica_ordinamento(int v[]) {
    // Scorriamo il vettore fermandoci al penultimo elemento (DIM - 1)
    for (int i = 0; i < DIM - 1; i++) {
        // Se un elemento è strettamente maggiore di quello successivo,
        // l'ordinamento crescente è interrotto
        if (v[i] > v[i + 1]) {
            return 0; 
        }
    }
    
    // Se il ciclo termina senza interruzioni, significa che 
    // l'ordine crescente è stato rispettato per tutti gli elementi
    return 1; 
}