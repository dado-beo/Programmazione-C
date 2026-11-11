#include <stdio.h>

#define DIM 5

// Prototipi delle funzioni
void riempi_vettore(int v[]);
int verifica_ordine(int v[]);

int main(void) {
    int vet[DIM];
    int risultato;

    // Invoca la funzione per caricare il vettore da tastiera
    riempi_vettore(vet);

    // Invoca la funzione per verificare l'ordine del vettore
    risultato = verifica_ordine(vet);

    // Visualizza il messaggio corrispondente
    if (risultato == 1) {
        printf("il vettore e' ordinato in modo crescente\n");
    } else if (risultato == 2) {
        printf("il vettore e' ordinato in modo decrescente\n");
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

int verifica_ordine(int v[]) {
    // Inizializziamo due flag supponendo inizialmente 
    // che il vettore sia sia crescente che decrescente
    int crescente = 1;
    int decrescente = 1;

    for (int i = 0; i < DIM - 1; i++) {
        // Se troviamo un elemento maggiore del successivo, non può essere crescente
        if (v[i] > v[i + 1]) {
            crescente = 0;
        }
        // Se troviamo un elemento minore del successivo, non può essere decrescente
        if (v[i] < v[i + 1]) {
            decrescente = 0;
        }
    }
    
    // Controlliamo flag
    if (crescente == 1) {
        return 1;
    } else if (decrescente == 1) {
        return 2;
    } else {
        return 0; // non è ordinato
    }
}