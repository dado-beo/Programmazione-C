#include <stdio.h>

#define PIGRECO 3.141592

// Prototipi delle funzioni
float leggi_valore_positivo(void);
char leggi_tipo_figura(void);
float area_cerchio(float raggio);
float area_quadrato(float lato);

int main(void) {
    float misura, area;
    char figura;

    misura = leggi_valore_positivo();

    figura = leggi_tipo_figura();

    if (figura == 'C' || figura == 'c') {
        area = area_cerchio(misura);
        printf("L'area del cerchio di raggio %.2f e' %.2f\n", misura, area);
    } else {
        area = area_quadrato(misura);
        printf("L'area del quadrato di lato %.2f e' %.2f\n", misura, area);
    }

    return 0;
}

// Funzione che richiede un valore float > 0
float leggi_valore_positivo(void) {
    float val;
    do {
        printf("Inserire un valore (positivo): ");
        scanf("%f", &val);

        if (val <= 0) {
            printf("ERRORE: il valore deve essere positivo.\n");
        }
    } while (val <= 0);

    return val;
}

// Funzione che richiede un carattere ('C' o 'Q')
char leggi_tipo_figura(void) {
    char c;
    do {
        printf("Inserire C per il cerchio o Q per il quadrato: ");
        // Lo spazio prima di %c pulisce il buffer dal tasto Invio precedente
        scanf(" %c", &c);

        if (c != 'C' && c != 'c' && c != 'Q' && c != 'q') {
            printf("ERRORE: il carattere deve essere C o Q.\n");
        }
    } while (c != 'C' && c != 'c' && c != 'Q' && c != 'q');

    return c;
}

// Funzione per il calcolo dell'area del cerchio
float area_cerchio(float raggio) {
    return PIGRECO * raggio * raggio;
}

// Funzione per il calcolo dell'area del quadrato
float area_quadrato(float lato) {
    return lato * lato;
}