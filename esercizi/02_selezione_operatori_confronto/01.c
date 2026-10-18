#include <stdio.h>

int main(void) {
    int n;
    printf("Inserisci un numero: ");
    scanf("%d", &n);

    if(n % 2 == 0) {
        printf("Il numero è pari\n");
    } else {
        printf("Il numero è dispari\n");
    }

    return 0;
}