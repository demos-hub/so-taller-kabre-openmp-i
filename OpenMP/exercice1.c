#include <stdio.h>
#include <omp.h>

long fibonacci(long numero){
    if(numero == 1 || numero == 2){
        return 1;
    }else{
        return fibonacci(numero - 1) + fibonacci(numero - 2);
    }
}

int main(){
    long numero;
    printf("Ingresar un numero (mayor a 2): ");
    scanf("%ld", &numero);

    /*
        Implemetar el API de openMP para realizar 
        * asignar un numero de hilos por medio de las rutinas
        * fibonacci a n-1 y n-2 en hilos separados (sin alterar la definicion de la funcion)
        * imprimir el subresultado del hilo y el numero de hilo que lo realizo
        * imprimir el resultado con el tiempo que tomó su ejecución.
    */


    printf("El numero %ld de la sucesion de Fibonacci es %ld\n", numero, fibonacci(numero));
    return 0;
}