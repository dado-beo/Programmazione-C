#include <stdio.h>

// Prototipi
int leggi_argomento(void);
int fattoriale(int x);

int main(void) {
    int n, f;

    n = leggi_argomento();

    f = fattoriale(n);

    printf("Il fattoriale di %d vale %d.\n", n, f);

    return 0;
}

int leggi_argomento(void) {
    int x;

    do {
        printf("Inserire l'argomento del fattoriale: ");
        scanf("%d", &x);

        if (x < 0) {
            printf("ERRORE: l'argomento non deve essere negativo.\n"); //
        }
    } while (x < 0);

    return x;
}

int fattoriale(int x) {
    int i, fatt = 1;

    for (i = 1; i <= x; i++) {
        fatt = fatt * i;
    }

    return fatt;
}