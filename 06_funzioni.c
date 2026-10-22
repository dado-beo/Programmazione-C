/*
 * =====================================================================================
 *  NOME FILE: 06_funzioni.c
 *  CORSO: Programmazione C 
 *  ARGOMENTO: Funzioni, Prototipi, Librerie, Scope delle variabili e -Wall
 * =====================================================================================
 *
 * --- NOTE SULLA TEORIA (Tratte dalle slide) ---
 * 1. FUNZIONI: Sottoprogrammi che ricevono input (parametri), elaborano i dati 
 *    e restituiscono un output (valore di ritorno). Scompongono il problema principale.
 * 2. LIBRERIE PREDEFINITE: Contengono funzioni già pronte da includere con #include.
 *    - stdlib.h: abs (valore assoluto per interi).
 *    - math.h: fabs (valore assoluto float), pow (potenza), sqrt (radice quadrata).
 *    NOTA: L'uso di math.h richiede spesso di compilare aggiungendo -lm (es. gcc -lm file.c).
 * 3. STRUTTURA DI UNA FUNZIONE:
 *    - Intestazione (Header): tipo_ritorno nome(tipo_param nome_param).
 *    - Corpo: Racchiuso tra {}, contiene variabili locali e le istruzioni.
 *    - return: Restituisce il valore al chiamante e TERMINA l'esecuzione della funzione.
 * 4. FUNZIONI SENZA PARAMETRI E VOID:
 *    - Senza parametri: Hanno parentesi tonde vuote ().
 *    - void: Non restituiscono alcun valore (nessun return finale) e si invocano
 *      senza assegnamento.
 * 5. VISIBILITA' (SCOPE) DELLE VARIABILI:
 *    - Locali: Create dentro una funzione. Esistono solo nel suo "record di attivazione"
 *      (nella memoria Stack). Variabili con lo stesso nome in funzioni diverse sono distinte.
 *    - Globali: Dichiarate fuori dalle funzioni (es. in cima). Sono condivise da tutti.
 * 6. PROTOTIPI: Intestazioni delle funzioni scritte all'inizio del file, con punto e virgola.
 *    Servono a presentare la funzione al compilatore prima che venga invocata nel main, 
 *    evitando errori di ordine di scrittura nel codice.
 * 7. MESSAGGI DEL COMPILATORE (gcc -Wall):
 *    - Errori: Sintassi errata, il programma non viene generato.
 *    - Warnings (-Wall): Sintassi corretta ma potenziali difetti logici (es. = al posto di ==).
 */

#include <stdio.h>
#include <stdlib.h> // Per abs()
#include <math.h>   // Per fabs(), pow(), sqrt()

/* ==========================================
 * PROTOTIPI DI FUNZIONE
 * ========================================== */
void benvenuto();
int leggi_argomento();
int fattoriale(int x);
int numero_primo(int x);
int massimo2(int a, int b);
int massimo3(int a, int b, int c);

/* Variabile Globale (visibile e modificabile in tutte le funzioni) */
int chiamate_totali = 0; 

int main(void) {
    // Variabili locali al main
    int a, f, p, m2, m3;
    float base, esponente;

    // 1. Invocazione di funzione void senza parametri
    benvenuto();

    // 2. Test delle funzioni di libreria predefinite
    printf("\n--- Test Librerie Standard ---\n");
    int negativo = -15;
    printf("Valore assoluto di %d (stdlib.h): %d\n", negativo, abs(negativo));
    
    base = 2.0;
    esponente = 3.0;
    printf("Potenza %.1f^%.1f (math.h): %.1f\n", base, esponente, pow(base, esponente));
    printf("Radice quadrata di 16 (math.h): %.2f\n", sqrt(16.0));

    // 3. Funzione di input con controllo (senza parametri, con return)
    printf("\n--- Test Fattoriale e Numeri Primi ---\n");
    a = leggi_argomento(); 

    // 4. Invocazione di funzioni con parametri e return
    f = fattoriale(a);
    printf("Il fattoriale di %d e' %d\n", a, f);

    p = numero_primo(a);
    if (p == 1) {
        printf("%d e' un numero primo\n", a);
    } else {
        printf("%d non e' un numero primo\n", a);
    }

    // 5. Test funzioni per il calcolo del massimo (con parametri multipli)
    printf("\n--- Test Calcolo Massimo ---\n");
    m2 = massimo2(a, 10);
    printf("Tra %d e 10, il massimo e' %d\n", a, m2);

    m3 = massimo3(a, 10, 25);
    printf("Tra %d, 10 e 25, il massimo e' %d\n", a, m3);

    printf("\nFunzioni utente chiamate in totale: %d volte (variabile globale).\n", chiamate_totali);

    return 0; // Termina il programma
}

/* ==========================================
 * DEFINIZIONE DELLE FUNZIONI
 * ========================================== */

// Funzione void (senza parametri e senza return)
void benvenuto() {
    chiamate_totali++;
    printf("==================================================\n");
    printf("Questo programma testa le funzioni matematiche.\n");
    printf("Il numero inserito non deve essere negativo.\n");
    printf("In caso contrario si ripetera' la lettura.\n");
    printf("==================================================\n");
}

// Funzione senza parametri, con return
int leggi_argomento() {
    chiamate_totali++;
    int x; // Variabile locale: esiste solo qui dentro, non e' la x di altre funzioni
    do {
        printf("Inserire un valore intero (>= 0): ");
        scanf("%d", &x);
        if (x < 0) {
            printf("ERRORE: il valore non deve essere negativo.\n");
        }
    } while (x < 0);
    return x;
}

// Funzione che calcola il fattoriale
int fattoriale(int x) {
    chiamate_totali++;
    int i, fatt = 1; // Variabili locali
    for (i = 1; i <= x; i++) {
        fatt = fatt * i;
    }
    return fatt; // Dopo questa istruzione, il record di attivazione viene cancellato
}

// Funzione per il controllo dei numeri primi
int numero_primo(int x) {
    chiamate_totali++;
    int i, primo, conta = 0;
    
    // Un numero è primo se ha esattamente 1 o 2 divisori
    for (i = 1; i <= x; i++) {
        if (x % i == 0) {
            conta++;
        }
    }
    
    if (conta == 1 || conta == 2) {
        primo = 1; // vero
    } else {
        primo = 0; // falso
    }
    return primo;
}

// Funzione che calcola il massimo tra due interi
int massimo2(int a, int b) {
    chiamate_totali++;
    int max;
    if (a > b) {
        max = a;
    } else {
        max = b;
    }
    return max;
}

// Funzione che calcola il massimo tra tre interi
int massimo3(int a, int b, int c) {
    chiamate_totali++;
    int max;
    if (a > b) {
        if (a > c) {
            max = a;
        } else {
            max = c;
        }
    } else {
        if (b > c) {
            max = b;
        } else {
            max = c;
        }
    }
    return max;
}