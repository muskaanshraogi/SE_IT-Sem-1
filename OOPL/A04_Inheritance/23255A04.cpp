/*
Roll no.:23255
Batch:H10
Problem Definition:
				Design a base class with name, date of birth, blood group and another base class consisting of the data members such as height and weight. Design one more base class consisting of the insurance policy number and contact address. The derived class contains the data members’ telephone numbers and driving license number. Write a menu driven program to carry out the following things:
i. Build a master table
ii.  Display Record
iii.  Insert  a record
iv.  Delete record
v.  Edit  record
vi.  Search  for a record
Date of Performance:5/9/19
*/

#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

class base1
{
	protected:
		char name[50],blood[3];
		struct dob
		{
			int date,month,year;
		}d;
};

class base2
{
	protected:
		int height,weight;
};

class base3
{
	protected:
		char address[200];
		long policy;
};

class derived:public base1,public base2,public base3
{
		long long mobile;
		long license;
	public:
		void accept();
		void display();
		int search(char s[]);
		void modify();
};

int derived::search(char s[])
{
	if((strcmp(name,s))==0)
 			return 1;
	else
			return 0;
}

void derived::accept()
{
		cout<<"\nEnter name:"<<endl;
		cin.ignore(50,'\n');
		cin.getline(name,50);
		cout<<"Enter blood group:"<<endl;
		cin>>blood;
		cout<<"Enter date of birth(dd <space> mm <space> yyyy)"<<endl;
		cin>>d.date>>d.month>>d.year;
		cout<<"Enter height(cms) and weight(kgs):"<<endl;
		cin>>height>>weight;
		cout<<"Enter address:"<<endl;
		cin.ignore(50,'\n');
		cin.getline(address,200);
		cout<<"Enter insurance policy number:"<<endl;
		cin>>policy;
		cout<<"Enter mobile number:"<<endl;
		cin>>mobile;
		cout<<"Enter driving license number:"<<endl;
		cin>>license;
}

void derived::display()
{
	cout<<name<<"\t\t"<<blood<<"\t\t"<<d.date<<"/"<<d.month<<"/"<<d.year<<"\t"<<height<<"\t\t"<<weight<<"\t\t"<<mobile<<"\t"<<license<<"\t\t"<<policy<<"\t\t"<<address<<endl;
}

void derived::modify()
{
	int ch;
	cout<<"\nSelect the field to be modified:\n1)Height\n2)Weight\n3)Address\n4)Mobile no."<<endl;
	cin>>ch;
	switch(ch)
	{
	case 1:
		cout<<"\nEnter modified height(cms):"<<endl;
		cin>>height;
		break;
	case 2:
		cout<<"\nEnter modified weight(kgs):"<<endl;
		cin>>weight;
		break;
	case 3:
		cout<<"\nEnter modified address:"<<endl;
		cin.ignore(50,'\n');
		cin.getline(address,200);
		break;
	case 4:
		cout<<"\nEnter modified mobile no."<<endl;
		cin>>mobile;
		break;
	}	
	cout<<"\nRecord successfully modified:"<<endl;
}



int main()
{
	derived d[100];
	int n,i,j,ch,s;
	char record[50];
	do
	{
		cout<<"\nEnter your choice:\n1)Build a master table\n2)Display Record\n3)Insert  a record\n4)Delete record\n5)Edit  record\n6)Search for a record\n7)Exit"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter the number of records to be added:"<<endl;
				cin>>n;
				for(i=0;i<n;i++)
					d[i].accept();
				break;
			case 2:
					   cout<<"\n------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
				cout<<"Name\t\t\tBlood Group\tDOB\t\tHeight\t\tWeight\t\tMobile.No.\tLicence.No.\tPolicy.No.\tAddress"<<endl;
				cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
				for(i=0;i<n;i++)
					d[i].display();
				break;
			case 3:
				d[n].accept();
				n++;
				break;
			case 4:
				cout<<"\nEnter the name of the record to be deleted:"<<endl;
				cin.ignore(50,'\n');
				cin.getline(record,50);
				for(i=0;i<n;i++)
				{
					s=d[i].search(record);
					if(s==1)
					{
						for(j=i;j<n;j++)
							d[i]=d[i+1];
						cout<<"\nRecord successfully deleted!"<<endl;
						n--;
					}
				}
				break;
			case 5:
				cout<<"\nEnter the name of the record to be modified:"<<endl;
				cin.ignore(50,'\n');
				cin.getline(record,50);
				for(i=0;i<n;i++)
				{
					s=d[i].search(record);
					if(s==1)
					{
						d[i].modify();
						cout<<"\n------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
				cout<<"Name\t\t\tBlood Group\tDOB\t\tHeight\t\tWeight\t\tMobile.No.\tLicence.No.\tPolicy.No.\tAddress"<<endl;
				cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
						d[i].display();
					}
				}
				break;
			case 6:
				cout<<"\nEnter the name to be searched:"<<endl;
				cin.ignore(50,'\n');
				cin.getline(record,50);
				for(i=0;i<n;i++)
				{
					s=d[i].search(record);
					if(s==1)
					{
						cout<<"\nRecord found!"<<endl;
						cout<<"\n------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
				cout<<"Name\t\t\tBlood Group\tDOB\t\tHeight\t\tWeight\t\tMobile.No.\tLicence.No.\tPolicy.No.\tAddress"<<endl;
				cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
						d[i].display();
					}
				}
				break;
			case 7:
				exit(0);
		}
	}while(1);
	return 0;
}
