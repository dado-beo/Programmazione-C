#include <stdio.h>

#define R 4
#define C 5

void riempiMatrice(int matrice[R][C]) {
    printf("Riempi la matrice con numeri casuali: \n");
    int n;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("Inserisci un numero per la posizione [%d][%d]: ", i, j);
            scanf("%d", &n);
            matrice[i][j] = n;
        }
    }
}

void ordinataCrescente(int matrice[R][C]) {
    int ordinata = 1;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C - 1; j++) {
            if (matrice[i][j] > matrice[i][j + 1]) {
                ordinata = 0;
                break;
            }
        }
        if (!ordinata) {
            break;
        }
    }
    if (ordinata) {
        printf("La matrice e' ordinata in senso crescente.\n");
    } else {
        printf("La matrice non e' ordinata in senso crescente.\n");
    }
}

int main(void) {
    int matrice[R][C];

    riempiMatrice(matrice);
    ordinataCrescente(matrice);

    return 0;
}