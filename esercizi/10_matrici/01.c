#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Dimensioni della matrice
#define RIGHE 4
#define COLONNE 5

// 1. Carica la matrice con numeri pseudo-casuali a una o due cifre (da 0 a 99)
void caricaMatrice(int mat[RIGHE][COLONNE]) {
    for (int i = 0; i < RIGHE; i++) {
        for (int j = 0; j < COLONNE; j++) {
            mat[i][j] = rand() % 100; // Genera un numero tra 0 e 99
        }
    }
}

// 2. Visualizza indici e valori della matrice
void visualizzaMatrice(int mat[RIGHE][COLONNE]) {
    printf("Contenuto della matrice:\n\n");
    for (int i = 0; i < RIGHE; i++) {
        for (int j = 0; j < COLONNE; j++) {
            printf("[%d][%d]: %2d   ", i, j, mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// 3. Calcola la somma della riga indicata o restituisce -1 se l'indice non è valido
int sommaRiga(int mat[RIGHE][COLONNE], int indiceRiga) {
    // Controllo compatibilità dell'indice
    if (indiceRiga < 0 || indiceRiga >= RIGHE) {
        return -1;
    }

    int somma = 0;
    for (int j = 0; j < COLONNE; j++) {
        somma += mat[indiceRiga][j];
    }
    return somma;
}

// 4. Funzione principale
int main() {
    // Inizializzazione del generatore di numeri pseudo-casuali
    srand(time(NULL));

    int matrice[RIGHE][COLONNE];
    int rigaScelta, risultato;

    // Caricamento e visualizzazione
    caricaMatrice(matrice);
    visualizzaMatrice(matrice);

    // Richiesta dell'indice all'utente
    printf("Inserisci l'indice della riga da sommare (da 0 a %d): ", RIGHE - 1);
    scanf("%d", &rigaScelta);

    // Calcolo e stampa del risultato
    risultato = sommaRiga(matrice, rigaScelta);

    if (risultato == -1) {
        printf("ERRORE: l'indice %d non e' compatibile.\n", rigaScelta);
    } else {
        printf("La somma della riga %d e' %d.\n", rigaScelta, risultato);
    }

    return 0;
}