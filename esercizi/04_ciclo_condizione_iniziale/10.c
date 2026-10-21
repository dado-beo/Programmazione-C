#include <stdio.h>

int main(void) {
    int n;
    int i = 0;
    int contaColonna = 0;

    printf("Inserisci un intero maggiore di 0: ");
    scanf("%d", &n);
    while (n <= 0) {
        printf("Valore non valido, inserisci un intero maggiore di 0: ");
        scanf("%d", &n);
    }

    while(n >= 0) {
        printf("%6d\t", i);
        i++;
        contaColonna++;
        if(contaColonna == 4) {
            printf("\n");
            contaColonna = 0;
        }
        n--;
    }
    printf("\n");
    return 0;
}