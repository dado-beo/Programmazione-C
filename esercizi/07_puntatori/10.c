#include <stdio.h>

// Prototipi
int giorniDelMese(int mese, int anno);
void inserisciData(int* giorno, int* mese, int* anno);

int main(void) {
    int giorno, mese, anno;

    inserisciData(&giorno, &mese, &anno);

    printf("%02d/%02d/%04d\n", giorno, mese, anno);

    return 0;
}

// Funzione che calcola e restituisce il numero di giorni in base a mese e anno
int giorniDelMese(int mese, int anno) {
    if (mese < 1 || mese > 12) {
        return 0; // Mese non valido
    }

    switch (mese) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            // Controllo anno bisestile: divisibile per 4 e non per 100, oppure divisibile per 400
            if ((anno % 4 == 0 && anno % 100 != 0) || (anno % 400 == 0)) {
                return 29;
            } else {
                return 28;
            }
        default:
            return 0;
    }
}

// Funzione che legge la data e ne verifica la validita' invocando giorniDelMese
void inserisciData(int* giorno, int* mese, int* anno) {
    int maxGiorni;
    int dataValida;

    do {
        printf("Inserisci giorno, mese e anno (di 4 cifre): ");
        scanf("%d %d %d", giorno, mese, anno);

        // Calcolo del numero massimo di giorni per il mese e anno inseriti
        maxGiorni = giorniDelMese(*mese, *anno);

        // Verifica: anno di 4 cifre, mese valido (maxGiorni > 0) e giorno compreso tra 1 e maxGiorni
        if (*anno >= 1000 && *anno <= 9999 && maxGiorni > 0 && *giorno >= 1 && *giorno <= maxGiorni) {
            dataValida = 1;
        } else {
            dataValida = 0;
            printf("ERRORE: data non corretta\n");
        }
    } while (!dataValida);
}