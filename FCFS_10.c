/*                                                     
Name: Aman Siraj Antuley                                                        
Roll No.: 23CO25
Batch: 01
                                                        

EXPERIMENT 10
                                                        
Aim: Write a program in C to do disk scheduling - FCFS, SCAN, C-SCAN

Theory: Disk scheduling algorithms decide the order in which disk I/O requests are served. FCFS serves in arrival order, SCAN moves the head back and forth like an elevator, and C-SCAN moves in one direction and jumps back to the start.



*/

#include<math.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,n,req[50],mov=0,cp;
    printf("enter the current position\n");
    scanf("%d",&cp);
    printf("enter the number of requests\n");
    scanf("%d",&n);
    printf("enter the request order\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
    mov=mov+abs(cp-req[0]); // abs is used to calculate the absolute value
    printf("%d -> %d",cp,req[0]);
    for(i=1;i<n;i++)
    {
        mov=mov+abs(req[i]-req[i-1]);
        printf(" -> %d",req[i]);
    }
    printf("\n");
    printf("total head movement = %d\n",mov);
}



/* 
Conclusion: Disk scheduling improves I/O efficiency. Algorithms like SCAN and C-SCAN reduce seek time compared to FCFS, enhancing overall system performance.

OUTPUT:
enter the current position
3
enter the number of requests
4
enter the request order
1
5
3
2
3 -> 1 -> 5 -> 3 -> 2
total head movement = 9


*/
