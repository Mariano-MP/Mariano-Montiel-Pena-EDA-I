#include <stdio.h>
int main(void) {
    int x = 7;        // Creo un variable x con valor 7
    int *p = &x;      // Creo un puntero p que guarda la dirección de x
    int y = *p + 3;   // y vale lo que apunta p (7) más 3 -> y = 10

    printf("1) x = %d\n", x);       // Imprime x
    printf("2) *p = %d\n", *p);     // Imprime el valor de x usando el puntero
    printf("3) p = %p\n", (void*)p);// Imprime la diección guardada en p
    printf("4) &x = %p\n", (void*)&x); // Imprime la dirección de x (igual que p)
    printf("5) y = %d\n", y);       // Imprime y (10)

    *p = 42;   // Cambio el valor de x usado el puntero

    printf("6) x = %d, *p = %d\n", x, *p); // Imprime x y *p (los dos son 42)
    return 0;
}
