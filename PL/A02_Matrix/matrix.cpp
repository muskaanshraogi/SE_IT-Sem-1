#include<stdio.h>
#include<stdlib.h>

void accept(int mat[10][10],int row,int col);
void display(int mat[10][10],int row,int col);
void add(int mat1[10][10],int mat2[10][10],int row1,int col1,int row2,int col2);
void multiply(int mat1[10][10],int mat2[10][10],int row1,int col1,int row2,int col2);
void transpose(int mat[10][10],int row,int col);
int saddle(int mat[10][10],int row,int col);

int main()
{
	int choice,mat1[10][10],mat2[10][10],row1,col1,row2,col2,sad;
	
	do
	{
		printf("\n***MATRIX MENU***\n1)Accept matrices\n2)Display\n3)Add\n4)Multiply\n5)Saddle point\n6)Transpose\n7)Exit\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
		case 1:
			printf("\nEnter the number of rows and columns for matrix A:\n");
			scanf("%d%d",&row1,&col1);
			accept(mat1,row1,col1);
			
			printf("\nEnter the number of rows and columns for matrix B:\n");
			scanf("%d%d",&row2,&col2);
			accept(mat2,row2,col2);
			break;
		case 2:
			printf("\nMatrix A is:\n");
			display(mat1,row1,col1);
			
			printf("\nMatrix B is:\n");
			display(mat2,row2,col2);
			break;
		case 3:
			add(mat1,mat2,row1,col1,row2,col2);
			break;
		case 4:
			multiply(mat1,mat2,row1,col1,row2,col2);
			break;
		case 5:
			if(saddle(mat1,row1,col1)!=-1)
			{
				printf("\n%d is the saddle point of matrix A.\n",saddle(mat1,row1,col1));
			}
			else
			{
				printf("\nMatrix A does not have a saddle point.\n");
			}
			
			if(saddle(mat2,row2,col2)!=-1)
			{
				printf("\n%d is the saddle point of matrix B.\n",saddle(mat2,row2,col2));
			}
			else
			{
				printf("\nMatrix B does not have a saddle point.\n");
			}
			break;
		case 6:
			printf("\nMatrix A:\n");
			transpose(mat1,row1,col1);
			
			printf("\nMatrix B:\n");
			transpose(mat2,row2,col2);
			break;
		case 7:
			exit(0);
				
		}
	}while(1);
	
	return 0;
}

void accept(int mat[10][10],int row,int col)
{
	int i,j;
	
	printf("Enter the elements:\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	
	printf("\nThe entered matrix is:\n");
	display(mat,row,col);
}

void display(int mat[10][10],int row,int col)
{
	int i,j;
	
	for(i=0;i<row;i++)
	{
		printf("\n");
		for(j=0;j<col;j++)
		{
			printf("%d\t",mat[i][j]);
		}
	}
	printf("\n");
}

void add(int mat1[10][10],int mat2[10][10],int row1,int col1,int row2,int col2)
{
	int i,j,result[10][10];
	
	if(row1==row2 && col1==col2)
	{
		for(i=0;i<row1;i++)
		{
			for(j=0;j<col1;j++)
			{
				result[i][j]=mat1[i][j]+mat2[i][j];
			}
		}
		
		printf("\nThe addition matrix is:\n");
		display(result,row1,col1);
	}
	
	else
	{
		printf("\nSorry!Addition of these matrices is not possible.\n");
	}
}

void multiply(int mat1[10][10],int mat2[10][10],int row1,int col1,int row2,int col2)
{
	int i,j,k,result[10][10];
	
	if(col1==row2)
	{
		for(i=0;i<row1;i++)
		{
			for(j=0;j<col2;j++)
			{
				result[i][j]=0;
			}
		}
		
		for(i=0;i<row1;i++)
		{
			for(j=0;j<col2;j++)
			{
				for(k=0;k<row2;k++)
				{
					result[i][j]+=mat1[i][k]*mat2[k][j];
				}
			}
		}
		
		printf("\nThe multiplication matrix is:\n");
		display(result,row1,col2);
	}
	
	else
	{
		printf("\nSorry!Multiplication of these matrices is not possible.\n");
	}
}

void transpose(int mat[10][10],int row,int col)
{
	int i,j,result[10][10];
	
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			result[j][i]=mat[i][j];
		}
	}
	
	printf("\nThe transpose matrix is:\n");
	display(result,col,row);
}

int saddle(int mat[10][10],int row,int col)
{
	int i,j,min,max,r1,c1,r2,c2;
	
	for(i=0;i<row;i++)
	{
		min=mat[i][0];
		for(j=0;j<col;j++)
		{
			if(min>=mat[i][j])
			{
				min=mat[i][j];
				r1=i;
				c1=j;
			}
		}
		
		max=mat[0][c1];
		for(j=0;j<col;j++)
		{
			if(max<=mat[j][c1])
			{
				max=mat[j][c1];
				r2=j;
				c2=c1;
			}
		}
		
		if(min==max && r1==r2 && c1==c2)
		{
			return min;
		}
	}
	return -1;
}
