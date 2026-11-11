#include <stdio.h>

#define DIM 5

// Prototipi delle funzioni
char chiedi_direzione(void);
void visualizza_vettore(int v[]);
void shift_sinistra(int v[]);
void shift_destra(int v[]);

int main(void) {
    // Dichiara il vettore e gli assegna dei valori di partenza
    int vet[DIM] = {10, 20, 30, 40, 50}; 
    char direzione;

    // Chiede la direzione
    direzione = chiedi_direzione();

    // Visualizza prima dello shift
    printf("\nVettore iniziale:\n");
    visualizza_vettore(vet);

    // Esegue lo shift in base alla scelta
    if (direzione == 'S') {
        shift_sinistra(vet);
    } else if (direzione == 'D') {
        shift_destra(vet);
    }

    // Visualizza dopo lo shift
    printf("\nVettore dopo lo shift:\n");
    visualizza_vettore(vet);

    return 0;
}

char chiedi_direzione(void) {
    char d;
    
    // Ciclo do-while per continuare a chiedere finché l'input non è corretto
    do {
        printf("Inserisci la direzione dello shift (S per sinistra, D per destra): ");
        // Lo spazio prima di %c in scanf è fondamentale: ignora eventuali "invii" o spazi precedenti
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

void shift_sinistra(int v[]) {
    // Sposta ogni elemento verso sinistra (cioè all'indice precedente)
    for (int i = 0; i < DIM - 1; i++) {
        v[i] = v[i + 1];
    }
    // Essendo uno shift NON circolare, il valore che "entra" da destra è uno 0
    v[DIM - 1] = 0; 
}

void shift_destra(int v[]) {
    // Sposta ogni elemento verso destra partendo dal fondo 
    // (per non sovrascrivere i valori prima di averli copiati)
    for (int i = DIM - 1; i > 0; i--) {
        v[i] = v[i - 1];
    }
    // Essendo uno shift NON circolare, il valore che "entra" da sinistra è uno 0
    v[0] = 0; 
}