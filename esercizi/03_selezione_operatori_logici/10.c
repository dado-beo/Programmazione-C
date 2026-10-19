#include <stdio.h>

int main(void) {
    int giorno, mese, anno;
    int e_bisestile;
    int giorni_max;
    int data_valida = 1; // Variabile flag: 1 = valida, 0 = non valida

    printf("Inserisci giorno, mese e anno separati da spazio: ");
    scanf("%d %d %d", &giorno, &mese, &anno);

    if (anno < 1000 || anno > 9999) {
        data_valida = 0;
    }

    if (mese < 1 || mese > 12) {
        data_valida = 0;
    }

    if (data_valida) {
        e_bisestile = ((anno % 4 == 0 && anno % 100 != 0) || (anno % 400 == 0));

        if (mese == 2) {
            if (e_bisestile) {
                giorni_max = 29;
            } else {
                giorni_max = 28;
            }
        } else if (mese == 4 || mese == 6 || mese == 9 || mese == 11) {
            giorni_max = 30;
        } else {
            giorni_max = 31;
        }

        if (giorno < 1 || giorno > giorni_max) {
            data_valida = 0;
        }
    }

    if (data_valida) {
        printf("la data ha il formato corretto\n");
    } else {
        printf("la data non ha il formato corretto\n");
    }

    return 0;
}