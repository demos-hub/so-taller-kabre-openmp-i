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
  int numeroHilos = 5;
  double segundos = omp_get_wtime();
  omp_set_num_threads(numeroHilos);
  long respuesta = 0, numero;
  printf("Ingresar un numero (mayor a 2): ");
  scanf("%ld", &numero);

  #pragma omp parallel sections
  {
    #pragma omp section
    {
      long subrespuesta = fibonacci(numero - 2);
      printf("El hilo %d descubrio que fibonacci(%ld) = %ld\n", omp_get_thread_num(), numero - 2, subrespuesta);
      #pragma omp atomic
        respuesta += subrespuesta;
    }
    #pragma omp section
    {
      long subrespuesta = fibonacci(numero - 1);
      printf("El hilo %d descubrio que fibonacci(%ld) = %ld\n", omp_get_thread_num(), numero - 1, subrespuesta);
      #pragma omp atomic
        respuesta += subrespuesta;
    }
  }

  segundos = omp_get_wtime() - segundos;

  printf("El numero %ld de la sucesion de Fibonacci es %ld, realizado en %f segundos\n", numero, respuesta, segundos);
  return 0;
}