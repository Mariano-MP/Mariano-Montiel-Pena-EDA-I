#include <stdio.h>
#include <stdlib.h>

int main() {
    int numeros, nuevosNumeros;
    int *arr1, *arr2;

    printf("Cuantos numeros deseas guarda en el arreglo de malloc (arr1)? ");
    scanf("%d", &numeros);

    arr1 = (int*) malloc(numeros * sizeof(int));

    if (arr1 == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        return 1;
    }
    printf("\nNumeros reservados con malloc (arr1)\n");
    for (int i = 0; i < numeros; i++) {
        printf("Numero guardado %d: %d \n", i + 1, arr1[i]);
    }

    printf("\nCuantos numeros deseas guardar con calloc (arr2)? ");
    scanf("%d", &numeros);

    arr2 = (int *)calloc(numeros, sizeof(int));

    if (arr2 == NULL) {
        printf("Error al asignar memoria\n");
        return 1;
    }

    printf("\nNumeros reservados con calloc (arr2)\n");
    for (int i = 0; i < numeros; i++) {
        printf("Numero guardado %d: %d \n", i + 1, arr2[i]);
    }

    for (int i = 0; i < numeros; i++){
        printf("Ingrese el numero %d que desea guardar en el arreglo arr2:  ", i + 1);
        scanf("%d", &arr2[i]);
    }

    printf("\nNumeros guardados (arr2)\n");
    for (int i = 0; i < numeros; i++) {
        printf("Numero guardado %d: %d \n", i + 1, arr2[i]);
    }

    
    printf("De que tamanio desea redimensionar el arreglo (arr2):");
    scanf("%d", &nuevosNumeros);

    arr2 = (int*) realloc(arr2, (nuevosNumeros) * sizeof(int));


    if (arr2 == NULL) {
        printf("Error: no se pudo reasignar memoria.\n");
        return 1;
    }

    if (nuevosNumeros > numeros){
        for (int i = numeros; i < nuevosNumeros; i++) {
            printf("Ingrese el numero %d que desea guardar en el arreglo arr2:  ", i + 1);
            scanf("%d", &arr2[i]);
        }
    }

    for(int i = 0; i < nuevosNumeros; i++){
        printf("Numero guardado %d: %d \n", i + 1, arr2[i]);
    }

    free(arr1);
    free(arr2);

    printf("\nMemoria Liberada Correctamente :D\n");
    
    return 0;
}
