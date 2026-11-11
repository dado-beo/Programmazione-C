/*
 * =====================================================================================
 *  NOME FILE: 09_funzioni_vettori.c
 *  CORSO: Programmazione C
 *  ARGOMENTO: Funzioni per Vettori: Verifica Proprieta, Ricerca, Ordinamento e Shift
 * =====================================================================================
 *
 * --- NOTE SULLA TEORIA (Tratte dalle slide) ---
 * 1. VERIFICA DI PROPRIETÀ PER TUTTI I VALORI:
 *    - Inizialmente si assume che la proprieta valga per tutti (p = 1).
 *    - Si analizza un elemento alla volta. Se un valore NON rispetta la proprieta,
 *      questa cade per l'intero vettore (p = 0) e il ciclo viene INTERROTTO (uscita anticipata).
 *    - Condizione ciclo: `for (i = 0; i < DIM && p; i++)`
 *    - ERRORE COMUNE: Sovrascrivere `p` a ogni passo con l'operazione `if (v[i]>0) p=1 else p=0;`
 *      fa si che il risultato dipenda SOLO DALL'ULTIMO ELEMENTO!
 *
 * 2. VERIFICA DI PROPRIETÀ PER ALMENO UN VALORE:
 *    - Inizialmente si assume che nessun valore rispetti la proprieta (p = 0).
 *    - Se si trova anche solo UN valore che la rispetta, p passa a 1 e il ciclo si INTERROMPA.
 *    - Condizione ciclo: `for (i = 0; i < DIM && !p; i++)`
 *
 * 3. RICERCA IN UN VETTORE:
 *    - Presenza/Assenza: analogo ad "almeno un valore".
 *    - Prima Occorrenza: restituisce l'indice i del primo elemento trovato (interrompe il ciclo).
 *    - Ultima Occorrenza: deve scorrere TUTTO il vettore aggiornando l'indice ogni volta che trova x.
 *    - Conteggio Occorrenze: incrementa un contatore per ogni occorrenza di x trovata.
 *
 * 4. ORDINAMENTO (Bubble Sort):
 *    - Verifica Ordine: controlla che v[i] <= v[i+1] (oppure v[i] >= v[i-1]).
 *    - Ordinamento a Bolle: usa due cicli annidati (i da 0 a DIM-2, j da i+1 a DIM-1).
 *      Se v[i] > v[j], si effettua lo scambio (swap) tramite una variabile temporanea k.
 *
 * 5. SHIFT DEL VETTORE:
 *    - Shift a Sinistra: scorre da sinistra a destra (i=0 a DIM-2). v[i] = v[i+1].
 *      * Non circolare: v[DIM-1] diventa 0.
 *      * Circolare: il primo elemento originale (v[0]) viene salvato prima e messo in v[DIM-1].
 *    - Shift a Destra: scorre da destra a sinistra (i=DIM-1 a 1). v[i] = v[i-1].
 *      * Non circolare: v[0] diventa 0.
 *      * Circolare: l'ultimo elemento originale (v[DIM-1]) viene salvato prima e messo in v[0].
 */

#include <stdio.h>

// Definizione della costante per la dimensione del vettore
#define DIM 10

/* ==========================================
 * PROTOTIPI DI FUNZIONE
 * ========================================== */
void carica_vettore(int v[]);
void visualizza_vettore(int v[]);

// 1. Verifica Proprieta
int tutti_positivi(int v[]);
int tutti_positivi_ERRATO(int v[]); // Esempio didattico di errore
int esiste_positivo(int v[]);

// 2. Ricerca
int cerca_valore(int v[], int x);
int prima_occorrenza(int v[], int x);
int ultima_occorrenza(int v[], int x);
int conta_occorrenze(int v[], int x);

// 3. Ordinamento
int verifica_ordine(int v[]);
void ordina_vettore(int v[]);

// 4. Shift (Spostamenti)
void shift_sinistra_non_circolare(int v[]);
void shift_sinistra_circolare(int v[]);
void shift_destra_non_circolare(int v[]);
void shift_destra_circolare(int v[]);

