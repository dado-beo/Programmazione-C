#include <stdio.h>

#define PIGRECO 3.141592

int main(void) {
    float raggio, area;
    
    printf("Inserisci il raggio del cerchio: ");
    scanf("%f", &raggio);
    
    area = PIGRECO * raggio * raggio;
    
    printf("L'area è: %f", area);
    
    return 0;
}