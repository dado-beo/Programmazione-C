#include <stdio.h>

// Prototipi
void scambio(int* valore1, int* valore2);
void crescente(int* a, int* b, int* c);

int main(void) {
    int a, b, c;

    printf("Inserisci i valori di tre variabili: ");
    scanf("%d %d %d", &a, &b, &c);

    printf("Valori iniziali: a = %d, b = %d, c = %d\n", a, b, c);

    crescente(&a, &b, &c);

    printf("Valori ordinati: a = %d, b = %d, c = %d\n", a, b, c);

    return 0;
}

void scambio(int* valore1, int* valore2) {
    int t;
    t = *valore1;
    *valore1 = *valore2;
    *valore2 = t;
}

// Funzione che ordina a, b, c inserendo min in a, mezzo in b e max in c
void crescente(int* a, int* b, int* c) {
    // 1. Confronta e ordina le prime due variabili
    if (*a > *b) {
        scambio(a, b);
    }
    // 2. Confronta e ordina le ultime due variabili
    if (*b > *c) {
        scambio(b, c);
    }
    // 3. Ricontrolla le prime due per garantire l'ordine definitivo
    if (*a > *b) {
        scambio(a, b);
    }
}