#include <stdio.h>

// Prototipo della funzione
int booleanoDivisori(int x);

int main(void) {
    int numero, e_primo;

    printf("Inserisci un numero intero: ");
    scanf("%d", &numero);

    e_primo = booleanoDivisori(numero);

    if (e_primo == 1) {
        printf("Il numero %d e' primo.\n", numero);
    } else {
        printf("Il numero %d non e' primo.\n", numero);
    }

    return 0;
}

int booleanoDivisori(int x) {
    int i, conta_divisori = 0;
    int booleano;

    // Se x <= 0 non e' un numero primo valido
    if (x <= 0) {
        return 0;
    }

    // Conta tutti i divisori di x da 1 a x
    for (i = 1; i <= x; i++) {
        if (x % i == 0) {
            conta_divisori++;
        }
    }

    // Un numero e' primo se ha 1 o 2 divisori
    if (conta_divisori == 1 || conta_divisori == 2) {
        booleano = 1; // Vero (e' primo)
    } else {
        booleano = 0; // Falso (non e' primo)
    }

    return booleano;
}