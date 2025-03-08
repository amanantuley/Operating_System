/*

Name: Aman Siraj Antuley
Roll No.: 23CO25
Batch: 01
                                                        
EXPERIMENT 3
                                                        
Aim: Implement any one basic commands of linux like ls, cp, mv and others using kernel APIs

Theory:

The fork() system call in C is used to create a new process by duplicating the calling process. 
This results in two processes: 1. The parent process 2. The child process. 
The parent process is the one that calls fork(), and the child process is the new process created by it.

When fork() is executed, it returns:
    -A positive value (PID of the child) in the parent process.
    -0 in the child process.
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h> //Import neccessary Libraries
#include <errno.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    int i, fd1, fd2;
    char *file1, *file2, buf[2];
    file1 = argv[1];
    file2 = argv[2];
    printf("file1=%s file2=%s", file1, file2); //Print the content 
    fd1 = open(file1, O_RDONLY, 0777); //Give Permissions
    fd2 = creat(file2, 0777);
    while (i = read(fd1, buf, 1) > 0) //Move the Content from File 1 to File 2
        write(fd2, buf, 1);
    remove(file1);
    close(fd1); //Close the Files
    close(fd2);
}

/*
Conclusion : The fork() system call in C creates a new child process by duplicating the parent process. It returns a positive PID in the parent and 0 in the child, enabling concurrent execution of both processes.
*/