/*
Roll no.:23255
Batch:H10
Problem Statement:
		Create class television that has members to hold the model number ,screen size and price.Member functions include
overloaded insertion and extraction operators.If more than 4 digits are entered for model number,if screen size is smaller than 12
inches or greater than 70 inches or if the price is negative or greater than 5000$ then throw an integer.Write a main() that 
instantiates an object and allows the user to enter and display data.If exception is caught,replace all data member values 
with zero.
*/

#include<iostream>
#include<exception>

using namespace std;

class television
{
	int model,screen,price;
	public:
		friend ostream& operator<<(ostream& myout,television t);
		friend istream& operator>>(istream& myin,television& t);
		void reset();
};

ostream& operator<<(ostream& myout,television t)
{
	myout<<"Model no.:"<<t.model<<endl<<"Screen size:"<<t.screen<<endl<<"Price:"<<t.price<<endl;
	return myout;
}

istream& operator>>(istream& myin,television& t)
{
	cout<<"\nEnter model number:"<<endl;
	myin>>t.model;
	if(t.model>9999)
		throw t.model;
		
	cout<<"Enter screen size:"<<endl;
	myin>>t.screen;
	if(t.screen<12 || t.screen>70)
		throw t.screen;
		
	cout<<"Enter price:"<<endl;
	myin>>t.price;
	if(t.price<0 || t.price>5000)
		throw t.price;
	return myin;
}

void television::reset()
{
	cout<<"\nException caught\n";
	model=0;
	screen=0;
	price=0;
}

int main()
{
	television tv;
	try
	{
		cin>>tv;
	}
	catch(int)
	{
		tv.reset();
	}
	cout<<"\nFinal values:"<<endl;
	cout<<tv;
	return 0;
}
