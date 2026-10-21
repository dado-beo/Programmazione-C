#include <stdio.h>

int main(void) {
    int n = 0;

    while (n <= 100) {
        printf("%d\t", n);
        n += 2;
    }
    return 0;
}