#include <stdio.h>
int main() {
    int a[3] = {10,20,30}; // Arreglo de 3 elementod
    int *p = a;            // Puntero que apunta al primer elemento del arreglo

    for(int i=0; i<3; i++){
        printf("%d", *(p+i)); // Imprime a[0], a[1], a[2] -> 10 20 30
    }
    printf("\n");

    for(int i=0; i<3; i++){
        printf("%d", *p); // Imprime el valor al que apunta p
        p++;              // Avanza el puntero al siguiente elemento
    }
}
