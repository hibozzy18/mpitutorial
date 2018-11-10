#include<mpi.h>
#include<stdio.h>


int main(int argc, char  *argv[])
{
    //initialize
    MPI_Init(&argc, &argv);
    
    //initialize and get the size get call the process requested 
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);


    //assign rank returns rank of each process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD,&world_rank);


    //MPI_Get_processor_name(char *name,int * name_length);obtains the actual nameof the process
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len; 
    MPI_Get_processor_name(processor_name, &name_len);

    printf("Hello world from %s and my rank is %d  out of length %d\n",processor_name, world_rank,world_size );
    
    MPI_Finalize();
    return 0;
}
