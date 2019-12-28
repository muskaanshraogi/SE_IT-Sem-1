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
	int mat1[10][10],mat2[10][10],mat3[10][10],row1,col1,row2,col2,choice;
	do
	{
	printf("\n***MATRIX MENU***\n1)Accept\n2)Display\n3)Add\n4)Multiply\n5)Saddle point\n6)Transpose\n7)Exit\n");
	scanf("%d",&choice);
	
	switch(choice)
	{
	case 1:
		printf("\nEnter the number of rows and columns for matrix A:\n");
		scanf("%d%d",&row1,&col1);
		accept(&mat1[0][0],row1,col1);
		
		printf("\nEnter the number of rows and columns for matrix B:\n");
		scanf("%d%d",&row2,&col2);
		accept(&mat2[0][0],row2,col2);
		break;
	case 2:
		printf("\nThe given matrix A is:\n");
		display(&mat1[0][0],row1,col1);
		
		printf("\nThe given matrix B is:\n");
		display(&mat2[0][0],row2,col2);
		break;
	case 3:
		add(&mat1[0][0],&mat2[0][0],&mat3[0][0],row1,col1,row2,col2);
		break;
	case 4:
		multiply(&mat1[0][0],&mat2[0][0],&mat3[0][0],row1,col1,row2,col2);
		break;
	case 5:
		if(saddle(&mat1[0][0],row1,col1)!=-1)
		{
			printf("\n%d is the saddle point of matrix A.\n",saddle(&mat1[0][0],row1,col1));
		}
		else
		{
			printf("\nMatrix A has no saddle point.\n");
		}
		
		if(saddle(&mat2[0][0],row2,col2)!=-1)
		{
			printf("\n%d is the saddle point of matrix B.\n",saddle(&mat2[0][0],row2,col2));
		}
		else
		{
			printf("\nMatrix B has no saddle point.\n");
		}
		break;
	case 6:
		printf("\nMatrix A:\n");
		transpose(&mat1[0][0],&mat3[0][0],row1,col1);
		
		printf("\nMatrix B:\n");
		transpose(&mat2[0][0],&mat3[0][0],row2,col2);
		break;
	case 7:
		 exit(0);	
	}
	}while(1);
	
	return 0;
}

void add(int *mat1,int *mat2,int *mat3,int row1,int col1,int row2,int col2)
{
	int i,j;
	
	if(row1==row2 && col1==col2)
	{
		for(i=0;i<row1;i++)
		{
			for(j=0;j<col1;j++)
			{
				*(mat3+i*col1+j)=*(mat1+i*col1+j)+*(mat2+i*col1+j);
			}
		}
		
		printf("\nThe addition matrix is:\n");
		display(mat3,row1,col1);
	}
	else
	{
		printf("\nSorry addition of these matrices is not possible.\n");
	}
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

void multiply(int *mat1,int *mat2,int *mat3,int row1,int col1,int row2,int col2)
{
	int i,j,k;
	
	if(col1==row2)
	{
		for(i=0;i<row1;i++)
		{
			for(j=0;j<col2;j++)
			{
				*(mat3+i*col2+j)=0;
			}
		}
		
		for(i=0;i<row1;i++)
		{
			for(j=0;j<col2;j++)
			{
				for(k=0;k<row2;k++)
				{
					*(mat3+i*col2+j)+=*(mat1+i*col1+k)*(*(mat2+i*col2+j));
				}
			}
		}
		
		printf("\nThe multiplication matrix is:\n");
		display(mat3,row1,col2);
	}
	else
	{
		printf("\nSorry!Multiplication of these matrices is not possible.\n");
	}
}

void transpose(int *mat,int *result,int row,int col)
{
	int i,j;
	
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			*(result+j*row+i)=*(mat+i*col+j);
		}
	}
	
	printf("\nThe transpose matrix is:\n");
	display(result,col,row);
}

int saddle(int *mat,int row,int col)
{
	int i,j,k,min,max,r1,r2,c1,c2;
	
	for(i=0;i<row;i++)
	{
		min=*(mat+i*col+0);
		for(j=0;j<col;j++)
		{
			if(min>=*(mat+i*col+j))
			{
				min=*(mat+i*col+j);
				r1=i;
				c1=j;
			}
		}
		max=*(mat+0*col+c1);
		
		for(j=0;j<col;j++)
		{
			if(max<=*(mat+j*col+c1))
			{
				max=*(mat+j*col+c1);
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
