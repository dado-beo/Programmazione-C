#include <stdio.h>

// Prototipi
void sommaProdottoMedia(float a, float b, float c, float* somma, float* prodotto, float* media);

int main (void) {
    float a, b, c;
    float somma, prodotto, media;

    printf("Inserisci i tre valori: ");
    scanf("%f %f %f", &a, &b, &c);

    sommaProdottoMedia(a, b, c, &somma, &prodotto, &media);

    printf("La somma vale %.2f, il prodotto vale %.2f, la media vale %.2f.", somma, prodotto, media);
    return 0;
}

void sommaProdottoMedia(float a, float b, float c, float* somma, float* prodotto, float* media) {
    *somma = a + b + c;
    *prodotto = ((a) * (b) * (c));
    *media = (a + b + c) / 3;
}