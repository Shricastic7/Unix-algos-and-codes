
#include <stdio.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
int main()
{
int fd[2],n;
char buffer[100];
pid_t p;
pipe(fd); 
p=fork();
if(p>0) 
{
printf("Parent Passing value to child\n");
char msg[30];
printf("Enter the message\n");
gets(msg);
int len = strlen(msg);
write(fd[1],msg,len); 

}
else 
{
n=read(fd[0],buffer,100); 
printf("\n read successfully by child");
write(1,buffer,n);
}
}
