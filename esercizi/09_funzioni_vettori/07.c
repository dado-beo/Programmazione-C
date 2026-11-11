#include <stdio.h>

#define DIM 5

// Prototipi delle funzioni
char chiedi_direzione(void);
void visualizza_vettore(int v[]);
void shift_circolare_sinistra(int v[]);
void shift_circolare_destra(int v[]);

int main(void) {
    // Dichiara il vettore e gli assegna dei valori di partenza
    int vet[DIM] = {11, 22, 33, 44, 55}; 
    char direzione;
    int numero_shift;

    // Chiede la direzione
    direzione = chiedi_direzione();

    // Chiede il numero di volte per cui effettuare lo shift
    printf("Inserisci il numero di shift da effettuare: ");
    scanf("%d", &numero_shift);

    // Visualizza prima dello shift
    printf("\nVettore iniziale:\n");
    visualizza_vettore(vet);

    // Esegue lo shift per il numero di volte richiesto
    for (int i = 0; i < numero_shift; i++) {
        if (direzione == 'S') {
            shift_circolare_sinistra(vet);
        } else if (direzione == 'D') {
            shift_circolare_destra(vet);
        }
    }

    // Visualizza dopo lo shift
    printf("\nVettore dopo %d shift a %s:\n", numero_shift, (direzione == 'S') ? "sinistra" : "destra");
    visualizza_vettore(vet);

    return 0;
}

char chiedi_direzione(void) {
    char d;
    
    // Ciclo per continuare a chiedere finché l'input non è corretto
    do {
        printf("Inserisci la direzione dello shift (S per sinistra, D per destra): ");
        scanf(" %c", &d); 
        
        if (d != 'S' && d != 'D') {
            printf("ERRORE: direzione sconosciuta\n");
        }
    } while (d != 'S' && d != 'D');
    
    return d;
}

void visualizza_vettore(int v[]) {
    for (int i = 0; i < DIM; i++) {
        printf("Indice %d: valore %d\n", i, v[i]);
    }
}

void shift_circolare_sinistra(int v[]) {
    // Salviamo il primo elemento prima che venga sovrascritto
    int temp = v[0]; 
    
    // Sposta ogni elemento verso sinistra
    for (int i = 0; i < DIM - 1; i++) {
        v[i] = v[i + 1];
    }
    
    // Inseriamo l'elemento salvato (il primo) in coda (all'ultimo posto)
    v[DIM - 1] = temp; 
}

void shift_circolare_destra(int v[]) {
    // Salviamo l'ultimo elemento prima che venga sovrascritto
    int temp = v[DIM - 1]; 
    
    // Sposta ogni elemento verso destra partendo dal fondo
    for (int i = DIM - 1; i > 0; i--) {
        v[i] = v[i - 1];
    }
    
    // Inseriamo l'elemento salvato (l'ultimo) in testa (al primo posto)
    v[0] = temp; 
}