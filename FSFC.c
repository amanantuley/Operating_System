/*       

Name: Aman Siraj Antuley
Roll No.: 23CO25
Batch: 01
EXPERIMENT 05

Aim: Write a program to demonstrate the concept of non-preemptive scheduling algorithms

Theory:
First Come First Serve (FCFS) Scheduling
FCFS is the simplest non-preemptive scheduling algorithm where processes are executed in the order they arrive. The CPU is assigned to the first process in the queue and continues execution until completion.

Waiting Time (WT) = Start Time - Arrival Time
Turnaround Time (TAT) = WT + Burst Time
*/
#include<stdio.h>
 
 int main()
 
{
    int n,bt[30],wait_t[30],turn_ar_t[30],av_wt_t=0,avturn_ar_t=0,i,j;
    printf("Please enter the total number of processes(maximum 30):");  // the maximum process that be used to calculate is specified.
    scanf("%d",&n);
 
    printf("\nEnter The Process Burst Time");
    for(i=0;i<n;i++)  // burst time for every process will be taken as input
    {
        printf("P[%d]:",i+1);
        scanf("%d",&bt[i]);
    }
 
    wait_t[0]=0;   
 
    for(i=1;i<n;i++)
    {
        wait_t[i]=0;
        for(j=0;j<i;j++)
            wait_t[i]+=bt[j];
    }
 
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
 
    for(i=0;i<n;i++)
    {
        turn_ar_t[i]=bt[i]+wait_t[i];
        av_wt_t+=wait_t[i];
        avturn_ar_t+=turn_ar_t[i];
        printf("\nP[%d]\t\t%d\t\t\t%d\t\t\t\t%d",i+1,bt[i],wait_t[i],turn_ar_t[i]);
    }
 
    av_wt_t/=i;
    avturn_ar_t/=i;  // average calculation is done here
    printf("\nAverage Waiting Time:%d",av_wt_t);
    printf("\nAverage Turnaround Time:%d",avturn_ar_t);
 
    return 0;
}

/* 
Conclusion: The implementation of the First Come First Serve (FCFS) scheduling algorithm successfully demonstrates how processes are executed in the order of their arrival. The waiting time for each process is calculated based on the burst time of previous processes, and the turnaround time is obtained by adding the burst time to the waiting time. The program also computes the average waiting time (AWT) and average turnaround time (ATAT) for all processes. Since FCFS is a non-preemptive scheduling algorithm, once a process starts execution, it runs to completion before the next process starts.


OUTPUT:

*/