/* ==========================================
 * MAIN PROGRAM
 * ========================================== */
int main(void) {
    int vet[DIM];
    int scelta, x, res;

    printf("=== GESTIONE AVANZATA VETTORI (Slide 09) ===\n");
    printf("Dimensione del vettore: %d elementi.\n\n", DIM);

    // Caricamento iniziale e visualizzazione
    carica_vettore(vet);
    visualizza_vettore(vet);

    do {
        printf("\n--- MENU OPERAZIONI ---\n");
        printf(" 1. Verifica se TUTTI i valori sono positivi\n");
        printf(" 2. DIMOSTRAZIONE ERRORE: Tutti positivi (errato)\n");
        printf(" 3. Verifica se ESISTE ALMENO UN valore positivo\n");
        printf(" 4. Cerca se un valore X e' presente (0/1)\n");
        printf(" 5. Trova la PRIMA occorrenza di X\n");
        printf(" 6. Trova l'ULTIMA occorrenza di X\n");
        printf(" 7. Conta il numero di occorrenze di X\n");
        printf(" 8. Verifica se il vettore e' ordinato crescente\n");
        printf(" 9. Ordina il vettore (Bubble Sort)\n");
        printf("10. Shift a SINISTRA (Non Circolare)\n");
        printf("11. Shift a SINISTRA (Circolare)\n");
        printf("12. Shift a DESTRAMA (Non Circolare)\n");
        printf("13. Shift a DESTRA (Circolare)\n");
        printf("14. Ricarica nuovi valori nel vettore\n");
        printf(" 0. Uscita\n");
        printf("Scegli un'opzione: ");
        scanf("%d", &scelta);
        printf("\n");

        switch (scelta) {
            case 1:
                if (tutti_positivi(vet))
                    printf("ESITO: Tutti i valori nel vettore SONO positivi.\n");
                else
                    printf("ESITO: NON tutti i valori sono positivi.\n");
                break;

            case 2:
                printf("ATTENZIONE: Questa funzione dimostra l'algoritmo sbagliato delle slide.\n");
                if (tutti_positivi_ERRATO(vet))
                    printf("ESITO ERRATO: Il codice dice che sono TUTTI positivi (guarda solo l'ultimo!).\n");
                else
                    printf("ESITO ERRATO: Il codice dice che NON sono tutti positivi.\n");
                break;

            case 3:
                if (esiste_positivo(vet))
                    printf("ESITO: Esiste ALMENO UN valore positivo nel vettore.\n");
                else
                    printf("ESITO: NESSUN valore e' positivo nel vettore.\n");
                break;

            case 4:
                printf("Inserisci il valore X da cercare: ");
                scanf("%d", &x);
                if (cerca_valore(vet, x))
                    printf("Valore %d PRESENTE nel vettore.\n", x);
                else
                    printf("Valore %d ASSENTE dal vettore.\n", x);
                break;

            case 5:
                printf("Inserisci il valore X: ");
                scanf("%d", &x);
                res = prima_occorrenza(vet, x);
                if (res != -1)
                    printf("La PRIMA occorrenza di %d si trova all'indice [%d].\n", x, res);
                else
                    printf("Valore %d NON trovato.\n", x);
                break;

            case 6:
                printf("Inserisci il valore X: ");
                scanf("%d", &x);
                res = ultima_occorrenza(vet, x);
                if (res != -1)
                    printf("L'ULTIMA occorrenza di %d si trova all'indice [%d].\n", x, res);
                else
                    printf("Valore %d NON trovato.\n", x);
                break;

            case 7:
                printf("Inserisci il valore X: ");
                scanf("%d", &x);
                printf("Il valore %d compare %d volte nel vettore.\n", x, conta_occorrenze(vet, x));
                break;

            case 8:
                if (verifica_ordine(vet))
                    printf("ESITO: Il vettore E' ordinato in modo crescente.\n");
                else
                    printf("ESITO: Il vettore NON e' ordinato.\n");
                break;

            case 9:
                ordina_vettore(vet);
                printf("Vettore ordinato con successo!\n");
                visualizza_vettore(vet);
                break;

            case 10:
                shift_sinistra_non_circolare(vet);
                printf("Effettuato Shift a Sinistra Non Circolare.\n");
                visualizza_vettore(vet);
                break;

            case 11:
                shift_sinistra_circolare(vet);
                printf("Effettuato Shift a Sinistra Circolare.\n");
                visualizza_vettore(vet);
                break;

            case 12:
                shift_destra_non_circolare(vet);
                printf("Effettuato Shift a Destra Non Circolare.\n");
                visualizza_vettore(vet);
                break;

            case 13:
                shift_destra_circolare(vet);
                printf("Effettuato Shift a Destra Circolare.\n");
                visualizza_vettore(vet);
                break;

            case 14:
                carica_vettore(vet);
                visualizza_vettore(vet);
                break;

            case 0:
                printf("Uscita dal programma.\n");
                break;

            default:
                printf("Opzione non valida! Riprova.\n");
        }
    } while (scelta != 0);

    return 0;
}

