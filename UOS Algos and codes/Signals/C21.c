#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
void DivideByZero(int signum)
{
	printf("\n\nChild : Divide By Zero Error\n\n");
	printf("\n\nChild : Terminating\n\n");
	kill(getpid(),SIGKILL);
}
void parentHandler(int signum)
{
	printf("\nParent : Child Terminated\n");
	printf("\nParent : Terminating\n\n");
}
int main()
{
	int ret = fork();
	if(ret==0)
	{
		// child
		int a,b,res; 
		signal(SIGFPE,DivideByZero);
		printf("\nEnter Num 1 : ");
		scanf("%d",&a);
		printf("\nEnter Num 2 : ");
		scanf("%d",&b);
		res=a/b;
		printf("\nResult : %d \n",res);

	}
	else
	{
		// parent
		signal(SIGCHLD,parentHandler);
		printf("\nParent : Waiting for child\n");
		pause();
	}
	return 0;
}
