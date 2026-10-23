#include <stdio.h>

// Prototipo
float max(float v1, float v2, float v3);

int main (void) {
    float v1, v2, v3, risultato;

    printf("Inserisci tre valori: ");
    scanf("%f %f %f", &v1, &v2, &v3);

    risultato = max(v1, v2, v3);

    printf("Il valore massimo e': %.2f\n", risultato);

    return 0;
}

float max(float v1, float v2, float v3) {
    float vMax;
    
    if (v1 >= v2 && v1 >= v3) {
        vMax = v1;
    } else if (v2 >= v1 && v2 >= v3) {
        vMax = v2;
    } else {
        vMax = v3;
    }
    
    return vMax;
}