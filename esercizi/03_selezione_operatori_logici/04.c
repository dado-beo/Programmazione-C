#include <stdio.h>

int main(void){
    int anno;

    printf("Inserisci un anno:");
    scanf("%d", &anno);

    if(anno % 4 == 0 && (anno % 100 != 0 || anno % 400 == 0)){
        printf("L'anno %d è bisestile.\n", anno);
    } else {
        printf("L'anno %d non è bisestile.\n", anno);
    }

    return 0;
}