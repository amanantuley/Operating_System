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



#include<stdio.h> //Import the Librarires
#include<unistd.h>
int main()
{


    int pid; //Declare variable to store the pid
    pid=fork();
   
    if (pid > 0) //Check condition for Parent Class
       {
        printf("\n Before fork");  
        printf("\n The Parent Process ID is :- %d", getppid());  //Print Parent Process id (ppid)
        printf("\nParent Process exexuted successfully \n");
       }
    else if(pid == 0) //Check for child process id
       {
        printf("\n After fork");  
        printf("\n The New Child Process Created by fork system call %d \n", getpid());  //print child process id
       }
return 0;
}


/*
Conclusion: The Fork command to print the Parent and Child process id was implmented without any errors.

OUTPUT: 

    - Before fork
        The Parent Process ID is :- 20716
        Parent Process executed successfully 

    - After fork
        The New Child Process Created by fork system call 20718 

*/