#include <stdio.h>

#define R 4
#define C 5

void caricaMatrice(int mat[R][C]) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            mat[i][j] = (rand() % 90) + 10; // Genera un numero tra 10 e 99
        }
    }
}

void visualizzaMatrice(int mat[R][C]) {
    printf("Contenuto della matrice:\n\n");
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("[%d][%d]: %2d   ", i, j, mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void compatibilitàColonna(int mat[R][C]) {
    int indiceColonna;
    do {
        printf("Inserisci l'indice di una colonna: ");
        scanf("%d", &indiceColonna);
        if (indiceColonna < 0 || indiceColonna >= C) {
            printf("ERRORE: l'indice non e' compatibile.\n");
        } else {
            break; // Esci dal ciclo se l'indice è valido
        }
    } while (1);
}

int massimoValoreColonna(int mat[R][C], int indiceColonna) {
    int max = mat[0][indiceColonna];
    for(int j = 1; j < R; j++) {
        if(mat[j][indiceColonna] > max) {
            max = mat[j][indiceColonna];
        }
    }
    return max;
}


int main (void) {
    int matrice[R][C];

    // Riempi la matrice con numeri casuali compresi tra 10 e 99
    caricaMatrice(matrice);
    visualizzaMatrice(matrice);

    // Chiede all'utente di inserire l'indice di una colonna
    compatibilitàColonna(matrice);

    // restituisce il massimo dei valori su quella colonna
    int indiceColonna;
    printf("Inserisci l'indice della colonna per trovare il massimo valore: ");
    scanf("%d", &indiceColonna);
    int max = massimoValoreColonna(matrice, indiceColonna);
    printf("Il massimo valore della colonna %d e': %d\n", indiceColonna, max);

    return 0;
}