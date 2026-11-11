/*
 * =====================================================================================
 *  NOME FILE: 10_matrici.c
 *  CORSO: Programmazione C
 *  ARGOMENTO: Matrici, Dichiarazione, Cicli annidati, Passaggio parametri, 
 *             Operazioni globali e su singole righe/colonne.
 * =====================================================================================
 *
 * --- NOTE SULLA TEORIA (Tratte dalle slide) ---
 * 1. COSA E' UNA MATRICE: 
 *    - È una tabella (o vettore a due dimensioni) composta da Righe (R) e Colonne (C).
 *    - Occupa una porzione di memoria contigua: R * C * dimensione_tipo.
 * 2. INDICI E DIMENSIONI:
 *    - Le righe vanno dall'indice 0 all'indice R-1.
 *    - Le colonne vanno dall'indice 0 all'indice C-1.
 *    - m[0][0] è il primo elemento, m[R-1][C-1] è l'ultimo.
 * 3. DICHIARAZIONE E ASSEGNAMENTO:
 *    - Sintassi: tipo nome[righe][colonne]; (es. int m[3][4];)
 *    - Inizializzazione: int m[2][2] = { {1, 2}, {3, 4} };
 *    - ATTENZIONE: l'indicazione del numero di COLONNE è sempre obbligatoria.
 * 4. PASSAGGIO AI SOTTOPROGRAMMI:
 *    - Come i vettori, le matrici sono passate SEMPRE PER RIFERIMENTO.
 *    - Nella chiamata si usa il nome: funzione(mat); che equivale a &mat[0].
 *    - Nel prototipo la dichiarazione deve specificare il numero di colonne:
 *      void funzione(int m[][C]); che equivale al puntatore int (*m)[C].
 * 5. ACCESSO AGLI ELEMENTI (DOPPIO CICLO):
 *    - Per scorrere l'intera matrice si usano due cicli `for` annidati: 
 *      quello esterno scorre le righe (r), quello interno le colonne (c).
 * 6. OPERAZIONI SU RIGHE/COLONNE SPECIFICHE:
 *    - Fissando la riga (es. parametro 'riga') e iterando solo sulle colonne (c),
 *      si lavora solo su quella riga.
 *    - Fissando la colonna e iterando solo sulle righe (r), si lavora solo su quella colonna.
 */

#include <stdio.h>

// Definizione delle costanti per le dimensioni della matrice
#define R 3
#define C 4

/* ==========================================
 * PROTOTIPI DI FUNZIONE
 * ========================================== */

// Operazioni di I/O
void carica_matrice(int m[][C]);
void visualizza_matrice(int m[][C]);

// Operazioni sull'intera matrice
int somma_matrice(int m[][C]);
int prodotto_matrice(int m[][C]);
float media_matrice(int m[][C]);
int massimo_matrice(int m[][C]);

// Operazioni logiche e di ricerca sull'intera matrice
int tutti_positivi(int m[][C]);
int esiste_positivo(int m[][C]);
int cerca_valore(int m[][C], int x);

// Operazioni su una singola RIGA
int somma_riga(int m[][C], int riga);
int prodotto_riga(int m[][C], int riga);
float media_riga(int m[][C], int riga);
int massimo_riga(int m[][C], int riga);

// Operazioni su una singola COLONNA
int somma_colonna(int m[][C], int colonna);
int prodotto_colonna(int m[][C], int colonna);
float media_colonna(int m[][C], int colonna);
int massimo_colonna(int m[][C], int colonna);

/* ==========================================
 * MAIN PROGRAM
 * ========================================== */
