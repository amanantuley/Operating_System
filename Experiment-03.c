/*

Name: Aman Siraj Antuley
Roll No.: 23CO25
Batch: 01
                                                        
EXPERIMENT 3
                                                        
Aim: Implement any one basic commands of linux like ls, cp, mv and others using kernel APIs

Theory:
This program implements the mv (move) command in Linux using system calls. The mv command moves a file from one location to another by copying its content to a new file and deleting the original.

Key System Calls Used:
open() – Opens the source file (file1) for reading.
creat() – Creates the destination file (file2) with permissions.
read() – Reads content from file1 in chunks.
write() – Writes content to file2.
remove() – Deletes the original file (file1), mimicking the mv command.
close() – Closes both files.

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
Conclusion : 
This program successfully simulates the mv command using low-level system calls. It moves a file by:
Copying its content to another file.
Deleting the original file (file1).

*/