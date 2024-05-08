#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main() {
    struct timeval inicio, fin;
    double tiempo;
    gettimeofday(&inicio, NULL); 

    int vector[10];
    int *ptr = vector; 
    int *ptr_final = vector + 10; 

    while (ptr < ptr_final) {
        *ptr = 10;
        ptr++;
    }

    ptr = vector; // Reiniciar el puntero al inicio del arreglo

    while (ptr < ptr_final) {
        printf("%d\n", *ptr);
        ptr++;
    }

    gettimeofday(&fin, NULL); 
    tiempo = (fin.tv_sec - inicio.tv_sec) + (fin.tv_usec - inicio.tv_usec) / 1000000.0; 
    printf("El tiempo transcurrido es: %f segundos.\n", tiempo);
    return 0;
}