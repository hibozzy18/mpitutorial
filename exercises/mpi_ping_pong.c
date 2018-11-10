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

    int num = 10;
    int ping_pong,ping_pong_count=0;
    while(ping_pong_count < num){
        if(world_rank == 0){
            ping_pong_count++;
            MPI_Send(&ping_pong_count, 1, MPI_INT, 1, 10, MPI_COMM_WORLD);
            fprintf(stdout," I have sent %d to %d \n",ping_pong_count, world_rank );

        }
        else
        {
            MPI_Recv(&ping_pong_count, 1, MPI_INT, 0,10, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
            fprintf(stdout, " I have received  from %d to %d\n", ping_pong_count, world_rank);
        }

    }




    MPI_Finalize();
    return 0;
}

