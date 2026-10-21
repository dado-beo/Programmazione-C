#include <stdio.h>

int main(void) {
    int n;
    int sum = 0, i = 1;

    printf("Quanti primi n numeri naturali vuoi sommare? ");
    scanf("%d", &n);

    while (i <= n) {
        sum += i;
        i++;
    }
   
    printf("La somma dei primi %d numeri naturali è: %d\n", n, sum);
    
    return 0;
}