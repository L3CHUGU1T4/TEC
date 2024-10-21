#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv){
    int size, rank;
    MPI_Init(&argc, &argv);  // Usar 'argc' en lugar de 'arg'
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    printf("Hola mundo (size=%i, rank=%i)\n", size, rank);  // Añadir coma y nueva línea
    MPI_Finalize();
    return 0;
}
