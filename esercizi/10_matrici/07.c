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

void uguali(int matrice[R][C]) {
    int uguali = 1;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (matrice[i][j] != matrice[0][0]) {
                uguali = 0;
                break;
            }
        }
        if (!uguali) {
            break;
        }
    }
    if (uguali) {
        printf("Tutti gli elementi della matrice sono uguali.\n");
    } else {
        printf("Gli elementi della matrice non sono tutti uguali.\n");
    }
}

int main(void) {
    int matrice[R][C];

    riempiMatrice(matrice);
    uguali(matrice);

    return 0;
}