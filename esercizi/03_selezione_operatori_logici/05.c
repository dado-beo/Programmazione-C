#include <stdio.h>

int main() {
    int x, y;

    printf("Inserisci le coordinate del punto (x, y): ");
    scanf("%d %d", &x, &y);

    if( x == 0 && y == 0) {
        printf("Il punto (%d,%d) si trova nell'origine del piano cartesiano.\n", x, y);
    } else if( x == 0 ) {
        printf("Il punto (%d,%d) si trova sull'asse delle ordinate (y).\n", x, y);
    } else if( y == 0 ) {
        printf("Il punto (%d,%d) si trova sull'asse delle ascisse (x).\n", x, y);
    } else if( x > 0 && y > 0 ) {
        printf("Il punto (%d,%d) si trova nel primo quadrante.\n", x, y);
    } else if( x < 0 && y > 0 ) {
        printf("Il punto (%d,%d) si trova nel secondo quadrante.\n", x, y);
    } else if( x < 0 && y < 0 ) {
        printf("Il punto (%d,%d) si trova nel terzo quadrante.\n", x, y);
    } else if( x > 0 && y < 0 ) {
        printf("Il punto (%d,%d) si trova nel quarto quadrante.\n", x, y);
    }

    return 0;
}