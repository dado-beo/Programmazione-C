/*
- =====================================================================================
-  NOME FILE: 11_stringhe.c
-  CORSO: Programmazione C (UPO)
-  ARGOMENTO: Stringhe, Terminatore '\0', Memoria, I/O (%s), Libreria string.h,
-             Passaggio per Riferimento, Tabella ASCII, Ricerche e Parole Palindrome
- =====================================================================================
 *
- --- NOTE SULLA TEORIA (Tratte dalle slide) ---
- 1. DEFINIZIONE: Una stringa e' una parola memorizzata in un vettore di caratteri (char).
-    Il primo carattere e' all'indice 0, il secondo all'indice 1, ecc.
- 2. FINE STRINGA ('\0'): Carattere speciale detto NUL (codice ASCII 0). Separa la porzione
-    di vettore usata dalla parte inutilizzata. E' OBBLIGATORIO.
- 3. LUNGHEZZA: Numero di caratteri significativi ('\0' escluso). Es. "ciao" ha lunghezza 4.
-    Un vettore di dimensione DIM contiene stringhe di lunghezza massima DIM - 1
-    (una casella va sempre riservata a '\0').
- 4. MEMORIA (RAM): char s[10]; riserva 10 byte consecutivi (1 byte per ogni char),
-    incluse le caselle non utilizzate dalla parola.
- 5. STRINGA VUOTA: Non contiene caratteri significativi, ma contiene '\0' in posizione 0
-    (es. char s[10] = ""; oppure char s[10] = {'\0'}; oppure s[0] = '\0';).
- 6. ASSEGNAMENTO E CONFRONTO DIRETTI VIETATI:
-    - NON si puo' scrivere w = s; (equivarrebbe a &w[0] = &s[0]). Usare ciclo o strcpy().
-    - NON si puo' scrivere if (s == w) (confronta gli indirizzi). Usare ciclo o strcmp().
- 7. INPUT/OUTPUT:
-    - scanf("%s", s); -> legge la parola e aggiunge '\0' automaticamente. NON si usa &s
-      perche' il nome del vettore s equivale gia' a &s[0].
-    - printf("%s", s); -> stampa fino a '\0' (escluso), ignorando il resto del vettore.
- 8. PASSAGGIO PER RIFERIMENTO: Le stringhe (come vettori e matrici) sono SEMPRE passate
-    per riferimento alle funzioni: char s[] equivale a char *s, e passare s equivale a &s[0].
- 9. TABELLA ASCII E CASE-SENSITIVE: Le lettere e le cifre sono consecutive in ASCII:
-    - Minuscole: 'a'..'z' (97..122)
-    - Maiuscole: 'A'..'Z' (65..90)
-    - Cifre:     '0'..'9' (48..57)
-    Il confronto e' case-sensitive: 'a' e 'A' sono caratteri diversi.
- 10. ERRORI COMUNI:
-    - Dimenticare '\0' o lasciare caselle indefinite prima di '\0'.
-    - Confondere 'c' (carattere) con c (variabile di nome c).
-    - Usare i < dim invece di s[i] != '\0' (o i < len) nei cicli sulle stringhe.
-    - Assegnare una stringa piu' lunga della dimensione dichiarata (errore di compilazione).
 */

#include <stdio.h>
#include <string.h> // Necessaria per strlen(), strcpy(), strcmp()

// Costanti simboliche per le dimensioni dei vettori di caratteri
#define DIM 30
#define DIM_PICCOLA 10

// =============================================================================
// PROTOTIPI DELLE FUNZIONI (definite in fondo al file)
// =============================================================================
void stampa_stringa_ciclo(char s[]);
void carica_caratteri_successivi(char s[], int dim, char c);

int calcola_lunghezza_while(char s[]);
int calcola_lunghezza_for(char s[]);
void copia_stringa(char w[], char s[]);

// Versioni con uso esplicito dei puntatori (equivalenti a char s[])
int calcola_lunghezza_ptr(char *s);
void copia_stringa_ptr(char *w, char *s);

int confronta_stringhe(char s[], char w[]);

// Verifica di proprieta' sui caratteri
int tutti_minuscoli(char s[]);
int esiste_maiuscolo(char s[]);
int contiene_cifra(char s[]);
int tutti_vocali(char s[]);
int esiste_vocale_maiuscola(char s[]);

// Ricerche e conteggi di un carattere
int cerca_prima_occorrenza(char s[], char c);
int cerca_ultima_occorrenza(char s[], char c);
int conta_occorrenze(char s[], char c);

// Parola palindroma
int palindrome(char s[]);


