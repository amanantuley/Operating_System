#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>

int main()
{
  int fd1,fd2,n;
  char buffer[100];
  fd1= open("first.txt",O_RDONLY | O_CREAT, 0777);
  fd2= open("second.txt",O_WRONLY | O_APPEND | O_CREAT, 0644);
 while((n=read(fd1,buffer,20))!=0)
{
 write(fd2,buffer,n);
}
close(fd1);
close(fd1);
}
