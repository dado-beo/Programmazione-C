#include <stdio.h>

void scambio(int* valore1, int* valore2);

int main (void) {
    int numero1, numero2;

    printf("Inserire due valori interi: ");
    scanf("%d %d", &numero1, &numero2);

    scambio(&numero1, &numero2);

    printf("I valori scambiati sono: %d e %d\n", numero1, numero2);

    return 0;
}

void scambio(int* valore1, int* valore2) {
    int t; 

    t = *valore1;           // Salvo il valore puntato da valore1 in t
    *valore1 = *valore2;    // Metto il valore puntato da valore2 dentro valore1
    *valore2 = t;           // Metto il valore temporaneo t dentro valore2
}