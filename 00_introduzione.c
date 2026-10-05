/*
 * =====================================================================================
 *  NOME FILE: 00_introduzione.c
 *  CORSO: Programmazione C (UPO)
 *  ARGOMENTO: Struttura base del C, Compilazione con GCC, Terminale e Sequenze di Escape
 * =====================================================================================
 *
 * --- CONCETTI CHIAVE E FLUSSO DI SVILUPPO ---
 * 1. SCRITTURA DEL CODICE:
 *    Il codice sorgente si scrive in testo semplice e si salva con estensione `.c`.
 *
 * 2. COMPILAZIONE (Con il compilatore GCC):
 *    Traduce il testo C in linguaggio macchina (binario).
 *    - Comando base: gcc 00_introduzione.c
 *      --> Genera un file eseguibile di default chiamato 'a.out' (su Linux) o 'a.exe' (su Windows).
 *    - Comando con nome personalizzato (Scelta consigliata):
 *      --> gcc 00_introduzione.c -o somma
 *      --> L'opzione '-o' (output) definisce il nome dell'eseguibile generato.
 *
 * 3. ESECUZIONE DA TERMINALE:
 *    - Su Linux/WSL: ./a.out oppure ./somma
 *      (Il prefisso './' indica al sistema operativo di cercare l'eseguibile nella cartella corrente).
 *
 * --- CRONOLOGIA E SHORTCUT DEL TERMINALE LINUX ---
 * - `cd nome_cartella`: Cambia la directory/cartella di lavoro.
 * - Freccia SU / GIÙ (↑ / ↓): Scorri la cronologia dei comandi inviati precedentemente.
 * - Tasto TAB (↹): Autocompleta automaticamente i nomi di file e cartelle.
 *
 * --- NOTA SULLO STANDARD C (IMPORTANTE PER GLI ESAMI) ---
 * Nelle slide storiche si legge spesso `void main()`. Negli standard C moderni (ANSI C, C99, C11, C17)
 * la firma standard della funzione principale è SEMPRE `int main(void)` oppure `int main()`.
 * Deve sempre restituire un valore intero al sistema operativo (tramite `return 0;`).
 */

// DIRETTIVA AL PREPROCESSORE:
// Include le definizioni della libreria standard di Input/Output (STandard Input/Output Header).
// È indispensabile per poter usare le funzioni 'printf' (stampa) e 'scanf' (lettura).
#include <stdio.h>

/*
 * FUNZIONE PRINCIPALE: main()
 * È il punto di ingresso (entry point) di qualunque programma C.
 * Il sistema operativo inizia ad eseguire le istruzioni partendo dalla prima riga di main().
 */
int main(void) {

    // =========================================================================
    // 1. DICHIARAZIONE E INIZIALIZZAZIONE DELLE VARIABILI
    // =========================================================================
    // 'int' indica che la variabile conterra' un numero intero (es. -5, 0, 12).
    int x;      // Alloca memoria per la variabile intera 'x'
    int y;      // Alloca memoria per la variabile intera 'y'
    int somma;  // Alloca memoria per contenere il risultato finale

    // ASSEGNAMENTO: Si assegna un valore concreto usando l'operatore '='
    x = 3;      // Salva il valore 3 dentro 'x'
    y = 2;      // Salva il valore 2 dentro 'y'

    // CALCOLO ARITMETICO:
    // L'operatore '+' calcola la somma. Il risultato viene salvato nella variabile 'somma'.
    somma = x + y;


    // =========================================================================
    // 2. STAMPA A SCHERMO (printf) E SPECIFICATORI DI FORMATO
    // =========================================================================
    // La funzione 'printf' stampa testo sul terminale.
    // '%d' è uno specificatore di formato (placeholder): indica che in quel punto
    // della stringa verrà inserito il valore di una variabile di tipo intero decimal.
    printf("La somma vale: %d\n", somma);

    // Possiamo passare più variabili a una singola printf (sostituite in ordine da sinistra a destra):
    printf("Dettaglio calcolo: %d + %d = %d\n", x, y, somma);


    // =========================================================================
    // 3. SEQUENZE DI ESCAPE (Formattazione del Testo)
    // =========================================================================
    // I caratteri di escape iniziano con il simbolo '\' (backslash) e gestiscono la formattazione.
    printf("\n=== RIEPILOGO SEQUENZE DI ESCAPE COMUNI ===\n");
    printf("1. Nuova riga (\\n): Prima riga di testo.\nSeconda riga di testo.\n");
    printf("2. Tabulazione (\\t): Colonna A\tColonna B\tColonna C\n");
    printf("3. Virgolette doppie (\\\"): Stampa le \"virgolette\" senza chiudere la stringa.\n");
    printf("4. Backslash (\\\\): Per stampare una singola barra inversa: \\\n");


    // =========================================================================
    // 4. CHIUSURA DEL PROGRAMMA
    // =========================================================================
    // 'return 0;' segnala al sistema operativo che il programma è terminato Correttamente (Codice 0 = OK).
    return 0;
}