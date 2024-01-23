#include<stdio.h>
struct process{
char pname[5];
int at, bt, wt, tat;
}p[10];

void fcfs(int a1)
{
	int j;
	p[1].wt=0;
	p[1].tat=0;
	for(j=1;j<=a1;j++)
	{
		 p[j].wt=p[j-1].wt+p[j-1].bt;
		 p[j].tat=p[j].wt+ p[j].bt;
	}
}

int main()
{
	int i, a, ch;
	int temp=0, temp1=0;
	float avg, avg1;
	printf("Enter number of process:");
	scanf("%d",&a);

	for(i=1;i<=a;i++)
	{
 		printf("Enter AT:");
 		scanf("%d",&p[i].at);
 		printf("Enter BT:");
 		scanf("%d",&p[i].bt);
	}

	printf("Enter 1 for FCFS\n Enter 2 for SJF:");
	scanf("%d",&ch);

	switch(ch)
 	{
 		case 1:
 				fcfs(a);
				printf("\tProcess\tAT\tBT\tWT\tTAT\t\n");
				for(i=1;i<=a;i++)
				{
					printf("\tP%d\t%d\t%d\t%d\t%d\n",i,p[i].at,p[i].bt,p[i].wt,p[i].tat);
				}
				for(i=1;i<=a;i++)
				{
					temp= temp+p[i].wt;
					temp1= temp1 + p[i].tat;
				}
		
				avg = temp/a;
				avg1=temp1/a;
				printf("Average WT is:%f\n",avg);
				printf("Average TAT is:%f\n",avg1);
				break;
		case 2:
				for (int step = 1; step <= a - 1; ++step) 
				{
	    			for (int i = 1; i <= a - step; ++i) 
					{
    	  				if (p[i].bt > p[i+1].bt) 
						{
       						int temp = p[i].bt;
        					p[i].bt = p[i + 1].bt;
        					p[i + 1].bt = temp;
      					}
    				}
 				}
		 		fcfs(a);
 				printf("\tProcess\tAT\tBT\tWT\tTAT\t\n");
				for(i=1;i<=a;i++)
				{
					printf("\tP%d\t%d\t%d\t%d\t%d\n",i,p[i].at,p[i].bt,p[i].wt,p[i].tat);
				}
				for(i=1;i<=a;i++)
				{
					temp= temp+p[i].wt;
					temp1= temp1 + p[i].tat;
				}
		
				avg = temp/a;
				avg1=temp1/a;
				printf("Average WT is:%f\n",avg);
				printf("Average TAT is:%f\n",avg1);
				break;
	}
}