#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
char buffer[2048];
int version=1;
int copy(int old,int new)
{
	//int new,old;

	int count;
	while((count=read(old,buffer,sizeof(buffer)))>0)
		write(new,buffer,count);
}
int main(int argc,char *argv[])
{
	//int argc;
	//char *argv[];
	
	int fdold,fdnew;
	
	if(argc!=3)
	{
		printf("need two arguments for copy program\n");
		exit(0);
	}
	fdold=open(argv[1],O_RDONLY);
	if(fdold==-1)
	{
		printf("can not open file %s\n",argv[1]);
		exit(0);
	}
	fdnew=creat(argv[2],0666);
	if(fdnew==-1)
	{
		printf("can not create file %s\n",argv[1]);
		exit(0);
	}

	copy(fdold,fdnew);

	exit(0);
}


