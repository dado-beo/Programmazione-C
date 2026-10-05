/*
 * =====================================================================================
 *  NOME FILE: 02_selezione_operatori_confronto.c
 *  CORSO: Programmazione C (UPO)
 *  ARGOMENTO: Selezione (if-else), Operatori di Confronto, Operatore Resto (%),
 *             Libreria Math, Selezioni Annidate e Selezione Multipla (switch-case)
 * =====================================================================================
 *
 * --- REGOLE E CONCETTI TEORICI COMPLETI (Tratti dalle slide) ---
 *
 * 1. STRUTTURA DELLA SELEZIONE (if / else):
 *    - Sintassi: if (condizione) comando1; else comando2;
 *    - La condizione si scrive SEMPRE tra parentesi tonde.
 *    - Ramo falso vuoto: L'operatore 'else' si omette se non ci sono comandi nel ramo falso.
 *
 * 2. REGOLE SULLE PARENTESI GRAFFE { }:
 *    - Se un ramo (if o else) contiene PIÙ DI UN COMANDO, le graffe sono OBBLIGATORIE.
 *    - Senza graffe, soltanto il PRIMO comando è vincolato alla condizione; i successivi
 *      verranno eseguiti SEMPRE, causando errori logici o di compilazione (else spaiato).
 *
 * 3. ATTENZIONE AGLI ERRORE COMUNI (TRAPPOLI D'ESAME):
 *    - TRAPPOLA DEL PUNTO E VIRGOLA: Scrivere `if (condizione);` (con il punto e virgola)
 *      crea una selezione vuota! Il blocco successivo verrà eseguito SEMPRE.
 *    - UGUAGLIANZA VS ASSEGNAMENTO:
 *      * '==' è l'operatore di confronto (es. x == y controlla se x è uguale a y).
 *      * '=' è l'operatore di assegnamento (es. x = 0 assegna 0 a x).
 *      * Scrivere `if (x = 0)` assegna 0 a x e rende la condizione FALSA (0 = falso in C).
 *      * Usare la flag di compilazione `gcc -Wall` per individuare questo tipo di warning.
 *
 * 4. OPERATORI DI CONFRONTO:
 *    - '>' (maggiore), '<' (minore), '>=' (magg. uguale), '<=' (min. uguale)
 *    - '==' (uguale), '!=' (diverso)
 *    - Operandi: Possono essere variabili, costanti, valori, caratteri o espressioni.
 *
 * 5. OPERATORE RESTO (%):
 *    - Restituisce il resto della divisione intera tra due numeri.
 *    - Divisibilità / Multipli: x % y == 0 (x è multiplo/divisibile per y).
 *    - Pari / Dispari: x % 2 == 0 (pari), x % 2 != 0 (dispari).
 *    - Divisore: y % x == 0 (x è divisore di y).
 *
 * 6. LIBRERIE E FUNZIONI MATEMATICHE INTEGRATE:
 *    - abs(x): Valore assoluto per 'int' (richiede <stdlib.h>).
 *    - fabs(x): Valore assoluto per 'float' (richiede <math.h>).
 *    - pow(base, esp): Calcola la potenza (richiede <math.h>).
 *    - sqrt(x): Calcola la radice quadrata (richiede <math.h>).
 *    * NOTA COMPILATORE: Su alcuni sistemi Linux serve l'opzione `-lm` (gcc file.c -lm).
 *
 * 7. SELEZIONE MULTIPLA (switch-case):
 *    - Si applica quando ci sono più condizioni di UGUAGLIANZA (==) sulla STESSA variabile.
 *    - REQUISITO FONDAMENTALE: La variabile DEVE essere 'int' o 'char' (NO 'float'!).
 *    - Sintassi: switch(variabile) { case val1: comandi; break; default: comandi; break; }
 *    - L'istruzione 'break' è indispensabile per uscire dallo switch evitando il fall-through.
 *    - 'default' corrisponde all'ultimo 'else' (eseguito se nessun caso coincide).
 */

