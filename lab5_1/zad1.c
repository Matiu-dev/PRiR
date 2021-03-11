#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


#define NR_PROC 5

float f(float x)
{
        return 4*x-6*x+5;
}

float mTrapezow(float a,float b,float n){
	                float h = (b-a)/n;
                float sum = f(a)/2+f(b)/2;

                printf("a to %f, b to %f, n to %f \n", a,b,n);

                for(int i = 1; i <= n-1; i++){
                        sum+=f(a+(i/n) * (b-a));
                }
        return  h*sum;

}



main(){
	//if(fork() != 0){
	//	printf("Jestem rozdziciem, moj pid = %d \n", getpid());
	//}else{
	//	printf("Ja potomek, moj pid = %d \n", getpid());
	//	printf("pid mojego potomka = %d \n", getpid());
	//}

	time_t tt;
	srand((unsigned) time(&tt));

	float a, b, n;
	float z = 5.0;

	pid_t pid;
	int i;

	for(i =1; i <= NR_PROC; i++){
		switch(pid = fork()){
			case -1:
				printf("Error in fork\n");
			case 0:
                		a = (float)rand()/(float)RAND_MAX;
                		b = (float)rand()/(float)RAND_MAX;
                		n = rand()%30;

                		while(a>b){
                         		a = (float)(rand())/(float)RAND_MAX;
                        		b = (float)(rand())/(float)RAND_MAX;
                         		n = (float)(rand()%30+1);
				}
                		printf("Wynik to %f, jestem procesem potomnym moj pid to %d\n", mTrapezow(a,b,n),getpid());

		default:
		

                a = (float)rand()/(float)RAND_MAX;
                b = (float)rand()/(float)RAND_MAX;
                n = rand()%30;

                while(a>b){
                         a = (float)(rand())/(float)RAND_MAX;
                         b = (float)(rand())/(float)RAND_MAX;
                         n = (float)(rand()%30+1);
		}
 		printf("Wynik to %f, jestem procesem macierzystym a moj pid to%d\n",mTrapezow(a,b,n),getpid());
 
		}		
	}
}
