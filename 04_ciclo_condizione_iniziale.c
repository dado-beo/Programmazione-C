/*
 * =====================================================================================
 *  NOME FILE: 04_ciclo_condizione_iniziale.c
 *  CORSO: Programmazione C (UPO)
 *  ARGOMENTO: Cicli con Condizione Iniziale e Contatore (while, for),
 *             Sommatoria, Produttoria, Fattoriale, Selezione + Ciclo e Ciclo + Selezione
 * =====================================================================================
 *
 * --- REGOLE E CONCETTI TEORICI COMPLETI (Tratti dalle slide) ---
 *
 * 1. CHE COS'È UN CICLO (ITERAZIONE):
 *    Permette di ripetere un blocco di comandi (corpo del ciclo) per un certo numero
 *    di volte senza dover duplicare il codice (evitando il "copia-incolla").
 *
 * 2. ELEMENTI DI UN CICLO CON CONTATORE:
 *    - CONTATORE: Variabile intera (es. 'i') che conta le iterazioni eseguite.
 *    - INIZIALIZZAZIONE: Valore di partenza assegnato prima del ciclo (es. i = 0 oppure i = 1).
 *    - CONDIZIONE DI CICLO: Condizione valutata PRIMA di ogni iterazione (es. i < n).
 *      Se VERA, il corpo viene eseguito; se FALSA, il ciclo termina.
 *    - INCREMENTO / DECREMENTO: Modifica del contatore (es. i++, i = i + 2, i--) che
 *      consente di far progredire la variabile e garantire la terminazione del ciclo.
 *
 * 3. CONFRONTO SINTATTICO: 'while' VS 'for'
 *    - CICLO while:
 *        i = 0;                  // Inizializzazione esterna
 *        while (i < n) {         // Condizione
 *            // comandi...
 *            i++;                // Incremento dentro il corpo
 *        }
 *    - CICLO for:
 *        for (i = 0; i < n; i++) { // Concentra inizializzazione, condizione e incremento
 *            // comandi...
 *        }
 *      Nota: L'algoritmo sottostante è identico; cambia solo la compattezza della notazione.
 *
 * 4. ELEMENTI NEUTRI DELLE OPERAZIONI:
 *    - SOMMATORIA (somma accumulata): Inizializzata a 0 (elemento neutro della somma: 0 + x = x).
 *    - PRODUTTORIA (prodotto accumulato): Inizializzata a 1 (elemento neutro del prodotto: 1 * x = x).
 *      ATTENZIONE: Inizializzare una produttoria a 0 renderà il risultato finale SEMPRE 0!
 *
 * 5. TRAPPOLI ED ERRORI COMUNI D'ESAME (ATTENZIONE!):
 *    a) MANCATA INIZIALIZZAZIONE: Se 'i' non viene inizializzata prima del ciclo, contiene un
 *       valore "spazzatura" e il ciclo potrebbe non eseguire affatto o eseguire erratamente.
 *    b) MANCATO INCREMENTO / LOOP INFINITO: Se dimentichi 'i++' nel 'while', 'i' rimane invariata,
 *       la condizione resta sempre vera e il programma entra in un "infinite loop" (si ferma con CTRL+C).
 *    c) PUNTO E VIRGOLA DOPO L'INTESTAZIONE:
 *       - `while (i < 3);` -> Crea un ciclo vuoto infinito (se 'i' non cambia).
 *       - `for (i = 0; i < 3; i++);` -> Il ciclo esegue solo l'incremento di 'i' fino a 3;
 *         il blocco tra graffe successivo NON farà parte del ciclo e verrà eseguito UNA SOLA VOLTA!
 *    d) MANCANZA DELLE PARENTESI GRAFFE { }:
 *       - Nel 'while': Solo il primo comando viene ripetuto. Se l'incremento 'i++' era il secondo
 *         comando, viene escluso dal ciclo, generando un loop infinito!
 *       - Nel 'for': Solo il primo comando viene ripetuto n volte. I comandi successivi vengono
 *         eseguiti una sola volta fuori dal ciclo.
 *    e) DOPPIO INCREMENTO NEL 'for': Scrivere 'i++' nell'intestazione del 'for' E ANCHE dentro
 *       il corpo provoca l'incremento di 2 a ogni passo, dimezzando le iterazioni previste.
 *
 * 6. STRUTTURE COMBINATE:
 *    - SELEZIONE CON CICLO (if che racchiude un ciclo):
 *      Es. Controllare se n >= 0 prima di avviare il ciclo per il calcolo del fattoriale.
 *    - CICLO CON SELEZIONE (ciclo che racchiude un if):
 *      Es. Trovare il massimo tra n numeri: al primo passo (i == 0) si inizializza max = x,
 *      nei passi successivi si confronta x > max.
 */

#include <stdio.h>