#include <stdio.h>
#include <stdlib.h> // Per la funzione abs()
#include <math.h>   // Per le funzioni fabs(), pow(), sqrt()

#define PI 3.14159

int main(void) {

    // =========================================================================
    // 1. SELEZIONE SEMPLICE (if-else) E MASSIMO TRA DUE NUMERI
    // =========================================================================
    printf("=== 1. MASSIMO TRA DUE NUMERI (if-else) ===\n");
    int num1, num2;
    
    printf("Inserisci il primo valore intero: ");
    scanf("%d", &num1);
    printf("Inserisci il secondo valore intero: ");
    scanf("%d", &num2);

    // Selezione binaria classica
    if (num1 > num2) {
        printf("Il massimo vale: %d\n", num1);
    } else {
        printf("Il massimo vale: %d\n", num2);
    }
    printf("\n");


    // =========================================================================
    // 2. RAMO FALSO VUOTO E VALORE ASSOLUTO (MANUALE VS LIBRERIA)
    // =========================================================================
    printf("=== 2. VALORE ASSOLUTO (Ramo else vuoto & Math Lib) ===\n");
    int x_int;
    float x_float;

    printf("Inserisci un numero intero (anche negativo): ");
    scanf("%d", &x_int);

    // Algoritmo manuale: ramo falso vuoto (niente else)
    int va_manuale = x_int;
    if (x_int < 0) {
        va_manuale = -x_int; // Inverte il segno solo se negativo
    }
    printf("Valore assoluto manuale: %d\n", va_manuale);

    // Tramite funzione di libreria abs() per interi (<stdlib.h>)
    printf("Valore assoluto con abs(): %d\n", abs(x_int));

    printf("Inserisci un numero float (anche negativo): ");
    scanf("%f", &x_float);
    // Tramite funzione di libreria fabs() per float (<math.h>)
    printf("Valore assoluto con fabs(): %.2f\n\n", fabs(x_float));


    // =========================================================================
    // 3. BLOCCHI MULTI-COMANDO E USO DI RESTO (%) PER PARI/DISPARI
    // =========================================================================
    printf("=== 3. CIRCONFERENZA E VERIFICA PARI/DISPARI ===\n");
    float raggio, circonferenza;

    printf("Inserisci il raggio del cerchio: ");
    scanf("%f", &raggio);

    // Esempio di ramo con PIÙ comandi -> Le graffe { } sono OBBLIGATORIE!
    if (raggio > 0) {
        circonferenza = 2 * PI * raggio;
        printf("Raggio valido! Circonferenza calcolata: %.2f\n", circonferenza);
    } else {
        printf("ERRORE: Il raggio non e' positivo!\n");
    }

    // Verifica PARI / DISPARI tramite operatore resto (%)
    int numero_test;
    printf("\nInserisci un numero intero da verificare se pari o dispari: ");
    scanf("%d", &numero_test);

    if (numero_test % 2 == 0) {
        printf("Il numero %d e' PARI (resto divisione per 2 == 0).\n\n", numero_test);
    } else {
        printf("Il numero %d e' DISPARI (resto divisione per 2 != 0).\n\n", numero_test);
    }


    // =========================================================================
    // 4. SELEZIONI ANNIDATE: MASSIMO TRA TRE NUMERI ED EQUAZIONE DI 2° GRADO
    // =========================================================================
    printf("=== 4. SELEZIONI ANNIDATE (Max 3 numeri & Equazione 2° grado) ===\n");
    
    // A) Massimo tra tre valori interi
    int a, b, c_val;
    printf("Inserisci tre interi separati da spazio (es. 5 12 3): ");
    scanf("%d %d %d", &a, &b, &c_val);

    if (a > b) {
        if (a > c_val) {
            printf("Il massimo tra i tre e': %d\n", a);
        } else {
            printf("Il massimo tra i tre e': %d\n", c_val);
        }
    } else {
        if (b > c_val) {
            printf("Il massimo tra i tre e': %d\n", b);
        } else {
            printf("Il massimo tra i tre e': %d\n", c_val);
        }
    }

    // B) Risoluzione Equazione di secondo grado: ax^2 + bx + c = 0
    float coeff_a, coeff_b, coeff_c, delta, x1, x2;
    printf("\nRisoluzione Equazione 2° Grado (a*x^2 + b*x + c = 0)\n");
    printf("Inserisci i coefficienti a, b, c separati da spazio: ");
    scanf("%f %f %f", &coeff_a, &coeff_b, &coeff_c);

    // Calcolo del Delta usando pow() da <math.h>
    delta = pow(coeff_b, 2) - (4 * coeff_a * coeff_c);

    if (delta < 0) {
        printf("Delta = %.2f < 0: Equazione IMPOSSIBILE (nessuna soluzione reale).\n\n", delta);
    } else if (delta == 0) { // ATTENZIONE: '==' per confronto uguaglianza!
        x1 = (-coeff_b) / (2 * coeff_a);
        printf("Delta = 0: Unica soluzione reale x1 = x2 = %.2f\n\n", x1);
    } else {
        // USO DI sqrt() da <math.h>
        x1 = (-coeff_b + sqrt(delta)) / (2 * coeff_a);
        x2 = (-coeff_b - sqrt(delta)) / (2 * coeff_a);
        printf("Delta = %.2f > 0: Due soluzioni reali distinte: x1 = %.2f, x2 = %.2f\n\n", delta, x1, x2);
    }


    // =========================================================================
    // 5. SELEZIONE MULTIPLA (switch - case)
    // =========================================================================
    printf("=== 5. SELEZIONE MULTIPLA (switch - case) ===\n");

    // Esempio A: Tassa sulla casa in base alla zona ('A', 'B', 'C', 'D')
    char zona;
    float valore_casa, tassa;

    printf("Inserisci il valore della casa in Euro: ");
    scanf("%f", &valore_casa);
    printf("Inserisci la zona (A, B, C, D): ");
    scanf(" %c", &zona); // Nota lo spazio prima di %c per ignorare eventuali spazi/INVIO residui

    switch (zona) {
        case 'A':
        case 'a': // Supportiamo sia maiuscole che minuscole
            tassa = valore_casa * (5.0 / 100.0);
            printf("Zona A: Tassa al 5%% = %.2f Euro\n", tassa);
            break; // Uscita fondamentale dallo switch
        case 'B':
        case 'b':
            tassa = valore_casa * (10.0 / 100.0);
            printf("Zona B: Tassa al 10%% = %.2f Euro\n", tassa);
            break;
        case 'C':
        case 'c':
            tassa = valore_casa * (15.0 / 100.0);
            printf("Zona C: Tassa al 15%% = %.2f Euro\n", tassa);
            break;
        case 'D':
        case 'd':
            tassa = valore_casa * (20.0 / 100.0);
            printf("Zona D: Tassa al 20%% = %.2f Euro\n", tassa);
            break;
        default: // Eseguito se la zona inserita non coincide con nessun case
            printf("ERRORE: Zona '%c' sconosciuta!\n", zona);
            break;
    }

    // Esempio B: Giorni del mese con raggruppamento di case (senza break intermedi)
    int mese;
    printf("\nInserisci il numero del mese (1-12): ");
    scanf("%d", &mese);

    switch (mese) {
        // Casi raggruppati: Mesi con 31 giorni
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            printf("Il mese %d ha 31 giorni.\n", mese);
            break;

        // Casi raggruppati: Mesi con 30 giorni
        case 4: case 6: case 9: case 11:
            printf("Il mese %d ha 30 giorni.\n", mese);
            break;

        // Mese di Febbraio
        case 2:
            printf("Il mese 2 (Febbraio) ha 28 giorni (o 29 negli anni bisestili).\n");
            break;

        default:
            printf("ERRORE: Numero mese %d non valido! Deve essere compreso tra 1 e 12.\n", mese);
            break;
    }

    return 0;
}