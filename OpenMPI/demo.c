#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define FLAG 7

// Main routine
int main (int argc, char *argv[]){
	int rank, size;
	int number = 0, i;
	double start_time, end_time;

	// initialize MPI
	MPI_Init(&argc, &argv);	
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);	
	MPI_Comm_size(MPI_COMM_WORLD, &size);	

	// sending and receiving a message
    for (i = 0; i < 1000; i++) {
        if(rank == 0){
            start_time = MPI_Wtime();

            MPI_Send (&number , 1 , MPI_INT , 1 , 0 ,MPI_COMM_WORLD ) ;

            MPI_Recv (& number , 1 , MPI_INT , 1 , 0 ,MPI_COMM_WORLD , MPI_STATUS_IGNORE ) ;
            
            end_time = MPI_Wtime();
            printf("Elapsed time: %f seconds\n",end_time-start_time);
        } else {

            MPI_Recv (&number , 1 , MPI_INT , 0 , 0 ,MPI_COMM_WORLD , MPI_STATUS_IGNORE ) ;
            number++;
            MPI_Send (& number , 1 , MPI_INT , 0 , 0 ,MPI_COMM_WORLD ) ;

        }
    }
	// finalize MPI
	MPI_Finalize();
    printf("Number: %d\n", number);
	return 0;
}
