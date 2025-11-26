#include <stdio.h>
#define MAX_PILA 5   // Capacidad fija de la pila
#define MAX_COLA 5   // Capacidad fija de la cola (índices válidos: 0..MAX-1)

// Definición de la estructura Cola.
// 'frente' apunta al índice del siguiente elemento a salir.
// 'final' apunta al índice del último elemento insertado.
// Convención de vacío: frente > final
typedef struct {
    int datos[MAX_COLA];
    int frente;   // índice del primer elemento válido
    int final;    // índice del último elemento válido
} Cola;

// Inicializa la cola vacía.
// Para que "vacío" sea cierto, dejamos frente=0 y final=-1 (frente > final).
void inicializarCola(Cola *c) {
    c->frente = 0;
    c->final  = -1;
}

// ENCOLAR (enqueue): inserta al FINAL de la cola.
void enqueue(Cola *c, int valor) {
    // Caso extremo: ¿está "llena" porque ya alcanzamos el final del arreglo?
    if (c->final == MAX_COLA - 1) {
        printf("La cola está llena (no recicla espacio en esta versión)\n");
    } else {
        // Avanzamos 'final' y colocamos el nuevo valor en esa posición.
        c->datos[++(c->final)] = valor;
        printf("Insertado %d en la cola (frente=%d, final=%d)\n", valor, c->frente, c->final);
    }
}

// DESENCOLAR (dequeue): saca del FRENTE de la cola.
int dequeue(Cola *c) {
    // Vacío si frente > final.
    if (c->frente > c->final) {
        printf("La cola está vacía\n");
        return -1;   // Valor centinela: no había dato
    } else {
        // Devolvemos el elemento actual en 'frente' y movemos 'frente' a la derecha.
        return c->datos[(c->frente)++];
    }
}

// Definición de la estructura Pila.
// 'datos' guarda los elementos y 'tope' marca el índice del último elemento insertado.
typedef struct {
    int datos[MAX_PILA];
    int tope;          // Cuando la pila está vacía, tope = -1
} Pila;

// Inicializa la pila dejándola vacía.
void inicializarPila(Pila *p) {
    p->tope = -1;      // Convención: -1 significa "sin elementos"
}

// Inserta un elemento en la cima (PUSH).
void push(Pila *p, int valor) {
    // Caso extremo: ¿está llena? (no hay espacio para insertar)
    if (p->tope == MAX_PILA - 1) {
        printf("La pila está llena\n");
    } else {
        // Pre-incremento: primero subimos el tope, luego escribimos en esa posición.
        p->datos[++(p->tope)] = valor;
        printf("Insertado %d en la pila (tope=%d)\n", valor, p->tope);
    }
}

// Elimina y devuelve el elemento en la cima (POP).
int pop(Pila *p) {
    // Caso extremo: ¿está vacía? (no hay qué extraer)
    if (p->tope == -1) {
        printf("La pila está vacía\n");
        return -1;     // Valor para indicar "no había dato"
    } else {
        // Devolvemos el elemento actual y luego reducimos el tope.
        return p->datos[(p->tope)--];
    }
}

int main(void) {
    Pila p;
    inicializarPila(&p);
    printf("\nPila Inicializada Vacia\n");

    int cantidad = 0, elemento;


    //PUSH
    printf("Cuantos elementos deseas apilar (MAX=5)?    ");
    scanf("%d", &cantidad);

    for(int i = 0; i < cantidad; i++){
        printf("\nIngresa el elemento %d a insertar:  ", i + 1);
        scanf("%d", &elemento);
        push(&p, elemento);
        for(int j = p.tope; j >= 0; j--){
            if(j == p.tope){
                printf("\nEstado Pila\n");
            }
            printf("%d [ %d ] (tope=%d)\n", j + 1, p.datos[j], p.tope);
        }
    }

    //POP
    printf("\n==============================\n");
    for(int j = p.tope; j >= 0; j--){
        if(j == p.tope){
            printf("\nEstado Pila\n");
        }
        printf("%d [ %d ] (tope=%d)\n", j + 1, p.datos[j], p.tope);
    }

    printf("\nCuantos elementos deseas desapilar?    ");
    scanf("%d", &cantidad);

    for(int i = 0; i < cantidad; i++){
        printf("\nElemento extraido: %d\n", pop(&p));
        for(int j = p.tope; j >= 0; j--){
            if(j == p.tope){
                printf("\nEstado Pila\n");
            }
            printf("%d [ %d ] (tope=%d)\n", j + 1, p.datos[j], p.tope);
        }
    }


    Cola c;
    inicializarCola(&c); 

    printf("==============================\nCola Inicializada Vacia\n");

    //ENCOLAR
    printf("Cuantos elementos deseas encolar (MAX=5)?    ");
    scanf("%d", &cantidad);

    for(int i = 0; i < cantidad; i++){
        printf("\nIngresa el elemento %d a insertar:  ", i + 1);
        scanf("%d", &elemento);
        enqueue(&c, elemento);
        for(int j = c.frente; j <= c.final; j++){
            if(j == c.frente){
                printf("\nEstado Cola\n");
                printf("Frente: %d\n", c.frente);
                printf("Final: %d\n", c.final);
            }
            printf("[ %d ]", c.datos[j]);
        }
    }

    //DESENCOLAR
    printf("\n==============================\n");
    for(int j = c.frente; j <= c.final; j++){
        if(j == c.frente){
            printf("\nEstado Cola\n");
            printf("Frente: %d\n", c.frente);
            printf("Final: %d\n", c.final);
        }
        printf("[ %d ]", c.datos[j]);
    }

    printf("\nCuantos elementos deseas desencolar?    ");
    scanf("%d", &cantidad);

    for(int i = 0; i < cantidad; i++){
        printf("\nElemento extraido: %d\n", dequeue(&c));
        for(int j = c.frente; j <= c.final; j++){
            if(j == c.frente){
                printf("\nEstado Cola\n");
                printf("Frente: %d\n", c.frente);
                printf("Final: %d\n", c.final);
            }
            printf("[ %d ]", c.datos[j]);
        }
    }

    printf("\n==============================\n");
    printf("Comparacion:\n");
    printf("Pila -> LIFO (Último en entrar, primero en salir)\n");
    printf("Cola -> FIFO (Primero en entrar, primero en salir)\n");


    return 0;

}