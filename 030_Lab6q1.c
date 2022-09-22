#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
/*64050030 KITIPUM NORNUA*/
int csum, msum;
void *calculateCsum(void *param);

int main(int argc, char *argv[]){	/*2.1*/
	pthread_t	tid;
	pthread_attr_t	attr;
	pthread_attr_init(&attr);

	pthread_create(&tid, &attr, calculateCsum, argv[1]);

	pthread_join(tid, NULL);

	int i;
	msum = 0;
	for(i = 1; i <= atoi(argv[1]); i++){ /*2.3*/
		msum += i;
	}
	//printf("The mother sum is %d\n",msum);

	int output = csum - msum;
	printf("The difference is %d , The child is %d , The parent is %d\n",output, csum, msum); /*2.4*/
       	return 0;	
}

void *calculateCsum(void *param){ /*2.2*/
	int i;
	csum = 0;
	for(i = 1; i <= 2*(atoi(param)); i++){
		csum += i;
	}
	//printf("Thr child sum is %d\n",csum);
	pthread_exit(0);
}
