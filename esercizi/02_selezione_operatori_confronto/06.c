#include <stdio.h>

int main(void) {
    float raggioCirconferenza, circonferenza, area;

    printf("Inserisci il raggio della circonferenza: ");
    scanf("%f", &raggioCirconferenza);

    if( raggioCirconferenza > 0) {
        circonferenza = 2 * 3.141592 * raggioCirconferenza;
        area = 3.141592 * raggioCirconferenza * raggioCirconferenza;

        printf("La circonferenza è: %f\n", circonferenza);
        printf("L'area è: %f\n", area);
    } else {
        printf("Il raggio deve essere maggiore di 0.\n");
    }
    return 0;
}