/*
Roll no:23255
Batch:H10
Problem Statement:
				  Write a program in C++ which includes the code for following operations :
i. A function to read two double type numbers from keyboard
ii. A function to calculate the division of these two numbers
iii. A try block to detect and throw an exception if the condition "divide-by-zero" occurs
iv. Appropriate catch block to handle the exceptions thrown
Date of performance:
*/

#include<iostream>

using namespace std;

class numbers
{
	double num1,num2;
	public:
		void accept();
		void divide();
};

void numbers::accept()
{
	cout<<"\nEnter the dividend and the divisor respectively:"<<endl;
	cin>>num1>>num2;
	if(num2==0)
			   throw num2;
}

void numbers::divide()
{
	double num3;
	num3=num1/num2;
	cout<<"\nThe result of the division is:"<<endl;
	cout<<num1<<"/"<<num2<<"="<<num3<<endl;
}

int main()
{
	numbers n;
	double ans;
	char choice;
	cout<<"\nDivision of two numbers:\n"<<endl;
	do
	{
		try
		{
			n.accept();
			n.divide();
		}
		catch(double)
		{
			cout<<"\nCannot divide by zero!"<<endl;
		}
		cout<<"\nTry another division?(y/n)"<<endl;
		cin>>choice;
	}while(choice=='y');
	return 0;
}
