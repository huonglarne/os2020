#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(){

	int n1=fork();

	if (n1==0){

		int n2=fork();

		if (n2==0){
			
			char *args[] = {"ps", "-ef", NULL};
			execvp("ps", args);
			
		}

		char *args[] ={"free", "-h", NULL};
		execvp("free", args);

	}
	printf("done");
	return 0;
}
	
