#include <stdio.h>

int main() {
    int n;

    printf("Ingrese el tamanio del vector: ");
    scanf("%d", &n);

    int vector[n];
    int suma = 0;
    float promedio;
    int min, max;
    int idx_min = 0, idx_max = 0;

    for(int i = 0; i < n; i++) {
        printf("Ingrese el elemento %d: ", i);
        scanf("%d", &vector[i]);
    }

    min = max = vector[0];

    for(int i = 0; i < n; i++) {
        suma += vector[i];

        if(vector[i] < min) {
            min = vector[i];
            idx_min = i;
        }

        if(vector[i] > max) {
            max = vector[i];
            idx_max = i;
        }
    }

    promedio = (float)suma / n;

    printf("\n    -  Suma: %d", suma);
    printf("\n    -  Promedio: %.2f", promedio);
    printf("\n    -  Minimo: %d (indice %d)", min, idx_min);
    printf("\n    -  Maximo: %d (indice %d)\n", max, idx_max);

    return 0;
}
