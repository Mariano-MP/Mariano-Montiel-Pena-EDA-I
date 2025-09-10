#include <stdio.h>
int main(void) {
    int numeros[4] = {5, 10, 15, 20}; // Arreglo con 4 enteros
    int *p = numeros;                 // Puntero que apunta al primer elemento del arreglo

    printf("1) numeros[2] = %d\n", numeros[2]); // Imprime el tercer elemento del arreglo (15)
    printf("2) *(p+2) = %d\n", *(p+2));         // Hace lo mismo per usando el puntero (15)
    printf("3) *p = %d\n", *p);                 // Imprime el valor al que apunta p, o sea numeros[0] = 5

    p++; // Ahora el puntero apunta al siguiente elemento (numeros[1])

    printf("4) *p = %d\n", *p); // Imprime el nuevo vaolr al que apunta p -> 10
    return 0;
}
