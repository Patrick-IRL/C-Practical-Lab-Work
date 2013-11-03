/*	filename.c:		Program description.
	Authors: Patrick Moorehouse
	Last Modified: 21/12/2012
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_every_second_line(FILE *fp1);

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
	
	printf("\n\n1: Displaying every second line of %s\n\n", fname);
	display_every_second_line(fp1);

	fclose(fp1);
	return 0;
}

void display_every_second_line(FILE *fp1)
{
	char string[BUFSIZ];
	int line_count = 1;
	
	while (fgets(string, sizeof string, fp1) != NULL)
	{
		if (line_count == 2)
		{
		fputs(string, stdout);
		line_count = 1;
		}
		else
		{
		line_count += 1;
		}
	}
}