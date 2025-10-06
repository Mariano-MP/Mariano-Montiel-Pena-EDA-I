#include <stdio.h>
#include <stdlib.h>

int main() {
    int registroActivo = 1;
    int numeroEstudiantes, numeroEstudiantesNuevos;
    float *calificaciones;
    float total;

    // Ingreso de los primeros estudiantes
    printf("¿Cuantos estudiantes deseas agregar? ");
    scanf("%d", &numeroEstudiantes);

    // Se reserva memoria para la primera cantidad de estudiantes
    calificaciones = (float*) malloc(numeroEstudiantes * sizeof(float));

    // Verifica que si se haya reservado la memoria
    if (calificaciones == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        return 1;
    }

    // Se captura la calificacion de cada estudiante
    for (int i = 0; i < numeroEstudiantes; i++) {
        printf("Calificacion del estudiante %d: ", i + 1);
        scanf("%f", &calificaciones[i]);
    }

    do {
        total = 0;
        // Se imprime cada calificacion y el promedio del grupo
        printf("\n--- Calificaciones ---\n");
        for (int i = 0; i < numeroEstudiantes; i++) {
            printf("Estudiante %d: %.2f\n", i + 1, calificaciones[i]);
            total += calificaciones[i];
        }
        printf("\n\tPromedio: %.2f\n", total / numeroEstudiantes);
        
        // Se pregunta si se desean agregar nuevos estudiantes
        printf("\n¿Deseas agregar mas estudiantes?\n");
        printf("Presiona 1 para SI o cualquier otro numero para NO: ");
        scanf("%d", &registroActivo);

        if (registroActivo == 1) {
            // De nueva cuenta se pregunta cuantos estudiantes se desean agregar 
            printf("¿Cuantos estudiantes deseas agregar? ");
            scanf("%d", &numeroEstudiantesNuevos);

            // En este apartado se reasigna la cantidad de memoria con la nueva cantidad de estudiantes
            calificaciones = (float*) realloc(calificaciones, (numeroEstudiantes + numeroEstudiantesNuevos) * sizeof(float));
                
            // Verifica que si se haya reservado la memoria
            if (calificaciones == NULL) {
                printf("Error: no se pudo reasignar memoria.\n");
                return 1;
            }

            // Se captura la calificacion solo de los nuevos estudiantes
            for (int i = numeroEstudiantes; i < numeroEstudiantes + numeroEstudiantesNuevos; i++) {
                printf("Calificacion del estudiante %d: ", i + 1);
                scanf("%f", &calificaciones[i]);
            }

            numeroEstudiantes += numeroEstudiantesNuevos;
        }

    } while (registroActivo == 1);

    // Se libera la memoria
    free(calificaciones);

    printf("\nMemoria liberada. Programa finalizado.\n");

    return 0;
}
