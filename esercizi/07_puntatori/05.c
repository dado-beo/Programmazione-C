#include <stdio.h>

// Prototipo
void minMax(float a, float b, float c, float* min, float* max);

int main(void) {
    float v1, v2, v3;
    float minimo, massimo;

    printf("Inserisci tre valori: ");
    scanf("%f %f %f", &v1, &v2, &v3);

    minMax(v1, v2, v3, &minimo, &massimo);

    printf("Il minimo vale %.2f, il massimo vale %.2f\n", minimo, massimo);

    return 0;
}

// Funzione che calcola il minimo e il massimo tra tre numeri
void minMax(float a, float b, float c, float* min, float* max) {
    // Inizializzazione
    *min = a;
    *max = a;

    if (b < *min) {
        *min = b;
    }
    if (b > *max) {
        *max = b;
    }

    if (c < *min) {
        *min = c;
    }
    if (c > *max) {
        *max = c;
    }
}