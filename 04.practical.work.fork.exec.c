#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(){

	int n1=fork();
	if (n1==0){
		printf("Child after 1st fork\n");

		int n2=fork();
		if (n2==0){
			printf("Child after 2nd fork\n");	
			char *args[] = {"ps", "-ef", NULL};
			execvp("ps", args);
		} else {
			char *args[] ={"free", "-h", NULL};
			execvp("free", args);
		}
	} else printf("Parent of 1st fork\n");

	printf("done\n");
	return 0;
}
	
