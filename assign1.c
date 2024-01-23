#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct mot{
	char mn[10];
	char op[3];
}mot[12];

struct symbol{
	int sr;
	char name[10];
	int add;
}st[10];
struct lit{
	int ln;
	char val[10];
	int ladd;
}lt[10];

int main()
{
	FILE* ptr;
	FILE* ptr1;
	ptr=fopen("abc.txt","r");
	ptr1=fopen("ic.txt","w");
	strcpy(mot[0].mn,"STOP");
	strcpy(mot[0].op,"00");
	strcpy(mot[1].mn,"ADD");
	strcpy(mot[1].op,"01");
	strcpy(mot[2].mn,"SUB");
	strcpy(mot[2].op,"02");
	char str[100];
	char oprand[10];
	int lc,isflag=0;
	int i,sptr=1,lptr=1,sf, lf;
	int df,a;

		if(ptr==NULL)
		{
			printf("The file is empty.......");
		}
		else
		{
		    	printf("The equivalent IC is....\n");
			while(fscanf(ptr, "%s",str)!= EOF){
			//printf("%s\n", str);
			//printf("The equivalent IC is....\n");
			df=0;
			sf=0;
			lf=0;
				if(strcmp(str,"START")==0)
				{
					isflag=1;
					df=1;
					printf("AD,01");
					fscanf(ptr, "%s", str);
					int n;
					n=atoi(str);
					printf("\tc,%d\n",n);
					lc=n;
					}
				if(strcmp(str,"END")==0)
				{
					isflag=1;
					df=1;
					printf("AD,02\n");
					for(i=1;i<lptr;i++)
					{
						lt[i].ladd=lc;
						lc++;
					}
				}
				if(isflag==1)
				{
					for(i=0;i<12;i++)
					{
						if(strcmp(str,mot[i].mn)==0)
							{
								printf("%d IS, %s",lc,mot[i].op);
								lc++;
								df=1;
								//for operand 1
								fscanf(ptr, "%s",str);
						if(strcmp(str,"AREG")==0)
						{
						printf("\tR,1");
						}
						if(strcmp(str,"BREG")==0)
						{
						printf("\tR,2");
						}
						if(strcmp(str,"CREG")==0)
						{
						printf("\tR,3");
						}
						if(strcmp(str,"DREG")==0)
						{
						printf("\tR,1");
						}
						
						//operand 2
						fscanf(ptr, "%s",str);
						if(str[0]!='=')
						{
						
						for(i=1;i<=sptr;i++)
						{
						if(strcmp(str,st[i].name)==0)
						{
						printf("\tS, %d\n",i);
						sf=1;
						break;
						}
						}
						if(sf==0)
						{
						strcpy(st[sptr].name,str);
						st[sptr].sr=sptr;
						printf("\tS, %d\n",sptr);
						sptr++;
						//isflag=0;
						}
						}
						
						//for litral
						else
						{
						
						for(i=1;i<=lptr;i++)
						{
						if(strcmp(str,lt[i].val)==0)
						{
						printf("\tL, %d\n",i);
						lf=1;
						break;
						}
						}
						if(lf==0)
						{
						strcpy(lt[lptr].val,str);
						lt[lptr].ln=lptr;
						printf("\tL, %d\n",lptr);
						lptr++;
						//isflag=0;
						}
						}
						}
					}
				}
					
			if(df==0)
			{
			for(i=1;i<=sptr;i++)
			{
			if(strcmp(str,st[i].name)==0)
			{
			st[i].add=lc;
			fscanf(ptr, "%s",str);
			if(strcmp(str,"DC")==0)
			{
			printf("%d DL,01",lc);
			lc++;
			fscanf(ptr, "%s",str);
			a=atoi(str);
			printf("\tC, %d\n",a);
			}
			if(strcmp(str,"DS")==0)
			{
			printf("%d DL,02",lc);
			fscanf(ptr, "%s",str);
			a=atoi(str);
			lc=lc+a;
			printf("\tC, %d\n",a);
			}		
			}						
			}
			}
			}
		}
		printf("---------------------------------------------------------------------------\n");
		printf("Symbol Table\n");
		printf("Sr.No.\tSName\tSAdd\n");
		for(i=1;i<sptr;i++)
		{
		printf("%d\t%s\t%d\n",st[i].sr,st[i].name,st[i].add);
		}
		
		
		
}

