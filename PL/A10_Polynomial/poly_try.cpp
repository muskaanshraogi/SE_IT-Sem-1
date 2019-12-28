#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node
{
	int coef,exp;
	struct node *next;
}node;

node *create(node *poly);
node *insert(node *head,int coef,int expo);
void display(node *head);
node *add(node *poly1,node *poly2);
node *multiply(node *poly1,node *poly2);
void evaluate(node *poly,int x);

int main()
{
	node *poly1=NULL,*poly2=NULL,*poly3=NULL;
	int choice,x;
	
	do
	{
		printf("\n***MENU***\n1)Create\n2)Add\n3)Multiply\n4)Evaluate\n5)Exit\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
		case 1:
			printf("\nPoly 1:\n");
			poly1=create(poly1);
			
			printf("\nPoly 2:\n");
			poly2=create(poly2);
			break;
		case 2:
			printf("\nPoly 1:\n");
			display(poly1);
			
			printf("\nPoly 2:\n");
			display(poly2);
			break;
		case 3:
			poly3=add(poly1,poly2);
			break;
		case 4:
			poly3=multiply(poly1,poly2);
			break;
		case 5:
			printf("\nEnter x:\n");
			scanf("%d",&x);
			evaluate(poly1,x);
			break;
		case 6:
			exit(0);
		}
	}while(1);
	
	return 0;
}

node *create(node *poly)
{
	int coef,expo,num,i;
	
	printf("\nEnter the number of terms in the poly:\n");
	scanf("%d",&num);
	
	for(i=0;i<num;i++)
	{
		printf("\nEnter coef and exp:\n");
		scanf("%d%d",&coef,&expo);
		poly=insert(poly,coef,expo);
	}
	return poly;
}

node *insert(node *head,int coef,int expo)
{
	node *p,*q,*temp;
	p=(node *)malloc(sizeof(node));
	
	p->exp=expo;
	p->coef=coef;
	
	if(head==NULL)
	{
		head=p;
		head->next=head;
		return head;
	}
	
	if(expo>head->exp)
	{
		p->next=head;
		temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=p;
		head=p;
		return head;
	}
	
	q=head;
	while(q->next!=head && q->next->exp>=expo)
	{
		q=q->next;
	}
	
	if(p->exp==q->exp)
	{
		q->coef=q->coef+coef;
		free(p);
	}
	else
	{
		p->next=q->next;
		q->next=p;
	}
	
	return head;
}

void display(node *head)
{
	node*current=head;
	while(current->next!=head)
	{
		printf(" %d*x^%d +",current->coef,current->exp);
		current=current->next;
	}
	printf(" %d*x^%d\n",current->coef,current->exp);
}

node *add(node *poly1,node *poly2)
{
	node *temp=NULL;
	node *poly3=NULL;
	
	if(poly1!=NULL)
	{
		temp=poly1;
		do
		{
			poly3=insert(poly3,temp->coef,temp->exp);
			temp=temp->next;
		}while(temp!=poly1);
	}
	
	if(poly2!=NULL)
	{
		temp=poly2;
		do
		{
			poly3=insert(poly3,temp->coef,temp->exp);
			temp=temp->next;
		}while(temp!=poly2);
	}
	display(poly3);
	return poly3;
}

node *multiply(node *poly1,node *poly2)
{
	node *p1=NULL,*p2=NULL,*poly3=NULL;
	
	p2=poly2;
	do
	{
		p1=poly1;
		do
		{
			poly3=insert(poly3,p1->coef*p2->coef,p1->exp+p2->exp);
			p1=p1->next;
		}while(p1!=poly1);
		
		p2=p2->next;
	}while(p2!=poly2);
	
	display(poly3);
	return poly3;
}

void evaluate(node *poly,int x)
{
	node *p;
	int ans=0;
	p=poly;
	do
	{
		ans+=p->coef*pow(x,p->exp);
		p=p->next;
	}while(p!=poly);
	
	printf("\n%d",ans);
}