int main(void) {
    int mat[R][C];
    int scelta, x, indice;

    printf("=== GESTIONE MATRICI (Slide 10) ===\n");
    printf("Dimensione: %d Righe x %d Colonne.\n\n", R, C);

    // Caricamento iniziale
    carica_matrice(mat);
    visualizza_matrice(mat);

    do {
        printf("\n--- MENU OPERAZIONI ---\n");
        printf(" 1. Calcola Somma, Prodotto, Media e Massimo (Intera Matrice)\n");
        printf(" 2. Verifica se TUTTI i valori sono positivi\n");
        printf(" 3. Verifica se ESISTE ALMENO UN valore positivo\n");
        printf(" 4. Cerca se un valore X e' presente\n");
        printf(" 5. Analizza una RIGA specifica (Somma, Prodotto, Media, Max)\n");
        printf(" 6. Analizza una COLONNA specifica (Somma, Prodotto, Media, Max)\n");
        printf(" 7. Visualizza di nuovo la matrice\n");
        printf(" 8. Ricarica nuovi valori nella matrice\n");
        printf(" 0. Uscita\n");
        printf("Scegli un'opzione: ");
        scanf("%d", &scelta);
        printf("\n");

        switch (scelta) {
            case 1:
                printf("Somma totale: %d\n", somma_matrice(mat));
                printf("Prodotto totale: %d\n", prodotto_matrice(mat));
                printf("Media totale: %.2f\n", media_matrice(mat));
                printf("Massimo assoluto: %d\n", massimo_matrice(mat));
                break;

            case 2:
                if (tutti_positivi(mat))
                    printf("ESITO: I valori sono TUTTI positivi.\n");
                else
                    printf("ESITO: I valori NON sono tutti positivi.\n");
                break;

            case 3:
                if (esiste_positivo(mat))
                    printf("ESITO: Almeno un valore E' positivo.\n");
                else
                    printf("ESITO: NESSUN valore e' positivo.\n");
                break;

            case 4:
                printf("Inserisci il valore X da cercare: ");
                scanf("%d", &x);
                if (cerca_valore(mat, x))
                    printf("Il valore %d E' PRESENTE nella matrice.\n", x);
                else
                    printf("Il valore %d e' ASSENTE.\n", x);
                break;

            case 5:
                printf("Inserisci l'indice della riga (da 0 a %d): ", R - 1);
                scanf("%d", &indice);
                if (indice >= 0 && indice < R) {
                    printf("Somma riga %d: %d\n", indice, somma_riga(mat, indice));
                    printf("Prodotto riga %d: %d\n", indice, prodotto_riga(mat, indice));
                    printf("Media riga %d: %.2f\n", indice, media_riga(mat, indice));
                    printf("Massimo riga %d: %d\n", indice, massimo_riga(mat, indice));
                } else {
                    printf("Indice riga non valido!\n");
                }
                break;

            case 6:
                printf("Inserisci l'indice della colonna (da 0 a %d): ", C - 1);
                scanf("%d", &indice);
                if (indice >= 0 && indice < C) {
                    printf("Somma colonna %d: %d\n", indice, somma_colonna(mat, indice));
                    printf("Prodotto colonna %d: %d\n", indice, prodotto_colonna(mat, indice));
                    printf("Media colonna %d: %.2f\n", indice, media_colonna(mat, indice));
                    printf("Massimo colonna %d: %d\n", indice, massimo_colonna(mat, indice));
                } else {
                    printf("Indice colonna non valido!\n");
                }
                break;

            case 7:
                visualizza_matrice(mat);
                break;

            case 8:
                carica_matrice(mat);
                visualizza_matrice(mat);
                break;

            case 0:
                printf("Uscita dal programma.\n");
                break;

            default:
                printf("Opzione non valida!\n");
        }
    } while (scelta != 0);

    return 0;
}

/* ==========================================
 * DEFINIZIONE DELLE FUNZIONI
 * ========================================== */

// --- FUNZIONI DI I/O GLOBALI ---

void carica_matrice(int m[][C]) {
    int r, c;
    printf("--- Inserimento Valori Matrice ---\n");
    for (r = 0; r < R; r++) {
        for (c = 0; c < C; c++) {
            printf("Inserisci valore per [%d][%d]: ", r, c);
            scanf("%d", &m[r][c]);
        }
    }
    printf("\n");
}

void visualizza_matrice(int m[][C]) {
    int r, c;
    printf("--- Contenuto Matrice ---\n");
    for (r = 0; r < R; r++) {
        for (c = 0; c < C; c++) {
            printf("%4d ", m[r][c]); // %4d allinea i numeri in colonna
        }
        printf("\n"); // A capo alla fine di ogni riga
    }
    printf("-------------------------\n");
}

// --- FUNZIONI MATEMATICHE GLOBALI ---

int somma_matrice(int m[][C]) {
    int r, c, somma = 0;
    for (r = 0; r < R; r++) {
        for (c = 0; c < C; c++) {
            somma = somma + m[r][c];
        }
    }
    return somma;
}

