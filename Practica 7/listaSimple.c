#include <stdio.h>
#include <stdlib.h>

//Definimos la estructura del nodo
struct Nodo {
    int dato;                // almacena el valor
    struct Nodo *siguiente;  // apunta al siguiente nodo (o NULL)
};

//  Crea un nodo en el heap y devuelve su puntero
//    Retorna NULL si no hay memoria
struct Nodo* crearNodo(int valor) {
    // Reservamos memoria del tamaño de un Nodo
    struct Nodo *nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        // Siempre validar malloc
        printf("[crearNodo] Error: no se pudo reservar memoria.\n");
        return NULL;
    }

    // Inicializamos campos
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    printf("[crearNodo] Creado nodo en %p con dato=%d (siguiente=NULL)\n",
           (void*)nuevo, nuevo->dato);

    return nuevo;
}

//  Inserta al INICIO de la lista y devuelve la nueva cabeza
struct Nodo* insertarInicio(struct Nodo *cabeza, int valor) {
    printf("[insertarInicio] Insertando %d al inicio...\n", valor);

    // Creamos el nodo
    struct Nodo *nuevo = crearNodo(valor);
    if (nuevo == NULL) {
        // Si falló la memoria, devolvemos la misma cabeza
        return cabeza;
    }

    // enlazamos: el nuevo apunta a la cabeza actual
    nuevo->siguiente = cabeza;

    // La nueva cabeza ahora es "nuevo"
    cabeza = nuevo;

    printf("[insertarInicio] Nueva cabeza en %p (dato=%d)\n",
           (void*)cabeza, cabeza->dato);

    return cabeza;
}

//  Recorre la lista e imprime valores y direcciones
void recorrer(struct Nodo *cabeza) {
    printf("\n[recorrer] Mostrando lista enlazada:\n");
    if (cabeza == NULL) {
        printf("(lista vacía)\n");
        return;
    }

    while (cabeza != NULL) {
        printf("%d -> ", cabeza->dato);
        cabeza = cabeza->siguiente;  // avanzamos al siguiente nodo
    }
}

//  Libera toda la memoria de la lista
void liberar(struct Nodo *cabeza) {
    printf("\n[liberar] Liberando memoria de la lista...\n");

    while (cabeza != NULL) {
        struct Nodo *tmp = cabeza;         // guardo el nodo actual
        cabeza = cabeza->siguiente;         // avanzo antes de liberar
        printf("  free(%p)\n", (void*)tmp); // mostramos qué liberamos
        free(tmp);                          // libero el nodo
    }

    printf("[liberar] Memoria liberada correctamente.\n");
}



struct Nodo* eliminar(struct Nodo *cabeza, int valor) {
    if (cabeza == NULL) {
        printf("(lista vacía)\n");
        return NULL;
    }

    struct Nodo *actual = cabeza;
    struct Nodo *anterior = NULL;

    while (actual != NULL && actual->dato != valor) {
        anterior = actual;
        actual = actual->siguiente;
    }

    // Si no lo encontramos, devolvemos la cabeza original
    if (actual == NULL) {
        printf("[eliminar] Valor %d no encontrado.\n", valor);
        return cabeza;
    }

    // Si vamos a eliminar la cabeza
    if (anterior == NULL) {
        cabeza = actual->siguiente;
    }else{
        anterior->siguiente = actual->siguiente;
    }

    printf("[eliminar] Eliminando nodo en %p con valor %d\n",
           (void*)actual, actual->dato);
    free(actual);

    return cabeza;
}

int main(void) {
    struct Nodo *cabeza = NULL; 
    int n;

    printf("-----------------\nPaso A2. Insercion\n-----------------\n");
    printf("Cuantos numeros deseas guardar en la lista? ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Entrada invalida.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int x;
        printf("\n\nValor %d/%d: ", i + 1, n);
        if (scanf("%d", &x) != 1) {
            printf("Entrada invalida.\n");
            liberar(cabeza);
            return 1;
        }
        cabeza = insertarInicio(cabeza, x);
        recorrer(cabeza);
    }

    printf("-----------------\nPaso A3. Recorrido y eliminacion\n-----------------\n");

    printf("\n\nQue valor deseas eliminar?  ");
    scanf("%d", &n);

    cabeza = eliminar(cabeza, n);

    recorrer(cabeza);


    printf("-----------------\nPaso A4. Liberacion de memoria\n-----------------\n");
    liberar(cabeza);


    return 0;
    
    
}