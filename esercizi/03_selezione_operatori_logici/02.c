#include <stdio.h>

int main(void) {
    int mese;
    printf("Inserisci il numero del mese (1-12): ");
    scanf("%d", &mese);

    switch (mese) {
        case 1:
            printf("Gennaio, giorni: 31\n");
            break;
        case 2:
            printf("Febbraio, giorni: 28\n");
            break;
        case 3:
            printf("Marzo, giorni: 31\n");
            break;
        case 4:
            printf("Aprile, giorni: 30\n");
            break;
        case 5:
            printf("Maggio, giorni: 31\n");
            break;
        case 6:
            printf("Giugno, giorni: 30\n");
            break;
        case 7:
            printf("Luglio, giorni: 31\n");
            break;
        case 8:
            printf("Agosto, giorni: 31\n");
            break;
        case 9:
            printf("Settembre, giorni: 30\n");
            break;
        case 10:
            printf("Ottobre, giorni: 31\n");
            break;
        case 11:
            printf("Novembre, giorni: 30\n");
            break;
        case 12:
            printf("Dicembre, giorni: 31\n");
            break;
        default:
            printf("Errore: numero del mese non valido.\n");
    }
    return 0;

    if(mese == 1) {
        printf("Gennaio, giorni: 31\n");
    } else if(mese == 2) {
        printf("Febbraio, giorni: 28\n");
    } else if(mese == 3) {
        printf("Marzo, giorni: 31\n");
    } else if(mese == 4) {
        printf("Aprile, giorni: 30\n");
    } else if(mese == 5) {
        printf("Maggio, giorni: 31\n");
    } else if(mese == 6) {
        printf("Giugno, giorni: 30\n");
    } else if(mese == 7) {
        printf("Luglio, giorni: 31\n");
    } else if(mese == 8) {
        printf("Agosto, giorni: 31\n");
    } else if(mese == 9) {
        printf("Settembre, giorni: 30\n");
    } else if(mese == 10) {
        printf("Ottobre, giorni: 31\n");
    } else if(mese == 11) {
        printf("Novembre, giorni: 30\n");
    } else if(mese == 12) {
        printf("Dicembre, giorni: 31\n");
    } else {
        printf("Errore: numero del mese non valido.\n");
    }
}