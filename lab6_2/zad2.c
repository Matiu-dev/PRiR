#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"
#include <math.h>

float f(float x){
return pow(x,2);
}

int main(int argc, char **argv){

int p;
int n = 1;
int tag = 50;

int N=1;
float wynikPi = 0;

MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &p);
MPI_Comm_size(MPI_COMM_WORLD, &n);
MPI_Status status;

//m trapezow
float a = 0.1;
float b = 1.1;
//float h = (b-a)/(n-2);
//float sum = f(a)/2+f(b)/2;
float h;
float sum;

if(p==0){
h = (b-a)/(n-2);
sum = f(a)/2+f(b)/2;

MPI_Send(&N, 1, MPI_INT, p+1, tag, MPI_COMM_WORLD);
MPI_Send(&wynikPi, 1, MPI_INT, p+1, tag, MPI_COMM_WORLD);
MPI_Send(&sum, 1, MPI_INT, p+1, tag, MPI_COMM_WORLD);
MPI_Send(&h, 1, MPI_INT, p+1, tag, MPI_COMM_WORLD);

}

if((p>0)&&(p<n-1)){

MPI_Recv(&N,1, MPI_INT, p-1, tag, MPI_COMM_WORLD, &status);
MPI_Recv(&wynikPi,1, MPI_INT, p-1, tag, MPI_COMM_WORLD, &status);
MPI_Recv(&sum, 1, MPI_INT, p-1, tag, MPI_COMM_WORLD, &status);
MPI_Recv(&h, 1, MPI_INT, p-1, tag, MPI_COMM_WORLD, &status);

N+=1;
wynikPi+=(pow(-1, p-1))/(2*p-1);

//printf("h wynosi: %f, suma startowa wynosi %f\n", h, sum);

if(p <=n-3){
sum+=f(a+(p/(n-2.0)) * (b-a));
printf("Aktualny wynik dla trapazow dla procesu  %d wynosi %f\n\n", p, sum);
}else{
printf("Ostateczny wynik dla trapazow dla procesu %d wynosi %f\n\n", p, sum);

}
//printf("suma wewnatrz tej funkcji wynosi %f + ( %d / ( %d - 2 ) ) * ( %f - %f )\n", a,p,n,b,a);
//printf("wartosc sumy tutaj wynosi %f + %f i w sumie to wynosi %f \n", a,(p/(n-2.0))*(b-a), a+(p/(n-2)) * (b-a));
//printf("Aktualny wynik dla trapazow o ilosci %d wynosi %f\n\n", p, sum);
//printf("przyblizenie o wartosci %d wynosi %f\n",p, wynikPi*4);
if(p!=n-1){
MPI_Send(&N, 1, MPI_INT, p+1, tag, MPI_COMM_WORLD);
MPI_Send(&wynikPi, 1, MPI_INT, p+1, tag, MPI_COMM_WORLD);
MPI_Send(&sum, 1, MPI_INT, p+1, tag, MPI_COMM_WORLD);
MPI_Send(&h, 1, MPI_INT, p+1, tag, MPI_COMM_WORLD);

}
}

MPI_Finalize();
return 0;

}
