/*
Roll no.:23255
Batch:H10
Problem Statement:
	Write a C++ program that creates an output file, writes information to it, closes the file and open it again as an input file and read the information from the file.
Date of Performance:03/10/2019
*/

#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	char c[500];
	ofstream outfile;
	outfile.open("sample.txt");
	
	cout<<"\nEnter text to be written to the file:"<<endl;
	cin.getline(c,500);
	outfile<<c;
	outfile.close();
	cout<<"\nWritten to the file successfully!"<<endl;
	
	ifstream infile;
	infile.open("sample.txt");
	
	infile.getline(c,500);
	cout<<"\nThe content of the file is:"<<endl;
	cout<<c<<endl;
	infile.close();
	
	return 0;
}
