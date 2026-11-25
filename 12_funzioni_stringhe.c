/*
- =====================================================================================
- NOME FILE: 12_funzioni_stringhe.c
- CORSO: Programmazione C (UPO)
- ARGOMENTO: Funzioni per Caratteri (ctype.h), I/O Stringhe (stdio.h),
-            Funzioni per Stringhe (string.h), Inserimenti e Cancellazioni (Shift)
- =====================================================================================
*
- --- NOTE SULLA TEORIA (Tratte dalle slide) ---
1. I/O DI CARATTERI (libreria stdio.h):
- a = getchar();  -> Legge un singolo carattere da tastiera (equivale a scanf("%c", &a)).
- putchar(a);     -> Visualizza un singolo carattere (equivale a printf("%c", a)).
2. FUNZIONI PER I CARATTERI (libreria ctype.h, basate su Tabella ASCII):
- Verifica proprieta' (ritornano 0 se FALSO, un numero != 0 se VERO):
  * isalnum(c): alfanumerico (lettera o cifra)
  * isalpha(c): alfabetico (lettera)
  * isdigit(c): numerico (cifra '0'-'9')
  * isupper(c): lettera maiuscola ('A'-'Z')
  * islower(c): lettera minuscola ('a'-'z')
- Conversione (ritornano il carattere convertito, se applicabile):
  * tolower(c): converte in minuscolo
  * toupper(c): converte in maiuscolo
3. VOCALI E CONSONANTI (su char c):
- Vocale minuscola:     c=='a' || c=='e' || c=='i' || c=='o' || c=='u'
- Vocale maiuscola:     c=='A' || c=='E' || c=='I' || c=='O' || c=='U'
- Consonante minuscola: islower(c) && c!='a' && c!='e' && c!='i' && c!='o' && c!='u'
- Consonante maiuscola: isupper(c) && c!='A' && c!='E' && c!='I' && c!='O' && c!='U'
4. I/O DI STRINGHE (libreria stdio.h):
- scanf("%s", s): legge fino a spazio o invio (solo 1 parola), NON include '\n', mette '\0'.
  Rischio overflow! Per troncare a DIM-1 caratteri usare es. scanf("%9s", s) per char s[10].
- fgets(s, DIM, stdin): legge fino all'invio (anche frasi con spazi), INCLUDE '\n' prima di '\0'.
  Sicura: tronca automaticamente a DIM-1 caratteri (+ '\0' riservato).
  Per rimuovere '\n': len = strlen(s); s[len-1] = s[len]; (sposta '\0' a sinistra su '\n').
- printf("%s", s): stampa fino a '\0', NON va a capo da sola, permette testi complessi.
- puts(s): stampa solo la stringa fino a '\0' e va a capo AUTOMATICAMENTE.
- sscanf(s, formato, &var): legge/converte un valore da una stringa (es. stringa -> int/float).
- sprintf(s, msg, valori): compone una stringa formattata salvandola in s invece di stamparla.
5. FUNZIONI PER STRINGHE (libreria string.h):
- strchr(s, c): prima occorrenza di c in s (ritorna puntatore char* oppure NULL).
- strrchr(s, c): ultima occorrenza di c in s (ritorna puntatore char* oppure NULL).
- strstr(s1, s2): prima occorrenza della sottostringa s2 in s1 (ritorna char* oppure NULL).
- strcat(s1, s2): accoda s2 a s1 sovrascrivendo '\0' di s1 (ATTENZIONE: s1 deve avere spazio!).
- Varianti sui primi n caratteri:
  * strncat(s1, s2, n): accoda i primi n caratteri di s2 a s1 (serve spazio in s1).
  * strncmp(s1, s2, n): confronta i primi n caratteri di s1 e s2 (0 se uguali, != 0 altrimenti).
  * strncpy(dest, src, n): copia i primi n caratteri di src in dest.
    ATTENZIONE: NON mette '\0' in dest! Va aggiunto a mano: dest[n] = '\0';
6. MODIFICA DI UNA STRINGA (INSERIMENTI E CANCELLAZIONI):
- Il vettore puo' essere parzialmente usato: '\0' separa la parte usata da quella non usata.
- Inserimento: possibile solo se len < DIM-1 (1 cella e' sempre riservata a '\0').
- Cancellazione: possibile solo se len > 0 (stringa non vuota), senza lasciare "buchi" (shift).
- Generalizzazione: inserimento in testa = pos k=0, in coda = pos k=len.
                    cancellazione in testa = pos k=0, in coda = pos k=len-1.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define DIM 30
#define DIM_PICCOLA 10

// =========================================================================
// PROTOTIPI DELLE FUNZIONI (Implementate in fondo al file)
// =========================================================================
int cerca_carattere(char s[], char c);
int inserimento_coda(char s[], char c, int dim);
int inserimento_testa(char s[], char c, int dim);
int inserimento_posizione(char s[], char c, int k, int dim);
int cancellazione_coda(char s[]);
int cancellazione_testa(char s[]);
int cancellazione_posizione(char s[], int k);
void cancellazione_carattere(char s[], char c);
void pulisci_buffer(void);

int main(void) {

    // =========================================================================
    // 1. I/O CARATTERI (getchar/putchar), CTYPE.H, VOCALI E CONSONANTI
    // =========================================================================
    printf("=== 1. CARATTERI (getchar/putchar, ctype.h, vocali/consonanti) ===\n");

    char c, d;
    printf("Inserire un singolo carattere: ");
    c = getchar(); // Equivale a scanf("%c", &c);
    if (c != '\n') {
        pulisci_buffer(); // Rimuove l'Invio ('\n') rimasto nel buffer per le letture successive
    }

    printf("Hai inserito il carattere (stampato con putchar): ");
    putchar(c); // Equivale a printf("%c", c);
    printf("\n");

    // --- Esempio di controllo proprieta' (ctype.h) ---
    if (isalnum(c))
        printf(" -> il carattere e' alfanumerico (lettera o cifra)\n");
    if (isalpha(c))
        printf(" -> il carattere e' alfabetico (lettera)\n");
    if (isdigit(c))
        printf(" -> il carattere e' numerico (cifra)\n");
    if (islower(c))
        printf(" -> il carattere e' una lettera minuscola\n");
    if (isupper(c))
        printf(" -> il carattere e' una lettera maiuscola\n");

    // --- Esempio di conversione (toupper / tolower) ---
    if (islower(c)) {
        d = toupper(c);
        printf(" -> la lettera maiuscola corrispondente e': %c\n", d);
    }
    if (isupper(c)) {
        d = tolower(c);
        printf(" -> la lettera minuscola corrispondente e': %c\n", d);
    }

    // --- Condizioni per vocali e consonanti ---
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        printf(" -> e' una VOCALE minuscola\n");
    else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        printf(" -> e' una VOCALE maiuscola\n");
    else if (islower(c) && c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
        printf(" -> e' una CONSONANTE minuscola\n");
    else if (isupper(c) && c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U')
        printf(" -> e' una CONSONANTE maiuscola\n");

    printf("\n");

    // =========================================================================
    // 2. I/O STRINGHE: fgets vs scanf, DIMENSIONE, RIMOZIONE '\n', puts vs printf
    // =========================================================================
    printf("=== 2. I/O STRINGHE (fgets, scanf con limite, puts vs printf) ===\n");

    char frase[DIM];
    int len;

    // fgets legge anche gli spazi, ma INCLUDE '\n' prima di '\0'
    printf("Inserisci una frase (anche con spazi, max %d caratteri): ", DIM - 1);
    fgets(frase, DIM, stdin);

    // RIMOZIONE DI '\n' DALLA STRINGA LETTA CON fgets:
    // len e' sia la lunghezza della stringa sia l'indice di '\0'.
    // Spostando '\0' a sinistra (s[len-1] = s[len]) si sovrascrive '\n'.
    // (Controlliamo che l'ultimo carattere sia effettivamente '\n' nel caso la stringa fosse stata troncata)
    len = (int)strlen(frase);
    if (len > 0 && frase[len - 1] == '\n') {
        frase[len - 1] = frase[len];
    }

    // Confronto tra printf e puts:
    printf("Stampa con printf: \"%s\" (lunghezza: %d caratteri)\n", frase, (int)strlen(frase));
    printf("Stampa con puts (va a capo automaticamente):\n");
    puts(frase);

    // --- Troncamento con fgets e scanf su vettore di dimensione 10 ---
    // Un vettore char s[10] contiene al massimo 9 caratteri significativi + '\0'.
    // Es. se l'utente scrive "Buonasera!!!", viene troncata in "Buonasera".
    char parola_corta[DIM_PICCOLA];
    printf("\nInserisci una parola lunga (es. Buonasera!!! - verra' troncata a 9 char con scanf): ");
    scanf("%9s", parola_corta); // %9s indica la dimensione DIM-1 per evitare overflow!
    pulisci_buffer();           // Scarta eventuali caratteri in eccesso rimasti nel buffer
    printf("La parola letta con scanf(\"%%9s\") e': %s\n\n", parola_corta);

    // =========================================================================
    // 3. CONVERSIONE E COMPOSIZIONE: sscanf E sprintf (stdio.h)
    // =========================================================================
    printf("=== 3. sscanf E sprintf ===\n");

    // sscanf: legge/estrae valori da una stringa (utile per convertire stringhe in int/float)
    char str_int[DIM_PICCOLA] = "-18";
    char str_float[DIM_PICCOLA] = "2.75";
    int x_conv;
    float y_conv;

    sscanf(str_int, "%d", &x_conv);
    printf("sscanf su \"%s\" -> la variabile int x_conv vale: %d\n", str_int, x_conv);

    sscanf(str_float, "%f", &y_conv);
    printf("sscanf su \"%s\" -> la variabile float y_conv vale: %.2f\n", str_float, y_conv);

    // sprintf: come printf, ma scrive il risultato formattato dentro una stringa
    char str_composta[DIM_PICCOLA];
    int val = 7;
    sprintf(str_composta, "x vale %d", val); // Salva "x vale 7\0" in str_composta
    printf("Stringa composta con sprintf: \"%s\"\n\n", str_composta);

    // =========================================================================
    // 4. RICERCA IN STRINGHE: cerca_carattere, strchr, strrchr, strstr
    // =========================================================================
    printf("=== 4. RICERCA CARATTERI E SOTTOSTRINGHE (string.h) ===\n");

    char testo[DIM] = "buonasera";
    char da_cercare = 'a';
    char sottostringa[DIM] = "sera";

    // A) Ricerca manuale con funzione definita da noi
    int presente = cerca_carattere(testo, da_cercare);
    if (presente)
        printf("[cerca_carattere] '%c' e' presente in \"%s\"\n", da_cercare, testo);
    else
        printf("[cerca_carattere] '%c' NON e' presente in \"%s\"\n", da_cercare, testo);

    // B) strchr: cerca la PRIMA occorrenza del carattere (restituisce char* o NULL)
    char *p_primo = strchr(testo, da_cercare);
    if (p_primo != NULL)
        printf("[strchr]  Prima occorrenza di '%c' in \"%s\": parte da \"%s\"\n", da_cercare, testo, p_primo);
    else
        puts("[strchr]  Il carattere non e' presente nella stringa");

    // C) strrchr: cerca l'ULTIMA occorrenza del carattere (restituisce char* o NULL)
    char *p_ultimo = strrchr(testo, da_cercare);
    if (p_ultimo != NULL)
        printf("[strrchr] Ultima occorrenza di '%c' in \"%s\": parte da \"%s\"\n", da_cercare, testo, p_ultimo);

    // D) strstr: cerca la PRIMA occorrenza della sottostringa s2 dentro s1 (char* o NULL)
    char *p_sub = strstr(testo, sottostringa);
    if (p_sub != NULL)
        printf("[strstr]  \"%s\" e' contenuta in \"%s\" (trovata in: \"%s\")\n\n", sottostringa, testo, p_sub);
    else
        printf("[strstr]  \"%s\" NON e' contenuta in \"%s\"\n\n", sottostringa, testo);

    // =========================================================================
    // 5. CONCATENAZIONE E VARIANTI SU n CARATTERI (strcat, strncat, strncmp, strncpy)
    // =========================================================================
    printf("=== 5. strcat, strncat, strncmp E strncpy ===\n");

    // strcat: aggiunge s2 in coda a s1 (s1 DEVE avere spazio sufficiente!)
    char auguri[DIM] = "Felice ";
    char resto_auguri[] = "Anno Nuovo";
    strcat(auguri, resto_auguri); // Sovrascrive '\0' di auguri con 'A' e accoda il resto
    printf("Dopo strcat: \"%s\"\n", auguri);

    // strncat: aggiunge solo i primi n caratteri di s2 in coda a s1
    char saluto[DIM] = "Ciao ";
    strncat(saluto, "Mondo Bellissimo", 5); // Accoda solo "Mondo"
    printf("Dopo strncat (n=5): \"%s\"\n", saluto);

    // strncmp: confronta solo i primi n caratteri (0 se uguali, != 0 se diversi)
    char w1[] = "programma";
    char w2[] = "progetto";
    if (strncmp(w1, w2, 4) == 0)
        printf("strncmp(4): \"%s\" e \"%s\" hanno gli stessi primi 4 caratteri (\"prog\")\n", w1, w2);
    if (strncmp(w1, w2, 5) != 0)
        printf("strncmp(5): \"%s\" e \"%s\" differiscono entro i primi 5 caratteri\n", w1, w2);

    // strncpy: copia i primi n caratteri di source in dest
    // ATTENZIONE: strncpy NON inserisce '\0' automaticamente! Va aggiunto a mano!
    char dest[DIM];
    int n_copia = 6;
    strncpy(dest, auguri, n_copia);
    dest[n_copia] = '\0'; // Fondamentale per terminare correttamente la stringa!
    printf("Dopo strncpy (n=%d) + '\\0' manuale: \"%s\"\n\n", n_copia, dest);

    // =========================================================================
    // 6. MODIFICARE UNA STRINGA: INSERIMENTI (coda, testa, posizione k)
    // =========================================================================
    printf("=== 6. INSERIMENTI IN STRINGA (con shift a destra) ===\n");

    char s_ins[DIM_PICCOLA] = "ciao";
    int ins;
    printf("Stringa iniziale: \"%s\" (capacita' max: %d caratteri + '\\0')\n", s_ins, DIM_PICCOLA - 1);

    // Inserimento in coda: "ciao" -> "ciao!"
    ins = inserimento_coda(s_ins, '!', DIM_PICCOLA);
    if (ins)
        printf("Dopo inserimento_coda('!'):            \"%s\"\n", s_ins);
    else
        printf("Inserimento in coda fallito (vettore pieno)\n");

    // Inserimento in testa: "ciao!" -> ">ciao!"
    ins = inserimento_testa(s_ins, '>', DIM_PICCOLA);
    if (ins)
        printf("Dopo inserimento_testa('>'):           \"%s\"\n", s_ins);
    else
        printf("Inserimento in testa fallito (vettore pieno)\n");

    // Inserimento in posizione k=3: ">ciao!" -> ">ci*ao!"
    // Nota: k=0 equivale a inserimento_testa, k=strlen(s) equivale a inserimento_coda
    ins = inserimento_posizione(s_ins, '*', 3, DIM_PICCOLA);
    if (ins)
        printf("Dopo inserimento_posizione('*', k=3):  \"%s\"\n\n", s_ins);
    else
        printf("Inserimento in posizione k fallito (vettore pieno o k non valido)\n\n");

    // =========================================================================
    // 7. MODIFICARE UNA STRINGA: CANCELLAZIONI (coda, testa, pos k, carattere c)
    // =========================================================================
    printf("=== 7. CANCELLAZIONI IN STRINGA (con shift a sinistra) ===\n");

    char s_canc[DIM_PICCOLA] = "ciao";
    int canc;
    printf("Stringa iniziale: \"%s\"\n", s_canc);

    // Cancellazione in coda: "ciao" -> "cia"
    canc = cancellazione_coda(s_canc);
    if (canc)
        printf("Dopo cancellazione_coda:               \"%s\"\n", s_canc);
    else
        printf("Cancellazione fallita (stringa vuota)\n");

    // Cancellazione in testa: "cia" -> "ia"
    canc = cancellazione_testa(s_canc);
    if (canc)
        printf("Dopo cancellazione_testa:              \"%s\"\n", s_canc);
    else
        printf("Cancellazione fallita (stringa vuota)\n");

    // Cancellazione in posizione k=1: "ia" -> "i"
    // Nota: k=0 equivale a cancellazione_testa, k=strlen(s)-1 equivale a cancellazione_coda
    canc = cancellazione_posizione(s_canc, 1);
    if (canc)
        printf("Dopo cancellazione_posizione(k=1):     \"%s\"\n", s_canc);
    else
        printf("Cancellazione fallita (stringa vuota o k non valido)\n");

    // Cancellazione di TUTTE le occorrenze di un carattere c: "buonasera" senza 'a' -> "buonser"
    char s_rimuovi[DIM] = "buonasera";
    char target = 'a';
    printf("\nStringa prima di cancellazione_carattere: \"%s\"\n", s_rimuovi);
    cancellazione_carattere(s_rimuovi, target);
    printf("Dopo cancellazione_carattere('%c'):       \"%s\"\n", target, s_rimuovi);

    // --- Prova interattiva finale (come da invocazione nelle slide) ---
    printf("\n=== PROVA INTERATTIVA: CANCELLAZIONE CARATTERE ===\n");
    char stringa_utente[DIM];
    char carattere_utente;

    printf("Inserisci una parola (senza spazi): ");
    scanf("%29s", stringa_utente);
    printf("Inserisci il carattere da eliminare da \"%s\": ", stringa_utente);
    scanf("\n%c", &carattere_utente); // \n pulisce l'Invio rimasto nel buffer

    cancellazione_carattere(stringa_utente, carattere_utente);
    printf("La stringa modificata e': %s\n", stringa_utente);

    return 0;
}

// =========================================================================
// IMPLEMENTAZIONE DELLE FUNZIONI (Tratte dalle slide)
// =========================================================================

// Ricerca di c nella stringa: restituisce 1 se c e' presente, 0 se e' assente.
// Il ciclo si ferma appena trova c (!presente) oppure a fine stringa ('\0').
int cerca_carattere(char s[], char c) {
    int i, presente;
    presente = 0; // Si assume inizialmente che c sia assente
    for (i = 0; s[i] != '\0' && !presente; i++) {
        if (s[i] == c) {
            presente = 1; // Trovato!
        }
    }
    return presente;
}

// Inserimento di c in coda (in fondo):
// Restituisce 1 se avvenuto, 0 se il vettore e' pieno (len == dim - 1).
int inserimento_coda(char s[], char c, int dim) {
    int len, inserito;
    len = (int)strlen(s); // len e' sia la lunghezza sia la posizione di '\0'
    if (len == dim - 1) {
        inserito = 0; // Vettore pieno (un posto e' sempre riservato a '\0')
    } else {
        s[len] = c;        // Inserisce c dove prima c'era '\0'
        s[len + 1] = '\0'; // Inserisce il nuovo '\0' subito a destra
        inserito = 1;
    }
    return inserito;
}

// Inserimento di c in testa (posizione 0):
// Fa lo shift a destra di tutti i caratteri ('\0' incluso) e mette c in s[0].
int inserimento_testa(char s[], char c, int dim) {
    int i, len, inserito;
    len = (int)strlen(s);
    if (len == dim - 1) {
        inserito = 0; // Vettore pieno
    } else {
        for (i = len + 1; i > 0; i--) {
            s[i] = s[i - 1]; // Shift a destra ('\0' incluso)
        }
        s[0] = c;
        inserito = 1;
    }
    return inserito;
}

// Inserimento di c in posizione generica k:
// Verifica che ci sia spazio e che 0 <= k <= len; shift a destra da k ('\0' incluso).
int inserimento_posizione(char s[], char c, int k, int dim) {
    int i, len, inserito;
    len = (int)strlen(s);
    if (len == dim - 1 || k < 0 || k > len) {
        inserito = 0; // Vettore pieno oppure k non valido (negativo o oltre '\0')
    } else {
        for (i = len + 1; i > k; i--) {
            s[i] = s[i - 1]; // Shift a destra a partire da k ('\0' incluso)
        }
        s[k] = c;
        inserito = 1;
    }
    return inserito;
}

// Cancellazione dell'ultimo carattere (in coda):
// Restituisce 1 se avvenuta, 0 se la stringa e' vuota.
int cancellazione_coda(char s[]) {
    int cancellato, len;
    len = (int)strlen(s);
    if (len == 0) {
        cancellato = 0; // Stringa vuota: niente da cancellare
    } else {
        s[len - 1] = s[len]; // Copia '\0' sopra l'ultimo carattere significativo
        cancellato = 1;
    }
    return cancellato;
}

// Cancellazione del primo carattere (in testa):
// Fa lo shift a sinistra di tutti i caratteri ('\0' incluso).
int cancellazione_testa(char s[]) {
    int i, cancellato, len;
    len = (int)strlen(s);
    if (len == 0) {
        cancellato = 0; // Stringa vuota
    } else {
        for (i = 0; i < len; i++) {
            s[i] = s[i + 1]; // Shift a sinistra ('\0' incluso quando i == len - 1)
        }
        cancellato = 1;
    }
    return cancellato;
}

// Cancellazione del carattere in posizione generica k:
// Verifica che la stringa non sia vuota e che 0 <= k <= len-1; shift a sinistra da k.
int cancellazione_posizione(char s[], int k) {
    int i, cancellato, len;
    len = (int)strlen(s);
    if (len == 0 || k < 0 || k > len - 1) {
        cancellato = 0; // Stringa vuota o k fuori intervallo
    } else {
        for (i = k; i < len; i++) {
            s[i] = s[i + 1]; // Shift a sinistra a partire da k ('\0' incluso)
        }
        cancellato = 1;
    }
    return cancellato;
}

// Cancellazione di TUTTE le occorrenze del carattere c nella stringa s:
// Quando trova c in posizione i, fa lo shift a sinistra senza incrementare i
// (cosi' ricontrolla subito il nuovo carattere scivolato in posizione i).
void cancellazione_carattere(char s[], char c) {
    int i, j;
    i = 0;
    while (s[i] != '\0') {
        if (s[i] == c) {
            for (j = i; s[j] != '\0'; j++) {
                s[j] = s[j + 1]; // Shift a sinistra ('\0' incluso)
            }
        } else {
            i++; // Avanza solo se non c'e' stata cancellazione
        }
    }
}

// Funzione di utilita' per svuotare il buffer della tastiera fino al '\n'
// (evita che un Invio residuo faccia saltare la chiamata successiva a fgets)
void pulisci_buffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        // Scarta i caratteri residui
    }
}