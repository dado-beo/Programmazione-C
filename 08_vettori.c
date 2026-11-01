/*
 * =====================================================================================
 *  NOME FILE: 08_vettori.c
 *  CORSO: Programmazione C
 *  ARGOMENTO: Vettori (Array), Dichiarazione, Cicli e Passaggio per Riferimento
 * =====================================================================================
 *
 * --- NOTE SULLA TEORIA (Tratte dalle slide) ---
 * 1. COSA E' UN VETTORE: Un contenitore composto da più caselle (memoria contigua).
 *    Tutte le caselle contengono valori dello STESSO TIPO.
 * 2. CARATTERISTICHE:
 *    - Nome: Identificativo del vettore.
 *    - Dimensione (DIM): Quantità totale di valori.
 *    - Indici: Vanno da 0 a DIM-1. Il primo elemento è v[0], l'ultimo è v[DIM-1].
 * 3. DICHIARAZIONE E ASSEGNAMENTO:
 *    - Dichiarazione: tipo nome[dimensione]; (es. int v[10];)
 *    - Assegnamento diretto: v[0] = 1;
 *    - Inizializzazione: int v[10] = {1, 3, 5, ...};
 *    - I valori mancanti nell'inizializzazione vengono impostati a 0.
 * 4. GESTIONE CON I CICLI:
 *    - Per riempire o leggere un vettore, si usa quasi sempre un ciclo for che 
 *      scorre gli indici da i=0 fino a i<DIM.
 * 5. DIMENSIONE COME COSTANTE:
 *    - È buona pratica usare `#define DIM 10` per definire la grandezza del vettore,
 *      rendendo il codice più pulito e facile da modificare.
 * 6. PASSAGGIO AI SOTTOPROGRAMMI (FUNZIONI):
 *    - In C, i vettori sono SEMPRE passati per riferimento.
 *    - Scrivere `int v[]` come parametro equivale a scrivere `int* v`.
 *    - Invocare `funzione(vet)` equivale a passare l'indirizzo del primo elemento `&vet[0]`.
 *    - Le modifiche fatte al vettore dentro la funzione hanno effetto sul vettore originale nel main!
 */

#include <stdio.h>

// Definizione della costante per la dimensione del vettore
#define DIM 10

/* ==========================================
 * PROTOTIPI DI FUNZIONE
 * ========================================== */
void carica_vettore(int v[]);
void visualizza_vettore(int v[]);
int somma_vettore(int v[]);
int prodotto_vettore(int v[]);
float media_vettore(int v[]);
int massimo_vettore(int v[]);

int main(void) {
    // Dichiarazione del vettore e delle variabili per i risultati
    int vet[DIM];
    int sv, pv, max;
    float mv;

    printf("=== GESTIONE VETTORI ===\n");
    printf("Il vettore ha dimensione fissa: %d elementi.\n\n", DIM);

    // 1. Caricamento dei dati da tastiera
    carica_vettore(vet);

    // 2. Visualizzazione dei dati inseriti
    visualizza_vettore(vet);

    // 3. Calcolo e stampa della somma
    sv = somma_vettore(vet);
    printf("La somma vale %d\n", sv);

    // 4. Calcolo e stampa del prodotto
    pv = prodotto_vettore(vet);
    printf("Il prodotto vale %d\n", pv);

    // 5. Calcolo e stampa della media
    mv = media_vettore(vet);
    printf("La media vale %f\n", mv);

    // 6. Ricerca e stampa del valore massimo
    max = massimo_vettore(vet);
    printf("Il massimo vale %d\n", max);

    return 0; // Termina il programma
}

/* ==========================================
 * DEFINIZIONE DELLE FUNZIONI
 * ========================================== */

// Funzione per caricare i valori nel vettore
void carica_vettore(int v[]) {
    int i;
    printf("--- Inserimento Valori ---\n");
    for (i = 0; i < DIM; i++) {
        printf("Inserisci il valore per la casella [%d]: ", i);
        scanf("%d", &v[i]);
    }
    printf("\n");
}

// Funzione per stampare a schermo i valori del vettore
void visualizza_vettore(int v[]) {
    int i;
    printf("--- Contenuto del Vettore ---\n");
    for (i = 0; i < DIM; i++) {
        printf("v[%d] = %d\n", i, v[i]);
    }
    printf("\n");
}

// Funzione che calcola e restituisce la somma degli elementi
int somma_vettore(int v[]) {
    int i;
    int somma = 0; // Inizializzazione elemento neutro dell'addizione
    
    for (i = 0; i < DIM; i++) {
        somma = somma + v[i];
    }
    
    return somma;
}

// Funzione che calcola e restituisce il prodotto degli elementi
int prodotto_vettore(int v[]) {
    int i;
    int prodotto = 1; // Inizializzazione elemento neutro della moltiplicazione
    
    for (i = 0; i < DIM; i++) {
        prodotto = prodotto * v[i];
    }
    
    return prodotto;
}

// Funzione che calcola e restituisce la media degli elementi
float media_vettore(int v[]) {
    int i;
    int somma = 0;
    float media;
    
    // Ricalcolo la somma per fare la media
    for (i = 0; i < DIM; i++) {
        somma = somma + v[i];
    }
    
    // Cast esplicito a float per evitare la divisione intera
    media = (float)somma / DIM;
    
    return media;
}

// Funzione che trova e restituisce il valore massimo nel vettore
int massimo_vettore(int v[]) {
    int i;
    int massimo;
    
    for (i = 0; i < DIM; i++) {
        if (i == 0) {
            // Per il primo elemento, il massimo è l'elemento stesso
            massimo = v[i];
        } else {
            // Per gli elementi successivi, confronto con il massimo attuale
            if (v[i] > massimo) {
                massimo = v[i];
            }
        }
    }
    
    return massimo;
}