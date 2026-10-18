#include <stdio.h>

#define PIGRECO 3.141592

int main(void) {
    float raggio, circonferenza;
    
    printf("Inserisci il raggio della circonferenza: ");
    scanf("%f", &raggio);
    
    circonferenza = 2 * PIGRECO * raggio;
    
    printf("La circonferenza è: %f", circonferenza);
    
    return 0;
}