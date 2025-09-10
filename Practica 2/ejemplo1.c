int main() {
    int x = 5; // una variable normal
    int *p; // un apuntador a entero

    p = &x; // p guarda la dirección de x

    printf("x vale: %d\n", x); // imprime 5
    printf("Direccion de x: %p\n", &x);
    printf("p apunta a: %p\n", p);
    printf("Valor al que apunta p: %d\n", *p); // imprime 5

    *p = 20; // ¿Qué hace?

    printf("Nuevo valor de x: %d\n", x); // ¿Qué imprime?
    return 0;
}