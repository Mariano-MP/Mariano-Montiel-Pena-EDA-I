#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};


void insertarInicio(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    struct Nodo *nuevo = malloc(sizeof(struct Nodo));
    if (nuevo == NULL) return;

    nuevo->dato = valor;

    if (*cabeza == NULL) {
        nuevo->siguiente = NULL;
        nuevo->anterior = NULL;
        *cabeza = nuevo;
        *ultimo = nuevo;
        return;
    }

    nuevo->siguiente = *cabeza;
    nuevo->anterior = NULL;
    (*cabeza)->anterior = nuevo;
    *cabeza = nuevo;
}

void recorrerAdelante(struct Nodo *cabeza) {
    if (cabeza == NULL) return;

    struct Nodo *temp = cabeza;
    printf("Recorriendo lista hacia adelante:\n");

    do {
        if(temp->siguiente == NULL){
            printf("%d", temp->dato);
        }else{
            printf("%d -> ", temp->dato);
        }
        temp = temp->siguiente;
    } while (temp != NULL);

    printf("\n");
}


void insertarFinal(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    struct Nodo *nuevo = malloc(sizeof(struct Nodo));
    if (nuevo == NULL) return;

    nuevo->dato = valor;

    if (*cabeza == NULL) {
        nuevo->siguiente = NULL;
        nuevo->anterior = NULL;
        *cabeza = nuevo;
        *ultimo = nuevo;
        return;
    }

    nuevo->siguiente = NULL;
    nuevo->anterior = *ultimo;
    (*ultimo)->siguiente = nuevo;
    *ultimo = nuevo;
}

void recorrerAtras(struct Nodo *ultimo) {
    if (ultimo == NULL) return;

    struct Nodo *temp = ultimo;
    printf("Recorriendo lista hacia atras:\n");

    do {
        if(temp->anterior == NULL){
            printf("%d", temp->dato);
        }else{
            printf("%d -> ", temp->dato);
        }
        temp = temp->anterior;
    } while (temp != NULL);

    printf("\n");
}

void eliminar(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    if (*cabeza == NULL) {
        printf("(lista vacía)\n");
        return;
    }

    struct Nodo *actual = *cabeza;
    struct Nodo *anterior = NULL;

    do {
        if (actual->dato == valor){
            break;
        }

        anterior = actual;
        actual = actual->siguiente;

    } while (actual != NULL);

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
        (*cabeza)->anterior = NULL;
    }
    else if (actual == *ultimo) {
        *ultimo = anterior;
        (*ultimo)->siguiente = NULL;
    } 
    else {
        anterior->siguiente = actual->siguiente;
        actual->siguiente->anterior = anterior;  
    }

    free(actual);
}

void liberar(struct Nodo *cabeza) {
    printf("\n[liberar] Liberando memoria de la lista...\n");

    while (cabeza != NULL) {
        struct Nodo *tmp = cabeza;         
        cabeza = cabeza->siguiente;         
        printf("  free(%p)\n", (void*)tmp); 
        free(tmp);                     
    }

    printf("[liberar] Memoria liberada correctamente.\n");
}

int main() {
    struct Nodo *cabeza = NULL;
    struct Nodo *ultimo = NULL;
    int n, valor;

    printf("-----------------\nPaso A2. Insercion\n-----------------\n");
    printf("\n[Insercion inicio]    Cuantos numeros deseas guardar al INICIO de la lista? ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Entrada invalida.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int x;
        printf("\nValor %d/%d: ", i + 1, n);
        if (scanf("%d", &x) != 1) {
            printf("Entrada invalida.\n");
            return 1;
        }
        insertarInicio(&cabeza, &ultimo, x);
        recorrerAdelante(cabeza);
    }
    printf("\n[Insercion Final]     Cuantos numeros deseas guardar al FINAL de la lista? ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Entrada invalida.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int x;
        printf("\nValor %d/%d: ", i + 1, n);
        if (scanf("%d", &x) != 1) {
            printf("Entrada invalida.\n");
            return 1;
        }
        insertarFinal(&cabeza, &ultimo, x);
        recorrerAtras(ultimo);
    }

    printf("-----------------\nPaso A3. Recorrido en ambos sentidos\n-----------------\n");
    recorrerAdelante(cabeza);
    recorrerAtras(ultimo);

    printf("\n-----------------\nPaso A4. Eliminacion\n-----------------\n");
    printf("\nQue valor deseas eliminar?  ");
    scanf("%d", &valor);
    eliminar(&cabeza, &ultimo, valor);
    recorrerAdelante(cabeza);
    recorrerAtras(ultimo);

    printf("\nQue valor deseas eliminar?  ");
    scanf("%d", &valor);
    eliminar(&cabeza, &ultimo, valor);
    recorrerAdelante(cabeza);
    recorrerAtras(ultimo);

    printf("\nQue valor deseas eliminar?  ");
    scanf("%d", &valor);
    eliminar(&cabeza, &ultimo, valor);
    recorrerAdelante(cabeza);
    recorrerAtras(ultimo);

    printf("-----------------\nPaso A5. Liberacion de memoria\n-----------------\n");
    liberar(cabeza);

    return 0;
}