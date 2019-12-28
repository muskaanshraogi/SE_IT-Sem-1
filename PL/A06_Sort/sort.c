#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct student
{
	char name[20];
	int roll,marks;
}student;

void create(student s[50],int num);
void display(student s[50],int num);
void bubblesort(student s[50],int num);
void selctionsort(student s[50],int num);
int binarysearch(student s[50],int num,int rn);
int recursivesearch(student s[50],int left,int right,int rn);

int main()
{
	student s[50];
	int choice,num,ch,rn,result;

	do
	{
		printf("\n***SORT MENU***\n1)Create database\n2)Display\n3)Ascending order(Roll no.)\n4)Descending order(Name)\n5)Search(Roll no.)\n6)Exit\n");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1:
			printf("\nEnter the number of records to be added to the database:\n");
			scanf("%d",&num);
			create(s,num);
		case 2:
			display(s,num);
			break;
		case 3:
			bubblesort(s,num);
			break;
		case 4:
			selctionsort(s,num);
			break;
		case 5:
			printf("\nEnter the roll no to be searched:\n");
			scanf("%d",&rn);
			printf("\n**SEARCH MENU**\n1)Recursive function\n2)Non-recursive function\n");
			scanf("%d",&ch);

			if(ch==1)
			{
				if(recursivesearch(s,0,num-1,rn)!=-1)
				{
					printf("\nRecord found!\n");
				}
			}
			if(ch==2)
			{
				if(binarysearch(s,num,rn)!=-1)
				{
					printf("\nRecord found!\n");
				}
			}
			break;
		case 6:
			exit(0);
		}
	}while(1);

	return 0;
}

void create(student s[50],int num)
{
	int i;

	for(i=0;i<num;i++)
	{
		printf("\nEnter the roll no.:\n");
		scanf("%d",&s[i].roll);
		printf("Enter name:\n");
		scanf("%s",s[i].name);
		printf("Enter the marks:\n");
		scanf("%d",&s[i].marks);
	}
	printf("\nDatabase created successfully!\n");
}

void display(student s[50],int num)
{
	int i;

	printf("\n------------------------------------------------------\n");
	printf("Roll no.\tName\t\tMarks\n");
	printf("------------------------------------------------------\n");

	for(i=0;i<num;i++)
	{
		printf("%d\t\t%s\t%d\n",s[i].roll,s[i].name,s[i].marks);
	}
	printf("------------------------------------------------------\n");
}

void bubblesort(student s[50],int num)
{
	int i,j,k;
	int flag=1,count=0,comp=0;
	student temp;

	printf("\n**BUBBLE SORT(Ascending order of roll no.)**\n");
	printf("\n----------------------------------------------------------------------\n");
	for(k=0;k<num;k++)
	{
		printf("%d\t",s[k].roll);
	}
	printf("Initial list\n");
	printf("----------------------------------------------------------------------\n");

	for(i=0;i<num && flag;i++)
	{
		flag=0;
		for(j=0;j<num-i-1;j++)
		{
			comp++;
			if(s[j].roll>s[j+1].roll)
			{
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
				count++;
				flag=1;
			}
		}

		for(k=0;k<num;k++)
		{
			printf("%d\t",s[k].roll);
		}
		printf("Pass %d\n",i+1);
	}

	if(count==0)
	{
		printf("\nThe record is already sorted.\n");
	}
	else
	{
		printf("\nPasses:%d",i);
		printf("\nComparisons:%d",comp);

		if(i<=2)
		{
			printf("\nBEST CASE\n");
		}
		if(i>=num-2)
		{
			printf("\nWORST CASE\n");
		}

		display(s,num);
	}
}

void selctionsort(student s[50],int num)
{
	student temp;
	int i,j,k,max;
	int count=0,comp=0;

	printf("\n**SELECTION SORT(Descending order of name.)**\n");
	printf("\n----------------------------------------------------------------------\n");
	for(k=0;k<num;k++)
	{
		printf("%s\t",s[k].name);
	}
	printf("Initial list\n");
	printf("----------------------------------------------------------------------\n");

	for(i=0;i<num-1;i++)
	{
		max=i;
		for(j=i+1;j<num;j++)
		{
			comp++;
			if(strcmp(s[j].name,s[max].name)>0)
			{
				max=j;
				count++;
			}
		}

		temp=s[max];
		s[max]=s[i];
		s[i]=temp;

		for(k=0;k<num;k++)
		{
			printf("%s\t",s[k].name);
		}
		printf("Pass %d\n",i+1);
	}

	if(count==0)
	{
		printf("\nThe record is already sorted.\n");
	}
	else
	{
		printf("\nPasses:%d",i);
		printf("\nComparisons:%d",comp);
		display(s,num);
	}
}

int binarysearch(student s[50],int num,int rn)
{
	int left,right,mid;
	left=0;
	right=num-1;

	while(left<=right)
	{
		mid=(left+right)/2;

		if(rn<s[mid].roll)
			right=mid-1;
		if(rn==s[mid].roll)
			return mid;
		if(rn>s[mid].roll)
			left=mid+1;
	}

	return -1;
}

int recursivesearch(student s[50],int left,int right,int rn)
{
	int mid=(left+right)/2;
	if(left<=right)
	{
		if(rn<s[mid].roll)
			return(s,left,mid-1,rn);
		if(rn==s[mid].roll)
			return mid;
		if(rn>s[mid].roll)
			return(s,mid+1,right,rn);
	}

	return -1;
}

