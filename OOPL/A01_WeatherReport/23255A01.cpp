/*Roll no.:23255
  Batch:H10
  Problem definition:Create a class named weather report that holds a daily weather report with data members day_of_month,hightemp,lowtemp,amount_rain and amount_snow.Use different types of constructors to initialize the objects.Also include a function that prompts the user and sets values for each field so that you can override the default values.Write a menu driven program in C++ with options to enter data and generate monthly report that displays average of each attribute.(The constructor initializes the fields with default values: 99 for day_of_month,999 for hightemp,-999 for lowtemp and 0 for amount_rain and amount_snow.)
  Date of performance:04/07/2019*/

#include<iostream>
using namespace std;



	
class weather
{
	int day_of_month;
	float htemp,ltemp,rain,snow;
	static int n;
	static float total_htemp,total_ltemp,total_rain,total_snow;
	static float avg_htemp,avg_ltemp,avg_rain,avg_snow;	
public:
	void update(int day);
	void avg();
	void display();
	void display_average();
	weather()
	{
		day_of_month=99;
		htemp=999;
		ltemp=-999;
		rain=0;
		snow=0;
	}
	~weather()
	{
		cout<<"\nDestroyed"<<endl;
	}
};

float weather::total_htemp;
float weather::total_ltemp;
float weather::total_rain;
float weather::total_snow;
float weather::avg_htemp;
float weather::avg_ltemp;
float weather::avg_rain;
float weather::avg_snow;
int weather::n;

void weather::display_average()
{
	cout<<"Average:"<<"\t\t\t"<<avg_htemp<<"\t\t\t"<<avg_ltemp<<"\t\t\t"<<avg_rain<<"\t\t\t"<<avg_snow<<endl;
}

void weather::update(int day)
{
	day_of_month=day;
	cout<<"Enter maximum temperature:"<<endl;
	cin>>htemp;
	cout<<"Enter minimum temperature:"<<endl;
	cin>>ltemp;
	cout<<"Enter amount of rainfall:"<<endl;
	cin>>rain;
	cout<<"Enter amount of snowfall:"<<endl;
	cin>>snow;
}

void weather::display()
{
	int i;
	i=i+1;
	cout<<i<<"\t\t"<<day_of_month<<"\t\t"<<htemp<<"\t\t\t"<<ltemp<<"\t\t\t"<<rain<<"\t\t\t"<<snow<<"\n";
}

void weather::avg()
{
	int i;
		if(day_of_month!=99)
		{
			n++;
			total_htemp=total_htemp+htemp;
			total_ltemp=total_ltemp+ltemp;
			total_rain=total_rain+rain;
			total_snow=total_snow+snow;
		}
	if(n>0)
	{
	avg_htemp=total_htemp/n;
	avg_ltemp=total_ltemp/n;
	avg_rain=total_rain/n;
	avg_snow=total_snow/n;
	}	
}
	
int main()
{
	weather w[30];
	int i,n,day,ch;
	cout<<"\n*****WEATHER REPORT*****\n";
	do
	{
		cout<<"\nEnter your choice:\n1)Update report\n2)Display report\n3)Quit\n"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter number of days to be updated:"<<endl;
				cin>>n;
				for(i=0;i<n;i++)
				{
					cout<<"\nEnter the day to be updated:"<<endl;
					cin>>day;
					w[day-1].update(day);
				}
				break;
			case 2:
				cout<<"\t\t\t\t\t\t MONTH REPORT\n"<<endl;;
			 	cout<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl;
				cout<<"Sr.No."<<"\t"<<"Day_of_Month"<<"\t"<<"High_Temperature"<<"\t"<<"Low_Temperature"<<"\t\t  "<<"Rainfall"<<"\t\t"<<"Snowfall"<<endl;
				cout<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl;
				for(i=0;i<30;i++)
				w[i].display();
				cout<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl;
				for(i=0;i<30;i++)
				w[i].avg();
				w[0].display_average();
				break;
			case 3:
				exit(0);
			}
	}while(1);
return 0;
}