/* ==========================================
 * DEFINIZIONE DELLE FUNZIONI
 * ========================================== */

// Funzione per caricare i valori nel vettore
void carica_vettore(int v[]) {
    int i;
    printf("--- Inserimento Valori ---\n");
    for (i = 0; i < DIM; i++) {
        printf("Inserisci valore per v[%d]: ", i);
        scanf("%d", &v[i]);
    }
    printf("\n");
}

// Funzione per stampare a schermo il vettore
void visualizza_vettore(int v[]) {
    int i;
    printf("--- Contenuto Vettore ---\n[ ");
    for (i = 0; i < DIM; i++) {
        printf("%d ", v[i]);
    }
    printf("]\n\n");
}

/* ---------------------------------------------------------------------
 * 1. PROPRIETA' RISPETTATA DA TUTTI I VALORI
 * --------------------------------------------------------------------- */

// CORRETTO: Si ferma non appena trova un elemento che NON rispetta la proprieta
int tutti_positivi(int v[]) {
    int i, positivi;
    positivi = 1; // Inizialmente si assume che la proprieta valga per tutti

    // Il ciclo prosegue solo finche i valori sono positivi (positivi == 1)
    for (i = 0; i < DIM && positivi; i++) {
        if (!(v[i] > 0)) {
            positivi = 0; // Trovato un valore <= 0, la proprieta cade per tutti
        }
    }
    return positivi; // Restituisce 1 se tutti positivi, 0 altrimenti
}

// ERRATO (Dal test/slide): Sovrascrive positivi a ogni passo!
int tutti_positivi_ERRATO(int v[]) {
    int i, positivi;
    for (i = 0; i < DIM; i++) {
        if (v[i] > 0)
            positivi = 1;
        else
            positivi = 0;
    }
    // Errore: 'positivi' dipende ESCLUSIVAMENTE dall'ultimo elemento del vettore!
    return positivi;
}

/* ---------------------------------------------------------------------
 * 2. PROPRIETA' RISPETTATA DA ALMENO UN VALORE
 * --------------------------------------------------------------------- */

// CORRETTO: Si ferma non appena trova ALMENO UN valore che rispetta la proprieta
int esiste_positivo(int v[]) {
    int i, positivo;
    positivo = 0; // Inizialmente si assume che nessun valore sia positivo

    // Il ciclo prosegue finche !positivo e' vero (ovvero positivo == 0)
    for (i = 0; i < DIM && !positivo; i++) {
        if (v[i] > 0) {
            positivo = 1; // Trovato almeno un valore positivo!
        }
    }
    return positivo; // Restituisce 1 se esiste almeno un positivo, 0 altrimenti
}

/* ---------------------------------------------------------------------
 * 3. RICERCA DI UN VALORE NEL VETTORE
 * --------------------------------------------------------------------- */

