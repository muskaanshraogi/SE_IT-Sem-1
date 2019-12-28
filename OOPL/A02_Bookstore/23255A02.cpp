/*Roll no.:23255
  Batch:H10
  Problem definition:
 		       A bookshop maintains an inventory of books being sold at the shop.The list includes details such as title,author,publisher,price,available stock. Write a program in C++ which will have a class called book with suitable member functions for:add,search,update,purchase and record number of transactions.(Use static data members to keep count of transactions.) Use new operator in constructor to allocate memory space required.
  Date of performance:  /07/19
 */  

#include<iostream>
#include<cstring>
using namespace std;

static int number;

class book
{
	char *title,*author,*publisher;
	float *price;
	int *stock,num;
public:
	book()
	{
	 	title=new char[50];
	 	author=new char[50];
	 	publisher=new char[50];
	 	price=new float;
	 	stock=new int;
	}
	~book()
	{
		cout<<"\nObject destructed."<<endl;
		delete []title;
		delete []author;
		delete []publisher;
		delete stock;
		delete price;
	}
	void add();
	int search(char t[50]);
	int search(int num);
	void update(int num);
	int buy(int num,int stock);
	void trans();
	void display();
};

void book::add()
{
	cout<<"\nEnter book number:"<<endl;
	cin>>num;
	cout<<"Enter the name of the book:"<<endl;
	cin>>title;
	cout<<"Enter the name of the author:"<<endl;
	cin>>author;
	cout<<"Enter the name of publisher:"<<endl;
	cin>>publisher;
	cout<<"Enter price of book:"<<endl;
	cin>>*price;
	cout<<"Enter the available stock:"<<endl;
	cin>>*stock;
}

int book::search(char t[50])
{
	if((strcmp(t,title)==0) ||(strcmp(t,author)==0))
		return 1;
	else
		return 0;
}

int book::search(int no)
{
	if(num==no)
		return 1;
	else
		return 0;
}

void book::update(int num)
{
	int c;
	cout<<"What do you want to update?\n1)Price\n2)Stock\n";
	cin>>c;
	switch(c)
	{
		case 1:
			cout<<"Enter updated price:"<<endl;
			cin>>*price;
			break;
		case 2:
			cout<<"Enter updated stock:"<<endl;
			cin>>*stock;
			break;
	}
	cout<<"\nInventory successfully updated.\n"<<endl;
}

void book::display()
{
	cout<<"ISBN no.:"<<num<<"\t\tTitle:"<<title<<"\t\tAuthor:"<<author<<"\t\tPublisher:"<<publisher<<"\t\tPrice:"<<*price<<"\t\tStock:"<<*stock<<endl;
}

int book::buy(int num,int stck)
{
	if(stck<=*stock)
	{
		cout<<"\nBook in stock!"<<endl;
		cout<<"\nYour total bill is Rs."<<stck*(*price)<<endl;
		cout<<"\nTransaction successful!"<<endl;
		*stock=*stock-stck;
		return stck;
	}
	else
	{
		cout<<"\nSorry!We're out of stock.\n\nTransaction unsuccessful."<<endl;
		return 0;
	}
}

int main()
{
	book b[100];
	char t[50],a[50],p[50];
	float price;
	int stock,n,ch,i,s,no,buy;
	int suc=0;
	int total=0;
	cout<<"\n***BOOKSTORE INVENTORY***\n"<<endl;
	do
	{
		cout<<"\nEnter your choice:\n1)Add books\n2)Search for book\n3)Purchase a book\n4)Update book details\n5)Transaction history\n6)Exit.\n"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter the number of books to be added:"<<endl;
				cin>>n;
				for(i=0;i<n;i++)
				{
					b[number].add();
					number++;
				}
				break;
			case 2:
				int choice;
				cout<<"\nSelect mode for search:\n1)Search by number\n2)Search by author\n3)Search by title\n"<<endl; 
				cin>>choice;
				if(choice==1)
				{
					cout<<"\nEnter the book number:"<<endl;
					cin>>no;
					for(i=0;i<number;i++)
					{
						s=b[i].search(no);
						if(s==1)
						{
							cout<<"\nBook found!"<<endl;
							b[i].display();
						}
					}
				}
				else if(choice==2)
				{
					cout<<"\nEnter the name of the author:"<<endl;
					cin>>a;
					for(i=0;i<number;i++)
					{
						s=b[i].search(a);
						if(s==1)
						{
							cout<<"\nBook found!"<<endl;
							b[i].display();
						}
					}
				}
				else if(choice==3)
				{
					cout<<"\nEnter the title:"<<endl;
					cin>>t;
					for(i=0;i<number;i++)
					{
						s=b[i].search(t);
						if(s==1)
						{
							cout<<"\nBook found!"<<endl;
							b[i].display();
						}
					}
				}
				break;
			case 3:
				cout<<"\nEnter the ISBN no. of the book that you want to buy:"<<endl;
				cin>>no;
				cout<<"Enter the number of copies you want:"<<endl;
				cin>>stock;
				for(i=0;i<number;i++)
				{
					s=b[i].search(no);
					if(s==1)
					{
						total++;
						buy=b[i].buy(no,stock);
						if(buy!=0)
							suc++;
					}
				}
				break;	
			case 4:
				cout<<"\nEnter the ISBN no. of the book to be updated:"<<endl;
				cin>>no;
				for(i=0;i<number;i++)
				{
					s=b[i].search(no);
					if(s==1)
					{
						b[i].update(no);
						b[i].display();
					}
					else if(s==0)
					cout<<"\nAdd book first."<<endl;
				}
				break;
			case 5:
				cout<<"\nSuccessful transactions:"<<suc<<endl;
				cout<<"\nUnsuccessful transactions:"<<total-suc<<endl;
				cout<<"\nTotal transactions:"<<total<<endl;
				break;
			case 6:
				exit(0);
		}
	}while(1);	
return 0;
}
