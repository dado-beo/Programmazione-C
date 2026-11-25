#include <stdio.h>

#define R 4
#define C 5

void riempiMatrice(int matrice[R][C]) {
    int listaValoriPrimaColonna[R];

    printf("Inserisci i valori per la prima colonna:\n");
    for (int i = 0; i < R; i++) {
        printf("Valore per la riga %d: ", i);
        scanf("%d", &listaValoriPrimaColonna[i]);
        // salviamo i valori inseriti nella prima colonna della matrice
        matrice[i][0] = listaValoriPrimaColonna[i];
    }

    // Caricamento delle colonne successive
    for (int j = 1; j < C; j++) {
        for (int i = 0; i < R; i++) {
            matrice[i][j] = matrice[i][j - 1] * 2; // raddoppiamo il valore della colonna precedente
        }
    }
}

void visualizzaMatrice(int matrice[R][C]) {
    printf("Contenuto della matrice:\n\n");
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("[%d][%d]: %2d   ", i, j, matrice[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main (void) {
    int matrice[R][C];

    riempiMatrice(matrice);
    visualizzaMatrice(matrice);

    return 0;
}