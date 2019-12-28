#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct employee
{
	char name[20];
	int id,sal;
	struct joining
	{
		int date,month,year;
	}d;
}employee;

void create(employee e[50],int num);
void display(employee e[50],int num);
int add_record(employee e[50],int num);
int search(employee e[50],int num);
void modify(employee e[50],int num);
int delete_record(employee e[50],int num);

int main()
{
	int choice,num,s;
	employee e[50];
	
	do
	{
		printf("\n***DATABASE MENU***\n1)Create\n2)Display\n3)Add record\n4)Modify\n5)Delete\n6)Search\n7)Exit\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
		case 1:
			printf("\nEnter the total number of employees in the database:\n");
			scanf("%d",&num);
			create(e,num);
		case 2:
			display(e,num);
			break;
		case 3:
			num=add_record(e,num);
			break;
		case 4:
			modify(e,num);
			break;
		case 5:
			num=delete_record(e,num);
			break;
		case 6:
			s=search(e,num);
			
			if(s!=-1)
			{
				printf("\nRecord found!\n");
			}
			else
			{
				printf("\nRecord not found!\n");
			}
			break;
		case 7:
			exit(0);
		}
	}while(1);
	
	return 0;
}

void create(employee e[50],int num)
{
	int i;
	for(i=0;i<num;i++)
	{
		printf("\nEnter employee ID:\n");
		scanf("%d",&e[i].id);
		printf("Enter the name of the employee:\n");
		scanf("%s",e[i].name);
		printf("Enter salary:\n");
		scanf("%d",&e[i].sal);
		printf("Enter joining date dd/mm/yyyy:\n");
		scanf("%d/%d/%d",&e[i].d.date,&e[i].d.month,&e[i].d.year);
	}
	printf("\nDatabase created successfully!\n");
}

void display(employee e[50],int num)
{
	int i;
	
	printf("\n----------------------------------------------------------------------------------------------------------------\n");
	printf("ID\tName\t\tSalary\t\tDate of joining\n");
	printf("----------------------------------------------------------------------------------------------------------------\n");
	
	for(i=0;i<num;i++)
	{
		printf("%d\t%s\t%d\t\t%d/%d/%d\n",e[i].id,e[i].name,e[i].sal,e[i].d.date,e[i].d.month,e[i].d.year);
	}
	
	printf("----------------------------------------------------------------------------------------------------------------\n");
}

int add_record(employee e[50],int num)
{
		printf("\nEnter employee ID:\n");
		scanf("%d",&e[num].id);
		printf("Enter the name of the employee:\n");
		scanf("%s",e[num].name);
		printf("Enter salary:\n");
		scanf("%d",&e[num].sal);
		printf("Enter joining date dd/mm/yyyy:\n");
		scanf("%d/%d/%d",&e[num].d.date,&e[num].d.month,&e[num].d.year);
		
		num++;
		printf("\nRecord added successfully!\n");
		display(e,num);
		return num;
}

int search(employee e[50],int num)
{
	int choice,id,i;
	char name[20];
	printf("\n***SEARCH MENU***\n1)Search by id\n2)Search by name\n");
	scanf("%d",&choice);
	
	switch(choice)
	{
	case 1:
		printf("\nEnter the id to be searched:\n");
		scanf("%d",&id);
		
		for(i=0;i<=num;i++)
		{
			if(id==e[i].id)
			{
				return i;
			}
		}
		break;
		
	case 2:
		printf("\nEnter the name to be searched:\n");
		scanf("%s",name);
		
		for(i=0;i<=num;i++)
		{
			if(strcmp(name,e[i].name)==0)
			{
				return i;
			}
		}
		break;
	}
	return -1;
}

void modify(employee e[50],int num)
{
	int i,choice,s;
	
	s=search(e,num);
	
	if(s!=-1)
	{
    printf("\n***MODIFY MENU***\n1)Name\n2)Salary\n");
	scanf("%d",&choice);
	
	switch(choice)
	{
	case 1:
		printf("Enter the modified name of the employee:\n");
		scanf("%s",e[s].name);
		break;
	case 2:
        printf("Enter modified salary:\n");
		scanf("%d",&e[s].sal);
		break;
	}
	
	printf("\nModification successful!\n");
	}
}

int delete_record(employee e[50],int num)
{
	int i,choice,s;
	
	s=search(e,num);
	
	if(s!=-1)
	{
		for(i=s;i<num;i++)
		{
			e[i]=e[i+1];
		}
		printf("\nRecord deleted!\n");
		num--;
	}
	return num;
}
