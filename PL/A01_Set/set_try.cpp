#include<stdio.h>
#include<stdlib.h>
#define min(x,y)((x<y?x:y))

void accept(int *set,int num);
void display(int *set,int num);
void intersection(int *set1,int *set2,int num1,int num2);
void unionset(int *set1,int *set2,int num1,int num2);
int difference(int *set1,int *set2,int *result,int num1,int num2);
void symmetric(int *set1,int *set2,int num1,int num2);

int main()
{
	int choice,*set1,*set2,*result,num1,num2;
	
	do
	{
		printf("\n***SET MENU***\n1)Accept elements\n2)Display Set\n3)Intersection\n4)Union\n5)Difference\n6)Symmetric Difference\n7)Exit\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
		case 1:
			printf("\nEnter the number of elements for set A:\n");
			scanf("%d",&num1);
			set1=(int *)malloc(num1*sizeof(int));
			accept(set1,num1);
			
			printf("\nEnter the number of elements for set B:\n");
			scanf("%d",&num2);
			set2=(int *)malloc(num2*sizeof(int));
			accept(set2,num2);
			break;
		case 2:
			printf("\nThe set A is ");
			display(set1,num1);
			
			printf("\nThe set B is ");
			display(set2,num2);
			break;
		case 3:
			intersection(set1,set2,num1,num2);
			break;
		case 4:
			unionset(set1,set2,num1,num2);
			break;
		case 5:
			printf("\nA-B: ");
			difference(set1,set2,result,num1,num2);
				
			printf("\nB-A: ");
			difference(set2,set1,result,num2,num1);
			break;
		case 6:
				symmetric(set1,set2,num1,num2);
				break;
			case 7:
				exit(0);
		}
	}while(1);
	
	return 0;
}

void accept(int *set,int num)
{
	int i,j;
	printf("\nEnter the elements of set A:\n");
	for(i=0;i<num;i++)
	{
		scanf("%d",(set+i));
	}
}

void display(int *set,int num)
{
	int i;
	printf("{");
	for(i=0;i<num;i++)
	{
		printf("  %d  ",*(set+i));
	}
	printf("}\n");
}

void intersection(int *set1,int *set2,int num1,int num2)
{
	int num,i,j,k=0;
	num=min(num1,num2);
	int *result=(int *)malloc(num*sizeof(int));
	
	for(i=0;i<num1;i++)
	{
		for(j=0;j<num2;j++)
		{
			if(*(set1+i)==*(set2+j))
			{
				*(result+k)=*(set1+i);
				k++;i++;
			}
		}
	}
	printf("\nThe intersection set is ");
	display(result,k);
}

void unionset(int *set1,int *set2,int num1,int num2)
{
	int i,j,flag,k=0;
	int *result=(int *)malloc((num1+num2)*sizeof(int));
	
	for(i=0;i<num1;i++)
	{
		*(result+k)=*(set1+i);
		k++;
	}
	
	for(i=0;i<num2;i++)
	{
		flag=0;
		for(j=0;j<num1;j++)
		{
			if(*(set2+i)==*(set1+j))
			{
				flag=1;
			}
		}
		if(flag==0)
		{
			*(result+k)=*(set2+i);
		    k++;
		}
	}
	printf("\nThe union set is ");
	display(result,k);
}

int difference(int *set1,int *set2,int *result,int num1,int num2)
{
	int i,j,flag,k=0;
	result=(int *)malloc(num1*sizeof(int));
	
	for(i=0;i<num1;i++)
	{
		for(j=0;j<num2;j++)
		{
			if(*(set1+i)==*(set2+j))
			{
				flag=1;
				break;
			}
			else
			{
				flag=0;
			}
		}
		if(flag==0)
		{
			*(result+k)=*(set1+i);
		    k++;
		}
	}
	
	printf("\nThe difference set is ");
	display(result,k);
	return k;
}

void symmetric(int *set1,int *set2,int num1,int num2)
{
	int *diff1,*diff2,k1,k2;
	
	k1=difference(set1,set2,diff1,num1,num2);
	k2=difference(set2,set1,diff2,num2,num1);
	unionset(diff1,diff2,k1,k2);
}
