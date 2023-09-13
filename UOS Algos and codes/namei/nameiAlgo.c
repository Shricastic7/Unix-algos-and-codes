#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<time.h>
#include<string.h>
int main()
{
	char path[100]="/home/ubuntu/b23/statP.c";
	int len=strlen(path);
	char working_dir[10]="/";
	struct stat statbuf; 
	int ans1=stat("/",&statbuf);
	if(ans1==0)
	{
		printf("/-----Inode Number:%li\n",statbuf.st_ino);
	}
	int i=1;
	while(i<len)
	{
		
		while(path[i]!='/' && i<len)
		{
			char c=path[i];
			strncat(working_dir,&c,1);
			i++;
		}
		printf("%s",working_dir);
		struct stat statbuf1; 
		int ans1=stat(working_dir,&statbuf1);
		if(ans1==0)
		{
			printf("-----");
			printf("Inode Number:%li\n",statbuf1.st_ino);
		}
		char c1=path[i];
		strncat(working_dir,&c1,1);
		i++;
	}
	return 0;
}

