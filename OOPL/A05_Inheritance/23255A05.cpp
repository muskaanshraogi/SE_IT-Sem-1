/*
Roll no.:23255
Batch:H10
Problem Statement:
		Create employee bio-data using following classes
		i. Personal record 
		ii. Professional record 
		iii. Academic record 
		Assume appropriate data members and member function to accept required data & print bio-data. Create bio-data using multiple inheritance using C++.
Date of Performance:05/09/2019
*/

#include<iostream>
#include<cstdlib>

using namespace std;

class personal_detail
{
	protected:
		char name[50],blood[3];
		struct dob
		{
			int date,month,year;
		}d;
};

class professional_detail
{
	protected:
		int exp_years;
		char skill[200];
};

class academic_detail
{
	protected:
		float percentile;
};

class resume:public personal_detail,public professional_detail,public academic_detail
{
	public:
		void accept();
		void display();
};

void resume::accept()
{
	cout<<"\nCREATE A BIODATA:"<<endl;
	cout<<"\nEnter name of employee:"<<endl;
	cin.getline(name,50);
	cout<<"Enter blood group:"<<endl;
	cin>>blood;
	cout<<"Enter date of birth(dd <space> mm <space> yyyy)"<<endl;
	cin>>d.date>>d.month>>d.year;
	cout<<"Enter field(s) of expertise:"<<endl;
	cin.ignore(50,'\n');
	cin.getline(skill,200);
	cout<<"Enter no. of years of work experience:"<<endl;
	cin>>exp_years;
	cout<<"Enter percentile obtained in degree:"<<endl;
	cin>>percentile;
}

void resume::display()
{
	cout<<endl<<endl;
	cout<<"--------------------------RESUME---------------------------\n"<<endl;
	cout<<"\nPERSONAL DETAILS:"<<endl;
	cout<<"\nName\t\t:"<<name<<endl;
	cout<<"Date of birth\t:"<<d.date<<"/"<<d.month<<"/"<<d.year<<endl;
	cout<<"Blood Group\t:"<<blood<<endl;
	cout<<"\nPROFESSIONAL DETAILS:"<<endl;
	cout<<"\nSkills\t\t:"<<skill<<endl;
	cout<<"Experience\t:"<<exp_years<<" years"<<endl;
	cout<<"\nACADEMIC DETAILS:"<<endl;
	cout<<"\nPercentile\t:"<<percentile<<endl;
	cout<<"\n\n-----------------------------------------------------------"<<endl;
}

int main()
{
	resume r;
	r.accept();
	r.display();
	return 0;
}