int main(void) {

    // =========================================================================
    // 1. DICHIARAZIONE, ASSEGNAMENTO, STRINGA VUOTA E MEMORIA (sizeof)
    // =========================================================================
    printf("=== 1. DICHIARAZIONE, STRINGA VUOTA E MEMORIA ===\n");

    // Modo 1: Dichiarazione con lista di caratteri tra graffe ('\0' OBBLIGATORIO)
    char s1[DIM_PICCOLA] = {'c', 'i', 'a', 'o', '\0'};

    // Modo 2: Dichiarazione con doppi apici ('\0' aggiunto automaticamente)
    char s2[DIM_PICCOLA] = "ciao";

    // Modo 3: Dimensione omessa -> calcolata automaticamente al minimo (4 char + '\0' = 5 byte)
    char s3[] = "ciao";

    // Modo 4: Assegnamento diretto casella per casella
    // ATTENZIONE: 'c' e' il carattere, c sarebbe una variabile!
    // Non dimenticare '\0' e non lasciare caselle indefinite (es. saltare s4[2]).
    char s4[DIM_PICCOLA];
    s4[0] = 'c';
    s4[1] = 'i';
    s4[2] = 'a';
    s4[3] = 'o';
    s4[4] = '\0';

    // ESEMPI DI ERRORI DA NON COMMETTERE (commentati per permettere la compilazione):
    // char err1[10] = "buongiorno!";              // ERRORE: 11 caratteri + '\0' non entrano in 10!
    // char err2[10] = {'c', 'i', 'a', 'o'};       // NO: manca '\0' (non e' una stringa valida)
    // s4[0]='c'; s4[1]='i'; s4[3]='o'; s4[4]='\0'; // NO: s4[2] resta indefinito!

    // Stringa vuota: nessun carattere significativo, ma '\0' in posizione 0 e' obbligatorio
    char vuota1[DIM_PICCOLA] = {'\0'};
    char vuota2[DIM_PICCOLA] = "";
    char vuota3[DIM_PICCOLA];
    vuota3[0] = '\0';

    printf("s1: %s | s2: %s | s3: %s | s4: %s\n", s1, s2, s3, s4);
    printf("Stringhe vuote -> vuota1: '%s', vuota2: '%s', vuota3: '%s'\n", vuota1, vuota2, vuota3);

    // Occupazione in RAM: 1 byte per ogni casella del vettore (anche quelle non usate)
    printf("Memoria occupata da s1[10]: %lu byte (lunghezza utile max: %d)\n",
           (unsigned long)sizeof(s1), DIM_PICCOLA - 1);
    printf("Memoria occupata da s3[] (\"ciao\"): %lu byte (4 caratteri + '\\0')\n\n",
           (unsigned long)sizeof(s3));

    // =========================================================================
    // 2. VISUALIZZAZIONE DI UNA STRINGA (CICLO for VS FORMATO %s)
    // =========================================================================
    printf("=== 2. VISUALIZZAZIONE DI UNA STRINGA ===\n");

    // Metodo 1: Ciclo carattere per carattere fino a '\0' (NON usare i < dim!)
    printf("Stampa con ciclo for (s[i] != '\\0'): ");
    stampa_stringa_ciclo(s1);

    // Metodo 2: Formato compatto %s (stampa automaticamente fino a '\0')
    printf("Stampa compatta con %%s:              %s\n\n", s1);

    // =========================================================================
    // 3. CARICAMENTO AUTOMATICO DI UNA STRINGA CON FUNZIONE
    // =========================================================================
    printf("=== 3. CARICAMENTO AUTOMATICO ===\n");

    char sequenza[5]; // Puo' contenere 4 caratteri + '\0'
    carica_caratteri_successivi(sequenza, 5, 'd');
    printf("4 caratteri consecutivi a partire da 'd': %s\n\n", sequenza);

    // =========================================================================
    // 4. LUNGHEZZA, COPIA, string.h E PASSAGGIO CON PUNTATORI ESPLICITI
    // =========================================================================
    printf("=== 4. LUNGHEZZA, COPIA E PASSAGGIO PER RIFERIMENTO ===\n");

    char originale[DIM] = "ciao";
    char copia_man[DIM];
    char copia_lib[DIM];
    char copia_ptr[DIM];

    // Calcolo lunghezza: versioni manuali (while e for senza corpo) vs strlen()
    int len_w = calcola_lunghezza_while(originale);
    int len_f = calcola_lunghezza_for(originale);
    int len_s = (int)strlen(originale);

    printf("Lunghezza di \"%s\" -> while: %d | for: %d | strlen(): %d\n",
           originale, len_w, len_f, len_s);

    // Copia stringa: NON si puo' scrivere copia_man = originale;
    // Versione manuale vs strcpy(destinazione, sorgente)
    copia_stringa(copia_man, originale);
    strcpy(copia_lib, originale);

    printf("Copia manuale: %s | Copia con strcpy(): %s\n", copia_man, copia_lib);

    // Passaggio per riferimento esplicito tramite puntatori (&vettore[0] -> char*)
    int len_p = calcola_lunghezza_ptr(&originale[0]);
    copia_stringa_ptr(&copia_ptr[0], &originale[0]);
    printf("Con puntatori espliciti -> lunghezza: %d | copia: %s\n\n", len_p, copia_ptr);

    // =========================================================================
    // 5. UGUAGLIANZA E CONFRONTO TRA STRINGHE (MANUALE VS strcmp)
    // =========================================================================
    printf("=== 5. CONFRONTO TRA STRINGHE ===\n");

    // NON si puo' scrivere if (a == b) perche' confronterebbe gli indirizzi &a[0] == &b[0]!
    char p1[] = "ciao";
    char p2[] = "ciao";
    char p3[] = "Ciao";  // Diversa perche' 'c' != 'C' (case-sensitive)
    char p4[] = "ciao!"; // Lunghezza diversa

    printf("Confronto manuale \"%s\" vs \"%s\":  %d (1=uguali, 0=diverse)\n",
           p1, p2, confronta_stringhe(p1, p2));
    printf("Confronto manuale \"%s\" vs \"%s\":  %d (case-sensitive!)\n",
           p1, p3, confronta_stringhe(p1, p3));
    printf("Confronto manuale \"%s\" vs \"%s\": %d (lunghezze diverse)\n",
           p1, p4, confronta_stringhe(p1, p4));

    // strcmp(s, w): restituisce 0 se uguali, <0 se s precede w, >0 se s segue w in ordine alfabetico
    char alfa1[] = "albero";
    char alfa2[] = "casa";
    int diff = strcmp(alfa1, alfa2);
    printf("strcmp(\"%s\", \"%s\") = %d -> ", alfa1, alfa2, diff);
    if (diff == 0)
        printf("le parole sono uguali\n\n");
    else if (diff > 0)
        printf("\"%s\" segue \"%s\" in ordine alfabetico\n\n", alfa1, alfa2);
    else
        printf("\"%s\" precede \"%s\" in ordine alfabetico\n\n", alfa1, alfa2);

    // =========================================================================
    // 6. VERIFICA DI PROPRIETA' SUI CARATTERI E CODICI ASCII
    // =========================================================================
    printf("=== 6. PROPRIETA' DEI CARATTERI (TABELLA ASCII) ===\n");

    char test_min[] = "ciao";
    char test_mai[] = "ciAo";
    char test_cif[] = "corso2026";
    char test_voc[] = "uiao";

    printf("\"%s\" ha tutti caratteri minuscoli?       %d\n", test_min, tutti_minuscoli(test_min));
    printf("\"%s\" ha almeno un carattere maiuscolo?   %d\n", test_mai, esiste_maiuscolo(test_mai));
    printf("\"%s\" contiene almeno una cifra?     %d\n", test_cif, contiene_cifra(test_cif));
    printf("\"%s\" ha tutte vocali minuscole?          %d\n", test_voc, tutti_vocali(test_voc));
    printf("\"%s\" ha almeno una vocale maiuscola?     %d\n\n", test_mai, esiste_vocale_maiuscola(test_mai));

    // =========================================================================
    // 7. RICERCA (PRIMA/ULTIMA OCCORRENZA) E CONTEGGIO DI UN CARATTERE
    // =========================================================================
    printf("=== 7. RICERCA E CONTEGGIO DI UN CARATTERE ===\n");

    char saluto[] = "buonasera";
    char cercato = 'a';
    char assente = 'z';

    printf("Stringa: \"%s\"\n", saluto);
    printf("Carattere '%c' -> prima occorrenza: indice %d | ultima: indice %d | totale: %d\n",
           cercato,
           cerca_prima_occorrenza(saluto, cercato),
           cerca_ultima_occorrenza(saluto, cercato),
           conta_occorrenze(saluto, cercato));
    printf("Carattere '%c' -> prima occorrenza: %d (assente) | totale: %d\n\n",
           assente,
           cerca_prima_occorrenza(saluto, assente),
           conta_occorrenze(saluto, assente));

    // =========================================================================
    // 8. PAROLE PALINDROME (CASE-SENSITIVE)
    // =========================================================================
    printf("=== 8. PAROLE PALINDROME ===\n");

    // Si leggono allo stesso modo da sinistra a destra e da destra a sinistra
    printf("\"ingegni\" e' palindroma? %d (atteso: 1)\n", palindrome("ingegni"));
    printf("\"insegni\" e' palindroma? %d (atteso: 0)\n", palindrome("insegni"));
    printf("\"anna\"    e' palindroma? %d (atteso: 1)\n", palindrome("anna"));
    printf("\"Anna\"    e' palindroma? %d (atteso: 0 -> confronto case-sensitive!)\n\n", palindrome("Anna"));

    // =========================================================================
    // 9. INPUT DA TASTIERA (scanf con %s) E PROVA INTERATTIVA
    // =========================================================================
    printf("=== 9. INPUT DA TASTIERA (scanf) ===\n");

    char parola1[DIM], parola2[DIM], copia_utente[DIM];
    char ch;

    // NOTA: con %s NON si mette & davanti al nome della stringa (parola1 equivale a &parola1[0]).
    // scanf("%s", ...) legge una singola parola senza spazi e inserisce '\0' in automatico.
    printf("Inserisci la prima parola (senza spazi): ");
    scanf("%s", parola1);

    printf("Inserisci la seconda parola (senza spazi): ");
    scanf("%s", parola2);

    // Lo spazio prima di %c pulisce eventuali '\n' rimasti nel buffer della tastiera
    printf("Inserisci un carattere da cercare nella prima parola: ");
    scanf(" %c", &ch);

    strcpy(copia_utente, parola1);

    printf("\n--- RIEPILOGO ANALISI SU \"%s\" E \"%s\" ---\n", parola1, parola2);
    printf("Lunghezza prima parola (strlen): %lu\n", (unsigned long)strlen(parola1));
    printf("Copia effettuata con strcpy:     %s\n", copia_utente);

    // Confronto con strcmp
    int ris_cmp = strcmp(parola1, parola2);
    if (ris_cmp == 0) {
        printf("Confronto (strcmp): le due parole sono UGUALI.\n");
    } else if (ris_cmp > 0) {
        printf("Confronto (strcmp): \"%s\" segue \"%s\" in ordine alfabetico.\n", parola1, parola2);
    } else {
        printf("Confronto (strcmp): \"%s\" precede \"%s\" in ordine alfabetico.\n", parola1, parola2);
    }

    // Proprieta' e palindroma sulla prima parola
    printf("Tutti minuscoli: %s | Almeno un maiuscolo: %s | Palindroma: %s\n",
           tutti_minuscoli(parola1) ? "SI" : "NO",
           esiste_maiuscolo(parola1) ? "SI" : "NO",
           palindrome(parola1) ? "SI" : "NO");

    // Ricerche del carattere scelto
    int prima = cerca_prima_occorrenza(parola1, ch);
    int ultima = cerca_ultima_occorrenza(parola1, ch);
    int volte = conta_occorrenze(parola1, ch);
    if (prima != -1) {
        printf("Carattere '%c' trovato %d volte (prima pos: %d, ultima pos: %d).\n",
               ch, volte, prima, ultima);
    } else {
        printf("Carattere '%c' non presente in \"%s\".\n", ch, parola1);
    }

    return 0;
}


