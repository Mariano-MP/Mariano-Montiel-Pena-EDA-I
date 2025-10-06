#include <stdio.h>
#include <stdlib.h>

int main() {
    int registroActivo = 1;
    int numeroEstudiantes, numeroEstudiantesNuevos;
    float *calificaciones;
    float total;

    printf("¿Cuantos estudiantes deseas agregar? ");
    scanf("%d", &numeroEstudiantes);

    calificaciones = (float*) malloc(numeroEstudiantes * sizeof(float));
    if (calificaciones == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        return 1;
    }

    for (int i = 0; i < numeroEstudiantes; i++) {
        printf("Calificacion del estudiante %d: ", i + 1);
        scanf("%f", &calificaciones[i]);
    }

    do {
        total = 0;
        printf("\n--- Calificaciones ---\n");
        for (int i = 0; i < numeroEstudiantes; i++) {
            printf("Estudiante %d: %.2f\n", i + 1, calificaciones[i]);
            total += calificaciones[i];
        }
        printf("\n\tPromedio: %.2f\n", total / numeroEstudiantes);

        printf("\n¿Deseas agregar mas estudiantes?\n");
        printf("Presiona 1 para SI o cualquier otro numero para NO: ");
        scanf("%d", &registroActivo);

        if (registroActivo == 1) {
            printf("¿Cuantos estudiantes deseas agregar? ");
            scanf("%d", &numeroEstudiantesNuevos);

            calificaciones = (float*) realloc(calificaciones, (numeroEstudiantes + numeroEstudiantesNuevos) * sizeof(float));
            if (calificaciones == NULL) {
                printf("Error: no se pudo reasignar memoria.\n");
                return 1;
            }

            for (int i = numeroEstudiantes; i < numeroEstudiantes + numeroEstudiantesNuevos; i++) {
                printf("Calificacion del estudiante %d: ", i + 1);
                scanf("%f", &calificaciones[i]);
            }

            numeroEstudiantes += numeroEstudiantesNuevos;
        }

    } while (registroActivo == 1);

    free(calificaciones);

    printf("\nMemoria liberada. Programa finalizado.\n");

    return 0;
}
