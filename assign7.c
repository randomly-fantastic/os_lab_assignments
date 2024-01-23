#include<stdio.h>
int main()
{
int n, n1;
int a[50];
int frame[5];
printf("Enter the no of elements in reference string");
scanf("%d", &n);
printf("Enter the reference string\n");
for(int i=0;i<n;i++)
{
 scanf("%d",&a[i]);
}

printf("Enter the number of frames:");
scanf("%d", &n1);

printf("The reference string is:\n");
for(int i=0;i<n;i++)
{
 printf("%d\t",a[i]);
}
printf("\n");
int f=0;
int flag=0;
int ph=0, pf=0;
for(int k=0; k<n; k++)
{
	flag=0;
	for(int i=0;i<n1;i++)
	{	
		if(a[k]==frame[i])
		{ 
		 ph++;
		 flag=1;
		 break;
		}
	}
	
	if(flag==0)
	{
	 frame[f]=a[k];
	 f=(f+1) % n1;
	 pf++;
	}
	
}

printf("Number of Page Fault is:%d\n", pf);
printf("Number of Page Hit is:%d\n", ph);
}

