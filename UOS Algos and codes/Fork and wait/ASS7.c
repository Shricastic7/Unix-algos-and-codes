#include<stdio.h>
 #include<unistd.h>
  #include<sys/wait.h>
int main() {
pid_t child_pid;
int status;

// Fork a child process
child_pid = fork();

if (child_pid == -1) {
// Forking failed
perror("fork");
return 1;
} else if (child_pid == 0) {
// Child process
printf("C) Child is having ID %d\n", getpid());
printf("D) My Parent ID is %d\n", getppid());
return 0;
} else {
// Parent process
printf("A) Parent (P) is having ID %d\n", getpid());
printf("C) ID of P's Child is %d\n", child_pid);

// Wait for child to exit
wait(&status);

printf("B) Parent process: Exiting...\n");
return 0;
}
}