int prodotto_matrice(int m[][C]) {
    int r, c, prodotto = 1;
    for (r = 0; r < R; r++) {
        for (c = 0; c < C; c++) {
            prodotto = prodotto * m[r][c];
        }
    }
    return prodotto;
}

float media_matrice(int m[][C]) {
    int r, c, somma = 0;
    for (r = 0; r < R; r++) {
        for (c = 0; c < C; c++) {
            somma = somma + m[r][c];
        }
    }
    return (float)somma / (R * C); // Cast a float per divisione reale
}

int massimo_matrice(int m[][C]) {
    int r, c, massimo;
    for (r = 0; r < R; r++) {
        for (c = 0; c < C; c++) {
            if (r == 0 && c == 0) {
                massimo = m[r][c]; // Inizializza con il primissimo elemento
            } else {
                if (m[r][c] > massimo) {
                    massimo = m[r][c];
                }
            }
        }
    }
    return massimo;
}

// --- FUNZIONI LOGICHE / RICERCA GLOBALI ---

int tutti_positivi(int m[][C]) {
    int r, c, positivi = 1;
    // Doppio ciclo che si interrompe se positivi diventa 0
    for (r = 0; r < R && positivi; r++) {
        for (c = 0; c < C && positivi; c++) {
            if (!(m[r][c] > 0)) {
                positivi = 0;
            }
        }
    }
    return positivi;
}

int esiste_positivo(int m[][C]) {
    int r, c, positivo = 0;
    // Doppio ciclo che si interrompe appena positivo diventa 1
    for (r = 0; r < R && !positivo; r++) {
        for (c = 0; c < C && !positivo; c++) {
            if (m[r][c] > 0) {
                positivo = 1;
            }
        }
    }
    return positivo;
}

int cerca_valore(int m[][C], int x) {
    int r, c, presente = 0;
    // Doppio ciclo che si interrompe appena trova x (presente diventa 1)
    for (r = 0; r < R && !presente; r++) {
        for (c = 0; c < C && !presente; c++) {
            if (m[r][c] == x) {
                presente = 1;
            }
        }
    }
    return presente;
}

// --- FUNZIONI SU SINGOLA RIGA (L'indice di riga e' FISSO) ---

int somma_riga(int m[][C], int riga) {
    int c, somma = 0;
    for (c = 0; c < C; c++) { // Scorre solo le colonne di quella riga
        somma = somma + m[riga][c];
    }
    return somma;
}

int prodotto_riga(int m[][C], int riga) {
    int c, prodotto = 1;
    for (c = 0; c < C; c++) {
        prodotto = prodotto * m[riga][c];
    }
    return prodotto;
}

float media_riga(int m[][C], int riga) {
    int c, somma = 0;
    for (c = 0; c < C; c++) {
        somma = somma + m[riga][c];
    }
    return (float)somma / C; // Divide per il numero di colonne (elementi in una riga)
}

int massimo_riga(int m[][C], int riga) {
    int c, massimo;
    for (c = 0; c < C; c++) {
        if (c == 0) {
            massimo = m[riga][c]; // Inizializza col primo elemento della riga
        } else {
            if (m[riga][c] > massimo) {
                massimo = m[riga][c];
            }
        }
    }
    return massimo;
}

// --- FUNZIONI SU SINGOLA COLONNA (L'indice di colonna e' FISSO) ---

int somma_colonna(int m[][C], int colonna) {
    int r, somma = 0;
    for (r = 0; r < R; r++) { // Scorre solo le righe di quella colonna
        somma = somma + m[r][colonna];
    }
    return somma;
}

int prodotto_colonna(int m[][C], int colonna) {
    int r, prodotto = 1;
    for (r = 0; r < R; r++) {
        prodotto = prodotto * m[r][colonna];
    }
    return prodotto;
}

float media_colonna(int m[][C], int colonna) {
    int r, somma = 0;
    for (r = 0; r < R; r++) {
        somma = somma + m[r][colonna];
    }
    return (float)somma / R; // Divide per il numero di righe (elementi in una colonna)
}

int massimo_colonna(int m[][C], int colonna) {
    int r, massimo;
    for (r = 0; r < R; r++) {
        if (r == 0) {
            massimo = m[r][colonna]; // Inizializza col primo elemento della colonna
        } else {
            if (m[r][colonna] > massimo) {
                massimo = m[r][colonna];
            }
        }
    }
    return massimo;
}