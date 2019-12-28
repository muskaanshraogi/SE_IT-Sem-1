#include<stdio.h>
#include<stdlib.h>

void accept(int *mat,int row,int col);
void display(int *mat,int row,int col);
void add(int *mat1,int *mat2,int *mat3,int row1,int col1,int row2,int col2);
void multiply(int *mat1,int *mat2,int *mat3,int row1,int col1,int row2,int col2);
void transpose(int *mat,int *result,int row,int col);
int saddle(int *mat,int row,int col);

int main()
{
	int *mat1,*mat2,row1,col1,row2,col2,choice;
	
	do
	{
		printf("\n***MATRIX MENU***\n1)Accept\n2)Display\n3)Add\n4)Multiply\n5)Saddle point\n6)Transpose\n7)Exit\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
		case 1:
		printf("\nEnter the number of rows and columns for matrix A:\n");
		scanf("%d%d",&row1,&col1);
		mat1=(int *)malloc(row1*col1*sizeof(int));
		accept(mat1,row1,col1);
		
		printf("\nEnter the number of rows and columns for matrix B:\n");
		scanf("%d%d",&row2,&col2);
		mat2=(int *)malloc(row2*col2*sizeof(int));
		accept(mat2,row2,col2);
		break;
		
		case 2:
		printf("\nThe given matrix A is:\n");
		display(mat1,row1,col1);
		
		printf("\nThe given matrix B is:\n");
		display(mat2,row2,col2);
		break;
		}
	}while(1);
	
	return 0;
}

void accept(int *mat,int row,int col)
{
	int i,j;
	
	printf("\nEnter the elements:\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",(mat+i*col+j));
		}
	}
	
	printf("\nThe entered matrix is:\n");
	display(mat,row,col);
}

void display(int *mat,int row,int col)
{
	int i,j;
	
	for(i=0;i<row;i++)
	{
		printf("\n");
		for(j=0;j<col;j++)
		{
			printf("%d\t",*(mat+i*col+j));
		}
	}
	printf("\n");
}
