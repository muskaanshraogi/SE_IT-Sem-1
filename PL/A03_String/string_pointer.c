#include<stdio.h>
#include<stdlib.h>

int strlength(char *string);
int compare(char *string1,char *string2);
void copy(char *string1,char *string2);
void reverse(char *string1);
void palindrome(char *string);
void substring(char *string,char *sub);

int main()
{
	char string1[20],string2[20];
	int choice;
	
	do
	{
		printf("\n***STRING MENU***\n1)Accept\n2)Display\n3)Length\n4)Compare\n5)Reverse\n6)Copy\n7)Palindrome\n8)Exit\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
		case 1:
			printf("\nEnter the string:\n");
			scanf("%s",string1);
		case 2:
			printf("\nThe string is '%s'.\n",string1);
			break;
		case 3:
			printf("\nThe length of the string is %d.\n",strlength(string1));
			break;
		case 4:
			printf("\nEnter the string to be compared:\n");
			scanf("%s",string2);
			
			if(compare(string1,string2)==0)
			{
				printf("\nStrings are same.\n");
			}
			else
			{
				printf("\nStrings are different.\n");
			}
			break;
		case 5:
			printf("\nThe string before reversing is '%s'.\n",string1);
			reverse(string1);
			printf("\nThe string after reversing is '%s'.\n",string1);
			break;
		case 6:
			printf("\nEnter the new string:\n");
			scanf("%s",string2);
			printf("\nString before copying is '%s'.\n",string1);
			copy(string1,string2);
			printf("\nString after copying is '%s'.\n",string1);
			break;	
		case 7:
			palindrome(string1);
			break;
		case 8:
			printf("\nEnter the string to be checked for substring:\n");
			scanf("%s",string2);
			substring(string1,string2);
			break;
		case 9:
			exit(0);
		}
	}while(1);
	
	return 0;
}

int strlength(char *string)
{
	int i=0;
	while(*(string+i)!=0)
	{
		i++;
	}
	return i;
}

int compare(char *string1,char *string2)
{
	int i,diff;
	
	if(strlength(string1)==strlength(string2))
	{
		for(i=0;i<strlength(string1) && i<strlength(string2);i++)
		if(*(string1+i)==*(string2+i))
		{
			diff=0;
		}
		else
		{
			diff=*(string1+i)-(*(string2+i));
			break;
		}
	}
	else
	{
		diff=-1;
	}
	
	return diff;
}

void copy(char *string1,char *string2)
{
	int i;
	
	for(i=0;i<strlength(string2);i++)
	{
		*(string1+i)=*(string2+i);
	}
	*(string1+i)='\0';
}

void reverse(char *string1)
{
	char rev[20];
	int i,l;
	i=0;
	copy(rev,string1);
	l=strlength(rev);
	
	while(i<l)
	{
		
		*(string1+i)=*(rev+(l-i-1));
		i++;
	}
	
	*(string1+i)='\0';
}

void palindrome(char *string)
{
	int p;
	char pal[20];
	copy(pal,string);
	reverse(pal);
	p=compare(pal,string);
	if(p==0)
	{
		printf("\nThe given string is a palindrome.\n");
	}
	else
	{
		printf("\nThe string is not a palindrome.\n");
	}
}

void substring(char *string,char *sub)
{
	int i,j,s=0;
	
	for(i=0,j=0;i<strlength(string) && j<strlength(sub);i++)
	{
		if(*(string+i)==*(sub+j))
		{
			s++;
			j++;
		}
		else
		{
			s=0;
			j=0;
		}
	}
	
	if(s!=0)
	{
		printf("\nSubstring.\n");
	}
	else
	{
		printf("\nNot Substring.\n");
	}
}
