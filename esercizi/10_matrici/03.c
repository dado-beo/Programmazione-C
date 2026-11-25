#include <stdio.h>

#define R 4
#define C 5

void caricaMatrice(int matrice[R][C]) {
    int listaValoriPrimaRiga[C]; 
    
    printf("Inserisci i valori per la prima riga:\n");
    for (int j = 0; j < C; j++) {
        printf("Valore per la colonna %d: ", j);
        scanf("%d", &listaValoriPrimaRiga[j]);
        // salviamo i valori inseriti nella prima riga della matrice
        matrice[0][j] = listaValoriPrimaRiga[j]; 
    }

    // Caricamento delle righe successive
    for (int i = 1; i < R; i++) {
        for (int a = 0; a < C; a++) {
            matrice[i][a] = matrice[i - 1][a] + 1;
        }
    }
}

void visualizzaMatrice(int matrice[R][C]) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int matrice[R][C];

    // 
    caricaMatrice(matrice);
    visualizzaMatrice(matrice);

    return 0;
}