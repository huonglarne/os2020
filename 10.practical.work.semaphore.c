#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#include<stdio.h>

sem_t mutex;
int i = 20;

void *print_prime(void *vargp){
	sleep(1);
	int is_prime;
	for (int t = 2; t<=i; t++){
		
		is_prime = 1;
		for (int j = 2; j<t/2; j++){
			if (t%j==0){
				is_prime = 0;
				break;
			}
		}
		sem_wait(&mutex);
		if (is_prime==1) printf("prime %d ", t);
		sem_post(&mutex);
	}
}

int fibo(int n){
	if ((n==0) || (n==1)) return 1;
	else return fibo(n-1) + fibo(n-2);
}

void *print_fibo(void *vargp){
	int t = 0;
	int n = 0;
	while (t <= i) {
		t = fibo(n);
		sem_wait(&mutex);
		if (t<=i) printf ("fibo %d ", t);
		sem_post(&mutex);
		n++;
	}
}
	

int main(){
	sem_init(&mutex, 0, 1);

	pthread_t thread_id1;
	pthread_create(&thread_id1, NULL, print_prime, NULL);
	pthread_join(thread_id1, NULL);

	pthread_t thread_id2;
	pthread_create(&thread_id2, NULL, print_fibo, NULL);
	pthread_join(thread_id2, NULL);

	sem_destroy(&mutex);
	
	return 0;
}
