#include <stdio.h>

#define DIM 5

// Prototipi delle funzioni
void riempi_vettore(int v[]);
void calcola_medie_rispetto_x(int v[], int x, float *p1, float *p2);

int main(void) {
    int vet[DIM];
    int x;
    float media_min, media_magg_uguale;

    riempi_vettore(vet);

    printf("\nInserisci il valore x di confronto: ");
    scanf("%d", &x);

    calcola_medie_rispetto_x(vet, x, &media_min, &media_magg_uguale);

    printf("\nla media dei valori < di %d e' %.2f la media dei valori >= di %d e' %.2f\n", 
           x, media_min, x, media_magg_uguale);

    return 0;
}

void riempi_vettore(int v[]) {
    printf("Inserisci %d valori interi:\n", DIM);
    for (int i = 0; i < DIM; i++) {
        printf("v[%d] = ", i);
        scanf("%d", &v[i]);
    }
}

void calcola_medie_rispetto_x(int v[], int x, float *p1, float *p2) {
    int somma_min = 0, cont_min = 0;
    int somma_magg_uguale = 0, cont_magg_uguale = 0;

    for (int i = 0; i < DIM; i++) {
        if (v[i] < x) {
            somma_min += v[i];
            cont_min++;
        } else {
            somma_magg_uguale += v[i];
            cont_magg_uguale++;
        }
    }

    // Calcolo della media per i valori minori di x (evitando divisione per zero)
    if (cont_min > 0) {
        *p1 = (float)somma_min / cont_min;
    } else {
        *p1 = 0.0f; // Valore di default se non ci sono elementi minori di x
    }

    // Calcolo della media per i valori maggiori o uguali a x
    if (cont_magg_uguale > 0) {
        *p2 = (float)somma_magg_uguale / cont_magg_uguale;
    } else {
        *p2 = 0.0f; // Valore di default se non ci sono elementi >= x
    }
}