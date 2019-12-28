#include<stdio.h>
#include<stdlib.h>

typedef struct sparsematrix
{
	int row,col,value;
}sparsemat;

void accept(int mat[10][10],int row,int col,sparsemat s[100]);
void mattosparse(sparsemat s[100],int mat[10][10],int row,int col);
void display(sparsemat s[100],int count);
void addition(sparsemat s1[100],sparsemat s2[100]);
void simpletranspose(sparsemat s[100]);
void fasttranspose(sparsemat s[100]);

int main()
{
	int mat1[10][10],mat2[10][10],choice,row1,col1,row2,col2;
	sparsemat s1[100],s2[100];
	
	do
	{
		printf("\n***MATRIX MENU***\n1)Accept matrices\n2)Display\n3)Add\n4)Simple transpose\n5)Fast transpose\n6)Exit\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
		case 1:
			printf("\nEnter the number of rows and columns for matrix A:\n");
			scanf("%d %d",&row1,&col1);
			accept(mat1,row1,col1,s1);
			
			printf("\nEnter the number of rows and columns for matrix B:\n");
			scanf("%d %d",&row2,&col2);
			accept(mat2,row2,col2,s2);
			break;
		case 2:
			printf("\nSparse matrix A:");
			display(s1,s1[0].value);
			
			printf("\nSparse matrix B:");
			display(s2,s2[0].value);
			break;
		case 3:
			addition(s1,s2);
			break;
		case 4:
			simpletranspose(s1);
			simpletranspose(s2);
			break;
		case 5:
			fasttranspose(s1);
			fasttranspose(s2);
			break;
		case 6:
			exit(0);
		}
	}while(1);
	
	return 0;
}

void accept(int mat[10][10],int row,int col,sparsemat s[100])
{
	int i,j,k;
	
	printf("Enter the elements:\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	
	mattosparse(s,mat,row,col);
	display(s,s[0].value);
}

void mattosparse(sparsemat s[100],int mat[10][10],int row,int col)
{
	int i,j,k=1;
	
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(mat[i][j]!=0)
			{
				s[k].value=mat[i][j];
				s[k].row=i;
				s[k].col=j;
				k++;
			}
		}
	}
	
	s[0].row=row;
	s[0].col=col;
	s[0].value=k-1;
}

void display(sparsemat s[100],int count)
{
	int i;
	
	printf("\nRow\tColumn\tValue\n");
	for(i=0;i<=count;i++)
	{
		printf("%d\t%d\t%d\n",s[i].row,s[i].col,s[i].value);
	}
}

void addition(sparsemat s1[100],sparsemat s2[100])
{
	int i=1,j=1,k=1;
	sparsemat add[100];
	
	while(i<=s1[0].value && j<=s2[0].value)
	{
		if(s1[i].row==s2[j].row && s1[i].col==s2[j].col)
		{
			add[k].row=s1[i].row;
			add[k].col=s1[i].col;
			add[k].value=s1[i].value+s2[j].value;
			i++;j++;k++;
		}
		
		else if(s1[i].row==s2[j].row && s1[i].col<s2[j].col)
		{
			add[k]=s1[i];
			i++;k++;
		}
		
		else if(s1[i].row==s2[j].row && s1[i].col>s2[j].col)
		{
			add[k]=s2[j];
			j++;k++;
		}
		
		else if(s1[i].row<s2[j].row)
		{
			add[k]=s1[i];
			i++;k++;
		}
		
		else
		{
			add[k]=s2[j];
			j++;k++;
		}
	}
	
	while(i<=s1[0].value)
	{
		add[k]=s1[i];
		k++;i++;
	}
	
	while(j<=s2[0].value)
	{
		add[k]=s2[j];
		k++;j++;
	}
	
	add[0].row=s1[0].row;
	add[0].col=s1[0].col;
	add[0].value=k-1;
	
	display(add,add[0].value);
}

void simpletranspose(sparsemat s[100])
{
	sparsemat t[100];
	int i,j,k=1;
	
	t[0].row=s[0].col;
	t[0].col=s[0].row;
	t[0].value=s[0].value;
	
	for(i=0;i<s[0].col;i++)
	{
		for(j=1;j<=s[0].value;j++)
		{
			if(s[j].col==i)
			{
				t[k].row=s[j].col;
				t[k].col=s[j].row;
				t[k].value=s[j].value;
				k++;
			}
		}
	}
	
	printf("\nSimple transpose:");
	display(t,t[0].value);
}

void fasttranspose(sparsemat s[100])
{
	sparsemat t[100];
	int row_terms[100],start_pos[100],i,j;
	
	t[0].row=s[0].col;
	t[0].col=s[0].row;
	t[0].value=s[0].value;
	
	if(s[0].value>0)
	{
		for(i=0;i<s[0].col;i++)
		{
			row_terms[i]=0;
		}
		
		for(i=1;i<=s[0].value;i++)
		{
			row_terms[s[i].col]++;
		}
		
		start_pos[0]=1;
		
		for(i=1;i<s[0].col;i++)
		{
			start_pos[i]=start_pos[i-1]+row_terms[i-1];
		}
		
		for(i=1;i<=s[0].value;i++)
		{
			j=start_pos[s[i].col]++;
			t[j].row=s[i].col;
			t[j].col=s[i].row;
			t[j].value=s[i].value;
		}
	}
	
	display(t,t[0].value);
}
