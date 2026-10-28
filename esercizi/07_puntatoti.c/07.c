#include <stdio.h>

// Definizione della costante Pi Greco
#define PI 3.14159f

// Prototipi delle funzioni
float raggioCerchio(void);
void calcoloCirconferenzaArea(float raggio, float* circonferenza, float* area);

int main(void) {
    float raggio, circonferenza, area;

    raggio = raggioCerchio();

    calcoloCirconferenzaArea(raggio, &circonferenza, &area);

    printf("La circonferenza vale %.2f, l'area vale %.2f\n", circonferenza, area);

    return 0;
}

float raggioCerchio(void) {
    float raggio;

    do {
        printf("Inserisci il raggio di un cerchio: ");
        scanf("%f", &raggio);

        if (raggio <= 0) {
            printf("ERRORE: il raggio non e' positivo!\n");
        }
    } while (raggio <= 0);

    return raggio;
}

void calcoloCirconferenzaArea(float raggio, float* circonferenza, float* area) {
    *circonferenza = 2 * PI * raggio;
    *area = PI * raggio * raggio;
}