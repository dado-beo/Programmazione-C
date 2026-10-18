#include <stdio.h>

int main(void) {
    int n1, n2, n3;
    int max;

    printf("Inserisci tre numeri interi: ");
    scanf("%d %d %d", &n1, &n2, &n3);

    max = n1;

    if (n2 > max) {
        max = n2;
    }

    if (n3 > max) {
        max = n3;
    }

    printf("Il numero maggiore e': %d\n", max);

    return 0;
}