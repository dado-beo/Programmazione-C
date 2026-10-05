/*
 * =====================================================================================
 *  NOME FILE: 03_operatori_logici.c
 *  CORSO: Programmazione C (UPO)
 *  ARGOMENTO: Selezione (if-else), Operatori Relazionali e Logici, Variabili Booleane
 * =====================================================================================
 *
 * --- NOTE SULLA TEORIA (Tratte dalle slide) ---
 * 1. SELEZIONE (if/else): Esegue blocchi di codice diversi in base a una condizione.
 * 2. OPERATORI RELAZIONALI: > (maggiore), < (minore), >=, <=, == (uguale), != (diverso).
 * 3. OPERATORI LOGICI:
 *    - AND (&&): Vero SOLO se TUTTE le condizioni sono vere.
 *    - OR (||): Vero se ALMENO UNA condizione è vera.
 *    - NOT (!): Inverte il valore della condizione (Vero diventa Falso e viceversa).
 * 4. PRIORITÀ: 1° NOT (!), 2° AND (&&), 3° OR (||). Usa le parentesi per cambiare l'ordine.
 * 5. INVERSIONE (De Morgan): Invertendo una condizione composta col NOT:
 *    - > diventa <= (e viceversa), == diventa != (e viceversa).
 *    - && diventa ||, || diventa &&.
 * 6. VARIABILI BOOLEANE: In C non esiste un tipo 'bool' nativo (senza librerie extra).
 *    Il risultato di una condizione è un 'int': 1 (Vero) o 0 (Falso).
 */

#include <stdio.h>

int main(void) {

    // =========================================================================
    // 1. CONDIZIONI COMPOSTE: AND (&&) - Esempio Area Triangolo
    // =========================================================================
    printf("=== 1. TEST AREA TRIANGOLO (AND) ===\n");
    float base, altezza, area;
    
    printf("Inserisci la base: ");
    scanf("%f", &base);
    printf("Inserisci l'altezza: ");
    scanf("%f", &altezza);

    // Entrambe le condizioni devono essere vere per calcolare l'area
    if (base > 0 && altezza > 0) {
        area = base * altezza / 2.0;
        printf("Area calcolata: %.2f\n\n", area);
    } else {
        // Condizione opposta implicita: base <= 0 || altezza <= 0
        printf("ERRORE: base e altezza devono essere positive!\n\n");
    }

    // =========================================================================
    // 2. CONDIZIONI COMPOSTE: AND, OR, NOT - Esempio Anno Bisestile
    // =========================================================================
    printf("=== 2. TEST ANNO BISESTILE (AND, OR, NOT) ===\n");
    int anno;
    
    printf("Inserisci un anno: ");
    scanf("%d", &anno);

    // Un anno è bisestile se:
    // (è divisibile per 4 E NON per 100) OPPURE (è divisibile per 400)
    // L'operatore && ha priorità sull'operatore ||
    if ((anno % 4 == 0 && anno % 100 != 0) || anno % 400 == 0) {
        printf("L'anno %d e' bisestile.\n\n", anno);
    } else {
        printf("L'anno %d NON e' bisestile.\n\n", anno);
    }

    // =========================================================================
    // 3. VARIABILI LOGICHE (BOOLEANE) - Esempio Lati Triangolo
    // =========================================================================
    printf("=== 3. VARIABILI LOGICHE (LATI TRIANGOLO) ===\n");
    float l1, l2, l3;
    
    printf("Inserisci i tre lati del triangolo separati da spazio (es. 3 4 5): ");
    scanf("%f %f %f", &l1, &l2, &l3);

    // In C, il risultato di un confronto è un intero (1 se Vero, 0 se Falso).
    // Salviamo questi risultati in variabili int per semplificare l'if finale.
    
    // Condizioni di positività
    int positivi = (l1 > 0) && (l2 > 0) && (l3 > 0);
    
    // Condizioni geometriche (ogni lato < somma degli altri due)
    int geom_l1 = (l1 < l2 + l3);
    int geom_l2 = (l2 < l1 + l3);
    int geom_l3 = (l3 < l1 + l2);
    int disuguaglianze_ok = geom_l1 && geom_l2 && geom_l3;

    // Se tutte le condizioni base sono vere (1 && 1 -> 1)
    if (positivi && disuguaglianze_ok) {
        printf("I valori inseriti formano un triangolo valido.\n");
    } else {
        printf("I valori inseriti NON possono formare un triangolo.\n");
    }

    return 0;
}