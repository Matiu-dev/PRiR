#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>

float mojePi(int N){
	float wynik=0;
	for(int i = 1; i <= N; i++){
		wynik+=(pow(-1,i-1))/(2*i-1);
	}
	return 4*wynik;
}

int main(){
	int N,p, i;
	printf("Podaj ilosc procesow");
	scanf("%d", &p);

	pid_t pid;

	for(i = 1; i <= p; i++){
		switch(pid = fork()){
			case -1:
				printf("Error/n");
			case 0:
				N=rand()%5000+100;
				printf("N jest rowne %d", N);
				printf("Liczba pi wynosi %f, dla procesu %d\n", mojePi(N), getpid());
			default:
				N=rand()%5000+100;
                                printf("N jest rowne %d", N);
				printf("Liczba pi wynosi %f, dla procesu %d\n", mojePi(N), getpid());
		}
	}
	return 0;
}

