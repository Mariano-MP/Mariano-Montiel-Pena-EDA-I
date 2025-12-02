#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};



void recorrer(struct Nodo *cabeza) {
    if (cabeza == NULL) return;

    struct Nodo *temp = cabeza;
    printf("Recorriendo lista hacia adelante:\n");

    do {
        if(temp->siguiente == cabeza){
            printf("%d", temp->dato);
        }else{
            printf("%d -> ", temp->dato);
        }

        temp = temp->siguiente;
    } while (temp != cabeza);

    printf("\n");
}


void insertarFinal(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    struct Nodo *nuevo = malloc(sizeof(struct Nodo));
    if (nuevo == NULL) return;

    nuevo->dato = valor;

    if (*cabeza == NULL) {
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        *cabeza = nuevo;
        *ultimo = nuevo;
        return;
    }

    nuevo->siguiente = *cabeza;   
    nuevo->anterior = *ultimo;    

    (*ultimo)->siguiente = nuevo; 
    *ultimo = nuevo;              

    (*cabeza)->anterior = *ultimo;
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
        (*cabeza)->anterior = *ultimo;
        (*ultimo)->siguiente = *cabeza;
    }
    else if (actual == *ultimo) {
        *ultimo = anterior;
        (*ultimo)->siguiente = *cabeza;
        (*cabeza)->anterior = *ultimo;
    } 
    else {
        anterior->siguiente = actual->siguiente;
        actual->siguiente->anterior = anterior;  
    }

    free(actual);
}



int main() {
    struct Nodo *cabeza = NULL;
    struct Nodo *ultimo = NULL;
    int n, valor;

    printf("-----------------\nPaso B2. Insercion\n-----------------\n");
    printf("\n[Insercion]    Cuantos numeros deseas guardar en la lista? ");
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
        recorrer(cabeza);
    }
    
    printf("-----------------\nPaso B3. Recorrido\n-----------------\n");
    recorrer(cabeza);

    printf("\n-----------------\nPaso B4. Eliminacion\n-----------------\n");
    printf("\nQue valor deseas eliminar?  ");
    scanf("%d", &valor);
    eliminar(&cabeza, &ultimo, valor);
    recorrer(cabeza);

    printf("\nQue valor deseas eliminar?  ");
    scanf("%d", &valor);
    eliminar(&cabeza, &ultimo, valor);
    recorrer(cabeza);

    printf("\nQue valor deseas eliminar?  ");
    scanf("%d", &valor);
    eliminar(&cabeza, &ultimo, valor);
    recorrer(cabeza);

    return 0;
}