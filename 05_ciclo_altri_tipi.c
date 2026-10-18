/*
 * =====================================================================================
 *  NOME FILE: 05_ciclo_altri_tipi.c
 *  CORSO: Programmazione C (UPO)
 *  ARGOMENTO: Cicli senza contatore (MCD), Ciclo con condizione finale (do-while),
 *             Controllo dell'Input e Variabili Logiche, Cicli Annidati (Matrici,
 *             Tavola Pitagorica, Diagonali e Cornici con De Morgan)
 * =====================================================================================
 *
 * --- REGOLE E CONCETTI TEORICI COMPLETI (Tratti dalle slide) ---
 *
 * 1. CICLO SENZA CONTATORE:
 *    Un ciclo `while` non necessita per forza di un contatore intero (i++). Può essere
 *    guidato dalla modifica delle variabili di stato del problema.
 *    - Esempio classico: Calcolo del Massimo Comune Denominatore (MCD) di Euclide
 *      tramite sottrazioni successive (MCD(a,b) = MCD(a-b, b) se a > b).
 *
 * 2. CICLO CON CONDIZIONE FINALE (do-while):
 *    - Sintassi:
 *        do {
 *            // comandi da ripetere
 *        } while (condizione);  <-- NOTA FONDAMENTALE: Richiede il punto e virgola ';' finale!
 *    - CARATTERISTICA CHIAVE: Il corpo del ciclo viene eseguito ALMENO UNA VOLTA, perché
 *      la condizione viene valutata DOPO l'esecuzione del blocco.
 *    - QUANDO USARLO: Quando la condizione di arresto dipende da un valore calcolato o
 *      letto da tastiera DENTRO il corpo del ciclo (es. lettura sequenza con tappo/sentinella).
 *    - PERCHÉ NON IL WHILE NORMALE? Se usassimo `while(x != 0)` prima di leggere 'x',
 *      la variabile 'x' conterrebbe un valore "spazzatura" non definito, causando
 *      comportamenti imprevedibili.
 *
 * 3. CONTROLLO DELL'INPUT (VALIDAZIONE) CON VARIABILI LOGICHE:
 *    Si ripete la richiesta dei dati fino a quando l'utente non inserisce valori validi.
 *    - Flag `errore`: `errore = (base <= 0 || altezza <= 0);`
 *    - Flag `ok` (duale): `ok = (base > 0 && altezza > 0);` -> si ripete `while (!ok);`
 *
 * 4. CICLI ANNIDATI (NESTED LOOPS):
 *    Un ciclo inserito all'interno del corpo di un altro ciclo.
 *    - Ogni ciclo DEVE avere un contatore DIVERSO (es. 'i' per le righe, 'j' per le colonne).
 *    - Per ogni singola iterazione del ciclo esterno ('i'), il ciclo interno ('j') viene
 *      eseguito interamente per tutte le sue iterazioni.
 *
 * 5. PATTERN SU MATRICI (Sintassi & De Morgan):
 *    - Diagonale principale (\): `i == j`
 *    - Diagonale secondaria (/): `i + j == N - 1` (es. `i + j == 4` per matrice 5x5)
 *    - Entrambe le diagonali: `(i == j || i + j == 4)`
 *      * Negazione (De Morgan): `!(i == j || i + j == 4)` -> `(i != j && i + j != 4)`
 *    - Cornice / Bordo: `(i == 0 || i == 4 || j == 0 || j == 4)`
 *      * Negazione (De Morgan): `(i != 0 && i != 4 && j != 0 && j != 4)` (interno)
 */

#include <stdio.h>

