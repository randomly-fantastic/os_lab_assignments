#include<stdio.h>
int main()
{
int r,hp;
int req[50];
int s=0;
int x,pos;
int temp[50];
int l=0,r1=0;
int left[50];
int right[50];
int temp1, temp2;

printf("Enter the size of request queue:");
scanf("%d", &r);
printf("Enter the request queue:");
for(int i=0; i<r; i++)
{
	scanf("%d", &req[i]);
}

printf("Which is the initial head point:");
scanf("%d", &hp);

int ch;
printf("Enter 1 for FCFS\nEnter 2 for SSTF\nEnter 3 for SCAN:");
scanf("%d", &ch);
switch(ch)
{
case 1:
	s=s+abs(hp-req[0]);
	for(int i=0; i<r; i++)
	{
		s=s+abs(req[i]+req[i+1]);
		printf("Req %d is completed\n", req[i]);
	}

	printf("Total seek time is:%d", s);
	break;
	
case 2:
	
	for(int i=0; i<r;i++)
	{
		for(int j=0;j<r;j++)
		{ 
			x=abs(hp-req[j]);
			temp[j]=x;
		}
		int min=req[0];
		for(int k=0;k<r;k++)
		{
			if(min>temp[k])
			{
				min=temp[k];
				pos=k;
			}
		}
		
		s = s+abs(hp-req[pos]);
		printf("Req %d is completed\n", req[pos]);
		hp= req[pos];
		req[pos]=9999;
	}
	
	printf("Total seek time is:%d", s);
	break;
	
case 3:
	for(int k=0; k<r;k++)
	{
		if(hp>=req[k])
		{
			left[l]=req[k];
			l++;
		}
		else
		{
			right[r1]=req[k];
			r1++;
		}
	}
	for(int i=0; i<r1-1;i++)
	{
		for(int j=0; j< r1-i;j++)
		{
			if(right[j]>right[j+1])
			{
				temp1=right[j];
				right[j]=right[j+1];
				right[j+1]=temp1;
			}
		}
	}
	
	for(int i=0; i<l-1;i++)
	{
		for(int j=0; j< l-i;j++)
		{
			if(left[j]>left[j+1])
			{
				temp2=left[j];
				left[j]=left[j+1];
				left[j+1]=temp2;
			}
		}
	}
	for(int i=0;i<r1;i++)
	{
		printf("Req %d is completed\n", right[i]);
	}
	
	for(int j=l-1;j>=0;j--)
	{
		printf("Req %d is completed\n", left[j]);
	}
	break;
	
				

}
}


