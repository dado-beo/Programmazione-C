#include <stdio.h>

int main() {
    int a, b, c, d;
    int somma, media, prodotto;

    printf("Inserisci il primo numero: ");
    scanf("%d", &a);
    printf("Inserisci il secondo numero: ");
    scanf("%d", &b);
    printf("Inserisci il terzo numero: ");
    scanf("%d", &c);
    printf("Inserisci il quarto numero: ");
    scanf("%d", &d);

    somma = a + b + c + d;
    media = (float)somma / 4; // Type casting (float) per evitare la troncatura intera
    prodotto = a * b * c * d;
    
    printf("La somma è: %d\n", somma);
    printf("La media è: %f\n", media);
    printf("Il prodotto è: %d\n", prodotto);

    return 0;
}