// =============================================================================
// IMPLEMENTAZIONE DELLE FUNZIONI
// =============================================================================

// Stampa una stringa carattere per carattere fermandosi al terminatore '\0'
void stampa_stringa_ciclo(char s[]) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        printf("%c", s[i]);
    }
    printf("\n");
}

// Carica dim - 1 caratteri consecutivi a partire da c e chiude sempre con '\0'
void carica_caratteri_successivi(char s[], int dim, char c) {
    int i;
    for (i = 0; i < dim - 1; i++) {
        s[i] = c;
        c++; // Incrementa il codice ASCII passando al carattere successivo
    }
    s[i] = '\0'; // Fondamentale: inserisce il terminatore nell'ultima casella
}

// Calcola la lunghezza della stringa con ciclo while
// All'uscita, i vale sia la lunghezza della stringa sia l'indice di '\0'
int calcola_lunghezza_while(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

// Calcola la lunghezza della stringa con ciclo for senza corpo (notare il ';' finale!)
int calcola_lunghezza_for(char s[]) {
    int i;
    for (i = 0; s[i] != '\0'; i++);
    return i;
}

// Copia i caratteri da s (sorgente) a w (destinazione) e chiude w con '\0'
void copia_stringa(char w[], char s[]) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        w[i] = s[i];
    }
    w[i] = '\0'; // All'uscita dal ciclo, i indica la posizione dove mettere '\0' in w
}

