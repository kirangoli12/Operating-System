#include<stdio.h>

void findWaitingTime(int processes[], int n,
						int bt[], int wt[])
{
	wt[0] = 0;

	
	for (int i = 1; i < n ; i++ )
		wt[i] = bt[i-1] + wt[i-1] ;
}


void findTurnAroundTime( int processes[], int n,
				int bt[], int wt[], int tat[])
{

	for (int i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}


void findavgTime( int processes[], int n, int bt[])
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;

	
	findWaitingTime(processes, n, bt, wt);

	
	findTurnAroundTime(processes, n, bt, wt, tat);

	
	printf("Processes Burst time Waiting time Turn around time\n");

	for (int i=0; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		printf(" %d ",(i+1));
		printf("	 %d ", bt[i] );
		printf("	 %d",wt[i] );
		printf("	 %d\n",tat[i] );
	}
	int s=(float)total_wt / (float)n;
	int t=(float)total_tat / (float)n;
	printf("Average waiting time = %d",s);
	printf("\n");
	printf("Average turn around time = %d ",t);
}
int main()
{
	int np;
	int processes[10];
	int burst_time[10];
	printf("enter the no of process: ");
	scanf("%d0",&np);
	printf("enter the process and burst time:\n");
	for(int i=0;i<np;i++)
	{
		scanf("%d %d",&processes[i],&burst_time[i]);
	}
	findavgTime(processes, np, burst_time);
	return 0;
}
