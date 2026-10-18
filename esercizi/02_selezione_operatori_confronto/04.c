#include <stdio.h>

int main(void) {
    int n;

    printf("Inserisci un numero: ");
    scanf("%d", &n);

    if(n > 0) {
        printf("Il numero è positivo\n");
    } else if(n < 0) {
        printf("Il numero è negativo\n");
    } else {
        printf("Il numero è nullo\n");
    }

    return 0;
}