#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	char name[20];
	int roll,marks;
	struct node *next,*prev;
}node;

node *insert(node *head);
void display(node *head);
void display_reverse(node *head);
void modify(node *head);
node *delete_record(node *head);

int main()
{
	node *head=NULL;
	int choice;
	
	do
	{
		printf("\n***MENU***\n1)Add record\n2)Display forward\n3)Display backwards\n4)Modify\n5)Delete\n6)Exit\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
		case 1:
			head=insert(head);
			break;
		case 2:
			printf("\n---------------------------------------------------\n");
			printf("Roll no.\tName\t\tMarks\n");
			printf("---------------------------------------------------\n");
			display(head);
			printf("---------------------------------------------------\n");
			break;
		case 3:
			printf("\n---------------------------------------------------\n");
			printf("Roll no.\tName\t\tMarks\n");
			printf("---------------------------------------------------\n");
			display_reverse(head);
			printf("---------------------------------------------------\n");
			break;
		case 4:
			modify(head);
			break;
		case 5:
			head=delete_record(head);
			break;
		case 6:
			exit(0);
		}
	}while(1);
	
	return 0;
}

node *insert(node *head)
{
	node *current=(node *)malloc(sizeof(node));
	node *temp;
	
	printf("\nEnter the roll no.:\n");
	scanf("%d",&current->roll);
	printf("Enter the name:\n");
	scanf("%s",current->name);
	printf("Enter marks:\n");
	scanf("%d",&current->marks);
	
	if(head==NULL)
	{
		head=current;
		current->next=NULL;
		current->prev=NULL;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=current;
		current->prev=temp;
		current->next=NULL;
	}
	return head;
}

void display(node *head)
{
	node *current;
	current=head;
	
	while(current!=NULL)
	{
		printf("%d\t%s\t%d\n",current->roll,current->name,current->marks);
		current=current->next;
	}
}

void display_reverse(node *head)
{
	node *current;
	current=head;
	
	while(current->next!=NULL)
	{
		current=current->next;
	}
	
	while(current!=NULL)
	{
		printf("%d\t%s\t%d\n",current->roll,current->name,current->marks);
		current=current->prev;
	}
}

void modify(node *head)
{
	node *current=head;
	int rn;
	
	printf("\nEnter the roll no of the record to be modified:\n");
	scanf("%d",&rn);
	
	while(current->roll!=rn && current!=NULL)
	{
		current=current->next;
	}
	
	if(current->roll==rn)
	{
		printf("\nEnter the modified marks:\n");
		scanf("%d",&current->marks);
	}
}

node *delete_record(node *head)
{
	node *current=head;
	int rn;
	
	printf("\nEnter the roll no. of the record to be deleted:\n");
	scanf("%d",&rn);
	
	while(current->roll!=rn && current!=NULL)
	{
		current=current->next;
	}
	if(current->roll==rn)
	{
		current->next->prev=current->prev;
		current->prev->next=current->next;
	}
	return head;
}
