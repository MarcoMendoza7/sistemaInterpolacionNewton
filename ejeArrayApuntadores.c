//CREA UN ARREGLO ENTERO DE TAMAÑO X, EN 
//DINDE X ES INGRESADO POR TECLADO

//LLENA TODOS LOS ELEMENTOS DEL ARREGLO CON 
//DATOS INGRESADOS POR EL USUARIO

//MUESTRA LOS VALORES

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main (){
    struct timeval inicio, fin;
    double tiempo;
    gettimeofday(&inicio, NULL); 


    int c;
    puts("Ingrese el tamaño del arrgelo");
    scanf("%d", &c);
    int *arre = (int *)malloc(c* sizeof(int));

    puts("Ingrese los elementos del arreglo");
    for (int i = 0; i< c; i++){
        printf("(%d)", i + 1);
        scanf("%d", arre + i);
    }

    puts("Elementos del arreglo");
    for(int i=0; i<c; i++){
        printf("%d", *(arre + i));
    }
    printf("\n");
    free(arre);


    gettimeofday(&fin, NULL); 
    tiempo = (fin.tv_sec - inicio.tv_sec) + (fin.tv_usec - inicio.tv_usec) / 1000000.0; 
    printf("El tiempo transcurrido es: %f segundos.\n", tiempo);
    return 0;
}