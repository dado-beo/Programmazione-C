#include <stdio.h>
#include <stdlib.h>

#define R 4
#define C 5

void riempiMatrice(int matrice[R][C]) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            matrice[i][j] = (rand() % 9) + 1; // Genera un numero tra 1 e 9
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

void cercaValore(int matrice[R][C], int x, int *p1, int *p2) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (matrice[i][j] == x) {
                *p1 = i;
                *p2 = j;
                return; // trovato
            }
        }
    }
    // il valore non è stato trovato
    *p1 = -1;
    *p2 = -1;
}

int main (void) {
    int matrice[R][C];
    int x, p1, p2;

    riempiMatrice(matrice);
    visualizzaMatrice(matrice);

    // Chiede all'utente di inserire un valore da cercare
    printf("Inserisci un valore da cercare nella matrice: ");
    scanf("%d", &x);
    // passando gli indirizzi &p1 e &p2
    cercaValore(matrice, x, &p1, &p2);

    // Visualizzazione risultato
    if (p1 == -1 && p2 == -1) {
        printf("Il valore %d e' assente.\n", x);
    } else {
        printf("Il valore %d e' presente sulla riga %d, colonna %d.\n", x, p1, p2);
    }

    return 0;
}