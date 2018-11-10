#include<stdlib.h>
#include<stdio.h>
#include <mpi.h>

int main(int argc, char  *argv[])
{
     int world_size, world_rank;
     int rec, sent;
    
    //init
    MPI_Init(&argc,&argv);

    // get size
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    //get rank
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    fprintf(stdout,"I am flexing my muscles at %d of %d \n", world_rank,world_size);

    //MPI_Send(void *data, int count, MPI_Datatype datatype, int destination, int tag, MPI_Comm communicator)
    if( world_rank == 1)
    {   
        rec = 5;
        MPI_Send(&rec,1, MPI_INT, 0, 10,MPI_COMM_WORLD);
    }
    else
    {
        //MPI_Recv(void *data,int count, MPI_Datatype datatype,int source,int tag,MPI_Comm communicator,MPI_Status *status)
        MPI_Recv(&rec, 1, MPI_INT, 1, 10, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        fprintf(stdout,"I have received %d \n ", rec);

    }

        MPI_Finalize();

    return 0;
}
