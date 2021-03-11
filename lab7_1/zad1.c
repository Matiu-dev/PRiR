#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "mpi.h"
#define REZERWA 500
#define SCHRONISKO 1
#define KARM 2
#define ZABAWA 3
#define KONIEC_ZABAWY 4
#define KATASTROFA 5
#define JEDZ 5000
int jedzenie = 5000;
int PUKAJ=1, NIE_PUKAJ=0;
int liczba_procesow;
int nr_procesu;
int ilosc_kotow;
int ilosc_miejsc=4;
int ilosc_zajetych_miejsc=0;
int tag=1;
int wyslij[2];
int odbierz[2];
MPI_Status mpi_status;



void Wyslij(int nr_kota, int stan) //wyslij do lotniska swoj stan
{
wyslij[0]=nr_kota;
wyslij[1]=stan;
MPI_Send(&wyslij, 2, MPI_INT, 0, tag, MPI_COMM_WORLD);
sleep(1);
}



void Schronisko(int liczba_procesow){
int nr_kota,status;
ilosc_kotow = liczba_procesow - 1;
printf("Halo, Witam serdecznie, tu wlasciciel schroniska \n");
if(rand()%2==1){
printf("Mamy piekna pogode sprzyjajaca zabawie\n");
}
else{
printf("Niestety pogoda nie sprzyja zabawie\n");
}
printf("Zyczymy Panstwu, przyjemnej zabawy \n \n \n");
printf("Dysponujemy %d miejscami\n", ilosc_miejsc);
sleep(2);
while(ilosc_miejsc<=ilosc_kotow){
MPI_Recv(&odbierz,2,MPI_INT,MPI_ANY_SOURCE,tag,MPI_COMM_WORLD, &mpi_status); //odbieram od kogokolwiek
nr_kota=odbierz[0];
status=odbierz[1];
if(status==1){
printf("Kot %d lezy na kocu, przynajmniej nie ucieknie\n", nr_kota);
}
if(status==2){
printf("Kot %d pozwolenie na zabawe z koca nr %d\n", nr_kota, ilosc_zajetych_miejsc);
ilosc_zajetych_miejsc--;
}
if(status==3){
printf("Kot %d BAWI SIE\n", nr_kota);
}
if(status==4){
if(ilosc_zajetych_miejsc<ilosc_miejsc){
ilosc_zajetych_miejsc++;
MPI_Send(&PUKAJ, 1, MPI_INT, nr_kota, tag, MPI_COMM_WORLD);
}
else{
MPI_Send(&NIE_PUKAJ, 1, MPI_INT, nr_kota, tag, MPI_COMM_WORLD);
}
}
if(status==5){
ilosc_kotow--;
printf("Ilosc kotow %d\n", ilosc_kotow);
}
} //zamykam while
printf("Program zakonczyl dzialanie:)\n");
}



void Kot(){
int stan,suma,i;
stan=ZABAWA; //to chyba jedyny rozsadny stan z jakiego warto startowac
while(1){
if(stan==1){
if(rand()%2==1){
stan=KARM;
jedzenie=JEDZ;
printf("Kot jest nakarmiony i gotowy do zabawy, kot %d\n",nr_procesu);
Wyslij(nr_procesu,stan);
}
else{
Wyslij(nr_procesu,stan);
}
}
else if(stan==2){
printf("Bawie sie, kot %d\n",nr_procesu);
stan=ZABAWA;
Wyslij(nr_procesu,stan);
}
else if(stan==3){
jedzenie-=rand()%500; // spalilem troche paliwa
if(jedzenie<=REZERWA){
stan=KONIEC_ZABAWY;
printf("kot puka w drzwi\n");
Wyslij(nr_procesu,stan);
}
else{
for(i=0; rand()%10000;i++);
}
}
else if(stan==4){
int temp;
MPI_Recv(&temp, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, &mpi_status);
if(temp==PUKAJ){
stan=SCHRONISKO;
printf("Kot odpoczywa, kot %d\n", nr_procesu);
}
else
{
jedzenie-=rand()%500;
if(jedzenie>0){
Wyslij(nr_procesu,stan);
}
else{
stan=KATASTROFA;
printf("kot uciekl\n");
Wyslij(nr_procesu,stan);
return;
}
}
}
}
}



int main(int argc, char *argv[])
{
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD,&nr_procesu);
MPI_Comm_size(MPI_COMM_WORLD,&liczba_procesow);
srand(time(NULL));
if(nr_procesu == 0) 
Schronisko(liczba_procesow);
else Kot();
MPI_Finalize();
return 0;
}
