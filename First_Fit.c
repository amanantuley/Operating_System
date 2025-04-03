


/*       

Name: Aman Siraj Antuley
Roll No.: 23CO25
Batch: 01
EXPERIMENT 08

Aim: Write a program to demonstrate the concept of dynamic partitioning placement algorithms i.e. Best Fit, First Fit, Worst-Fit etc

Theory:
Dynamic partitioning allocates variable-sized memory blocks to processes using different placement strategies. First Fit assigns the first suitable block, Best Fit selects the smallest available block that fits, and Worst Fit chooses the largest block to leave bigger gaps. Each method affects memory utilization and fragmentation differently

   

*/ 

// First Fit 
#include<stdio.h>


void firstFit(int blockSize[], int m, int processSize[], int n)
{
	int i, j;
	
	int allocation[n];

	for(i = 0; i < n; i++)
	{
		allocation[i] = -1;
	}

	
	for (i = 0; i < n; i++)	 //here, n -> number of processes
	{
		for (j = 0; j < m; j++)	 //here, m -> number of blocks
		{
			if (blockSize[j] >= processSize[i])
			{
				// allocating block j to the ith process
				allocation[i] = j;

				// Reduce available memory in this block.
				blockSize[j] -= processSize[i];

				break; //go to the next process in the queue
			}
		}
	}

	printf("\nProcess No.\tProcess Size\tBlock no.\n");
	for (int i = 0; i < n; i++)
	{
		printf(" %i\t\t\t", i+1);
		printf("%i\t\t\t\t", processSize[i]);
		if (allocation[i] != -1)
			printf("%i", allocation[i] + 1);
		else
			printf("Not Allocated");
		printf("\n");
	}
}

int main()
{
	int m; //number of blocks in the memory
	int n; //number of processes in the input queue
	int blockSize[] = {100, 500, 200, 300, 600};
	int processSize[] = {212, 417, 112, 426};
	m = sizeof(blockSize) / sizeof(blockSize[0]);
	n = sizeof(processSize) / sizeof(processSize[0]);

	firstFit(blockSize, m, processSize, n);

	return 0 ;
}

/* 
Conclusion: Dynamic partitioning allows efficient memory management, but each placement strategy—First Fit, Best Fit, or Worst Fit—has its advantages and drawbacks. The choice of algorithm affects memory utilization and fragmentation, making it essential to select the most suitable approach based on system requirements.

OUTPUT:
Process No.     Process Size    Block no.
 1                      212                             2
 2                      417                             5
 3                      112                             2
 4                      426                             Not Allocated

*/