/*
 * =====================================================================================
 *  NOME FILE: 07_puntatoti.c
 *  CORSO: Programmazione C 
 *  ARGOMENTO: Teoria dei puntatori, passaggio per riferimento e funzioni a piu' risultati
 * =====================================================================================
 *
 * --- NOTE TEORICHE E SINTASSI ---
 *
 * 1. VARIABILI E MEMORIA:
 *    - Ogni variabile occupa una porzione di memoria RAM (dimensione in byte base al tipo).
 *    - L'indirizzo della variabile e' l'indirizzo del primo byte di quella porzione.
 *
 * 2. COSA E' UN PUNTATORE:
 *    - E' una variabile che contiene l'INDIRIZZO di un'altra variabile.
 *    - Dichiarazione: tipo* nome_puntatore; (es. int* p; float* p2;)
 *    - Il tipo del puntatore DEVE corrispondere al tipo della variabile puntata.
 *
 * 3. OPERATORI FONDAMENTALI:
 *    - & (Operatore Indirizzo): Variabile -> Indirizzo. (es. p = &x;)
 *    - * (Operatore Valore/Dereferenziazione): Indirizzo -> Valore. (es. *p = 25;)
 *
 * 4. STAMPA E LETTURA CON PUNTATORI:
 *    - In printf, %p visualizza un indirizzo in formato esadecimale (es. 0x...).
 *    - In scanf, se abbiamo gia' un puntatore 'p', non usiamo la '&'. (es. scanf("%d", p);)
 *
 * 5. ATTENZIONE AGLI ERRORI COMUNI:
 *    - INCREMENTO: Per incrementare il VALORE puntato, usare le parentesi: (*p)++ 
 *      Scrivere *p++ incrementa l'indirizzo, spostando il puntatore altrove (ERRORE!).
 *    - PUNTATORI NON INIZIALIZZATI: Mai usare *p se p non punta ancora a un indirizzo
 *      valido (es. p = &x). Altrimenti il programma va in crash (Segmentation Fault).
 *    - PUNTATORE NULL: Assegnare 'p = NULL;' significa che non punta a nulla (indirizzo 0).
 *
 * 6. PASSAGGIO DEI PARAMETRI NELLE FUNZIONI:
 *    - PER VALORE (es. int a): La funzione riceve una COPIA del valore. Le modifiche non 
 *      hanno effetto nel main.
 *    - PER RIFERIMENTO (es. int* a): La funzione riceve l'INDIRIZZO. Tramite '*a' la 
 *      funzione puo' modificare direttamente la variabile originale nel main.
 *
 * 7. FUNZIONI CON PIU' RISULTATI:
 *    - Il comando 'return' restituisce un solo valore.
 *    - Passando indirizzi (puntatori) come "parametri di output", una funzione di tipo void 
 *      puo' calcolare e restituire 2 o piu' risultati (es. area e perimetro contemporaneamente).
 */

#include <stdio.h>
#include <math.h> // Necessario per la funzione pow()

#define PI 3.141592 // Costante Pi Greco

// =================================================================================
// PROTOTIPI DELLE FUNZIONI (Passaggio per riferimento tramite puntatori)
// =================================================================================

// 1. Funzione che scambia i valori di due variabili nel main
void scambia(int* x, int* y);

// 2. Funzione che calcola 2 risultati: perimetro e area di un rettangolo
void perimetro_area(float b, float h, float* p, float* a);

// 3. Funzione che calcola 2 risultati: circonferenza e area di un cerchio
void circonferenza_area(float r, float* c, float* a);


// =================================================================================
// FUNZIONE MAIN
// =================================================================================
int main(void) {
    
    printf("=== 1. DIMOSTRAZIONE BASE PUNTATORI ===\n");
    int x = 12;
    int* ptr = &x; // ptr punta a x
    
    printf("Valore di x: %d\n", x);
    printf("Indirizzo di x (&x): %p\n", &x);
    printf("Contenuto di ptr (indirizzo di x): %p\n", ptr);
    
    (*ptr)++; // Incremento il valore di x tramite il puntatore (Parentesi OBBLIGATORIE)
    printf("Nuovo valore di x dopo (*ptr)++: %d\n\n", x);

    
    printf("=== 2. FUNZIONE SCAMBIA ===\n");
    int var1 = 3, var2 = 5;
    printf("Prima dello scambio: var1 = %d, var2 = %d\n", var1, var2);
    // Passo gli INDIRIZZI delle variabili
    scambia(&var1, &var2); 
    printf("Dopo lo scambio: var1 = %d, var2 = %d\n\n", var1, var2);


    printf("=== 3. PERIMETRO E AREA (RETTANGOLO) ===\n");
    float base = 5.1, altezza = 3.2;
    float ris_perimetro, ris_area_rettangolo; // Variabili destinate a ricevere i risultati
    
    // b e h passati per valore. Gli indirizzi di perimetro e area passati per riferimento.
    perimetro_area(base, altezza, &ris_perimetro, &ris_area_rettangolo);
    printf("Rettangolo (b=%.1f, h=%.1f) -> Perimetro: %.2f | Area: %.2f\n\n", 
            base, altezza, ris_perimetro, ris_area_rettangolo);


    printf("=== 4. CIRCONFERENZA E AREA (CERCHIO) ===\n");
    float raggio = 5.1;
    float ris_circonferenza, ris_area_cerchio;
    
    // r passato per valore. Gli indirizzi di c e a passati per riferimento.
    circonferenza_area(raggio, &ris_circonferenza, &ris_area_cerchio);
    printf("Cerchio (r=%.1f) -> Circonferenza: %.3f | Area: %.4f\n", 
            raggio, ris_circonferenza, ris_area_cerchio);

    return 0;
}


// =================================================================================
// DEFINIZIONE DELLE FUNZIONI
// =================================================================================

/*
 * Funzione scambia: 
 * Usa una variabile temporanea 'k' per scambiare i VALORI puntati da x e y.
 */
void scambia(int* x, int* y) {
    int k;
    k = *x;    // Salvo il valore originale del primo parametro
    *x = *y;   // Assegno il valore del secondo al primo
    *y = k;    // Assegno il valore salvato al secondo
}

/*
 * Funzione perimetro_area:
 * Scrive i risultati calcolati direttamente agli indirizzi puntati da p e a.
 */
void perimetro_area(float b, float h, float* p, float* a) {
    *p = (b + h) * 2.0; // Scrive il perimetro nella variabile puntata da p nel main
    *a = b * h;         // Scrive l'area nella variabile puntata da a nel main
}

/*
 * Funzione circonferenza_area:
 * Calcola circonferenza e area usando math.h e la costante PI.
 */
void circonferenza_area(float r, float* c, float* a) {
    *c = 2.0 * PI * r;         // Calcolo circonferenza
    *a = pow(r, 2.0) * PI;     // Calcolo area (r^2 * PI)
}