// Versione con puntatore esplicito (char *s equivale a char s[])
int calcola_lunghezza_ptr(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

// Versione con puntatori espliciti (char *w, char *s)
void copia_stringa_ptr(char *w, char *s) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        w[i] = s[i];
    }
    w[i] = '\0';
}

// Verifica manuale dell'uguaglianza tra due stringhe (1 = uguali, 0 = diverse)
int confronta_stringhe(char s[], char w[]) {
    int uguali = 1; // Si assume inizialmente che siano uguali
    int len1 = calcola_lunghezza_while(s);
    int len2 = calcola_lunghezza_while(w);
    int i;

    if (len1 != len2) {
        uguali = 0; // Lunghezze diverse -> sicuramente diverse
    } else {
        // Stessa lunghezza: confronto casella per casella finche' restano uguali
        for (i = 0; s[i] != '\0' && uguali; i++) {
            if (s[i] != w[i]) {
                uguali = 0;
            }
        }
    }
    return uguali;
}

// Verifica se TUTTI i caratteri sono lettere minuscole ('a'..'z', ossia ASCII 97..122)
int tutti_minuscoli(char s[]) {
    int i, minus = 1; // Proprieta' universale: si assume vera (1)
    for (i = 0; s[i] != '\0' && minus; i++) {
        // Equivalente a: !(s[i] >= 'a' && s[i] <= 'z') oppure (s[i] < 97 || s[i] > 122)
        if (s[i] < 'a' || s[i] > 'z') {
            minus = 0;
        }
    }
    return minus;
}

