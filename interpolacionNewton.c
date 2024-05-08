#include <stdio.h>

float diferenciasDivididas(float x[], float y[], int n, int i, int j) {
    if (j == 0)
        return y[i];
    else
        return (diferenciasDivididas(x, y, n, i + 1, j - 1) - diferenciasDivididas(x, y, n, i, j - 1)) / (x[i + j] - x[i]);
}

float interpolacion(float x[], float y[], int n, float valor) {
    float resultado = 0; 

    for (int i = 0; i < n; i++) {
        float temp = diferenciasDivididas(x, y, n, 0, i);
        for (int j = 0; j < i; j++) {
            temp *= (valor - x[j]);
        }
        resultado += temp;
    }
    return resultado;
}

int main() {
    int n;
    puts("Ingrese el numero de puntos...");
    scanf("%d", &n);

    float x[n], y[n];
    puts("Ingrese los puntos en formato x y...");
    for (int i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i]);
    }

    float valor;
    puts("Ingrese el valor para interpolar...");
    scanf("%f", &valor);

    float resultado = interpolacion(x, y, n, valor);
    printf("El resultado de la interpolacion en %f es: %f\n", valor, resultado);

    return 0;
}