int main(void) {

    // =========================================================================
    // 1. SOMMATORIA DI N NUMERI (Confronto while vs for)
    // =========================================================================
    printf("=== 1. SOMMATORIA DI N VALORI (while vs for) ===\n");
    int n, x, somma, i;

    printf("Quanti numeri vuoi sommare? ");
    scanf("%d", &n);

    // --- Versione A: Ciclo WHILE ---
    somma = 0; // Elemento neutro della somma
    i = 0;     // Inizializzazione del contatore
    while (i < n) {
        printf("[WHILE] Inserisci l'intero #%d: ", i + 1);
        scanf("%d", &x);
        somma = somma + x; // Accumulo
        i++;               // Incremento indispensabile per evitare il loop infinito
    }
    printf("La somma totale con WHILE vale: %d\n", somma);

    // --- Versione B: Ciclo FOR ---
    somma = 0; // Reset della variabile di accumulo
    for (i = 0; i < n; i++) {
        printf("[FOR] Inserisci l'intero #%d: ", i + 1);
        scanf("%d", &x);
        somma = somma + x;
    }
    printf("La somma totale con FOR vale: %d\n\n", somma);


    // =========================================================================
    // 2. PRODUTTORIA DI N NUMERI (Elemento neutro = 1)
    // =========================================================================
    printf("=== 2. PRODUTTORIA DI N VALORI ===\n");
    int prodotto;

    printf("Quanti numeri vuoi moltiplicare tra loro? ");
    scanf("%d", &n);

    prodotto = 1; // IMPORTANTE: Inizializzare a 1 (elemento neutro della moltiplicazione)
    for (i = 0; i < n; i++) {
        printf("Inserisci il fattore #%d: ", i + 1);
        scanf("%d", &x);
        prodotto = prodotto * x;
    }
    printf("Il prodotto totale vale: %d\n\n", prodotto);


    // =========================================================================
    // 3. CALCOLO DEL FATTORIALE (n!) - Varianti Crescente e Decrescente
    // =========================================================================
    printf("=== 3. CALCOLO DEL FATTORIALE (n!) ===\n");
    int n_fatt, fattoriale;

    printf("Inserisci un numero intero positivo per calcolarne il fattoriale: ");
    scanf("%d", &n_fatt);

    // --- Variante 1: Crescente (i varia da 1 a n_fatt, condizione i <= n_fatt) ---
    fattoriale = 1;
    for (i = 1; i <= n_fatt; i++) {
        fattoriale = fattoriale * i; // 'i' assume sia il ruolo di contatore che di fattore
    }
    printf("Fattoriale di %d (algoritmo crescente 1..n): %d\n", n_fatt, fattoriale);

    // --- Variante 2: Decrescente (i varia da n_fatt a 1, condizione i > 0, decremento i--) ---
    fattoriale = 1;
    for (i = n_fatt; i > 0; i--) {
        fattoriale = fattoriale * i;
    }
    printf("Fattoriale di %d (algoritmo decrescente n..1): %d\n\n", n_fatt, fattoriale);


    // =========================================================================
    // 4. GENERAZIONE DI SEQUENZE CON INCREMENTO PERSONALIZZATO
    // =========================================================================
    printf("=== 4. NUMERI PARI COMPRESI TRA 2 E 100 ===\n");
    printf("Stampa numeri pari (incremento i = i + 2):\n");
    
    // In questo ciclo 'i' parte da 2, avanza di 2 a ogni passo e include il 100 (i <= 100)
    for (i = 2; i <= 100; i = i + 2) {
        printf("%d\t", i);
        if (i % 20 == 0) { // Semplice formattazione per andare a capo ogni 10 numeri
            printf("\n");
        }
    }
    printf("\n\n");


    // =========================================================================
    // 5. SELEZIONE CON CICLO (if-else racchiude un ciclo)
    // =========================================================================
    printf("=== 5. SELEZIONE CON CICLO (Fattoriale sicuro) ===\n");
    int n_sicuro;

    printf("Inserisci un numero per il fattoriale (con controllo validita'): ");
    scanf("%d", &n_sicuro);

    // Controllo preliminare di validita' (n >= 0)
    if (n_sicuro < 0) {
        printf("ERRORE: Impossibile calcolare il fattoriale di un numero negativo!\n\n");
    } else {
        fattoriale = 1;
        for (i = 1; i <= n_sicuro; i++) {
            fattoriale = fattoriale * i;
        }
        printf("Fattoriale calcolato con successo: %d! = %d\n\n", n_sicuro, fattoriale);
    }


    // =========================================================================
    // 6. CICLO CON SELEZIONE (Ciclo racchiude un if-else - Ricerca del Massimo)
    // =========================================================================
    printf("=== 6. CICLO CON SELEZIONE (Ricerca del Massimo) ===\n");
    int num_elementi, max;

    printf("Quanti valori vuoi inserire per trovare il massimo? ");
    scanf("%d", &num_elementi);

    if (num_elementi <= 0) {
        printf("Nessun elemento da elaborare.\n");
    } else {
        for (i = 0; i < num_elementi; i++) {
            printf("Inserisci il valore #%d: ", i + 1);
            scanf("%d", &x);

            // Alla prima iterazione (i == 0) il primo valore inserito diventa il massimo iniziale
            if (i == 0) {
                max = x;
            } else {
                // Per le iterazioni successive, si aggiorna max solo se il nuovo valore e' maggiore
                if (x > max) {
                    max = x;
                }
            }
        }
        printf("Il massimo valore inserito e': %d\n", max);
    }

    return 0;
}