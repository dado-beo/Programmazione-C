#include <stdio.h>

int main(void) {
    int n;
    char c, n_esimo;

    printf("Inserisci un valore intero: ");
    scanf("%d", &n);
    printf("Inserisci un carattere: ");
    scanf(" %c", &c); // Nota lo spazio prima di %c per ignorare eventuali spazi bianchi nel buffer
    
    n_esimo = c + n; // Calcola il carattere n-esimo nella sequenza ASCII
    printf("Il carattere %d-esimo dopo '%c' è: '%c'\n", n, c, n_esimo);

    return 0;
}