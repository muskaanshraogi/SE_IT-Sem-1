#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

node *insertbeg(node *head);
void display(node *head);
void display_rev(node *head);
node *insertend(node *head);
node *insertmid(node *head);
node *deletebeg(node *head);
node *deleteend(node *head);
node *deletemid(node *head);
node *revert(node *head);

int main()
{
	int choice,ch;
	node *head=NULL;
	
	do
	{
		printf("\n***MENU***\n1)Insert\n2)Delete\n3)Display\n4)Display reverse\n5)Revert\n6)Exit\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
		case 1:
			printf("\n**INSERT MENU**\n1)Insert at beginning\n2)Insert at end\n3)Insert in middle\n");
			scanf("%d",&ch);
			
			switch(ch)
			{
			case 1:
				head=insertbeg(head);
				break;
			case 2:
				head=insertend(head);
				break;
			case 3:
				head=insertmid(head);
				break;
			}
			break;
		
		case 2:
			printf("\n**DELETE MENU**\n1)Delete at beginning\n2)Delete at end\n3)Delete in middle\n");
			scanf("%d",&ch);
			
			switch(ch) 	
			{
			case 1:
				head=deletebeg(head);
				break;
			case 2:
				head=deleteend(head);
				break;
			case 3:
				head=deletemid(head);
				break;
			}
			break;
			
		case 3:
			if(head==NULL)
			{
				printf("\nList is empty.\n");
			}
			else
			{
				printf("\nThe linked list is:\n");
				display(head);
			}
			break;
			
		case 4:
			if(head==NULL)
			{
				printf("\nList is empty.\n");
			}
			else
			{
				printf("\nThe linked list in reverse is:\n");
				display_rev(head);
			}
			break;
			
		case 5:
			head=revert(head);
			break;
			
		case 6:
			exit(0);
		}
	}while(1);
	
	return 0;
}

node *insertbeg(node *head)
{
	node *current=(node *)malloc(sizeof(node));
	int data;
	
	printf("\nEnter data:\n");
	scanf("%d",&data);
	current->data=data;
	
	if(head==NULL)
	{
		head=current;
		current->next=NULL;
	}
	else
	{
		current->next=head;
		head=current;
	}
	
	return head;
}

node *insertend(node *head)
{
	node *current=(node *)malloc(sizeof(node));
	node *temp;
	int data;
	
	printf("\nEnter data:\n");
	scanf("%d",&data);
	current->data=data;
	current->next=NULL;
	
	if(head==NULL)
	{
		head=current;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		
		temp->next=current;
	}
	
	return head;
}

node *insertmid(node *head)
{
	node *current=(node *)malloc(sizeof(node));
	node *temp;
	int data,pos,i;
	
	printf("\nEnter the position at which data has to be inserted:\n");
	scanf("%d",&pos);
	
	printf("\nEnter data:\n");
	scanf("%d",&data);
	current->data=data;
	
	if(head==NULL)
	{
		printf("\nList is empty.\n");
	}
	else
	{
		temp=head;
		for(i=1;i<pos-1;i++)
		{
			if(temp->next==NULL)
			{
				printf("\nNot enough elements in the list.\n");
				return head;
			}
			else
			{
				temp=temp->next;
			}
		}
		current->next=temp->next;
		temp->next=current;
	}
	
	return head;
}

void display(node *head)
{
	if(head!=NULL)
	{
		printf("%d\n",head->data);
		display(head->next);
	}
}

void display_rev(node *head)
{
	if(head!=NULL)
	{
		display_rev(head->next);
		printf("%d\n",head->data);
	}
}

node *deletebeg(node *head)
{
	node *current;
	
	if(head==NULL)
	{
		printf("\nList is empty.\n");
	}
	else
	{
		current=head;
		head=current->next;
		free(current);
	}
	return head;
}

node *deleteend(node *head)
{
	node *current,*temp;
	
	if(head==NULL)
	{
		printf("\nList is empty.\n");
	}
	else
	{
		temp=head;
		
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		
		current=temp->next;
		temp->next=NULL;
		free(current);
	}
	return head;
}

node *deletemid(node *head)
{
	int pos,i;
	node *temp,*current;
	
	printf("\nEnter the position ofthe element to be deleted:\n");
	scanf("%d",&pos);
	
	if(head==NULL)
	{
		printf("\nList is empty.\n");
	}
	else
	{
		temp=head;
		for(i=1;i<pos-1;i++)
		{
			if(temp->next==NULL)
			{
				printf("\nNot enough elements in the list.\n");
				return head;
			}
			else
			{
				temp=temp->next;
			}
		}
		
		current=temp->next;
		temp->next=current->next;
		free(current);
	}
	
	return head;
}

node *revert(node *head)
{
	node *temp,*current,*result;
	current=head;
	temp=NULL;
	result=NULL;
	
	while(current!=NULL)
	{
		temp=current->next;
		current->next=result;
		result=current;
		current=temp;
	}
	head=result;
}
