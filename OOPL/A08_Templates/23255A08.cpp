/*
Roll no.:23255
Batch:H10
Problem Statement:
Write a program in C++ using function/class template to read two matrices of different data types such as integers and floating-point values and perform simple arithmetic operations on these matrices separately and display it.
Date of performance:
*/


#include<iostream>

using namespace std;

template<class T>
class matrix
{
	T mat[10][10];
	int row,col;
public:
	void accept()
	{
			cout<<"\nEnter the number of rows and columns:"<<endl;
			cin>>row>>col;
			cout<<"\nEnter the elements of the matrix:"<<endl;
			for(int i=0;i<row;i++)
			{
				for(int j=0;j<col;j++)
					cin>>mat[i][j];
			}
	}
	
	void display()
	{
		for(int i=0;i<row;i++)
		{
 		 		for(int j=0;j<col;j++)
				{
					cout<<mat[i][j];
					cout<<"\t";
				}
				cout<<endl;
		}
	}
	
	matrix addition(matrix<T> m)
	{
		matrix result;
		for(int i=0;i<row;i++)
		{
 		 	for(int j=0;j<col;j++)
			{
				result.mat[i][j]=mat[i][j]+m.mat[i][j];
			}
		}
		return result;
	}
	
	matrix multiplication(matrix<T> m)
	{
		matrix result;
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				result.mat[i][j]=0;
				for(int k=0;k<row;k++)
						result.mat[i][j]+=mat[i][k]*m.mat[i][j];
			}
		}
		return result;
	}
};


int main()
{
	matrix<int>m1,m2,m3;
	int choice;
	do
	{
		cout<<"\nEnter your choice:"<<endl<<"1)Accept matrices"<<endl<<"2)Add matrices"<<endl<<"3)Multiply matrices"<<endl<<"4)Display result"<<endl<<"5)Exit"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 1:
			m1.accept();
			cout<<"\nMatrix A is:"<<endl;
			m1.display();
			m2.accept();
			cout<<"\nMatrix B is:"<<endl;
			m2.display();
			break;
		case 2:
			m3=m1.addition(m2);
			cout<<"\nThe addition matrix is:"<<endl;
			m3.display();
			break;
		case 3:
			m3=m1.multiplication(m2);
			cout<<"\nThe multiplication matrix is:"<<endl;
			m3.display();
			break;
		case 4:
			 m3.display();
			 break;	
		case 5:
			exit(0);	
		} 
	}while(1);
}
