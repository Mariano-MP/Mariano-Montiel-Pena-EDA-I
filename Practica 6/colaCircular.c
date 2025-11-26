#include <stdio.h>
#define MAX 5   


typedef struct {
    int datos[MAX];
    int frente;  
    int final;
    int size;   
    int capacidad;     
} ColaCircular;


void inicializar(ColaCircular *c) {
    c->frente = 0;
    c->final = -1;
    c->size = 0;
    c->capacidad = MAX;
}

void enqueue(ColaCircular *c, int valor) {
    if (llena(c)) {
        printf("Cola llena, no se puede insertar %d\n", valor);
        return;
    }

    c->final = (c->final + 1) % c->capacidad;
    c->datos[c->final] = valor;
    c->size++;

    printf("+ Insertado: %d\n", valor);
}

int dequeue(ColaCircular *c) {
    if (vacia(c)) {
        printf("Cola vacía\n");
        return -1;
    }

    int valor = c->datos[c->frente];
    c->frente = (c->frente + 1) % c->capacidad;
    c->size--;

    return valor;
}

// Verificar si está vacía
int vacia(ColaCircular *c) {
    return c->size == 0;
}

// Verificar si está llena
int llena(ColaCircular *c) {
    return c->size == c->capacidad;
}

void mostrar(ColaCircular *cola) {
    if (vacia(cola)) {
        printf("Cola vacía\n");
        return;
    }

    printf("\n==========================\nEstado de la cola: ");
    int idx = cola->frente;
    printf("\nFrente: %d\n", cola->frente);
    printf("Final: %d\n", cola->final);
    for (int i = 0; i < cola->size; i++) {
        printf("%d - ", cola->datos[idx]);
        idx = (idx + 1) % cola->capacidad;
    }
    printf("\n==========================\n");
}

void peek(ColaCircular *cola) {
    if (vacia(cola)) {
        printf("Cola vacía\n");
        return;
    }
    printf("peek:    %d",cola->datos[cola->frente]);
}


int main(void) {
    ColaCircular c;
    inicializar(&c);               

    enqueue(&c, 5);
    enqueue(&c, 10);
    enqueue(&c, 15);
    mostrar(&c);
    printf("- Eliminado: %d\n", dequeue(&c));
    enqueue(&c, 20);
    enqueue(&c, 25);
    enqueue(&c, 30);
    mostrar(&c);

}