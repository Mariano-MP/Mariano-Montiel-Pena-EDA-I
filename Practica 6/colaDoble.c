#include <stdio.h>

#define MAX 5   // capacidad de la deque


typedef struct {
    int datos[MAX];
    int front;   
    int size;      
} Deque;

int obtenerRear(Deque *dq) {
    return (dq->front + dq->size - 1) % MAX;
}


void inicializar(Deque *dq) {
    dq->front = 0;
    dq->size = 0;
}

int estaVacia(Deque *dq) {
    return dq->size == 0;
}

int estaLlena(Deque *dq) {
    return dq->size == MAX;
}


void insert_front(Deque *dq, int valor) {
    if (estaLlena(dq)) {
        printf("Deque llena, no se puede insertar %d\n", valor);
        return;
    }

    dq->front = (dq->front - 1 + MAX) % MAX;
    dq->datos[dq->front] = valor;
    dq->size++;

    printf("insert_front(%d)\n", valor);
}

void insert_rear(Deque *dq, int valor) {
    if (estaLlena(dq)) {
        printf("Deque llena, no se puede insertar %d\n", valor);
        return;
    }

    int rear = (dq->front + dq->size) % MAX;
    dq->datos[rear] = valor;
    dq->size++;

    printf("insert_rear(%d)\n", valor);
}


int delete_front(Deque *dq) {
    if (estaVacia(dq)) {
        printf("Deque vacía\n");
        return -1;
    }

    int valor = dq->datos[dq->front];
    dq->front = (dq->front + 1) % MAX;
    dq->size--;

    printf("delete_front() : %d\n", valor);
    return valor;
}

int delete_rear(Deque *dq) {
    if (estaVacia(dq)) {
        printf("Deque vacía\n");
        return -1;
    }

    int rear = obtenerRear(dq);
    int valor = dq->datos[rear];
    dq->size--;

    printf("delete_rear() : %d\n", valor);
    return valor;
}


int peek_front(Deque *dq) {
    if (estaVacia(dq)) return -1;
    return dq->datos[dq->front];
}

int peek_rear(Deque *dq) {
    if (estaVacia(dq)) return -1;
    return dq->datos[obtenerRear(dq)];
}


void printDeque(Deque *dq) {
    printf("--------------------------------------\n");
    printf("Deque = [ ");
    for (int i = 0; i < dq->size; i++) {
        int idx = (dq->front + i) % MAX;
        printf("%d ", dq->datos[idx]);
    }
    printf("]\n");

    if (!estaVacia(dq)) {
        printf("front = %d (valor %d)\n", dq->front, dq->datos[dq->front]);
        printf("rear  = %d (valor %d)\n", obtenerRear(dq), dq->datos[obtenerRear(dq)]);
    }
    printf("--------------------------------------\n");
}


int main() {
    Deque dq;
    inicializar(&dq);

    insert_front(&dq,10);
    insert_rear(&dq,15);
    insert_rear(&dq,20);
    insert_front(&dq,30);
    insert_rear(&dq,40);

    printDeque(&dq);

    delete_front(&dq);
    delete_rear(&dq);

    printDeque(&dq);

    insert_rear(&dq,50);
    insert_front(&dq,60);

    printDeque(&dq);

    return 0;
}
