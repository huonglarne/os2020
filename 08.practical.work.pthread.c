#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

void *print_prime(void *vargp){
	sleep(1);
	int is_prime;
	for (int i = 2; i<=20; i++){
		is_prime = 1;
		for (int j = 2; j<i/2; j++){
			if (i%j==0){
			is_prime = 0;
			break;
			}
		}
		if (is_prime==1) printf("%d ", i);
	}
}

int fibo(int n){
	if ((n==0) || (n==1)) return 1;
	else return fibo(n-1) + fibo(n-2);
}

void *print_fibo(void *vargp){
	for (int i = 2; i<20; i++){
		printf ("%d ", fibo(i));
	}
}
	

int main(){
	printf("Before thread\n");

	pthread_t thread_id1;
	pthread_create(&thread_id1, NULL, print_prime, NULL);
	pthread_join(thread_id1, NULL);

	pthread_t thread_id2;
	pthread_create(&thread_id2, NULL, print_fibo, NULL);
	pthread_join(thread_id2, NULL);
	
	return 0;
}
