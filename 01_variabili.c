/*
 * =====================================================================================
 *  NOME FILE: 01_variabili.c
 *  CORSO: Programmazione C (UPO)
 *  ARGOMENTO: Variabili, Tipi di dato, Operatori, printf/scanf, Costanti e Memoria
 * =====================================================================================
 *
 * --- NOTE SULLA TEORIA (Tratte dalle slide) ---
 * 1. VARIABILI: Aree di memoria (RAM) con un NOME (identificatore), un TIPO e un VALORE.
 * 2. REGOLE NOMI: Sensibili alle maiuscole (case-sensitive), niente spazi, iniziano con lettera.
 * 3. TIPI BASE: 
 *    - int: interi con segno (es. 5, -3)
 *    - float: decimali con segno (es. 3.14)
 *    - char: singoli caratteri racchiusi tra apici singoli (es. 'A', '1', '?')
 * 4. COSTANTI: Valori immutabili. Si definiscono con '#define' (pre-processore) o 'const'.
 * 5. ERRORI COMUNI:
 *    - Compilazione: Errori di sintassi (es. manca il ;). Il programma non viene creato.
 *    - Logici: Sintassi corretta ma formula sbagliata (es. x = a + b*2 invece di (a+b)*2).
 *    - Esecuzione (Crash): Operazioni illegali (es. divisione per zero).
 *    - Warnings: Il compilatore segnala potenziali problemi logici (si attiva con gcc -Wall).
 */

#include <stdio.h>

// COSTANTE SIMBOLICA: Sostituita dal compilatore ovunque trovi "PIGRECO" prima di compilare.
// Non occupa uno spazio di memoria dedicato come le variabili.
#define PIGRECO 3.141592

int main(void) {

    // =========================================================================
    // 1. DICHIARAZIONE, ASSEGNAMENTO E COSTANTI
    // =========================================================================
    
    // Dichiarazione multipla e assegnamento contestuale
    int x = 9, y = 2; 
    
    // Costante con allocazione di memoria (non modificabile durante l'esecuzione)
    const int MOLTIPLICATORE = 10;
    
    // =========================================================================
    // 2. DIMENSIONE IN MEMORIA (sizeof)
    // =========================================================================
    printf("=== OCCUPAZIONE IN MEMORIA ===\n");
    // sizeof restituisce il numero di byte occupati da un tipo o da una variabile.
    // NOTA: I byte esatti possono variare in base al sistema operativo/architettura.
    printf("Un 'int' occupa %lu byte.\n", sizeof(int));
    printf("Un 'float' occupa %lu byte.\n", sizeof(float));
    printf("Un 'char' occupa %lu byte.\n\n", sizeof(char));

    // =========================================================================
    // 3. OPERATORI ARITMETICI E DIVISIONE INTERA VS DECIMALE
    // =========================================================================
    printf("=== OPERATORI ARITMETICI ===\n");
    
    int div_intera = x / y;   // 9 / 2 = 4 (Tronca la parte decimale perché sono interi)
    int resto = x % y;        // 9 % 2 = 1 (Il resto della divisione intera)
    
    printf("Divisione intera (9/2): %d\n", div_intera);
    printf("Resto della divisione (9%%2): %d\n", resto); // Si usa %% per stampare il simbolo %

    // Per avere una divisione decimale, le variabili devono essere float
    float f1 = 9.0, f2 = 2.0;
    float div_decimale = f1 / f2;
    // Il formato %.2f limita la stampa a due cifre decimali
    printf("Divisione con float (9.0/2.0): %.2f\n\n", div_decimale);

    // =========================================================================
    // 4. INCREMENTO E DECREMENTO (++ / --)
    // =========================================================================
    printf("=== INCREMENTO (++) E DECREMENTO (--) ===\n");
    int c = 1;
    printf("Valore iniziale c: %d\n", c);
    
    // POST-INCREMENTO: Assegna prima il valore, poi incrementa.
    int post = c++; 
    printf("Dopo post = c++ -> post vale: %d, c vale: %d\n", post, c); // post=1, c=2
    
    // PRE-INCREMENTO: Incrementa prima, poi assegna il valore.
    int pre = ++c;
    printf("Dopo pre = ++c  -> pre vale: %d, c vale: %d\n\n", pre, c); // pre=3, c=3

    // =========================================================================
    // 5. CARATTERI E TABELLA ASCII
    // =========================================================================
    printf("=== VARIABILI CHAR E TABELLA ASCII ===\n");
    char lettera = 'a'; // Occupa 1 byte, contiene il valore intero 97 (codice ASCII)
    printf("La lettera iniziale e': %c (codice ASCII: %d)\n", lettera, lettera);
    
    // Essendo numeri interi, possiamo applicare operazioni matematiche sui caratteri!
    lettera = lettera + 3; // 97 + 3 = 100 (che corrisponde a 'd')
    printf("Aggiungendo 3, la lettera diventa: %c (codice ASCII: %d)\n\n", lettera, lettera);

    // =========================================================================
    // 6. INPUT DA TASTIERA (scanf) E GESTIONE DEL BUFFER
    // =========================================================================
    printf("=== INPUT DA TASTIERA (scanf) ===\n");
    
    int utente_int;
    float utente_float;
    char utente_char;

    // Richiesta di un intero. Si usa & (operatore di indirizzo) per indicare a scanf dove salvare il dato.
    printf("Inserisci un numero intero: ");
    scanf("%d", &utente_int);
    
    // Richiesta di un float.
    printf("Inserisci un numero decimale (usa il punto, es. 3.5): ");
    scanf("%f", &utente_float);

    // RISOLUZIONE PROBLEMA 'INVIO' SUL CHAR:
    // Quando si preme 'Invio' dopo il float, il carattere '\n' rimane nel buffer della tastiera.
    // Una scanf normale per il %c catturerebbe quell'Invio al posto del carattere voluto.
    // SOLUZIONE: Inserire uno spazio o un \n prima di %c (es. " %c" o "\n%c") per pulire il buffer.
    printf("Inserisci una singola lettera: ");
    scanf("\n%c", &utente_char);

    // Stampa finale dei dati raccolti
    printf("\n--- RIEPILOGO DATI INSERITI ---\n");
    printf("Intero: %d\n", utente_int);
    printf("Decimale: %.3f (precisione a 3 cifre)\n", utente_float);
    printf("Carattere: %c\n", utente_char);
    printf("Circonferenza calcolata con PIGRECO: %.2f\n", 2 * PIGRECO * utente_float);

    return 0;
}