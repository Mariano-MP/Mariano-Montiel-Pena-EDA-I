#include <stdio.h>
#include <string.h>

#define NUM_DIR 3   // Máximo número de directores por película

// --- 1) Definición de la estructura ---
struct pelicula {
    char nombre[50];
    char genero[30];
    int  anio;
    int  numDirectores;
    char directores[NUM_DIR][50];
};

// --- Función para mostrar una película ---
void mostrarPelicula(struct pelicula p) {
    printf("Pelicula: %s\n", p.nombre);
    printf("Genero: %s\n", p.genero);
    printf("Anio: %d\n", p.anio);
    printf("Directores (%d):\n", p.numDirectores);
    for (int j = 0; j < p.numDirectores; j++) {
        printf("  - %s\n", p.directores[j]);
    }
    printf("\n");
}

int main() {
    int tam = 0;
    printf("Cuantas peliculas deseas registrar: ");
    scanf("%d", &tam);

    // --- 2) Declaración de la videoteca ---
    struct pelicula videoteca[tam];

    // Validación simple de cantidad de películas
    if (tam <= 0) {
        printf("ERROR: la videoteca debe tener al menos 1 pelicula.\n");
        return 1;
    }

    // --- 3) Captura de datos por teclado ---
    for (int i = 0; i < tam; i++) {
        printf("\n---- Captura de Pelicula %d ----\n", i + 1);

        printf("Nombre: ");
        scanf(" %[^\n]", videoteca[i].nombre); 

        printf("Genero: ");
        scanf(" %[^\n]", videoteca[i].genero);

        printf("Anio: ");
        scanf("%d", &videoteca[i].anio);

        printf("Numero de directores (1-%d): ", NUM_DIR);
        scanf("%d", &videoteca[i].numDirectores);

        // Validación simple de directores
        if (videoteca[i].numDirectores <= 0) {
            printf("ERROR: El numero de directores no puede ser 0 o negativo.\n");
            return 1;
        }

        for (int j = 0; j < videoteca[i].numDirectores; j++) {
            printf("Nombre del director %d: ", j + 1);
            scanf(" %[^\n]", videoteca[i].directores[j]);
        }
    }

    // --- 4) Imprimir en orden inverso ---
    printf("\n##### VIDEOTECA (orden inverso) #####\n");
    for (int i = tam - 1; i >= 0; i--) {
        mostrarPelicula(videoteca[i]);
    }
    int menuActivo = 1;

    // --- Implementación de búsqueda ---
    while(menuActivo == 1){
        int opcion;
        int busqueda = 0;
        printf("\nBuscar pelicula por:\n1) Nombre\n2) Anio\n3) Director\n4) Salir\nOpcion: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            char nombreBuscado[50];
            printf("Ingresa el nombre: ");
            scanf(" %[^\n]", nombreBuscado);

            for (int i = 0; i < tam; i++) {
                if (strcmp(videoteca[i].nombre, nombreBuscado) == 0) {
                    printf("\nPelicula encontrada:\n");
                    mostrarPelicula(videoteca[i]);
                    busqueda = 1;
                }
            }
        } else if (opcion == 2) {
            int anioBuscado;
            printf("Ingresa el anio: ");
            scanf("%d", &anioBuscado);

            for (int i = 0; i < tam; i++) {
                if (videoteca[i].anio == anioBuscado) {
                    printf("\nPelicula encontrada:\n");
                    mostrarPelicula(videoteca[i]);
                    busqueda = 1;
                }
            }
        } else if (opcion == 3) {
            char directorBuscado[50];
            printf("Ingresa el nombre del director: ");
            scanf(" %[^\n]", directorBuscado);

            for (int i = 0; i < tam; i++) {
                for (int j = 0; j < videoteca[i].numDirectores; j++) {
                    if (strcmp(videoteca[i].directores[j], directorBuscado) == 0) {
                        printf("\nPelicula encontrada:\n");
                        mostrarPelicula(videoteca[i]);
                        busqueda = 1;
                    }
                }
            }
        } else if(opcion == 4){
            menuActivo = 0;
            busqueda = 1;
        }
        if(busqueda == 0){
            printf("\n ----> Pelicula NO encontrada\n");
        }
    }


    // --- Contador por género ---
    char generoBuscado[30];
    int contador = 0;
    printf("\nIngresa un genero para contar cuantas peliculas hay: ");
    scanf(" %[^\n]", generoBuscado);

    for (int i = 0; i < tam; i++) {
        if (strcmp(videoteca[i].genero, generoBuscado) == 0) {
            contador++;
        }
    }

    printf("Hay %d pelicula(s) del genero %s\n", contador, generoBuscado);


    return 0;
}
