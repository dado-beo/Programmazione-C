#include <stdio.h>

#define R 4
#define C 5

void riempiMatriceNaturali(int matrice[R][C]) {
    int numero = 1; // Inizializza il numero naturale da inserire
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            matrice[i][j] = numero++; // Assegna il numero e incrementa
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

    riempiMatriceNaturali(matrice);
    visualizzaMatrice(matrice);

    return 0;
}