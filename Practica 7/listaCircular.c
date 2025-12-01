#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *siguiente;
};


// Insertar al inicio en lista circular
void insertarInicio(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    struct Nodo *nuevo = malloc(sizeof(struct Nodo));
    if (nuevo == NULL) return;

    nuevo->dato = valor;

    if (*cabeza == NULL) {
        // Primer nodo, apunta a sí mismo
        nuevo->siguiente = nuevo;
        *cabeza = nuevo;
        *ultimo = nuevo;
        return;
    }

    nuevo->siguiente = *cabeza;
    (*ultimo)->siguiente = nuevo;
    *cabeza = nuevo;
}

// Recorrer la lista circular
void recorrer(struct Nodo *cabeza) {
    if (cabeza == NULL) return;

    struct Nodo *temp = cabeza;
    printf("Recorriendo lista circular:\n");

    do {
        printf("%d -> ", temp->dato);
        temp = temp->siguiente;
    } while (temp != cabeza);

    printf("\n");
}

void eliminar(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    if (*cabeza == NULL) {
        printf("(lista vacía)\n");
        return;
    }

    struct Nodo *actual = *cabeza;
    struct Nodo *anterior = *ultimo;

    do {
        if (actual->dato == valor){
            break;
        }

        anterior = actual;
        actual = actual->siguiente;

    } while (actual != *cabeza);

    if (actual->dato != valor) {
        printf("[eliminar] No existe el valor.\n");
        return;
    }

    if (actual == *cabeza && actual == *ultimo) {
        *cabeza = NULL;
        *ultimo = NULL;
        free(actual);
        return;
    }

    if (actual == *cabeza) {
        *cabeza = actual->siguiente;
        (*ultimo)->siguiente = *cabeza;
    }
    else if (actual == *ultimo) {
        *ultimo = anterior;
        (*ultimo)->siguiente = *cabeza;
    } 
    else {
        anterior->siguiente = actual->siguiente;
    }

    free(actual);
}

int main() {
    struct Nodo *cabeza = NULL;
    struct Nodo *ultimo = NULL;
    int n, valor;

    printf("-----------------\nPaso B2. Insercion circular\n-----------------\n");
    printf("Cuantos numeros deseas guardar en la lista? ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Entrada invalida.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int x;
        printf("\nValor %d/%d: ", i + 1, n);
        if (scanf("%d", &x) != 1) {
            printf("Entrada invalida.\n");
            //liberar(cabeza);
            return 1;
        }
        insertarInicio(&cabeza, &ultimo, x);
        recorrer(cabeza);
    }
    printf("-----------------\nPaso B3. Recorrido circular\n-----------------\n");
    recorrer(cabeza);

    printf("-----------------\nPaso B4. Eliminación\n-----------------\n");
    printf("\nQue valor deseas eliminar?  ");
    scanf("%d", &valor);
    eliminar(&cabeza, &ultimo, valor);
    recorrer(cabeza);



    return 0;
}