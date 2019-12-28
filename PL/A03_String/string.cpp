#include<stdio.h>
#include<stdlib.h>

int strlen(char string[20]);
int strcmp(char string1[20],char string2[20]);
void strcpy(char string1[20],char string2[20]);
void strrev(char string[20]);
void palindrome(char string[20]);
void substring(char string[20]);

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
			printf("\nThe length of the string is %d.\n",strlen(string1));
			break;
		case 4:
			printf("\nEnter the string to be compared:\n");
			scanf("%s",string2);
			
			if(strcmp(string1,string2)==0)
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
			strrev(string1);
			printf("\nThe string after reversing is '%s'.\n",string1);
			break;
		case 6:
			printf("\nEnter the new string:\n");
			scanf("%s",string2);
			printf("\nString before copying is '%s'.\n",string1);
			strcpy(string1,string2);
			printf("\nString after copying is '%s'.\n",string1);
			break;
		case 7:
			palindrome(string1);
			break;
		case 8:
			substring(string1);
			break;
		case 9:
			exit(0);
		}
	}while(1);
	
	return 0;
}

int strlen(char string[20])
{
	int i=0;
	while(string[i]!='\0')
	{
		i++;
	}
	return i;
}

int strcmp(char string1[20],char string2[20])
{
	int i,diff;
	
	if(strlen(string1)==strlen(string2))
	{
		for(i=0;i<strlen(string1);i++)
		{
			if(string1[i]==string2[i])
			{
				diff=0;
			}
			else
			{
				diff=string1[i]-string2[i];
				break;
			}
		}
	}
	else
	{
		diff=-1;
	}
	
	return diff;
}

void strcpy(char string1[20],char string2[20])
{
	int i;
	for(i=0;i<strlen(string2);i++)
	{
		string1[i]=string2[i];
	}
	string1[i]='\0';
}

void strrev(char string[20])
{
	char rev[20];
	strcpy(rev,string);
	int i;
	for(i=0;i<strlen(rev);i++)
	{
		string[i]=rev[strlen(rev)-i-1];
	}
	string[i]='\0';
}

void palindrome(char string[20])
{
	char pal[20];
	strcpy(pal,string);
	strrev(pal);
	
	if(strcmp(pal,string)==0)
	{
		printf("%s is a palindrome.\n",string);
	}
	else
	{
		printf("%s is not a palindrome.\n",string);
	}
}

void substring(char string[20])
{
	int i,j,count;
	count=0;
	char sub[20];
	printf("\nEnter the substring to be checked:\n");
	scanf("%s",sub);
	
	for(i=0,j=0;i<strlen(string) && j<strlen(sub);i++)
	{
		if(string[i]==sub[j])
		{
			count++;
			j++;
		}
		else
		{
			count=0;
			j=0;
		}
	}
	
	if(count==0)
	{
		printf("\n%s is not a substring of %s",sub,string);
	}
	else
	{
		printf("\n%s is a substring of %s",sub,string);
	}
}
