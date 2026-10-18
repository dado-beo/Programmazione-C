#include <stdio.h>

int main(void) {
    int n1, n2;
    printf("Inserisci due numeri interi: ");
    scanf("%d %d", &n1, &n2);

    if(n1 % n2 == 0) {
        printf("%d è multiplo di %d\n", n1, n2);
    } else {
        printf("%d non è multiplo di %d\n", n1, n2);
    }

    return 0;
}