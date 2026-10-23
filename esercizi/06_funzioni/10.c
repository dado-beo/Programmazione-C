#include <stdio.h>

// Prototipi delle funzioni
int booleanoTriangolo(float lato1, float lato2, float lato3);
int booleanoTipoTriangolo(float lato1, float lato2, float lato3);
int booleanoRettangolo(float lato1, float lato2, float lato3);

int main(void) {
    float lato1, lato2, lato3;

    printf("Inserisci tre valori: ");
    scanf("%f %f %f", &lato1, &lato2, &lato3);

    int e_Triangolo = booleanoTriangolo(lato1, lato2, lato3);

    if (e_Triangolo == 1) {
        printf("I valori inseriti sono i lati di un triangolo.\n");
        
        int tipo = booleanoTipoTriangolo(lato1, lato2, lato3);
        
        if (tipo == 0) {
            printf("Tipo: isoscele equilatero\n");
        } else if (tipo == 1) {
            printf("Tipo: isoscele non equilatero\n");
        } else {
            printf("Tipo: scaleno\n");
        }

        // Se isoscele non equilatero (1) o scaleno (2), controlla se è rettangolo
        if (tipo == 1 || tipo == 2) {
            int rettangolo = booleanoRettangolo(lato1, lato2, lato3);
            if (rettangolo == 1) {
                printf("Il triangolo e' rettangolo.\n");
            } else {
                printf("Il triangolo e' non rettangolo.\n");
            }
        }

    } else {
        printf("I valori inseriti non sono i lati di un triangolo.\n");
    }

    return 0;
}

int booleanoTriangolo(float lato1, float lato2, float lato3) {
    if (lato1 > 0 && lato2 > 0 && lato3 > 0 &&
        lato1 < (lato2 + lato3) && 
        lato2 < (lato1 + lato3) && 
        lato3 < (lato1 + lato2)) {
        return 1;
    }
    return 0;
}

int booleanoTipoTriangolo(float lato1, float lato2, float lato3) {
    if (lato1 == lato2 && lato2 == lato3) {
        return 0; // Equilatero
    } else if (lato1 == lato2 || lato1 == lato3 || lato2 == lato3) {
        return 1; // Isoscele non equilatero
    } else {
        return 2; // Scaleno
    }
}

// Verifica se il triangolo è rettangolo tramite il Teorema di Pitagora
int booleanoRettangolo(float lato1, float lato2, float lato3) {
    float a2 = lato1 * lato1;
    float b2 = lato2 * lato2;
    float c2 = lato3 * lato3;

    // Controlla tutte e 3 le combinazioni
    if ((a2 + b2 == c2) || (a2 + c2 == b2) || (b2 + c2 == a2)) {
        return 1;
    }
    return 0;
}