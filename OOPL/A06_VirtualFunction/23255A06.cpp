/*
Roll no.:23255
Batch:H10
Problem Statement:
		Create a base class shape with two double type values and member functions to input the data and compute_area() for calculating the area of the figure.
Derive two classes triangle and rectangle. Make compute_area() as a virtual function and redefine this function in the derived class to suit their requirements. Write a program that accepts dimensions of triangle/rectangle and display calculated area.
Date:
*/

#include<iostream>

using namespace std;

class shape
{
	protected:
		double base,height;
	public:
		void input(double a,double b)
		{
			base=a;
			height=b;
		}
		virtual double compute_area()=0;
};

class triangle:public shape
{
	public:
		double compute_area()
		{
			return (0.5*base*height);
		}
};

class rectangle:public shape
{
	public:
		double compute_area()
		{
			return (base*height);
		}
};

int main()
{
	shape *s;
	triangle t;
	rectangle r;
	int choice;
	double a,b;
	do
	{
		cout<<"\nChoose the shape to compute area for:\n1)Triangle\n2)Rectangle\n3)Exit"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 1:
			s=&t;
			cout<<"\nEnter the dimensions of base and height:"<<endl;
			cin>>a>>b;
			s->input(a,b);
			cout<<"\nThe area of the given triangle is "<<s->compute_area()<<" sq. units."<<endl;
			break;
		case 2:
			s=&r;
			cout<<"\nEnter the dimensions of length and breadth:"<<endl;
			cin>>a>>b;
			s->input(a,b);
			cout<<"\nThe area of the given rectangle is "<<s->compute_area()<<" sq. units."<<endl;
			break;
		case 3:
			exit(0);
		}
	}while(1);
	return 0;
}

