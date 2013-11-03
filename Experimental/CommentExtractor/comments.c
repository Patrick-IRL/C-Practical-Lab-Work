/*	commments.c:	Program to extract the comments from a .c source
					file and store them in a text file.
	Authors: Patrick Moorehouse
	Last Modified: 09/12/2012
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Main function of the program */
int main(int argc, char *argv[])
{
	int arg1_length=strlen(argv[1]);
	int arg2_length=strlen(argv[2]);
	
	char file1[arg1_length], file2[arg2_length], c, a = '0';
	FILE *fp1, *fp2;
	
	sscanf(argv[1], "%s", &file1);
	sscanf(argv[2], "%s", &file2);
	
	if ( (fp1 = fopen(file1, "r" )) == NULL )
	{
		printf("cannot open file %s for reading\n", file1);
		exit(1);
	}
	else if ( (fp2 = fopen(file2, "w" )) == NULL )
	{
		printf("cannot open file %s for writing\n", file1);
		exit(1);
	}
	
	else
	{
	printf("Extracting comments from File %s to File %s\n", file1, file2);
	
	c = getc(fp1);
	printf("first char = %c\n", c);
	while (c != EOF)
	{
	//printf("begin while loop until EOF: a = %c\n", a);
	if (c == '/')
	{
		printf("detecting first / \n");
		if (a != '/')
		{
		a = '/';
		c = getc(fp1);
		}
		else{
		printf("statement when a and c are %c and %c \n", a, c);
		a = '0';
		while (c != '\n')
		{
			c = getc(fp1);
			printf("reading %c and %c\n", a, c);
			putc(c, fp2);
			printf("writing %c and %c\n", a, c);
		}
		}
	}
	
	else if (c == '*')
	{
		if (a == '/')
		{
			printf("if c is * and a is / start while loop\n");
			a = '0';
			while ( (c != '/') && (a != '*') )
			{
				printf("in while loop: a=%C c=%c\n", a, c);
				c = getc(fp1);
				putc(c, fp2);
				
				if (c == '*')
				{
					printf("if c is *");
					if (a != '*'){a = '*';}
				}
			}
		}
	
	}
	
	else{
	c = getc(fp1);
	printf("c = %c: a = %c\n", c, a);
	}//if c is not a / or * gets next char
	
	
	}//end of while loop for reading through file (EOF)
	
	}//end of else condition relating to file opening
	
	fclose(fp1);
	fclose(fp2);
	return 0;
}