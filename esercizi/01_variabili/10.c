#include <stdio.h>

int main() {
    int a;
    float b;
    char c;

    printf("La quantità di memoria occupata da un int è: %lu byte\n", sizeof(a));
    printf("La quantità di memoria occupata da un float è: %lu byte\n", sizeof(b));
    printf("La quantità di memoria occupata da un char è: %lu byte\n", sizeof(c));
    
    return 0;
}