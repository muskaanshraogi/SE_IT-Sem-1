/*
 ============================================================================
 Name        : file5.c
 Author      : Muskaan Shraogi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main(int argc,char *argv[])
{
	FILE *fs,*ft,*fp;
	char ch;
	if(argc>=3)
	{
		if(argc==3 && (strcmp(argv[1],"type")==0))
		{
			fp=fopen(argv[2],"r");
			if(fp==NULL)
			{
				printf("\nError opening file!\n");
				return 2;
			}
			while(!feof(fp))
			{
				ch=getc(fp);
				printf("%c",ch);
			}
		fclose(fp);
		}
		else if(argc==3 && (strcmp(argv[1],"type")!=0))
		{
			printf("\nInvalid argument.\n");
		}
		if(argc==4 && (strcmp(argv[1],"copy")==0))
		{
			fs=fopen(argv[2],"r");
			if(fs==NULL)
			{
				printf("\nError opening file!\n");
				return 3;
			}
			ft=fopen(argv[3],"w");
			if(ft==NULL)
			{
				printf("\nError opening file!\n");
				return 4;
			}
			while(!feof(fs))
			{
				ch=getc(fs);
				fprintf(ft,"%c",ch);
			}
			fclose(fs);
			fclose(ft);
			printf("\nFile successfully copied!\n");
		}
		else if(argc==4 &&(strcmp(argv[1],"copy")!=0))
		{
			printf("\nInvalid argument.\n");
		}
	}
	else
	{
		printf("\nPlease enter valid number of arguments.\n");
	return 1;
	}
	return 0;
}
