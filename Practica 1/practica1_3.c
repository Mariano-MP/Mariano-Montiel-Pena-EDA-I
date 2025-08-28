#include <stdio.h>

int main() {
    int n;

    printf("Ingrese el tamanio del vector: ");
    scanf("%d", &n);

    int vector[n];

    for(int i = 0; i < n; i++) {
        printf("Ingrese el elemento %d: ", i);
        scanf("%d", &vector[i]);
    }

    printf("\nVector original: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", vector[i]);
    }

    for(int i = 0; i < n/2; i++) {
        int temp = vector[i];
        vector[i] = vector[n - 1 - i];
        vector[n - 1 - i] = temp;
    }

    printf("\nVector invertido: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", vector[i]);
    }

    printf("\n");
    return 0;
}
