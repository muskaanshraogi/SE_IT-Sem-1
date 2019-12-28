#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static int pass;

typedef struct mobile
{
	char name[50];
	long long int mob;
	int bill;
}mobile;

void accept(mobile m[50],int num);
void display(mobile m[50],int num);
void quicksort(mobile m[50],int left,int right,int num);

int main()
{
	mobile m[50];
	int choice,num,k;
	
	do
	{
		printf("\n***MENU***\n1)Create database\n2)Display\n3)Sort(Descending order of name)\n4)Exit\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
		case 1:
			printf("\nEnter the number of records to be added:\n");
			scanf("%d",&num);
			
			accept(m,num);
		case 2:
			display(m,num);
			break;
		case 3:
			printf("\nQUICK SORT\n");
			printf("-------------------------------------------------------------\n");
			for(k=0;k<num;k++)
			{
				printf("%s\t",m[k].name);
			}
			printf("Initial list\n");
			
			quicksort(m,0,num-1,num);
			break;
		case 4:
			exit(0);
		}
	}while(1);
	
	return 0;
}

void accept(mobile m[50],int num)
{
	int i;
	
	for(i=0;i<num;i++)
	{
		printf("\nEnter mobile number:\n");
		scanf("%lld",&m[i].mob);
		printf("Enter name:\n");
		scanf("%s",m[i].name);
		printf("Enter total bill:\n");
		scanf("%d",&m[i].bill);
	}
	
	printf("\nDatabase created successfully!\n");
}

void display(mobile m[50],int num)
{
	int i;
	
	printf("\n------------------------------------------------\n");
	printf("Name\t\tMobile no.\tBill\n");
	printf("------------------------------------------------\n");
	
	for(i=0;i<num;i++)
	{
		printf("%s\t%lld\t%d\n",m[i].name,m[i].mob,m[i].bill);
	}
	
	printf("------------------------------------------------\n");
}

void quicksort(mobile m[50],int left,int right,int num)
{
	int i,j,k;
	char pivot[20];
	mobile temp;
	
	if(left<right)
	{
		i=left;
		j=right+1;
		strcpy(pivot,m[left].name);
		
		do
		{
			do
			{
				i++;
			}while((strcmp(pivot,m[i].name))>0);
			
			do
			{
				j--;
			}while((strcmp(pivot,m[j].name))<0);
			
			if(i<j)
			{
				temp=m[i];
				m[i]=m[j];
				m[j]=temp;
			}
		}while(i<j);
		
		temp=m[j];
		m[j]=m[left];
		m[left]=temp;
		
		for(k=0;k<num;k++)
		{
			printf("%s\t",m[k].name);
		}
		printf("Pass %d\n",pass+1);
		pass++;
		
		quicksort(m,left,j-1,num);
		quicksort(m,j+1,right,num);
	}
	pass=0;
}
