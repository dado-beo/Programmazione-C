#include <stdio.h>
#include <math.h>

int main(void) {
    float a, b, c;
    float delta, x1, x2;

    printf("Inserisci i coefficienti a, b e c dell'equazione quadratica ax^2 + bx + c = 0: ");
    scanf("%f %f %f", &a, &b, &c);

    delta = b * b - 4 * a * c;

    if(delta < 0) {
        printf("Nessuna soluzione reale.\n");
    } else if(delta == 0) {
        x1 = -b / (2 * a);
        printf("Una soluzione reale: x = %f\n", x1);
    } else {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        printf("Due soluzioni reali: x1 = %f, x2 = %f\n", x1, x2);
    }
    return 0;
}