// Verifica se ALMENO UN carattere e' maiuscolo ('A'..'Z', ossia ASCII 65..90)
// Esempio con la condizione di ciclo alternativa: i < len (dove len = strlen(s))
int esiste_maiuscolo(char s[]) {
    int i, maius = 0; // Proprieta' esistenziale: si assume falsa (0)
    int len = (int)strlen(s);
    for (i = 0; i < len && !maius; i++) {
        // Equivalente a: (s[i] >= 65 && s[i] <= 90)
        if (s[i] >= 'A' && s[i] <= 'Z') {
            maius = 1;
        }
    }
    return maius;
}

// Verifica se almeno un carattere e' una cifra ('0'..'9', ossia ASCII 48..57)
// Negazione (non cifra): (s[i] < '0' || s[i] > '9') oppure !(s[i] >= '0' && s[i] <= '9')
int contiene_cifra(char s[]) {
    int i, cifra = 0;
    for (i = 0; s[i] != '\0' && !cifra; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            cifra = 1;
        }
    }
    return cifra;
}

// Verifica se TUTTI i caratteri sono vocali minuscole (a, e, i, o, u)
int tutti_vocali(char s[]) {
    int i, vocali = 1;
    for (i = 0; s[i] != '\0' && vocali; i++) {
        if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u') {
            vocali = 0;
        }
    }
    return vocali;
}

// Verifica se ALMENO UN carattere e' una vocale maiuscola (A, E, I, O, U)
int esiste_vocale_maiuscola(char s[]) {
    int i, vocale = 0;
    for (i = 0; s[i] != '\0' && !vocale; i++) {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            vocale = 1;
        }
    }
    return vocale;
}

// Restituisce l'indice della PRIMA occorrenza di c, oppure -1 se c e' assente
// Il ciclo si ferma appena trovato (indice == -1 diventa falso)
int cerca_prima_occorrenza(char s[], char c) {
    int i, indice = -1;
    for (i = 0; s[i] != '\0' && indice == -1; i++) {
        if (s[i] == c) {
            indice = i;
        }
    }
    return indice;
}

// Restituisce l'indice dell'ULTIMA occorrenza di c, oppure -1 se c e' assente
// Scorre tutta la stringa fino a '\0' sovrascrivendo indice ad ogni corrispondenza
int cerca_ultima_occorrenza(char s[], char c) {
    int i, indice = -1;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            indice = i;
        }
    }
    return indice;
}

// Restituisce il numero totale di occorrenze di c nella stringa (0 se assente)
int conta_occorrenze(char s[], char c) {
    int i, conta = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            conta++;
        }
    }
    return conta;
}

// Verifica se la parola e' palindroma (1 = palindroma, 0 = non palindroma)
// Confronta il primo carattere con l'ultimo, il secondo col penultimo, ecc. (case-sensitive)
int palindrome(char s[]) {
    int i = 0;
    int j = (int)strlen(s) - 1;
    int pal = 1;

    while (i < j && pal) {
        if (s[i] != s[j]) {
            pal = 0;
        } else {
            i++;
            j--;
        }
    }
    return pal;
}