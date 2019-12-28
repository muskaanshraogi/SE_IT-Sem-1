#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct employee
{
	char name[20];
	int id,sal;
}employee;

void create();
void display();
void add();
void search();
void modify();
void Delete();

int main()
{
	int choice;
	
	do
	{
		printf("\n***DATABASE MENU***\n1)Create\n2)Display\n3)Add record\n4)Modify\n5)Delete\n6)Search\n7)Exit\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
		case 1:
			create();
			break;
		case 2:
			display();
			break;
		case 3:
			add();
			break;
		case 4:
			modify();
			break;
		case 5:
			Delete();
			break;
		case 6:
			search();
			break;
		case 7:
			exit(0);
		}
	}while(1);
	
	return 0;
}

void create()
{
	FILE *fp=fopen("file.txt","a");
	employee e;
	char repeat;
	
	do
	{
		printf("\nEnter the employee id:\n");
		scanf("%d",&e.id);
		printf("Enter name of the employee:\n");
		scanf("%s",e.name);
		printf("Enter salary:\n");
		scanf("%d",&e.sal);
		
		fprintf(fp,"%d\t%s\t%d\n",e.id,e.name,e.sal);
		
		fflush(stdin);
		printf("\nAdd another record?(y/n):\n");
		scanf("%c",&repeat);
	}while(repeat=='y' || repeat=='Y');
	
	printf("\nDatabase created successfully.\n");
	fclose(fp);	
}

void display()
{
	FILE *fp=fopen("file.txt","r");
	employee e;
	
	printf("\n-------------------------------------------------------------------\n");
	printf("Id.\tName\t\tSalary\n");
	printf("-------------------------------------------------------------------\n");
	
	fscanf(fp,"%d %s %d",&e.id,e.name,&e.sal);
	while(!feof(fp))
	{
		printf("%d\t%s\t%d\n",e.id,e.name,e.sal);
		fscanf(fp,"%d %s %d",&e.id,e.name,&e.sal);
	}
	
	printf("-------------------------------------------------------------------\n");
	fclose(fp);	
}

void add()
{
	FILE *fp=fopen("file.txt","a");
	employee e;
	
	printf("\nEnter the employee id:\n");
	scanf("%d",&e.id);
	printf("Enter name of the employee:\n");
	scanf("%s",e.name);
	printf("Enter salary:\n");
	scanf("%d",&e.sal);
		
	fprintf(fp,"%d\t%s\t%d\n",e.id,e.name,e.sal);
	
	printf("\nRecord added successfully!\n");
	fclose(fp);	
}

void search()
{
	FILE *fp=fopen("file.txt","r");
	employee e;
	int search;
	
	printf("\nEnter the id to be searched:\n");
	scanf("%d",&search);
	
	fscanf(fp,"%d %s %d",&e.id,e.name,&e.sal);
	while(!feof(fp))
	{
		if(e.id==search)
		{
			printf("\nRecord found!\n");
			break;
		}
		else
		{
			fscanf(fp,"%d %s %d",&e.id,e.name,&e.sal);
		}
	}
	
	fclose(fp);
}

void Delete()
{
	FILE *fs=fopen("file.txt","r");
	FILE *ft=fopen("new.txt","w");
	employee e;
	int search;
	
	printf("\nEnter the id of the record to be deleted:\n");
	scanf("%d",&search);
	
	fscanf(fs,"%d %s %d",&e.id,e.name,&e.sal);
	while(!feof(fs))
	{
		if(search!=e.id)
		{
			fprintf(ft,"%d\t%s\t%d\n",e.id,e.name,e.sal);
		}
		fscanf(fs,"%d %s %d",&e.id,e.name,&e.sal);
	}
	
	remove("file.txt");
	rename("new.txt","file.txt");
	fclose(fs);
	fclose(ft);
}

void modify()
{
	FILE *fs=fopen("file.txt","r");
	FILE *ft=fopen("new.txt","w");
	employee e;
	int search,ch;
	
	printf("\nEnter the id of the record to be deleted:\n");
	scanf("%d",&search);
	
	fscanf(fs,"%d %s %d",&e.id,e.name,&e.sal);
	while(!feof(fs))
	{
		if(search!=e.id)
		{
			fprintf(ft,"%d\t%s\t%d\n",e.id,e.name,e.sal);
		}
		else
		{
			printf("\nModify Menu:\n1)Name\n2)Salary\n");
			scanf("%d",&ch);
			
			switch(ch)
			{
			case 1:
				printf("\nEnter the modified name:\n");
				scanf("%s",e.name);
				break;
			case 2:
				printf("\nEnter the modified salary:\n");
				scanf("%d",&e.sal);
				break;
			}
			
			fprintf(ft,"%d\t%s\t%d\n",e.id,e.name,e.sal);
		}
		
		fscanf(fs,"%d %s %d",&e.id,e.name,&e.sal);
	}
	
	remove("file.txt");
	rename("new.txt","file.txt");
	fclose(fs);
	fclose(ft);
}
