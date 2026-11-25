#include <stdio.h>

#define R 4
#define C 5

void riempiMatricePitagorica(int matrice[R][C]) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            matrice[i][j] = (i + 1) * (j + 1); // Calcola il prodotto dei numeri di riga e colonna
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

int main (void) {
    int matrice[R][C];

    riempiMatricePitagorica(matrice);
    visualizzaMatrice(matrice);


    return 0;
}