// Controlla se x e' presente nel vettore (0 = no, 1 = si)
int cerca_valore(int v[], int x) {
    int i, presente = 0;
    for (i = 0; i < DIM && !presente; i++) {
        if (v[i] == x) {
            presente = 1;
        }
    }
    return presente;
}

// Restituisce l'indice della PRIMA occorrenza di x (oppure -1 se assente)
int prima_occorrenza(int v[], int x) {
    int i, pos = -1;
    for (i = 0; i < DIM && pos == -1; i++) {
        if (v[i] == x) {
            pos = i; // Trovata prima occorrenza, si esce dal ciclo
        }
    }
    return pos;
}

// Restituisce l'indice dell'ULTIMA occorrenza di x (oppure -1 se assente)
int ultima_occorrenza(int v[], int x) {
    int i, pos = -1;
    // DEVE scorrere tutto il vettore senza interrompersi
    for (i = 0; i < DIM; i++) {
        if (v[i] == x) {
            pos = i; // Aggiorna ogni volta che lo ritrova
        }
    }
    return pos;
}

// Conta quante volte il valore x compare nel vettore
int conta_occorrenze(int v[], int x) {
    int i, cnt = 0;
    for (i = 0; i < DIM; i++) {
        if (v[i] == x) {
            cnt++;
        }
    }
    return cnt;
}

/* ---------------------------------------------------------------------
 * 4. VERIFICA E ORDINAMENTO (BUBBLE SORT)
 * --------------------------------------------------------------------- */

// Verifica se i valori sono ordinati in modo crescente (v[i] >= v[i-1])
int verifica_ordine(int v[]) {
    int i, ordine = 1;
    // Parte dall'indice 1 e confronta con l'elemento precedente (i-1)
    for (i = 1; i < DIM && ordine; i++) {
        if (v[i] < v[i - 1]) {
            ordine = 0; // Trovata una coppia non ordinata
        }
    }
    return ordine;
}

// Ordina il vettore in modo crescente tramite scambio (Bubble Sort)
void ordina_vettore(int v[]) {
    int i, j, k;
    for (i = 0; i < DIM - 1; i++) {
        for (j = i + 1; j < DIM; j++) {
            if (v[i] > v[j]) {
                // Scambio (Swap) dei due valori tramite variabile d'appoggio k
                k = v[i];
                v[i] = v[j];
                v[j] = k;
            }
        }
    }
}

/* ---------------------------------------------------------------------
 * 5. SHIFT DEL VETTORE
 * --------------------------------------------------------------------- */

// Shift a sinistra NON circolare: il primo elemento si perde, l'ultimo diventa 0
void shift_sinistra_non_circolare(int v[]) {
    int i;
    for (i = 0; i < DIM - 1; i++) {
        v[i] = v[i + 1];
    }
    v[DIM - 1] = 0;
}

// Shift a sinistra CIRCOLARE: il primo elemento originale finisce in fondo
void shift_sinistra_circolare(int v[]) {
    int i, k;
    k = v[0]; // Salva il primo valore originale
    for (i = 0; i < DIM - 1; i++) {
        v[i] = v[i + 1];
    }
    v[DIM - 1] = k; // Il primo elemento originale va in ultima posizione
}

// Shift a destra NON circolare: l'ultimo elemento si perde, il primo diventa 0
void shift_destra_non_circolare(int v[]) {
    int i;
    for (i = DIM - 1; i > 0; i--) {
        v[i] = v[i - 1];
    }
    v[0] = 0;
}

// Shift a destra CIRCOLARE: l'ultimo elemento originale finisce in cima
void shift_destra_circolare(int v[]) {
    int i, k;
    k = v[DIM - 1]; // Salva l'ultimo valore originale
    for (i = DIM - 1; i > 0; i--) {
        v[i] = v[i - 1];
    }
    v[0] = k; // L'ultimo elemento originale va in prima posizione
}