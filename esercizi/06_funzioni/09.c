#include <stdio.h>

// Prototipi delle funzioni
int leggi_mese(void);
int leggi_anno(void);
int e_bisestile(int anno);
int calcola_giorni(int mese, int anno);

int main(void) {
    int mese, anno, giorni;

    mese = leggi_mese();
    anno = leggi_anno();

    giorni = calcola_giorni(mese, anno);

    printf("Il mese %d dell'anno %d e' composto da %d giorni.\n", mese, anno, giorni);

    return 0;
}

// Funzione che legge e controlla il mese (1-12)
int leggi_mese(void) {
    int m;
    do {
        printf("Inserire un mese espresso come numero tra 1 e 12: ");
        scanf("%d", &m);

        if (m < 1 || m > 12) {
            printf("ERRORE: il mese deve essere compreso tra 1 e 12.\n");
        }
    } while (m < 1 || m > 12);

    return m;
}

// Funzione che legge e controlla l'anno (4 cifre)
int leggi_anno(void) {
    int a;
    do {
        printf("Inserire un anno composto da 4 cifre: ");
        scanf("%d", &a);

        if (a < 1000 || a > 9999) {
            printf("ERRORE: l'anno deve essere composto da 4 cifre.\n");
        }
    } while (a < 1000 || a > 9999);

    return a;
}

// Funzione booleana: restituisce 1 se bisestile, 0 altrimenti
int e_bisestile(int anno) {
    if ((anno % 4 == 0 && anno % 100 != 0) || (anno % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

// Funzione per il calcolo dei giorni del mese
int calcola_giorni(int mese, int anno) {
    int giorni;

    switch (mese) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            giorni = 31;
            break;

        case 4: case 6: case 9: case 11:
            giorni = 30;
            break;

        case 2:
            if (e_bisestile(anno)) {
                giorni = 29;
            } else {
                giorni = 28;
            }
            break;

        default:
            giorni = 0;
            break;
    }

    return giorni;
}