int main(void) {

    // =========================================================================
    // 1. CICLO SENZA CONTATORE: MCD DI EUCLIDE (Sottrazioni successive)
    // =========================================================================
    printf("=== 1. MCD DI EUCLIDE (while senza contatore) ===\n");
    int a, b, a_orig, b_orig;

    printf("Inserisci il primo valore intero positivo (a): ");
    scanf("%d", &a);
    printf("Inserisci il secondo valore intero positivo (b): ");
    scanf("%d", &b);

    a_orig = a;
    b_orig = b;

    // Il ciclo prosegue finche' a e b sono diversi, riducendo il maggiore
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    printf("MCD(%d, %d) = %d\n\n", a_orig, b_orig, a);


    // =========================================================================
    // 2. CICLO CON CONDIZIONE FINALE (do-while): SOMMA CON TAPPO (0)
    // =========================================================================
    printf("=== 2. SOMMA DI UNA SEQUENZA TERMINATA DA 0 (do-while) ===\n");
    int x, somma_seq = 0;

    // do-while garantisce che la prima lettura avvenga prima del controllo (x != 0)
    do {
        printf("Inserisci un numero (0 per terminare): ");
        scanf("%d", &x);
        somma_seq = somma_seq + x;
    } while (x != 0); // NOTA: Punto e virgola obbligatorio dopo il while!

    printf("La somma totale della sequenza vale: %d\n\n", somma_seq);


    // =========================================================================
    // 3. CONTROLLO DELL'INPUT CON VARIABILI LOGICHE (Validation Loop)
    // =========================================================================
    printf("=== 3. CONTROLLO DELL'INPUT CON VARIABILE LOGICA ===\n");
    float base, altezza, area;
    int ok; // Variabile logica booleana (1 = ok, 0 = errore)

    do {
        printf("Inserisci la base del triangolo (> 0): ");
        scanf("%f", &base);
        printf("Inserisci l'altezza del triangolo (> 0): ");
        scanf("%f", &altezza);

        // Assegnamento booleano: ok sara' 1 (vero) solo se entrambi sono positivi
        ok = (base > 0 && altezza > 0);

        if (!ok) {
            printf("ERRORE: Base e altezza devono essere strettamente positive! Riprova.\n");
        }
    } while (!ok); // Ripete finche' !ok e' vero (ovvero finche' l'input non e' corretto)

    area = (base * altezza) / 2.0;
    printf("Area del triangolo calcolata: %.2f\n\n", area);


    // =========================================================================
    // 4. CICLI ANNIDATI: STAMPA DI UNA MATRICE 5x5 DI 'X'
    // =========================================================================
    printf("=== 4. CICLI ANNIDATI: MATRICE 5x5 DI 'X' ===\n");
    int i, j;

    // --- Versione A: Cicli FOR annidati ---
    printf("Versione FOR:\n");
    for (i = 0; i < 5; i++) {         // Ciclo esterno: gestione delle 5 righe
        for (j = 0; j < 5; j++) {     // Ciclo interno: gestione delle 5 colonne per riga
            printf("X\t");
        }
        printf("\n");                 // A capo alla fine di ogni riga
    }

    // --- Versione B: Cicli WHILE annidati ---
    printf("\nVersione WHILE equivalente:\n");
    i = 0;
    while (i < 5) {
        j = 0;                        // RESET FONDAMENTALE del contatore interno per ogni riga!
        while (j < 5) {
            printf("X\t");
            j++;
        }
        printf("\n");
        i++;
    }
    printf("\n");


    // =========================================================================
    // 5. TAVOLA PITAGORICA (10x10)
    // =========================================================================
    printf("=== 5. TAVOLA PITAGORICA (10x10) ===\n");
    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= 10; j++) {
            printf("%d\t", i * j); // Prodotto riga * colonna
        }
        printf("\n");
    }
    printf("\n");


    // =========================================================================
    // 6. CICLI ANNIDATI CON SELEZIONE: DIAGONALI E LEGISLAZIONE DE MORGAN
    // =========================================================================
    printf("=== 6. MATRICE 5x5 CON DIAGONALI ('O' su Diagonali, 'X' altrove) ===\n");
    
    // Condizione diretta: (i == j) per la diagonale principale (\)
    //                     (i + j == 4) per la diagonale secondaria (/)
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == j || i + j == 4) {
                printf("O\t");
            } else {
                printf("X\t");
            }
        }
        printf("\n");
    }

    printf("\nStessa Matrice Invertendo la Condizione (De Morgan: i != j && i + j != 4):\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i != j && i + j != 4) { // Condizione opposta duale
                printf("X\t");
            } else {
                printf("O\t");
            }
        }
        printf("\n");
    }
    printf("\n");


    // =========================================================================
    // 7. CICLI ANNIDATI CON SELEZIONE: CORNICE ('O' su Bordi, 'X' all'interno)
    // =========================================================================
    printf("=== 7. MATRICE 5x5 CON CORNICE ===\n");
    
    // Condizione di bordo: riga iniziale (i==0), riga finale (i==4),
    //                     colonna iniziale (j==0), colonna finale (j==4)
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == 0 || i == 4 || j == 0 || j == 4) {
                printf("O\t");
            } else {
                printf("X\t");
            }
        }
        printf("\n");
    }

    printf("\nStessa Cornice Invertendo i Rami (De Morgan per l'interno):\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i != 0 && i != 4 && j != 0 && j != 4) { // Condizione per le celle INTERNE
                printf("X\t");
            } else {
                printf("O\t");
            }
        }
        printf("\n");
    }

    return 0;
}