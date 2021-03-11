#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"
#include <math.h>

int main(int argc, char **argv){

int p;
int n = 1;
int tag = 50;

int N=1;
float wynikPi = 0;

MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &p);
MPI_Comm_rank(MPI_COMM_WORLD, &n);
MPI_STATUS status;

if(p==0){
MPI_Send(&N, 1, MPI_INT, p+1, tag, MPI_COMM_WORLD);
MPI_Send(&wynikPi, 1, MPI_INT, p+1, tag, MPI_COMM_WORLD);
}

if((p>0)&&(p<n-1)){

MPI_Recv(&N,1, MPI_INT, p-1, tag, MPI_COMM_WORLD, &status);
MPI_Recv(&wynikPi,1, MPI_INT, p-1, tag, MPI_COMM_WORLD, &status);
N+=1;
wynikPi+=(pow(-1, p-1))/(2*p-1);

printf("przyblizenie o wartosci %d wynosi %f\n",p, wynikPi*4);
if(p!=n-1){
MPI_Send(&N, 1, MPI_INT, p+1, tag, MPI_COMM_WORLD);
MPI_Send(&wynikPi, 1, MPI_INT, p+1, tag, MPI_COMM_WORLD);
}
}

MPI_Finalize();
return 0;

}