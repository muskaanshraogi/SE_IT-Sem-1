/*
Roll no.:23255
Batch:H10
Problem Statement:
		Implement stack using exception handling.
*/

#include<iostream>
#include<exception>

using namespace std;

class stack
{
	int s[5],top;
	public:
		stack()
		{
			top=-1;
		}
		void push(int data);
		int pop();
		void display();
};

void stack::push(int data)
{
	if(top>=4)
		throw top;
	
	top++;
	s[top]=data;
}

int stack::pop()
{
	if(top<=-1)
		throw 2.0;
	
	int x=s[top];
	top--;
	return x;
}

int main()
{
	stack s;
	int y,choice;
	try
	{
	do
	{
	 	cout<<"\n1)Push\n2)Pop\n3)Exit"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"\nEnter the data to be pushed onto the stack:"<<endl;
				cin>>y;
				s.push(y);
				break;
			case 2:
				y=s.pop();
				cout<<endl<<y<<" was popped from the stack."<<endl;
				break;
			case 3:
				exit(0);
		}
		
	}while(1);
	}
	catch(int)
	{
		cout<<"\nStack is full!"<<endl;
	}
	catch(float)
	{
		cout<<"\nStack is empty!"<<endl;
	}
	return 0;
}
