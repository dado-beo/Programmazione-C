#include <stdio.h>

// Prototipi
void scambio(int* valore1, int* valore2);
void decrescente(int* a, int* b, int* c);

int main(void) {
    int a, b, c;

    printf("Inserisci i valori di tre variabili: ");
    scanf("%d %d %d", &a, &b, &c);

    printf("Valori iniziali: a = %d, b = %d, c = %d\n", a, b, c);

    decrescente(&a, &b, &c);

    printf("Valori ordinati (decrescente): a = %d, b = %d, c = %d\n", a, b, c);

    return 0;

}

void scambio(int* valore1, int* valore2) {
    int t;
    t = *valore1;
    *valore1 = *valore2;
    *valore2 = t;
}

// Funzione che ordina a, b, c inserendo max in a, mezzo in b e min in c
void decrescente(int* a, int* b, int* c) {
    // 1. Se a è minore di b, li scambia per portare il maggiore in a
    if (*a < *b) {
        scambio(a, b);
    }
    // 2. Se b è minore di c, li scambia per far scendere il minore verso c
    if (*b < *c) {
        scambio(b, c);
    }
    // 3. Ricontrolla le prime due per garantire l'ordine tra a e b
    if (*a < *b) {
        scambio(a, b);
    }
}