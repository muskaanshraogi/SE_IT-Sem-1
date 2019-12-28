/*
Roll no.:23255
Batch:H10
Problem Definition:
		    Write a program to design a class 'complex' with data members for real and imaginary part.Provide default and parameterised constructors.Write a program in C++ to perform arithematic operations of 2 complex numbers using operator overloading.
		    1)Addition and subtraction using friend functions
		    2)Multiplication and division using member functions
Date of performance:01/08/2019
*/

#include<iostream>
#include<cstdlib>
using namespace std;

class complex
{
	float real,im;
public:
	complex()
	{
		real=0;
		im=0;
	}
	complex(float a,float b)
		{
			real=a;
			im=b;
		}
	~complex()
	{
		cout<<"\nDestroyed"<<endl;
	}
	friend ostream& operator<<(ostream& myout,complex c3);
	friend complex operator+(complex c1,complex c2);
	friend complex operator-(complex c1,complex c2);
	complex operator*(complex c1);
	complex operator/(complex c1);
};

ostream& operator<<(ostream& myout,complex c3)
{
	myout<<c3.real<<"+("<<c3.im<<")i"<<endl;
	return myout;
}

complex operator+(complex c1,complex c2)
{
	complex c;
	c.real=c1.real+c2.real;
	c.im=c1.im+c2.im;
	return c;
}

complex operator-(complex c1,complex c2)
{
	complex c;
	c.real=c1.real-c2.real;
	c.im=c1.im-c2.im;
	return c;
}

complex complex::operator*(complex c1)
{
	complex c;
	c.real=(c1.real*real)-(c1.im*im);
	c.im=(c1.real*im)+(real*c1.im);
	return c;
}

complex complex::operator/(complex c1)
{
	complex c;
	int i;
	i=(c1.real*c1.real)+(c1.im*c1.im);
	c.real=(real*c1.real)+(im*c1.im);
	c.real=c.real/i;
	c.im=(im*c1.real)-(real*c1.im);
	c.im=c.im/i;
	return c;
	
}

int main()
{
	complex c1,c2,c3;
	float a,b;
	int ch;
	do
	{
		cout<<"\nChoose any operation:\n1)Input\n2)Addition\n3)Subtraction\n4)Muliplication\n5)Division\n6)Exit"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter the real part for complex number c1:"<<endl;
				cin>>a;
				cout<<"Enter the imaginary part for complex number c1:"<<endl;
				cin>>b;
				c1=complex(a,b);
				cout<<"Complex number c1 is:"<<endl;
				cout<<c1;
				cout<<"\nEnter the real part for complex number c2:"<<endl;
				cin>>a;
				cout<<"Enter the imaginary part for complex number c2:"<<endl;
				cin>>b;
				c2=complex(a,b);
				cout<<"Complex number c2 is:"<<endl;
				cout<<c2;
				break;
			case 2:
				c3=c1+c2;
				cout<<"\nThe addition of the two complex numbers is:"<<endl;
				cout<<c3;
				break;
			case 3:
				c3=c1-c2;
				cout<<"\nThe subtraction of the two complex numbers is:"<<endl;
				cout<<c3;
				break;
			case 4:
				c3=c1*c2;
				cout<<"\nThe multiplication of the two complex numbers is:"<<endl;
				cout<<c3;
				break;
			case 5:
				c3=c1/c2;
				cout<<"\nThe division of the two complex numbers is:"<<endl;
				cout<<c3;
				break;
			case 6:
				exit(0);
		}
	}while(1);
return 0;
}


