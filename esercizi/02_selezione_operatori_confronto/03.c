#include <stdio.h>
#include <stdlib.h> // Necessario per utilizzare la funzione abs()

int main(void) {
    int x;
    int val_assoluto_if;
    int val_assoluto_abs;

    printf("Inserisci un numero intero: ");
    scanf("%d", &x);

    val_assoluto_if = x;
    if (x < 0) {
        val_assoluto_if = -x; // Inverte il segno se negativo
    }

    val_assoluto_abs = abs(x);
    
    printf("Valore assoluto (con il costrutto 'if'):  %d\n", val_assoluto_if);
    printf("Valore assoluto (con la funzione 'abs'): %d\n", val_assoluto_abs);

    return 0;
}
