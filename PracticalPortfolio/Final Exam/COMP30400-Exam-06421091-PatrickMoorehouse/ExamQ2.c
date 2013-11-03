/*	filename.c:		Program description.
	Authors: Patrick Moorehouse
	Last Modified: 21/12/2012
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void count_char(FILE *fp1);

int main(void)
{
	FILE *fp1;
	char fname[] = "input.txt";
	int word_count = 0;
	
	if ( (fp1 = fopen(fname, "r" )) == NULL )
	{
		printf("cannot open file %s for reading\n", fname);
		exit(1);
	}
	
	printf("\n\n1: Displaying contents of %s\n\n", fname);
	count_char(fp1);

	fclose(fp1);
	return 0;
}

void count_char(FILE *fp1)
{
	char c;
	int count = 0;
	
	//reads each character of file, and every time
	//a "3" is encountered, adds 1 to counter
	c = getc(fp1);
	while (c != EOF)
	{
		if (c == '3')
		{
			count += 1;
		}
		c = getc(fp1);
	}
	//prints result of count.
	printf("The character 3 appears %d times in the file.\n", count);
}