#include <stdio.h>

int main(void) {
    float a, b, c;
    int e_rettangolo;

    printf("Inserisci tre valori separati da spazio: ");
    scanf("%f %f %f", &a, &b, &c);

    if ((a > 0 && b > 0 && c > 0) &&
        (a < b + c) && (b < a + c) && (c < a + b)) {

        printf("I valori inseriti POSSONO formare un triangolo.\n");

        e_rettangolo = ((a * a + b * b == c * c) ||
                        (a * a + c * c == b * b) ||
                        (b * b + c * c == a * a));

        if (a == b && b == c) {
            printf("Tipologia: Triangolo EQUILATERO.\n");
        } 
        else if (a == b || a == c || b == c) {
            // Caso 2 & 3: Isoscele (normale o rettangolo)
            if (e_rettangolo) {
                printf("Tipologia: Triangolo ISOSCELE RETTANGOLO.\n");
            } else {
                printf("Tipologia: Triangolo ISOSCELE.\n");
            }
        } 
        else {
            // Caso 4 & 5: Scaleno (normale o rettangolo)
            if (e_rettangolo) {
                printf("Tipologia: Triangolo SCALENO RETTANGOLO.\n");
            } else {
                printf("Tipologia: Triangolo SCALENO.\n");
            }
        }

    } else {
        printf("I valori inseriti NON possono formare un triangolo.\n");
    }

    return 0;
}