/*                                                     
Name: Aman Siraj Antuley                                                        
Roll No.: 23CO25
Batch: 01
                                                        

EXPERIMENT 04
                                                        
Aim: Create a child process in Linux using the fork system call. From the child process obtain the process ID of both child 
and parent by using getpid and getppid system call.	

Theory:

The fork() system call in C is used to create a new process by duplicating the calling process. 
This results in two processes: 1. The parent process 2. The child process. 
The parent process is the one that calls fork(), and the child process is the new process created by it.

When fork() is executed, it returns:
    -A positive value (PID of the child) in the parent process.
    -0 in the child process.
*/



#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    
 fork();       

    printf("\n \t this is main process and child process creation using fork \n \t");

 fork();
  
  
    printf("\n \t this is Child process and child process creation using fork \n \t");



    return 0;
}

/*
Conclusion: The Fork command to print the Parent and Child process id was implmented without any errors.
*/