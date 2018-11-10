#include<stdio.h>
#include<stdlib.h>
#include"mpi.h"


int main(int argc, char  *argv[])
{
    MPI_Init(&argc, &argv);

    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    int mv_fwd = (world_rank+1)%world_size;

    int message;

    //set all the processes in the recieving mode
    if( world_rank !=0)
    {
        MPI_Recv(&message, 1, MPI_INT,world_rank-1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        fprintf(stdout," I am %d I received %d message from %d \n",world_rank,message,world_rank-1);

    } 
    else
    {
        message = -1;
    }

    //set Sending mode for every1
    MPI_Send(&message, 1,MPI_INT,mv_fwd,0, MPI_COMM_WORLD);
 
    //receive from  the 0 processor
    if(world_rank ==0)
    {
        MPI_Recv(&message,1,MPI_INT,world_size-1,0, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        printf("Process %d received token %d from process %d\n", world_rank, message, world_size - 1);
    }

    MPI_Finalize();


    return 0;
}

