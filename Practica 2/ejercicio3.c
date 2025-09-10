#include <stdio.h>
int main(void) {
    int a[5] = {2, 4, 6, 8, 10};
    int *p = a; // p empieza apuntando a a[0]

    printf("1) a[1] = %d\n", a[1]);        // imprime el segundo elemento -> 4
    printf("2) *(a+3) = %d\n", *(a+3));    // imprime el cuarto elemento -> 8
    printf("3) *p++ = %d\n", *p++);        // imprime *p (2) y luego avanza p a a[1]
    printf("4) *++p = %d\n", *++p);        // primero avanza p a a[2] ya que estaba en a[1], luego imprime -> 6
    printf("5) p[1] = %d\n", p[1]);        // p está en a[2], así que p[1] es a[3] -> 8
    printf("6) *(p+=2) = %d\n", *(p+=2));  // mueve p dos posiciones más (ahora apunta a a[4]) -> imprime 10
    printf("7) p - a = %ld\n", p - a);     // resta direcciones -> cuántos pasos se movió p desde a[0], aquí 4

    return 0;
}
