/*       

Name: Aman Siraj Antuley
Roll No.: 23CO25
Batch: 01
EXPERIMENT 04

Aim: Create a child process in Linux using the fork system call. From the child process obtain the process ID of both child and parent by using getpid and getppid system call.	

Theory:
In this experiment, the fork() system call is used to create a child process.
After the child process is created, the parent process waits for the child to finish using the wait() function.
The program prints the Process IDs (PID) for both the parent and the child to demonstrate process creation and the order of execution.

-The parent process prints its PID after the child process has finished.
-The child process prints its PID immediately after creation.
*/
#include<stdio.h>
#include<unistd.h>  //Import all neccessary libraries
#include<sys/wait.h>
int main()
{

    int pid;   //Declare variable for pid
    pid=fork(); //Implement fork() Command
   
    if (pid > 0) 
       {
        wait(NULL);  // Make the PArent Process to wait
        printf("\nBefore fork command:");  
        printf("\nThe Parent Process ID is : %d", getppid());  
        printf("\nParent Process exexuted successfully\n"); //Print the Parent process id after the Child
       }
    else if(pid == 0)
       {
     
        printf("\nAfter fork command");  
        printf("\nThe New Child Process Created by fork system call: %d\n", getpid()); //Print the Child Process id
       }
return 0;
}

/* 
Conclusion: This C code implements the fork() system call to create a child process, where the parent waits for the child to finish before executing its own code. 
It demonstrates process creation, differentiation, and synchronization between parent and child processes.


OUTPUT:
After fork command
The New Child Process Created by fork system call: 22407

Before fork command:
The Parent Process ID is : 22405
Parent Process exexuted successfully
*/